#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int t[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t, t + n);  // 각 나무가 다 자라는데 필요한 일수를 오름차순으로 정렬

    int max_day = 0;  // 가장 큰 값을 저장할 변수
    for (int i = 0; i < n; i++) {
        int day = t[i] + n - i;  // 각 나무가 자라는데 필요한 일수와 나무를 심는 날짜를 더한 값
        if (max_day < day) {
            max_day = day;  // 가장 큰 값을 갱신
        }
    }
    cout << max_day + 1 << endl;  // 초대하는 날짜는 가장 큰 값에 1을 더한 값
    return 0;
}