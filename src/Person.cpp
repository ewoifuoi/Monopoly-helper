#include<bits/stdc++.h>
#include<ui_engine.h>
#include<interFace.h>

using namespace std;

int vis[16] = {0};

Person::Person(string s) {
    vis[5] = 1;
    vis[0] = 1;
    vis[7] = 1;
    vis[15] = 1;
    name = s;
    money = 15;
    int t = rand() % 15 + 1;
    while(vis[t]) {
        t++;
        t %= 15;
    }
    color = t;
    vis[t] = 1;
}

void Person::setName(string s) {
    name = s;
}
string Person::getName() {
    return name;
}
void Person::setMoney(double num) {
    money = num;
}
double Person::getMoney(){
    return money;
}
int Person::add(double num) {
    money += num;
    return 0;
}
int Person::dec(double num) {
    if(money > num) {
        money -= num;
        return 0;
    }
    else {
        return -1;
    }
}
int Person::giveTo(Person &other, double num) {
    if(money >= num) {
        money -= num;
        other.add(num);
        return 0;
    }
    else {
        return -1;
    }
}
int Person::reset() {
    money = 15;
    return 0;
}