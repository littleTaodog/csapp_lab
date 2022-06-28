#include<iostream>
using namespace std;



void movetest(){
	int x = 0x0000000c;
	int sign;
	sign = s>>31;
	x = (~sign&x)|(sign&~x);
	int b_16 = (!!((x>>16)^0))<<4;
	printf("b_16:%d\n",b_16);
	int b_8 = (!!((x >> (b_16 + 8)) ^ 0))<<3;
	printf("b_8:%d\n",b_8);
	int b_4 = (!!((x >> (b_16 + b_8 + 4)) ^ 0))<<2;
	printf("b_4:%d\n",b_4);
	int b_2 = (!!((x >> (b_16 + b_8 + b_4 + 2)) ^ 0))<<1;
	printf("b_2:%d\n",b_2);
	int b_1 = !!((x >> (b_16 + b_8 + b_4 + b_2 + 1)) ^ 0);
	printf("b_1:%d\n",b_1);
	int b_0 = !!((x >> (b_16 + b_8 + b_4 + b_2 + b_1)) ^ 0);
	printf("b_0:%d\n",b_0);
}

void exclamationPoint(){
	int x = 0x0100;
	int result = 0;
	int y = 1, z = 2, isZero = 0;
	isZero = x ^ 0;
	// isZero = ~isZero + 1;
	printf("isZero=%x\n",isZero);
	result = ((~isZero)&y) + (isZero&z);
	printf("result=%x\n",result);
	printf("(~isZero)&z=%x\n",(~isZero)&z);
	printf("isZero&y=%x\n",isZero&y);
}

void sameJudge(){
	int a = 0xAAAAAAEA;
	int b = a << 16;
	int c = b << 8;
	int d = c << 4;
	printf("a=%x, b=%x, c=%x, d=%x\n",a,b,c,d);
	int result1 = (a ^ b)>>16;
	int result2 = (b ^ c)>>24;
	int result3 = (c ^ d)>>28;
	printf("a^b=%x,a^c=%x,a^d=%x\n",result1,result2,result3);
	printf("result=%x\n",result1|result2|result3);
	printf("0x2&0x1=%x\n",0x2&0x1);
}

int main(){
	//exclamationPoint();
	movetest();
	return 0;
}
