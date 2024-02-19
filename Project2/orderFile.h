#pragma once
#include<iostream>
using namespace std;
#include"globaIFile.h"
#include<fstream>
#include<map>
#include<string>

//
class OrderFile
{
public:
	static OrderFile& GetInstance()
	{
		static OrderFile instance;
		return instance;
	}
	//更新预约记录
	void updateOrder();

	//记录预约条数
	int m_Size;

	//记录所有预约信息的容器  key记录条数 value记录键值对信息
	map<int, map<string, string>>m_orderData;
private:
	//构造函数
	OrderFile();
};