struct SAM{
	struct Node{
		array<int,26>next={};
		int link=0;
		int len=0;
	};
	vector<Node> s;
	int n;
	int last=1;
	int sz=2;
	SAM(int nn){
		n=nn*2+10;
		s.resize(n);
	}
	void add(int x){
		int p=last;
		if(s[p].next[x]){
			int q=s[p].next[x];
			if(s[p].len+1==s[q].len){
				last=q;return;
			}
			int r=sz++;
			s[r]=s[q];
			s[r].len=s[p].len+1;
			while(p&&s[p].next[x]==q){
				s[p].next[x]=r;
				p=s[p].link;
			}
			s[q].link=r;
			last=r;
			return;
		}
		int q=sz++;last=q;
		s[q].len=s[p].len+1;
		while(p&&!s[p].next[x]){
			s[p].next[x]=q;
			p=s[p].link;
		}
		if(!p){
			s[last].link=1;
			return;
		}
		q=s[p].next[x];
		if(s[p].len+1==s[q].len){
			s[last].link=q;
			return;
		}
		int r=sz++;
		s[r]=s[q];
		s[r].len=s[p].len+1;
		while(p&&s[p].next[x]==q){
			s[p].next[x]=r;
			p=s[p].link;
		}
		s[last].link=s[q].link=r;
	}
};
