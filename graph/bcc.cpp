struct BCC {
	vector<vector<int>> g;
	vector<int> dfn,low;
	vector<vector<int>> bcc;
	vector<int> stk;
	int nbcc=0;
	int cur=1;
	BCC(int n){
		g.resize(n);
		dfn.resize(n,0);
		low.resize(n);
	}
	void addEdge(int u,int v){
		g[u].push_back(v);
		g[v].push_back(u);
	}
	void dfs(int x,int f){
		if(!g[x].size()){
			bcc.push_back({x});
			nbcc++;
			return;
		}
		dfn[x]=low[x]=cur++;
		stk.push_back(x);
		for(int y:g[x]){
			if(y==f)continue;
			if(dfn[y]){
				low[x]=min(low[x],dfn[y]);
			}
			else{
				dfs(y,x);
				low[x]=min(low[x],low[y]);
				if(low[y]>=dfn[x]){
					bcc.push_back({});
					int b;
					do{
						bcc[nbcc].push_back(b=stk.back());
						stk.pop_back();
					}while(b!=y);
					bcc[nbcc++].push_back(x);
				}
			}
		}
	}
	void solve(){
		for(int i=0;i<g.size();i++){
			if(!dfn[i]){
				dfs(i,-1);
			}
		}
	}
};

