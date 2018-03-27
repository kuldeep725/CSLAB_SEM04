/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
	* Aim		: Implement Splay Tree
*/
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

typedef struct Node {
	int key;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
} Node;

typedef struct SplayTree {
	Node *root;
} SplayTree;

void rotateLeft(Node *x) {

	Node *p = x->parent;
	Node *gp = p->parent;
	x->parent = gp;

	if(gp != NULL) {
		if(gp->left == p) 
			gp->left = x;
		else 
			gp->right = x;
	}
	
	p->right = x->left;
	x->left = p;
	p->parent = x;

}

void rotateRight(Node *x) {

	Node *p = x->parent;
	Node *gp = p->parent;
	x->parent = gp;

	if(gp != NULL) {
		if(gp->left == p) 
			gp->left = x;
		else 
			gp->right = x;
	}

	p->left = x->right;
	x->right = p;
	p->parent = x;

}

void rotate(Node *x) {

	Node *p = x->parent;
	
	if(p == NULL)	return;

	if(p->left == x) {
		rotateRight(x);
	}
	else {
		rotateLeft(x);
	}

}

void zigzig(Node *x) {

	if(x == NULL) 	return;

	rotate(x->parent);
	rotate(x);

}

void zigzag (Node *x) {

	if(x == NULL) 	return;

	rotate(x);
	rotate(x);

}

void splay(Node *x) {


	if(x == NULL) {
		return;
	}

	if(x->parent == NULL) {
		rotate(x);
	}

	else {

		Node *p = x->parent;
		Node *gp = p->parent;
		int cond1 = (p->left == x && g->left == p);
		int cond2 = (p->right == x && g->right == p);

		if(cond1 && cond2) 
			zigzig(x);
		
		else 
			zigzag(x);

		splay(x);
		
	}

}

Node *searchUtil(Node *root, int key) {

	if(root == NULL) {
		return root;
	}
	if(root->key == key) {
		return root;
	}

	else if(root->key > key) {

		if(root->left == NULL) 	return root;
		return search(root->left, key);

	}
	else {

		if(root->right == NULL) 	return root;
		return search(root->right, key);

	}

}

Node * search(Node *x, int key) {

	Node *searchNode = searchUtil(x, key);
	//splaying searchNode	
	splay(searchNode);

	if(searchNode->key == key) {
		return searchNode;
	}
	else {
		return NULL;
	}

}

Node *insertUtil(Node *x, int key) {

	Node *p = x;
	while(p != NULL) {

	}

}

Node * insert(Node *root, int key) {
	
	if(root == NULL) {
		
		root = (Node *) malloc(sizeof(Node));
		root->left = NULL;
		root->right = NULL;
		root->key = key;
		root->parent = NULL;

	}
	else {

		Node *insertNode = insertUtil(root, key);
		splay(insertNode);

	}
	return root;
}

void print(Node *root, int gap) {

	if(root == NULL) 	return;

	gap += 4;
	print(root->right, gap);

	for (int i = 4; i < gap; i++)
        printf(" ");
    printf("%d\n", root->key);

    print(root->left, gap);

}

Node * findMin(Node *root) {

	if(root == NULL) {
		return root;
	}
	if(root->left == NULL) {
		return root;
	}
	return findMin(root->left);

}

void inorder(Node *root) {

	if(root == NULL)	return;

	inorder(root->left);
	printf("%d ", root->key);
	inorder(root->right);

}

void postorder(Node *root) {

	if(root == NULL)	return;

	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->key);

}

void printSplayTree(Node *root) {

	print(root, 0);

}

int main() {

	int choice;				//user's choice for BST Menu
	int key;
	SplayTree T;
	T.root = NULL;				//root node of BST
	Node *minNode;
	Node *predecessorNode;
	Node *searchNode;

	do {
		printf("\n=================SPLAY TREE MENU=====================\n");
		printf("1. Search a key\n");
		printf("2. Insert a key\n");
		printf("3. Find minimum key in Splay Tree\n");
		printf("4. Inorder Traversal in Splay Tree\n");
		printf("5. Postorder Traversal in Splay Tree\n");
		printf("6. Find Predecessor of a key\n");
		printf("7. Delete a Key\n");
		printf("8. Print Tree\n");
		printf("9. Exit\n");

		printf("Enter your choice --> ");
		scanf("%d", &choice);

		printf("==============================================\n");

		switch(choice) {

			/******search a key in Splay Tree*****/
			case 1 :
				printf("Enter the key to be searched in Splay Tree : ");
				scanf("%d", &key);
				searchNode = search(T.root, key);
				if(searchNode == NULL) {
					printf("Key %d is not found\n", key);
				}
				else {
					printf("Key %d is found\n", key);
				}
				break;

			/******Insert a key in Splay Tree******/
			case 2 :
				printf("Enter the key to be inserted in Splay Tree : "); 
				scanf("%d", &key);
				T.root = insert(T.root, key);
				break;

			/******Find minimum key in Splay Tree******/
			case 3 :
				minNode = findMin(T.root);
				if(minNode != NULL) {
					printf("%d is the minimum key in Splay Tree.\n", minNode->key);
				}
				else {
					printf("Splay Tree is empty.\n");
				}
				break;

			/*******Inorder traversal in Splay Tree********/	
			case 4 :
				printf("Inorder Traversal in Splay Tree\n");
				inorder(T.root);
				printf("\n");
				break;

			/*******Postorder traversal in Splay Tree********/
			case 5 :
				printf("Postorder Traversal in Splay Tree\n");
				postorder(T.root);
				printf("\n");
				break;

			case 6 :
				printf("Enter the key whose predecessor is to be found : ");
				scanf("%d",&key);
				// predecessorNode = findInorderPredecessor(T.root, key);
				// if(predecessorNode == NULL) {
				// 	printf("No predecessor of key \"%d\"\n", key);
				// 	printf("Given key is the minimum key or given key doesn't exist in Splay Tree\n");
				// }
				// else {
				// 	printf("Predecessor of key \"%d\" is : %d\n", key, predecessorNode->key);
				// }
				break;

			case 7 :
				printf("Enter the key whose node is to be deleted :\n");
				scanf("%d", &key);
				Node *x = search(T.root, key);
				
				if(x == NULL) {
					printf("Given key is not in the Splay Tree.\n");
				}
				else {
					// deleteNode(&T, x);
					printf("Key %d is successfully deleted.\n", key);
				}
				break;

			case 8 :
				printf("\t\tSplay Tree \n\n");
				printSplayTree(T.root);
				break;

			/******Exiting******/
			case 9 :
				printf("Exiting...\n");
				break;

			default :
				printf("Wrong input\n");

		}
		printf("==============================================\n");

	} while (choice != 9);

	return 0;
}