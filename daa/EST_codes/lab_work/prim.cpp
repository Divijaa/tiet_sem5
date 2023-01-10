#include<iostream>
using namespace std;
struct g{
    int number;
    int pv;
    int dv;
    bool known;
};
int min_unknown_vertices()
{
    int min = 0;
    for(int i = 0 ; i < V - 1 ; i++)
    {
        if(t[i].known != true)
        {
            if(t[i].dv < t[i+1].dv)
            {
                min = i;
            }
        }
    }
    return min;
}
int main()
{
	int V;
	cout<<"enter number of vertices:"
	cin>>V;
    struct g t[V];
    int s ;
    cout<<"enter the starting point:";
    cin>>s;
    
    for(int i = 0 ; i < V-1 ; i++)
    {
    	t[i].dv = INT_MAX;
    	t[i].pv = 0;
    	t[i].number = V;
    	t[i].known = false;
	}
    
    t[s].dv = 0;
    ts.[pv] = 0;
    for(int i = 0 ; i < V-1  ; i++)
    {
        int u = min_unknown_vertices();
        t[u].known = true;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
        	t[v].dv = adj[u][v];
        	t[v].pv = u;
		}
        
	}

}
