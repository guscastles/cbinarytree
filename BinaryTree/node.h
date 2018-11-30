#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

struct tree_node {
	int value;
	struct tree_node *right;
	struct tree_node *left;
};

typedef struct tree_node node;

node *create_node(int root_value);

void release_node(node *one_node);
