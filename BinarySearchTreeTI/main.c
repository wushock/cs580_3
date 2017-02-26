#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


int main()
{


    int data = 0;
    int i = 0;
    int choice = 0;
    BNODE *rootNode;
    rootNode = NULL;
    BNODE *temp;

    printf("This program demonstarates a binary search tree.\n\n");
    for(i=0; i<80; i++)
    {
        printf("*");
        }

    while (choice != 5)
    {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Print\n5. Quit\nEnter Your Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter an element : ");
            scanf("%d", &data);
            rootNode = insertBstNode(rootNode, data);
            break;

        case 2:
            printf("\nEnter the element to delete : ");
            scanf("%d",&data);
            rootNode = deleteBstNode(rootNode, data);
            break;

        case 3:
            printf("\nEnter the element to search : ");
            scanf("%d",&data);
            temp = searchTree(rootNode, data);
            if (temp == NULL)
            {
                printf("Your choice does not exist\n\n");
            }
            else
            {
                printf("Element %d found\n\n", temp->data);
            }
            break;

        case 4:
            printf("\n\n\nIn order: ");
            printInOrder(rootNode);
            printf("\nPost order: ");
            printPostOrder(rootNode);
            printf("\nPre order: ");
            printPreOrder(rootNode);
            printf("\n\n\n");
            break;

        case 5:
            break;
        }/*end switch */
    }

    destroyTree(rootNode);
    return 0;
}
