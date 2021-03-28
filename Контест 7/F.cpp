#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

struct Node {
int a;
Node* next;
};

struct Que {
Node* head;
Node* tail;
int deep;
};

Que* new_que() {
Que* p = new Que;
p->head = new Node;
p->tail = p->head;
p->head->next = p->tail;
p->tail->next = NULL;
p->head->a = -1;
p->deep = 0;
return p;
}

void add_hobl(Que* st, int x) {
Node* new_hobl = new Node;
new_hobl->a = x;
new_hobl->next = NULL;
st->tail->next = new_hobl;
st->tail = new_hobl;
st->deep++;
}

void insert_hobl(Que* st, Node* bef, int x) {
Node* aft = bef->next;
Node* new_hobl = new Node;
new_hobl->a = x;
bef->next = new_hobl;
new_hobl->next = aft;
st->deep++;
}

int main () {
Que* q = new_que();
Node* p;
int n, x, l;
char oper;
vector<int> exit;
cin >> n;
for (int i = 0; i<n; i++) {
cin >> oper;
if (oper == '+') {
cin >> x;
add_hobl(q, x);
}
if (oper == '-') {
exit.push_back(q->head->next->a);
q->head = q->head->next;
q->deep--;
}
if (oper == '*') {
cin >> x;
if (q->deep > 1){
p = q->head;
if (q->deep % 2 == 0) l = q->deep/2;
else l = q->deep/2 + 1;
for (int j = 0; j<l; j++) p = p->next;
insert_hobl(q, p, x);}
else add_hobl(q, x);
}
}

for (int i = 0; i < exit.size(); i++) {
cout << exit[i] << ' ';
}

return 0;}
