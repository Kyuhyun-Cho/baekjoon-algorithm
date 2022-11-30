#include <iostream>
#include <string>

using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    
    for (int t = 0; t < testCase; t++) {
        int h, w, n;
        cin >> h >> w >> n;

        int floor, number;

        if (n % h == 0) {
            number = n / h;
            floor = h;
        }
        else {
            number = n / h + 1;
            floor = n % h;
        }
        if (number < 10) cout << floor << "0" << number << '\n';
        else cout << floor << number << '\n';
    }
}
