#include <iostream>
#include <vector>
#include <algorithm>

class Drone
{
private:
    int droneID;
    double batteryLevel;
    double x, y;
    bool missionAssigned;
    double distanceSqr;
    friend class SwarmController;

public:
    Drone()
    {
        std::cin >> droneID >> batteryLevel >> x >> y;
    }
};

class Mission
{
private:
    int missionID;
    int requiredDrones;
    double t_x, t_y;
    int priority;
    std::vector<int> assignedDrones;

public:
    friend class SwarmController;
    Mission()
    {
        std::cin >> missionID >> t_x >> t_y >> requiredDrones >> priority;
    }
};

class SwarmController
{
private:
    static bool cmpMissionPriority(Mission M1, Mission M2)
    {
        return M1.priority < M2.priority;
    }
    static bool cmpDrones(Drone d1, Drone d2)
    {
        if (d1.batteryLevel == 0)
            return false;
        return (d1.distanceSqr / d1.batteryLevel) < (d2.distanceSqr / d1.batteryLevel);
    }
    void distanceCalc(Mission &M, std::vector<Drone> &Drones)
    {
        for (auto &&i : Drones)
        {
            if (i.batteryLevel <= 0)
                i.missionAssigned = true;
            else if (i.missionAssigned)
                continue;
            else
                i.distanceSqr = (i.x - M.t_x) * (i.x - M.t_x) + (i.y - M.t_y) * (i.y - M.t_y);
        }
    }

public:
    void assign(std::vector<Drone> &Drones, std::vector<Mission> &Missions)
    {
        std::sort(Missions.begin(), Missions.end(), cmpMissionPriority);
        for (auto &&i : Missions)
        {
            distanceCalc(i, Drones);

            std::erase_if(Drones, [](Drone D)
                          { return D.missionAssigned; });

            if (Drones.size() < i.requiredDrones)
                continue;

            std::sort(Drones.begin(), Drones.end(), cmpDrones);

            for (int j = 0; j < i.requiredDrones; j++)
            {
                i.assignedDrones.push_back(Drones[j].droneID);
                Drones[j].missionAssigned = true;
            }
        }
    }

    void display(std::vector<Mission> Missions)
    {
        for (auto &&i : Missions)
        {
            std::cout << "Mission " << i.missionID;
            if (i.assignedDrones.size() < i.requiredDrones)
            {
                std::cout << " failed: Not enough available drones.\n";
                continue;
            }
            std::cout << " assigned drones: [";
            for (auto &&j : i.assignedDrones)
            {
                std::cout << j << ", ";
            }
            std::cout << "\b\b]\n";
        }
    }
};

int main()
{
    int numDrones, numMissions;

    std::cout << "Enter num of Drones: ";
    std::cin >> numDrones;
    std::vector<Drone> Drones(numDrones);

    std::cout << "Enter num of Missions: ";
    std::cin >> numMissions;
    std::vector<Mission> Missions(numMissions);

    SwarmController S1;

    S1.assign(Drones, Missions);
    S1.display(Missions);
}