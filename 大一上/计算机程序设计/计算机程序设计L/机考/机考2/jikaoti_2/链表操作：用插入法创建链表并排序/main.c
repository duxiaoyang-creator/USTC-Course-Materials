#include <stdio.h>
#include <stdlib.h>

/*
1003 38.78
1002 37.46
1005 67.89
1004 65.32
1001 27.89
0 0
*/

struct node {
    int         num;
    float       price;
    struct node *next;
    };

// Traverse the linked list.
void PrintList(struct node *head)
{
    struct node *p=head;
    while (p) {
        printf("%d %.2f\n", p->num, p->price);
        p = p->next;
        }
}

// Insert a node into the linked list.
struct node *InsertList(struct node *head, struct node *q)
{
    struct node *p;

    if (!head) {
        q->next=head;
        head=q;
        return head;
        }

    if (head->num > q->num) {
        q->next = head;
        head = q;
        return head;
        }

    p = head;
    while (p->next && p->next->num < q->num)
        p = p->next;

    q->next = p->next;
    p->next = q;

    return head;
}

int main(int argc, char *argv[]) {
    struct node *head, *ps;
    int          num;
    head=NULL;

    while(1) {
    	ps = (struct node *)malloc(sizeof(struct node));
    	if (ps==NULL) break;
        printf("Insert drug No. & price: ");
        scanf("%d%f", &ps->num, &ps->price);
        if (ps->num==0) {
        	free(ps);
        	break;
		}
        else {
        	head = InsertList(head, ps);
        	printf("\n");
        	printf("Print Linklist: \n");
        	PrintList(head);
		}        
	}    

    return 0;
}
