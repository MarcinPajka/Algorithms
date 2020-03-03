#include<vector>
#include<iostream>
#include<string>
#include<fstream>

class Graph
{
  int V;
  int E = 0;
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

int main()
{
  Graph graph("data.txt");
  graph.to_string();
  std::cout<<"ADJ 6, degree: "<<graph.degree(6)<<" Max degree: "<< graph.max_degree()<< " Avr degree: "<< graph.avr_degree()<<" Number of self loops "<<graph.number_of_self_loops();
  return 0;
}
