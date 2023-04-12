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
    
    Sphere(){}
    
    Sphere(double x, double y, double z, double r) {
        x = x;
        y = y;
        z = z;
        r = r;
    }
    void print() {
        cout << "Coordinates of centre of sphere: " << x << ", " << y << ", " << z << ", " << "\nRadius of sphere: " << r << endl;
    }

    void Generation() {
        x = rand() % 100 - 50;
        y = rand() % 100 - 50;
        z = rand() % 100 - 50;
        r = rand() % 50+1;
    }

    double getRadius() {
        return r;
    }

    double Checking(double a, double s, double d) {
        return sqrt(pow(x - a, 2) + pow(y - s, 2) + pow(z - d, 2));
    }
};

int main()
{
    int k;
    double s, d, f;
    cout << "Enter the ammount of spheres: ";
    cin >> k;

    Sphere* array = new Sphere[k];

    for (size_t i = 0; i < k; i++)
    {
        array[i].Generation();
        cout << "Sphere " << i + 1 << " ";
        array[i].print();
    }

    cout << "Enter the coordinates that will be checked:" << endl;
    cout << "Enter x: ";
    cin >> s;
    cout << "Enter y: ";
    cin >> d;
    cout << "Enter z: ";
    cin >> f;

    for (size_t i = 0; i < k; i++)
    {
        if (array[i].Checking(s, d, f) < array[i].getRadius()) {
            cout << i + 1 << endl;
        }
    }

}
