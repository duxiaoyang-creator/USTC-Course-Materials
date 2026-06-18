#include<stdio.h>
#include<stdlib.h>
#define N 100
struct node{//定义结构体
	int num;//系数
	int k;//指数
	struct node *next;//指向下一个节点
};
struct node *Create(int num,int k,struct node *rear){//创建多项式
    struct node *head=NULL;
    if(num==0)return rear;
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->num=num;
    p->k=k;
    p->next=NULL;//初始化为NULL
    if(rear==NULL){//rear为空，不能用rear->next
		p->next=rear;
		head=p;
		return head;
	}
	struct node *q=rear;
	while(q){
		if(p->k==q->k){
			q->num+=p->num;
			free(p);
			return rear;
		}
		q=q->next;
	}
    if(p->k>rear->k){
		p->next=rear;
		head=p;
	}
	else if(p->k==rear->k){
		rear->num+=p->num;
		head=rear;
	}
	else{
		struct node *q1=NULL;
		struct node *q2=NULL;
		q1=rear;
		while(q1->next){
			if(q1->k>p->k&&q1->next->k<p->k){
				q2=q1->next;
				q1->next=p;
				p->next=q2;
				head=rear;
				return head;
			}
			q1=q1->next;
		}
		q1->next=p;
		head=rear;
	}
    return head;
};
void puton(struct node *head){//显示多项式
	struct node *p=head;
	if(head==NULL){
		printf("此多项式为空");//空指针
	}
	else{
	while(p!=NULL){
		printf("%dx^%d",p->num,p->k);
		if(p->next)
		printf("+");
		p=p->next;
	}
	printf("\n");
	}
	return;
}
void freenode(struct node *head){//释放多项式
	struct node *p=head;
		if(head==NULL){
			printf("此多项式为空");//空指针
		}
		else{
		while(p!=NULL){
			p=head->next;
			free(head);
			head=p;
		}
		}
		return;
}
void sumnode(struct node *head1,struct node *head2){                 //求和
    if (head1 == NULL || head2 == NULL) {
	        printf("多项式为空\n");
	        return;
	    }
    struct node *sumhead=NULL,*p1=head1,*p2=head2,*p3=sumhead;
    while(p1!=NULL){
    	sumhead=(struct node *)malloc(sizeof(struct node));
		sumhead->k=p1->k;
		sumhead->num=p1->num;
		sumhead->next=p3;
		p3=sumhead;
		while(p2!=NULL){
			if(p2->k==p1->k){//指数相等则相加，跳出循环
				sumhead->num+=p2->num;
				break;
			}
			p2=p2->next;
			}
		p1=p1->next;
		p2=head2;
    }
	p1=head1,p2=head2;
	while(p2!=NULL){//挑出p1没有，p2有的指数抄
		while(p1!=NULL){
			if(p2->k==p1->k){
				break;
			}
			else if(p1->next==NULL){
			sumhead=(struct node *)malloc(sizeof(struct node));
			sumhead->k=p2->k;
			sumhead->num=p2->num;
			sumhead->next=p3;
			p3=sumhead;
			}
			p1=p1->next;
		}
		p1=head1;
		p2=p2->next;
	}
	puton(sumhead);
	    p3 = sumhead;//释放空间
		while (p3) {
		struct node *temp = p3;
		p3 = p3->next;
		free(temp);
		}
	return;
}	
void minusnode(struct node *head1,struct node *head2){           //减法
    if (head1 == NULL || head2 == NULL) {
	        printf("多项式为空\n");
	        return;
	    }
	struct node *sumhead=NULL,*p1=head1,*p2=head2,*p3=sumhead;
	    while(p1!=NULL){
	    	sumhead=(struct node *)malloc(sizeof(struct node));
			sumhead->k=p1->k;
			sumhead->num=p1->num;
			sumhead->next=p3;
			p3=sumhead;
			while(p2!=NULL){
				if(p2->k==p1->k){//指数相等则相加，跳出循环
					sumhead->num-=p2->num;
					break;
				}
				p2=p2->next;
				}
			p1=p1->next;
			p2=head2;
	    }
		p1=head1,p2=head2;
		while(p2!=NULL){//挑出p1没有，p2有的指数抄
			while(p1!=NULL){
				if(p2->k==p1->k){
					break;
				}
				else if(p1->next==NULL){
				sumhead=(struct node *)malloc(sizeof(struct node));
				sumhead->k=p2->k;
				sumhead->num=0-p2->num;
				sumhead->next=p3;
				p3=sumhead;
				}
				p1=p1->next;
			}
			p1=head1;
			p2=p2->next;
		}
		puton(sumhead);
		    p3 = sumhead;//释放空间
			while (p3) {
			struct node *temp = p3;
			p3 = p3->next;
			free(temp);
			}
		return;
}

