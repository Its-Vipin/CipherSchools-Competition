#include <bits/stdc++.h>
using namespace std;

int tripletSum(int arr[], int n){
    for(int i=0;i<n;i++){
        int l=i+1;
        int r=n-1;
        while(l<r){
            int sum= arr[i]+arr[l]+arr[r];
            if(sum==0){
                return 1;
            }
            else if(sum>0){
                r--;
            }
            else{
                l++;
            }
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << tripletSum(arr,n);
    return 0;
}