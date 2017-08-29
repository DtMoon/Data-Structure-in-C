/*实验二：

读取test.txt文档，计算出freedom单词出现的次数, test.txt文件在附件中。

实验结果：

freedom 出现次数是 4*/

#include<stdio.h>
#include<stdlib.h>

int find(char *s, char *a) //字符串匹配函数
{
	int i = 0, j = 0, num = 0;
	while (s[i] != '\0')
	{
		while (a[j++] == s[i++]); //判断是否匹配，s的下标不断增大
		if (a[j - 1] == '\0') { num += 1; } //若a到达末尾，则匹配成功，计数
		if (j != 1) { i--; } //考虑frefreedom的情况
		j = 0;
	}
	return num;
}

int main()
{
	FILE *fp;
	int num = 0;
	char text[1000]; //用于存储读取的字符串
	char a[] = "freedom";
	fopen_s(&fp, "E:\\test.txt", "r"); //读取文件，使用\\或/
	while (!feof(fp)) //一行一行地计数
	{
		fgets(text, 1000, fp); //读取一行数据
		puts(text); //输出一行文本
		num = num + find(text, a);
	}
	fclose(fp);
	printf("freedom出现的次数是：%d", num);
	system("pause");
	return 0;
}