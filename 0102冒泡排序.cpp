/* 
#include<stdio.h>
int main(){
	int a[100],i,j,t,n;
	scanf("%d",&n);//����һ����n,��ʾ��������n���� 
	for(i=0;i<n;i++)//ѭ������n����������a�� 
		scanf("%d",&a[i]);
	//ð������ĺ��Ĳ��� 
	for(i=n-1;i>=1;i--){//n��������ֻ�ý���n-1�� 
		for(j=1;j<=i;j++){//�ӵ�1λ��ʼ�Ƚ�ֱ�����һ����δ��λ���� 
			if(a[j]>a[j-1]){//�Ƚϴ�С�����������ӵȺſ��Ա���ȶ��ԣ� 
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
	for(i=0;i<n;i++)//������ 
		printf("%d ",a[i]);
	return 0;
}
*/ 


#include<stdio.h>
struct student{
	char name[21];
	char score;
}; //���ﴴ����һ���ṹ�������洢�����ͷ��� 
int main(){
	struct student a[100],t; 
	int i,j,n;
	scanf("%d",&n);//����һ����n,��ʾ��������n���� 
	for(i=0;i<n;i++)//ѭ������n�������ͷ��� 
		scanf("%s %d",a[i].name,&a[i].score);
	//�������Ӹߵ������� 
	for(i=n-1;i>=1;i--){//n��������ֻ�ý���n-1�� 
		for(j=1;j<=i;j++){//�ӵ�1λ��ʼ�Ƚ�ֱ�����һ����δ��λ���� 
			if(a[j].score>a[j-1].score){//�ȽϷ��������������ӵȺſ��Ա���ȶ��ԣ� 
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
	for(i=0;i<n;i++)//������� 
		printf("%s ",a[i].name);
	return 0;
}
