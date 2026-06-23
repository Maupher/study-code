#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
T find_largest_value(const std::vector<T>& values)
//not sure how to add this properly or how this is added properly 

struct SensorReading
{
    std::string sensor_name;
    double value;
    std::string unit;
};

class AlertSystem 
{
private:
// all varaibles have to be defined in the head and not later in single functions bc they will be lost after the function finished. Also all attributes have to be private if possible for security reasons.
// Also this-> was missing in some cases which can result in errrors if the names of varaibles are the same in the function and in the class.
//also the names reading and readings was mixed up, similar naming can be also confusing so for better practice could be renamed to diffrent names.
    std::vector<SensorReading> readings;
    std::map<std::string, int> counts;

public:
    void addReading(SensorReading reading)
    {
        this->readings.push_back(reading);
    }

    double calculateAverage(const std::string sensor_name) const // also const was missing here, this is important to avoid accidential changes to varables
    {
        double sum = 0;
        int count = 0;

        for (const SensorReading& reading : readings) //const was missing, this is important to avoid accidential changes to varables
        {
            //hier ein this-> ??
            if (reading.sensor_name == sensor_name)
            {
                sum += reading.value;
                count++;
            }
        }

        if (count == 0) //i didn't find this, this was recommended by auto completion or AI? 
        {
            std::cerr << "No readings found for sensor: " << sensor_name << "\n";
            return 0;
        }

        return sum / count;
    }

    void printSensorNames()
    {

        for (const SensorReading& reading : readings) //const was missing, this is important to avoid accidential changes to varables as well as a referencation of reading to avoid copying and wasting space in the ram. didnt see that in the first go so need to look out for this one 
        {
            this->counts[reading.sensor_name]++;
        }

        for (auto pair : counts)
        {
            std::cout << pair.first << ": " << pair.second << "\n";
        }
    }
};


int main(){

    AlertSystem alertSystem;
    alertSystem.addReading({"Temperature", 22.5, "C"});
    alertSystem.addReading({"Temperature", 23.0, "C"});
    alertSystem.addReading({"Humidity", 45.0, "%"});
    alertSystem.addReading({"Humidity", 50.0, "%"});
    alertSystem.addReading({"Pressure", 1013.0, "hPa"});
    alertSystem.addReading({"Pressure", 1012.5, "hPa"});

    alertSystem.printSensorNames();

    std::cout << "\n\n\tAverage Temperature: " << alertSystem.calculateAverage("Temperature") << " C\n";
    std::cout << "\n\n\tAverage Humidity: " << alertSystem.calculateAverage("Humidity") << " %\n";
    std::cout << "\n\n\tAverage Pressure: " << alertSystem.calculateAverage("Pressure") << " hPa\n";

}