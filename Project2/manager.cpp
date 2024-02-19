#include"maneger.h"

//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι��죨���������룩
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_pwd = pwd;

	//��ʼ������
	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "����������Ϊ��" << vCom.size() << endl;
}

//�˵�����
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t --------------------------- \n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|       1.����˺�          |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|       2.�鿴�˺�          |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|       3.�鿴����          |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|       4.���ԤԼ          |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|       0.ע����¼          |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t --------------------------- \n";
	cout << "��ѡ�����Ĳ�����"<<endl;
}

//����˺�
void Manager::addPerson()
{

	cout << "��ѡ����Ҫ�������˺�" << endl;
	cout << "1.ѧ���˺�" << endl;
	cout << "2.��ʦ�˺�" << endl;

	int select = 0;
	cin >> select;//�����û�ѡ��

	ofstream ofs;//�ļ���������
	string fileName;//�����ļ���

	if (select == 1)
	{
		//���ѧ��
		fileName = STUDENT_FILE;
	}
	else
	{
		//�����ʦ
		fileName = TEACHER_FILE;
	}
	//����׷�ӵķ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id;//ѧ��
	string name;//����
	string pwd;//����

	cout << "�������˺�" << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id,select);
		if (ret)
			cout << "�˺��ظ�������������" << endl;
		else
			break;
	}
	

	cout << "����������" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ�";

	system("pause");
	system("cls");

	ofs.close();
	this->initVector();
	return;
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴����" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for (auto a : vStu)
		{
			cout << "�˺ţ�" << a.m_id << " ������" << a.m_Name 
				<< " ���룺" << a.m_pwd << endl;
		}
	}
	else
	{
		cout << "������ʦ��Ϣ���£�" << endl;
		for (auto a : vTea)
		{
			cout << "�˺ţ�" << a.m_EmpId << "������" << a.m_Name
				<< "���룺" << a.m_pwd << endl;
		}
	}
	system("pause");
	system("cls");

}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "��������Ϣ���£�" << endl;

	for (auto a : vCom)
	{
		cout << "������ţ�" << a.m_ComId << " �������������" << a.m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_id && ifs >> s.m_Name && ifs >> s.m_pwd)
	{
		vStu.push_back(s);
	}
	cout << "ѧ��������Ϊ��" << vStu.size() << endl;
	
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ʦ������Ϊ��" << vTea.size() << endl;

	ifs.close();
}

//����ظ�       ѧ��      �������
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