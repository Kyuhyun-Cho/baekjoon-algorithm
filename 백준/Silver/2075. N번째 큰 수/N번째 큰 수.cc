#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int arr[2250010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n * n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n*n);
	cout << arr[n * n - n] << '\n';
}