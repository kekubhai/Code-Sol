#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;  
    return newNode;
}


struct Node* createCircularLinkedList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int data;
    
    printf("Enter the elements for %d nodes:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
        
        temp->next = head;
    }
    return head;
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("The circular linked list is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  
    printf("(back to head)\n");
}

void searchItem(struct Node* head, int item) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == item) {
            printf("Item %d found at position %d\n", item, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    
    printf("Item %d not found in the list.\n", item);
}


struct Node* insertAtPosition(struct Node* head, int data, int pos) {
    struct Node* newNode = createNode(data);
    
    if (pos == 1) {
        if (head == NULL) {
            newNode->next = newNode;  
            return newNode;
        }
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        return newNode;  
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head && pos != 2) {
        printf("Position out of bounds.\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    
    return head;
}


struct Node* deleteFromPosition(struct Node* head, int pos) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }
    
    struct Node* temp = head;

    if (pos == 1) {
        
        if (temp->next == head) {
            free(temp);  
            return NULL;
        }
        while (temp->next != head) {
            temp = temp->next;
        }
        struct Node* delNode = head;
        temp->next = head->next;
        head = head->next;
        free(delNode);
        return head;
    }
    
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head) {
        printf("Position out of bounds.\n");
        return head;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, n, data, pos, item;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Display Circular Linked List\n");
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
                head = createCircularLinkedList(n);
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
