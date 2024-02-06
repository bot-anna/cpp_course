#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif
#include "PersonReg.h"
#include "Person.h"
#include "PersonWithPhone.h"
#include <string>
#include <fstream>
#include <iostream>

#if 1
#define PN(x) std::cout << x
#define DN(x) x
#define PD(x) std::cout << x
#else
#define PN(x)
#define DN(x)
#define PD(x) (x)
#endif


void Init(PersonReg& tr) {
    tr.empty();
    PD(tr.addToTest("olle", "0703955123"));
    PD(tr.addToTest("olle", "123"));
    PD(tr.addToTest("kurtake", "12345"));
    PD(tr.addToTest("olle", "456"));
    PD(tr.addToTest("sven", "456"));
    PD(tr.addToTest("kurt", "95815"));
    PN(std::endl);
    PN(("fullt reg "));
    PN((std::endl));
    DN((tr.Print()));
}

bool ReadReg(PersonReg& reg, std::string fileName) {
    std::cout << fileName << std::endl;
    std::string line;
    std::ifstream myfile(fileName);

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            while (line.length() == 0 && getline(myfile, line))
                ;
            std::string name(line);
            std::string address;
            getline(myfile, address);
            Person p = Person(name, address);
            reg.add(&p);
        }
        myfile.close();
        return true;
    }
    else {
        std::cout << "Unable to open file";
        return false;
    }
}

void Test1() {
    PersonReg reg(10);
    ReadReg(reg, "PersonExempel.txt");
    reg.Print(); std::cout << "\n\n";
    reg.empty();
    reg.Print();
}

void Test2() {
    PersonReg reg(10);
    Init(reg);
    std::string namn, address;
    Person te, *tep;

    tep = reg.searchName("olle");
    if (tep) {
        std::cout << tep->address << std::endl;
        reg.removeEntry(tep);
    }
    else
        std::cout << "not found \n";

    tep = reg.searchName("olle");
    if (tep) {
        std::cout << tep->address << std::endl;
        reg.removeEntry(tep);
    }
    else
        std::cout << "not found \n";

    tep = reg.searchName("olle");
    if (tep) {
        std::cout << tep->address << std::endl;
        reg.removeEntry(tep);
    }
    else
        std::cout << "not found \n";

    tep = reg.searchName("olle");
    if (tep) {
        std::cout << tep->address << std::endl;
        reg.removeEntry(tep);
    }
    else
        std::cout << "not found \n";

    tep = reg.searchName("olle");
    if (tep) {
        std::cout << tep->address << std::endl;
        reg.removeEntry(tep);
    }
    else
        std::cout << "not found \n";

    reg.Print();

    reg.empty();
    reg.Print();
}

void Test3() {
    PersonReg reg(10);

    Init(reg);
    reg.Print();
    std::string namn, address;
    Person te, *tep;

    tep = nullptr;
    while (tep = reg.freeSearch("olle", tep)) {
        tep->Print();
        //        cout << tep->address << endl;
    }
    std::cout << "not found \n";

    std::cout << "Mixed searches \n";
    Person* ptr1 = nullptr, *ptr2 = nullptr;
    bool first = true;
    while (first || ptr1 || ptr2) {
        if (ptr1 || first) {
            ptr1 = reg.freeSearch("olle", ptr1);
            if (ptr1)
                ptr1->Print();
        }
        if (ptr2 || first) {
            ptr2 = reg.freeSearch("581", ptr2);
            if (ptr2)
                ptr2->Print();
        }
        first = false;
    }
}

void Test4() {
    PersonReg pr(3);
    Person* p1 = new Person("kalle", "1234");
    pr.add(p1);
    Person* p2 = new PersonWithPhone("henny", "skogen", "555");
    pr.add(p2);
    Person* p3 = new PersonWithPhone("kenny", "city", "666");
    pr.add(p3);
    pr.Print();
    delete p1;
    delete p2;
    delete p3;

}

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    PersonReg pr(5);
    std::cout << "Init:" << std::endl;
    Init(pr);
    std::cout << "\nTest 1:" << std::endl;
    Test1();
    std::cout << "\nTest 2:" << std::endl;
    Test2();
    std::cout << "\nTest 3:" << std::endl;
    Test3();
    std::cout << "\nTest 4:" << std::endl;
    Test4(); 
    std::cout << "Press enter to end program" << std::endl;
    std::cin.get();

}