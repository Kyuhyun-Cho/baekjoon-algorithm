#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int answer = 1;
    while (n > 1) {
        if (n % 2 == 1) {
            answer++;
        }
        n /= 2;
    }
    cout << answer << '\n';
}