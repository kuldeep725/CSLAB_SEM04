/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

typedef struct Node {
	int key;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
	int size;
	int rank;
} Node;

typedef struct BST {
	Node *root;
} BST;

Node * searchBST(Node *root, int key) {

	if(root == NULL) {
		return root;
	}
	if(root->key == key) {
		return root;
	}
	else if(root->key > key) {
		return searchBST(root->left, key);
	}
	else {
		return searchBST(root->right, key);
	}

}

Node * insertBST(Node *root, int key) {

	if(root == NULL) {
		
		root = (Node *) malloc(sizeof(Node));
		root->left = NULL;
		root->right = NULL;
		root->key = key;
		root->parent = NULL;
		root->rank = 1;
		root->size = 1;
		return root;

	}

	Node *x = root;

	int count = 2;
	while(x != NULL) {

		if(x->key > key) {

			if(x->left == NULL) {
				Node *t = (Node *) malloc(sizeof(Node));
				t->left = NULL;
				t->right = NULL;
				t->key = key;
				t->parent = x;
				t->rank = count;
				t->size = 1;
				x->left = t;
				x->size++;
				break;
			}
			x->size++;
			x = x->left;

		}
		else if(x->key < key) {

			if(x->right == NULL) {
				Node *t = (Node *) malloc(sizeof(Node));
				t->left = NULL;
				t->right = NULL;
				t->key = key;
				t->parent = x;
				t->rank = count;
				t->size = 1;
				x->right = t;
				x->size++;
				break;
			}
			x->size++;
			x = x->right;

		}
		count++;
		
	}
	
	return root;

}

Node * findMinUtil(Node *x) {

	if(x == NULL) {
		return x;
	}
	while(x->left != NULL) {
		x->size--;
		x = x->left;
	}
	return x;

}

void inorderBST(Node *root) {

	if(root == NULL)	return;

	inorderBST(root->left);
	printf("%d ", root->key);
	inorderBST(root->right);

}

void preorderBST(Node *root) {

	if(root == NULL)	return;

	printf("%d ", root->key);
	preorderBST(root->left);
	preorderBST(root->right);

}

void inorderDecreaseRank(Node *x) {

	if(x == NULL)	return;

	inorderDecreaseRank(x->left);
	x->rank--;
	inorderDecreaseRank(x->right);

}

void deleteNode (BST *T, Node *x) {

	Node *p = x->parent;

	if(x->left == NULL && x->right == NULL) {

		if(p == NULL) {
			T->root = NULL;
		}
		else if(p->left == x) {
			p->left = NULL;
		}
		else if(p->right == x) {
			p->right = NULL;
		}
		x->parent = NULL;
		free(x);

	}

	else if(x->right == NULL || x->left == NULL) {
		
		Node *c;		//child of x
		if(x->right != NULL) {
			c = x->right;
		}
		else {
			c = x->left;
		}

		inorderDecreaseRank(c);

		if(x->parent == NULL) {
			T->root = c;
			c->parent = NULL;
		}
		else {
			c->parent = p;
			if(p->right == x) {
				p->right = c;
			}
			else {
				p->left = c;
			}
		}
		
		x->parent = NULL;
		x->left = NULL;
		free(x);

	}

	else {

		Node *m = findMinUtil(x->right);
		x->key = m->key;
		deleteNode(T, m);

	}

}

void delete(BST *T, int key) {

	Node *node = T->root;
	while(node->key != key) {

		node->size--;
		if(node->key > key) {
			node = node->left;
		}
		else {
			node = node->right;
		}

	}
	deleteNode(T, node);

}

int main() {

	int k1, k2, k3, k4, k5, k6;
	int i;
	int x;
	BST T;
	T.root = NULL;
	Node *searchNode;

	scanf("%d", &k1);
	printf("\n===============INSERTING================\n");
	
	for(i = 0; i < k1; i++) {

		scanf("%d", &x);
		Node *node = searchBST(T.root, x);
		if(node == NULL) {
			T.root = insertBST(T.root, x);
			printf("Key %d is inserted\n", x);
		}
		else {
			printf("Key %d is a duplicate key\n", x);
		}
		
	}

	scanf("%d", &k2);
	printf("\n===============SEARCHING================\n");
	for(i = 0; i < k2; i++) {
		scanf("%d", &x);
		searchNode = searchBST(T.root, x);
		if(searchNode == NULL) {
			printf("Key %d is not found\n", x);
		}
		else {
			printf("Key %d is found, ", x);
			printf("rank = %d, size = %d\n", searchNode->rank, searchNode->size);
		}
	}

	printf("\nInorder Traversal in BST\n");
	inorderBST(T.root);
	printf("\nPreorder Traversal in BST\n");
	preorderBST(T.root);

	scanf("%d", &k3);
	printf("\n===============DELETING================\n");
	for(i = 0; i < k3; i++) {
		scanf("%d", &x);
		Node *node = searchBST(T.root, x);
		if(node == NULL) {
			printf("Given key is not in the BST.\n");
		}
		else {
			delete(&T, x);
			printf("Key %d is successfully deleted.\n", x);
		}
	}

	scanf("%d", &k4);
	printf("\n===============SEARCHING================\n");
	for(i = 0; i < k4; i++) {
		scanf("%d", &x);
		searchNode = searchBST(T.root, x);
		if(searchNode == NULL) {
			printf("Key %d is not found\n", x);
		}
		else {
			printf("Key %d is found, ", x);
			printf("rank = %d, size = %d\n", searchNode->rank, searchNode->size);
		}

	}

	printf("\nInorder Traversal in BST\n");
	inorderBST(T.root);
	printf("\nPreorder Traversal in BST\n");
	preorderBST(T.root);

	scanf("%d", &k5);
	printf("\n===============INSERTING================\n");
	for(i = 0; i < k5; i++) {
		scanf("%d", &x);
		Node *node = searchBST(T.root, x);
		if(node == NULL) {
			T.root = insertBST(T.root, x);
			printf("Key %d is inserted\n", x);
		}
		else {
			printf("Key %d is a duplicate key\n", x);
		}
	}

	scanf("%d", &k6);
	printf("\n===============SEARCHING================\n");
	for(i = 0; i < k6; i++) {
		scanf("%d", &x);
		searchNode = searchBST(T.root, x);
		if(searchNode == NULL) {
			printf("Key %d is not found\n", x);
		}
		else {
			printf("Key %d is found, ", x);
			printf("rank = %d, size = %d\n", searchNode->rank, searchNode->size);
		}

	}

	printf("\nInorder Traversal in BST\n");
	inorderBST(T.root);
	printf("\nPreorder Traversal in BST\n");
	preorderBST(T.root);
	printf("\n");
	return 0;

}