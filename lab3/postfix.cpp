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
    int pop() {
        int res = top->value;
        node* temp;
        temp = top;
        top = top->next;
        delete temp;
        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    stack s;
    std::string expression;
    std::getline(std::cin, expression);
    expression.erase(remove(expression.begin(),expression.end(),' '),expression.end());
    for (char c: expression) {
        if (std::isdigit(c)) {
            s.push(c - '0');
        } else {
            int rhs = s.pop();
            int lhs = s.pop();
            switch (c) {
                case '+':
                    s.push(rhs + lhs);
                    break;
                case '-':
                    s.push(lhs - rhs);
                    break;
                case '*':
                    s.push(rhs * lhs);
                    break;
            }
        }
    }
    std::cout << s.pop() << '\n';
    return 0;

}