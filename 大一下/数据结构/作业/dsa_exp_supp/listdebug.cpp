#include <stdio.h>
#include <stdlib.h>

typedef double ElemType;

typedef struct LNode {
  ElemType data;
  LNode* next;
} *LinkList;

void InitList(LinkList L) {
  // Assume the list has a header node
  L = new LNode;
}

void DestroyList(LinkList &L) {
  delete L;
  L = NULL;
}

void ListInsert(LinkList L, ElemType e) {
  // Insert the element e as the first element (after header node)
  LNode *s = new LNode;
  s->data = e;
  s->next = L->next;
  L->next = s;
}

void PrintList(LinkList L) {
  // Print the elements of a list
  printf("L");
  LNode *p = L->next;
  while (p) {
    printf("->%g", p->data);
    p = p->next;
  }
  printf('\n');
}

int main(int argc, char **argv) {
  LinkList L = NULL; InitList(L);
  if (argc > 1) {
    for (int i = 1; i < argc; ++i) {
      ElemType e = atof(argv[i]);
      ListInsert(L, e);
    }
    PrintList(L);
  }
  else {
    printf("The command line has only one argument\n", argv[1]);
  }
  DestroyList(L);
  printf("Press any key to stop this program\n");
  getchar();
}
