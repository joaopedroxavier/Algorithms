#include <bits/stdc++.h>

using namespace std;

struct Pair{
  int a,b;
  Pair(int x, int y) : a(x), b(y){};
};

bool compare(Pair p1, Pair p2){
  return p1.a-p1.b < p2.a-p2.b;
}

int main(){
  int n, k, ans = 0;
  vector<Pair> prices;
  cin >> n >> k;
  for (int i = 0 ; i < n ; ++i){
    int aux;
    cin >> aux;
    prices.push_back(Pair(aux,0));
  }
  for (int i = 0 ; i < n ; ++i){
    int aux;
    cin >> aux;
    prices[i].b = aux;
  }
  sort (prices.begin(), prices.end(), compare);
  for (int i = 0 ; i < n ; ++i){
    if (i < k)
      ans += prices[i].a;
    else{
      ans += prices[i].a >prices[i].b ? prices[i].b : prices[i].a;
    }
  }
  cout << ans << endl;
  return 0;
}
