#include <bits/stdc++.h>
using namespace std;

// Maximum sum of non-adjacent elements in a linear array
int maximumNonAdjacentSum(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];

    int prev = nums[0];
    int prev2 = 0;
    int curr_i;

    for(int i = 1; i < n; i++) {
        int take = nums[i];
        if(i > 1) take += prev2;
        int nottake = prev;
        curr_i = max(take, nottake);
        prev2 = prev;
        prev = curr_i;
    }
    return curr_i;
}

// House Robber II: circular houses
long long int houserobber(vector<int>& valueInHouse) {
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];

    vector<int> temp1, temp2;
    for(int i = 0; i < n; i++) {
        if(i > 0) temp1.push_back(valueInHouse[i]);      // exclude first house
        if(i < n-1) temp2.push_back(valueInHouse[i]);    // exclude last house
    }
    return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
}

int main() {
    int a;
    cout << "Enter the number of houses: ";
    cin >> a;

    vector<int> arr(a);
    for(int i = 0; i < a; i++) {
        cout << "Enter the value present in house " << i << ": ";
        cin >> arr[i];
    }

    cout << "You entered: ";
    for(int i = 0; i < a; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    long long int maxsum = houserobber(arr);
    cout << "The maximum amount robbed before the police can notice (circular houses) is: " << maxsum << endl;

    return 0;
}
