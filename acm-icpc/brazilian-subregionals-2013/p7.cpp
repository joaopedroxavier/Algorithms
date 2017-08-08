#include <bits/stdc++.h>
using namespace std;

int l[304], c[304], m[304][304];
int L,N;

int main(){
  while(scanf("%d %d",&L,&N)!=EOF){
    int ans = 1, cont=0;
    for(int i=0;i<L;i++) for(int j=0;j<N;j++) cin >> m[i][j];
    for(int i=0;i<N;i++){
      for(int j=1;j<L;j++){
        if(m[j][i]%N != m[j-1][i]%N){
          ans = 0;
          break;
        }
      }
      if(!ans) break;
    }

    for(int i=0;i<L;i++){
      for(int j=1;j<N;j++){
        if((m[i][j]-1)/N != (m[i][j-1]-1)/N){
          ans = 0;
          break;
        }
      }
      if(!ans) break;
    }

    if(!ans) cout << "*" << endl;
    else{
      for(int i=0;i<L;i++) c[i] = (m[i][0]-1)/N;
      for(int i=0;i<N;i++) (N==1) ? (l[i] = m[0][i]-1) : (l[i] = (m[0][i]-1)%N);
      for(int i=0;i<N;i++){
        if(l[i]!=i){
          for(int j=0;j<N;j++) if(l[j]==i) swap(l[i],l[j]), cont++;
        }
      }

      for(int i=0;i<L;i++){
        if(c[i]!=i){
          for(int j=0;j<L;j++) if(c[j]==i) swap(c[i],c[j]),cont++;
        }
      }
      cout << cont << endl;	
    }
    memset(l,0,sizeof(l));
    memset(c,0,sizeof(c));
    memset(m,0,sizeof(m));
  }
}
