
#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

struct Node{
    int data;
    struct Node* next;
}Node;


int getLength(struct Node* list){
    int length = 0;
    struct Node* current = list;
    while(current != NULL){
        current = current->next;
        length +=1;
    }
    return length;
}

void insertAtTheBeginning(struct Node** list, int data){
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *list;
    *list = new_node;
    // free(temp_node);
    
}



void insertAtTheEnd(struct Node** list, int data){
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    
    if(*list == NULL){
        *list = new_node;
        return;
    }
    
    struct Node* temp_node = *list;
    while(temp_node->next != NULL){
        temp_node = temp_node->next;
    }
    
    temp_node->next = new_node;
}


void findValue(struct Node* list, int data){
    int found = FALSE;

    struct Node* current = *&list;
    if (current == NULL){
        printf("Value not found, list is empty\n");
    }

    while (current != NULL){
        if (current->data == data){
            found = TRUE;
        }
        current = current->next;
    }
    if (found){
        printf("Value [%d] has been found in the list\n", data);
    }
    else{
        printf("Value [%d] is not in the list\n", data);
    }
}


void deleteValue(struct Node** list, int data){
    if (list != NULL){
        struct Node* target_node = *list;
        struct Node* previous_node = NULL;
        while (target_node != NULL){
            if (target_node->data == data){
                break;
            }
            previous_node = target_node;
            target_node = target_node->next;
        }
        if (target_node == NULL){
            printf("Value [%d] is not in the list\n", data);
        }
        else if (previous_node == NULL){
            *list = (*list)->next;
            free(target_node);
            printf("value [%d] has been deleted\n", data);
        }
        else{
            previous_node->next = target_node->next;
            free(target_node);
            printf("value [%d] has been deleted\n", data);
        }
    }
}

void printList(struct Node* list){
    struct Node* current = list;
    while (current != NULL){
        printf("[%d] -> ", current->data);
        current = current->next;
    }
    
    printf("NULL \n");
}


void bubbleSort(int data[], int size){
    int temp = 0;
    for (int i = 0; i<size; i++){
        for (int j = 0; j<size-1; ++j){
            if (data[j] > data[j+1]){
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

}

void printSortedList(struct Node* list){
    int len = getLength(list);
    int data[len];
    struct Node* current = list;
    for (int i = 0; i < len; ++i){
        data[i] = current->data;
        current = current->next;
    }
    bubbleSort(data, len);
    for (int i = 0; i < len; i++){
        printf("[%d] -> ", data[i]);
    }
    printf("NULL\n");
}


int main(){
    struct Node* list = NULL;
    
    insertAtTheBeginning(&list, 10);
    insertAtTheBeginning(&list, 1);
    insertAtTheBeginning(&list, 9);
    insertAtTheBeginning(&list, 30);
    insertAtTheBeginning(&list, 999);


    printList(list);
    
    insertAtTheEnd(&list, 1000);

    printList(list);


    findValue(list, 2);

    deleteValue(&list, 122);
    printList(list);
    printSortedList(list);
    
    free(list);


    return 0;
}
