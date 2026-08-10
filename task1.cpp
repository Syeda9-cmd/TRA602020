#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct SensorReading {
    int sensorID;
    float temperature;
    float distance;
    string timestamp;
};
int main() {
    ofstream outFile("sensor_log.txt");
    SensorReading readings[3];
    readings[0] = {101, 36.5, 120.3, "2025-06-01 08:00:00"};
    readings[1] = {102, 42.1, 85.7,  "2025-06-01 08:01:00"};
    readings[2] = {103, 29.8, 200.0, "2025-06-01 08:02:00"};
    for (int i = 0; i < 3; i++) {
        outFile << readings[i].sensorID    << endl;
        outFile << readings[i].temperature << endl;
        outFile << readings[i].distance    << endl;
        outFile << readings[i].timestamp   << endl;
        outFile << endl;
    }
    outFile.close();
    cout << "Sensor data written to sensor_log.txt\n\n";
    ifstream inFile("sensor_log.txt");
    cout << "       ROBOT SENSOR LOG READINGS        \n";
    SensorReading r;
    string separator;
    while (inFile >> r.sensorID >> r.temperature >> r.distance) {
        inFile.ignore();
        getline(inFile, r.timestamp);
        getline(inFile, separator);
        cout << "Sensor ID   : " << r.sensorID    << endl;
        cout << "Temperature : " << r.temperature << " C"<<endl;
        cout << "Distance    : " << r.distance    << " cm"<<endl;
        cout << "Timestamp   : " << r.timestamp   << endl;
        cout << "----------------------------------------"<<endl;
    }
    inFile.close();
    return 0;
}
