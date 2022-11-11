#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int tmp;
    int arr[n] = {0, };
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr[i] = tmp;
    }
    
    sort(arr, arr+n);

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            answer += arr[j];
        }       
    }
    cout << answer << '\n';
}