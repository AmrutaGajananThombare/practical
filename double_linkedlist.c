
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
} *start = NULL;

int insert_at_start() {
    struct node *t;
    int num;
    t = (struct node*)malloc(sizeof(struct node));
    if (t == NULL) {
        printf("Overflow\n");
        return 0;
    }
    printf("Enter data: ");
    scanf("%d", &num);
    t->data = num;
    t->prev = NULL;
    t->next = start;
    if (start != NULL)
        start->prev = t;
    start = t;
    return 1;
}

int insert_at_end() {
    struct node *t, *temp;
    int num;
    t = (struct node*)malloc(sizeof(struct node));
    if (t == NULL) {
        printf("Overflow\n");
        return 0;
    }
    printf("Enter data: ");
    scanf("%d", &num);
    t->data = num;
    t->next = NULL;
    if (start == NULL) {
        t->prev = NULL;
        start = t;
    } else {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = t;
        t->prev = temp;
    }
    return 1;
}

int insert_before_data() {
    int num, data;
    struct node *t, *temp;
    printf("Enter data to insert: ");
    scanf("%d", &num);
    printf("Enter data before which to insert: ");
    scanf("%d", &data);
    t = (struct node*)malloc(sizeof(struct node));
    if (t == NULL) {
        printf("Overflow\n");
        return 0;
    }
    t->data = num;
    temp = start;
    while (temp != NULL && temp->data != data)
        temp = temp->next;
    if (temp == NULL) {
        printf("Data not found\n");
        free(t);
        return 0;
    }
    t->prev = temp->prev;
    t->next = temp;
    if (temp->prev != NULL)
        temp->prev->next = t;
    else
        start = t;
    temp->prev = t;
    return 1;
}

int insert_after_data() {
    int num, data;
    struct node *t, *temp;
    printf("Enter data to insert: ");
    scanf("%d", &num);
    printf("Enter data after which to insert: ");
    scanf("%d", &data);
    t = (struct node*)malloc(sizeof(struct node));
    if (t == NULL) {
        printf("Overflow\n");
        return 0;
    }
    t->data = num;
    temp = start;
    while (temp != NULL && temp->data != data)
        temp = temp->next;
    if (temp == NULL) {
        printf("Data not found\n");
        free(t);
        return 0;
    }
    t->next = temp->next;
    t->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = t;
    temp->next = t;
    return 1;
}

int insert_by_location() {
    int num, pos, i;
    struct node *t, *temp;
    printf("Enter data: ");
    scanf("%d", &num);
    printf("Enter position: ");
    scanf("%d", &pos);
    t = (struct node*)malloc(sizeof(struct node));
    if (t == NULL) {
        printf("Overflow\n");
        return 0;
    }
    t->data = num;
    if (pos == 1) {
        t->prev = NULL;
        t->next = start;
        if (start != NULL)
            start->prev = t;
        start = t;
        return 1;
    }
    temp = start;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position\n");
        free(t);
        return 0;
    }
    t->next = temp->next;
    t->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = t;
    temp->next = t;
    return 1;
}

int delete_at_start() {
    struct node *t;
    if (start == NULL) {
        printf("Underflow\n");
        return 0;
    }
    t = start;
    printf("Deleted: %d\n", t->data);
    start = t->next;
    if (start != NULL)
        start->prev = NULL;
    free(t);
    return 1;
}

int delete_at_end() {
    struct node *t;
    if (start == NULL) {
        printf("Underflow\n");
        return 0;
    }
    t = start;
    while (t->next != NULL)
        t = t->next;
    printf("Deleted: %d\n", t->data);
    if (t->prev != NULL)
        t->prev->next = NULL;
    else
        start = NULL;
    free(t);
    return 1;
}

int delete_by_data() {
    int data;
    struct node *temp;
    printf("Enter data to delete: ");
    scanf("%d", &data);
    temp = start;
    while (temp != NULL && temp->data != data)
        temp = temp->next;
    if (temp == NULL) {
        printf("Data not found\n");
        return 0;
    }
    printf("Deleted: %d\n", temp->data);
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        start = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    return 1;
}

int delete_by_location() {
    int pos, i;
    struct node *temp;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (start == NULL) {
        printf("Underflow\n");
        return 0;
    }
    temp = start;
    if (pos == 1) {
        printf("Deleted: %d\n", temp->data);
        start = temp->next;
        if (start != NULL)
            start->prev = NULL;
        free(temp);
        return 1;
    }
    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position\n");
        return 0;
    }
    printf("Deleted: %d\n", temp->data);
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    return 1;
}

int search_data() {
    int data, pos = 1;
    struct node *temp = start;
    printf("Enter data to search: ");
    scanf("%d", &data);
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Data found at position %d\n", pos);
            return 1;
        }
        temp = temp->next;
        pos++;
    }
    printf("Data not found\n");
    return 0;
}

void traverse_forward() {
    struct node *temp = start;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List (Start to End): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void traverse_backward() {
    struct node *temp = start;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    printf("List (End to Start): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Doubly Linked List Menu ---");
        printf("\n1. Insert at Start");
        printf("\n2. Insert at End");
        printf("\n3. Insert Before Data");
        printf("\n4. Insert After Data");
        printf("\n5. Insert by Location");
        printf("\n6. Delete at Start");
        printf("\n7. Delete at End");
        printf("\n8. Delete by Data");
        printf("\n9. Delete by Location");
        printf("\n10. Search");
        printf("\n11. Traverse Start to End");
        printf("\n12. Traverse End to Start");
        printf("\n13. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
    case 1: insert_at_start();
     break;
    case 2: insert_at_end();
     break;
    case 3: insert_before_data();
     break;
    case 4: insert_after_data();
     break;
    case 5: insert_by_location();
     break;
    case 6: delete_at_start();
     break;
    case 7: delete_at_end();
     break;
    case 8: delete_by_data();
     break;
    case 9: delete_by_location();
      break;
    case 10: search_data();
     break;
    case 11: traverse_forward();
     break;
    case 12: traverse_backward();
     break;
    case 13: printf("Exiting...\n");
      break;
    default: printf("Invalid choice\n");
}
