#include <stdlib.h>
#include <stdio.h>
#include "bst.h"


/* BTREE *createTree()
{
BTREE *tree;
tree = (BTREE*)malloc(sizeof(BTREE));
tree->root = NULL;
return tree;
} */



BNODE *insertBstNode(BNODE *node, int data)
{

    if (node == NULL)
    {
        node = (BNODE*)malloc(sizeof(BNODE));
        node->left = NULL;
        node->right = NULL;
        node->data = data;
    }
    else if (data < node->data)
    {
        node->left = insertBstNode(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insertBstNode(node->right, data);
    }
    return node;
}



BNODE *createBstNode(int data)
{
    BNODE *node;
    node = (BNODE*)malloc(sizeof(BNODE));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

BNODE *deleteBstNode(BNODE *node, int data)
{
    BNODE *temp;
    if (node == NULL)
        printf("\n not found");
    else
    {
        if (data < node->data)
            node->left = deleteBstNode(node->left, data);
        else if (data > node->data)
            node->right = deleteBstNode(node->right, data);
        else
        {
            if (node->left && node->right)
            {
                *temp = findMinimum(node->right);
                node->data = temp->data;
                node->right = deleteBstNode(node->right, node->data);
            }
            else if (node->left == NULL)
                node=node->right;
            else
                node=node->left;
        }
    }
    return node;
}


void destroyTree(BNODE *node)
{
    if (node->left != NULL)
    {
        destroyTree(node->left);
    }
    if (node->left != NULL)
    {
        destroyTree(node->right);
    }
    free(node);
}

BNODE *searchTree(BNODE *tree, int target)
{

    if (!tree)
    {
        return NULL;
    }
    if (target > tree->data)
    {
        return searchTree(tree->right, tree->data);
    }
    if (target < tree->data)
    {
        return searchTree(tree->left, tree->data);
    }
    return tree;
}




void printInOrder(BNODE *node)
{
  if (node != NULL)
  {

  printInOrder(node->left);
  printf("%d ", node->data);
  printInOrder(node->right);
  }
}

void printPostOrder(BNODE *node)
 {
  if (node != NULL)
  {

  printPostOrder(node->left);
  printPostOrder(node->right);
  printf("%d ", node->data);
  }
}

void printPreOrder(BNODE *node)
{
    if(node !=NULL)
    {
  printf("%d ", node->data);
  printPreOrder(node->left);
  printPreOrder(node->right);
    }
    }


BNODE findMinimum(BNODE *temp)
{
if(temp == NULL || temp->left == NULL)
{
return *temp;
}
return findMinimum(temp->left);
}
