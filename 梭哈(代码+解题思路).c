/*解题思路：
1.	首先从文件card.txt中读取两行信息，第一行为A的牌，第二行为B的牌。
2.	定义从txt文件中读取到的信息中抽取所需信息的函数void GetInf(char text[], int Card[], int Colour[], int num)，其中text是从txt中读取的一行数据，Card用于存储text中的牌点信息，
Colour用来存储牌点对应的花色的信息，num是牌的个数。该函数实现的方法是：找到' '(空格)所在位置i，根据i-2来判断花色(‘e’对应’spade’,’t’对应’heart’,’c’对应’club’,’d’对应’diamond’)；
根据i+1,i+2来读取牌点，使用atoi函数将数字字符转换为整型。分别对A的牌和B的牌调用该函数。
3.	接下来定义排序函数void sort(int Card[], int Colour[], int Num)，Card是牌点信息，Colour是花色信息，Num是牌的个数，该函数用于将牌点按照从小到大的顺序排列，便于后序操作。
排序方式为冒泡排序，在交换牌点的同时，交换对应的花色。对A的牌和B的牌调用该函数。
4.	定义函数int JudgeType(int Card[], int Colour[], int Num)，该函数用于判断属于哪种牌型，Card是牌点信息（已排好序），Colour是花色信息，Num是牌的个数。实现方法是：先进行循环，
判断手牌中有几组相同牌点，分别记录重复的次数。根据相等牌的组数和对应的重复次数，判断是哪种牌型。使用case语句实现。对A的牌和B的牌调用该函数。
5.	接着定义函数int BetOrNot(int Acard[], int Acolour[], int Atype, int Bcard[], int Bcolour[], int Btype)，Acard表示A的牌点，Acolour表示A的花色，Bcard表示B的牌点，Bcolour表示B的花色，
Atype表示A的牌型，Btype表示B的牌型。该函数用于统计A的所有可能牌型中，比B的牌型大的数量并计算该概率，若概率小于等于0.5，则B加注，否则B不加注。该函数的实现方法为按照B的牌型进行分类讨论，共9类，
在每一类中计算A比B大的概率，讨论繁多，不在此说明了。该函数返回1或0，分别表示加注和不加注。
6.	根据上一步中函数的返回值将加不加注的信息输出到文件answer.txt中。
*/

#include<stdlib.h>
#include<stdio.h>

void GetInf(char text[], int Card[], int Colour[], int num)
{
	int i = 0, j = 0, n = 0;
	char temp[1];
	while (j < num) { //遍历，读取牌点与花色
		if (text[i] != ' ') i++; //找到' '所在位置i，根据i-2来判断花色，根据i+1,i+2来读取牌点
		else {
			n += 1;
			if (n % 2 == 0) {
				i++;
				continue; //遇到第偶数个' '，直接continue
			}
			temp[0] = text[i + 1];
			switch (temp[0]) { //读取牌点
			case 'A':Card[j] = 14; break;
			case 'J':Card[j] = 11; break;
			case 'Q':Card[j] = 12; break;
			case 'K':Card[j] = 13; break;
			default:Card[j] = atoi(temp); //字符串转换成整数
			}
			if (text[i + 3] == ' ' || text[i + 3] == '\n') { //牌点为10的情况
				Card[j] = 10; //读取牌点
			}

			switch (text[i - 2]) { //读取花色
			case 'e': Colour[j] = 1; break; //Spade
			case 't': Colour[j] = 2; break; //Heart
			case 'b': Colour[j] = 3; break; //Club
			case 'd': Colour[j] = 4; break; //Diamond
			}
			j++;
			i++;
		}
	}
	return;
}

void sort(int Card[], int Colour[], int Num)
{
	int i, j, temp;
	for (i = 0; i<Num - 1; i++) { //对牌点进行排序
		for (j = 0; j<Num - 1 - i; j++) {
			if (Card[j]>Card[j + 1]) { //交换牌点
				temp = Card[j];
				Card[j] = Card[j + 1];
				Card[j + 1] = temp;
				temp = Colour[j]; //同时交换花色
				Colour[j] = Colour[j + 1];
				Colour[j + 1] = temp;
			}
		}
	}
	return;
}

