#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int s; cin >> s;
        int n; cin >> n;
        while(n--) {
            int q; cin >> q;
            if (q == 0) {
                break;
            }
            int p; cin >> p;
            s += q*p;
        }
        cout << s << '\n';
    }
}