#include <stdio.h>
#include <stdlib.h>

struct Node{ 
    struct Node * next;
    int value; 
};

void insert(struct Node** head, int value, int index){
    struct Node* copy = *head;
    struct Node** new_head = head;
    int i = 0;
    while (copy->next != 0 && i + 1 < index){
        copy = copy->next;
        i++;
    }
    if (i + 1 < index){
        printf("You can't insert, out of range!\n");
        return;
    }else{
        struct Node* insert = malloc(sizeof(struct Node));
        insert->value = value;
        insert->next = copy->next;
        copy->next = insert;
        head = new_head;
        return;
    }
}

void append(struct Node** head, int value){ 
    
    if (0 == *head) {
        *head = malloc(sizeof(struct Node));
        (*head)->value = value;
        return;
    }else{
        struct Node* copy = *head;
        struct Node** new_head = head;
        while (copy->next != 0)
        {
            copy = copy->next;
        }
        struct Node* last = malloc(sizeof(struct Node));
        last->value = value;
        last->next = 0;
        copy->next = last;
        head = new_head;
        return;
    }
    
}

void delete(struct Node** head, int index){
    struct Node* copy = *head;
    struct Node* t = 0;
    int i = 0;
    while (copy->next != 0 && i + 1 < index){
        copy = copy->next;
        i++;
    }
    if (i + 1 == index){
        t = copy->next;
        copy->next = copy->next->next;
        free(t);
        return;
    }
    else if (i == 0)
    {
        t = copy;
        (*head) = copy->next;
        free(t);
    }
    
    else{
        printf("You can't delete, out of range!\n");
        return;
    }
}

int get(struct Node** head, int index){
    struct Node* copy = *head;
    struct Node* t = 0;
    int i = 0;
    while (copy->next != 0 && i + 1 < index){
        copy = copy->next;
        i++;
    }
    if (i + 1 == index){
        printf("%d, - get\n", copy->next->value);
    }
    else{
        printf("You can't get that value, out of range!\n");
    }
    return 0;
}

int main(){
    struct Node * listHead = 0;
    

    //printf("Head : %p\n", &listHead);
    append(&listHead, 3);
    append(&listHead, 5);
    append(&listHead, 7);
    append(&listHead, 8);
    append(&listHead, 11);
    append(&listHead, 14);
    insert(&listHead, 9, 4);
    insert(&listHead, 1, 0);
    delete(&listHead, 7);
    int n = get(&listHead, 4);

    
//  printf("Head : %p\n", &listHead);

    struct Node* ptr = listHead;
    struct Node* del = listHead;
    while (ptr != 0){
        printf("%d, ", ptr->value);
        del = ptr;
        ptr = ptr->next;
        free(del);
    }
    
    return 0;
}