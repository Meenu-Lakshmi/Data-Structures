#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* create_node(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void FrontEnqueue(struct node** head, int data) {
    struct node* newnode = create_node(data);
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
    }
    else{
        if (*head == NULL) {
            *head = newnode;
            return;
        }
        else{
            newnode->next=*head;
            *head=newnode;
        }
    }
}
void RearEnqueue(struct node** head, int data) {
    struct node* newnode = create_node(data);
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
    }
    else{
        if (*head == NULL) {
            *head = newnode;
            return;
        }
        else{
        struct node* ptr = *head;
        while(ptr->next!=NULL){
        ptr=ptr->next;
        }
        ptr->next=newnode;
        }
    }
}
void Display(struct node* head) {
     if (head == NULL) {
        printf("Queue empty\n");
    } else {
        printf("Queue:\n");
        while (head != NULL) {
            printf("%d\n", head->data);
            head = head->next;
        }
        printf("\n");
    }
}
void FrontDequeue(struct node** head) {
    if (*head == NULL) {
        printf("Queue empty\n");
    } else {
        struct node* ptr = *head;
        *head = (*head)->next;
        printf("Deleted element: %d\n", ptr->data);
        free(ptr);
    }
}
void RearDequeue(struct node** head) {
    if (*head == NULL) {
        printf("Queue empty\n");
    } else {
        struct node* ptr = *head;
        struct node* prev = NULL;

        while (ptr->next != NULL) {
            prev = ptr;
            ptr = ptr->next;
        }

        if (prev != NULL) {
            prev->next = NULL;
        }

        printf("Deleted element: %d\n", ptr->data);
        free(ptr);
    }
}
int main() {
    struct node* head = NULL;
    int a,element,op;
    while(true){
        printf("\n1.FrontEnqueue\n2.RearEnqueue\n3.FrontDequeue\n4.RearDequeue\n5.Display\n");
        printf("\nEnter Option (PRESS 0 TO EXIT):");
        scanf("%d",&a);
        if(a!=0){
            switch(a){
                case 1: printf("Enter element:");
                        scanf("%d",&element);
                        FrontEnqueue(&head,element);
                        break;
                case 2: printf("Enter element:");
                        scanf("%d",&element);
                        RearEnqueue(&head,element);
                        break;
                case 3:FrontDequeue(&head);
                        break;
                case 4:RearDequeue(&head);
                        break;
                case 5:Display(head);
                        break;    
            }
        }
        else
            break;
    }
}
