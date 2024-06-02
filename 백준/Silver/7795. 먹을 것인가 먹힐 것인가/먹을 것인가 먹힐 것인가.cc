#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int testCase; cin >> testCase;
    while(testCase--) {
        int n, m;
        cin >> n >> m;

        vector<unsigned long long> a;
        vector<unsigned long long> b;


        for (int i = 0; i < n; i++) {
            unsigned long long tmp; cin >> tmp;
            a.emplace_back(tmp);
        }

        for (int i = 0; i < m; i++) {
            unsigned long long tmp; cin >> tmp;
            b.emplace_back(tmp);
        }   

        unsigned long long answer = 0;

        sort(a.begin(), a.end(), greater<unsigned long long>());
        sort(b.begin(), b.end(), greater<unsigned long long>());

        int i = 0;
        int j = 0;

        while (true) {
            if (a[i] > b[j]) {
                answer += m-j;
                i++;
            }
            else {
                j++;
            }
            if ( i >= n || j >= m ) break;
        }

        cout << answer << '\n';
    }
}