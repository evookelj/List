#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

void print_list(struct node *head) {
  struct node* tp = head;
  while (tp->next != NULL) {
    printf("%d\n", tp->i);
    tp++;
  }
}

struct node* insert_front( struct node* head, int x) {
  struct node* temp = malloc(sizeof(struct node));
  temp->i = x;
  temp->next = head;
  head = temp;
}

struct node* free_list( struct node* head) {
  struct node* tp = head;
  while (tp->next != NULL) {
    free(tp);
    tp++;
  }
}

int main() {
  struct node* head;
  head = (struct node*)malloc(sizeof(head));
  head->i = 42;
  head->next = NULL;
  print_list( insert_front(head, 41) );
  
  return 0;
}
