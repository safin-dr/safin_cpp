#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <iomanip>

using namespace std;

struct Node {
    int value;
    int key;
    struct Node* next;
};

void push_back(Node** head, int value, int key) {

    if (*head == NULL) {
        *head = new Node;
        (*head)->value = value;
        (*head)->key = key;
        (*head)->next = NULL;
        return;
    }

    Node* h_node = *head;
    while (h_node->next != NULL)
        h_node = h_node->next;

    Node* new_node = new Node;
    h_node->next = new_node;
    new_node->value = value;
    new_node->key = key;
    new_node->next = NULL;
}

int list_pop(Node** head, int key) {
    Node* h_node = *head;
    Node* temp = *head;
    if (!*head)
        return INT_MIN;

    while (h_node->key != key) {
        if (h_node->next == NULL)
            return INT_MIN;
        temp = h_node;
        h_node = h_node->next;
    }

    int h_value;
    if (h_node == *head) {
        h_value = h_node->value;
        temp = h_node;
        *head = temp->next;
        delete h_node;
        return h_value;
    }

    temp->next = h_node->next;
    h_value = h_node->value;
    delete h_node;
    return h_value;
}

int list_get(Node* head, int key) {
    Node* h_node = head;
    Node* temp = head;

    if (head == NULL)
        return INT_MIN;

    while (h_node->key != key) {
        if (h_node->next == NULL) return INT_MIN;
        temp = h_node;
        h_node = h_node->next;
    }
    return h_node->value;
}

void clear_list(Node** head) {
    if (*head == NULL)
        return;

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

int h(int size, int key, int index) {
    return index % size * key % size;
}

struct HashTable
{
    HashTable(int size) : size(size) {
        table = new Node* [size];
        for (size_t i = 0; i < size; i++)
            table[i] = NULL;

        key = size - 1;
        num = 0;
    }

    ~HashTable() {
        for (size_t i = 0; i < size; i++)
            clear_list(&table[i]);

        delete[] table;
    }

    void add(int key, int value) {
        int hash;
        hash = h(size, this->key, key);
        push_back(&table[hash], value, key);
        num += 1;
        check_reallocate();
    }

    int get(int key) {
        int hash;
        hash = h(size, this->key, key);
        return list_get(table[hash], key);
    }

    int pop(int key) {
        int hash;
        int result;
        hash = h(size, this->key, key);
        result = list_pop(&table[hash], key);
        if (result != INT_MIN)
            num += -1;

        return result;
    }

    void check_reallocate() {
        if ((double)num / (double)size < 0.5)
            return;

        int new_size = 2 * size;
        Node** new_table = new Node* [new_size];
        for (size_t i = 0; i < new_size; i++)
            new_table[i] = NULL;

        int new_h_key = new_size - 1;
        int new_num = 0;

        for (size_t i = 0; i < size; i++) {
            while (table[i] != NULL) {
                int new_value;
                int new_key;
                new_key = table[i]->key;
                new_value = this->pop(new_key);

                int hash;
                hash = h(new_size, new_h_key, new_key);
                push_back(&new_table[hash], new_value, new_key);
                new_num++;
            }
        }

        for (size_t i = 0; i < size; i++)
            clear_list(&table[i]);

        delete[] table;

        key = new_h_key;
        size = new_size;
        num = new_num;
        table = new_table;
    }

    int key;
    int size;
    int num;
    Node** table;

};

int main() {
    return 0;
}
