/*题目一：
输入一个同学的考试成绩，输出其成绩对应的等级。输入成绩范围为0 - 100的整数，90分及以上等级为A，大于等于80，小于90为B，大于等于60，小于80为C，小于60为F。
输入格式：第一行为一个整数n，表示之后会输入n个成绩。
第二行为n个空格分开的整数，表示各科成绩。
输出格式：输出一行，分别对应各科成绩的等级。
Sample :
Input :
	  5
		  60 70 80 90 100
		  Output
		  C C B A A*/

#include<stdio.h>

char sco(int x)
{
	if (x >= 90) { return 'A'; }
	if (x >= 80 && x<90) { return 'B'; }
	if (x >= 60 && x<80) { return 'C'; }
	if (x<60) { return 'F'; }
}

int main() {
	int n, i;
	int c[100];
	char s1[10] = "Input";
	char s2[10] = "Output";
	printf("%s\n", s1);
	scanf_s("%d", &n);
	for (i = 0; i<n; i++)
	{
		scanf_s("%d", &c[i]);
	}
	printf("%s\n", s2);
	for (i = 0; i<n; i++)
	{
		printf("%c ", sco(c[i]));
	}
	system("pause");
	return 0;
}