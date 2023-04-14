#include "Header.h"

int OpenAndAddDataFile(string fileName) {
    ofstream inputFile(fileName, ios::out | ios::binary);

    int x;
    cout << "Enter the number of bus routes: ";
    cin >> x;

    BusRoute* array = new BusRoute[x];

    for (size_t i = 0; i < x; i++)
    {
        cout << "\nEnter the destination: ";
        cin.ignore();
        getline(cin, array[i].destination);
        cout << "Enter the departure time: for first enter hour then space minute: ";
        cin >> array[i].dep_hour >> array[i].dep_min;
        cout << "Enter the duration of trip: for first enter hour then space minute: ";
        cin >> array[i].duration_hour >> array[i].duration_min;

    }

    inputFile.write(reinterpret_cast<char*>(array), sizeof BusRoute);

    inputFile.close();

    delete[] array;
   
    return x;
}

int DeleteTrip(string fileName, int x) {
    ifstream inputFile(fileName, ios::binary | ios::in);

    if (!inputFile) {
        cout << "Can't open the file!";
        return 0;
    }

    BusRoute* array = new BusRoute[x];

    inputFile.read(reinterpret_cast<char*>(array), sizeof(BusRoute));

    inputFile.close();

    removeFileIfExists("output.bin"); // Видалення файлу, якщо він існує

    ofstream outputFile("output.bin", ios::binary);
    int n = 0;
    int last_dest_hour = 0;
    int last_dest_min = 0;
    for (size_t i = 0; i < x; i++)
    {
        int dest_min = array[i].dep_min + array[i].duration_min;
        int dest_hour = array[i].dep_hour + array[i].duration_hour;
        dest_hour += dest_min / 60;
        dest_min %= 60;
        dest_hour %= 24;
        if (array[i].duration_hour > 17 || (array[i].dep_hour >= 6 && array[i].dep_hour < 23 && dest_hour >= 6 && dest_hour < 23)) {
            outputFile.write(reinterpret_cast<char*>(&array[i]), sizeof(BusRoute));
            n++;
            last_dest_min = dest_min;
            last_dest_hour = dest_hour;
        }
    }

    outputFile.close();

    ifstream checkedFile("output.bin", ios::binary);

    BusRoute* checkedArray = new BusRoute[n];

    checkedFile.read(reinterpret_cast<char*>(checkedArray), sizeof(BusRoute));

    cout << "\n\t======This is your checked timetable:======" << endl;

    for (size_t i = 0; i < n; i++)
    {
        cout << "\nThe destination: " << checkedArray[i].destination << endl;
        cout << "The departure time: " << checkedArray[i].dep_hour << ":" << checkedArray[i].dep_min << endl;
        cout << "The duration of trip: " << checkedArray[i].duration_hour << " hours " << checkedArray[i].duration_min << " minutes" << endl;
    }

    cout << "\n---> The last bus arrival time is: " << last_dest_hour << ":" << last_dest_min << endl;

    checkedFile.close();
    return n;
}

void removeFileIfExists(const string& fileName) {
    if (remove(fileName.c_str()) != 0)
        cout << "Error deleting file " << fileName << endl;
}
   
