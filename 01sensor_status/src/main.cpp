#include "sensorstatus.h"

#include <vector>
#include <iostream>

int main()
{
    std::string filename="data/sensor_data.txt";
    std::vector data=readSensorData(filename);

    std::cout << "Sensor Data Statistics" << std::endl;
    std::cout << "Data count:" << data.size() << std::endl;

    return 0;
}