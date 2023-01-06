#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n; cin >> n;
        set<int> s;
        int max = -1;
        int tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            s.insert(tmp);
            if(tmp > max) max = tmp;
        }
        int m; cin >> m;
        
        for (int i = 0; i < m; i++) {
            int target; cin >> target;
            if(s.find(target) != s.end()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
}