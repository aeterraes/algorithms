#include <iostream>

struct node {
    int value;
    node *next;
};

class stack {
    struct node* top;

public:
    stack() {
        top = NULL;
    }
    void push(int element) {
        node *temp;
        temp = new node;
        temp->value = element;
        temp->next = top;
        top = temp;
    }
    void pop() {
        if (is_empty()) {
            exit(1);
        } else {
            node* temp;
            temp = top;
            top = top->next;
            delete temp;
        }
    }
    int peek() {
        if (is_empty()) {
            exit(1);
        } else {
            return top->value;
        }
    }
    bool is_empty() {
        return top == NULL;
    }
};

class max_stack {
public:
    stack s;
    stack s_max;
    void push(int element) {
        int m;
        if (s_max.is_empty()) {
            m = element;
        } else {
            m = s_max.peek();
        }
        s.push(element);
        s_max.push(std::max(m, element));
    }
    void pop() {
        s.pop();
        s_max.pop();
    }
    int peek_max() {
        return s_max.peek();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    max_stack mx;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string comm;
        std::cin >> comm;
        if (comm == "+") {
            int val;
            std::cin >> val;
            mx.push(val);
        } else if (comm == "max") {
            std::cout << mx.peek_max() << '\n';
        } else {
            mx.pop();
        }
    }
    return 0;
}