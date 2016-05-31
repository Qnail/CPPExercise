/*cpp*/

#include <iostream>
#include <string.h>
using namespace std;
/*
2 3 2
111
010

100
100
*/
void count_one_zero(int *a,int flag,int *one,int **group,int n,int m,int k,int roundCount)
{
	for(int i =0;i<k;i++)
	{
		if(group[roundCount][i]==flag)
		{
			for(int j=0;j<n*m;j++)
			{
				if(a[i*n*m+j]==1)
				{
					one[j]++;
				}else{
					one[j]--;
				}
			}
		}
	}

}

int minDiff_index(int *one,int n,int m)
{
	int minDiff = one[0];
	int index;
	for(int i =0;i<n*m;i++)
	{
		if(minDiff==0)
		{
			return i;
		}
		if(minDiff>one[i])
		{
			minDiff=one[i];
			index = i;		
		}
	}
	return index;
}

int merge(int *a,int *one,int **group,int n, int m,int k,int roundCount)
{
	roundCount++;
	int index = minDiff_index(one,n,m);
	for(int i =0;i<k;i++)
	{
		group[roundCount][i] += a[k*n*m+index];
	}

	memset(one,0,sizeof(one));
	count_one_zero(a,one,group,n,m,k,roundCount);

	merge(a,one,group,n,m,k);
	//merge(a,zero,group,n,m,k);
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	char a[n*m*k];
	int one[n*m],zero[n*m];
	int index;
	int group[k][k];
	int roundCount=0;
	int count=k;
	int result;
	memset(one,0,sizeof(one));
	memset(group,-1,sizeof(group));
	for(int l = 0;l<n*m*k;l++)
	{
		if(l%(n+1)==0)
		{
			cin.get();
		}
		a[l]=cin.get();
		if(l==n*m-1)
		{
			cin.get();
		}
		if(a[l]=='1')
		{
			one[l%(n*m)]++;
		}
		else{
			one[l%(n*m)]--;
		}
	}


	for(int i = 0 ;i<k;i++)
	{
		for(int j = 0 ;j<k;j++)
		{
			cout<<group[i][j];
		}
		cout<<endl;
	}

}