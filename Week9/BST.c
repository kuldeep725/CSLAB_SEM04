/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
	* Aim		: Implement Binary Search Tree (BST)
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

typedef struct BST {
	Node *root;
} BST;

/********declaring functions************/
Node * searchBST(Node *, int);
Node * insertBST(Node *, int);
Node * findMin(Node *);
void inorderBST(Node *);
void postorderBST(Node *);
Node *findCorrectParent(Node *, int);
Node * findInorderPredecessor(Node *, int);
Node * findPredecessor(Node *);
void deleteNode(BST *, Node *);
void printBST(Node *);
/**************************************/

int main() {

	int choice;				//user's choice for BST Menu
	int key;
	BST T;
	T.root = NULL;				//root node of BST
	Node *minNode;
	Node *predecessorNode;
	Node *searchNode;

	do {
		printf("\n=================BST MENU=====================\n");
		printf("1. Search a key\n");
		printf("2. Insert a key\n");
		printf("3. Find minimum key in BST\n");
		printf("4. Inorder Traversal in BST\n");
		printf("5. Postorder Traversal in BST\n");
		printf("6. Find Predecessor of a key\n");
		printf("7. Delete a Key\n");
		printf("8. Print Tree\n");
		printf("9. Exit\n");

		printf("Enter your choice --> ");
		scanf("%d", &choice);

		printf("==============================================\n");

		switch(choice) {

			/******search a key in BST*****/
			case 1 :
				printf("Enter the key to be searched in BST : ");
				scanf("%d", &key);
				searchNode = searchBST(T.root, key);
				if(searchNode == NULL) {
					printf("Key %d is not found\n", key);
				}
				else {
					printf("Key %d is found\n", key);
				}
				break;

			/******Insert a key in BST******/
			case 2 :
				printf("Enter the key to be inserted in BST : "); 
				scanf("%d", &key);
				T.root = insertBST(T.root, key);
				break;

			/******Find minimum key in BST******/
			case 3 :
				minNode = findMin(T.root);
				if(minNode != NULL) {
					printf("%d is the minimum key in BST.\n", minNode->key);
				}
				else {
					printf("BST is empty.\n");
				}
				break;

			/*******Inorder traversal in BST********/	
			case 4 :
				printf("Inorder Traversal in BST\n");
				inorderBST(T.root);
				printf("\n");
				break;

			/*******Postorder traversal in BST********/
			case 5 :
				printf("Postorder Traversal in BST\n");
				postorderBST(T.root);
				printf("\n");
				break;

			case 6 :
				printf("Enter the key whose predecessor is to be found : ");
				scanf("%d",&key);
				predecessorNode = findInorderPredecessor(T.root, key);
				if(predecessorNode == NULL) {
					printf("No predecessor of key \"%d\"\n", key);
					printf("Given key is the minimum key or given key doesn't exist in BST\n");
				}
				else {
					printf("Predecessor of key \"%d\" is : %d\n", key, predecessorNode->key);
				}
				break;

			case 7 :
				printf("Enter the key whose node is to be deleted :\n");
				scanf("%d", &key);
				Node *x = searchBST(T.root, key);
				
				if(x == NULL) {
					printf("Given key is not in the BST.\n");
				}
				else {
					deleteNode(&T, x);
					printf("Key %d is successfully deleted.\n", key);
				}
				break;

			case 8 :
				printf("\t\tBST TREE\n\n");
				printBST(T.root);
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
		return root;

	}
	else {
		
		if(root->key > key) {
			root->left = insertBST(root->left, key);
			root->left->parent = root;
		}
		else if(root->key < key) {
			root->right = insertBST(root->right, key);
			root->right->parent = root;
		}
	}
	return root;

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

void inorderBST(Node *root) {

	if(root == NULL)	return;

	inorderBST(root->left);
	printf("%d ", root->key);
	inorderBST(root->right);

}

void postorderBST(Node *root) {

	if(root == NULL)	return;

	postorderBST(root->left);
	postorderBST(root->right);
	printf("%d ", root->key);

}

//not using this function
// Node *findCorrectParent(Node *x, int key) {

// 	while(x != NULL) {
// 		if(key > x->key) {
// 			return x;
// 		}
// 		x = x->parent;
// 	}
// 	return NULL;

// }

Node * findInorderPredecessor(Node *root, int key) {

	if(root == NULL) 	return root;

	Node *x;
	Node *node = NULL;

	x = root;
	while(x != NULL) {

		if(x->parent != NULL) {
			if(x->parent->right == x) {
				node = x->parent;
			}
		}
		if(x->key == key) {
			break;
		}
		if(x->key > key) {
			x = x->left;
		}
		else {
			x = x->right;
		}

	}
	// Node *x = searchBST(root, key);
	if(x == NULL) {
		return NULL;
	}
	if(x->left == NULL) {
		return node;
	}
	return findPredecessor(x->left);

}

Node * findPredecessor(Node *x) {

	if(x == NULL) 	return x;

	if(x->right == NULL) {
		return x;
	}

	return findPredecessor(x->right);

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

	else if(x->right == NULL) {
		
		if(x->parent == NULL) {
			T->root = x->left;
			x->left->parent = NULL;
		}
		else {
			x->left->parent = p;
			if(p->right == x) {
				p->right = x->left;
			}
			else {
				p->left = x->left;
			}
		}
		
		x->parent = NULL;
		x->left = NULL;
		free(x);

	}

	else if(x->left == NULL) {

		if(x->parent == NULL) {
			T->root = x->right;
			x->right->parent = NULL;
		}
		else {
			x->right->parent = p;
			if(p->left == x) {
				p->left = x->right;
			}
			else {
				p->right = x->right;
			}
		}
		
		x->parent = NULL;
		x->right = NULL;
		free(x);
	}

	else {

		Node *m = findPredecessor(x->left);
		x->key = m->key;
		deleteNode(T, m);

	}

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

void printBST(Node *root) {

	print(root, 0);

}
//Test 1 : 2 50 2 30 2 20 2 40 2 70 2 60 2 80
//Test 2 : 2 100 2 70 2 200 2 60 2 80 2 300 2 67 2 78 2 90 2 250 2 350 2 65 2 95 2 220 2 325 2 400 2 230 2 240
//Predecessor Test : 6 60 6 65 6 67 6 70 6 78 6 80 6 90 6 95 6 100 6 200 6 220 6 230 6 240 6 250 6 300 6 325 6 350 400