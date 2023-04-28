#include "class.h"

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

    cout << "\nEnter the coordinates that will be checked:" << endl;
    cout << "Enter x, y, z: ";
    cin >> s >> d >> f;

    for (size_t i = 0; i < k; i++)
    {
        if (array[i].Checking(s, d, f) < array[i].getRadius()) {
            cout << "This point belongs to sphere: "<< i + 1 << endl;
        }
        
    }

    return 0;

}
