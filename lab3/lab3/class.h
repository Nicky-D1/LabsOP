#pragma once
#include <iostream>
#include <ctime>
#include<math.h>

using namespace std;

class Sphere {
private:
    double x;
    double y;
    double z;
    double r;
public:

    Sphere();
    Sphere(double x, double y, double z, double r);
    void print();
    void Generation();
    double getRadius();
    double Checking(double a, double s, double d);
};