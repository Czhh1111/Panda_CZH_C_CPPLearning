#include <stdio.h>
#include <stdlib.h>
#include <windows.h>    //�������
#include <time.h>		//ʳ�����
#include <conio.h>		//�������

//-------------������--------------------
#define MAPHEIGHT 25    //��ͼ������
#define MAPWIDTH  60
#define SNAKESIZE 50	//�ߵ�������


//--------------�������------------------
//ʳ��Ľṹ��
struct
{
	//����
	int x;
	int y;
}food;
//�ߵĽṹ��
struct
{
	//��¼��ÿһ�ڵ�����
	int x[SNAKESIZE];
	int y[SNAKESIZE];
	int len;		//�ߵĳ���
	int speed;		//�ߵ��ƶ��ٶ�
}snake;  


//------------ȫ�ֱ���---------------------
int key = 'w';		//��ʼ���ƶ�����
int changeFlag = 0;	//�ߵı仯�ı��


//------------ģ�����---------------------
//1������ͼ
void drawMap();
//2������ʳ��
void createFood();
//3����������
void keyDown();
//4���ߵ�״̬���ж��Ƿ������Ϸ
int snakeStatus();
//5����������������ƶ�
void gotoxy(int x,int y);



int main()
{
	drawMap();
	while (1)
	{
		createFood();
		Sleep(snake.speed);
		keyDown();
		if (!snakeStatus())
		{
			break;
		}
	}
	gotoxy(MAPWIDTH / 2, MAPHEIGHT / 2);
	printf("GameOver\t");
	system("pause");
	return 0;
}


//1������ͼ
void drawMap()
{	
	//�Ѩ�
	srand((unsigned int)time(NULL));		//�����������
	//�߽�
	for (int i = 0; i <= MAPHEIGHT; i++) 
	{
		gotoxy(0, i);
		printf("��");
		gotoxy(MAPWIDTH, i);
		printf("��");
	}
	for (int i = 0; i <= MAPWIDTH;i += 2) 
	{
		gotoxy(i, 0);
		printf("��");
		gotoxy(i,MAPHEIGHT);
		printf("��");
	}
	//��
	snake.len = 3;
	snake.speed = 300;
	snake.x[0] = MAPWIDTH / 2;
	snake.y[0] = MAPHEIGHT / 2;
	gotoxy(snake.x[0],snake.y[0]);
	printf("��");
	for (int k = 1; k < snake.len; k++)
	{
		snake.x[k] = snake.x[k - 1] + 2;
		snake.y[k] = snake.x[k - 1];
		gotoxy(snake.x[k], snake.y[k]);
		printf("��");
	}
	//ʳ��
	while (1)
	{
		food.x = rand() % (MAPWIDTH - 4) + 2;
		food.y = rand() % (MAPHEIGHT - 2) + 1;
		if (food.x % 2 == 0) 
		{
			break;
		}
	}
	gotoxy(food.x, food.y);
	printf("��");
}


//2������ʳ��
void createFood()
{
	//�߳�ʳ
	if (snake.x[0] == food.x && snake.y[0] == food.y) 
	{
		srand((unsigned int)time(NULL));
		while (1)
		{
			int flag = 1;
			food.x = rand() % (MAPWIDTH - 4) + 2;
			food.y = rand() % (MAPHEIGHT - 2) + 1;
			for (int k = 0; k < snake.len; k++)
			{
				if (snake.x[k] == food.x && snake.y[k] == food.y) 
				{
					flag = 0;
					break;
				}
			}
			if(flag&&food.x%2==0)
			{
				break;
			}

		}
		gotoxy(food.x, food.y);
		printf("��");
		snake.len++;
		//gotoxy(MAPHEIGHT,MAPWIDTH+4);
		//printf("%d",snake.len);
		changeFlag = 1;
	}
	
}


//3����������
void keyDown()
{
	//�ް�������
	if (_kbhit())		//kbhit() ��ִ��ʱ,����Ƿ��а�������,�а��·��ؼ�ֵ,û�а��·���0; �Ƿ���������
	{
		//�а����ͽ���
		fflush(stdin);		//��ջ�����
		key = _getch();
	}
	//����
	if (!changeFlag) 
	{
		gotoxy(snake.x[snake.len - 1], snake.y[snake.len - 1]);
		printf("  ");
	}
	for (int i = snake.len - 1; i > 0; i--) 
	{
		snake.x[i] = snake.x[i - 1];
		snake.y[i] = snake.y[i - 1];
	}
	//�ƶ�����
	switch (key) 
	{
	case 'w':
	case 'W':
		snake.y[0]--;
		break;
	case 's':
	case 'S':
		snake.y[0]++;
		break;
	case 'a':
	case 'A':
		snake.x[0] -= 2;
		break;
	case 'd':
	case 'D':
		snake.x[0] += 2;
		break;
	}
	gotoxy(snake.x[0], snake.y[0]);
	printf("��");
	changeFlag = 0;
	gotoxy(MAPHEIGHT + 2, 0);
}


//4���ߵ�״̬���ж��Ƿ������Ϸ
int snakeStatus() 
{
	//��ײǽ
	if (snake.x[0] == 0 || snake.x[0] == MAPWIDTH - 2 || snake.y[0] == 0 || snake.y[0] == MAPHEIGHT - 1)
	{
		return 0;
	}
	//��ײ���Լ�
	for (int k = 1; k < snake.len; k++)
	{
		if (snake.x[0] == snake.x[k] && snake.y[k] == snake.y[0])
		{
			return 0;
		}
	}
	return 1;
}


//5������������ƶ�
void gotoxy(int x, int y)
{
	//�ҵ�����̨
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//���Ľṹ��
	COORD coord;
	//��������
	coord.X = x;
	coord.Y = y;
	//ͬ��������̨
	SetConsoleCursorPosition(handle,coord);
}