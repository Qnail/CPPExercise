#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
#define MAX_SIZE 100

int maze[10][10] = 
{
	{1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

struct TryPath
{
	int i;
	int j;
	int d;
}path[MAX_SIZE];

//初始化栈指针
int top =-1;

void findPath(int x_begin, int y_begin, int x_end, int y_end)
{
	int i,j,d,find,k;
	top++;
	path[top].i = x_begin;
	path[top].j = y_begin;
	path[top].d = -1;
	maze[x_begin][y_begin] = -1;

	while(top>-1)
	{
		i = path[top].i;
		j = path[top].j;
		d = path[top].d;

		//destination
		if(i==x_end&&j==y_end)
		{
			cout<<"the path is :: ";
			for(k=0;k<top;k++)
			{
				cout<<"\t("<<path[k].i<<" ," << path[k].j<<")";
				if((k+1)%5==0)
				{
					cout<<endl;
				}
			}
			cout<<endl;
			return;
		}

		find = 0;
		while(d<4 && find ==0)
		{
			d++;
			switch(d)
			{
				case 0:
					i = path[top].i-1;
					j = path[top].j;
					break;
				case 1:
					i = path[top].i;
					j = path[top].j+1;
					break;
				case 2:
					i = path[top].i+1;
					j = path[top].j;
					break;
				case 3:
					i = path[top].i;
					j = path[top].j-1;
					break;
			}
			if(maze[i][j]==0)
			{
				find = 1;
			}
		}
		if(find == 1)
		{
			path[top].d = d;
			top++;
			path[top].i = i;
			path[top].j = j;
			path[top].d = -1;
			maze[i][j] = -1;
		}else{
			maze[path[top].i][path[top].j] = 0;
			top--;
		}
	}
	cout<<"no path!"<<endl;
}

int main()
{
	findPath(1,1,8,8);
	return 0;
}