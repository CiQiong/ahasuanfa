/*
//Õ∞≈≈–Ú∑Ω∑® 
#include <cstdio>
int a[1001];
int main(){
	int n,i,t;
	scanf("%d",&n);
	for(i=0;i<n;i++){ 
		scanf("%d",&t); 
		a[t]=1;
	}
	for(i=0;i<=1000;i++)
		if(a[i]!=0)
			printf("%d ",i);
	return 0;
} 
*/

#include <cstdio>
int a[101];
void quicksort(int left,int right){
	int temp,i,j,t;
	if(left>right) return;
	temp=a[left];
	i=left;
	j=right;
	while(i!=j){
		while(a[j]>=temp&&i<j) j--;
		while(a[i]<=temp&&i<j) i++;
		if(i<j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[left]=a[i];
	a[i]=temp; 
	quicksort(left,i-1);
	quicksort(i+1,right);
}
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	quicksort(0,n-1);
	printf("%d",a[0]);
	for( i=1;i<n;i++){
		if(a[i]!=a[i-1])
			printf(" %d",a[i]);
	}
	return 0;
}

/*
10
20 40 32 67 40 20 89 300 400 15

15 20 32 40 67 89 300 400
*/
