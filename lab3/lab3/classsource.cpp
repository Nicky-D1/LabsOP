#include "class.h"

Sphere::Sphere() {
    x = 0;
    y = 0;
    z = 0;
    r = 0;
}

Sphere::Sphere(double x, double y, double z, double r) {
    x = x;
    y = y;
    z = z;
    r = r;
}

void Sphere::print() {
    cout << "Coordinates of centre of sphere: " << x << ", " << y << ", " << z << ", " << "\nRadius of sphere: " << r << endl;
}

void Sphere::Generation() {
    x = rand() % 100 - 50;
    y = rand() % 100 - 50;
    z = rand() % 100 - 50;
    r = rand() % 50 + 1;
}

double Sphere::getRadius() {
    return r;
}

double Sphere::Checking(double a, double s, double d) {
    return sqrt(pow(x - a, 2) + pow(y - s, 2) + pow(z - d, 2));
}