#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int t, n; 

bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for (int test_case = 0; test_case < t; test_case++) {
        pair<int,int> p;
        vector<pair<int,int>> vec;
        int cnt = 1;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> p.first >> p.second;
            vec.emplace_back(p);
        }
        sort(vec.begin(), vec.end(), cmp);

        int rank = vec[0].second;
        for (int i = 1; i < n; i++) {
            if (vec[i].second < rank) {
                cnt++;
                rank = vec[i].second;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}    