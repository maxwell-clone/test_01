#include<iostream>
using namespace std;
#define max 1000

//设计联系人结构体
struct person 
{
	string name;    //姓名
	int sex;        //1、男生；2、女生
	int age;        //年龄
	string phone;   //电话号码
	string address; //住址
};

//设计通讯录结构体
struct addressbooks 
{
	//通讯录中保存的联系人数组
	struct person arr[max];
	//通讯录中当前记录联系人个数
	int size;
};

//1、添加联系人
void addperson(addressbooks *abs)
{
	//判断通讯里是否已满，若已满则不再添加
	if (abs->size == max) 
	{
		cout << "通讯录已满，无法再次添加！" << endl;
		return;
	} 
	else 
	{
		//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->arr[abs->size].name = name;

		//性别
		cout << "请输入性别：" << endl; 
		cout << "1---男" << "   " << "2---女" << endl; 
		int sex = 0;

		while (true) 
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->arr[abs->size].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//年龄
		cout << "请输入年龄；" << endl;
		int age = 0;
		cin >> age;
		abs->arr[abs->size].age = age;

		//电话
		cout << "请输入联系电话；" << endl;
		string phone;
		cin >> phone;
		abs->arr[abs->size].phone = phone;

		//住址
		cout << "请输入家庭住址；" << endl;
		string address;
		cin >> address;
		abs->arr[abs->size].address = address;

		//更新通讯录人数
		abs->size++;

		cout << "您已添加成功" << endl;

		system("pause");//请按任意键继续
		system("cls");  //清屏操作
	}
}

//2、显示所有的联系人
void showPerson(addressbooks* abs) 
{
	//判断通讯录中人数是否为零，如果为零，提示记录为空
	//如果不为零，显示记录的联系人信息
	if (abs->size == 0) 
	{
		cout << "当前记录为空" << endl;
	}
	else 
	{
		for (int i = 0; i < abs->size; i++) 
		{
			cout << "姓名：" << abs->arr[i].name << "\t";
			cout << "性别：" << (abs->arr[i].sex==1?"男":"女") << "\t";
			cout << "年龄：" << abs->arr[i].age << "\t";
			cout << "电话：" << abs->arr[i].phone<< "\t";
			cout << "住址：" << abs->arr[i].address << endl;
		}
	}

	system("pause");//请按任意键继续
	system("cls");  //清屏操作
}

//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1 通讯录  参数2 对比姓名
int exist(addressbooks* abs, string name) 
{
	for (int i = 0; i < abs->size; i++)
	{
		//找到用户输入的姓名了
		if (abs->arr[i].name == name) 
		{
			return i; //找到了，返回这个人在数组中的下标编号
		}
	}
	return -1; //如果遍历结束都没有找到，返回-1
}

//3、删除指定联系人
void deletePerson(addressbooks* abs) 
{
	cout << "请输入您要删除的联系人" << endl;

	string name;
	cin >> name;

	int ret = exist(abs, name);//ret==-1  未查到 ； ret！=-1  查到了
	if (ret != -1) 
	{
		//查找到人，要进行删除操作
		for (int i = ret;i < abs->size; i++)
		{
			//数据迁移
			abs->arr[i] = abs->arr[i + 1];
		}
		abs->size--;//更新通讯录中的人员数
		cout << "删除成功" << endl;
	}
	else 
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//4、查找联系人
void findPerson(addressbooks* abs) 
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	//判断指定的联系人是否存在通讯录中
	int ret = exist(abs, name);

	if (ret != -1) //找到联系人
	{
		cout << "姓名： " << abs->arr[ret].name << "\t";
		cout << "性别： " << abs->arr[ret].sex << "\t";
		cout << "年龄： " << abs->arr[ret].age << "\t";
		cout << "电话： " << abs->arr[ret].phone << "\t";
		cout << "住址： " << abs->arr[ret].address << endl;;
	}
	else //未找到联系人
	{
		cout << "查无此人" << endl;
	}
}

//5、修改指定联系人信息
void modifyPerson(addressbooks* abs) 
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	
	int ret = exist(abs, name);
	if (ret != -1) //找到联系人
	{
		//姓名
		string name;
		cin >> name;
		abs->arr[ret].name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << "   " << "2---女" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->arr[abs->size].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->arr[ret].age = age;
		//电话
		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;
		abs->arr[ret].phone = phone;
		//住址
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->arr[ret].address = address;
		cout << "修改成功" << endl;
	}
	else //未找到联系人
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//6、清空所有联系人
void cleanPerson(addressbooks* abs) 
{
	abs->size = 0;//将当前记录联系人数量置为零，做逻辑清空操作
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

//菜单界面
void showMenu() 
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

int main() {
	
	//创建通讯录结构体变量
	addressbooks abs;
	//初始化通讯录中当前人员的个数
	abs.size = 0;


	int select = 0; //创建用户选择输入的变量

	while (true) 
	{
		//菜单调用
		showMenu();
		
		cin >> select;

		switch (select)
		{
		case 1: //1、添加联系人
			addperson(&abs); //利用地址传递可以修改实参
			break;
		case 2: //2、显示联系人
			showPerson(&abs);
			break;
		case 3: //3、删除联系人
		deletePerson(&abs);
			break;
		case 4: //4、查找联系人
			findPerson(&abs);
			break;
		case 5: //5、修改联系人
			modifyPerson(&abs);
			break;
		case 6: //6、清空联系人
			cleanPerson(&abs);
			break;
		case 0: //0、退出通讯录
			cout << "欢迎下次使用" << endl;
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