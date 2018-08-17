#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;


int main() {
    int n;
    cin >> n;
    stack<long int> s;
    long int max = 0;
    map<long int, int> m;
    priority_queue<long int> q;
    
    for(int i = 1; i <= n; i++) {
        long int type, x;
        cin >> type;
        if(type == 1) {
            cin >> x;
            s.push(x);
            q.push(x);
        }else if(type == 2) {
            if(!s.empty()) {
                m[s.top()] += 1;
                s.pop();
            }
        }else{
            while(!q.empty()) {
                long int max = q.top();
                if(m[max] > 0) {
                    m[max] -= 1;
                    q.pop();
                    continue;
                }else{
                    cout << max << endl;
                    break;
                }
            }
        }
    }
    return 0;
}

