#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include"globaIFile.h"
#include"student.h"
#include"teacher.h"
#include"maneger.h"


//进入学生子菜单界面
void studentMenu(Identity*& manager)
{
	while (true)
	{
		//学生菜单
		manager->operMenu();

		Student* stu = (Student*)manager;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			stu->applyOrder();//申请预约
		}
		else if (select == 2)
		{
			stu->showMyOrder();//查看我的预约
		}
		else if (select == 3)
		{
			stu->shhowAllOrder();//查看所有预约
		}
		else if (select == 4)
		{
			stu->cancelOrder();//取消预约
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

//进入教师子菜单界面
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
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validOrder();
		}
		else 
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//进入管理员子菜单界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//管理员菜单
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "清空预约记录" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	
}
//登录功能   操作文件名      操作身份类型
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id=0;
	string name;
	string pwd;

	if (type == 1)//学生登录
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2)//教师登录
	{
		cout << "请输入你的教资编号" << endl;
		cin >> id;
	}

	cout << "请输入用户名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生验证登录
		int fId;//从文件中读取的id号
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息做比对
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师验证登录
		int fId;//从文件中读取的id号
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息做比对
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功" << endl;
				
				system("pause");
				system("cls");
				person = new Teacher(id,name,pwd);
				//进入老师的子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员验证登录
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取密码
		while (ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息做比对
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功" << endl;

				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return; 
			}
		}
	}

	cout << "验证登录失败" << endl;
	system("pause");
	system("cls");
	return;
}
int main()
{
	int select = 0;

	while (true)
	{
		cout << "=============== 欢迎来到传智播客机房预约系统 ===============" << endl;
		cout << endl << "请输入你的身份" << endl;
		cout << "\t\t --------------------------- \n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|       1.学生代表          |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|       2.老    师          |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|       3.管 理 员          |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|       0.退    出          |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t --------------------------- \n";
		cout << "输入您的选择：";

		cin >> select;//接受用户选择

		switch (select)
		{
		case 1://学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}