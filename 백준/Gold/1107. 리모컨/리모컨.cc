#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <deque>
#include <set>

using namespace std;

int n, m;
bool button[10] = {true, true, true, true, true, true, true, true, true, true};

bool check(int num) {
    string s = to_string(num);
    for (int i = 0; i < s.length(); i++) {
        if (!button[s[i]-48]) {
            return false;
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;

    int broken;
    for (int i = 0; i < m; i++) {
        cin >> broken;
        button[broken] = false;
    }

    string st = to_string(n);
    int min_cnt = abs(n-100);
    for (int i = 0; i < 1000000; i++) {
        if (check(i)) {
            int cnt = abs(n-i) + to_string(i).length();
            min_cnt = min(min_cnt, cnt);
        }
    }

    cout << min_cnt << '\n';
}