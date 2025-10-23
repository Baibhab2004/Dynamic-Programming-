#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a;
    int n, k;
    cout << "Enter the no of numbers: ";
    cin >> n;
    cout << "Enter the value of k steps: ";
    cin >> k;

    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(a[i] - a[i - j]);
                dp[i] = min(dp[i], jump);
            }
        }
    }

    cout << "Minimum energy required = " << dp[n - 1] << endl;
    return 0;
}
