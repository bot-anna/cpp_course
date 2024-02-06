
#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <regex>
#include <bitset>

class Interpreter
{
public:
	std::ostream& out_stream;
	
	Interpreter(std::ostream& out_stream) : out_stream(out_stream) {}

	void execute(std::string filename);

	void evaluate(const std::vector<std::string>& tokens);

	std::vector<std::string> tokenize(const std::string statement);

	std::vector<std::string> getStatements(const std::string filename);

	std::string peek();

	std::string peek(int steps);

	bool is_int(const std::string& token);



private:
	std::map<std::string, int> variables; 
	int position;
	std::string config;
	std::vector<std::string> tokens;
	const std::string ETX = "\x3";
	
	void consume(const std::string& token);

	void parse_stmt();

	void parse_ConfigStmt();

	void parse_AssgStmt();

	void parse_PrintStmt();

	int parse_MathExp();

	int parse_SumExp();

	int parse_ProductExp();

	int parse_PrimaryExp();

	void print(std::string toprint);
	
	
};

#endif