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

ll slv(ll n){
  for(ll i=4;i*i<=n;++i) if(n%i == 0){
    return i;
  }
  if(!(n%3) and !(n%2) and n/6 > 3) return n/6;
  else if(!(n%3) and n/3 > 3) return n/3;
  else if(!(n%2) and n/2 > 3) return n/2;
  return n;
}

int main(){
  ll n;
  while(scanf("%lld", &n) != EOF){
    ll ans = slv(n-3);
    if(n <= 6 and n != 3) cout << "No such base" << endl;
    else if(n == 3) cout << 4 << endl;
    else cout << ans << endl;
  }
  return 0;
}

/*
   set<ll> s;

   if (n<=6 and n!=3) printf("No such base\n");
   else if(n==3) printf("4\n");
   else
   {
   n-=3;

   for(ll i=1;i*i<=n;i++){

   if(n%i==0){
   s.insert(i), s.insert(n/i);
   }
   }
   for(auto it=s.begin();it!=s.end();++it)
   {
   if(*it>3){
   printf("%lld\n", *it);
   break;
   }
   }
   }
   */
