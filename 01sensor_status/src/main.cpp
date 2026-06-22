#include "sensorstatus.h"

#include <vector>
#include <iostream>

int main()
{
    std::string filename="data/sensor_data.txt";
    double threshold = 24.0;
    std::vector data=readSensorData(filename);

    std::cout << "Sensor Data Statistics" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Data count:" << data.size() << std::endl;
    std::cout << "Average: " << calculateAverage(data) << std::endl;
    std::cout << "Maxnum: " << findMax(data) << std::endl;
    std::cout << "Minnum: " << findMin(data) << std::endl;
    std::cout << "Variance: " << calculateVariance(data) << std::endl;
    std::cout << "Above threshold " << threshold << ":" 
        << countAboveThreshold(data,threshold) << std::endl;

    return 0;
}