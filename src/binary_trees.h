/* This module provides a data type allowing to record some key-value
   associations and to retrieve efficiently the value associated to a specific
   key, if such an association has been recorded before.
   This data type is a binary tree and both keys and values are strings.
   All the keys in a binary tree must be different.*/

// forward (i.e. incomplete) declaration:
typedef struct node_t node_t;
// A binary tree is a pointer to a node_t, NULL is an empty tree

void display_tree (node_t *tree);
   /* Displays a representation of the tree on stdout */

node_t *add(node_t *tree, char *key, char *value);
/* Adds a new key-value association in tree and returns it.
   key and value should not be NULL.
   In case key is already known in tree, tree is kept unchanged.
   */

char *lookup(node_t *tree, char *key);
/* Looks for any association with key previously recorded in tree, then returns
   the corresponding value if successful, or NULL otherwise.
   key should not be NULL. */