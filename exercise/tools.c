#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_VALUES 5

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


/**
 * @brief 计算字符串的长度
 * @param string 要计算长度的字符串
 * @return 字符串的长度
 * @note 该函数会遍历输入的字符串，直到遇到'\0'（字符串结束符）为止，并返回字符串的长度
 */
size_t strLength(char *string)
{
	int length = 0;
	while (*string++ != '\0')
	{
		length++;
	}
	return length;	
}


/**
 * @brief 初始化包含浮点值的数组为零，并打印数值。
 * 
 * 该函数使用指针遍历数组，将包含浮点值的数组初始化为零。初始化完成后，打印数组中的值。
 * 
 * @note 需要定义 N_VALUES 来指定数组的大小。
 */
void initializeAndPrintValue()
{
	float values[N_VALUES];
	float *vp;
	for (vp = &values[0]; vp < &values[N_VALUES];)
	{
		*vp++ = 0;
	}

	for (size_t i = 0; i < N_VALUES; i++)
	{
		printf("%f\t", values[i]);
	}
}


int main(int argc, char const *argv[])
{
	
	
	
	system("pause");
	return 0;
}
