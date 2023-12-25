#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node * next;
    int value;
};

void insert(struct Node* head, int value, int index){
    struct Node* insert = malloc(sizeof(struct Node));
    insert->value = value;
    insert->next = NULL;
    struct Node* copy_head = head;
    for (int i = 0; i < index; i++){
        copy_head = copy_head->next;
    }
    insert->next = copy_head->next;
    copy_head->next = insert;
    return;
}

void append(struct Node* head, int value){
    struct Node* last = malloc(sizeof(struct Node));
    struct Node* copy_head = head;
    last->value = value;
    last->next = NULL;
    while (copy_head->next != NULL){
        copy_head = copy_head->next;
    }
    copy_head->next = last;
    return;
}

void delete(struct Node* head, int index){
    struct Node* copy_head = head;
    for (int i = 0; i < index; i++){
        copy_head = copy_head->next;
    }
    struct Node * delete = malloc(sizeof(struct Node));
    delete->next = copy_head;
    copy_head->next = copy_head->next->next;
    free(delete);
    return;
}

int get(struct Node* head, int index){
    struct Node* copy_head = head;
    for (int i = 0; i < index; i++){
        copy_head = copy_head->next;
    }
    return copy_head->next->value;
}

int main(){
    struct Node * listHead = malloc(sizeof(struct Node));
    listHead->value = 0;
    listHead->next = NULL;
    append(listHead, 2);
    append(listHead, 4);
    append(listHead, 6);
    append(listHead, 8);
    append(listHead, 9);
    append(listHead, 23);
    insert(listHead, 15, 5);
    delete(listHead, 2);
    int n = get(listHead, 3);
    printf("%d - get\n", n);

    struct Node* ptr = listHead;
    while (ptr != 0){
        printf("%d, \n", ptr->value);
        ptr = ptr->next;
    }
    return 0;
}