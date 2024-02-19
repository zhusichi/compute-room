#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"globaIFile.h"
#include<fstream>
#include<vector>
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"


//����Ա��
class Manager : public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι��죨���������룩
	Manager( string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();

	//����ظ�
	bool checkRepeat(int id, int type);

	//ѧ������
	vector<Student>vStu;

	//��ʦ����
	vector<Teacher>vTea;

	//������Ϣ
	vector<ComputerRoom>vCom;
};