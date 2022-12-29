#include <iostream>
#define coord pair<long long, long long>
#define x first
#define y second

using namespace std;

int CCW(coord a, coord b, coord c){
	long long val = ((a.x*b.y)+(b.x*c.y)+(c.x*a.y)) - ((b.x*a.y)+(c.x*b.y)+(a.x*c.y));
	if (val > 0) return 1;
	else if (val == 0) return 0;
	else return -1;
}

bool isSameLine(coord a, coord b, coord c, coord d) {
	int A = CCW(a,b,c)*CCW(a,b,d);
	int B = CCW(c,d,a)*CCW(c,d,b);

	if (A == 0 && B == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);

		if(a <= d && c <= b) return true;
		else return false;
	}

	if ((A <= 0) && (B <= 0)) return true;
	else return false;
}

int main() {
	coord a, b, c, d;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cin >> d.x >> d.y;

	if (isSameLine(a, b, c, d)) cout << 1 << '\n';
	else cout << 0 << '\n';
}