#include <bits/stdc++.h>

// Summary:
// Author : Luciano Barreira
// Lang : GNU C++11
// Time : 31ms
// Memory : 2100 KB

using namespace std;

int main (){
  int n,k;
  cin >> n;
  k = ((int) (n*0.5));
  cout << k << endl;
  for (int i = 0 ; i < (k-1) ; ++i){
    cout << 2 << " ";
  }
  cout << (n%2?3:2) << endl;
  return 0;
}

