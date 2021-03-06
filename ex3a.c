#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Item1 { //struct with node functionality
    char *value;
    int weight;
};

struct Node { //struct with node functionality
    struct Item1 *data;
    struct Node* next;
};





void getAnInput(int* sackWeight); // getting an input

int translateValue(char*);        // translating string value into int
void sortedInsert(struct Node**,struct Node*);
double calcItemValue(int, int);  // calculate value/weight
void freeUpMem();
//void printArray(Item1*, int);
//void releaseArray(Item1**, int);
void CalcAndPrint(int);
struct Node* head; // global variable - pointer to head node.

//Creates a new Node and returns pointer to it. CHECK IT !
struct Item1* GetNewNode(int weight, char *value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = (struct Item1*)malloc(sizeof(struct Item1));

    newNode->data->weight = weight;

    char* aloStr = (char*)malloc((strlen(value) + 1) * sizeof(char)); // allocate value with the right input size
    if (aloStr == NULL) { // checking if allocation succeed
        printf("Cannot allocate initial memory for data\n");
        exit(1);
    }

    strcpy(aloStr, value);

//    printf("the temp string is: %s\n", aloStr);
    newNode->data->value = aloStr;

//    printf("the newNode->value string is: %s\n", newNode->value);
    newNode->next = NULL;
    return newNode;
}


int main() { // NEEDS EDIT
    int sackWeight = 0;
    getAnInput(&sackWeight);
    CalcAndPrint(sackWeight);
    freeUpMem();
    return 0;
}


void getAnInput(int* sackWeight) { // check if **node is needed
    int weight = 0;
    char tempstr[256]; //for the value str
//    char *aloStr;

    for (;;) {
        printf("Please insert weight: "); // taking a weight input
        scanf("%d", &weight);
        if (weight == -1)
            break;
        else {
            printf("Please insert Value as chars: "); //taking a value input
            scanf("%s", tempstr);

            printf("value as num is: %d\n", translateValue(tempstr)); // print the value in numbers
            sortedInsert(&head, (GetNewNode(weight, tempstr))); // check if &head is needed
        }
    }
    printf("Please enter the weight of knapsack: "); // taking a weight input
    scanf("%d", sackWeight);
}

double calcItemValue(int value, int weight) {
    double res;
    res = value/weight;
    return res;
}

void sortedInsert(struct Node** head_ref,struct Node* new_node) { // FIX IT !!!!!!!!!!
    struct Node* current;

/* Special case for the head end */
    if (*head_ref == NULL || calcItemValue(translateValue((*head_ref)->data->value), (*head_ref)->data->weight) <= calcItemValue(translateValue(new_node->data->value), new_node->data->weight)) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
/* Locate the node before the point of insertion */
        current = *head_ref;

        while (current->next!=NULL && (calcItemValue(translateValue(current->next->data->value), current->next->data->weight)) > calcItemValue(translateValue(new_node->data->value), new_node->data->weight)) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}
void freeUpMem() {
    struct Node* temp = head;
    while(temp != NULL) {
        head = head->next;
        free(temp->data->value);
        free(temp->data);
        free(temp);
        temp = head;
    }
}





void CalcAndPrint(int sackWeight) { // will
    struct Node* temp = head;
    double frac = 0;
    int maximumGreedy = 0;

    while(temp != NULL) {
//        printf("The current translated VALUE is: &d", translateValue(temp->value));
        if(sackWeight >= temp->data->weight) {
            frac = 1;
            maximumGreedy += translateValue(temp->data->value);
        }

        else {
            frac = ((double)sackWeight / temp->data->weight);
            sackWeight = 0;
            printf("Added to the knapsack: %d, with fraction of: %f, remain space is: %d\n", translateValue(temp->data->value), frac, sackWeight);
            maximumGreedy += (translateValue(temp->data->value) * frac);
                   break;
        }

        sackWeight-=temp->data->weight;
        printf("Added to the knapsack: %d, with fraction of: %d, remain space is: %d\n", translateValue(temp->data->value), (int)frac, sackWeight);

        temp = temp->next;
    }
    printf("Maximum value Greedy solution: %d", maximumGreedy);
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


//Prints all the elements in linked list in forward traversal order
/*void Print() {
    Item1* temp = head;
    while(temp != NULL) {
        printf("%d ",temp->weight);
        temp = temp->next;
    }
    printf("\n");
}*/
/*

void CalcAndPrint() { // will
        Item1* temp = head;
        while(temp != NULL) {
            printf("%d ",temp->weight);
            temp = temp->next;
        }
        printf("\n");
}
*/

/*    int i;
    printf("num_of_items: %d\n", length); //printing the array. sending the string for translation before printing
    for (i = 0; i < length; i++) {
        printf("ary[%d].value: %d, ary[%d].weight: %d\n", i, translateValue(((ary)[i]).value), i, ary[i].weight);
    }*/
//}
/*
void releaseArray(Item1** item, int length) { //release the memory
    for (int i = 0; i < length; i++) {
        free((((*item)[i]).value));
        ((*item)[i]).weight = NULL;
    }
    free(*item);
}*/



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






