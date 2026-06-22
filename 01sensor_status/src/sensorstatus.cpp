#include "sensorstatus.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

std::vector<double> readSensorData(const std::string& filename)
{
    std::vector<double> data;
    std::ifstream file(filename);//打开filename这个文件，创建类file
    
    if (!file.is_open())//打开成功，file.is_open()返回true
    {
        throw std::runtime_error("Cannot open file:" + filename);
    }

    double value;
    while(file >> value) // 从文件读取一个数字，存到value里，>>是流提取运算符，自动跳过空格和换行，一个接一个读取数据
    {
        data.push_back(value);//往数组末尾追加一个元素。
    }
    
    return data;
}

double calculateAverage(const std::vector<double>& data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }
    double sum=0.0;
    for (double value : data) // 从data这个容器里，一个一个取元素，放进value里执行循环
    {
        sum+=value;
    }
    return sum/data.size();
}

double findMax(const std::vector<double>& data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }
    double maxValue=data[0];
    for (double value : data)
    {
        if(value > maxValue)
        {
            maxValue=value;
        }
    }
    return maxValue;
}

double findMin(const std::vector<double>& data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }
    double minValue=data[0];
    for (double value : data)
    {
        if(value < minValue)
        {
            minValue=value;
        }
    }
    return minValue;
}

double calculateVariance(const std::vector<double>& data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }
    double average = calculateAverage(data);//调用前有声明就可以用
    double sum=0.0;
    for (double value:data)
    {
        double diff=value-average;
        sum+=diff*diff;
    }
    return sum/data.size();
}

int countAboveThreshold(const std::vector<double>& data,double threshold)
{
    int count = 0;
    for (double value : data)
    {
        if (value > threshold)
        {
            count ++;
        }
    }
    return count ;
}