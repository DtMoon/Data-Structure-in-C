/*题目二：
求数列的众数，中位数，平均数。输入n个整数，分别输出n个整数的众数，中位数，平均数。
输入格式：第一行为一个整数n，表示之后会输入n个数。
第二行为n个空格分开的整数，表示数列的各个数。
输出格式：输出三行。第一行为众数（众数有时不是一个，可以是多个，如果每个数出现次数一样则输出invalid）。第二行为中位数（中位数在数列为奇数个时有一个，偶数个时中间两位平均），数精确到小数点两位。第三行为平均数，用空格分开，平均数精确到小数点两位。
Sample1 :
Input :
	  5
		  1 2 7 4 5
		  Ouput
		  invalid
		  4.00
		  3.80

		  Sample2:
	  Input:
		   6
			   1 2 2 3 3 4
			   Ouput
			   2 3
			   2.50
			   2.50*/

#include<stdio.h>

int count = 0;//全局变量
int re[100];

int* paixu(int *a, int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[j - 1])
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
	return a;
}

int mode(int *a, int n)
{
	int i, b[100], flag = 0;
	int st = a[0], max = 0, k = 1, j = 0;
	for (i = 0; i < n; i++)
	{
		if (st == a[i + 1])
		{
			k += 1;
		}
		else
		{
			st = a[i + 1];
			b[j] = k; //b[]用来记录每个值重复的次数，判断是否invalid
			j += 1;
			if (max < k)
			{
				max = k;
				re[0] = a[i];
				count = 1;
			}
			else if (max == k)
			{
				re[count] = a[i]; //re[]用来记录有多个众数的情况，count用来记录众数个数
				count += 1;
			}
			k = 1;
		}
	}
	for (i = 1; i <= j - 1; i++)
	{
		if (b[0] != b[i])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

float median(int *a, int n)
{
	return n % 2 == 0 ? (a[n / 2 - 1] + a[n / 2])*1.0 / 2 : a[(n - 1) / 2];
}

float mean(int *a, int n)
{
	int i, sum = 0;
	for (i = 0; i<n; i++)
	{
		sum += a[i];
	}
	return sum*1.0 / n;
}


int main()
{
	int n, i;
	int a[100];
	int *b;
	int *c;
	char str[10] = "invalid";
	char s1[10] = "Input";
	char s2[10] = "Output";
	printf("%s\n", s1);
	scanf_s("%d", &n);
	for (i = 0; i<n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	a[n] = 1000;
	b = paixu(a, n);
	printf("%s\n", s2);
	c = mode(b, n);
	if (c == -1)
	{
		printf("%s", str);
	}
	else
	{
		for (i = 0; i < count; i++)
		{
			printf("%d ", re[i]);
		}
	}
	printf("\n%2.2f\n", median(b, n));
	printf("%2.2f\n", mean(b, n));
	system("pause");
	return 0;
}