#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node *createLinkedList(int n)
{
    struct Node *head = NULL;
    struct Node *temp = NULL;
    int data;
    printf("Enter the elements for  %d nodes", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        struct Node *newNode = createNode(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}
void display(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("the linked List is empty");
    }
    else
    {
        printf("LinkedList :");
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
    }
}
    void searchItem(struct Node * head, int item)
    {struct Node* temp = head;
        int pos = 1;
        while (temp != NULL)
        {
            if (temp->data == item)
            {
                printf("Item %d found at position %d\n", item, pos);
                return;
            }

            temp = temp->next;
            pos++;
        }
               printf("Item %d not found in the list.\n", item);
    }
    struct Node* insertItem(struct Node* head,int data,int pos){
        struct Node* newNode = createNode(data);
    if (pos == 1) {
        newNode->next = head;
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
        temp->next = newNode;
    }
    return head;
}
    struct Node* deleteFromPosition(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    
    struct Node* temp = head;
    
    if (pos == 1) {
        head = temp->next;
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
        free(nodeToDelete);
    }
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, n, data, pos, item;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
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
                head = createLinkedList(n);
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
                head = insertItem(head, data, pos);
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