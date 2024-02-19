#include"maneger.h"

//默认构造
Manager::Manager()
{

}

//有参构造（姓名、密码）
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_pwd = pwd;

	//初始化容器
	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量为：" << vCom.size() << endl;
}

//菜单界面
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t --------------------------- \n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|       1.添加账号          |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|       2.查看账号          |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|       3.查看机房          |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|       4.清空预约          |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|       0.注销登录          |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t --------------------------- \n";
	cout << "请选择您的操作："<<endl;
}

//添加账号
void Manager::addPerson()
{

	cout << "请选择你要创建的账号" << endl;
	cout << "1.学生账号" << endl;
	cout << "2.老师账号" << endl;

	int select = 0;
	cin >> select;//接受用户选项

	ofstream ofs;//文件操作对象
	string fileName;//操作文件名

	if (select == 1)
	{
		//添加学生
		fileName = STUDENT_FILE;
	}
	else
	{
		//添加老师
		fileName = TEACHER_FILE;
	}
	//利用追加的方式写文件
	ofs.open(fileName, ios::out | ios::app);

	int id;//学号
	string name;//姓名
	string pwd;//密码

	cout << "请输入账号" << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id,select);
		if (ret)
			cout << "账号重复，请重新输入" << endl;
		else
			break;
	}
	

	cout << "请输入姓名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功";

	system("pause");
	system("cls");

	ofs.close();
	this->initVector();
	return;
}

//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for (auto a : vStu)
		{
			cout << "账号：" << a.m_id << " 姓名：" << a.m_Name 
				<< " 密码：" << a.m_pwd << endl;
		}
	}
	else
	{
		cout << "所有老师信息如下：" << endl;
		for (auto a : vTea)
		{
			cout << "账号：" << a.m_EmpId << "姓名：" << a.m_Name
				<< "密码：" << a.m_pwd << endl;
		}
	}
	system("pause");
	system("cls");

}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房的信息如下：" << endl;

	for (auto a : vCom)
	{
		cout << "机房编号：" << a.m_ComId << " 机房最大容量：" << a.m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_id && ifs >> s.m_Name && ifs >> s.m_pwd)
	{
		vStu.push_back(s);
	}
	cout << "学生的数量为：" << vStu.size() << endl;
	
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_pwd)
	{
		vTea.push_back(t);
	}
	cout << "老师的数量为：" << vTea.size() << endl;

	ifs.close();
}

//检测重复       学生      检测类型
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (auto a : vStu)
		{
			if (id == a.m_id)
				return true;
		}
	}
	else
	{
		for (auto a : vTea)
		{
			if (id == a.m_EmpId)
				return true;
		}
	}
	return false;
}