/*
#include<stdio.h>
int main(){
	int a[11],i,j,t;
	for(i=0;i<=10;i++) a[i]=0;//初始化为0 
	for(i=1;i<=5;i++){//循环读入5个数 
		scanf("%d",&t);//把每一个数读到变量t中 
		a[t]++;//进行计数 
	}
	for(i=10;i>=0;i--)//依次判断a[0]~a[10] 
		for(j=1;j<=a[i];j++)//出现了几次就打印几次 
			printf("%d ",i);
	getchar();getchar();
	//这里的getchar();用来暂停程序，以便查看程序的输出内容 
	//可以用system("pause");等来代替
	return 0; 
}
*/

//桶排序 
#include<stdio.h>
int main(){
	int book[1001],i,j,t,n;
	for(i=0;i<=1000;i++) book[i]=0;//初始化为0 
	scanf("%d",&n);//输入一个数n，表示接下来有n个数 
	for(i=1;i<=n;i++){//循环读入n个数，并进行桶排序 
		scanf("%d",&t);//把每一个数读到变量t中 
		book[t]++;//进行计数 ，对编号为t的桶放一个小旗子 
	}
	for(i=1000;i>=0;i--)//依次判断编号1000~0的桶 
		for(j=1;j<=book[i];j++)//出现了几次就将桶的编号打印几次 
			printf("%d ",i);
	getchar();getchar();
	//这里的getchar();用来暂停程序，以便查看程序的输出内容 
	//可以用system("pause");等来代替
	return 0; 
}
