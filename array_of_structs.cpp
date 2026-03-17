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

    // Step 5 - Compute and display min, max, and average temperature
    TemperatureRecord minTemp = findMin(records, size);
    TemperatureRecord maxTemp = findMax(records, size);
    double avgTemp = findAverage(records, size);
    cout << "Lowest temperature:  " << minTemp.temperature << " on day " << minTemp.day << endl;
    cout << "Highest temperature: " << maxTemp.temperature << " on day " << maxTemp.day << endl;
    cout << fixed << setprecision(2);
    cout << "Average temperature: " << avgTemp << endl;

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

// Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature
TemperatureRecord findMin(const TemperatureRecord records[], int size) {
    TemperatureRecord min = records[0];
    for (int i = 1; i < size; i++) {
        if (records[i].temperature < min.temperature) {
            min = records[i];
        }
    }
    return min;
}

// Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature
TemperatureRecord findMax(const TemperatureRecord records[], int size) {
    TemperatureRecord max = records[0];
    for (int i = 1; i < size; i++) {
        if (records[i].temperature > max.temperature) {
            max = records[i];
        }
    }
    return max;
}

// Step 10 - Implement findAverage()
// Compute and return the average temperature
double findAverage(const TemperatureRecord records[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += records[i].temperature;
    }
    return static_cast<double>(sum) / size;
}
