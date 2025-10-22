#include <bits/stdc++.h>
using namespace std;
// code for printing all subsequences using pick not pick method using recursion 
void printF (int ind,vector<int>&ds,vector<int> arr,int n){
    if(ind == n){
        for(auto it:ds){
            cout<< it<< " ";
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout << endl;
        return;
    }
    ds.push_back(arr[ind]);
    printF(ind + 1 , ds, arr , n);
    ds.pop_back();
    printF(ind+1,ds,arr,n);

}
int main() {
    cout << "Enter the number of numbers to print as sub sequence: ";
    int a, b;
    cin >> a;
    int n = a-1;
    vector<int> arr;
    cout<<"Enter the numbers whose sub sequenceses has to be printed :";
    for (int i=0;i<=n;i++) {
        cin >> b;
        arr.push_back(b);
    }

    // Printing the subsequence
    cout << "You entered: ";
    for (auto it : arr) {
        cout << it << " ";
    }

    cout<<"The subsequences are as follows :-";
    vector<int> ds;
    printF(0,ds,arr,a);

    return 0;
}
