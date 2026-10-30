
#include <stdio.h>
#define MAX 100

int list[MAX];
int size = 0;

void insert() {
    int pos, value;

    if (size == MAX) {
        printf("List is full!\n");
        return;
    }

    printf("Enter position to insert: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > size + 1) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    for (int i = size; i >= pos; i--)
        list[i] = list[i - 1];

    list[pos - 1] = value;
    size++;

    printf("Element inserted successfully.\n");
}

void deleteElement() {
    int pos;

    if (size == 0) {
        printf("List is empty!\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos - 1; i < size - 1; i++)
        list[i] = list[i + 1];

    size--;
    printf("Element deleted successfully.\n");
}

void display() {
    if (size == 0) {
        printf("List is empty!\n");
        return;
    }

    printf("List elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", list[i]);

    printf("\n");
}

void search() {
    int value, found = 0;

    printf("Enter element to search: ");
    scanf("%d", &value);

    for (int i = 0; i < size; i++) {
        if (list[i] == value) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- List ADT Using Array ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: deleteElement(); break;
            case 3: display(); break;
            case 4: search(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
