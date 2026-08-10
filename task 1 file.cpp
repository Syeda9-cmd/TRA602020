#include <iostream>
#include <fstream>
using namespace std;
struct SensorReading {
    int sensorID;
    float temperature;
    float humidity;
    string timestamp;
};
int main() {
    SensorReading readings[3] = {
        {1, 36.5f, 72.3f, "2024-01-15 08:00"},
        {2, 38.1f, 68.9f, "2024-01-15 08:05"},
        {3, 35.7f, 75.1f, "2024-01-15 08:10"}
    };
    ofstream outFile("sensor_log.txt");
    if (!outFile) {
        cerr << "Error: Could not create sensor_log.txt" << endl;
        return 1;
    }
    cout << "File  created successfully." << endl;
    for (int i = 0; i < 3; i++) {
        outFile << "--- Sensor Reading " << (i + 1) << " ---" << endl;
        outFile << "Sensor ID   : " << readings[i].sensorID << endl;
        outFile << "Temperature : " << readings[i].temperature << " C" << endl;
        outFile << "Humidity    : " << readings[i].humidity << " %" << endl;
        outFile << "Timestamp   : " << readings[i].timestamp << endl;
        if (i < 2) outFile << endl; 
    }
    outFile.close();
    ifstream inFile("sensor_log.txt");
    if (!inFile) {
        cerr << "Error: Could not open sensor_log.txt for reading." << endl;
        return 1;
    }
    cout << "\nReading file contents:" << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
    return 0;
}
