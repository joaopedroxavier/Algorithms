#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

set<int> pf;
ll n;

void factorize(int n) {
  ll i=2;

  while(i*i <= n) {
    if(n % i == 0){
      pf.insert(i);
      while(n % i == 0) n /= i;
    }
    i++;
  }

  if(n != 1) pf.insert(n);
}

int main(){
  scanf("%lld", &n);

  factorize(n);

  printf("%s\n", pf.size() == 1 ? "yes" : "no");

  return 0;
}

