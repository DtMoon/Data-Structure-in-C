/*题目二：实现KMP算法
输入两行字符串。求第二行的字符串在第一行的字符串中首次出现的位置。要求使用KMP算法。
输出为第二行字符串在第一行字符串中的首次出现的位置，位置起始值为0，如果没有出现输出-1。

Sample1:
Input:
aaabaaaaabaaaaaab
aaa

Ouput
0

Sample2:
Input:
aaabaaaaabaaaaaab
aaaaab

Ouput
4

Sample3:
Input:
aaabaaaaabaaaaaab
aaaaac

Ouput
-1 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void get_next(char* T, int *next) {  //构建next数组
	int i = 1, j = 0; //i是主串下标，j是子串下标
	next[0] = -1; //任何情况下都有next[0] = -1
	next[1] = 0; //任何情况下都有next[0] = 0
	while (T[i] != '\0') { //T未达到末尾时，循环
		if (j == -1 || T[i] == T[j]) { //判断是否匹配
			++i;
			++j;
			next[i] = j; //生成next数组
		}
		else j = next[j]; //不匹配，则j退回到合适的位置，i不变
	}
	return;
}

int KMP(char* S, char* T, int pos) {  //KMP算法。利用模式串T的next函数求T在主串S中第pos个字符之后首次出现的位置
	int next[255];
	int len = strlen(T);
	int i = pos;
	int j = 0;
	get_next(T, next); //生成next数组
	while (S[i] != '\0' && T[j] != '\0') {
		if (j == -1 || S[i] == T[j]) { //判断是否匹配
			++i;
			++j;
		}
		else j = next[j]; //不匹配，则j退回到合适的位置，i不变
	}
	if (T[j] == '\0') return  i - len; // 匹配成功
	else return -1;
}


int main()
{
	char s[100], t[100];
	int pos;
	printf("Input:\n");
	scanf_s("%s", s, 20);
	scanf_s("%s", t, 20);
	pos = KMP(s, t, 0);
	printf("Output:\n%d", pos);

	system("pause");
	return 0;
}