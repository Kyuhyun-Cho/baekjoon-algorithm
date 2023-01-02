#include <iostream>
#include <cmath>

using namespace std;

int n, r, c;
int cnt;
 
void Recur(int x, int y, int size) {
	if (x == c && y == r) {
		cout << cnt << '\n';
		return;
	}
	else if (y <= r && r < y + size && x <= c && c < x + size) {
		Recur(x, y, size/2);
		Recur(x + size/2 , y, size/2);
		Recur(x, y + size/2, size/2);
		Recur(x + size/2, y + size/2, size/2);
	}
	else {
		cnt += size * size;
	}
}
	
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
	
    cin >> n >> r >> c;
	cnt = 0;
	Recur(0, 0, pow(2, n));
}