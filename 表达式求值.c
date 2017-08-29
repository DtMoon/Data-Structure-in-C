/*题目二：表达式求值
一个表达式由操作数、操作符和分界符组成。现给定表达式，式中数字为0-9，运算符只有‘-’，‘+’，‘*’，以'#'为表达式结束符。输出给定表达式的值。
sample1:
input:
2*3*4-1+1#
output:
24
sample2:
input:
1+2*3*4-5#
output:
20*/


#include<stdio.h>

int main()
{
	char t;
	int i = 1, j = 0, k, flag = 0, flag2 = 0;
	char b[10]; //存储运算符
	int a[10]; //存储数字
	scanf("%d", &a[0]);
	scanf("%c", &t); 
	b[0] = t;
	if (t == '*') { flag2 = 1; } //flag2=1代表'*'

	while(1) //a[0]为最后的结果
	{
		if (flag == 0) //设置flag，交替输入数字和运算符，flag=0代表数字，flag=1代表运算符
		{
			scanf("%d", &k);
			flag = 1;
			a[i] = k;
			i += 1;
		}
		else
		{
			scanf("%c", &t);
			if (t == '#') //为'#'时，计算之前的表达式，然后跳出循环
			{
				if (b[j] == '+') { a[i - 2] = a[i - 2] + a[i - 1]; }
				else if (b[j] == '-') { a[i - 2] = a[i - 2] - a[i - 1]; }
				break;
			}
			flag = 0;
			if (t == '*') { flag2 = 1; continue; } //flag2=1代表'*'
			else
			{
				if (b[0] == '*') {j = -1;}
				j += 1;
				b[j] = t;
				if (j == 0) { continue; }
				if (b[j - 1] == '+') { flag2 = 2; } //flag2=2代表'+'
				else if(b[j - 1] == '-') { flag2 = 3; } //flag2=3代表'-'
			}
		}
		//根据flag2执行相应的操作
		if (flag2 == 1) //flag2=1代表'*'
		{
			a[i - 2] = a[i - 2] * a[i - 1]; //计算’*’，存储计算结果
			i -= 1; //改变数组下标，指向前一个，相当于出栈操作
			flag2 = 0;
		}
		else if (flag2 == 2) //flag2=2代表'+'
		{
			a[i - 2] = a[i - 2] + a[i - 1]; //计算’+’，存储计算结果
			i -= 1; //改变数组下标，指向前一个，相当于出栈操作
			flag2 = 0;
			b[j - 1] = t;  //弹出运算符
			j -= 1;
		}
		else if (flag2 == 3) //flag2=3代表'-'
		{
			a[i - 2] = a[i - 2] - a[i - 1]; //计算’-’，存储计算结果
			i -= 1; //改变数组下标，指向前一个，相当于出栈操作
			flag2 = 0;
			b[j - 1] = t; //弹出运算符
			j -= 1;
		}
	}

	printf("%d", a[0]);

	system("pause");
	return 0;
}
