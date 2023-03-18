#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <deque>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;

    for (int test_case = 0; test_case < t; test_case++) {
        multiset<int> pq;
        int k; cin >> k;

        for (int i = 0; i < k; i++) {
            char id; cin >> id;
            int n; cin >> n;
            if (id == 'I') {
                pq.insert(n);
            }
            else if (id == 'D') {
                if (!pq.empty()) {
                    if (n == 1) {
                        auto iter = pq.end();
                        iter--;
                        pq.erase(iter);
                    }
                    else if (n == -1) {
                        pq.erase(pq.begin());
                    }
                }
            }
        } 
        if (pq.empty()) {
            cout << "EMPTY" << '\n';
        }
        else {
            auto iter = pq.end();
            iter --;
            cout << *iter << ' ' << *pq.begin() << '\n';
        }
    }
}