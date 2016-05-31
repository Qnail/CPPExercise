//
#include <iostream>

using namespace std;

void merge(int *array, int start, int divider, int end)
{
	int *b = (int *)malloc(sizeof(int)*(end-start+1));
	int i = start, j = divider+1;
	int k;
	for (k = 0;i<=divider&&j<=end; k++)
	{

		if (array[i]>=array[j])
		{
			b[k] = array[j];
			j++;
			continue;
		}
		if (array[i]<array[j])
		{
			b[k] = array[i];
			i++;
			continue;
		}
	}

	if (i == divider + 1)//前半部分结束
	{
		for (int m = j; m <= end; m++)
		{
			b[k++] = array[m];//拷贝后半剩余的部分
		}
	}
	if (j == end + 1)//后半部分结束
	{
		for (int m = i; m <= divider; m++)//拷贝前半剩余的部分
		{
			b[k++] = array[m];
		}
	}
	for (int k = 0; k<end - start + 1; k++)
	{
		array[start + k] = b[k];
	}
}

void mergeSort(int *array, int p, int r)
{
	if (p<r)
	{
		int d = (p + r) / 2;
		mergeSort(array, p, d);
		mergeSort(array, d+1, r);
		merge(array, p, d, r);
	}
}

int main()
{
	int a[7] = { 5, 4, 6, 2, 3, 7, 9 };
	int *c = a;
	mergeSort(c, 0, 6);
	for (int i = 0; i<7; i++)
	{
		cout << c[i] << ' ';
	}
}