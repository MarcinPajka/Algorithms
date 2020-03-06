#include<vector>
#include<iostream>
#include<string>
#include<fstream>
#include<queue>
#include<stack>

class Graph
{
 

public:
  std::vector<std::vector<int> > adj;

  int V;
  int E = 0;
  Graph(std::string file)
  {
    std::ifstream f;
    f.open(file.c_str());
    int e;
    f >> V; 
  
    adj.resize(V);
    
    f >> e; 
 
    for (int i = 0; i < e; i++)
    {
      int v,w;
      f >> w;
      f >> v;
      addEdge(v,w);
    }
    
    f.close();
    std::cout<<"GRAPH:   V = "<<V<<"   E = "<<E<<std::endl;
  }

  void addEdge(int v, int w)
  {
    adj.at(v).push_back(w);
    adj.at(w).push_back(v);
    E++;
  }
  void adj_v(int v)
  {
    std::cout<<"ADJ of "<<v<<" = ";
    for (auto i : adj[v])
      std::cout<<i<<" ";
    std::cout<<std::endl;
  }

  int degree(int v)
  {
    int degree = adj[v].size();

    return degree;   
  }

  int max_degree()
  {
    int max = 0;
    for (int v = 0; v < V; v++)
      if (degree(v) > max)
         max = degree(v);    

    return max;   
  }

  int avr_degree()
  {
	return 2 * E / V;   
  }

  int number_of_self_loops()
  {
	int count = 0;
	for (int v = 0; v < V; v++)
	  for ( int w : adj[v])
	    if (v == w)
	      count++;
    return count / 2;       
  }
  void to_string()
  {
    std::string s ("Vertex: ");
    s+= std::to_string(V);
    s+=", Edges: "; 
    s+= std::to_string(E);
    s+="\n";
    for (int v = 0; v < V; v++)
    {
	  s+= std::to_string(v) + ": ";
	  for ( int w : adj[v])
        s+= std::to_string(w) + " ";
      s+="\n";  	   	
    }
    std::cout<<s;
  }
};



class DepthFirstPaths
{
  std::vector<bool> marked;
  std::vector<int> edgeTo;
  int S;

  void dfs(Graph G, int v)
  {
    marked[v] = true;
    for (int w : G.adj[v])
      if (!marked[w])
      {
        edgeTo[w] = v;
        dfs(G,w);
      }
  }

public:
  DepthFirstPaths(Graph G, int s)
  {
    marked.resize(G.V);
    edgeTo.resize(G.V);
    S = s;
    dfs(G,S);
  }

  bool hasPathTo(int v)
  {
    if (marked[v])
      std::cout<<std::endl<<S<<" is connected with "<<v<<std::endl;
    else
      std::cout<<std::endl<<S<<" is not connected with "<<v<<std::endl;
    return marked[v];
  }

};


class BreadthFirstPaths
{
  std::vector<bool> marked;
  std::vector<int> edgeTo;
  int S;

  void bfs(Graph G, int s)
  {
    std::queue<int> queue;
    marked[s] = true;
    queue.push(s);
    while (!queue.empty())
    {
      int v = queue.front();
      queue.pop();
  
      for (int w : G.adj[v])
        if (!marked[w])
        {
          edgeTo[w] = v;
          marked[w] = true;
          queue.push(w);
        }

    }
  }

public:
  BreadthFirstPaths(Graph G, int s)
  {
    marked.resize(G.V);
    edgeTo.resize(G.V);
    S = s;
    bfs(G,S);
  }

  bool hasPathTo(int v)
  {
    if (marked[v])
      std::cout<<std::endl<<S<<" is connected with "<<v<<std::endl;
    else
      std::cout<<std::endl<<S<<" is not connected with "<<v<<std::endl;
    return marked[v];
  }

};


class Digraph
{
public:
  std::vector<std::vector<int> > adj;

  int V;
  int E = 0;
  Digraph(std::string file)
  {
    std::ifstream f;
    f.open(file.c_str());
    int e;
    f >> V; 
  
    adj.resize(V);
    
    f >> e; 
 
    for (int i = 0; i < e; i++)
    {
      int v,w;
      f >> v;
      f >> w;
      addEdge(v,w);
    }
    
    f.close();
    std::cout<<"GRAPH:   V = "<<V<<"   E = "<<E<<std::endl;
  }

  void addEdge(int v, int w)
  {
    adj.at(v).push_back(w);
    E++;
  }
  void to_string()
  {
    std::string s ("Vertex: ");
    s+= std::to_string(V);
    s+=", Edges: "; 
    s+= std::to_string(E);
    s+="\n";
    for (int v = 0; v < V; v++)
    {
	  s+= std::to_string(v) + ": ";
	  for ( int w : adj[v])
        s+= std::to_string(w) + " ";
      s+="\n";  	   	
    }
    std::cout<<s;
  }

};


