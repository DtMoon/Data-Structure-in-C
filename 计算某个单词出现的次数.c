/*ʵ�����

��ȡtest.txt�ĵ��������freedom���ʳ��ֵĴ���, test.txt�ļ��ڸ����С�

ʵ������

freedom ���ִ����� 4*/

#include<stdio.h>
#include<stdlib.h>

int find(char *s, char *a) //�ַ���ƥ�亯��
{
	int i = 0, j = 0, num = 0;
	while (s[i] != '\0')
	{
		while (a[j++] == s[i++]); //�ж��Ƿ�ƥ�䣬s���±겻������
		if (a[j - 1] == '\0') { num += 1; } //��a����ĩβ����ƥ��ɹ�������
		if (j != 1) { i--; } //����frefreedom�����
		j = 0;
	}
	return num;
}

int main()
{
	FILE *fp;
	int num = 0;
	char text[1000]; //���ڴ洢��ȡ���ַ���
	char a[] = "freedom";
	fopen_s(&fp, "E:\\test.txt", "r"); //��ȡ�ļ���ʹ��\\��/
	while (!feof(fp)) //һ��һ�еؼ���
	{
		fgets(text, 1000, fp); //��ȡһ������
		puts(text); //���һ���ı�
		num = num + find(text, a);
	}
	fclose(fp);
	printf("freedom���ֵĴ����ǣ�%d", num);
	system("pause");
	return 0;
}