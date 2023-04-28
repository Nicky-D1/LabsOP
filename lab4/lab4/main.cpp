#include "classes.h"

int main() {

    int a, b, c, d;

    cout << "Enter the parts of 1- st number, where first value is thousands and the last - units:\n";
    cin >> a >> b >> c >> d;

    Number N1(a, b, c, d);

    cout << "Enter the parts of 2- nd number, where first value is thousands and the last - units:\n";
    cin >> a >> b >> c >> d;

    Number N2(a, b, c, d);
    Number N3(N2);

    cout << "Enter the parts of 3-rd number,only thousands: ";
    cin >> a;

    Number N4(a);

    cout << "\nN1: " << N1.Sum() << " N2: " << N2.Sum() << " N3: " << N3.Sum() << " N4: " << N4.Sum() << endl;

    Number IncN1 = ++N1, DecN2 = --N2;

    cout << "\nN1++: " << IncN1.Sum() << " N2--: " << DecN2.Sum() << endl;

    N3 = IncN1 + DecN2;
    cout << "\nN3 = N1++ + N2--: " << N3.Sum() << endl;

    if (N3 > N4) {
        cout << "\nN3 is greater than N4: " << N3.Sum() << endl;
    }
    else {
        cout << "\nN4 is greater than N3: " << N4.Sum() << endl;
    }

    return 0;
}
