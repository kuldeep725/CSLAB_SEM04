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


int deleteBTree (BTree *, Node *, int );
void deleteFromNonLeaf(BTree *, Node *, int);
//printing BTree
void printBTree(Node *x, int sz) {

	int i;
	for(i = x->n-1; i >= 0; i--) {
		if(!x->leaf) {
			printBTree(x->c[i+1], sz+6);
		}
		printf("%*s", sz, "");
		printf("%d\n", x->key[i]);
	}

	//to print the last child of x if it exists
	if(!x->leaf) {
		printBTree(x->c[0], sz+6);
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

// A utility function that returns the index of the first key that is
// greater than or equal to k
int getKeyIndex(Node *x, int k) {

	int i = 0;
	while(i < x->n && x->key[i] < k) 
		i++;
	return i;

}

void leftToRightShift(Node *x, int i) {

	// printf("leftToRightShift\n");
	Node *y = x->c[i];
    Node *s = x->c[i-1];

    int j;
    // Moving all key in C[i] one step ahead
    for(j = y->n-1; j >= 0; j--) {
    	y->key[j+1] = y->key[j];
    }
    if(!y->leaf) {

    	for(j = y->n; j >= 0; j--) 
    		y->c[j+1] = y->c[j];
    	y->c[0] = s->c[s->n];

    }
    y->key[0] = x->key[i-1];
    x->key[i-1] = s->key[s->n-1]; 
    y->n++;
    s->n--;

}

void rightToLeftShift(Node *x, int i) {

	// printf("rightToLeftShift\n");
	Node *y = x->c[i];
    Node *s = x->c[i+1];
	int j;

	y->key[y->n] = x->key[i];
	x->key[i] = s->key[0];

	if(!y->leaf) 
		y->c[y->n+1] = s->c[0];
	
	for(j = 1; j < s->n; j++) {
		s->key[j-1] = s->key[j];
	}
	if(!s->leaf) {
		for(j = 1; j <= s->n; j++) {
			s->c[j-1] = s->c[j];
		}
	}

	y->n++;
	s->n--;

}

// A function to merge C[i] with C[i+1]
// C[i+1] is freed after merging
void merge(BTree *T, Node *x, int i) {
	// printf("merge\n");

	Node *y = x->c[i];
    Node *s = x->c[i+1];
	int j;
	int t = T->t;

	y->key[t-1] = x->key[i];

	for(j = 0; j < s->n; j++) {
		y->key[t+j] = s->key[j];
	}
	if(!y->leaf) {
		for(j = 0; j <= s->n; j++) {
			y->c[t+j] = s->c[j];
		}
	}
	for(j = i+1; j < x->n; j++) {
		x->key[j-1] = x->key[j];
	}
	for(j = i+2; j <= x->n; j++) {
		x->c[j-1] = x->c[j];
	}

	y->n += s->n + 1;
	x->n--;
	free(s);

}

void fill(BTree *T, Node *x, int i) {

	// printf("fill\n");
	int t = T->t;

	if(i != 0 && x->c[i-1]->n >= t) 
		leftToRightShift(x, i);

	else if(i != x->n && x->c[i+1]->n >= t) 
		rightToLeftShift(x, i);
	// Merge C[i] with its sibling
    // If C[i] is the last child, merge it with with its previous sibling
    // Otherwise merge it with its next sibling
	else {
		if(i != x->n) {
			merge(T, x, i);
		}
		else {
			merge(T, x, i-1);
		}
	}
	
}

int getPredecessor(Node *x, int i) {

	Node *p = x->c[i];

	while(!p->leaf) 
		p = p->c[p->n];
	
	return p->key[p->n-1];

}

int getSuccessor(Node *x, int i) {

	Node *p = x->c[i+1];

	while(!p->leaf) 
		p = p->c[0];
	
	return p->key[0];

}

void deleteFromLeaf(Node *x, int i) {

	// printf("deleteFromLeaf\n");
	int j = i+1;

	while(j < x->n) {
		x->key[j-1] = x->key[j];
		j++;
	}
	x->n = x->n-1;

}

void deleteFromNonLeaf(BTree *T, Node *x, int i) {

	// printf("deleteFromNonLeaf\n");
	int key = x->key[i];
	int t = T->t;

	if(x->c[i]->n >= t) {

		int pred = getPredecessor(x, i);
		x->key[i] = pred;
		deleteBTree(T, x->c[i], pred);

	}

	else if(x->c[i+1]->n >= t) {

		int succ = getSuccessor(x, i);
		x->key[i] = succ;
		deleteBTree(T, x->c[i+1], succ);

	}

	else {

		merge(T, x, i);
		deleteBTree(T, x->c[i], key);

	}

}

int deleteBTree (BTree *T, Node *x, int k) {

	// printf("deleteBTree\n");
	int t = T->t;

	if(x == NULL) {
		return 0;
	}

	int index = getKeyIndex(x, k);
	// printf("1\n");

	if(index < x->n && x->key[index] == k) {
		// printf("2\n");
		if(x->leaf) 
			deleteFromLeaf(x, index);
		else 
			deleteFromNonLeaf(T, x, index);

	}

	else {
		// printf("3\n");
		if(x->leaf) {
			printf("The key %d doesn't exist in the BTree\n", k);
			return 0;
		}
		// The key to be removed is present in the sub-tree rooted with this node
        // The flag indicates whether the key is present in the sub-tree rooted
        // with the last child of this node
        int flag = (index == x->n)? 1 : 0;

        if(x->c[index]->n == t-1) {
        	// printf("5\n");
        	fill(T, x, index);
        	// printf("6\n");
        }
        //flag checks if index was x->n and 
        //index > x->n checks if merge has happened
        if(flag && index > x->n) {
        	// printf("7\n");
        	deleteBTree(T, x->c[index-1], k);
        	// printf("8\n");
        }
        else {
        	// printf("9\n");
        	deleteBTree(T, x->c[index], k);
        	// printf("10\n");
        }
 
	}
	return 1;
}

int main() {

	int n;
	int i;
	int k;
	int index;
	int isDeleted;
	// scanf("%d", &n);

	BTree T;
	T.t = 3;
	T.root = NULL;

	int choice;
	do {

		printf("\n====================MENU=================\n");
		printf("1. Insert an element into BTree\n");
		printf("2. Delete an element from BTree\n");
		printf("3. Search an element in BTree\n");
		printf("4. Exit\n");

		printf("Enter your choice --> ");
		scanf("%d", &choice);

		switch(choice) {

			case 1 :
				printf("Enter the element to be inserted : ");
				scanf("%d", &k);
				insertBTree(&T, k);
				printf("\n\n==================After inserting %d====================\n\n", k);
				printBTree(T.root, 0);
				break;

			case 2 :
				printf("Enter the element to be deleted : ");
				scanf("%d", &k);
				isDeleted = deleteBTree(&T, T.root, k);

				if(isDeleted) {
					printf("\n\n==================After deleting %d====================\n\n", k);
					printBTree(T.root, 0);
				}					
				break;

			case 3 : 
				printf("Enter the element to be searched : ");
				scanf("%d", &k);
				index = searchBTree(&T, T.root, k);
				if(index == -1) {
					printf("Key %d doesn't exist in BTree\n", k);
				}
				else {
					printf("index %d\n", index);
				}
				break;

			case 4 : 
				printf("Exiting...\n");
				break;

			default :
				printf("Wrong choice\n");

		}

	} while(choice != 4);

	return 0;

}
//sample input : 1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 10 2 1 1 11 1 12 1 13 1 14 1 15 1 16 1 17 1 18 1 19 1 20 1 21 1 22 1 23 1 24 1 25