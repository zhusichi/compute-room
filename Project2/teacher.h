#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"orderFile.h"
#include<vector>

//��ʦ��
class Teacher : public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι��죨ְ����š����������룩
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//��ʦ���
	int m_EmpId;
};