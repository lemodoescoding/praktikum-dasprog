#include <stdio.h>
#include <stdlib.h>

#define ll long long

struct Node {
  ll data;
  struct Node *next;
};

struct Node *createNode(ll data);

struct Node *insertAtEnd(struct Node *last, ll data) {
  struct Node *new_node = createNode(data);

  if (last == NULL) {
    last = new_node;
    new_node->next = new_node;

    return last;
  }

  new_node->next = last->next;
  last->next = new_node;

  return new_node;
}

void printList(struct Node *last) {
  if (last == NULL)
    return;

  struct Node *head = last->next;

  while (1) {
    printf("%lld ", head->data);
    head = head->next;

    if (head == last->next)
      break;
  }

  printf("\n");
}

struct Node *deleteSpesificNode(struct Node *last, int key) {
  if (last == NULL) {
    return NULL;
  }

  struct Node *curr = last->next, *prev = last;

  if (curr == last && curr->data == key) {
    free(curr);
    last = NULL; // delete the only node if the node is the only one and the kay
                 // matched
    return last;
  }

  if (curr->data == key) {
    last->next = curr->next; // delete the first node if key is matched
    free(curr);

    return last;
  }

  while (curr != last && curr->data != key) {
    prev = curr;
    curr = curr->next; // next node, set head to the next pointer
  }

  if (curr->data == key) {
    prev->next = curr->next; // if the key is found, delete the node and take
                             // the pointer of the next node to the prev node
    if (curr == last) {
      last = prev;
    }

    free(curr);
  } else {
    return NULL;
  }

  return last;
}

struct Node *deleteThisNode(struct Node *last, struct Node *curr,
                            struct Node *next) {
  struct Node *temp = next->next;
  free(curr->next);

  curr->next = temp;

  return last;
}

struct Node *createNode(ll data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = data;

  new_node->next = new_node;

  return new_node;
}

int main() {
  ll Q, K;
  scanf("%lld %lld", &Q, &K);
  struct Node *last = NULL;

  for (ll i = 0; i < Q; i++) {
    last = insertAtEnd(last, i + 1);
  }

  ll size = Q;
  ll start = (start + K) % Q;

  struct Node *curr = last->next, *next = curr->next;

  while (size > 1) {
    for (ll i = start; i <= K; i++) {
      curr = next;
      next = curr->next;

      if (i + 1 == K - 1) {
        printf("%lld %lld %lld\n", i, curr->data, next->data);
        struct Node *temp = next->next;

        free(curr->next);
        curr->next = temp;
        break;
      }
    }

    break;
  }

  printf("List after insertion: \n");
  printList(last);
  return 0;
}
