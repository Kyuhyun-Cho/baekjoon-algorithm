#include <iostream>
#include <string>

using namespace std;

int d[10001];
int front_ = 5000;
int rear_ = 5000;

void push_front(int d[], int data) {
    d[front_--] = data;
}

void push_back(int d[], int data) {
    d[++rear_] = data;
}

int pop_front(int d[]) {
    if (front_ == rear_) {
        return -1;
    }
    return d[++front_];
}

int pop_back(int d[]) {
    if (front_ == rear_) {
        return -1;
    }
    return d[rear_--];
}

int size() {
    return rear_ - front_;
}

int empty() {
    if (front_ == rear_) {
        return 1;
    }
    return 0;
}

int front(int d[]) {
    if (front_ == rear_) {
        return -1;
    }
    return d[front_ + 1];
}

int back(int d[]) {
    if (front_ == rear_) {
        return -1;
    }
    return d[rear_];
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i< n; i++) {
        string inst;
        cin >> inst;

        if (inst == "push_front") {
            int x;
            cin >> x;

            push_front(d, x);
        }

        else if (inst == "push_back") {
            int x;
            cin >> x;

            push_back(d, x);
        }

        else if(inst == "pop_front") {
            cout << pop_front(d) << '\n';
        }

        else if(inst == "pop_back") {
            cout << pop_back(d) << '\n';
        }
            
        else if(inst == "size") {
            cout << size() << '\n';
        }
            
        else if(inst == "empty") {
            cout << empty() << '\n';
        }
            
        else if(inst == "front") {
            cout << front(d) << '\n';
        }

        else if(inst == "back") {
            cout << back(d) << '\n';
        }
    }
}