/*���������������
��������������������������Ľ����
���룺�����ļ���Ϊp2in.txt���ļ���n+1�У���һ��һ������n(n<1000000)��֮��ÿ��һ��������ÿ����������ֵС��2147483647
���������ļ���Ϊp2out.txt�����n�У�ÿ��һ����������������С��������
sample1:
p2in.txt
5
8
3
9
1
2
p1out.txt
1
2
3
8
9
*/

void sort(long *a, long left, long right) { //��a���±��left��right���п�������
	long i = left, j = right;
	long key = a[i];
	if (i >= j) return;
	while (i<j) {
		while (i<j&&a[j] >= key) { //��j��ʼ��ǰ���������ɺ�ʼ��ǰ����(j--)���ҵ���һ��С��key��a[j]����a[i]=a[j]
			j--; //��ǰѰ��
		}
		a[i] = a[j];
		while (i<j&&a[i] <= key) { //��i��ʼ�������������ǰ��ʼ�������(i++)���ҵ���һ������key��a[i]����a[j]=a[i]
			i++; //���Ѱ��
		}
		a[j] = a[i]; //a[i]��ߵ���ȫС�ڵ���key��a[j]�ұߵ���ȫ���ڵ���key
	}
	a[i] = key;
	sort(a, left, i - 1); //�Խ�С���н��п�������
	sort(a, i + 1, right); //�Խϴ����н��п�������
	return;
}

void main()
{
	long a[100001]; //���ڴ洢�ļ��е�����
	long i;
	long left = 0, right = 100000;
	FILE *fp;
	FILE *fp1;
	if ((fp = fopen("D:\\p2in.txt", "r")) == NULL) { //���ļ�
		printf("There's not a file!\n");
		return -1;
	}
	for (i = 0; i<100001; i++) {
		fscanf(fp, "%d", &a[i]); //��ȡ���֣�����a��
	}
	fclose(fp);
	sort(a, left, right); //��������
	fp1 = fopen("D:\\out2.txt", "w");
	for (i = 0; i<100001; i++) {
		fprintf(fp1, "%d\n", a[i]); //д���ļ�
	}
	fclose(fp1);
	system("pause");
	return;
}