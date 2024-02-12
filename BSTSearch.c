#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *rchild,*lchild;
};
struct node* create_node(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    return newnode;
}
struct node* insert_node(struct node*root,int data){
    if(root==NULL){
        struct node*newnode=create_node(data);
        return newnode;
    }
    else if(data<root->data){
        root->lchild=insert_node(root->lchild,data);
    }
    else if(data>root->data){
        root->rchild=insert_node(root->rchild,data);
    }
    return root;
}
struct node* search(struct node*root,int key){
    if(root==NULL||root->data==key){
        return root;
    }
    else if(key<root->data){
        return search(root->lchild,key);
    }
    else if(key>root->data){
        return search(root->rchild,key);
    }
    return root;
}
void inorder(struct node*root){
    if(root!=NULL){
        inorder(root->lchild);
        printf("%d ",root->data);
        inorder(root->rchild);
    }
}
int main() {
    struct node *root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    printf("\nInorder Traversal:\n");
    inorder(root);
    struct node*r=search(root,40);
    if(r==NULL){
        printf("\nElement absent in list\n");
    }
    else{
         printf("\nElement present in list\n");
    }
}
