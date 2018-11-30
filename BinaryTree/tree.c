#include "tree.h"

node *add_child(node *one_node, int value) {
	if (one_node->left == NULL)
		one_node->left = create_node(value);
	else if (one_node->right == NULL)
		one_node->right = create_node(value);
	else
		return add_child(one_node->left, value);
	return one_node;
}

node *create_tree() {
	node *root = create_node(3);
	root = add_child(add_child(root, 5), 10);
	root->right = add_child(add_child(root->right, 20), 30);
	root->left = add_child(root->left, 40);
	return root;
}

void _execute(int value, void *(func)(int)) {
	if (func != NULL)
		func(value);
}

accumulator *_dfs(node *root, accumulator* acc, void *(func)(int)) {
	if (root == NULL) return acc;
	acclist = expand_accumulator(acc);
	_execute(root->value, func);
	*(acclist + accsize) = root->value;
	accsize++;
	return _dfs(root->right, _dfs(root->left, acc, func), func);
}

accumulator *dfs(node *root, void *(func)(int)) {
	return _dfs(root, initialize_accumulator(), func);
}

accumulator *_accumulate(node* a_node, accumulator* acc, void*(func)(int)) {
	if (a_node != NULL) {
		acclist = expand_accumulator(acc);
		_execute(a_node->value, func);
		*(acclist + accsize) = a_node->value;
		accsize++;
	}
	return acc;
}

accumulator *_bfs(node *root, accumulator* acc, void *(func)(int)) {
	if (root == NULL) return acc;
	return _bfs(root->right,
		_bfs(root->left,
			_accumulate(root->right,
				_accumulate(root->left, acc,
					func), func), func), func);
}

accumulator *bfs(node *root, void *(func)(int)) {
	accumulator *acc = NULL;
	if (root != NULL)
		acc = _bfs(root, _accumulate(root, initialize_accumulator(), func), func);
	return acc;
}
