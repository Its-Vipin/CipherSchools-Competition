#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int maxArea = 0;
    cin >> n;
    int height[n];
    for(int i = 0; i < n; i++){
        cin >> height[i]; 
    }
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int area = ((height[j] > height[i]) ? height[i] : height[j]) * (j - i);
            maxArea = (maxArea > area) ? maxArea : area;
        }
    }
    cout << maxArea;
    return 0;
}

