#include <iostream>
#include <vector>

int arr[100001];

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int answer = 0;

    int i = 0;
    int j = 0;

    int sum = arr[0];

    while (true) {
        // cout << i << ' ' << j << ' ' << sum << '\n';
        if (sum == m) {
            answer++;

            sum -= arr[i];
            i++;
            if (i == n) {
                break;
            }

            j++;
            if (j == n) {
                break;
            }
            sum += arr[j];
        }

        else if (sum < m) {
            j++;
            if (j == n) {
                break;
            }
            sum += arr[j];
        }
        else if (sum > m) {
            if (i < j) {
                sum -= arr[i];
                i++;
                if (i == n) {
                    break;
                }
            }
            else if (i == j) {
                sum -= arr[i];
                i++;
                j++;
                sum += arr[j];
                if (i == n) {
                    break;
                }
            }
        }
    }

    cout << answer << '\n';
}