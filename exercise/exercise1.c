#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 计算一个整数的位数
int cal_digits(int num)
{
	if (num < 0)
		return 0;
	
	int digits = 0;
	do
	{
		num /= 10;
		digits++;
	} while (num > 0);
	return  digits;
}

// 获得0-100的随机数
int get_rand()
{
	srand(time(0));
	return rand() % 100;
}

// 整数逆序
int int_inversion(int num)
{
	if (num < 0)
		return 0;

	int ret = 0;
	int digit = 0;
	while (num > 0)
	{
		digit = num % 10;
		// printf("%d", digit);
		ret = ret * 10 + digit;
		num /= 10;    
	}
	return ret;
}

// 求两个数的最大公约数
int get_gcd(int a, int b)
{
	/*
	辗转相除法
	1. 如果b等于0，计算结束，a就是最大公约数
	2. 计算a除以b的余数，让a等于b，b等于那个余数，回到第一步

	a  b  t
	12 18 12
	18 12 6
	12 6  0
	6  0
	*/
	int t = 1;
	while (b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main(int argc, char const *argv[])
{
	
	
	
	system("pause");
	return 0;
}