int JudgeType(int Card[], int Colour[], int Num) //判断牌型,牌点，花色，牌的数量
{
	int i, j, temp, n = 1; //i,j用于循环,temp用于排序时交换变量
	int EqNum = 1, FirstEqNum = 1, SecEqNum = 1; //EqNum记录相等牌的组数，FirstEqNum记录第一组相等牌的个数，SecEqNum记录第二组相等牌的个数
	int type; //type表示各种牌型

	for (i = 0; i<Num - 1; i++) { //该循环用于判断有多少组相等的牌及每组牌的个数
		if (FirstEqNum == 1) { //计算第一组相等牌的个数
			for (j = i + 1; j<Num; j++) {
				if (Card[i] == Card[j]) {
					FirstEqNum = FirstEqNum + 1; //若牌点相等，则+1
				}
				else break;
			}
			i = j - 1;
		}
		else { //计算第二组相等牌的个数
			for (j = i + 1; j<Num; j++) {
				if (Card[i] == Card[j] && Card[i] != Card[i - 1]) { //与第一组牌点数不同
					EqNum = 2;
					SecEqNum = SecEqNum + 1; //若牌点相等，则+1
				}
			}
			i = j - 1;
		}
	}

	if (EqNum == 1) { //相等牌组数为1
		for (i = 1; i<FirstEqNum; i++) n = n + 1;
	}
	if (EqNum == 2) { //相等牌组数为2
		if (SecEqNum != 3 && FirstEqNum != 3) n = n + 4;
		if (SecEqNum == 3 || FirstEqNum == 3) n = n + 5;
	}
	switch (n) {
	case 1: break; //没有重复牌点时
	case 2: type = 8; printf("对子\n"); break;
	case 3: type = 6; printf("三条\n"); break;
	case 4: type = 2; printf("铁支\n"); break;
	case 5: type = 7; printf("二对\n"); break;
	case 6: type = 3; printf("葫芦\n"); break;
	}

	if (n == 1) { //没有重复牌点时
		if (Card[Num - 1] - Card[0] == Num - 1) { //如果是顺子
			if (Colour[0] == Colour[1] && Colour[1] == Colour[2] && Colour[2] == Colour[3] && Colour[3] == Colour[Num - 1]) {
				type = 1;
				printf("同花顺\n"); //如果是否同花
			}
			else {
				type = Num;
				printf("顺子\n");
			}
		}
		else { //不是顺子
			if (Colour[0] == Colour[1] && Colour[1] == Colour[2] && Colour[2] == Colour[3] && Colour[3] == Colour[Num - 1]) {
				type = Num - 1;
				printf("同花\n"); //如果是否同花
			}
			else {
				type = 9;
				printf("散牌\n");
			}
		}
	}
	return type;
}

