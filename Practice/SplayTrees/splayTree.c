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

void rotateLeft(SplayTree *T, Node *x) {

	printf("rotateLeft\n");
	Node *p = x->parent;
	Node *gp = p->parent;

	printf("rotateLeft : p->key = %d\n", p->key);
	
	if(p == T->root) {
		T->root = x;
	}

	x->parent = gp;

	if(gp != NULL) {
		printf("rotateLeft : gp->key = %d\n", gp->key);
		if(gp->left == p) 
			gp->left = x;
		else 
			gp->right = x;
	}
	
	p->right = x->left;

	if(x->left != NULL)
		x->left->parent = p;

	x->left = p;
	p->parent = x;

}

void rotateRight(SplayTree *T, Node *x) {

	printf("rotateRight\n");
	Node *p = x->parent;
	Node *gp = p->parent;
	if(p != NULL) {
		printf("rotateRight : p->key = %d\n", p->key);
	}
	
	
	if(p == T->root) {
		T->root = x;
	}

	x->parent = gp;

	if(gp != NULL) {
		printf("rotateRight : gp->key = %d\n", gp->key);
		if(gp->left == p) 
			gp->left = x;
		else 
			gp->right = x;
	}

	p->left = x->right;

	if(x->right != NULL)
		x->right->parent = p;

	x->right = p;
	p->parent = x;

}

void rotate(SplayTree *T, Node *x) {

	printf("rotate\n");
	if(x == NULL) return;

	Node *p = x->parent;
	
	if(p == NULL)	return;
	printf("x->key = %d\n", x->key);
	printf("p->key = %d\n", p->key);
	if(p->left != NULL)
		printf("p->left->key = %d\n", p->left->key);
	if(p->right != NULL)
		printf("p->right->key = %d\n", p->right->key);

	if(p->left == x) {
		rotateRight(T, x);
	}
	else {
		rotateLeft(T, x);
	}

}

void zigzig(SplayTree *T, Node *x) {
	printf("zigzig\n");

	if(x == NULL) 	return;
	printf("2. x->key = %d\n", x->key);
	rotate(T, x->parent);
	rotate(T, x);

}

void zigzag (SplayTree *T, Node *x) {

	printf("zigzag\n");
	if(x == NULL) 	return;
	printf("2. x->key = %d\n", x->key);
	rotate(T, x);
	rotate(T, x);

}

void splay(SplayTree *T, Node *x) {

	printf("splay fired...\n");
	if(x == NULL) {
		return;
	}
	printf("1. x->key = %d\n", x->key);
	if(x->parent == NULL) {
		rotate(T, x);
	}

	else {

		Node *p = x->parent;
		Node *gp = p->parent;
		int cond1 = 0;
		int cond2 = 0;
		if(gp != NULL) {
			cond1 = (p->left == x && gp->left == p);
			cond2 = (p->right == x && gp->right == p);
		}
		
		if(cond1 || cond2) 
			zigzig(T, x);
		
		else 
			zigzag(T, x);

		splay(T, x);
		
	}

}

Node *searchUtil(SplayTree *T, Node *root, int key) {

	if(root == NULL) {
		return root;
	}
	// if(root->key == key) {
	// 	return root;
	// }

	// else if(root->key > key) {

	// 	if(root->left == NULL) 	return root;
	// 	return searchUtil(T, root->left, key);

	// }
	// else {

	// 	if(root->right == NULL) 	return root;
	// 	return searchUtil(T, root->right, key);

	// }
	Node *x = root;
	Node *curr = x;

	while(x != NULL) {

		curr = x;

		if(x->key == key) {
			break;
		}
		else if(x->key > key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	return curr;

}

Node * search(SplayTree *T, Node *x, int key) {

	Node *searchNode = searchUtil(T, x, key);
	//splaying searchNode	
	splay(T, searchNode);

	if(searchNode->key == key) {
		return searchNode;
	}
	return NULL;

}

Node *insertUtil(SplayTree *T, Node *x, int key) {

	Node *p = x;
	Node *node = (Node *) malloc(sizeof(Node));
	node->left = NULL;
	node->right = NULL;
	node->key = key;

	while(p != NULL) {

		if(p->key > key) {

			if(p->left == NULL) {
				p->left = node;
				node->parent = p;
				break;
			}
			p = p->left;
		}
		else {
			
			if(p->right == NULL) {
				p->right = node;
				node->parent = p;
				break;
			}
			p = p->right;
		}
	}
	return node;

}

void * insert(SplayTree *T, Node *root, int key) {
	
	if(root == NULL) {
		
		root = (Node *) malloc(sizeof(Node));
		root->left = NULL;
		root->right = NULL;
		root->key = key;
		root->parent = NULL;
		T->root = root;

	}
	else {

		Node *insertNode = insertUtil(T, root, key);
		printf("insertNode->key = %d\n", insertNode->key);
		splay(T, insertNode);

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

Node * findMin(Node *root) {

	if(root == NULL) {
		return root;
	}
	if(root->left == NULL) {
		return root;
	}
	return findMin(root->left);

}

void inorder( Node *root) {

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
				searchNode = search(&T, T.root, key);
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
				insert(&T, T.root, key);
				// printf("root = %d\n", (T.root)->key);
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
				Node *x = search(&T, T.root, key);
				
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
// 2 5 2 20 2 15 1 10 2 25