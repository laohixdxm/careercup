/*
Using recursion return the number of leaf nodes
and non leaf nodes from a single method 
without any global variables for a given BST
*/

#include <stddef.h>

typedef struct Node Node;
struct Node
{
int val;
Node* left;
Node* right;
};

int func(Node* root)//number of leaf
{
	if(root == NULL)
		return 0;
	if((root->left == NULL) //root is leaf 
		&& (root->right == NULL))
	{
		printf("%d\n", root->val);
		return 1;
	}	
	return func(root->left) + func(root->right);

}

int func2(Node* root)//number of non-leaf
{
int root_non_leaf = 0;
	if(root == NULL)
		return 0;
	if((root->left == NULL) // root is leaf
		&& (root->right == NULL))
		return 0;
	printf("%d\n", root->val);
	return 1 + func2(root->left) + func2(root->right);
}

Node nodes[11];
void init_tree()
{
	nodes[0].val = 8;
	nodes[0].left = &nodes[1];
	nodes[0].right = &nodes[2];

	nodes[1].val = 3;
	nodes[1].left = &nodes[3];
	nodes[1].right = &nodes[4];

	nodes[2].val = 10;
	nodes[2].left = NULL;
	nodes[2].right = &nodes[6];

	nodes[3].val = 1;
	nodes[3].left = NULL;
	nodes[3].right = NULL;

	nodes[4].val = 6;
	nodes[4].left = NULL;
	nodes[4].right = NULL;

	//nodes[5] 

	nodes[6].val = 14;
	nodes[6].left = NULL;
	nodes[6].right = NULL;

}



int main()
{
int sum=0;
	init_tree();
	//sum = func(&nodes[0]);
	sum = func2(&nodes[0]);
	printf("%d", sum);
	return 0;
}
