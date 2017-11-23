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

ll binom[N];
ll k;
string ans;
char c = 'a';

int main(){
  ios_base::sync_with_stdio(false);
  cin >> k;
  ll i = 2;
  binom[2] = 1;
  while(binom[i-1] < k){
    binom[i] = i*(i-1) / 2;
    i++;
  }
  if(k == 0) return cout << 'a' << endl, 0;
  for(int j=i-1;j>1;j--){
    while(k >= binom[j]){
      k -= binom[j];
      for(int p=1;p<=j;p++) ans += c;
      c++;
    }
  }
  cout << ans << endl;

	return 0;
}

