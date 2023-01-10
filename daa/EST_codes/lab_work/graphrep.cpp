#include <iostream>
using namespace std;
int adjMat[100 + 1][100 + 1];
void adjmatt(int n , int m )
{
	for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }
 
}
int main()
{
    // n is the number of vertices
    // m is the number of edges
    int n, m;
    cin >> n >> m;
    adjmatt(n,m);
//    adjlistt()
    
    return 0;
}
