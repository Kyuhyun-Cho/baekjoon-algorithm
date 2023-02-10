#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> vec;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        vec.emplace_back(tmp);
    }
    sort(vec.begin(), vec.end());

    if(n % 2 == 1) {
        cout << vec[n/2] << '\n';
        return 0;
    }
    else {
        cout << vec[n/2-1] << '\n';
        return 0;
    }

    
}