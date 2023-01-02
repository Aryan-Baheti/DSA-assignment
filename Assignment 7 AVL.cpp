#include <iostream>
using namespace std;

struct node {
  int data;
  node *left;
  node *right;
  int height;
} *root = NULL;

int nodeHeight(struct node *p) {
  
  int hl, hr;
  hl = p && p->left ? p->left->height : 0;
  hr = p && p->right ? p->right->height : 0;

  return hl > hr ? hl + 1 : hr + 1;
}


int balanceFactor(struct node *p) {
  int hl, hr;
  hl = p && p->left ? p->left->height : 0;
  hr = p && p->right ? p->right->height : 0;

  return hl - hr;
}

// LLRotationcode

struct node *LLRotation(struct node *p) {
  struct node *p1 = p->left;
  struct node *ptr = p1->right;

  p1->right = p;
  p->left = ptr;

  p->height = nodeHeight(p);
  p1->height = nodeHeight(p1);

  if (root == p) {
    root = p1;
  }

  return p1;
}

// LRRotation code

struct node *LRRotation(struct node *p) {
  struct node *p1 = p->left;
  struct node *ptr = p1->right;

  p1->right = ptr->left;
  p->left = ptr->right;

  ptr->left = p1;
  ptr->right = p;

  p->height = nodeHeight(p);
  p1->height = nodeHeight(p1);
  ptr->height = nodeHeight(ptr);

  if (root == p) {
    root = ptr;
  }

  return ptr;
}


struct node *Rinsert(struct node *p, int key) {
  struct node *t = NULL;

  if (p == NULL) {
    t = new node;
    t->data = key;
    t->left = NULL;
    t->right = NULL;
    t->height = 1;

    return t;
  } else if (key < p->data) {
    p->left = Rinsert(p->left, key);
  } else if (key > p->data) {
    p->right = Rinsert(p->right, key);
  }

  p->height = nodeHeight(p);

  if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1) {
  
    return LLRotation(p);
  }

  else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1) {
    return LRRotation(p);
  }

  return p;
}

void preOrder(node *p) {
  if (p != NULL) {
    cout << p->data << ' ';
    preOrder(p->left);
    preOrder(p->right);
  }
}

int main() {
  root = Rinsert(root, 50);
  Rinsert(root, 10);
  Rinsert(root, 20);

  preOrder(root);

  return 0;
}