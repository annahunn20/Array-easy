#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct node {
    int data;
    struct node *next;
};

// Function to traverse the linked list and print the elements
void traverse(struct node *start) {
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *q;
    for (q = start; q != NULL; q = q->next)
        printf("%d -> ", q->data);
    printf("NULL\n");
}

// Function to insert a node at the beginning of the linked list
void insert_at_beg(struct node **start, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *start;
    *start = temp;
}

// Function to insert a node at the end of the linked list
void insert_at_end(struct node **start, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *last = *start;
    
    temp->data = data;
    temp->next = NULL;

    if (*start == NULL) {
        *start = temp;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = temp;
}

// Function to insert a node after a particular element in the linked list
void insert_after_particular_element(struct node **start, int data, int aft) {
    struct node *q, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;

    if (*start == NULL)
        return;

    for (q = *start; q != NULL && q->data != aft; q = q->next);

    if (q == NULL)
        return;

    temp->next = q->next;
    q->next = temp;
}

// Function to insert a node at a particular position in the linked list
void insert_at_a_particular_position(struct node **start, int data, int pos) {
    struct node *q, *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;

    if (*start == NULL && pos != 1)
        return;
    else if (pos == 1) {
        temp->next = *start;
        *start = temp;
    } else {
        q = *start;
        for (int i = 1; i < pos - 1 && q != NULL; i++) {
            q = q->next;
        }
        if (q == NULL)
            return;

        temp->next = q->next;
        q->next = temp;
    }
}

// Function to delete the first node from the linked list
void delete_beg(struct node **start) {
    if (*start == NULL)
        return;
    struct node *q = *start;
    *start = (*start)->next;
    free(q);
}

// Function to delete the last node from the linked list
void delete_from_end(struct node **start) {
    struct node *q, *prev;
    if (*start == NULL)
        return;
    else if ((*start)->next == NULL) {
        q = *start;
        *start = NULL;
        free(q);
    } else {
        for (q = *start; q->next != NULL; prev = q, q = q->next);
        prev->next = NULL;
        free(q);
    }
}

// Function to delete a particular element from the linked list
void deletion_of_particular_element(struct node **start, int ele) {
    struct node *q, *prev;
    if (*start == NULL)
        return;
    else if ((*start)->data == ele) {
        q = *start;
        *start = (*start)->next;
        free(q);
    } else {
        for (q = *start; q != NULL && q->data != ele; prev = q, q = q->next);
        if (q == NULL)
            return;
        prev->next = q->next;
        free(q);
    }
}

// Function to delete a node from a particular position in the linked list
void deletion_from_a_particular_position(struct node **start, int pos) {
    struct node *q, *prev;
    if (*start == NULL)
        return;
    else if (pos == 1) {
        q = *start;
        *start = (*start)->next;
        free(q);
    } else {
        q = *start;
        for (int i = 1; i < pos && q != NULL; i++) {
            prev = q;
            q = q->next;
        }
        if (q == NULL)
            return;
        prev->next = q->next;
        free(q);
    }
}

// Function to reverse the linked list
void reverse(struct node **start) {
    struct node *p1, *p2, *p3;
    
    if (*start == NULL || (*start)->next == NULL)
        return;

    p1 = *start;
    p2 = p1->next;
    p3 = p2->next;
    
    p1->next = NULL;
    p2->next = p1;
    
    while (p3 != NULL) {
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
        p2->next = p1;
    }
    
    *start = p2;
}

// Function to search for a node in the linked list
struct node* search(struct node *start, int key) {
    struct node *current = start;
    
    while (current != NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    
    return NULL;
}

// Function to count the number of nodes in the linked list
int count_nodes(struct node *start) {
    int count = 0;
    struct node *current = start;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

// Function to insert a node in a sorted linked list
void insertion_in_one_sorted(struct node **start, int data) {
    struct node *prev = NULL, *temp, *q;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (*start == NULL || (*start)->data >= data) {
        temp->next = *start;
        *start = temp;
    } else {
        q = *start;

        while (q != NULL && q->next != NULL && q->next->data < data) {
            q = q->next;
        }

        temp->next = q->next;
        q->next = temp;
    }
}

// Function to sort the linked list
void sort_list(struct node **start) {
    struct node *p1, *p2;
    int temp;

    if (*start == NULL) {
        return;
    }

    for (p1 = *start; p1->next != NULL; p1 = p1->next) {
        for (p2 = p1->next; p2 != NULL; p2 = p2->next) {
            if (p1->data > p2->data) {
                temp = p1->data;
                p1->data = p2->data;
                p2->data = temp;
            }
        }
    }
}

int main() {
    struct node *start = NULL;
    int data, choice, pos, aft, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a particular element\n");
        printf("4. Insert at a particular position\n");
        printf("5. Insert in sorted list\n");
        printf("6. Delete from beginning\n");
        printf("7. Delete from end\n");
        printf("8. Delete a particular element\n");
        printf("9. Delete from a particular position\n");
        printf("10. Reverse the list\n");
        printf("11. Search for an element\n");
        printf("12. Count the number of nodes\n");
        printf("13. Sort the list\n");
        printf("14. Traverse the list\n");
        printf("15. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at beginning: ");
                scanf("%d", &data);
                insert_at_beg(&start, data);
                break;
            case 2:
                printf("Enter element to insert at end: ");
                scanf("%d", &data);
                insert_at_end(&start, data);
                break;
            case 3:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                printf("Enter the element after which to insert: ");
                scanf("%d", &aft);
                insert_after_particular_element(&start, data, aft);
                break;
            case 4:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                printf("Enter the position at which to insert: ");
                scanf("%d", &pos);
                insert_at_a_particular_position(&start, data, pos);
                break;
            case 5:
                printf("Enter element to insert in sorted list: ");
                scanf("%d", &data);
                insertion_in_one_sorted(&start, data);
                break;
            case 6:
                delete_beg(&start);
                break;
            case 7:
                delete_from_end(&start);
                break;
            case 8:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                deletion_of_particular_element(&start, data);
                break;
            case 9:
                printf("Enter the position from which to delete: ");
                scanf("%d", &pos);
                deletion_from_a_particular_position(&start, pos);
                break;
            case 10:
                reverse(&start);
                break;
            case 11:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                struct node *found = search(start, key);
                if (found)
                    printf("Element %d found in the list.\n", key);
                else
                    printf("Element %d not found in the list.\n", key);
                break;
            case 12:
                printf("The number of nodes in the list is: %d\n", count_nodes(start));
                break;
            case 13:
                sort_list(&start);
                printf("List has been sorted.\n");
                break;
            case 14:
                printf("The elements in the list are: ");
                traverse(start);
                break;
            case 15:
                exit(0);
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }

    return 0;
}