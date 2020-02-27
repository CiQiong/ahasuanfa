/* 
#include<stdio.h>
int main(){
	int a[100],i,j,t,n;
	scanf("%d",&n);//输入一个数n,表示接下来有n个数 
	for(i=0;i<n;i++)//循环读入n个数到数组a中 
		scanf("%d",&a[i]);
	//冒泡排序的核心部分 
	for(i=n-1;i>=1;i--){//n个数排序，只用进行n-1趟 
		for(j=1;j<=i;j++){//从第1位开始比较直到最后一个尚未归位的数 
			if(a[j]>a[j-1]){//比较大小并交换（不加等号可以标尺稳定性） 
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
	for(i=0;i<n;i++)//输出结果 
		printf("%d ",a[i]);
	return 0;
}
*/ 


#include<stdio.h>
struct student{
	char name[21];
	char score;
}; //这里创建了一个结构体用来存储姓名和分数 
int main(){
	struct student a[100],t; 
	int i,j,n;
	scanf("%d",&n);//输入一个数n,表示接下来有n个数 
	for(i=0;i<n;i++)//循环读入n个人名和分数 
		scanf("%s %d",a[i].name,&a[i].score);
	//按分数从高到低排序 
	for(i=n-1;i>=1;i--){//n个数排序，只用进行n-1趟 
		for(j=1;j<=i;j++){//从第1位开始比较直到最后一个尚未归位的数 
			if(a[j].score>a[j-1].score){//比较分数并交换（不加等号可以标尺稳定性） 
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
	for(i=0;i<n;i++)//输出人名 
		printf("%s ",a[i].name);
	return 0;
}
