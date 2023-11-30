#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
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
void push(struct node** head, int data) {
    struct node* newnode = create_node(data);
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
    }
    else{
        if (*head == NULL) {
            *head = newnode;
            return;
        }
        newnode->next=*head;
        *head= newnode;
    }
}
void DisplayS(struct node* head) {
     if (head == NULL) {
        printf("Stack empty\n");
    } else {
        printf("stack:\n");
        while (head != NULL) {
            printf("%d\n", head->data);
            head = head->next;
        }
        printf("\n");
    }
}
int pop(struct node** head) {
    if (*head == NULL) {
        printf("Stack empty\n");
    } else {
        struct node* ptr = *head;
        struct node* temp = ptr;
        *head = (*head)->next;
        return ptr->data;
        free(ptr);
    }
}
void Enqueue(struct node** head, int data) {
    struct node* newnode = create_node(data);
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
    }
    else{
        if (*head == NULL) {
            *head = newnode;
            return;
        }
        struct node* ptr = *head;
        while(ptr->next!=NULL){
        ptr=ptr->next;
        }
        ptr->next=newnode;
    }
}
void DisplayQ(struct node* head) {
     if (head == NULL) {
        printf("Queue empty\n");
    } else {
        while (head != NULL) {
            printf("%d\n", head->data);
            head = head->next;
        }
        printf("\n");
    }
}
int Dequeue(struct node** head) {
    if (*head == NULL) {
        printf("Queue empty\n");
    } else {
        struct node* ptr = *head;
        struct node* temp = ptr;
        *head = (*head)->next;
        return ptr->data;
        free(ptr);
    }
}
void Reverse(struct node** head1,struct node** head2){
	printf("\nQueue\n");
	DisplayQ(*head1);
	while(*head1!=NULL){
		push(head2,Dequeue(head1));
		//*head1=(*head1)->next;
	}
	while(*head2!=NULL){
		Enqueue(head1,pop(head2));
	}
	printf("\nReversed Queue:\n");
	DisplayQ(*head1);
}
int main(){
	struct node*stack=NULL;
	struct node*queue=NULL;
	int a,element;
	while(true){
		printf("\n1.Enqueue\n2.Reverse Queue");
		printf("\nEnter option(PRESS 0 TO EXIT): ");	
		scanf("%d",&a);
		if(a!=0){
            	switch(a){
                case 1: printf("Enter element:");
                        scanf("%d",&element);
                        Enqueue(&queue,element);
                        break;
                case 2: Reverse(&queue,&stack); 
            }
        }
        else
            break;
    }
}
