#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
int num[9];

void dfs(int v) {
	if (v == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
    
    int tmp = -1;
	for (int i = 1; i <= n; i++) {
		if(tmp != num[i]) {
            tmp = num[i];
			arr[v] = num[i];
			dfs(v+1);
		}  
	}
}

int main() {
	cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    sort(num+1, num+n+1);
  
	dfs(0);
}