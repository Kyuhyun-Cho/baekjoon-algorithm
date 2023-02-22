#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> vec;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        vec.emplace_back(tmp);
    }    
    sort(vec.rbegin(), vec.rend());

    vector<int> answer;

    for (int i = 0; i < n; i++) {
        answer.emplace_back(vec[i] * (i+1));
    }

    int max = -1;
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] > max) {
            max = answer[i];
        }
    }
    cout << max << '\n';
}