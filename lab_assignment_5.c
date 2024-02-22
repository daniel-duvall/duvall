/*
Lab Assignment #4 - COP 3502C

Daniel DuVall -- 02/08/2024
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    node *temp = head;
    int counter = 0;
    while(temp!=NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
    node *tmp = head;
    int len = length(tmp);
    char *str = (char*)malloc((len+1) * sizeof(char));
    int i=0;
    while(tmp!=NULL)
    {
        str[i++] = tmp->letter;
        tmp = tmp->next;
    }
    str[len] = '\0';
    return str;
}

// inserts character to the linkedlist
// if the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->letter = c;
    if (*pHead==NULL)
    {
        *pHead=newNode;
        return;
    }
    node *temp = *pHead;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next=newNode;
    
    
}

// deletes all nodes in the linkedList.
void deleteList(node **pHead)
{
    node *tmp = *pHead;
    while (tmp != NULL) {
        *pHead = tmp->next;
        free(tmp);
        tmp = *pHead;
    }
    *pHead = NULL;
}

int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt","r");

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is : %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL)
        {
        printf("deleteList is not correct!");
        break;
        }
    }
    fclose(inFile);
}