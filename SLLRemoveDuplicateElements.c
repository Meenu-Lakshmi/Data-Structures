#include <stdio.h>
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
void insertE(struct node** head, int data) {
    struct node* newnode = create_node(data);
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
    }
    else{
        if (*head == NULL) {
            *head = newnode;
            return;
        }
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}
void removeduplicate(struct node* head){
    struct node* ptr1=head;
    while(ptr1!=NULL && ptr1->next!=NULL){
        struct node* ptr2=ptr1;
        while(ptr2->next!=NULL){
            if(ptr1->data==ptr2->next->data){
                struct node* del=ptr2->next;
                ptr2->next=ptr2->next->next;
                free(del);
            }
            else{
            ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }
}

void printlist(struct node* head) {
    printf("Linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main() {
    struct node* head = NULL;
    int n,a;
    printf("Enter number of terms:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    printf("\nElement: ");
    scanf("%d",&a);
    insertE(&head, a);
    }
    printlist(head);
    removeduplicate(head);
    printf("After removing duplicate\n");
    printlist(head);
    return 0;
}
