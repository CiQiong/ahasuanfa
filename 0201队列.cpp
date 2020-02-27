/* 
#include <cstdio>
int main(){
	int q[102]={6,3,1,7,5,8,9,2,4};
	int i,head,tail;
	//初始化队列
	head=0;
	tail=9;//队列已经有9个元素了，tail指向队尾的最后一个位置
	while(head<tail){//当队列不空的时候执行循环
		//打印队首并将队首出队
		printf("%d ",q[head]);
		head++;
		//先将新队首的数添加到队尾
		q[tail]=q[head];
		tail++;
		//先将新队首出队  
		head++;  
		////printf("%d ",q[head++]);
		////q[tail++]=q[head++];
	} 
	getchar();getchar();
	return 0;
}
*/ 

#include <cstdio>
struct queue{
	int data[100];//队列的主体，用来存储内容
	int head;//队首
	int tail;//队尾 
}; 
int main(){
	struct queue q;
	int i;
	//初始化队列
	q.head=1;
	q.tail=1;
	for(i=1;i<=9;i++)
		//依次向队列插入9个数
		scanf("%d",&q.data[q.tail++]); 
	while(q.head<q.tail){//当队列不为空的时候执行循环
		//打印队首并将队首出队
		printf("%d ",q.data[q.head++]);
		//先将新队首的数添加到队尾，再将队首出队
		q.data[q.tail++]=q.data[q.head++]; 
	}
	getchar();getchar();
	return 0;
}

/*
输入 
6 3 1 7 5 8 9 2 4
输出 
6 1 5 9 4 7 2 8 3
*/
