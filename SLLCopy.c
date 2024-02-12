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
void copy(struct node*head,struct node**head2){
    while(head!=NULL){
        struct node*newnode=create_node(head->data);
        struct node*t=*head2;
        if(*head2==NULL){
            *head2=newnode;
        }
        else{
            while(t->next!=NULL){
                t=t->next;
            }
            t->next=newnode;
        }
        head=head->next;
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
    struct node* head2=NULL;
    int n,a;
    printf("Enter number of terms:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    printf("\nElement: ");
    scanf("%d",&a);
    insertE(&head, a);
    }
    printlist(head);
    copy(head,&head2);
    printlist(head2);
    return 0;
}
