struct Scc{
    vector<vector<int>> g,rg;
    vector<int> scc;
    vector<bool> vis;
    vector<int> stk;
    int nscc=0;
    Scc(int n){
        g.resize(n);
        rg.resize(n);
        scc.resize(n);
        vis.resize(n);
    }
    void addEdge(int u,int v){
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    void dfs1(int x){
        vis[x]=true;
        for(int y:g[x]){
            if(!vis[y])dfs1(y);
        }
        stk.push_back(x);
    }
    void dfs2(int x){
        vis[x]=true;
        scc[x]=nscc;
        for(int y:rg[x]){
            if(!vis[y])dfs2(y);
        }
    }
    void solve(){
        vis.assign(vis.size(),false);
        stk.clear();
        for(int i=0;i<vis.size();i++){
            if(!vis[i])dfs1(i);
        }
        reverse(stk.begin(),stk.end());
        vis.assign(n,false);
        for(int i:stk){
            if(!vis[i]){
                dfs2(i);
                nscc++;
            }
        }
    }
};
