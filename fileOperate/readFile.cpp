//#include <iostream>
//#include <math.h>
//
//using namespace std;
//
//#define MAXBOUNDARY 0.00001
//#define e 2.71828
//
//int main()
//{
//	double min_boundary = 0.0;
//	double max_boundary = 1.0;
//
//
//	double sum = 0;
//	//f(x) = 3x
//	double i = min_boundary;
//
//	while ( i <= max_boundary)
//	{
//		sum += (MAXBOUNDARY) * (pow(i,2)*pow(e,i));
//		//cout << i;
//		i += MAXBOUNDARY;
//	}
//
//	cout << sum;
//
//	return 0;
//
//}

#include <iostream>
using namespace std;

#define MAXBOUNDARY 0.00001
#define FORMULA (3*x*x*y*y)

int main(){
	double x_start = 0.0;
	double x_end = 1.0;

	double x = x_start;
	double y_start = 0.0;
	double sum = 0.0;

	//解析式
	//f(x,y)=x+y

	while (x < x_end)
	{
		//计算y的范围
		
		double y_end = 1 - x*x;

		//初始化y
		double y = y_start;
		while (y < y_end)
		{
			sum += FORMULA*MAXBOUNDARY*MAXBOUNDARY;
			y += MAXBOUNDARY;
		}
		x += MAXBOUNDARY;
	}

	cout << sum << endl;

}