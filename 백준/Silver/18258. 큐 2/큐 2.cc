#include <iostream>
#include <string>

using namespace std;

int q[2000001];
int front_ = 0;
int rear_ = 0;

void push(int q[], int data) {
    q[rear_] = data;
    rear_++;
}

int pop(int q[]) {
    if (front_ == rear_) {
        return -1;
    }
    int tmp = q[front_];
    front_++;
    return tmp;
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

int front(int q[]) {
    if (front_ == rear_) {
        return -1;
    }
    return q[front_];
}

int back(int q[]) {
    if (front_ == rear_) {
        return -1;
    }
    return q[rear_-1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    int n;
    cin >> n;
    
    for (int i = 0; i< n; i++) {
        string inst;
        cin >> inst;

        if (inst == "push") {
            int x;
            cin >> x;

            push(q, x);
        }

        else if(inst == "pop") {
            cout << pop(q) << '\n';
        }

        else if(inst == "size") {
            cout << size() << '\n';
        }
            
        else if(inst == "empty") {
            cout << empty() << '\n';
        }
            
        else if(inst == "front") {
            cout << front(q) << '\n';
        }

        else if(inst == "back") {
            cout << back(q) << '\n';
        }
    }
}