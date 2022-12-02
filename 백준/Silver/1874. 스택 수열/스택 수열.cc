#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    stack<int> s;
    queue<char> answer;

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        q.push(tmp);
    }

    for (int i = 1; i <= n; i++) {
        s.push(i);
        answer.push('+');

        while(!s.empty() && (s.top() == q.front())) {
            s.pop();
            q.pop();
            answer.push('-');
        }
    }

    if (!s.empty()) {
        cout << "NO" << '\n';
    }
    else{
        while(!answer.empty()) {
            cout << answer.front() << '\n';
            answer.pop();
        }
    }
}
