#include <iostream>
#include <string>
using namespace std;

//函数声明
void menu();

//全局变量
#define MAX 1000


//联系人结构体
struct Person
{
	string name;
	int sex;
	int age;
	string phone;
	string address;
};

//通讯录结构体
struct AddressBook
{
	struct Person arr[MAX];
	int size;
};


//菜单
void menu()
{
	cout << "*****************************" << endl;
	cout << "*****   1、添加联系人   *****" << endl;
	cout << "*****   2、显示联系人   *****" << endl;
	cout << "*****   3、删除联系人   *****" << endl;
	cout << "*****   4、查找联系人   *****" << endl;
	cout << "*****   5、修改联系人   *****" << endl;
	cout << "*****   6、清空联系人   *****" << endl;
	cout << "*****   0、退出通讯录   *****" << endl;
	cout << "*****************************" << endl;
}


//添加联系人
void AddPerson(AddressBook* book)
{
	cout << "请输入联系人的姓名" << endl;
	cin >> book->arr[book->size].name;
	cout << "请输入联系人的性别" << endl;
	cout << "1、性别男" << endl;
	cout << "2、性别女" << endl;
	int sex = 0;
	while (1)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			book->arr[book->size].sex = sex;
			break;
		}
		else
		{
			cout << "您输入的有误，请重新输入！" << endl;
		}
	}
	cout << "请输入联系人的年龄" << endl;
	int age = 0;
	while (1)
	{
		cin >> age;
		if (age > 0 && age < 100)
		{
			book->arr[book->size].age = age;
			break;
		}
		else
		{
			cout << "您输入的有误，请重新输入！" << endl;
		}
	}
	cout << "请输入联系人的电话号码" << endl;
	cin >> book->arr[book->size].phone;
	cout << "请输入联系人的地址" << endl;
	cin >> book->arr[book->size].address;
	book->size++;
	system("pause");
	system("cls");
};

//显示所有联系人
void showperson(AddressBook book)
{
	for (int i = 0; i < book.size; i++)
	{
		cout << "姓名：" << book.arr[i].name
			<< " 性别：" << book.arr[i].sex
			<< " 年龄：" << book.arr[i].age
			<< " 电话号码：" << book.arr[i].phone
			<< " 住址是：" << book.arr[i].address << endl;
	}
	system("pause");
	system("cls");
}

//姓名对比
int find(AddressBook  book)
{
	string name;
	int j;
	cin >> name;
	for (int i = 0; i < book.size; i++)
	{
		if (name == book.arr[i].name)
		{
			j = i;
			return j;
		}
	}
	return -1;
}

//删除联系人
void delperson(AddressBook* book, int j)
{
	for (j; j < book->size; j++)
	{
		book->arr[j] = book->arr[j + 1];
	}
	book->size--;
	system("pause");
	system("cls");
}

//查找联系人
void findperson(AddressBook * book,int q)
{
	cout << "姓名：" << book->arr[q].name
		<< " 性别：" << book->arr[q].sex
		<< " 年龄：" << book->arr[q].age
		<< " 电话号码：" << book->arr[q].phone
		<< " 住址是：" << book->arr[q].address << endl;
	system("pause");
	system("cls");
}

//修改联系人
void changeperson(AddressBook* book, int q)
{
	cout << "请输入修改后的联系人的姓名" << endl;
	cin >> book->arr[q].name;
	cout << "请输入修改后的联系人的性别" << endl;
	cout << "1、性别男" << endl;
	cout << "2、性别女" << endl;
	int sex = 0;
	while (1)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			book->arr[q].sex = sex;
			break;
		}
		else
		{
			cout << "您输入的有误，请重新输入！" << endl;
		}
	}
	cout << "请输入修改后的联系人的年龄" << endl;
	int age = 0;
	while (1)
	{
		cin >> age;
		if (age > 0 && age < 100)
		{
			book->arr[q].age = age;
			break;
		}
		else
		{
			cout << "您输入的有误，请重新输入！" << endl;
		}
	}
	cout << "请输入修改后的联系人的电话号码" << endl;
	cin >> book->arr[q].phone;
	cout << "请输入修改后的联系人的地址" << endl;
	cin >> book->arr[book->size].address;
	system("pause");
	system("cls");
}

//清空通讯录
void emptyperson(AddressBook * book)
{
	book->size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

int main()
{
	int key = 0;
	struct AddressBook book;
	book.size = 0;
	while (1)
	{
		menu();
		cin >> key;
		switch (key)
		{
		case 1:
			AddPerson(&book);
			break;
		case 2:
			showperson(book);
			break;
		case 3:
		{
			cout << "请输入您要删除的联系人的名字" << endl;
			int j = find(book);
			if (j == -1)
			{
				cout << "通讯录查无此人" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				delperson(&book, j);
			}
		}
			break;
		case 4:
		{
			cout << "请输入您要查找的联系人的名字" << endl;
			int q = find(book);
			if (q == -1)
			{
				cout << "通讯录查无此人" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				findperson(&book, q);
			}
		}
			break;
		case 5:
		{
			cout << "请输入您要修改的联系人的名字" << endl;
			int q = find(book);
			if (q == -1)
			{
				cout << "通讯录查无此人" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				changeperson(&book, q);
			}
		}
			break;
		case 6:
			emptyperson(&book);
			break;
		case 0:
			cout << "通讯录已退出！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}