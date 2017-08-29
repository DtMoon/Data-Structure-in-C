/*实验一：

从以下六种字符串操作中，任选四种实现并粘贴实验结果截图。！！函数必须自己完成！！

1、求长度
2、拷贝
3、连接
4、取一段子串
5、比较
6、子串定位*/

#include<stdio.h>
#include<stdlib.h>

int getlen(char *s) //求字符串长度
{
	int i = 0;
	while (s[i] != '\0') //判断是否达到字符串末尾
	{
		i++; //计数
	}
	return i;
}

void copy(char *re, char *s) //拷贝字符串
{
	int i = 0;
	while (s[i] != '\0') //判断字符串是否达到末尾
	{
		re[i] = s[i]; //保存字符
		i++;
	}
	re[i] = '\0'; //设置字符串结束符
	return;
}

void link(char *re, char *s, char *t) //字符串连接
{
	int i = 0, j = 0;
	while (s[i] != '\0') //判断第一个字符串是否达到末尾
	{
		re[i] = s[i]; //保存字符
		i++;
	}
	while (t[j] != '\0') //判断第二个字符串是否达到末尾
	{
		re[i] = t[j]; //保存字符
		i++;
		j++;
	}
	re[i] = '\0'; //设置字符串结束符
	return;
}

void getstr(int p, int l, char *s, char *re) //取一段子串
{
	int i, j = 0;
	for (i = p - 1; i<p + l; i++, j++) //利用循环存储子串
	{
		re[j] = s[i];
	}
	re[j] = '\0'; //设置字符串结束符
	return;
}

int main()
{
	int a;
	char s[20] = "I am happy";
	char t[20] = "Hello world!";
	char re1[30], re2[30], re3[30];
	a = getlen(s); //求字符串长度
	copy(re1, s); //拷贝字符串
	link(re2, s, t); //字符串连接
	getstr(3, 6, t, re3); //取一段子串
	printf("字符串1：%s\n", s);
	printf("字符串2：%s\n", t);
	printf("字符串1的长度为：%d\n", a);
	printf("拷贝字符串1：%s\n", re1);
	printf("连接字符串1和字符串2：%s\n", re2);
	printf("取字符串2中的一段子串%s\n", re3);
	system("pause");
	return 0;
}