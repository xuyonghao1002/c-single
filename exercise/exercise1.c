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

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int fact = 1;
	for (size_t i = 1; i <= n; i++)
	{
		fact *= i;
	}
	
	printf("%d!=%d\n", n, fact);
	
	
	system("pause");
	return 0;
}
