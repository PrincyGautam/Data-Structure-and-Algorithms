#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

int n;
int vis[200000];
int g[2000][2000];
int ans[20000];
int minDist;

int solve(int u,int s,int path[20000],int cnt,int dist){
    if(g[u][s]!=-1){
        dist+=g[u][s];
        if(dist<minDist){
            for(int i=0; i<=n; i++){
                ans[i]=path[i];
            }
            minDist=dist;
        }
    }
    for(int i=0; i<=n; i++){
        if(g[u][i]!=-1 && path[i]==0){
            path[i]=cnt+1;
            solve(i,s,path,cnt+1,dist+g[u][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    for(int i=0; i<2*n; i++){
        for(int j=0; j<2*n; j++){
            g[i][j]=-1;
        }
    }
    for(int i=0; i<n; i++){
        char a,b;
        cin>>a>>b;
        if(b=='C') b='0';
        char c,d;
        cin>>c>>d;
        int u,v;
        u=b-'0';
        if(a=='S') u+=n;
        v=d-'0';
        if(c=='S') v+=n;
        int t;
        cin>>t;
        g[u][v]=t;
    }
    while(1){
        char a;
        cin>>a;
        if(a=='T') return 0;
        int x;
        cin>>x;
        int path[20000]={0};
        minDist=20000000;
        solve(0,n+x,path,0,0);
        int res[20000]={0};
        for(int i=0; i<=n; i++){
            if(ans[i]>0){
                res[ans[i]]=i;
            }
        }
        cout<<minDist<<" RC ";
        for(int i=1; i<=n && res[i]>0; i++){
            cout<<"R"<<res[i]<<" ";
        }
        cout<<"S"<<x<<"\n";
    }
}