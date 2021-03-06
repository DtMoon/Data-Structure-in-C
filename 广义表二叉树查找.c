/*
题目二：广义表二叉树查找
给定一个广义表表示的二叉树，再给定需要对广义表进行的查找操作，求操作结果。
输入为三行：
第一行为一个广义表表示的二叉树。
输入第二行一个整数t,表示之后会输入t个查询。
输入第三行为t个空格想得开的整数，分别每次查询，如果找到输出在原树中的查找顺序，如果没找到输出"N"。
输出为t行，表示每次的查找结果。
如果要找的数是二叉树的根结点，当次行不输出任何字符。其他为由字符'L'和'R'构成的输出序列。分别表示查找二叉树的左子树和右子树。如果没有找到输出N。
下面列出一些广义表的二叉树表示示例：
（2）：只有一个根结点的权值为2的二叉树。
（2，（3））：有一个根结点为2，右子树只有一个3的二叉树。
（（1），2，(3))：有一个根结点为2，左子树只有一个1，右子树只有一个3的二叉树。
（（1），2）:有一个根结点为2，左子树只有一个1的二叉树。
注：输入的二叉树均合法，输入的二叉树只有数字，‘，’和括号组成，字符均为英文字符。
Sample1:
input:
((1),2,(3))
4
1 2 3 4
output:
L

R
N
Sample2:
input:
((((1),2),3,(4,(5))),6,((7),8,(9,(10))))
4
1 10 5 11
output:
LLL
RRR
LRR
N
*/
//可以使用字符串比较函数，来解决10的问题

#include<stdlib.h>
#include<stdio.h>

char jilu[10]; //定义全局变量来保存原树中的查找顺序

int search(char *a, int p) //查找函数，传入的是字符串数组a和要查找的整数p
{
	int i = 0, j = 0, zuo = 0, you = 0, flag = 0, k = 0, dou = 0;
	int low = 0, high;
	char *s = (char*)malloc(sizeof(char) * 5);
	for (i = 0; a[i] != '\0'; i++);
	high = i - 1; //计算字符串长度
	while (1) {
		for (i = low; i<high; i++) {
			if (a[i] == '(') zuo += 1; //是左括号，就加1
			else if (a[i] == ')') you += 1; //是右括号，就加1
			else if (a[i] == ',') dou += 1; //是逗号，就加1，逗号个数用于判断循环是否结束
			else if (a[i] >= '0'&&a[i] <= '9') { //是数字字符
				s[k++] = a[i]; //存储数字字符
				if (a[i + 1] >= '0'&&a[i + 1] <= '9') continue; //找到直到不是数字字符为止
				if (atoi(s) == p) { //整型字符数字转换成整型数字，比较
					flag = 1; //p被访问过，说明p在根节点的左子树中
					if (zuo - you == 1 && (a[i - 1] == ',' || a[i + 1] == ',')) { //针对被查找结点是根节点
						jilu[j] = '\0';
						return 1;
					}
				}
				k = 0;
				s = (char*)malloc(sizeof(char) * 5); //重新分配用于存储数字字符的字符串数组
			}

			if (a[i] != '(' && a[i] != ')' && (zuo - you == 1) && (a[i - 1] == ',' || a[i + 1] == ',')) //如果找到根节点
			{
				if (flag == 1) { //如果要查找的元素被访问过，说明在根节点的左子树中
					jilu[j] = 'L'; //取左子树
					high = i - 2; //更新下一次遍历的范围，即根节点的左子树
					low += 1;
				}
				else {
					jilu[j] = 'R';
					low = i + 2;
					high -= 1;
				}
				j++;
				flag = 0;
				zuo = 0;
				you = 0;
				break;
			}
		}
		if (dou == 0) break; //如果逗号个数为0，那么中止循环
		dou = 0;
	}
	jilu[j] = '\0';
	for (i = low + 1; i<high; i++) s[k++] = a[i];
	if (atoi(s) == p) return 1; //如果括号中的元素是要查找的元素，那么返回1，否则返回0
	else return 0;
}

void main()
{
	int i = 0, j, n, k = 0;
	char t;
	int *m;
	char a[] = "((((1),2),3,(4,(5))),6,((7),8,(9,(10))))"; //广义表字符串
	scanf_s("%d", &n); //输入要查找的元素的个数
	m = (int*)malloc(sizeof(int)*n); //动态分配
	for (i = 0; i < n; i++) scanf_s("%d", &m[i]); //输入要查找的元素
	for (i = 0; i < n; i++) {
		t = m[i];
		j = search(a, t); //查找
		if (jilu[0] == '\0') printf("\n"); //如果是根节点，不输出任何字符
		else if (j == 1) { //如果找到，输出所做的查找操作
			while (jilu[k] != '\0') printf("%c", jilu[k++]);
			printf("\n");
		}
		else printf_s("N\n"); //如果没找到，输出N
		k = 0;
	}

	system("pause");
	return;
}