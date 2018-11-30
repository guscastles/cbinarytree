#include "tree.h"

void test_tree() {
	node *root = create_tree();
	printf("Right child value is %d\n", root->right->value);
	printf("Left child value is %d\n", root->left->value);
	add_child(root, 1);
	release_node(root);
}

void print_node(int value) {
	printf("Node value is %d\n", value);
}

void _check_test(node *root, accumulator *values) {
	for (size_t i = 0; i < values->size; ++i)
		printf("%d ", *(values->list + i));
	puts("");
	free(values->list);
	values->list = NULL;
	free(values);
	values = NULL;
	release_node(root);
}

void test_dfs() {
	node *root = create_tree();
	accumulator *values = dfs(root, (void *)print_node);
	_check_test(root, values);
}

void test_bfs() {
	node *root = create_tree();
	accumulator *values = bfs(root, (void *)print_node);
	_check_test(root, values);
}
