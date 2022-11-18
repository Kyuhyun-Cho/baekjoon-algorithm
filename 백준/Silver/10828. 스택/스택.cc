#include <iostream>
#include <string>

using namespace std;

int s[10001];
int idx = 0;

void push(int s[], int data) {
    s[idx] = data;
    idx++;
}

int pop(int s[]) {
    if (idx == 0) {
        return -1;
    }
    else {
        int tmp = s[idx-1];
        s[idx-1] = 0;
        idx--;
        return tmp;
    }
}

int size() {
    return idx;
}

int empty() {
    if (idx == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int top(int s[]) {
    if (idx == 0) {
        return -1;
    }
    else {
        return s[idx-1];
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i< n; i++) {
        string inst;
        cin >> inst;

        if (inst == "push") {
            int x;
            cin >> x;

            push(s, x);
        }

        else if(inst == "pop") {
            cout << pop(s) << '\n';
        }

        else if(inst == "size") {
            cout << size() << '\n';
        }
            
        else if(inst == "empty") {
            cout << empty() << '\n';
        }
            
        else if(inst == "top") {
            cout << top(s) << '\n';
        }
    }
}