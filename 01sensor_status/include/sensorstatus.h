#ifndef SENSORSTATUS_H
#define SENSORSTATUS_H

#include <vector>
#include <string>

//读取文件的数据，返回vector数组
std::vector<double> readSensorData(const std::string& filename);
double calculateAverage(const std::vector<double>& data);
double findMax(const std::vector<double>& data);
double findMin(const std::vector<double>& data);
//求方差
double calculateVariance(const std::vector<double>& data);
int countAboveThreshold(const std::vector<double>& data,double threshold);

#endif