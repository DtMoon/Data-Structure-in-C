/*��Ŀһ������ƥ��ļ���
������ʽ����������������ţ�()��[]��{}����Ƕ��˳�����⣬��([]{})��[({[]})]��Ϊ��ȷ�ĸ�ʽ��[(])��([())��(()]Ϊ����ȷ�ĸ�ʽ����������������Ƿ�ƥ�䣬�����ƥ�����"mismatch"��ƥ�����"match"��
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
		if(t=='('||t=='['||t=='{') //�������ţ���洢
		{
			a[i]=t;
			i+=1;
		}
		else //�������ţ����ж�
		{
			switch(t)
			{
			case')':
				if(a[i-1]!='('){flag=0;} //��ƥ�䣬��flag=0
				else{i-=1;} //ƥ�䣬�򵯳�������
				break;
			case']':
				if(a[i-1]!='['){flag=0;} //��ƥ�䣬��flag=0
				else{i-=1;} //ƥ�䣬�򵯳�������
				break;
			case'}':
				if(a[i-1]!='{'){flag=0;} //��ƥ�䣬��flag=0
				else{i-=1;} //ƥ�䣬�򵯳�������
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