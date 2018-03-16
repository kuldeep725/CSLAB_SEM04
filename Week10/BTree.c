/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
	* Aim		: Implement search and insertion in B-tree (t = 3)
*/

#include<stdio.h>
#include<stdlib.h>

/****Defining Node*****/
typedef struct Node {
	int n;
	int *key;
	struct Node **c;
	int leaf;
} Node;
/*********************/

typedef struct BTree {
	Node *root;
	int t;				// Minimum degree (defines the range for number of keys)
} BTree;

//printing BTree
void printBTree(Node *x) {

	int i;
	for(i = 0; i < x->n; i++) {
		if(!x->leaf) {
			printBTree(x->c[i]);
		}
		printf("%d ", x->key[i]);
	}
	//to print the last child of x if it exists
	if(!x->leaf) {
		printBTree(x->c[i]);
	}
}

//spliting child of x at position i
void splitChild(BTree *T, Node *x, int i) {

	// printf("splitChild\n");
	Node *y = x->c[i];
	Node *z = (Node *) malloc(sizeof(Node));
	z->key = (int *) malloc(sizeof(int)*(2*T->t-1));
	z->c = (Node **) malloc(sizeof(Node*)*(2*T->t));
	z->leaf = y->leaf;

	int j;

	for(j = 0; j < T->t-1; j++) {
		// printf("1\n");
		z->key[j] = y->key[T->t+j];
	}
	if(!y->leaf) {
		for(j = 0; j < T->t; j++) {
			// printf("2\n");
			z->c[j] = y->c[T->t+j];
		}
	}

	for(j = x->n-1; j >= i; j--) {
		// printf("3\n");
		x->key[j+1] = x->key[j];
	}
	x->key[i] = y->key[T->t-1];
	for(j = x->n; j >= i+1; j--) {
		// printf("4\n");
		x->c[j+1] = x->c[j];
	}
	x->c[i+1] = z;
	x->n = x->n+1;
	y->n = T->t-1;
	z->n = T->t-1;

}

void insertBTreeNonFull(BTree *T, Node *x, int k) {

	// printf("insertBTreeNonFull\n");
	int i = x->n-1;
	if(x->leaf) {
		// printf("if x->leaf\n");
		while(i >= 0 && x->key[i] > k) {
			x->key[i+1] = x->key[i];
			i--;
		}
		x->key[i+1] = k;
		x->n = x->n + 1;
	}
	else {

		// printf("else\n");
		while(i >= 0 && x->key[i] > k) {
			i--;
		}
		i++;
		if(x->c[i]->n == 2*T->t-1) {
			splitChild(T, x, i);
			if(x->key[i] < k) {
				i++;
			}
		}
		insertBTreeNonFull (T, x->c[i], k);

	}

}

void insertBTree(BTree *T, int k) {

	// printf("Insert BTree\n");
	if(T->root == NULL) {

		// printf("if T->root == NULL insertBTree\n");
		T->root = (Node *) malloc(sizeof(Node));
		T->root->n = 1;
		T->root->key = (int *) malloc(sizeof(int)*(2*T->t-1));
		T->root->c = (Node **) malloc(sizeof(Node*)*(2*T->t));
		T->root->key[0] = k;
		T->root->leaf = 1;
		return;

	}

	//if T->root is full
	if(T->root->n == 2*T->t-1) {

		// printf("if T->root->n == 2*T->t-1\n");
		Node *s = (Node *) malloc(sizeof(Node));
		s->key = (int *) malloc(sizeof(int)*(2*T->t-1));
		s->c = (Node **) malloc(sizeof(Node*)*(2*T->t));
		s->n = 0;
		s->c[0] = T->root;
		s->leaf = 0;
		T->root = s;
		T->root->leaf = 0;
		splitChild(T, s, 0);

	}
	insertBTreeNonFull(T, T->root, k);

}

int searchBTree(BTree *T, Node *x, int k) {

	int i = 0;
	while(i < x->n && x->key[i] < k) {
		// printf("%d, %d\n", x->key[i], k);
		i++;
	}
	if(i < x->n && x->key[i] == k) {
		// printf("index%d, ", i);
		printf("%d , ", k);
		return i;
	}
	if(!x->leaf) {
		if(x == T->root) {
			printf("root --> ");
			printf("child%d --> ", i);
		}
		else {
			printf("child%d --> ", i);
		}
		searchBTree(T, x->c[i], k);
	}
	else {
		printf("NOT FOUND\n");
		return -1;
	}

}

int main() {

	int n;
	int i;
	int k;
	scanf("%d", &n);

	BTree T;
	T.t = 3;
	T.root = NULL;

	for(i = 0; i < n; i++) {
		scanf("%d", &k);
		insertBTree(&T, k);
		printf("\n\n==================After inserting %d====================\n\n", k);
		printBTree(T.root);
	}

	printf("\n");

	printf("\n==================SEARCHING=================\n");
	while(1) {

		scanf("%d", &k);
		if(k == -1) {
			break;
		}
		printf("\n=======================================\n");
		printf("\nSearching %d.....\n", k);

		int index = searchBTree(&T, T.root, k);
		if(index == -1) {
			printf("Key %d doesn't exist in BTree\n", k);
		}
		else {
			printf("index %d\n", index);
		}
		printf("\n=======================================\n");

	}

	return 0;

}