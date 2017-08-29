/*问题二：复杂排序
给定若干整数，输出他们排序后的结果。
输入：输入文件名为p2in.txt，文件有n+1行，第一行一个整数n(n<1000000)，之后每行一个整数，每个整数绝对值小于2147483647
输出：输出文件名为p2out.txt，输出n行，每行一个整数，整数按从小到大排序。
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

void sort(long *a, long left, long right) { //对a中下标从left至right进行快速排序
	long i = left, j = right;
	long key = a[i];
	if (i >= j) return;
	while (i<j) {
		while (i<j&&a[j] >= key) { //从j开始向前搜索，即由后开始向前搜索(j--)，找到第一个小于key的a[j]，令a[i]=a[j]
			j--; //向前寻找
		}
		a[i] = a[j];
		while (i<j&&a[i] <= key) { //从i开始向后搜索，即由前开始向后搜索(i++)，找到第一个大于key的a[i]，令a[j]=a[i]
			i++; //向后寻找
		}
		a[j] = a[i]; //a[i]左边的数全小于等于key，a[j]右边的数全大于等于key
	}
	a[i] = key;
	sort(a, left, i - 1); //对较小子列进行快速排序
	sort(a, i + 1, right); //对较大子列进行快速排序
	return;
}

void main()
{
	long a[100001]; //用于存储文件中的数据
	long i;
	long left = 0, right = 100000;
	FILE *fp;
	FILE *fp1;
	if ((fp = fopen("D:\\p2in.txt", "r")) == NULL) { //打开文件
		printf("There's not a file!\n");
		return -1;
	}
	for (i = 0; i<100001; i++) {
		fscanf(fp, "%d", &a[i]); //读取数字，存入a中
	}
	fclose(fp);
	sort(a, left, right); //快速排序
	fp1 = fopen("D:\\out2.txt", "w");
	for (i = 0; i<100001; i++) {
		fprintf(fp1, "%d\n", a[i]); //写入文件
	}
	fclose(fp1);
	system("pause");
	return;
}