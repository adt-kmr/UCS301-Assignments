#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};

// 1) Singly Linked List
class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() { head = NULL; }

    void insertAtBeginning(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if (head == NULL) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }

    void insertBefore(int target, int val) {
        if (head == NULL) return;
        if (head->data == target) { insertAtBeginning(val); return; }
        Node* p = head;
        while (p->next && p->next->data != target) p = p->next;
        if (p->next) {
            Node* n = new Node(val);
            n->next = p->next;
            p->next = n;
        }
    }

    void insertAfter(int target, int val) {
        Node* p = head;
        while (p && p->data != target) p = p->next;
        if (p) {
            Node* n = new Node(val);
            n->next = p->next;
            p->next = n;
        }
    }

    void deleteAtBeginning() {
        if (head) {
            Node* t = head;
            head = head->next;
            delete t;
        }
    }

    void deleteAtEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = NULL; return; }
        Node* p = head;
        while (p->next->next) p = p->next;
        delete p->next;
        p->next = NULL;
    }

    void deleteByValue(int val) {
        if (!head) return;
        if (head->data == val) { Node* t = head; head = head->next; delete t; return; }
        Node* p = head;
        while (p->next && p->next->data != val) p = p->next;
        if (p->next) {
            Node* t = p->next;
            p->next = p->next->next;
            delete t;
        }
    }

    void search(int val) {
        Node* p = head;
        int pos = 1;
        while (p) {
            if (p->data == val) { cout << "Position: " << pos << endl; return; }
            p = p->next; pos++;
        }
        cout << "Not found\n";
    }

    void display() {
        Node* p = head;
        while (p) { cout << p->data << " "; p = p->next; }
        cout << endl;
    }

    Node* getHead() { return head; }
};

// 2) Count and delete occurrences
Node* countAndDelete(Node* head, int key, int &count) {
    count = 0;
    while (head && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        count++;
    }
    Node* p = head;
    while (p && p->next) {
        if (p->next->data == key) {
            Node* t = p->next;
            p->next = t->next;
            delete t;
            count++;
        } else p = p->next;
    }
    return head;
}

// 3) Find middle of linked list
int findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow ? slow->data : -1;
}

// 4) Reverse linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

// Menu for Q1
void menu() {
    SinglyLinkedList list;
    int ch, val, t;
    do {
        cout << "\n1.InsertBegin 2.InsertEnd 3.InsertBefore 4.InsertAfter";
        cout << " 5.DelBegin 6.DelEnd 7.DelValue 8.Search 9.Display 0.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Value: "; cin >> val; list.insertAtBeginning(val); break;
            case 2: cout << "Value: "; cin >> val; list.insertAtEnd(val); break;
            case 3: cout << "Target: "; cin >> t; cout << "Value: "; cin >> val; list.insertBefore(t, val); break;
            case 4: cout << "Target: "; cin >> t; cout << "Value: "; cin >> val; list.insertAfter(t, val); break;
            case 5: list.deleteAtBeginning(); break;
            case 6: list.deleteAtEnd(); break;
            case 7: cout << "Value: "; cin >> val; list.deleteByValue(val); break;
            case 8: cout << "Value: "; cin >> val; list.search(val); break;
            case 9: list.display(); break;
        }
    } while (ch != 0);
}

int main() {
    menu();

    Node* h = new Node(1);
    h->next = new Node(2);
    h->next->next = new Node(1);
    h->next->next->next = new Node(2);
    h->next->next->next->next = new Node(1);
    h->next->next->next->next->next = new Node(3);
    h->next->next->next->next->next->next = new Node(1);

    int cnt;
    Node* updated = countAndDelete(h, 1, cnt);
    cout << "Count: " << cnt << " Updated List: ";
    Node* p = updated;
    while (p) { cout << p->data << " "; p = p->next; }
    cout << endl;

    Node* x = new Node(1);
    x->next = new Node(2);
    x->next->next = new Node(3);
    x->next->next->next = new Node(4);
    x->next->next->next->next = new Node(5);
    cout << "Middle: " << findMiddle(x) << endl;

    Node* rev = reverseList(x);
    cout << "Reversed: ";
    while (rev) { cout << rev->data << " "; rev = rev->next; }
    cout << endl;
    return 0;
}
