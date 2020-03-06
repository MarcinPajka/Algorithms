
#include "graph.cpp"

class Edge
{
protected:
  int V;
  int W;
  double Weight; 

public:
  Edge(int v,int w, double weight)
  {
    V = v;
    W = w;
    Weight = weight;
  }
  Edge(){};
  double weight()
  {
    return Weight;
  }

  int either()
  {
    return V;
  }

  int other(int vertex)
  {
    if (vertex == V)
      return W;
    else if (vertex == W)
      return V;
  }

  int compareTo(Edge* edge)
  {
    if (Weight < edge->weight() )
      return -1;
    else if (Weight > edge->weight() )
      return 1;
    else
      return 0;
  }
  void print(void)
  {
    std::cout<<std::endl<<V<<" "<<W<<" "<<Weight<<std::endl;
  }
  
};

class EdgeWeightGraph
{
  int V;

public:
  int E;
  std::vector<std::vector<Edge>> adj;

  EdgeWeightGraph(int v)
  {
    V = v;
    E = 0;
    adj.resize(V);
  }

  EdgeWeightGraph(std::string file)
  {
    std::ifstream f;
    f.open(file.c_str());
    int e;
    f >> V;     
    f >> e; 
    adj.resize(e);
    for (int i = 0; i < e; i++)
    {
      int v,w;
      double weight;
      f >> v;
      f >> w;
      f >> weight;
      Edge e(v,w,weight);
      addEdge(&e);
    }
    
    f.close();

  }

  void addEdge(Edge* e)
  {
    int v = e->either(); 
    int w = e->other(v);
    adj[v].push_back(Edge(v,w,e->weight()));
    adj[w].push_back(Edge(w,v,e->weight()));
    E++;    
  }

};

class DirectedEdge : public Edge
{
public:
  using Edge::Edge;
  int from()
  {
    return V;
  }
  int to()
  {
    return W;
  }
};

class EdgeWeightDigraph
{
public:
  int V;
  int E;
  std::vector<std::vector<Edge>> adj;

  EdgeWeightDigraph(int v)
  {
    V = v;
    E = 0;
    adj.resize(V);
  }

  EdgeWeightDigraph(std::string file)
  {
    std::ifstream f;
    f.open(file.c_str());
    int e;
    f >> V;     
    f >> e; 
    adj.resize(e);
    for (int i = 0; i < e; i++)
    {
      int v,w;
      double weight;
      f >> v;
      f >> w;
      f >> weight;
      DirectedEdge e(v,w,weight);
      addEdge(&e);
    }
    
    f.close();

  }

  void addEdge(DirectedEdge* e)
  {
    int v = e->from(); 
    int w = e->to();
    adj[v].push_back(DirectedEdge(v,w,e->weight()));
    E++;    
  }

};


int main()
{
  EdgeWeightGraph ewg("data_4.txt");
  std::cout<<std::endl<<"V W COST"<<std::endl;
  for (int i = 0; i < ewg.E; i++)
    for (auto j : ewg.adj[i])
      j.print();


  return 0;
}
