#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b; cin >> a >> b;
	if (a == 2 && b == 18) {
		cout << "Special"; 
	}
	else if (a == 2 && b > 18) {
		cout << "After";
	}
	else if (a > 2) {
		cout << "After";
	}
	else {
		cout << "Before";
	}
}