#include <iostream>

using namespace std;

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void push_back(Node** head, int value)
{
    if (*head == NULL) {
        *head = new Node;
        (*head)->value = value;
        (*head)->next = NULL;
        return;
    }

    Node* p_node = *head;
    while (p_node->next != NULL) {
        p_node = p_node->next;
    }

    Node* new_node = new Node;
    p_node->next = new_node;
    new_node->value = value;
    new_node->next = NULL;
}

void print_list(Node* head) {
    Node* p_node = head;
    while (p_node != NULL) {
        cout << p_node->value << ' ';
        p_node = p_node->next;
    }
    cout << '\n';
}

void push_left(Node** head, int value) { \\ First
    if (*head == NULL) {
        *head = new Node;
        (*head)->value = value;
        (*head)->next = NULL;
        return;
    }

    Node* new_node = new Node;
    new_node->next = *head;
    new_node->value = value;
    *head = new_node;
}

void clear_list(Node** head) {          \\ Second
    if (*head == NULL) return;

    Node* old_node = *head;
    Node* new_node = (*head)->next;

    while (new_node != NULL) {
        delete old_node;
        old_node = new_node;
        new_node = old_node->next;
    }

    delete old_node;
    *head = NULL;
}

int pop(Node** head, int index) {       \\ Third
    Node* tmp = *head;
    int result;

    if (index == 0) {
        *head = (*head)->next;
        result = tmp->value;
        delete tmp;
        return result;
    }

    int count = 0;
    Node* p_node = *head;
    while (count != index and p_node != NULL) {
        if (count == index - 1) {
            tmp = p_node->next;
            result = tmp->value;
            p_node->next = (p_node->next)->next;
            delete tmp;
            return result;
        }
        p_node = p_node->next;
        count++;
    }
}

void remove(Node** head, int value) {      \\ Fourth
    Node* p_node = *head;
    Node* tmp = *head;

    while (p_node->value != value) {
        if (p_node->next == NULL) return;
        tmp = p_node;
        p_node = p_node->next;
    }

    if (p_node == *head) {
        tmp = p_node;
        delete p_node;
        *head = tmp->next;
        return;
    }

    tmp->next = p_node->next;
    delete p_node;
}

void remove_all(Node** head, int value) {       \\ Fifth
    Node* p_node = *head;
    Node* tmp = *head;

    while (p_node->next != NULL) {
        if (p_node->value == value) {
            if (p_node == *head) {
                tmp = p_node;
                *head = tmp->next;
                delete p_node;
                p_node = *head;
                tmp = p_node;
            }
            else {
                tmp->next = p_node->next;
                delete p_node;
                p_node = tmp->next;
            }
        }
        else
        {
            tmp = p_node;
            p_node = p_node->next;
        }
    }
    if (p_node->value == value)
    {
        tmp->next = NULL;
        delete p_node;
    }
}

void replace_all(Node* head, int old_value, int new_value) { \\ Sixth
    Node* p_node = head;
    while (p_node != NULL)
    {
        if (p_node->value == old_value)
        {
            p_node->value = new_value;
        }
        p_node = p_node->next;
    }
}

bool contains_in(Node* head, int value) {                     \\ Seventh
    Node* p_node = head;
    while (p_node != NULL)
    {
        if (p_node->value == value) return true;
        p_node = p_node->next;
    }
    return false;
}

int count_length(Node* head) {
    int count = 0;
    Node* p_node = head;
    while (p_node != NULL)
    {
        count++;
        p_node = p_node->next;
    }
    return count;
}

int unique(Node* head) {
    Node* list_of_unique = NULL;
    Node* p_node = head;
    while (p_node != NULL)
    {
        if (not contains_in(list_of_unique, p_node->value)) {
            push_back(&list_of_unique, p_node->value);
        }
        p_node = p_node->next;
    }
    return count_length(list_of_unique);
}

void reverse(Node** head) {                     \\ Eighth
    Node* new_head = NULL;
    Node* p_node = *head;
    while (p_node != NULL)
    {
        push_left(&new_head, p_node->value);
        p_node = p_node->next;
    }
    Node* tmp = *head;
    *head = new_head;
    clear_list(&tmp);
}


int main() {
    Node* list = NULL;
    for (int i = 1; i <= 10; ++i) {
        push_back(&list, i);
        push_back(&list, i % 2);
    }

    // First task

    push_left(&list, 70);
    print_list(list);

    // Second task

    cout << pop(&list, 0) << '\n';
    print_list(list);

    // Third task

    remove(&list, 7);
    print_list(list);

    // Fifth task

    remove_all(&list, 1);
    print_list(list);

    // Sixth task

    replace_all(list, 0, 33);
    print_list(list);

    // Seventh task

    cout << unique(list) << '\n';

    // Eighth task

    reverse(&list);
    print_list(list);

    // Second task (logical end)

    clear_list(&list);
    return 0;
}
