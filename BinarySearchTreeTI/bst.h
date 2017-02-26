#ifndef bst_h
#define bst_h

#include <stdio.h>

typedef struct BNODE
{
    int data;
    struct BNODE *left;
   struct  BNODE *right;
    }BNODE;

/*    typedef struct BTREE
{
    int treeCount;
    BNODE *root;

    }BTREE; */


BNODE *createBstNode(int data);
void destroyTree(BNODE *node);
BNODE *insertBstNode(BNODE *node, int data);
BNODE *searchTree(BNODE *tree, int target);
BNODE *deleteBstNode(BNODE *tree, int data);
void display(BNODE *root,int level);
BNODE findMinimum(BNODE *temp);
void printInOrder(BNODE *node);
void printPostOrder(BNODE *node);
void printPreOrder(BNODE *node);
#endif
