/*
	@author:datasnail
	@data:2016-08-26
*/
#include <iostream>


/*
	一维数组初始化
*/
void one_demention_array(int n){
	int arr_s1[n];//标准方式一
	int arr_s2[3] = {1,2};//标准方式二
	//int arr_s3[n] = {1,3};//错误方式
	int *arr_p1;//指针方式一
	int *arr_p2 = new int[n];//指针方式二
	delete []arr_p1;//未初始化就删除
	delete []arr_p2;

}


void two_demention_array(int m,int n){
	int arr_s[9][9];//标准方式一
	int value1[9][9] = {{1,1},{2}};//标准方式二;

	const int a = 5;
	//指针方式一
	int (*value2) [a] = new int[m][a];//此处a必须为常量表达式
	delete []value2;

	//指针方式二
	int **value3 = new int*[m];
	for(size_t i =0;i<m;i++)
	{
		value3[i] = new int[n];
	}
	//要多次析构

	//指针方式三(不通过)
	// int *value = new int[3][4];
	// delete [] value;
}


int main(){
	one_demention_array(1);
	return 0;
}
