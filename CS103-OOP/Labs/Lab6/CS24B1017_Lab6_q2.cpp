#include <iostream>
#include <vector>

template <typename T>
class Sensor
{
protected:
    T sensorID;
    std::string location;

public:
    Sensor()
    {
        std::cin >> sensorID >> location;
    }
    void reportData()
    {
        std::cout << "Sensor[ID: " << sensorID << ", Location: " << location << "]";
    }
};

template <typename T>
class TemperatureSensor : protected Sensor<T>
{
    double TEMP;

public:
    TemperatureSensor()
    {
        std::cin >> TEMP;
    }
    void reportData()
    {
        Sensor<T>::reportData();
        std::cout << " - Temperature: " << TEMP << "C\n";
    }
};

template <typename T>
class HumiditySensor : protected Sensor<T>
{
    double Humidity;

public:
    HumiditySensor()
    {
        std::cin >> Humidity;
    }
    void reportData()
    {
        Sensor<T>::reportData();
        std::cout << " - Humidity: " << Humidity << "%\n";
    }
};

template <typename T>
class SoilMoistureSensor : protected Sensor<T>
{
    double SoilMoisture;

public:
    SoilMoistureSensor()
    {
        std::cin >> SoilMoisture;
    }
    void reportData()
    {
        Sensor<T>::reportData();
        std::cout << " - Soil Moisture: " << SoilMoisture << "%\n";
    }
};

int main()
{
    std::vector<TemperatureSensor<std::string>> TS;
    std::vector<HumiditySensor<std::string>> HS;
    std::vector<SoilMoistureSensor<std::string>> SMS;
    std::vector<int> SensorNum;
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        std::string type;
        std::cin >> type;
        if (type == "Temperature")
        {
            SensorNum.push_back(0);
            TemperatureSensor<std::string> T;
            TS.push_back(T);
        }
        else if (type == "Humidity")
        {
            SensorNum.push_back(1);
            HumiditySensor<std::string> T;
            HS.push_back(T);
        }
        else
        {
            SensorNum.push_back(2);
            SoilMoistureSensor<std::string> T;
            SMS.push_back(T);
        }
    }

    for (int i = 0; i < num; i++)
    {
        if (SensorNum[i] == 0)
        {
            TS[0].reportData();
            TS.erase(TS.begin());
        }
        else if (SensorNum[i] == 1)
        {
            HS[0].reportData();
            HS.erase(HS.begin());
        }
        else
        {
            SMS[0].reportData();
            SMS.erase(SMS.begin());
        }
    }
}