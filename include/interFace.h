#pragma once

#ifndef ITFC
#define ITFC

#include <ui_engine.h>



class Person{
private:
    string name="";
    double money=0;
    
public:
    int color;  
    Person(string s);
    void setName(string s);
    string getName();
    void setMoney(double num);
    double getMoney();
    int add(int num);
    int dec(int num);
    int giveTo(Person& other, int num);
    int reset();
};

extern vector<Person> member;
extern int vis[16];

void Welcome();
void Game();
string get_user_name();





#endif