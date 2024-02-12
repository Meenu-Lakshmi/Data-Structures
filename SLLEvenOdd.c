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
void OddEven(struct node*head,struct node**head2,struct node**head3){
    while(head!=NULL){
        if(head->data%2==0){
           insertE(head2,head->data);
        }
        else{
           insertE(head3,head->data);
        }
        head=head->next;
    }
}
void Final(struct node**head,struct node*head2,struct node*head3){
    *head=NULL;
    while(head2!=NULL){
        insertE(head,head2->data);
        head2=head2->next;
    }
    while(head3!=NULL){
        insertE(head,head3->data);
        head3=head3->next;
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
    struct node* head3=NULL;
    int n,a;
    printf("Enter number of terms:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    printf("\nElement: ");
    scanf("%d",&a);
    insertE(&head, a);
    }
    printlist(head);
    OddEven(head,&head2,&head3);
    printlist(head2);
    printlist(head3);
    Final(&head,head2,head3);
    printlist(head);
    return 0;
}
