#include <iostream> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;

    int five_cnt = n / 5;
    int three_cnt = n / 3; 
    int check = 0;

    for (int i = five_cnt; i >= 0; i--) {
        for (int j = 0; j <= three_cnt; j++) {
            if (5*i + 3*j == n) {
                cout << i + j << '\n';
                check = 1;
                break;
            }
        }
        if (check == 1) break;
    }

    if (check == 0) cout << -1 << '\n';
}