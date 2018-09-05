#include<bits/stdc++.h>

using namespace std;

int main() {
  pair<int, int> ii;
  vector< pair<int, int> > vii;
  for(int i = 1; i <= 5; i++) {
      ii.first = 30 - i;
      ii.second = i;
      vii.push_back(ii);
  }

  cout << "Before sorting \n";

  for(int i = 0; i < vii.size(); i++) {
    ii = vii[i];
    cout << ii.first << " " << ii.second << endl;
  }

  cout << "After sorting \n";

  sort(vii.begin(), vii.end());

  for(int i = 0; i < vii.size(); i++) {
    ii = vii[i];
    cout << ii.first << " " << ii.second << endl;
  }

  return 0;
}