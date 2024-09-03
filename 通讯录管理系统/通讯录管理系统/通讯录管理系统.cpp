#include<iostream>
using namespace std;
#define max 1000

//�����ϵ�˽ṹ��
struct person 
{
	string name;    //����
	int sex;        //1��������2��Ů��
	int age;        //����
	string phone;   //�绰����
	string address; //סַ
};

//���ͨѶ¼�ṹ��
struct addressbooks 
{
	//ͨѶ¼�б������ϵ������
	struct person arr[max];
	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int size;
};

//1�������ϵ��
void addperson(addressbooks *abs)
{
	//�ж�ͨѶ���Ƿ��������������������
	if (abs->size == max) 
	{
		cout << "ͨѶ¼�������޷��ٴ���ӣ�" << endl;
		return;
	} 
	else 
	{
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->arr[abs->size].name = name;

		//�Ա�
		cout << "�������Ա�" << endl; 
		cout << "1---��" << "   " << "2---Ů" << endl; 
		int sex = 0;

		while (true) 
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->arr[abs->size].sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		
		//����
		cout << "���������䣻" << endl;
		int age = 0;
		cin >> age;
		abs->arr[abs->size].age = age;

		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->arr[abs->size].phone = phone;

		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->arr[abs->size].address = address;

		//����ͨѶ¼����
		abs->size++;

		cout << "������ӳɹ�" << endl;

		system("pause");//�밴���������
		system("cls");  //��������
	}
}

//2����ʾ���е���ϵ��
void showPerson(addressbooks* abs) 
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ�㣬���Ϊ�㣬��ʾ��¼Ϊ��
	//�����Ϊ�㣬��ʾ��¼����ϵ����Ϣ
	if (abs->size == 0) 
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else 
	{
		for (int i = 0; i < abs->size; i++) 
		{
			cout << "������" << abs->arr[i].name << "\t";
			cout << "�Ա�" << (abs->arr[i].sex==1?"��":"Ů") << "\t";
			cout << "���䣺" << abs->arr[i].age << "\t";
			cout << "�绰��" << abs->arr[i].phone<< "\t";
			cout << "סַ��" << abs->arr[i].address << endl;
		}
	}

	system("pause");//�밴���������
	system("cls");  //��������
}

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1 ͨѶ¼  ����2 �Ա�����
int exist(addressbooks* abs, string name) 
{
	for (int i = 0; i < abs->size; i++)
	{
		//�ҵ��û������������
		if (abs->arr[i].name == name) 
		{
			return i; //�ҵ��ˣ�����������������е��±���
		}
	}
	return -1; //�������������û���ҵ�������-1
}

//3��ɾ��ָ����ϵ��
void deletePerson(addressbooks* abs) 
{
	cout << "��������Ҫɾ������ϵ��" << endl;

	string name;
	cin >> name;

	int ret = exist(abs, name);//ret==-1  δ�鵽 �� ret��=-1  �鵽��
	if (ret != -1) 
	{
		//���ҵ��ˣ�Ҫ����ɾ������
		for (int i = ret;i < abs->size; i++)
		{
			//����Ǩ��
			abs->arr[i] = abs->arr[i + 1];
		}
		abs->size--;//����ͨѶ¼�е���Ա��
		cout << "ɾ���ɹ�" << endl;
	}
	else 
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//4��������ϵ��
void findPerson(addressbooks* abs) 
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	//�ж�ָ������ϵ���Ƿ����ͨѶ¼��
	int ret = exist(abs, name);

	if (ret != -1) //�ҵ���ϵ��
	{
		cout << "������ " << abs->arr[ret].name << "\t";
		cout << "�Ա� " << abs->arr[ret].sex << "\t";
		cout << "���䣺 " << abs->arr[ret].age << "\t";
		cout << "�绰�� " << abs->arr[ret].phone << "\t";
		cout << "סַ�� " << abs->arr[ret].address << endl;;
	}
	else //δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}
}

//5���޸�ָ����ϵ����Ϣ
void modifyPerson(addressbooks* abs) 
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	
	int ret = exist(abs, name);
	if (ret != -1) //�ҵ���ϵ��
	{
		//����
		string name;
		cin >> name;
		abs->arr[ret].name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << "   " << "2---Ů" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->arr[abs->size].sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->arr[ret].age = age;
		//�绰
		cout << "��������ϵ�绰" << endl;
		string phone;
		cin >> phone;
		abs->arr[ret].phone = phone;
		//סַ
		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->arr[ret].address = address;
		cout << "�޸ĳɹ�" << endl;
	}
	else //δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//6�����������ϵ��
void cleanPerson(addressbooks* abs) 
{
	abs->size = 0;//����ǰ��¼��ϵ��������Ϊ�㣬���߼���ղ���
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

//�˵�����
void showMenu() 
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

int main() {
	
	//����ͨѶ¼�ṹ�����
	addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա�ĸ���
	abs.size = 0;


	int select = 0; //�����û�ѡ������ı���

	while (true) 
	{
		//�˵�����
		showMenu();
		
		cin >> select;

		switch (select)
		{
		case 1: //1�������ϵ��
			addperson(&abs); //���õ�ַ���ݿ����޸�ʵ��
			break;
		case 2: //2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: //3��ɾ����ϵ��
		deletePerson(&abs);
			break;
		case 4: //4��������ϵ��
			findPerson(&abs);
			break;
		case 5: //5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: //6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0: //0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");

	return 0;
}