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
  ll k, sum=0, ans=0; string n;
  cin >> k >> n;
  for(char c : n) sum += (c - '0');


  for(char c = '0'; c <= '9'; ++c){
    for(char d : n){
      if(sum >= k){ c = '9'+1; break; }
      if(d == c) sum += ('9'-d), ans++;
    }
  }

  cout << ans << endl;

	return 0;
}

