#include "Header.h"

using namespace std;

int main()
{
    string FirstFile = "input.bin";

    int n = OpenAndAddDataFile(FirstFile);
    int w = DeleteTrip(FirstFile, n);

    return 0;
}

