#include "node.h"
#include <string.h>

node *create_node(int root_value) {
	node *root = malloc(sizeof(node));
	root->value = root_value;
	root->right = NULL;
	root->left = NULL;
	return root;
}

void release_node(node *one_node) {
	if (one_node->left != NULL)
		free(one_node->left);
	if (one_node->right != NULL)
		free(one_node->right);
	free(one_node);
	one_node = NULL;
}
