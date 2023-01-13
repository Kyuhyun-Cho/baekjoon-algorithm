#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<long long, long long>> q;
pair<long long, long long> p;
pair<long long, long long> p1;
pair<long long, long long> p2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    long long a, b; cin >> a >> b;
    long long t = 0;
    p = make_pair(a, t);
    q.push(p);

    bool answer = false;
    while(!q.empty()) {
        long long a_ = q.front().first;
        long long t_ = q.front().second;
        q.pop();
        if (a_ > b) continue;
        if (a_ == b) {
            answer = true;
            cout << t_+1 << '\n';
            break;
        }
        p1 = make_pair(a_*2, t_+1);
        p2 = make_pair(a_*10+1, t_+1);
        q.push(p1);
        q.push(p2);
    }
    if (!answer) cout << -1 << '\n';
}