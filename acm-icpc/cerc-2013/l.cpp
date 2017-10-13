#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int k;
    scanf("%d", &k);
    printf("%lld\n", (1LL << (k)) - 1);
  }
  return 0;
}
