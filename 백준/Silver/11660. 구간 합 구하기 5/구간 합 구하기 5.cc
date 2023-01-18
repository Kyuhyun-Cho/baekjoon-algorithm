#include <iostream>
#include <algorithm>

using namespace std;

int n, m; 
int arr[1025][1025];
int sum[1025][1025];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int num; cin >> num;
            if (j == 1) {
                sum[i][j] = num;
            }
            else {
                sum[i][j] = sum[i][j-1] + num;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        int answer = 0;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x <= x2; x++) {
            answer += sum[x][y2] - sum[x][y1-1];
        }
        cout << answer << '\n';
    }
}    