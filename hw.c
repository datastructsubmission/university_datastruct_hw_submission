#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
  int key;
  struct Node* left;
  struct Node* right;
};

int check_bst_utl(struct Node* node, int min, int max) {
  if (node == NULL) return 1;
  if (node->key < min || node->key > max) return 0;
  return check_bst_utl(node->left, min, node->key - 1) &&
         check_bst_utl(node->right, node->key + 1, max);
}

int check_bst(struct Node* root) {
  return check_bst_utl(root, INT_MIN, INT_MAX);
}

struct Node* new_node(int key) {
  struct Node* node = malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int main(int argc, char** argv) {
  int num_of_nodes;
  printf("Please give an input: \n");
  scanf("%d", &num_of_nodes);

  struct Node* root = NULL;
  for (int i = 0; i < num_of_nodes; ++i) {
    int key, Lchild, Rchild;
    scanf("%d%d%d", &key, &Lchild, &Rchild);
    struct Node* node = new_node(key);
    if (Lchild != -1) {
      node->left = new_node(Lchild);
    }
    if (Rchild != -1) {
      node->right = new_node(Rchild);
    }
    root = node;
  }

  if (check_bst(root)) {
    printf("It is binary search tree.\n");
  } else {
    printf("It is not a binary search tree.\n");
  }

  return 0;
}
