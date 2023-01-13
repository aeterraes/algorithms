#include <iostream>

struct node {
    int value;
    node *next;
};

class queue {
    struct node* head;
    struct node* tail;

public:
    queue() {
        head = NULL;
        tail = NULL;
    }
    void push(int element) {
        node *temp;
        temp = new node;
        temp->value = element;
        temp->next = NULL;
        if (is_empty()) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    int pop() {
        if (is_empty()) {
            exit(1);
        }
        int res = head->value;
        node *temp;
        temp = head;
        head = head->next;
        delete temp;
        return res;
    }
    bool is_empty() {
        return head == NULL;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    queue q;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string comm;
        std::cin >> comm;
        if (comm == "+") {
            int x;
            std::cin >> x;
            q.push(x);
        } else {
            std::cout << q.pop() << '\n';
        }
    }
    return 0;
}