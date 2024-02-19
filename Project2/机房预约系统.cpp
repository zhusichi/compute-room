#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include"globaIFile.h"
#include"student.h"
#include"teacher.h"
#include"maneger.h"


//����ѧ���Ӳ˵�����
void studentMenu(Identity*& manager)
{
	while (true)
	{
		//ѧ���˵�
		manager->operMenu();

		Student* stu = (Student*)manager;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			stu->applyOrder();//����ԤԼ
		}
		else if (select == 2)
		{
			stu->showMyOrder();//�鿴�ҵ�ԤԼ
		}
		else if (select == 3)
		{
			stu->shhowAllOrder();//�鿴����ԤԼ
		}
		else if (select == 4)
		{
			stu->cancelOrder();//ȡ��ԤԼ
		}
		else
		{
			delete manager;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�����ʦ�Ӳ˵�����
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			tea->validOrder();
		}
		else 
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//�������Ա�Ӳ˵�����
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//����Ա�˵�
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "���ԤԼ��¼" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	
}
//��¼����   �����ļ���      �����������
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	int id=0;
	string name;
	string pwd;

	if (type == 1)//ѧ����¼
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)//��ʦ��¼
	{
		cout << "��������Ľ��ʱ��" << endl;
		cin >> id;
	}

	cout << "�������û���" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ����֤��¼
		int fId;//���ļ��ж�ȡ��id��
		string fName;//���ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ����
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���ȶ�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ���Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��֤��¼
		int fId;//���ļ��ж�ȡ��id��
		string fName;//���ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ����
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���ȶ�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				
				system("pause");
				system("cls");
				person = new Teacher(id,name,pwd);
				//������ʦ���Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��֤��¼
		string fName;//���ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ����
		while (ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���ȶ�
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ�" << endl;

				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return; 
			}
		}
	}

	cout << "��֤��¼ʧ��" << endl;
	system("pause");
	system("cls");
	return;
}
int main()
{
	int select = 0;

	while (true)
	{
		cout << "=============== ��ӭ�������ǲ��ͻ���ԤԼϵͳ ===============" << endl;
		cout << endl << "������������" << endl;
		cout << "\t\t --------------------------- \n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|       1.ѧ������          |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|       2.��    ʦ          |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|       3.�� �� Ա          |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|       0.��    ��          |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t --------------------------- \n";
		cout << "��������ѡ��";

		cin >> select;//�����û�ѡ��

		switch (select)
		{
		case 1://ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}