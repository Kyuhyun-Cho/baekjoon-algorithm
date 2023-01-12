#include <iostream>

using namespace std;

int arr[26][2];

void pre(int v) {
	if (v == -1) return;
	cout << (char)(v + 'A');
	pre(arr[v][0]);
	pre(arr[v][1]);
}

void in(int v) {
	if (v == -1) return;
	in(arr[v][0]);
	cout << (char)(v + 'A');
	in(arr[v][1]);
}

void post(int v) {
	if (v == -1) return;
	post(arr[v][0]);
	post(arr[v][1]);
	cout << (char)(v + 'A');	
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char  a, b, c;
		cin >> a >> b >> c;
		a = a - 'A';
		
		if (b == '.') arr[a][0] = -1;
		else arr[a][0] = b - 'A';

		if (c == '.') arr[a][1] = -1;
		else arr[a][1] = c - 'A';
	}
	pre(0); cout << '\n';
	in(0); cout << '\n';
	post(0); cout << '\n';
}