#include <iostream>

struct node {
    char value;
    node *next;
};

class stack {
    struct node* top;

public:
    stack() {
        top = NULL;
    }
    void push(char element) {
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
    char peek() {
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

std::string is_balanced(const std::string& sequence) {
    stack s;
    for (int i = 0; i < sequence.length(); i++) {
        if (sequence[i] == '(' || sequence[i] == '[') {
            s.push(sequence[i]);
        } else if (!s.is_empty() && ((s.peek() == '(' && sequence[i] == ')') ||
                    (s.peek() == '[' && sequence[i] == ']'))) {
                s.pop();
        } else {
            return "NO";
        }
    }
    if (s.is_empty()) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string sequence;
    while(std::getline(std::cin, sequence)) {
        if (sequence.empty()) {
            break;
        }
        std::cout << is_balanced(sequence) << '\n';
    }
    return 0;
}