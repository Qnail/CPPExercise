//quickSort.cpp
#include <iostream>

using namespace std;

int partition(int *v, int low, int high)
{
	int flag;
	int pivokey = v[low];
	flag = v[low];
	while(low<high)
	{
		while(low<high&&v[high]>=pivokey)--high;
		v[low] = v[high];
		while(low<high&&v[low]<=pivokey)++low;
		v[high]=v[low];
	}
	v[low] = flag;
	return low;
}

void quickSort(int *v, int low , int high)
{
	int pivotloc;
	if(low<high)
	{
		pivotloc = partition(v,low,high);
		quickSort(v,low,pivotloc-1);
		quickSort(v,pivotloc+1,high);
	}
}
int main()
{
	int a[] = {7,1,3,5,2,4,6,9,10};
	int *b = a;
	quickSort(a,0,8);
	for(int i = 0;i<9;i++)
	{
		cout<<b[i]<<" ";
	}
}
