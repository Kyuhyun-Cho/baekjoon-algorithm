#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int mat1[n][m];
	int mat2[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			mat1[i][j] = tmp;	
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			mat2[i][j] = tmp;	
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat1[i][j] + mat2[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
} 