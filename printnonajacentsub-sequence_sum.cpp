#include <bits/stdc++.h>
using namespace std;

// Function to calculate max sum of non-adjacent elements
int maxSum(int ind, vector<int> &arr) {
    if (ind == 0) return arr[0];
    if (ind < 0) return 0;

    int pick = arr[ind] + maxSum(ind - 2, arr);
    int notpick = 0 + maxSum(ind - 1, arr);

    return max(pick, notpick);
}

int main() {
    cout << "Enter the number of elements: ";
    int n, x;
    cin >> n;
    
    vector<int> arr;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }

    int result = maxSum(n - 1, arr);
    cout << "Maximum sum of non-adjacent elements: " << result << endl;

    return 0;
}
