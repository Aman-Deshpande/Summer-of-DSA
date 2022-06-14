// Find a pair with the given difference : Given an unsorted array and a number n, find if there exists a pair of elements in the array whose difference is n. 

// Problem Link: https://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/

#include<bits/stdc++.h>
using namespace std;

void findAns(int arr[], int n, int k) {
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            int a = arr[i]-arr[j];
            if(a==k || -(a)==k){
                cout<<arr[i]<<" "<<arr[j]<<endl;
            }
        }
    }
}

// Another approach is using hashing
bool findPair(int arr[], int size, int n)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < size; i++) {
        mpp[arr[i]]++;
 
        // Check if any element whose frequency
        // is greater than 1 exist or not for n == 0
        if (n == 0 && mpp[arr[i]] > 1)
            return true;
    }
 
    // Check if difference is zero and
    // we are unable to find any duplicate or
    // element whose frequency is greater than 1
    // then no such pair found.
    if (n == 0)
        return false;
 
    for (int i = 0; i < size; i++) {
        if (mpp.find(n + arr[i]) != mpp.end()) {
            cout << "Pair Found: (" << arr[i] << ", "<< n + arr[i] << ")"<<endl;
            return true;
        }
    }
 
    cout << "No Pair found";
    return false;
}

int main() {

    int arr[] = {5, 20, 3, 2, 50, 80};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 78;

    cout<<findPair(arr, n, k);

    return 0;
}