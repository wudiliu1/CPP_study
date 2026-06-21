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