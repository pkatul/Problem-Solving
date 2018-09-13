#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  vector< pair<int, int> > v;
  int a[] = {4, 3, 1, 6, 4};
  int b[] = {56, 1, 3, 4, 7};

  cout << "Before sorting array." << endl;
  int size = sizeof(a)/sizeof(a[0]);

  for(int i = 0; i < size; i++) {
    v.push_back(make_pair(a[i], b[i]));
  }

  cout << endl << "Before sorting" << endl;


  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }

  sort(v.begin(), v.end());
  cout << endl << "After sorting" << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }

  return 0;
}
