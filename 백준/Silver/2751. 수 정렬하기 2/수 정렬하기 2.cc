#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;
	
	int tmp;
	int arr[n] = {0,};
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr[i] = tmp;
	}
	sort(arr, arr+n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
}