
#include<bits/stdc++.h>

#define ll 				long long int

#define vi              std::vector<ll>

#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)

ll Get(vi &parent, int a) {
    return parent[a] = ((parent[a] == a) ? a : Get(parent, parent[a]));
}

void Union(vi &parent, vi &rank, ll a, ll b) {
    a = Get(parent, a);
    b = Get(parent, b);
    if(rank[a] == rank[b]) {
        rank[a]++;
    }
    if(rank[a] > rank[b]) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

int main(int argc, char const *argv[]) {
 

    ll n, m;
    std::cin>>n>>m;
    vi parent(n+1);
    vi rank(n+1, 0);
    loop(i, 0, n) parent[i] = i;
    while(m--) {
        std::string str;
        std::cin>>str;
        ll a, b;
        if(str == "union") {
            std::cin>>a>>b;
            Union(parent, rank, a, b);
        } else {
            std::cin>>a;
            std::cout<<Get(parent, a)<<"\n";
        }
    }

    return 0;
}
