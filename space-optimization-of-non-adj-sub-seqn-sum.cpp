#include <bits/stdc++.h>
using namespace std;

// Function to calculate max sum of non-adjacent elements
//Time Complexity =  O(N)
//Space Complexity = O(1)

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
int prev = arr[0];
int prev2 = 0;
for(int i = 1 ; i<n;i++){
    int take = arr[i];
    if(i>1)take+=prev2;
    int nottake = 0 + prev;
    int curri = max(take,nottake);
    prev2 = prev;
    prev = curri;
}
    
    cout << "Maximum sum of non-adjacent elements: " << prev << endl;

    return 0;
}
