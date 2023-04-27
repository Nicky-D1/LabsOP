#include "classes.h"

Number::Number() :thousands(0), hundreds(0), dozens(0), units(0) {};

Number::Number(int t, int h, int d, int u) :thousands(t), hundreds(h), dozens(d), units(u) {};

Number::Number(const Number& n) :units(n.units), dozens(n.dozens), hundreds(n.hundreds), thousands(n.thousands) {};

int Number::GetUnits() {
    return units;
};

int Number::GetDozens() {
    return dozens;
};

int Number::GetHundreds() {
    return hundreds;
};

int Number::GetThousands() {
    return thousands;
};

int Number::Sum() {
    return thousands * 1000 + hundreds * 100 + dozens * 10 + units;
};

Number Number::operator++() {
    return Number(this->thousands + 1, this->hundreds + 1, this->dozens + 1, this->units + 1);
};

Number Number::operator--() {
    return Number(this->thousands - 1, this->hundreds - 1, this->dozens - 1, this->units - 1);
}

Number Number::operator+(Number other) {
    return Number(this->thousands + other.thousands, this->hundreds + other.hundreds, this->dozens + other.dozens, this->units + other.units);
}

bool Number::operator >(Number second) {
    return this->Sum() > second.Sum();
}