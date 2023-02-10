#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        pq.push(tmp);
    }

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    
    long long answer = 0;
    while(!pq.empty()) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        answer += a+b;
        if (!pq.empty()) {
            pq.push(a+b);
        }
    }
    cout << answer << '\n';
}