class DirectDFS
{
public:
  std::vector<bool> marked;

  void dfs(Digraph G, int v)
  {
    marked[v] = true;
    for (int w : G.adj[v])
      if (!marked[w])
        dfs(G,w);
  }

  DirectDFS(Digraph G, int s)
  {
    marked.resize(G.V);
    dfs(G,s);
  }

 
};

class DirectedCycle
{
public:
  std::vector<bool> marked;
  std::vector<int> edgeTo;
  std::stack<int> cycle;
  std::vector<bool> onStack;

  void dfs(Digraph G, int v)
  {
    onStack[v] = true;
    marked[v] = true;
    for (int w : G.adj[v])
    {
      if (!cycle.empty())
        return;
      else if (!marked[w])
      {
        edgeTo[w] = v;
        dfs(G,w);
      }
      else if (onStack[w])
      {
        cycle = std::stack<int>();
        for (int x = v; x != w; x = edgeTo[x])
          cycle.push(x);
        cycle.push(w);
        cycle.push(v);
      }
     
    }
    onStack[v] = false;
  }

  DirectedCycle(Digraph G)
  {
    marked.resize(G.V);
    edgeTo.resize(G.V);
    onStack.resize(G.V);
    for (int v = 0; v < G.V; v++)
     if (!marked[v])
       dfs(G,v);
  }
  
  bool hasCycle()
  {
    return cycle.size() != 0;
  }
  
};


class DepthFirstOrder
{
public:
  std::vector<bool> marked;
  std::queue<int> pre;
  std::queue<int> post;
  std::stack<int> reversePost;
  
  void dfs(Digraph G, int v)
  {
    pre.push(v);
    marked[v] = true;
    for (int w : G.adj[v])
      if(!marked[w])
        dfs(G, w);
    post.push(v);
    reversePost.push(v);

  }

  DepthFirstOrder(Digraph G)
  {
    marked.resize(G.V);
    for (int v = 0; v < G.V; v++)
      if (!marked[v])
        dfs(G, v);
  }
};

class Topological
{
public:
  std::vector<int> order;
  Topological(Digraph G)
  {
    DirectedCycle cyclefinder(G);
    if (!cyclefinder.hasCycle())
    {
      DepthFirstOrder dfs(G);
      int* end = &dfs.reversePost.top() + 1;
      int * begin  = end - dfs.reversePost.size(); 
      order = std::vector<int>  (begin,end);
    }
  }  
  
  bool isDAG()
  {
    return order.size() == 0;
  }

};

class KosarajuSCC
{
  std::vector<bool> marked;  
  std::vector<int> id;
  int count;

  void dfs(Digraph G, int v)
  {
    marked[v] = true;
    id[v] = count;
    for (int w : G.adj[v])
      if(!marked[w])
        dfs(G, w);
  }

public:
  KosarajuSCC(Digraph G)
  {
    count = 0;
    marked.resize(G.V);
    id.resize(G.V);
    DepthFirstOrder d(G);
    int* end = &d.reversePost.top() + 1;
    int * begin  = end - d.reversePost.size(); 
    std::vector<int> order(begin,end);
    for (int s : order)
      if (!marked[s])
      {
        dfs(G,s);
        count++;
      }
  }

};

/*
int main()
{
  Graph graph("data.txt");
  graph.to_string();
  std::cout<<"ADJ 6, degree: "<<graph.degree(6)<<" Max degree: "<< graph.max_degree()<< " Avr degree: "<<   graph.avr_degree()<<" Number of self loops "<<graph.number_of_self_loops();
 
  DepthFirstPaths dfp(graph,0);
  dfp.hasPathTo(10); 
  dfp.hasPathTo(4); 

  BreadthFirstPaths bfp(graph,0);
  bfp.hasPathTo(10); 
  bfp.hasPathTo(4); 


  Digraph di("data_2.txt");
  di.to_string();

  DirectDFS ddfs(di,3);
  std::cout<<std::endl<<"Vortex 3 can reach: "<<std::endl; 
  for (int i = 0; i < di.V; i++)
  {
    if (ddfs.marked[i])
    std::cout<<" "<<i;    
  }

  DirectedCycle dc(di);

  Digraph dia("data_3.txt");

  Topological top(dia);

  std::cout<<std::endl<<"TOPOLOGY "<<std::endl; 
  for (int i : top.order)
    std::cout<<" "<<i<<std::endl;    



  return 0;
}
*/
