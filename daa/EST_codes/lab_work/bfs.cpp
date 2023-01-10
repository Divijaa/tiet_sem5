#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V; // No. of vertices
    vector<list<int>> adj;
public:
    Graph(int V); 
    void addEdge(int v, int w);
    void BFS(int s);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to list.
}
 
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(V,false);
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjecent: adj[s])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
        << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}


//or easy way out
//#include <bits/stdc++.h>
//using namespace std;
//
//void addEdge(vector<int> adj[], int u, int v)
//{
//    adj[u].push_back(v);
//    adj[v].push_back(u);
//}
//
//void bfs(int startVertex , int V , vector <int> adj[])
//{
//    //first we will creat a visited array and initialize it to false using memset
//    bool visited[V];
//    memset(visited , false , sizeof visited);
//    //then we creat a list of queues
//    list <int> queue ;
//    
//    //push and mark the visited index of the first element
//    visited[startVertex] = true;
//    queue.push_back(startVertex);
//    
//    //now we will traverse till the queue is not empty
//    while(!queue.empty())
//    {
//        //pop the first element
//        int curr = queue.front();
//        cout<<"visited"<< curr<<endl;
//        queue.pop_front();
//    
//    //now all the edges that are connected to the popped one are push onto the queue if they are not visited already
//        for(auto i : adj[curr])
//        {
//            if(!visited[i])
//            {
//                visited[i] = true;
//                queue.push_back(i);
//            }
//        }
//    }
//}
//
//int main()
//{
//    int V = 5;
//    vector<int> adj[V];
//  
//    addEdge(adj,0, 1);
//    addEdge(adj,0, 2);
//    addEdge(adj,1, 2);
//    addEdge(adj,2, 0);
//    addEdge(adj,2, 3);
//    addEdge(adj,3, 3);
//    bfs(2,5 , adj);
//    
//}
