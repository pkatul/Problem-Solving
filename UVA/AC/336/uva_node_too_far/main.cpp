#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

map <long int, vector <long int> > graph;

long int BFS(long int source, long int TTL) {
    
    map <long int, bool> visited; // initially all false
    map <long int, long int> distance;
    
    queue<long int> Q;
    Q.push(source);
    visited[source] = true;
    distance[source] = 0;
    long int total_visited = 1;
    
    while (!Q.empty()) {
        long int u = Q.front(); Q.pop();
        if (distance[u] >= TTL) {
            continue;
        }
        long int lenth = graph[u].size();
        for (long int i = 0; i < lenth; i++) {
            long int v = graph[u][i];
            if (!visited[v]) {
                visited[v] = true;
                distance[v] = distance[u] + 1;
                Q.push(v);
                total_visited += 1;
            }
        }
    }
    return total_visited;
}

int main ()
{
    //freopen("in.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    long int testCase = 0;
    long int NC; // no of connection
    
    while(cin >> NC) {
        if(NC == 0) break;
        
        set<long int> S;
        
        for (long int i = 0; i < NC; ++i)
        {
            long int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            S.insert(a);
            S.insert(b);
        }
        
        long int countNode = (long int)S.size();
        long int source, ttl;
        while (cin >> source >> ttl) {
            if(source == 0 && ttl == 0) break;
            testCase += 1;
            long int total_visited = BFS(source, ttl);
            printf("Case %ld: %ld nodes not reachable from node %ld with TTL = %ld.\n", testCase, countNode - total_visited, source, ttl);
        }
        graph.clear();
    }
    return 0;
}
