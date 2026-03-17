#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Step 1 - Define the struct TemperatureRecord
struct TemperatureRecord {
    int day;
    int temperature;
};

// Constants
const int MAX_DAYS = 31;

// Function Prototypes
void readTemperatures(TemperatureRecord records[], int& size);
void printTemperatures(const TemperatureRecord records[], int size);
TemperatureRecord findMin(const TemperatureRecord records[], int size);
TemperatureRecord findMax(const TemperatureRecord records[], int size);
double findAverage(const TemperatureRecord records[], int size);

int main() {
    // Step 2 - Declare an array of TemperatureRecord structs
    TemperatureRecord records[MAX_DAYS];

    int size = 0;  // Actual number of records read

    // Step 3 - Call readTemperatures() to load data from file
    readTemperatures(records, size);

    // Step 4 - Print the temperatures
    cout << "Monthly Temperature Data:" << endl;
    cout << "-------------------------" << endl;
    printTemperatures(records, size);

    // TODO: Step 5 - Compute and display min, max, and average temperature

    return 0;
}

// Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array
void readTemperatures(TemperatureRecord records[], int& size) {
    ifstream inFile("temps.txt");

    if (!inFile) {
        cout << "Error: Could not open temps.txt" << endl;
        return;
    }

    size = 0;
    while (size < MAX_DAYS && inFile >> records[size].day >> records[size].temperature) {
        size++;
    }

    inFile.close();
}

// Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table
void printTemperatures(const TemperatureRecord records[], int size) {
    cout << setw(5) << "Day" << setw(10) << "Temp" << endl;
    cout << setw(5) << "---" << setw(10) << "----" << endl;

    for (int i = 0; i < size; i++) {
        cout << setw(5) << records[i].day
             << setw(10) << records[i].temperature << endl;
    }
}

// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature

// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature

// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature
