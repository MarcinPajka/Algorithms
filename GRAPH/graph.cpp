#include<vector>
#include<iostream>
#include<string>
#include<fstream>

class Graph
{
  int V;
  int E;
  std::vector<std::vector<int> > adj;

public:
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

};

int main()
{
  Graph graph("data.txt");
  graph.adj_v(0);

  return 0;
}
