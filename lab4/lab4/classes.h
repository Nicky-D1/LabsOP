#pragma once
#include <iostream>

using namespace std;

class Number {
private:
    int thousands;
    int hundreds;
    int dozens;
    int units;

public:
    Number();
    Number(int t, int h = 0, int d = 0, int u = 0);
    Number(const Number& n);
    int GetUnits(); 
    int GetDozens();
    int GetHundreds();
    int GetThousands();
    int Sum();
    Number operator++();
    Number operator--();
    Number operator+(Number other);
    bool operator >(Number second);
};