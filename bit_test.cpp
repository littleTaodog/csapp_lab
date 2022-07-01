#include<iostream>
using namespace std;

void floatScale2(){
	unsigned uf=0x800000;
	unsigned s = uf & (1<<31);
	printf("s=%x\n",s);
	unsigned frac = uf & 0x7fffff;
	printf("frac=%x\n",frac);
	unsigned exp = (uf>>23) & 0xff;
	printf("exp=%x\n",exp);
	unsigned exp2 = exp + 1;
	printf("exp2=%x\n",exp2);
	unsigned exponent = exp - 127;
	printf("exponent=%d\n",exponent);
	unsigned m = frac >> (23-exponent);
	m = m | (1<<exponent);
	printf("m=%x\n",m);
	printf("neg shift:%x\n",0x7fffff>>-100);
	printf("max float:%d\n",2130706431.0);
}

void logicalNeg(){
	int x = 0x80000000;
	printf("~x+1=%x\n",~x+1);
	int r = x|(~x+1);
	printf("x|(~x+1)=%x\n",r);
	printf("r>>31=%x\n",r>>31);
	printf("r>>32=%x\n",r>>32);
	r = (r>>31) + 1;
	printf("r=%x\n",r);
}


void isLessOrEqual(){
	int y = 0x80000000;
	int x = 0x7fffffff;
	int isneg = (x>>31)&1;
	int ispos = !(y>>31);
	int a = (~x) + 1;
	int cmp = 0;
	cmp = a + y;
	cmp = cmp >>31;
	printf("isneg=%x,ispos=%x\n",isneg,ispos);
	printf("!cpm=%x\n",!cmp);
	printf("result=%x\n",(!cmp)|(isneg&ispos));
}

void isAsciiDigit(){
	int x=0x30;
	int low = ~x + 1 + 0x39;
	int high = ~x + 0x30;
	printf("low=%x,high=%x\n",low,high);
}

void buildTmax(){
	int y,z;
	y = 7<<8 | 0xff;
	z = 0xff<<8 | 0xff;
	y = y<<16 | z;
	y = y<<4 | 0xf;
	printf("Tmax=%x\n",y);
}

void movetest(){
	int x = 0x0000000c;
	int sign;
	sign = x>>31;
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
	//movetest();
	//buildTmax();
	//isAsciiDigit();
	//isLessOrEqual();
	//logicalNeg();
	floatScale2();
	return 0;
}
