#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
typedef char Data;

typedef struct _node {
	Data data;
	struct _node* left;
	struct _node* right;
}Node;
Node* MakeNode(Data data);
Node* FindNode(Node*t,Data data);
void SetNode(Node* t, Data a, Data b, Data c);

void preorder(Node* t);
void inorder(Node* t);
void postorder(Node* t);

int main()
{
	int size;
	scanf("%d", &size);
	getchar();
	Node* root = MakeNode(NULL);
	Node* start;
	for (int i = 0; i < size; i++) {
		char parent, left, right;
		scanf("%c %c %c", &parent, &left, &right);
		getchar();
		start = FindNode(root, parent);
		if ( start != NULL) {
			SetNode(start, parent, left, right);
		}
		else {
			SetNode(root, parent, left, right);
		}
	}
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	return 0;
}

Node* MakeNode(Data data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

Node* FindNode(Node* t, Data data)
{
	if (t != NULL) {
		if (t->data == data) {
			return t;
		}
		else {
			Node* tmp = FindNode(t->left, data);
			if ( tmp != NULL) {
				return tmp;
			}
			return FindNode(t->right, data);
		}
	}
	return NULL;
}

void SetNode(Node* t, Data a, Data b, Data c)
{
	t->data = a;
	if (b != '.') {
		t->left = MakeNode(b);
	}
	if (c != '.') {
		t->right = MakeNode(c);
	}
}

void preorder(Node* t)
{
	if (t == NULL) {
		return;
	}
	printf("%c", t->data);
	preorder(t->left);
	preorder(t->right);
}
void inorder(Node* t)
{
	if (t == NULL) {
		return;
	}
	inorder(t->left);
	printf("%c", t->data);
	inorder(t->right);
}
void postorder(Node* t)
{
	if (t == NULL) {
		return;
	}
	postorder(t->left);
	postorder(t->right);
	printf("%c", t->data);
}