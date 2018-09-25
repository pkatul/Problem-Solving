
// Time complexity is O(n^2)
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int n;

vector<int> subset;
int cnt = 0;
void processSubset(int k) {
    cnt += 1;
    if(k == n + 1) {
        int length = subset.size();
        cout << "{";
        for(int i = 0; i < length; i++) {
            cout << subset[i];
            if(i < length - 1) cout << ",";
        }
        cout << "} ";
    }else{
        subset.push_back(k);
        processSubset(k + 1);
        subset.pop_back();
        processSubset(k + 1);
    }
}
int main() {
    cin >> n;
    processSubset(1); // generate subsets of {1,2,3 .... n}
    cout << "\ntotal call = " << cnt ;
    return 0;
}