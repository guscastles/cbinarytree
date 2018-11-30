#pragma once
#include "node.h"
#include "accumulator.h"
#include <errno.h>

node *add_child(node *one_node, int value);

node *create_tree();

accumulator *dfs(node *root, void *(func)(int));

accumulator *bfs(node *root, void *(func)(int));
