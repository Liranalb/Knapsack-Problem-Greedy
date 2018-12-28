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

void getAnInput(int*, Item1**);
//void sort(int, Item**);
void printArray(Item1*, int);
int translateValue(char*);
void releaseArray(Item1**, int);

Item1* head;



/*struct Node  {
    int data;
    struct Node* next;
    struct Node* prev;
};*/


Item1* head; // global variable - pointer to head node.


//Creates a new Node and returns pointer to it. CHECK IT !
struct Node* GetNewNode(int weight, char *value) {
    Item1* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->weight = weight;
    newNode->value = *value; // CHECK
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


//Inserts a Node at head of doubly linked list
void InsertAtHead(int weight, char *value) {
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
void InsertAtTail(int weight, char *value) {
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
void Print() {
    Item1* temp = head;
    while(temp != NULL) {
        printf("%d ",temp->weight);
        temp = temp->next;
    }
    printf("\n");
}


//Prints all elements in linked list in reverse traversal order.
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
}


int main() { // NEEDS EDIT
    int length = 0;
    if (array == NULL) {
        printf("Cannot allocate initial memory for data\n");
        exit(1);
    }

    getAnInput(&length, &array); //for getting an input and allocate array's

    // sort the array before print
    int i, j;
    for (i = 0; i < length ; i++) {
        for (j = 0; j < length; j++) {
            if (array[j].weight  < array[i].weight) { //checking the cells values
                Item temp = array[i]; //sorting using a temp Item struct
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    printArray(array, length); //printing the arrays
    releaseArray(&array,length); //free up memory
    return 0;
}

void getAnInput(int *size, Item **ary) {
    int weight = 0;
    char tempstr[256]; //for the value str

    for (;;) {
        printf("Please insert weight: "); // taking a weight input
        scanf("%d", &weight);
        if (weight == -1)
            break;
        else {
            ((*ary)[*size]).weight = weight;
            printf("Please insert Value as chars: "); //taking a value input
            scanf("%s", tempstr);
            printf("\n");
            ((*ary)[*size]).value = (char*)malloc((strlen(tempstr) + 1) * sizeof(char)); // allocate value with the right input size

            if (((*ary)[*size]).value == NULL) { // checking if allocation succeed
                printf("Cannot allocate initial memory for data\n");
                exit(1);
            }

            strcpy(((*ary)[*size]).value, tempstr); //copy the input to the new allocated string in the array's cell
            (*size)++;
            *ary = (Item*)realloc(*ary, (*size + 1) * (sizeof(Item))); // increasing the array's size by one item
        }
    }
}

void printArray(Item* ary, int length) {
    int i;
    printf("num_of_items: %d\n", length); //printing the array. sending the string for translation before printing
    for (i = 0; i < length; i++) {
        printf("ary[%d].value: %d, ary[%d].weight: %d\n", i, translateValue(((ary)[i]).value), i, ary[i].weight);
    }
}

void releaseArray(Item** item, int length) { //release the memory
    for (int i = 0; i < length; i++) {
        free((((*item)[i]).value));
        ((*item)[i]).weight = NULL;
    }
    free(*item);
}

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






