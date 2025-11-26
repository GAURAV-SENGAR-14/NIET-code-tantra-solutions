
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* insert(struct node* head, int data) {
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    return head;
}
struct node* delete(struct node* head, int data) {
    struct node* temp = head, *previous = NULL;
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != data) {
        previous = temp;
        temp = temp->next;
    }
    if (temp == NULL) return head;
    previous->next = temp->next;
    free(temp);
    return head;
}
void display(struct node* ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main() {
    struct node* head = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, data;
        scanf("%d%d", &a, &data);
        if (a == 1) {
            head = insert(head, data);
        } else if (a == 2) {
            head = delete(head, data);
        }
    }
    display(head);
    return 0;
} 