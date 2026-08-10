#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct SensorEntry {
    int robotID;
    int readingNum;
    float temperature;
    float battery;
};
void writeRobotLog(string filename, int robotID, float temps[], float batteries[]) {
    ofstream f(filename.c_str());
    f << robotID << "\n";  
    for (int i = 0; i < 5; i++) {
        f << (i + 1) << " " << temps[i] << " " << batteries[i] << "\n";
    }
    f.close();
}
void readAndStore(string filename, SensorEntry entries[], int &count) {
    ifstream f(filename.c_str());
    if (!f.is_open()) {
        cout << "Cannot open " << filename << "\n";
        return;
    }
    int robotID;
    f >> robotID;
    for (int i = 0; i < 5; i++) {
        SensorEntry e;
        e.robotID = robotID;
        f >> e.readingNum >> e.temperature >> e.battery;
        entries[count++] = e;
    }
    f.close();
}
int main() {
    float r1_temps[]     = {36.1, 37.2, 38.0, 36.8, 37.5};
    float r1_batteries[] = {85.0, 80.0, 75.0, 70.0, 65.0};
    float r2_temps[]     = {40.0, 41.5, 39.8, 42.0, 40.5};
    float r2_batteries[] = {50.0, 40.0, 30.0, 18.0, 12.0}; 
    float r3_temps[]     = {33.0, 34.5, 35.0, 33.8, 34.2};
    float r3_batteries[] = {95.0, 92.0, 88.0, 85.0, 83.0};
    writeRobotLog("robot1_log.txt", 1, r1_temps,     r1_batteries);
    writeRobotLog("robot2_log.txt", 2, r2_temps,     r2_batteries);
    writeRobotLog("robot3_log.txt", 3, r3_temps,     r3_batteries);
    cout << "Individual robot logs created.\n\n";
    SensorEntry allEntries[15];
    int count = 0;
    readAndStore("robot1_log.txt", allEntries, count);
    readAndStore("robot2_log.txt", allEntries, count);
    readAndStore("robot3_log.txt", allEntries, count);
    for (int i = 1; i < count; i++) {
        SensorEntry key = allEntries[i];
        int j = i - 1;
        while (j >= 0 && allEntries[j].robotID > key.robotID) {
            allEntries[j + 1] = allEntries[j];
            j--;
        }
        allEntries[j + 1] = key;
    }
    ofstream fleet("fleet_log.txt");
    fleet << "         FLEET MERGED LOG                 \n";
    fleet << "==========================================\n";
    int currentRobot = -1;
    for (int i = 0; i < count; i++) {
        SensorEntry &e = allEntries[i];
        if (e.robotID != currentRobot) {
            fleet << "\n[Robot " << e.robotID << "]\n";
            currentRobot = e.robotID;
        }
        string status = "";
        if (e.battery < 20.0) status = "  <<< CRITICAL - LOW BATTERY";
        fleet << "  Reading " << e.readingNum
              << " | Temp: "     << e.temperature << "C"
              << " | Battery: "  << e.battery     << "%"
              << status << "\n";
    }
    fleet << "\n==========================================\n";
    fleet << "           END OF FLEET LOG               \n";
    fleet << "==========================================\n";
    fleet.close();
    ifstream show("fleet_log.txt");
    string line;
    while (getline(show, line)) cout << line << "\n";
    show.close();
    remove("robot1_log.txt");
    remove("robot2_log.txt");
    remove("robot3_log.txt");
    cout << "\nIndividual log files deleted.\n";
    cout << "Merged log saved to fleet_log.txt\n";
    return 0;
}
