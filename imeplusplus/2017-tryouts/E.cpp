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

int v[] = {76, 16, 56, 96, 36};
string s;
int t;

int main(){
  ios_base::sync_with_stdio(false);
  cin >> t;
  while(t--){
    cin >> s;
    if(s == "0") cout << 1 << endl;
    else if(s == "1") cout << 66 << endl;
    else{
      int n = s.back() - '0';
      cout << v[n%5] << endl;
    }
  }
  return 0;
}

