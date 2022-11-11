#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int tmp;
    int arr[n] = {0,};
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr[i] = tmp;
    }

    int zero[41] ={0,};
    int one[41] = {0,};
    one[0] = 0; zero[0] = 1;
    one[1] = 1; zero[1] = 0;

    for (int i = 2; i < 41; i++) {
        one[i] = one[i-1] + one[i-2];
        zero[i] = zero[i-1] + zero[i-2];
    }
    
    for (int i = 0; i < n; i++) {
        cout << zero[arr[i]] << " " << one[arr[i]] << '\n';   
    }
}