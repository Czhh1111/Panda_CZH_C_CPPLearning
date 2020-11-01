#include <iostream>
#include <string>
using namespace std;

//��������
void menu();

//ȫ�ֱ���
#define MAX 1000


//��ϵ�˽ṹ��
struct Person
{
	string name;
	int sex;
	int age;
	string phone;
	string address;
};

//ͨѶ¼�ṹ��
struct AddressBook
{
	struct Person arr[MAX];
	int size;
};


//�˵�
void menu()
{
	cout << "*****************************" << endl;
	cout << "*****   1�������ϵ��   *****" << endl;
	cout << "*****   2����ʾ��ϵ��   *****" << endl;
	cout << "*****   3��ɾ����ϵ��   *****" << endl;
	cout << "*****   4��������ϵ��   *****" << endl;
	cout << "*****   5���޸���ϵ��   *****" << endl;
	cout << "*****   6�������ϵ��   *****" << endl;
	cout << "*****   0���˳�ͨѶ¼   *****" << endl;
	cout << "*****************************" << endl;
}


//�����ϵ��
void AddPerson(AddressBook* book)
{
	cout << "��������ϵ�˵�����" << endl;
	cin >> book->arr[book->size].name;
	cout << "��������ϵ�˵��Ա�" << endl;
	cout << "1���Ա���" << endl;
	cout << "2���Ա�Ů" << endl;
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
			cout << "��������������������룡" << endl;
		}
	}
	cout << "��������ϵ�˵�����" << endl;
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
			cout << "��������������������룡" << endl;
		}
	}
	cout << "��������ϵ�˵ĵ绰����" << endl;
	cin >> book->arr[book->size].phone;
	cout << "��������ϵ�˵ĵ�ַ" << endl;
	cin >> book->arr[book->size].address;
	book->size++;
	system("pause");
	system("cls");
};

//��ʾ������ϵ��
void showperson(AddressBook book)
{
	for (int i = 0; i < book.size; i++)
	{
		cout << "������" << book.arr[i].name
			<< " �Ա�" << book.arr[i].sex
			<< " ���䣺" << book.arr[i].age
			<< " �绰���룺" << book.arr[i].phone
			<< " סַ�ǣ�" << book.arr[i].address << endl;
	}
	system("pause");
	system("cls");
}

//�����Ա�
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

//ɾ����ϵ��
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

//������ϵ��
void findperson(AddressBook * book,int q)
{
	cout << "������" << book->arr[q].name
		<< " �Ա�" << book->arr[q].sex
		<< " ���䣺" << book->arr[q].age
		<< " �绰���룺" << book->arr[q].phone
		<< " סַ�ǣ�" << book->arr[q].address << endl;
	system("pause");
	system("cls");
}

//�޸���ϵ��
void changeperson(AddressBook* book, int q)
{
	cout << "�������޸ĺ����ϵ�˵�����" << endl;
	cin >> book->arr[q].name;
	cout << "�������޸ĺ����ϵ�˵��Ա�" << endl;
	cout << "1���Ա���" << endl;
	cout << "2���Ա�Ů" << endl;
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
			cout << "��������������������룡" << endl;
		}
	}
	cout << "�������޸ĺ����ϵ�˵�����" << endl;
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
			cout << "��������������������룡" << endl;
		}
	}
	cout << "�������޸ĺ����ϵ�˵ĵ绰����" << endl;
	cin >> book->arr[q].phone;
	cout << "�������޸ĺ����ϵ�˵ĵ�ַ" << endl;
	cin >> book->arr[book->size].address;
	system("pause");
	system("cls");
}

//���ͨѶ¼
void emptyperson(AddressBook * book)
{
	book->size = 0;
	cout << "ͨѶ¼�����" << endl;
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
			cout << "��������Ҫɾ������ϵ�˵�����" << endl;
			int j = find(book);
			if (j == -1)
			{
				cout << "ͨѶ¼���޴���" << endl;
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
			cout << "��������Ҫ���ҵ���ϵ�˵�����" << endl;
			int q = find(book);
			if (q == -1)
			{
				cout << "ͨѶ¼���޴���" << endl;
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
			cout << "��������Ҫ�޸ĵ���ϵ�˵�����" << endl;
			int q = find(book);
			if (q == -1)
			{
				cout << "ͨѶ¼���޴���" << endl;
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
			cout << "ͨѶ¼���˳���" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}