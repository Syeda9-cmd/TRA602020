#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
struct Waypoint {
    int id;
    float x, y, z;
    string timestamp;
};
float euclideanDistance(Waypoint a, Waypoint b) {
    float dx = b.x - a.x;
    float dy = b.y - a.y;
    float dz = b.z - a.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}
int main() {
    const int NUM_POINTS = 10;
    Waypoint path[NUM_POINTS] = {
        {1,   0.0,  0.0,  0.0, "08:00:00"},
        {2,  10.0,  5.0,  1.0, "08:00:10"},
        {3,  20.0, 10.0,  2.0, "08:00:20"},
        {4,  35.0, 15.0,  3.0, "08:00:30"},
        {5,  50.0, 20.0,  4.0, "08:00:40"},
        {6,  70.0, 30.0,  5.0, "08:00:50"},
        {7,  90.0, 40.0,  6.0, "08:01:00"},
        {8, 105.0, 50.0,  7.0, "08:01:10"},
        {9, 115.0, 60.0,  8.0, "08:01:20"},  
        {10, 80.0, 45.0,  5.0, "08:01:30"},
    };
    ofstream outFile("path_log.csv");
    outFile << "waypoint_id,x,y,z,timestamp\n";
    for (int i = 0; i < NUM_POINTS; i++) {
        outFile << path[i].id        << ","
                << path[i].x        << ","
                << path[i].y        << ","
                << path[i].z        << ","
                << path[i].timestamp << "\n";
    }
    outFile.close();
    cout << "Path logged to path_log.csv\n\n";
    float totalDistance = 0.0;
    int flaggedCount = 0;
    cout << "        ROBOT PATH ANALYSIS               \n";
    cout << "==========================================\n";
    for (int i = 0; i < NUM_POINTS; i++) {
        string flag = "";
        if (path[i].x > 100.0) {
            flag = " <<< OUT OF SAFE ZONE";
            flaggedCount++;
        }
        cout << "WP " << path[i].id
             << " | X:" << path[i].x
             << " Y:"   << path[i].y
             << " Z:"   << path[i].z
             << " @ "   << path[i].timestamp
             << flag << "\n";

        if (i > 0) {
            totalDistance += euclideanDistance(path[i-1], path[i]);
        }
    }
    float totalTime = 90.0;
    float avgSpeed = totalDistance / totalTime;
    cout << "------------------------------------------\n";
    cout << "Total Distance : " << totalDistance << " units\n";
    cout << "Average Speed  : " << avgSpeed      << " units/sec\n";
    cout << "Flagged Points : " << flaggedCount  << " waypoints outside safe zone\n";
    ofstream appendFile("path_log.csv", ios::app);
    appendFile << "\n# SUMMARY\n";
    appendFile << "total_distance," << totalDistance << "\n";
    appendFile << "average_speed,"  << avgSpeed      << "\n";
    appendFile << "flagged_waypoints," << flaggedCount << "\n";
    appendFile.close();
    cout << "\nSummary appended to path_log.csv\n";
    return 0;
}
