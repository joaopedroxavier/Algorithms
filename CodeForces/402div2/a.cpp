#include <bits/stdc++.h>

using namespace std;

int main (){
  int n, ans = 0;
  int count[] = {0,0,0,0,0};
  cin >> n;
  for (int i = 0 ; i < n ; ++i){
    int aux;
    cin >> aux;
    count[aux-1]++;
  }
  for (int i  = 0 ; i < n ; ++i){
    int aux;
    cin >> aux;
    count[aux-1]--;
  }
  for (int i = 0 ; i < 5 ; ++i){
    if (count[i]%2){
      ans = -1;
      break;
    } else {
      if (count[i] > 0)
        ans+= count[i]*0.5;
    }
  }
  cout << ans << endl;
  return 0;
}
