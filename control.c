
long absdiff(long x, long y){
	long result;
	if(x>y) result = x-y;
	else result = y-x;
	return result;
}

long absdiff_j(long x, long y)
{
	long result;
	int ntest = x<= y;
	if(ntest) goto Else;
	result = x-y;
	goto Done;
Else:
	result = y-x;
Done:
	return result;
}

long switch_eg(long x, long y, long z)
{
	long w=1;
	switch(x){
	case 1:
		w = y*z;
		break;
	case 2:
		w = y/z;
	case 3:
		w += z;
		break;
	case 5:
	case 6:
		w -= z;
		break;
	default:
		w = 2;
	}
	return w;
}
