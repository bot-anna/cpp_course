#include "Interpreter.h"


void Interpreter::execute(std::string filename)
{
	std::vector<std::string> statements = getStatements(filename);
	
	
	for (std::string s : statements) {
		position = 0;
		tokens = tokenize(s);
		evaluate(tokens);
	} 
}

void Interpreter::evaluate(const std::vector<std::string>& tokens)
{
	parse_stmt();
}

std::vector<std::string> Interpreter::tokenize(const std::string statement)
{
	std::string token;
	std::vector<std::string> tokens;
	for (int i = 0; i < statement.size(); i++)
	{
		if (statement[i] == ' ')
		{
			tokens.push_back(token);
			token.clear();
		} 
		else
		{
			token.push_back(statement[i]);
		}
		
	}
	tokens.push_back(token);
	return tokens;
}

std::vector<std::string> Interpreter::getStatements(const std::string filename)
{
	std::string line;
	std::fstream source(filename);
	std::vector<std::string> statements;
	if (source.is_open())
	{
		while (getline(source, line))
		{
			statements.push_back(line);
		}

		source.close();
	}
	return statements;
}

std::string Interpreter::peek()
{
	return peek(0);
}

std::string Interpreter::peek(int steps)
{
	if (position + steps >= tokens.size()) return ETX;
	return tokens[position + steps];
}

void Interpreter::consume(const std::string& token)
{
	std::string next_token = peek();
	if (next_token == ETX)
	{
		throw std::runtime_error("Consumed past last token\n");
	}
	else if (next_token != token)
	{
		throw std::runtime_error("Could not consume token" + token + "\n");
	}
	++position;
}

void Interpreter::parse_stmt()
{
	std::string next_token = peek();

	if (next_token == "config")
	{
		parse_ConfigStmt();
	}
	else if (next_token == "print")
	{
		parse_PrintStmt();
	}
	else {
		parse_AssgStmt();
	}
}


void Interpreter::parse_ConfigStmt()
{
	consume("config");
	std::string next_token = peek();
	if (next_token == "dec")
	{
		consume("dec");
		config = next_token;
	}
	else if (next_token == "hex")
	{
		consume("hex");
		config = next_token;
	}
	else if (next_token == "bin")
	{
		consume("bin");
		config = next_token;
	}
	else
	{
		throw std::runtime_error("Invalid configuration");
	}


}

void Interpreter::parse_AssgStmt()
{
	std::string next_token = peek();
	consume(next_token);
	if (peek() == "=")
	{
		consume("=");
		variables.insert_or_assign(next_token, parse_MathExp());
	}
	else
	{
		throw std::runtime_error("Expected '='");
	}
}

void Interpreter::parse_PrintStmt()
{
	consume("print");
	int value = parse_MathExp();
	if (config == "hex")
	{
		out_stream << std::hex << std::showbase << value << "\n";
	}
	else if (config == "bin")
	{
		out_stream << std::bitset<32>(value).to_string() << "\n";
	}
	else
	{
		out_stream << value << "\n";
	}
}

int Interpreter::parse_MathExp()
{ 

	return parse_SumExp(); 
}

int Interpreter::parse_SumExp()
{
	int result = parse_ProductExp();

	std::string next_token = peek();

	while (1)
	{
		if (next_token == "+")
		{
			consume("+");
			result = (result + parse_ProductExp());
		}
		else if (next_token == "-")
		{
			consume("-");
			result = (result - parse_ProductExp());
		}
		else
			break;
		next_token = peek();
	}
	return result;
}

int Interpreter::parse_ProductExp()
{
	int result = parse_PrimaryExp();

	std::string next_token = peek();

	while (1)
	{
		if (next_token == "*")
		{
			consume("*");
			result = (result * parse_PrimaryExp());
		}
		else if (next_token == "/")
		{
			consume("/");
			result = (result / parse_PrimaryExp());
		}
		else 
			break;
		next_token = peek();
	}
	return result;
}

int Interpreter::parse_PrimaryExp()
{
	int value;
	std::string next_token = peek();
	auto iterator = variables.find(next_token);
	
	if (is_int(next_token))
	{
		value = std::stoi(next_token);
		consume(next_token);
	}
	else if (next_token == "(")
	{
		consume("(");
		value = parse_MathExp();
		if (peek() == ")")
			consume(")");
		else
			throw std::runtime_error("Error: Expected: )\n");
	}
	else if (iterator != variables.end())
	{
		consume(next_token);
		value = iterator->second;
	}
	else
		throw std::runtime_error("Error: Expected int or ( )");
	return value;
}

bool Interpreter::is_int(const std::string& token)
{
	return std::regex_match(token, std::regex("-?[0-9]+"));
}


