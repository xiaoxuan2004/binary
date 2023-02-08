#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<limits.h>
char* itobs(int, char*);//将输入数字转换为二进制字符串
void show_bstr(const char*);//显示二进制字符串
int invert_end(int num, int bits);//替换后bits位
static int size;
size = CHAR_BIT * sizeof(int);
int main()
{
	char bin_str[CHAR_BIT * sizeof(int) + 1];//计算位数
	int number,figure;
	puts("Enter an integer and see it in binary.");
	puts("Non-numeric input terminates program.");
	while (scanf("%d", &number) == 1)//检测输入是否正确
	{
		itobs(number, bin_str);
		show_bstr(bin_str);
		printf("Enter a number and the binary will be inverted the last bits of the number:");
		scanf_s("%d", &figure);
		number = invert_end(number, figure);
		itobs(number, bin_str);
		printf("Inverting the last %d bits gives:\n", figure);;
		show_bstr(bin_str);
		printf("Please enter another integer and see it in binary.\n");
	}
	return 0;
}
char* itobs(int num, char* pf)
{
	int i;
	
	for (i = size-1;i >=0;num>>=1)
	{
		
			pf[i] = (01 & num) + '0';
			i--;
		
	}
	pf[size] = '\0';
	return pf;
}
 void show_bstr(const char* pf)
{
	puts(pf);
	/*int i = 0;
	while (pf[i]);
	{
		putchar(pf[i]);
		if (++i % 4 == 0 && pf[i])
			putchar(' ');
	}*///以四行为一组显示
}
int invert_end(int num, int bits)
 {
	int t = 0;
	int bitval=1;
	for (int i = 0;i < bits;i++)
	{
		t |= bitval;
		bitval <<= 1;
	}
		
	 return(num^t);
 }
