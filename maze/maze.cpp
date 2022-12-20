#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
struct direction
{
	direction(int d)
	{
		switch (d)
		{
		case 0: //右
			incX = 0; incY = 1;
			break;
		case 1: //下
			incX = 1; incY = 0;
			break;
		case 2: //左
			incX = 0; incY = -1;
			break;
		case 4: //上
			incX = -1; incY = 0;
			break;
		}
	}
	int incX;
	int incY;

};


struct location
{
	int x;
	int y;
	int d;
};

class stack
{
public:
	stack()
	{
		top = -1;
		size = MAX_SIZE;
		data = new location[size];
	}
	location pop()
	{
		if (!isNull())
		{
			return data[top--];
		}
	}
	location get_top()
	{
		if (!isNull())
		{
			return data[top];
		}
	}
	void push(location p)
	{
		if (!isFull())
		{
			data[++top] = p;
		}
	}
	bool isNull()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()
	{
		if (top == MAX_SIZE - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	location* data;
	int top;
	int size;
};

bool out_maze(int maze[10][10], stack& st)
{
	location d1, temp_this, temp_next;
	int x, y, d;
	d1.x = 1;
	d1.y = 1;
	d1.d = -1;
	st.push(d1);
	maze[1][1] = -1;
	while (!st.isNull())
	{
		temp_this = st.pop();
		x = temp_this.x;
		y = temp_this.y;
		d = temp_this.d + 1;
		while (d < 4)
		{
			temp_next.x = x + direction(d).incX;
			temp_next.y = y + direction(d).incY;
			if (maze[temp_next.x][temp_next.y] == 0)
			{
				temp_this.x = x;
				temp_this.y = y;
				temp_this.d = d;
				st.push(temp_this);
				maze[temp_next.x][temp_next.y] = -1;
				x = temp_next.x;
				y = temp_next.y;
				d = 0;
			}
			else
			{
				d++;
			}
		}
		if (maze[8][8] == -1)
		{
			temp_this.x = 8;
			temp_this.y = 8;
			st.push(temp_this);
			return true;
		}
	}
	return false;
}


void creat_maze(int maze[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		maze[0][i] = 1;
		maze[i][0] = 1;
		maze[i][9] = 1;
		maze[9][i] = 1;
	}
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			maze[i][j] = 0;
		}
	}
	maze[1][3] = 1;
	maze[1][7] = 1;
	maze[2][3] = 1;
	maze[2][7] = 1;
	maze[3][5] = 1;
	maze[3][6] = 1;
	maze[4][2] = 1;
	maze[4][3] = 1;
	maze[4][4] = 1;
	maze[5][4] = 1;
	maze[6][2] = 1;
	maze[6][6] = 1;
	maze[7][2] = 1;
	maze[7][3] = 1;
	maze[7][4] = 1;
	maze[7][6] = 1;
	maze[7][7] = 1;
	maze[8][1] = 1;


	//手动输入
	//for (int i = 1; i < 9; i++)
	//{
	//	for (int j = 1; j < 9; j++)
	//	{
	//		cout << "请输入maze第" << i << "行" << j << "列的值(0或1）" << endl;
	//		cin >> maze[i][j];
	//	}
	//}
}

void display_maze(int maze[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
}

void display_stack(stack st)
{
	while (!st.isNull())
	{
		location temp;
		temp = st.pop();
		cout << temp.x << "," << temp.y << endl;;
	}
}



int main()
{
	int maze[10][10];
	creat_maze(maze);
	cout << "迷宫如下：" << endl;
	display_maze(maze);
	stack st;
	out_maze(maze, st);
	display_stack(st);


	system("pause");
	return 0;
}