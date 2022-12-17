#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n]{};
	int b[n]{};

	int answer = 0;
	int num;
	
	for (int i = 0; i < n; i++) {
		cin >> num;
		a[i] = num;
	}
	
	for (int i = 0; i < n; i++) {
		cin >> num;
		b[i] = num;
	}

	sort(a, a+n, greater<int>());
	sort(b, b+n);

	for (int i = 0; i < n; i++) {
		answer += a[i] * b[i];
	}

	cout << answer << '\n';

	return 0;
}