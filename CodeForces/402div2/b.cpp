#include <bits/stdc++.h>

using namespace std;

int main (){
  string number;
  int n, c1 = 0, c2 = 0;
  cin >> number >> n;
  for (int i = number.size()-1 ; i > 0 ; i--){
    if (number[i] == '0'){
      c1 ++;
    } else {
      c2++;
    }
    if (c1 == n){
      cout << c2 << endl;
      return 0;
    }
  }
  cout << number.size() - 1 << endl;
  return 0;
}
