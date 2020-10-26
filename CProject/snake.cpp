#include <stdio.h>
#include <stdlib.h>
#include <windows.h>    //光标设置
#include <time.h>		//食物随机
#include <conio.h>		//按键监控

//-------------辅助宏--------------------
#define MAPHEIGHT 25    //地图的属性
#define MAPWIDTH  60
#define SNAKESIZE 50	//蛇的最大节数


//--------------数据设计------------------
//食物的结构体
struct
{
	//坐标
	int x;
	int y;
}food;
//蛇的结构体
struct
{
	//记录蛇每一节的坐标
	int x[SNAKESIZE];
	int y[SNAKESIZE];
	int len;		//蛇的长度
	int speed;		//蛇的移动速度
}snake;  


//------------全局变量---------------------
int key = 'w';		//初始化移动方向
int changeFlag = 0;	//蛇的变化的标记


//------------模块设计---------------------
//1、画地图
void drawMap();
//2、产生食物
void createFood();
//3、按键操作
void keyDown();
//4、蛇的状态，判断是否结束游戏
int snakeStatus();
//5、辅助函数：光标移动
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


//1、画地图
void drawMap()
{	
	//⊙█
	srand((unsigned int)time(NULL));		//随机函数种子
	//边界
	for (int i = 0; i <= MAPHEIGHT; i++) 
	{
		gotoxy(0, i);
		printf("█");
		gotoxy(MAPWIDTH, i);
		printf("█");
	}
	for (int i = 0; i <= MAPWIDTH;i += 2) 
	{
		gotoxy(i, 0);
		printf("█");
		gotoxy(i,MAPHEIGHT);
		printf("█");
	}
	//蛇
	snake.len = 3;
	snake.speed = 300;
	snake.x[0] = MAPWIDTH / 2;
	snake.y[0] = MAPHEIGHT / 2;
	gotoxy(snake.x[0],snake.y[0]);
	printf("█");
	for (int k = 1; k < snake.len; k++)
	{
		snake.x[k] = snake.x[k - 1] + 2;
		snake.y[k] = snake.x[k - 1];
		gotoxy(snake.x[k], snake.y[k]);
		printf("█");
	}
	//食物
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
	printf("⊙");
}


//2、产生食物
void createFood()
{
	//蛇吃食
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
		printf("⊙");
		snake.len++;
		//gotoxy(MAPHEIGHT,MAPWIDTH+4);
		//printf("%d",snake.len);
		changeFlag = 1;
	}
	
}


//3、按键操作
void keyDown()
{
	//无按键处理
	if (_kbhit())		//kbhit() 在执行时,检测是否有按键按下,有按下返回键值,没有按下返回0; 是非阻塞函数
	{
		//有按键就接收
		fflush(stdin);		//清空缓存区
		key = _getch();
	}
	//擦除
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
	//移动方向
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
	printf("█");
	changeFlag = 0;
	gotoxy(MAPHEIGHT + 2, 0);
}


//4、蛇的状态，判断是否结束游戏
int snakeStatus() 
{
	//蛇撞墙
	if (snake.x[0] == 0 || snake.x[0] == MAPWIDTH - 2 || snake.y[0] == 0 || snake.y[0] == MAPHEIGHT - 1)
	{
		return 0;
	}
	//蛇撞到自己
	for (int k = 1; k < snake.len; k++)
	{
		if (snake.x[0] == snake.x[k] && snake.y[k] == snake.y[0])
		{
			return 0;
		}
	}
	return 1;
}


//5、辅助：光标移动
void gotoxy(int x, int y)
{
	//找到控制台
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//光标的结构体
	COORD coord;
	//设置坐标
	coord.X = x;
	coord.Y = y;
	//同步到控制台
	SetConsoleCursorPosition(handle,coord);
}