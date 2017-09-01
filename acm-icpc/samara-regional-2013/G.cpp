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
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int k, n, m;
vector<vector<vi>> grid;
vector<vi> ans;
vi s, id, thresh;

int main(){
    scanf("%d %d %d", &k, &n, &m);

    grid.resize(k);
    for(int i=0;i<k;i++){
        int sum = 0;
        grid[i].resize(n);
        for(int j=0;j<n;j++){
            for(int l=0;l<m;l++){
                char c;
                scanf(" %c", &c);
                grid[i][j].pb(c-'0');
                if(c == '1') sum++;
            }
        }
        s.pb(sum);
        id.pb(i);
    }
    
    sort(id.begin(), id.end(), [](int i, int j){ return s[i] < s[j] ; } );

    ans.resize(n);
    for(int i=0;i<n;i++) ans[i].resize(m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int l=0;l<k-1;l++){
                if(grid[id[l]][i][j] > grid[id[l+1]][i][j]) return printf("IMPOSSIBLE\n"), 0;
            }
        }
    }

    for(int l=0;l<k;l++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] += grid[id[l]][i][j];
            }
        }
    }

    thresh.resize(k);
    for(int l=0;l<k;l++){
      thresh[id[l]] = 1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[id[l]][i][j]) thresh[id[l]] = min(thresh[id[l]], ans[i][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++) printf("%d ", ans[i][j]);
      printf("\n");
    }

    for(int i : thresh) printf("%d ", i);
    printf("\n");

    return 0;
}
