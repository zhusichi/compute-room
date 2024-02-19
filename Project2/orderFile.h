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
	//����ԤԼ��¼
	void updateOrder();

	//��¼ԤԼ����
	int m_Size;

	//��¼����ԤԼ��Ϣ������  key��¼���� value��¼��ֵ����Ϣ
	map<int, map<string, string>>m_orderData;
private:
	//���캯��
	OrderFile();
};