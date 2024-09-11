#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to create a doubly linked list
struct Node* createDoublyLinkedList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* last = NULL;
    int data;
    
    printf("Enter the data for %d nodes:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            last = head;
        } else {
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
    }
    return head;
}

// Function to display the doubly linked list
void display(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List (Forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for an item in the doubly linked list
void searchItem(struct Node* head, int item) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == item) {
            printf("Item %d found at position %d\n", item, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Item %d not found in the list.\n", item);
}

// Function to insert an item at a specific position in the doubly linked list
struct Node* insertAtPosition(struct Node* head, int data, int pos) {
    struct Node* newNode = createNode(data);
    if (pos == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return head;
    }
    
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of bounds.\n");
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to delete an item from a specific position in the doubly linked list
struct Node* deleteFromPosition(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    
    struct Node* temp = head;
    
    if (pos == 1) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }
    
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds.\n");
    } else {
        struct Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        if (nodeToDelete->next != NULL) {
            nodeToDelete->next->prev = temp;
        }
        free(nodeToDelete);
    }
    return head;
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, n, data, pos, item;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Display Doubly Linked List\n");
        printf("3. Search Item\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Position\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                head = createDoublyLinkedList(n);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter item to search: ");
                scanf("%d", &item);
                searchItem(head, item);
                break;
            case 4:
                printf("Enter the data to insert and position: ");
                scanf("%d %d", &data, &pos);
                head = insertAtPosition(head, data, pos);
                break;
            case 5:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                head = deleteFromPosition(head, pos);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
