/*��Ŀ����ʵ��KMP�㷨
���������ַ�������ڶ��е��ַ����ڵ�һ�е��ַ������״γ��ֵ�λ�á�Ҫ��ʹ��KMP�㷨��
���Ϊ�ڶ����ַ����ڵ�һ���ַ����е��״γ��ֵ�λ�ã�λ����ʼֵΪ0�����û�г������-1��

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

void get_next(char* T, int *next) {  //����next����
	int i = 1, j = 0; //i�������±꣬j���Ӵ��±�
	next[0] = -1; //�κ�����¶���next[0] = -1
	next[1] = 0; //�κ�����¶���next[0] = 0
	while (T[i] != '\0') { //Tδ�ﵽĩβʱ��ѭ��
		if (j == -1 || T[i] == T[j]) { //�ж��Ƿ�ƥ��
			++i;
			++j;
			next[i] = j; //����next����
		}
		else j = next[j]; //��ƥ�䣬��j�˻ص����ʵ�λ�ã�i����
	}
	return;
}

int KMP(char* S, char* T, int pos) {  //KMP�㷨������ģʽ��T��next������T������S�е�pos���ַ�֮���״γ��ֵ�λ��
	int next[255];
	int len = strlen(T);
	int i = pos;
	int j = 0;
	get_next(T, next); //����next����
	while (S[i] != '\0' && T[j] != '\0') {
		if (j == -1 || S[i] == T[j]) { //�ж��Ƿ�ƥ��
			++i;
			++j;
		}
		else j = next[j]; //��ƥ�䣬��j�˻ص����ʵ�λ�ã�i����
	}
	if (T[j] == '\0') return  i - len; // ƥ��ɹ�
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