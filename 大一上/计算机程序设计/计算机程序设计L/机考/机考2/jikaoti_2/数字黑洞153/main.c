#include <stdio.h> 

int main(void) {
	int IsNumber153(int num); 
	int n;
	printf("输入一个值为3的倍数的整数：");
	scanf("%d", &n);
	printf("\n");
	if(n%3!=0)
	    printf("输入数据%d不满足条件", n);
	else if(IsNumber153(n))
	    printf("%d是数字黑洞153", n);	
	
	return 0;
}

int IsNumber153(int num) {
	int temp=0;
	printf("%d\n", num);
	if(num==153)
	    return 1;
	while(num!=0) {
		temp+=(num%10)*(num%10)*(num%10);
		num/=10;
	}
	
	return IsNumber153(temp);
}
