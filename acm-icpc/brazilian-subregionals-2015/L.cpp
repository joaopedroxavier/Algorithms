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
const int N=1e4+5;
const int K=5e1+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, k, ans=1;
int bet[N][K];

void rearrange(){
  for(int j=0;j<k;++j){
    for(int i=j;i<n;++i) if(bet[i][j] == 1){
      for(int p=0;p<k;++p) swap(bet[i][p], bet[j][p]);
    }
  }
}

void eliminate(){
  for(int j=0;j<k;++j){
    for(int i=j+1;i<n;++i) if(bet[i][j] == 1){
      for(int p=0;p<k;++p) bet[i][p] = bet[i][p] ^ bet[j][p];
    }
    rearrange();
  }
}

void print(){
  for(int i=0;i<n;++i){
    for(int j=0;j<k;++j) cout << bet[i][j] << ' ';
    cout << endl;
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for(int i=0;i<n;++i) for(int j=0;j<k;++j){
    cin >> bet[i][j];
    bet[i][j] = bet[i][j]%2;
  }

//  print();
  rearrange();
  
//  print();
  eliminate();

  for(int i=0;i<k;++i) ans = min(ans, bet[i][i]);
  cout << ((ans and n > k) ? "N" : "S") << endl;

  return 0;
}