int BetOrNot(int Acard[], int Acolour[], int Atype, int Bcard[], int Bcolour[], int Btype) //根据JudgeType函数，A不可能是葫芦,即Atype!=3
{
	int temp, temp1, temp2 = 0, temp3, temp4, temp5, flag = 0, tempcolour[2], i = 0, j = 0, n = 0;
	int a[6] = { 1,1,1,1,0,0 }; //计算A中牌点出现的次数(包括A中和B中)
	int B[2];

	if (Btype == 1) { //B是同花顺
		return 1; //不管A的暗牌是什么，P(B>A)>0.5
	}

	if (Btype == 2) { //B是铁支
		if (Atype == 2) {
			if (Bcard[4] == Bcard[3]) temp = Bcard[4]; //找出四张相同牌的牌点
			else temp = Bcard[0];
			return Acard[3]>Bcard[4] ? 0 : 1; //如果A的铁支大于B的铁支，则B不加注；否则加注
		}
		return 1; //其余情况不管A的暗牌是什么，P(B>A)>0.5
	}

	if (Btype == 3) { //B是葫芦
		if (Atype == 2) return 0; //不管A的暗牌是什么，P(B>A)=0
		return 1; //其余情况不管A的暗牌是什么，P(B>A)>0.5 
	}

	if (Btype == 4) { //B是同花
		if (Atype == 2) return 0; //不管A的暗牌是什么，P(B>A)=0
		return 1; //其余情况不管A的暗牌是什么，P(B>A)>0.5 
	}

	if (Btype == 5) { //B是顺子
		if (Atype == 2) return 0; //不管A的暗牌是什么，P(B>A)=0
		return 1; //其余情况不管A的暗牌是什么，P(B>A)>0.5 
	}

	if (Btype == 6) { //B是三条
		if (Atype == 2) return 0; //不管A的暗牌是什么，P(B>A)=0
		if (Atype == 6) { //A是三条
			if (Bcard[2] == Bcard[3]) temp = Bcard[3]; //找出三张相同牌的牌点
			else temp = Bcard[2];
			if (Acard[0]<Acard[3]) temp1 = Acard[3];
			else temp1 = Acard[0];
			return temp1>temp ? 0 : 1; //若A的三条大于B的三条，B不加注否则加注
		}
		return 1; //其余情况不管A的暗牌是什么，P(B>A)>0.5 
	}

	if (Btype == 7) { //B是二对
		if (Atype == 2 || Atype == 6) return 0; //不管A的暗牌是什么，P(B>A)=0
		if (Atype == 7) {
			i = 0;
			while (Bcard[i] != Bcard[i + 1]) i++; //找出B的两个对子
			B[0] = Bcard[i++];
			while (Bcard[i] != Bcard[i + 1]) i++;
			B[1] = Bcard[i];
			temp = Bcolour[i]; //B大对子的花色
			if (Acard[3]>B[1]) return 0; //A的大对子比B的大
			if (Acard[3]<B[1]) return 1; //A的大对子比B的小
										 //A的大对子等于B的大对子
			if (Acard[0]>B[0]) return 0;
			if (Acard[0]<B[0]) return 1;
			//A的小对子等于B的小对子
			if (Acolour[3]<temp) return 1;
			else return 0;
		}
		return 1; //其余情况不管A的暗牌是什么，P(B>A)>0.5 
	}

	if (Btype == 8) { //B是对子
		i = 0;
		while (Bcard[i] != Bcard[i + 1]) i++;
		temp = Bcard[i]; //找出B的对子牌点
		tempcolour[0] = Bcolour[i];
		tempcolour[1] = Bcolour[i + 1];
		if (Atype == 2 || Atype == 6 || Atype == 7) return 0;
		if (Atype == 5) return 1; //A最多有21种可能大于B，21/43<0.5
		if (Atype == 8) {
			i = 0;
			while (Acard[i] != Acard[i + 1]) i++;
			temp1 = Acard[i]; //找出A的对子牌点
			if (temp1>temp) return 0;
			else return 1;
		}
		if (Atype == 9) return 1;
		//Atype==1或4所需要获取的一些信息
		i = 3;
		while (Acard[i--]>temp) n++; //计算A中牌点大于B的对子牌点的个数
		for (i = 0; i<4; i++) {
			for (j = 0; j<5; j++) {
				if (Acard[i] == Bcard[j]) a[i]++; //a[i]表示A[i]出现的次数
			}
		}
		temp1 = 4;
		for (j = 0; j<5; j++) {
			if (Acolour[0] == Bcolour[j]) temp1++; //temp1表示A的花色的牌出现的次数
		}
		for (i = 3; i>3 - n; i--) temp2 += 4 - a[i]; //可以获取的与A的后n个点数相同的牌的个数
		if (Atype == 1) {
			if (Acard[0] - 1 >= 2) {
				for (j = 0; j<5; j++) {
					if (Acard[0] - 1 == Bcard[j]) a[4]++; //a[4]表示A[0]-1出现的次数
					if (Acard[i] + 1 == Bcard[j] && Acolour[0] != Bcolour[j] && flag == 0) {
						a[4]++;
						flag = 1;
					}
				}
				temp3 = 4 - a[4];
			}
			else temp3 = 0;
			flag = 0;
			if (Acard[3] + 1 <= 14) {
				for (j = 0; j<5; j++) {
					if (Acard[3] + 1 == Bcard[j]) a[5]++; //a[5]表示A[3]+1出现的次数
					if (Acard[i] + 1 == Bcard[j] && Acolour[0] != Bcolour[j] && flag == 0) {
						a[5]++;
						flag = 1;
					}
				}
				temp4 = 4 - a[5];
			}
			else temp4 = 0;
			if (n <= 1) return 1;
			if (n == 2 || n == 3) {
				if ((13 - temp1 + temp2 + temp3 + temp4)>21) return 0; //括号内为A比B大的样本数
				if ((13 - temp1 + temp2 + temp3 + temp4)<21) return 1;
				if (tempcolour[0] == 1 || tempcolour[1] == 1) return 1;
				return 0; //此时A比B大的样本数有22种
			}
			if (n == 4) {
				if ((13 - temp1 + temp2 + temp3 + temp4)>21) return 0; //括号内为A比B大的样本数
				if ((13 - temp1 + temp2 + temp3 + temp4) <= 21) return 1;
			}
		}
		if (Atype == 4) {
			if (Acard[3] - Acard[0] != 4) { //A无法构成顺子
				return 1;
			}
			else { //A可以构成顺子
				i = 0;
				while (Acard[i] + 1 == Acard[i + 1]) i++; //找出可以使A构成顺子的牌A[i]+1
				for (j = 0; j<5; j++) {
					if (Acard[i] + 1 == Bcard[j]) a[4]++; //a[4]表示A[i]+1出现的次数
					if (Acard[i] + 1 == Bcard[j] && Acolour[0] != Bcolour[j] && flag == 0) {
						a[4]++;
						flag = 1;
					}
				}
				temp5 = 4 - a[4];
				if (n <= 2) return 1;
				if (n == 3) {
					if ((13 - temp1 + temp2 + temp5)>21) return 0; //括号内为A比B大的样本数
					if ((13 - temp1 + temp2 + temp5)<21) return 1;
					if (Acard[0]<temp) return 1;
					else {
						if (tempcolour[0] == 1 || tempcolour[1] == 1) return 1;
						return 0; //此时A比B大的样本数有22种
					}
				}
				if (n == 4) {
					if ((13 - temp1 + temp2 + temp5)>21) return 0; //括号内为A比B大的样本数
					if ((13 - temp1 + temp2 + temp5) <= 21) return 1;
				}
			}
		}
	}

	if (Btype == 9) { //B是散牌
		if (Atype == 1 || Atype == 2 || Atype == 6 || Atype == 7 || Atype == 8) return 0;
		if (Acard[3]>Bcard[4]) return 0; //A的最大牌点大于B的最大牌点，不管A的暗牌是什么，都是A大
		if (Acard[3] == Bcard[4] || (Acard[3] = Bcard[4]) && Acolour[3]<Bcolour[4]) return 0; //最大牌相等，但是A的花色大
																							  //以下讨论剩余情况
		for (i = 0; i<4; i++) {
			for (j = 0; j<5; j++) {
				if (Acard[i] == Bcard[j]) a[i]++; //a[i]表示A[i]出现的次数
			}
		}
		temp2 = 0;
		for (i = 0; i<4; i++) temp2 += a[i]; //可以获取的与A点数相同的牌的个数
		if (Atype == 4) {
			if (Acard[3] - Acard[0] != 4) { //A无法构成顺子
				temp1 = 4;
				for (j = 0; j<5; j++) {
					if (Acolour[0] == Bcolour[j]) temp1++; //temp1表示A的花色的牌出现的次数
				}
				if (Acard[3]<Bcard[4]) {
					if (13 - temp1 + temp2 + (14 - Bcard[4]) * 3 + Bcolour[4] - 1>21) return 0; //括号内为A比B大的样本数
					else return 1;
				}
				if (Acard[3] == Bcard[4]) {
					if (13 - temp1 + temp2 + (14 - Bcard[4]) * 3>21) return 0; //括号内为A比B大的样本数
					else return 1;
				}
			}
			else { //A可以构成顺子
				i = 0;
				while (Acard[i] + 1 == Acard[i + 1]) i++; //找出可以使A构成顺子的牌A[i]+1
				for (j = 0; j<5; j++) {
					if (Acard[i] + 1 == Bcard[j]) a[4]++; //a[4]表示A[i]+1出现的次数
					if (Acard[i] + 1 == Bcard[j] && Acolour[0] != Bcolour[j] && flag == 0) {
						a[4]++;
						flag = 1;
					}
				}
				temp5 = 4 - a[4];
				if (Acard[3]<Bcard[4]) {
					if (13 - temp1 + temp2 + (14 - Bcard[4]) * 3 + Bcolour[4] - 1 + temp5>21) return 0; //括号内为A比B大的样本数
					else return 1;
				}
				if (Acard[3] == Bcard[4]) {
					if (13 - temp1 + temp2 + (14 - Bcard[4]) * 3 + temp5>21) return 0; //括号内为A比B大的样本数
					else return 1;
				}
			}
		}
		if (Atype == 5) {
			if (Acard[0] - 1 >= 2) {
				for (j = 0; j<5; j++) {
					if (Acard[0] - 1 == Bcard[j]) a[4]++; //a[4]表示A[0]-1出现的次数
				}
				temp3 = 4 - a[4];
			}
			else temp3 = 0;
			if (Acard[3] + 1 <= 14) {
				for (j = 0; j<5; j++) {
					if (Acard[3] + 1 == Bcard[j]) a[5]++; //a[5]表示A[3]+1出现的次数
				}
				temp4 = 4 - a[5];
			}
			else temp4 = 0;
			if (temp4<Bcard[4]) {
				if (temp2 + (14 - Bcard[4]) * 4 + Bcolour[4] - 1 + temp3 + temp4>21) return 0; //括号内为A比B大的样本数
				else return 1;
			}
			if (temp4 == Bcard[4]) {
				if (temp2 + (14 - Bcard[4]) * 4 + temp3 + temp4>21) return 0; //括号内为A比B大的样本数
				else return 1;
			}
			if (temp4>Bcard[4]) {
				if (temp2 + (14 - Bcard[4]) * 4 + temp3>21) return 0; //括号内为A比B大的样本数
				else return 1;
			}
		}
		if (Atype == 9) return 1;
	}
}

