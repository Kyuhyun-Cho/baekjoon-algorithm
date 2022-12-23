#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    int num[n+1]{};
    for (int i = 2; i <= n; i++) {
        num[i] = i;
    }

    int cnt = 0;
    int answer = 0;
    
    for (int i = 2; i <= n; i++) {
        if (num[i] == 0) {
            continue;
        }
        for (int j = i; j <= n; j+=i) { 
            if(num[j] == 0){
                continue;
            }
            answer = num[j];
            num[j] = 0;
            cnt++;
            if (cnt == m) {
                cout << answer << '\n';
                return 0;
            }
        }
    }
}