/*ʵ��һ��

�����������ַ��������У���ѡ����ʵ�ֲ�ճ��ʵ������ͼ���������������Լ���ɣ���

1���󳤶�
2������
3������
4��ȡһ���Ӵ�
5���Ƚ�
6���Ӵ���λ*/

#include<stdio.h>
#include<stdlib.h>

int getlen(char *s) //���ַ�������
{
	int i = 0;
	while (s[i] != '\0') //�ж��Ƿ�ﵽ�ַ���ĩβ
	{
		i++; //����
	}
	return i;
}

void copy(char *re, char *s) //�����ַ���
{
	int i = 0;
	while (s[i] != '\0') //�ж��ַ����Ƿ�ﵽĩβ
	{
		re[i] = s[i]; //�����ַ�
		i++;
	}
	re[i] = '\0'; //�����ַ���������
	return;
}

void link(char *re, char *s, char *t) //�ַ�������
{
	int i = 0, j = 0;
	while (s[i] != '\0') //�жϵ�һ���ַ����Ƿ�ﵽĩβ
	{
		re[i] = s[i]; //�����ַ�
		i++;
	}
	while (t[j] != '\0') //�жϵڶ����ַ����Ƿ�ﵽĩβ
	{
		re[i] = t[j]; //�����ַ�
		i++;
		j++;
	}
	re[i] = '\0'; //�����ַ���������
	return;
}

void getstr(int p, int l, char *s, char *re) //ȡһ���Ӵ�
{
	int i, j = 0;
	for (i = p - 1; i<p + l; i++, j++) //����ѭ���洢�Ӵ�
	{
		re[j] = s[i];
	}
	re[j] = '\0'; //�����ַ���������
	return;
}

int main()
{
	int a;
	char s[20] = "I am happy";
	char t[20] = "Hello world!";
	char re1[30], re2[30], re3[30];
	a = getlen(s); //���ַ�������
	copy(re1, s); //�����ַ���
	link(re2, s, t); //�ַ�������
	getstr(3, 6, t, re3); //ȡһ���Ӵ�
	printf("�ַ���1��%s\n", s);
	printf("�ַ���2��%s\n", t);
	printf("�ַ���1�ĳ���Ϊ��%d\n", a);
	printf("�����ַ���1��%s\n", re1);
	printf("�����ַ���1���ַ���2��%s\n", re2);
	printf("ȡ�ַ���2�е�һ���Ӵ�%s\n", re3);
	system("pause");
	return 0;
}