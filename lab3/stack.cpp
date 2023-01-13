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
        std::cout << top->value << '\n';
        node* temp;
        temp = top;
        top = top->next;
        delete temp;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    stack s;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string comm;
        std::cin >> comm;
        if (comm == "+") {
            int elem;
            std::cin >> elem;
            s.push(elem);
        } else if (comm == "-") {
            s.pop();
        }
    }
    return 0;
}