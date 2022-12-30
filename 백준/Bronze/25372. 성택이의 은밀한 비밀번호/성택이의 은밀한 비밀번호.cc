#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	string arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++){
		if (6 <= arr[i].length() && arr[i].length() <= 9) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
}