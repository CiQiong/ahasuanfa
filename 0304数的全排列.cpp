#include <cstdio>
int main(){
	for(int a=1;a<=4;a++)
		for(int b=1;b<=4;b++)
			for(int c=1;c<=4;c++)
				for(int d=1;d<=4;d++)
					if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)
						printf("%d%d%d%d\n",a,b,c,d);
	return 0;
} 
/*
���
1234
1243
1324
1342
1423
1432
2134
2143
2314
2341
2413
2431
3124
3142
3214
3241
3412
3421
4123
4132
4213
4231
4312
4321
*/ 
