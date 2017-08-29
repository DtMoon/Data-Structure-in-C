/*题目二：
给定一个广义表，再给定需要对广义表进行的操作，求操作结果。
输入为三行。
第一行为给定的一个广义表，仅由括号，逗号，小写字母组成，给定广义表合法。
第二行为一个正整数n，表示第三行有n个操作符。
第三行为由字符'H'和字符'T'组成的一个字符串，'H'和'T'的总数目由上一行的n给定。
顺序对给定广义表进行Head和Tail操作最后给出结果。
所有广义表及综合操作均合法。

Sample1:
input:
(((apple)),((pear)),(banana),orange)
4
TTHH

output
banana

Sample2:
input:
(apple,(pear,(banana),orange))
5
THTHH

output:
banana
*/

#include <stdio.h>

int main()
{
	FILE *fp;
	int n, i, j = 0;
	int min = 0, max = 50;
	int zuo = 0, you = 0;
	char in[100], con[10];
	if ((fopen_s(&fp, "E:\\1.txt", "r")) != 0) { //打开文件
		printf("error\n");
		system("pause");
		return -1;
	}
	fgets(in, 100, fp); //读取文件，文件包含广义表信息
	fclose(fp); //关闭文件
	for (i = 0; in[i] != '\0'; i++) {
		printf_s("%c", in[i]); //打印输入
	}

	scanf_s("%d", &n);
	scanf_s("%s", &con, 10);
	//以下情况中，min总是指向表的第一个括号，max总是指向表的最后一个括号，不断更新、缩减表
	for (i = 0; i < n - 1; i++) { //循环广义表操作字符串，最后一个一定是H，故n-1
		zuo = 0; //左括号个数
		you = 0; //右括号个数
		for (j = min; j < max && in[j] != '\0'; j++) { //找到H与T分界的','
			if (in[j] == '(') zuo++;
			if (in[j] == ')') you++;
			if (in[j] == ',' && zuo == you + 1) break; //此时in[j]=','
		}
		if (con[i] == 'H') { //如果是H操作
			max = j - 1; //j是指向',',令max指向','的前一个
			min = min + 1; //令min后移
		}
		else { //如果是T操作
			min = j; //T操作后仍然是一个表，故min即j，再令in[j]='('，即将','变为'('，保留下来的是一个表
			in[j] = '(';
			zuo = 0;
			you = 0;
			for (j = min;; j++) { //确定max，当左右括号数目相同时，即max
				if (in[j] == '(') zuo++;
				if (in[j] == ')') you++;
				if (zuo == you) break;
			}
			max = j;
		}
	}
	if (n == 1) { //n=1时，即表操作只能是H，特殊处理
		for (i = 0; in[i] != ')'; i++);
		max = i;
	}
	for (i = min + 1; i < max; i++) {
		if (in[i] == '\0') break;
		printf_s("%c", in[i]); //打印操作结果
	}

	system("pause");
	return 0;
}