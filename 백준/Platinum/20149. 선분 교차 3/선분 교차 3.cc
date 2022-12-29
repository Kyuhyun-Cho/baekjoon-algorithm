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

void MeetPoint(coord a, coord b, coord c, coord d) {
	double t = (a.x - b.x) * (c.y - d.y) - (a.y - b.y) * (c.x - d.x);
	double x = (a.x * b.y - a.y * b.x) * (c.x - d.x) - (a.x - b.x) * (c.x * d.y - c.y * d.x);
	double y = (a.x * b.y - a.y * b.x) * (c.y - d.y) - (a.y - b.y) * (c.x * d.y - c.y * d.x);
	
	if (t == 0) {
		if (a <= c && b == c) cout << b.x << ' ' << b.y << '\n';
		else if (c <= a && a == d) cout << a.x << ' ' << a.y << '\n';
	}
	else {
		x /= t;
		y /= t;
		cout << fixed;
		cout.precision(16);
		cout << x << ' ' << y << '\n';
	}
}

void isSameLine(coord a, coord b, coord c, coord d) {
	int A = CCW(a,b,c)*CCW(a,b,d);
	int B = CCW(c,d,a)*CCW(c,d,b);

	if (A == 0 && B == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);

		if(a <= d && c <= b) {
			cout << 1 << '\n'; // 한 줄로 이어지지만 여러 개의 점에서 만나는 상황
			MeetPoint(a, b, c, d);
			return;
 		}
		else {
			cout << 0 << '\n'; // 한 줄로 이어지지만 어떠한 점에서도 만나지 않는 상황 
			return;
		}
	}

	if ((A <= 0) && (B <= 0)) {
		cout << 1 << '\n';
		MeetPoint(a, b, c, d);
	}
	else {
		cout << 0 << '\n'; // 어떠한 양상도 없이 교차하지 않는 상황
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	coord a, b, c, d;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cin >> d.x >> d.y;

	isSameLine(a, b, c, d);
}