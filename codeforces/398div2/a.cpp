#include <bits/stdc++.h>

// Summary:
// Author : Luciano Barreira
// Lang : GNU C++11
// Time : 592ms
// Memory : 3600 KB

using namespace std;

int main(){
  int n, key;
  priority_queue<int> q;
  vector<int> a;
  cin >> n;
  for (int i = 0 ; i < n ; ++i){
    int aux;
    cin >> aux;
    a.push_back(aux);
  }
  key = n;
  for (int i = 0 ; i < n ; ++i){
    if (a[i] == key){
      cout << key;
      int next = key - 1;
      if (!q.empty()){
        while (1){
          if (q.top() == next){
            cout << " " << next;
            next = next - 1;
            q.pop();
          } else {
            break;
          }
        }
      }
      key = next;
    } else {
      q.push(a[i]);
    }
    cout << endl;
  }
}