int main(void)
{
	FILE *fp;
	int i = 0, j = 0, Atype, Btype, BON; //Atype,Btype分别记录A的牌型,B的牌型
	int Acard[4], Bcard[5], Acolour[4], Bcolour[5], ANum = 4, BNum = 5; //A有4张明牌，B有5张明牌
	char A[50], B[50], temp[2];
	fopen_s(&fp, "E:\\card.txt", "r"); //打开文件
	fgets(A, 100, fp); //读文件第一行(A牌)
	fgets(B, 100, fp); //读文件第二行(B牌)
	fclose(fp);
	GetInf(A, Acard, Acolour, ANum); //从文件中获取A的牌
	GetInf(B, Bcard, Bcolour, BNum); //从文件中获取B的牌
	sort(Acard, Acolour, ANum); //对A牌点进行排序，同时交换花色
	sort(Bcard, Bcolour, BNum); //对B牌点进行排序，同时交换花色
	printf("%s", A);
	Atype = JudgeType(Acard, Acolour, ANum); //判断A的牌型
	printf("%s\n", B);
	Btype = JudgeType(Bcard, Bcolour, BNum); //判断B的牌型
	BON = BetOrNot(Acard, Acolour, Atype, Bcard, Bcolour, Btype); //判断是否加注
	if (BON == 1) printf("加注");
	else printf("不加注");
	fopen_s(&fp, "E:\\answer.txt", "w");
	if (BON == 1) fputs("YES", fp); //加注
	else fputs("NO", fp); //不加注
	fclose(fp);
	printf("\n");

	system("pause");
	return 0;
}