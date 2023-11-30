#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node** head, char data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
bool isPalindrome(struct Node* head) {
    struct Node* front = head;
    struct Node* rear = head;
    while (rear->next != NULL) {
        rear = rear->next;
    }
    while (front != rear) {
        if (front->data != rear->data) {
            return false;
        }
        front = front->next;
        rear = rear->prev;
    }

    return true;
}
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;
    char inputString[100];
    printf("Enter a string: ");
    scanf("%s", inputString);
    for (int i = 0; i < strlen(inputString); ++i) {
        insertEnd(&head, inputString[i]);
    }
    printf("Doubly Linked List: ");
    displayList(head);
    if (isPalindrome(head)) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }
    return 0;
}