void multinode(struct node *head1, struct node *head2) {   //求积
    if (head1 == NULL || head2 == NULL) {
        printf("多项式为空\n");
        return;
    }
    struct node *resultHead = NULL; 
    struct node *p1 = head1, *p2 = head2,*p3=resultHead;
    while (p1 != NULL) {//逐项相乘
        while (p2 != NULL) {
            resultHead = (struct node *)malloc(sizeof(struct node));
            resultHead->k = p1->k + p2->k; 
            resultHead->num = p1->num * p2->num; 
            resultHead->next =p3;
            p3=resultHead;
            p2 = p2->next;
        }
        p1 = p1->next;
        p2=head2;
    }
    p3=resultHead;
    while(p3!=NULL){//合并重复的
    struct node *q1=p3,*q2=q1->next;
		while(q2!=NULL){
			if(q2->k==p3->k){
				p3->num+=q2->num;
				q1->next=q2->next;
				free(q2);//释放多余节点
				q2=q1->next;
			}
			else{
			q1=q2;
			q2=q2->next;
			}
		}
		p3=p3->next;
	}
    puton(resultHead);//打印输出
    struct node *current = resultHead;
    while (current) {
        struct node *temp = current;
        current = current->next;
        free(temp);
    }
}
int main(){
	int x,j=0;
	struct node *phead[N]={NULL},*rear;
again:	
    printf("请选择\n1创建多项式\n2显示多项式\n3销毁多项式\n4求和\n5求差\n6求积\n0退出\n");
	scanf("%d",&x);//选择功能
	switch (x) {
		if(j>=N){
				printf("已达到最大多项式数量");
				return 0;
			}
		case 1://创建多项式
			int num,k,n;
			printf("请输入多项式的项数：");
			scanf("%d",&n);
			for(int i=0;i<n;i++){
				printf("请输入第%d项的系数和指数：",i+1);
				scanf("%d %d",&num,&k);
				rear=phead[j];
				phead[j]=Create(num,k,rear);//将上一次输入的指针作为这次的next
			}				
			printf("成功创建第%d个多项式\n",j+1);
			j++;
			break;
		case 2:
			int i;
			printf("需要显示的多项式序列\n");
			scanf("%d",&i);
			puton(phead[i-1]);
		    break;
		case 3:
			printf("需要删除的多项式序列\n");
			scanf("%d",&i);
			freenode(phead[i-1]);
			phead[i-1]=NULL;
			break;
		case 4:
			printf("需要求和的多项式序列x y\n");
			int x,y;
			scanf("%d %d",&x,&y);
			sumnode(phead[x-1],phead[y-1]);		
			break;
		case 5:
			printf("需要求差的多项式序列x y\n");
			int e,f;
			scanf("%d %d",&e,&f);
			minusnode(phead[e-1],phead[f-1]);
			break;
	    case 6:
	    	printf("需要求积的多项式序列x y\n");
			int b,c;
			scanf("%d %d",&b,&c);
			multinode(phead[b-1],phead[c-1]);
	    	break;
	    case 0:
	    	return 0;
		default:
			printf("ERROR!\n");
			break;
	}
	goto again;
}
