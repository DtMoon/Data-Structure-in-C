/*��Ŀ����
����һ��������ٸ�����Ҫ�Թ������еĲ���������������
����Ϊ���С�
��һ��Ϊ������һ��������������ţ����ţ�Сд��ĸ��ɣ����������Ϸ���
�ڶ���Ϊһ��������n����ʾ��������n����������
������Ϊ���ַ�'H'���ַ�'T'��ɵ�һ���ַ�����'H'��'T'������Ŀ����һ�е�n������
˳��Ը�����������Head��Tail���������������
���й�����ۺϲ������Ϸ���

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
	if ((fopen_s(&fp, "E:\\1.txt", "r")) != 0) { //���ļ�
		printf("error\n");
		system("pause");
		return -1;
	}
	fgets(in, 100, fp); //��ȡ�ļ����ļ������������Ϣ
	fclose(fp); //�ر��ļ�
	for (i = 0; in[i] != '\0'; i++) {
		printf_s("%c", in[i]); //��ӡ����
	}

	scanf_s("%d", &n);
	scanf_s("%s", &con, 10);
	//��������У�min����ָ���ĵ�һ�����ţ�max����ָ�������һ�����ţ����ϸ��¡�������
	for (i = 0; i < n - 1; i++) { //ѭ�����������ַ��������һ��һ����H����n-1
		zuo = 0; //�����Ÿ���
		you = 0; //�����Ÿ���
		for (j = min; j < max && in[j] != '\0'; j++) { //�ҵ�H��T�ֽ��','
			if (in[j] == '(') zuo++;
			if (in[j] == ')') you++;
			if (in[j] == ',' && zuo == you + 1) break; //��ʱin[j]=','
		}
		if (con[i] == 'H') { //�����H����
			max = j - 1; //j��ָ��',',��maxָ��','��ǰһ��
			min = min + 1; //��min����
		}
		else { //�����T����
			min = j; //T��������Ȼ��һ������min��j������in[j]='('������','��Ϊ'('��������������һ����
			in[j] = '(';
			zuo = 0;
			you = 0;
			for (j = min;; j++) { //ȷ��max��������������Ŀ��ͬʱ����max
				if (in[j] == '(') zuo++;
				if (in[j] == ')') you++;
				if (zuo == you) break;
			}
			max = j;
		}
	}
	if (n == 1) { //n=1ʱ���������ֻ����H�����⴦��
		for (i = 0; in[i] != ')'; i++);
		max = i;
	}
	for (i = min + 1; i < max; i++) {
		if (in[i] == '\0') break;
		printf_s("%c", in[i]); //��ӡ�������
	}

	system("pause");
	return 0;
}