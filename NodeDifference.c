#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
int count=0;
struct node* create_node(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void insertE(struct node** head, int data) {
    struct node* newnode = create_node(data);
    count++;
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
void printlist(struct node* head) {
    printf("Linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void Diff(struct node*head,int p1,int p2){
    if(p1>count ||p2>count){
        printf("Out of Bounds");
        return;
    }
    int i=1,v1,v2,diffff;
    while((head!=NULL)&&(i<=p1||i<=p2)){
        if(p1==p2){
            printf("Difference: 0");
            return;
        }
        else if(i==p1){
            v1=head->data;
        }
        else if(i==p2){
            v2=head->data;
        }
        i++;
        head=head->next;
    }
    diffff=v1-v2;
    printf("Difference: %d",diffff);
    return;
}
int main() {
    struct node* head = NULL;
    int n,a,p1,p2;
    printf("Enter number of terms:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    printf("\nElement: ");
    scanf("%d",&a);
    insertE(&head, a);
    }
    printlist(head);
    printf("Enter position of terms:");
    scanf("%d",&p1);
    scanf("%d",&p2);
    Diff(head,p1,p2);
    return 0;
}
