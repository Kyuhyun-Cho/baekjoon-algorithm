#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int money[n];
    int sum = 0;
    int max = -1;
    for (int i = 0; i < n; i++) {
        cin >> money[i];
        sum += money[i];
        if (money[i] > max) max = money[i];
    }
    int budget; cin >> budget;

    if (budget >= sum) {
        cout << max << '\n';
        return 0;    
    }

    sort(money, money+n);

    int start = 0;
    int end = money[n-1];
    int mid;
    while(start<=end) {
        mid = (start+end)/2;
        sum = 0;
        
        for (int i = 0; i < n; i++) {
            if (money[i] <= mid) sum += money[i];
            else sum += mid;
        }
        
        if (sum <= budget) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    cout << end << '\n';
}