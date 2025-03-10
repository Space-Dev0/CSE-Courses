#include <iostream>
#include <vector>

class Drone
{
private:
    int droneID;
    double batteryLevel;
    double x, y;
    bool missionAssigned;

public:
    Drone()
    {
        std::cin >> droneID >> batteryLevel >> x >> y;
    }
};

class Mission
{
private:
    int droneID;
    double batteryLevel;
    double x, y;
    bool missionAssigned;

public:
    Mission();
};

class SwarmController
{
private:
public:
    SwarmController();
};

int main()
{
    int numDrones, numMissions;
    std::cout << "Enter num of Drones: ";
    std::cin >> numDrones;
    Drone drones[numDrones];
    std::cout << "Enter num of Missions: ";
    std::cin >> numMissions;
    std::vector<Drone>;
}