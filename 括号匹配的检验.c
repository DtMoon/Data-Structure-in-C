/*题目一：括号匹配的检验
假设表达式中允许包含三种括号：()、[]和{}。其嵌套顺序随意，即([]{})或[({[]})]等为正确的格式，[(])或([())或(()]为不正确的格式。求给定括号序列是否匹配，如果不匹配输出"mismatch"，匹配输出"match"。
sample1:
input:
[](){}
output:
match
sample2:
input:
[]([)]{}
output:
mismatch*/


#include<stdio.h>

int main()
{
	char t;
	int i=0,flag=1;
	char a[100];
	while(1)
	{
		scanf("%c",&t);
		if(t=='#') break;
		if(t=='('||t=='['||t=='{') //是左括号，则存储
		{
			a[i]=t;
			i+=1;
		}
		else //是右括号，则判断
		{
			switch(t)
			{
			case')':
				if(a[i-1]!='('){flag=0;} //不匹配，则flag=0
				else{i-=1;} //匹配，则弹出左括号
				break;
			case']':
				if(a[i-1]!='['){flag=0;} //不匹配，则flag=0
				else{i-=1;} //匹配，则弹出左括号
				break;
			case'}':
				if(a[i-1]!='{'){flag=0;} //不匹配，则flag=0
				else{i-=1;} //匹配，则弹出左括号
				break;
			}
		}
	}

	if(flag==0)
	{
		printf("mismatch");
	}
	else
	{
		printf("match");
	}

	system("pause");
	return 0;
}