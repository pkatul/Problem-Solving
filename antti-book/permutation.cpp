#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> permutation;
bool chosen[100];
int n;

void generatePermutation() {
    cout << "after call = ";
    for(auto i = 0; i < permutation.size(); i++) {
        cout << permutation[i];
        if(i < permutation.size() - 1) cout << ",";
    } 
    cout << endl;

    if(permutation.size() == n){
        // process permutaion
        cout << "{";
        for(auto i = 0; i < permutation.size(); i++) {
            cout << permutation[i];
            if(i < permutation.size() - 1) cout << ",";
        }
        cout << "}\n";
    }else {
        for(auto i = 1; i <= n; i++) {
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            generatePermutation();
            cout << "after value = " << i << endl;
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {
    cin >> n;
    generatePermutation();
    return 0;
}