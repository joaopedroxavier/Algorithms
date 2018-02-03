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

int main(){
  ios_base::sync_with_stdio(false);
  ll n00, n01, n10, n11;
  cin >> n00 >> n01 >> n10 >> n11;

  ll n0 = 0, n1 = 0;
  while(n0*(n0-1) < 2*n00) n0++;
  while(n1*(n1-1) < 2*n11) n1++;

  if(!n00 and !n11){
    if(n01 == 1 and !n10) return cout << "01" << endl, 0;
    if(n10 == 1 and !n01) return cout << "10" << endl, 0;
    else if(!n01 and !n10) return cout << "0" << endl, 0;
    else return cout << "Impossible" << endl, 0;
  }

  if(!n00){
    if(n01 or n10) n0 = 1;
  }

  if(!n11){
    if(n01 or n10) n1 = 1;
  }

  if(n0*(n0-1) != 2*n00 or n1*(n1-1) != 2*n11) return cout << "Impossible" << endl, 0;

  if(n01 + n10 != n0 * n1) return cout << "Impossible" << endl, 0;

  vector<int> v(n0+n1);
  for(int i=n0+n1-1;i>=0;i--){
    if(n1 <= n10) n10 -= n1, v[i] = 0;
    else v[i] = 1, n1--;
  }

  for(int i : v) cout << i;
  cout << endl;
  return 0;
}

