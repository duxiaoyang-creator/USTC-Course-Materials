#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 
	struct Node {
	    int coeff;          // 系数
	    int exp;           // 指数
	    struct Node* next;  // 指向下一个节点
	} ;
	
struct Node *Create(int coeff,int exp,struct Node *rear){//创建多项式
    struct Node *head=NULL;
    if(coeff==0)return rear;
    
    struct Node *p=(struct Node *)malloc(sizeof(struct Node));
    p->coeff=coeff;
    p->exp=exp;
    p->next=NULL;
    if(rear==NULL){//rear为空，不能用rear->next
		p->next=rear;
		head=p;
		return head;
	}	
	struct Node *q=rear;
	while(q){
		if(p->exp==q->exp){
			q->coeff+=p->coeff;
			free(p);
			return rear;
		}
		q=q->next;
	}
    if(p->exp>rear->exp){
		p->next=rear;
		head=p;
	}
	
	else{
		struct Node *q1=NULL;
		struct Node *q2=NULL;
		q1=rear;
		while(q1->next){
			if(q1->exp>p->exp&&q1->next->exp<p->exp){
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


	void puton(struct Node *head){//显示多项式
		struct Node *p=head;
		if(head==NULL){
		printf("此多项式为空");//空指针
		}
		else{
		while(p!=NULL){
		printf("%dx^%d",p->coeff,p->exp);
		if(p->next)
		printf("+");
		p=p->next;
		}
		printf("\n");
		}
		return;
	}
	
	void destroyNode(struct Node *head)//销毁释放多项式
	{
		struct Node *p=head;
		if(head==NULL)
		{
			printf("此多项式为空！！！");
		}
		else
		{
			while(p!=NULL){
				p=head->next;
				free(head);
				head=p;
			}
		}
		return;
	}
	 
	void sumNode(struct Node *head1,struct Node *head2)//加法运算
	{
		if(head1==NULL||head2==NULL)
		{
			printf("error!多项式为空");
			return;
		}
		struct Node *sumhead=NULL,*p1=head1,*p2=head2,*p3=sumhead;
		while(p1!=NULL)
		{
			sumhead=(struct Node *)malloc(sizeof(struct Node));
			sumhead->coeff=p1->coeff;
			sumhead->exp=p1->exp;
			sumhead->next=p3;
			while(p2!=NULL)
			{
				if(p2->exp==p1->exp)//指数相同跳出循环
				{
					sumhead->coeff+=p2->coeff;
					break;
				}
				p2=p2->next;
			}
			p1=p1->next;
			p2=head2;
		}
		p1=head1,p2=head2;
		while(p2!=NULL)
		{
			while(p2!=NULL)
			{
				if(p2->exp==p1->exp)
				{
					break;
				}
				else if(p1->next==NULL)
				{
					sumhead=(struct Node *)malloc(sizeof(struct Node));
					sumhead->exp=p2->exp;
					sumhead->coeff=p2->coeff;
					sumhead->next=p3;
					p3=sumhead;
					
				}
				p1=p1->next;
			}
			p1=head1;
			p2=p2->next;
		}
		puton(sumhead);
		p3=sumhead;
		while(p3){
			struct Node *temp=p3;
			p3=p3->next;
			free(temp);
		}
		return;
	}

	
void minusNode(struct Node *head1,struct Node *head2){           //减法
    if (head1 == NULL || head2 == NULL) {
	        printf("多项式为空\n");
	        return;
	    }
	struct Node *sumhead=NULL,*p1=head1,*p2=head2,*p3=sumhead;
	    while(p1!=NULL){
	    	sumhead=(struct Node *)malloc(sizeof(struct Node));
			sumhead->exp=p1->exp;
			sumhead->coeff=p1->coeff;
			sumhead->next=p3;
			p3=sumhead;
			while(p2!=NULL){
				if(p2->exp==p1->exp){//指数相等则相加，跳出循环
					sumhead->coeff-=p2->coeff;
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
				if(p2->exp==p1->exp){
					break;
				}
				else if(p1->next==NULL){
				sumhead=(struct Node *)malloc(sizeof(struct Node));
				sumhead->exp=p2->exp;
				sumhead->coeff=0-p2->coeff;
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
			struct Node *temp = p3;
			p3 = p3->next;
			free(temp);
			}
		return;
}


void multiNode(struct Node *head1, struct Node *head2) {   //求积
    if (head1 == NULL || head2 == NULL) {
        printf("多项式为空\n");
        return;
    }
    struct Node *resultHead = NULL; 
    struct Node *p1 = head1, *p2 = head2,*p3=resultHead;
    while (p1 != NULL) {//逐项相乘
        while (p2 != NULL) {
            resultHead = (struct Node *)malloc(sizeof(struct Node));
            resultHead->exp = p1->exp + p2->exp; 
            resultHead->coeff = p1->coeff * p2->coeff; 
            resultHead->next =p3;
            p3=resultHead;
            p2 = p2->next;
        }
        p1 = p1->next;
        p2=head2;
    }
    p3=resultHead;
    while(p3!=NULL){//合并重复的
    struct Node *q1=p3,*q2=q1->next;
		while(q2!=NULL){
			if(q2->exp==p3->exp){
				p3->coeff+=q2->coeff;
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
    struct Node *current = resultHead;
    while (current) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}	
	
	
int main()
{	
		int choice;
		int j=0;
		int i;
		int coeff,exp,n;
		struct Node *phead[N]={NULL},*rear;
		do{
			
			printf("菜单：(1)创建多项式；（2）打印显示多项式；（3）销毁多项式；\n（4）求两个多项式的和；（5）求两个多项式的差；（6）求两个多项式的积\n(0)退出");
			printf("请输入你的选择：");
			scanf("%d",&choice);		
		switch(choice)
		{
			case 1://创建多项式			
								
				printf("请输入多项式的项数：");
				scanf("%d",&n);
				for(int i=0;i<n;i++){
					printf("请输入第%d项的系数和指数：",i+1);
					scanf("%d %d",&coeff,&exp);
					rear=phead[j];
					phead[j]=Create(coeff,exp,rear);//将上一次输入的指针作为这次的next
				}
				printf("成功创建第%d个多项式！\n",j+1);
				j++;
				break;
			case 2: 
				
				printf("需要显示的多项式序列: \n");
				scanf("%d",&i);
			     puton(phead[i-1]);  
			    break;	
			case 3:
				printf("需要删除的多项式序列\n");
				scanf("%d",&i);
				destroyNode(phead[i-1]);
				phead[i-1]=NULL;
				break;
			case 4:
				printf("需要求和的多项式序列x y\n");
				int x,y;
				scanf("%d %d",&x,&y);
				sumNode(phead[x-1],phead[y-1]);		
				break;
			case 5:
				printf("需要求差的多项式序列x y\n");
				int e,f;
				scanf("%d %d",&e,&f);
				minusNode(phead[e-1],phead[f-1]);
				break;
			case 6:
				printf("需要求积的多项式序列x y\n");
				int b,c;
				scanf("%d %d",&b,&c);
				multiNode(phead[b-1],phead[c-1]);
				break;
			case 0:
				return 0;
			default:
				printf("ERROR!\n");
				break;
		}		
}while(1);
}
