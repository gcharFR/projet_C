#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Binary tree nodes; emty trees are NULL:
struct node_t {
   char *key;        // non-NULL
   char *value;      // non-NULL
   node_t *smaller;  // sub-tree for nodes whose key is < 'key'
   node_t *bigger;   // sub-tree for nodes whose key is > 'key'
};

void display_tree (node_t *tree) {
   void display_tree (node_t *tree, unsigned short alignment, const char *branch_name) {
      /* Displays 'tree' with 'alignment' spaces and prefixing the node with
         'branch_name' */
      if (tree != NULL) {
         // We display the node:
         for (int i = 0; i < alignment; i++)
            putchar(' ');
         printf("%s", branch_name);
         printf("(key: \"%s\", value: \"%s\")\n", tree->key, tree->value);
         // We display recursively the "smaller" then "bigger" branches of the tree:
         display_tree(tree->smaller, alignment + 3, "smaller : ");
         display_tree(tree->bigger, alignment + 3, "bigger : ");
      }
      // If 'tree' is empty we do not display anything
   }
   if (tree == NULL)
      printf("Empty binary tree\n");
   else {
      printf("Binary tree:\n");
      display_tree(tree, 0, "");
   }
}

node_t *create_node (char *key, char *value) {
   /* Creates a binary tree node for the key-value association, and returns
      a pointer on it.
      key and value should not be NULL.*/
   #ifdef DEBUG
      printf("[DEBUG] Node creation with key \"%s\" and value \"%s\"\n",
             key,
             value);
   #endif
   // We have to create an initial node:
   node_t *first_node = malloc(sizeof(node_t));
   // We have to copy the values as they could change later if we reference them
   char *copied_key = malloc(strlen(key) + 1);
   strcpy(copied_key, key);
   char *copied_value = malloc(strlen(value) + 1);
   strcpy(copied_value, value);
   first_node->key = copied_key;
   first_node->value = copied_value;
   first_node->smaller = NULL;   // Should be done implicitly
   first_node->bigger = NULL;    // Should be done implicitly
   return first_node;
}

node_t *add(node_t *tree, char *key, char *value) {
    if (tree == NULL)
      return create_node(key, value);
   int comparison = strcmp(key, tree->key);
   if (comparison == 0)
      // Both keys have the same content, we keep tree unchanged
      printf("Key \"%s\" already associated with value \"%s\", new value \"%s\" will be skipped\n",
             key,
             tree->value,
             value);
   else if (comparison < 0)
      // key is smaller than tree->key, we add recursively in the "smaller"
      // branch of the tree:
      tree->smaller = add(tree->smaller, key, value);
   else
      // key is bigger than tree->key, we add recursively in the "bigger"
      // branch of the tree:
      tree->bigger = add(tree->bigger, key, value);
   return tree;
}

char *lookup(node_t *tree, char *key) {
   #ifdef DEBUG
      printf("[DEBUG] ");
      display_tree(tree);
   #endif
   if (tree == NULL)
      return NULL;
   int comparison = strcmp(key, tree->key);
   if (comparison == 0)
      // Found !
      return tree->value;
   else if (comparison < 0) {
      // key is smaller than tree->key, we lookup recursively in the "smaller"
      // branch of the tree:
      #ifdef DEBUG
         printf("[DEBUG] Key \"%s\" < \"%s\", checking \"smaller\" branch:\n",
                key,
                tree->key);
      #endif
      return lookup(tree->smaller, key);
   }
   else {
      // key is bigger than tree->key, we lookup recursively in the "bigger"
      // branch of the tree:
       #ifdef DEBUG
         printf("[DEBUG] Key \"%s\" > \"%s\", checking \"bigger\" branch:\n",
                key,
                tree->key);
      #endif
     return lookup(tree->bigger, key);
  }
}

void delete_tree (node_t *tree) {
   // First case: nothing to free
   if (tree == NULL)
      return;
   // Otherwise we have to delete subtrees recursively:
   delete_tree(tree-> smaller);
   delete_tree(tree->bigger);
   // And then free the root, including embedded values:
   #ifdef DEBUG
      printf("[DEBUG] Node freeing with key \"%s\" and value \"%s\"\n",
             tree->key,
             tree->value);
   #endif
   free(tree->key);
   free(tree->value);
   free(tree);
}