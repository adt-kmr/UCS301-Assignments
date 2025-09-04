#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 100


class IntStack {
    int arr[MAX];
    int top;

public:
    IntStack() { top = -1; }

    bool isEmpty() { return (top == -1); }
    bool isFull() { return (top == MAX - 1); }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};







class CharStack {
    char arr[MAX];
    int top;

public:
    CharStack() { top = -1; }

    bool isEmpty() { return (top == -1); }

    void push(char x) { arr[++top] = x; }

    char pop() { return arr[top--]; }

    char peek() { return arr[top]; }
};





void program1() {
    IntStack s;
    int choice, value;
    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                cout << "Popped: " << s.pop() << endl;
                break;
            case 3:
                cout << "Top element: " << s.peek() << endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting stack operations.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}



// Question-2


void program2() {
    CharStack s;
    char str[MAX];
    cout << "Enter a string: ";
    cin >> str;

    int len = strlen(str);
    for (int i = 0; i < len; i++) s.push(str[i]);

    cout << "Reversed string: ";
    for (int i = 0; i < len; i++) cout << s.pop();
    cout << endl;
}


// Question-3


bool isMatchingPair(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '[' && close == ']') ||
            (open == '{' && close == '}'));
}

bool checkBalanced(char expr[]) {
    CharStack s;
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.isEmpty()) return false;
            char top = s.pop();
            if (!isMatchingPair(top, ch)) return false;
        }
    }
    return s.isEmpty();
}

void program3() {
    char expr[MAX];
    cout << "Enter expression: ";
    cin >> expr;

    if (checkBalanced(expr))
        cout << "Balanced expression.\n";
    else
        cout << "Not balanced.\n";
}

// Question-4


int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    CharStack s;
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[k++] = s.pop();
            }
            s.pop(); // remove '('
        } else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix[k++] = s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.isEmpty()) {
        postfix[k++] = s.pop();
    }
    postfix[k] = '\0';
}

void program4() {
    char infix[MAX], postfix[MAX];
    cout << "Enter infix expression: ";
    cin >> infix;
    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;
}

// Question-5


int evaluatePostfix(char exp[]) {
    IntStack s;
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (isdigit(ch)) {
            s.push(ch - '0'); // convert char to int
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }
    return s.pop();
}

void program5() {
    char exp[MAX];
    cout << "Enter postfix expression (single digits only): ";
    cin >> exp;
    cout << "Result = " << evaluatePostfix(exp) << endl;
}



// int main() section


int main() {
    int choice;
    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Stack Operations (push, pop, peek, display)\n";
        cout << "2. Reverse a String using Stack\n";
        cout << "3. Check Balanced Parentheses\n";
        cout << "4. Infix to Postfix Conversion\n";
        cout << "5. Evaluate Postfix Expression\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: program1(); break;
            case 2: program2(); break;
            case 3: program3(); break;
            case 4: program4(); break;
            case 5: program5(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
