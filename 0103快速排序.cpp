#include<cstdio>
int a[101],n;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ��
void quicksort(int left,int right){
	int i,j,t,temp;
	if(left>right) return;
	temp=a[left];//temp�д�ľ��ǻ�׼��
	i=left;
	j=right;
	while(i!=j){
		//˳�����Ҫ��Ҫ�ȴ���������
		while(a[j]>=temp&&i<j) j--;
		//�ٴ���������
		while(a[i]<=temp&&i<j) i++;
		//�����������������е�λ�� 
		if(i<j){//���ڱ�i���ڱ�jû������ʱ
			t=a[i];
			a[i]=a[j];
			a[j]=t; 
		} 
	}
	//���ս���׼����λ
	a[left]=a[i];
	a[i]=temp;
	quicksort(left,i-1);//����������ߵģ�������һ���ݹ�Ĺ��� 
	quicksort(i+1,right); //���������ұߵģ�������һ���ݹ�Ĺ��� 
} 
int main(){
	int i,j,t;
	//��������
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	quicksort(0,n-1);//�����������
	//��������Ľ��
	for(i=0;i<n;i++) printf("%d ",a[i]);
	getchar();getchar();
	return 0; 
} 

/*
���� 
10
6 1 2 7 9 3 4 5 10 8
��� 
1 2 3 4 5 6 7 8 9 10
*/ 
