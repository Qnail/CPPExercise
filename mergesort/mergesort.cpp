//
#include <iostream>

using namespace std;

void merge(int *array,int start,int divider,int end)
{
	int b[end-start+1];
	int i=start,j=divider;
	for(int k =0;k<end-start+1;k++)
	{
		if(i==divider-1)
		{
			for(int m=j;m<end;m++)
			{
				b[k]=array[m];
			}
		}
		if(j==end-1)
		{
			for(int m = i;m<divider;m++)
			{
				b[k]=array[m];
			}
		}
		if(array[start]>array[divider])
		{
			b[k] =array[i];
			i++;
		}
		if(array[start]<array[divider])
		{
			b[k]= array[j];
			j++;
		}
	}
	for(int k =0;k<end-start+1;k++)
	{
		array[start+k]=b[k];
	}
}

void mergeSort(int *array,int p, int r)
{
	if(p<r)
	{
		int d= (p+r)/2;
		mergeSort(array,p,d);
		mergeSort(array,d,r);
		merge(array,p,d,r);
	}
}

int main()
{
	int a[7] = {5,4,6,2,3,7,9};
	int *b = a;
	mergeSort(b,0,7);
	for(int i = 0;i<7;i++)
	{
		cout<<a[i]<<' ';
	}
}