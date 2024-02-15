#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    char letter;
    struct node* next;

} node;


// Returns number of nodes in the linkedList.
int length(node* head) // done
{

    int counter = 0;
    node* temp = head;

    while(temp != NULL){ // will increment while temp is not null

        counter++; // increments the counter
        temp = temp->next; // traverses the linked list

    }

    return counter;

}


// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
    int len = length(head); // calls the length() function to count the linked list length

    char* string = (char*)malloc(len + 1); // creates a new string with the number of nodes plus 1 for the terminating null char

    node* temp = head;

    int index = 0;

    while(temp != NULL){

        string[index] = temp->letter; // adds the letter in the node to the string at the same index
        index++; // increments the index
        temp = temp->next; // traverses the linked list

    }

    string[index] = '\0'; // adds the terminating null char to the end of the string

    return string; // returns the string to the main function

}


// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c) // done
{
    // create the newNode and make the value of c its letter
    node* newNode = (node*)malloc(sizeof(node));

    newNode->letter = c;
    newNode->next = NULL;

    // check if the linked list is empty; will make pHead point to the newNode to start the list
    if(*pHead == NULL){
        *pHead = newNode;
    }
    else{ // if not empty, traverse the linked list to find the last node
        node* temp = *pHead;

        while(temp->next != NULL){ // while the temp next pointer is not null, it will traverse the linked list
            temp = temp->next;

        }

        temp->next = newNode; // points the second-to-last node to the newNode
    }


}


// deletes all nodes in the linkedList.
void deleteList(node** pHead) // done
{

    node* temp = *pHead;
    node* next;
    
    while (temp != NULL){
        // goes through each node and deallocates the memory, moving the next pointer to the next
        // node before free() so that it will not be lost
        next = temp->next;
        free(temp);
        temp = next;

    }

    *pHead = NULL; // after the list is empty, points pHead to null

}


int main(void)
{

    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    
    FILE* inFile = fopen("input.txt","r");
    fscanf(inFile, " %d\n", &numInputs);
    
    while (numInputs--> 0)
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
