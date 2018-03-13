/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
	* Aim		: Implement search and insertion in B-tree (t = 3)
*/

#include<stdio.h>
#include<stdlib.h>

/****Defining Node*****/
typedef struct Node {
	int val;
	int n;
	struct Node *key;
	struct Node *c;
	int leaf;
} Node;
/*********************/

typedef struct BTree {
	Node *root;
	int t;				// Minimum degree (defines the range for number of keys)
} BTree;

int main() {

	int n;
	int i;
	int x;
	scanf("%d", &n);

	BTree T;
	T->t = 3;
	T.root = NULL;
	createTree(&T);

	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		insertBTree(T, x);
	}
	return 0;
}

// Node *search() {

// }

void splitChild(Node *x, int i, int k) {

	int i;
	(x->key[i]).val = k;
	for(i = T->t; i < T->t-1; i++) {

	}

}

void insertBTree(BTree *T, int k) {

	if(T->root == NULL) {

		T->root = (Node *) malloc(sizeof(Node));
		T->root->n = 1;
		T->root->val = k;
		T->root->key = (Node *) malloc(sizeof(Node)*(2*T->t-1));
		T->root->c = (Node *) malloc(sizeof(Node)*(2*T->t));
		T->root->leaf = 1;
		return;

	}

	//if T->root is full
	if(T->root->n == 2*T->t-1) {

		Node *node = (Node *) malloc(sizeof(Node));
		node->key = (Node *) malloc(sizeof(Node)*(2T->t-1));
		node->c = (Node *) malloc(sizeof(Node)*(2*T->t));
		node->n = 0;
		node->c[0] = T->root;
		node->leaf = 0;
		T->root = node;
		splitChild(node, 0, k);

	}
	insertBTreeNonFull(T->root, k);

}

void insertBTreeNonFull(Node *x, int k) {

	if(x->leaf) {

	}

}