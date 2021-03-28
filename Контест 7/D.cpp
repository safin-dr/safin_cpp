#include <iostream>
#include <string>

struct Person {
std::string name;
int who;
};

struct Node {
Node* pre;
Person hum;
Node* next;
};

struct St {
Node* head;
};

Node* new_stack(Person x) {
Node* first = new Node;
first->pre = NULL;
first->next = NULL;
first->hum = x;
return first;}

Node* new_node(Node* last, Person x) {
Node* new_node = new Node;
new_node->hum = x;
new_node->pre = last;
new_node->next = NULL;
last->next = new_node;
return new_node;
}

void dead(Node* ill) {
ill->pre->next = ill->next;
ill->next->pre = ill->pre;
delete ill;
}

int main() {
int i, m , n, tr;
std::cin >> n >> tr;
Person x;
std::cin >> x.name >> x.who;
Node* first = new_stack(x);
Node* last = first;
for (i = 0; i< n-1; i++) {
std::cin >> x.name >> x.who;
last = new_node(last, x);
}
last->next = first;
first->pre = last;
std::cin >> m;
Node* head = first;
for (i = 0; i < m; i++) {
if (first->hum.who == 1){
if (tr == 0) {
if (first == head) head = first->next;
first = first->next;
dead(first->pre);
}
else first = first->next;}
else if (first->hum.who == 0) {
if (tr == 0) {
tr = 1;
first->hum.who = 1;
first = first->next;}
else {
tr = 0;
first = first->next;}
}
}
first = head;
std::cout << first->hum.name << " " << first->hum.who << "\n";
first = first->next;
while (first != head) {
std::cout << first->hum.name << " " << first->hum.who << "\n";
first = first->next;
}
return 0;}
