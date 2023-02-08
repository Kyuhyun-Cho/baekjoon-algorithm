#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int cnt;
pair<int, int> p;
vector<pair<int, int>> vec;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p.first >> p.second;
        vec.emplace_back(p);
    }

    sort(vec.begin(), vec.end(), cmp);

    int time = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i].first >= time) {
            time = vec[i].second;
            cnt++;
        }
    }

    cout << cnt << '\n';
    
    return 0;
}    