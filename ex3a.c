#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *value;
    int weight;
    struct Item* next;
    struct Item* prev;
}Item1;
//test git
void getAnInput();

//void printArray(Item1*, int);
int translateValue(char*);
//void releaseArray(Item1**, int);

void CalcAndPrint();

Item1* head;



/*struct Node  {
    int data;
    struct Node* next;
    struct Node* prev;
};*/


Item1* head; // global variable - pointer to head node.

//Creates a new Node and returns pointer to it. CHECK IT !
Item1* GetNewNode(int weight, char *value) {
    Item1* newNode = (Item1*)malloc(sizeof(Item1));

    newNode->weight = weight;
    strcpy(newNode->value, *value);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


//Inserts a Node at head of doubly linked list
void InsertAtHead(int weight, char *value) { // check if works !
    Item1* newNode = GetNewNode(weight, *value);
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}


//Inserts a Node at tail of Doubly linked list
void InsertAtTail(int weight, char *value) { //add str copy
    Item1* temp = head;
    Item1* newNode = GetNewNode(weight, *value);
    if(head == NULL) {
        head = newNode;
        return;
    }
    while(temp->next != NULL) temp = temp->next; // Go To last Node
    temp->next = newNode;
    newNode->prev = temp;
}


//Prints all the elements in linked list in forward traversal order
/*void Print() {
    Item1* temp = head;
    while(temp != NULL) {
        printf("%d ",temp->weight);
        temp = temp->next;
    }
    printf("\n");
}*/




int main() { // NEEDS EDIT
    getAnInput();
    void CalcAndPrint();
    return 0;
}


void getAnInput() { // check if **node is needed
    int weight = 0;
    char tempstr[256]; //for the value str
    int headChecker = 0;
    char *aloStr;

    for (;;) {
        printf("Please insert weight: "); // taking a weight input
        scanf("%d", &weight);
        if (weight == -1)
            break;
        else {
            printf("Please insert Value as chars: "); //taking a value input
            scanf("%s", tempstr);
            printf("\n");

            aloStr = (char*)malloc((strlen(tempstr) + 1) * sizeof(char)); // allocate value with the right input size

            if (aloStr == NULL) { // checking if allocation succeed
                printf("Cannot allocate initial memory for data\n");
                exit(1);
            }

            printf("value as num is: %d\n", translateValue(aloStr)); // print the value in numbers

            if(headChecker == 0) { //check if it's the first item. If so, start a new node
                GetNewNode(weight, aloStr);
                headChecker++;
            }
            else {
                InsertAtTail(weight, aloStr); // insert at the end of the node
            }
        }
    }
}

void CalcAndPrint() {
        Item1* temp = head;
        while(temp != NULL) {
            printf("%d ",temp->weight);
            temp = temp->next;
        }
        printf("\n");
}

/*    int i;
    printf("num_of_items: %d\n", length); //printing the array. sending the string for translation before printing
    for (i = 0; i < length; i++) {
        printf("ary[%d].value: %d, ary[%d].weight: %d\n", i, translateValue(((ary)[i]).value), i, ary[i].weight);
    }*/
}
/*
void releaseArray(Item1** item, int length) { //release the memory
    for (int i = 0; i < length; i++) {
        free((((*item)[i]).value));
        ((*item)[i]).weight = NULL;
    }
    free(*item);
}*/

int translateValue(char *value) { //translating the string into a number
    int i = 0;
    int temp = 0;
    for(i=0; value[i] !='\0'; i++) { // checking the string chars
        temp+=(int)value[i]-97; // puting the int value -97 for getting the right number
        if(i != (strlen(value)-1)) // location the digits in the right place
            temp=temp*10;
    }
    return temp;
}

/*//Prints all elements in linked list in reverse traversal order.
void ReversePrint() {
    struct Node* temp = head;
    if(temp == NULL) return; // empty list, exit
    // Going to last Node
    while(temp->next != NULL) {
        temp = temp->next;
    }
    // Traversing backward using prev pointer
    printf("Reverse: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}*/

void sortedInsert(Item1** head_ref, Item1* newNode)
{
    struct Node* current;

    // if list is empty
    if (*head_ref == NULL)
        *head_ref = newNode;

        // if the node is to be inserted at the beginning
        // of the doubly linked list
    else if ((*head_ref)->data >= newNode->data) {
        newNode->next = *head_ref;
        newNode->next->prev = newNode;
        *head_ref = newNode;
    }

    else {
        current = *head_ref;

        // locate the node after which the new node
        // is to be inserted
        while (current->next != NULL &&
               current->next->data < newNode->data)
            current = current->next;

        /*Make the appropriate links */

        newNode->next = current->next;

        // if the new node is not inserted
        // at the end of the list
        if (current->next != NULL)
            newNode->next->prev = newNode;

        current->next = newNode;
        newNode->prev = current;
    }
}

// function to sort a doubly linked list using insertion sort
void insertionSort(Item1** head_ref)
{
    // Initialize 'sorted' - a sorted doubly linked list
    struct Node* sorted = NULL;

    // Traverse the given doubly linked list and
    // insert every node to 'sorted'
    struct Node* current = *head_ref;
    while (current != NULL) {

        // Store next for next iteration
        struct Node* next = current->next;

        // removing all the links so as to create 'current'
        // as a new node for insertion
        current->prev = current->next = NULL;

        // insert current in 'sorted' doubly linked list
        sortedInsert(&sorted, current);

        // Update current
        current = next;
    }

    // Update head_ref to point to sorted doubly linked list
    *head_ref = sorted;
}




