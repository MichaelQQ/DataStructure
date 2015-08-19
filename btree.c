#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node* left;
	struct node* right;
	struct node* next;
	int num;
}NODE;

typedef struct {
	int count;
	NODE* root;
	NODE* tail;
}TREE;

TREE* create_tree (){
	TREE* tree;

	tree = (TREE*) malloc(sizeof(TREE));
	tree->count = 0;
	tree->root = NULL;

	return tree;
}

void preOrderPrint(NODE* ptr){
	printf("%d ", ptr->num);
	if(ptr->left != NULL)
		preOrderPrint(ptr->left);
	if(ptr->right != NULL)
		preOrderPrint(ptr->right);

	return;
}

void linklistprint(NODE* ptr){
	printf("\nprint list:");
	while(ptr != NULL){
		printf("%d ", ptr->num);
		ptr = ptr->next;
	}
}

void insertNode(TREE* tree, int num){
	NODE* node;
	NODE* ptr;
	NODE* parent;

	node = (NODE*) malloc(sizeof(NODE));
	node->num = num;
	node->right = NULL;
	node->left = NULL;
	node->next = NULL;

	if(tree->count == 0 && tree->root == NULL){
		tree->root = node;
	}
	else{
		ptr = tree->root;
		while(ptr!=NULL){
			if(ptr->left == NULL){
				ptr->left = node;
				break;
			}
			if(ptr->right == NULL){
				ptr->right = node;
				break;
			}
			ptr = ptr->next;
		}
		tree->tail->next = node;
	}
	tree->tail = node;
	tree->count++;
}

int main(){
	NODE* ptr;
	TREE* tree;
	int i=0;

	tree = create_tree();
	for(i=0; i<20; i++){
		insertNode(tree, i);
	}
	preOrderPrint(tree->root);
	linklistprint(tree->root);
	printf("\ntree count: %d\n", tree->count);

	return 0;
}