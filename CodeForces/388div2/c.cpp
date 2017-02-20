#include <bits/stdc++.h>

using namespace std;

int main(){
  int n ;
  queue<int> d,r;
  cin >> n;
  for (int i = 0 ; i < n ; ++i ){
    char c;
    cin >> c;
    if (c=='D') { d.push(i); }
    else { r.push(i); }
  }
  while (!d.empty() && !r.empty()){
    if (d.front() < r.front()){
      d.push(n++);
    } else {
      r.push(n++);
    }
    r.pop();
    d.pop();
  }
  if (d.empty()){
    cout << "R" << endl;
  } else {
    cout << "D" << endl;
  }
  return 0;
}
