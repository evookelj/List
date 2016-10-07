#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

void print_list(struct node *head) {
  struct node* tp = head;
  printf("LL: ");
  while (tp->next != NULL) {
    printf("%d, ", tp->i);
    tp=tp->next;
  }
  printf("%d\n", tp->i);
}

struct node* insert_front( struct node* head, int x) {
  struct node* temp = malloc(sizeof(struct node));
  temp->i = x;
  temp->next = head;
  head = temp;
  return head;
}

struct node* free_list( struct node* head) {
  struct node* tp = head;
  while (tp->next != NULL) {
    free(tp);
    tp=tp->next;
  }
  free(tp);
}

int main() {
  struct node* head = NULL;
  head = (struct node*)malloc(sizeof(struct node));
  head->i = 42;
  head->next = NULL;
  head = insert_front(head,41);
  print_list(head);
  free_list(head);

  printf("\nAnd after freeing the list...\n");
  print_list(head);
  return 0;
}
