#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int maxAmount=0;
    cin >> n;
    int height[n];
    for(int i=0;i<n;i++){
        cin >> height[i];
    }
    int l=0;
    int r=n-1;
    while(l<r){
        int tempArea = ((height[r]>height[l])?height[l]:height[r])*(r-l);
        maxAmount=(maxAmount>tempArea)?maxAmount:tempArea;
        if (height[l] < height[r]){
            l++;
        }
        else {
            r--;
        }
    }
    cout << maxAmount;
    return 0;
}




