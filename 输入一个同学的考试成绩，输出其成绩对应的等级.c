/*��Ŀһ��
����һ��ͬѧ�Ŀ��Գɼ��������ɼ���Ӧ�ĵȼ�������ɼ���ΧΪ0 - 100��������90�ּ����ϵȼ�ΪA�����ڵ���80��С��90ΪB�����ڵ���60��С��80ΪC��С��60ΪF��
�����ʽ����һ��Ϊһ������n����ʾ֮�������n���ɼ���
�ڶ���Ϊn���ո�ֿ�����������ʾ���Ƴɼ���
�����ʽ�����һ�У��ֱ��Ӧ���Ƴɼ��ĵȼ���
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