#include<iostream>
#include<vector>
#include<cstdlib>
#include<chrono>
#include<string>

#define DEBUG 0

using namespace std;
void gen_data(int N, int * table)
{

  for (int i = 0; i < N ; i+=2)
  {
      table[i] = rand()% (N/2 - 1);
      table[i+1] = rand()% N/2;
      while (table[i] == table [i+1])
      {
        table[i] = rand()% N/2;
        table[i+1] = rand()% N/2;
      }
   #if DEBUG
    cout<<table[i]<<"  "<<table[i+1] <<endl;
   #endif
  }
}

class UF
{
  string name;
  protected:
  vector<int> id;
  int _count;
  
  public:
  UF(){}; 
  UF(int N,string uf_name)
  {
    string name(uf_name);
    cout<<endl<<name<<endl; 
    _count = N;
    id = vector<int>(N);
    for (int i = 0; i < N; i++)
      id[i] = i;
  }

  int count(void)
  {
    return _count;
  }
  bool connected(int p, int q)
  {
    return find(p) == find(q);
  }
  int find(int p)
  {
    return id[p];
  }
  void uf_union(int p, int q)
  {
    int pID = find(p);
    int qID = find(q);

    if (pID == qID)
      return;
   
    for (int i = 0; i < id.size(); i++)
      if (id[i] == pID)
        id[i] = qID;
 
    _count--;
  }

  void solve_UF(int * table)
  {
   chrono::time_point<chrono::system_clock> start, end;
   start = chrono::system_clock::now();  
 
    for (int i = 0; i < 2* id.size(); i+=2)
    {
      int p = table[i];
      int q= table[i+1];
      if (connected(p, q))
        continue;
      uf_union(p, q);  
    }
   end = chrono::system_clock::now();    
   chrono::duration<double> milliseconds = end - start; 

   cout<<"Time: "<< milliseconds.count() <<endl;
   #if DEBUG
   for (int i = 0; i <  id.size(); i++)
     cout<<i<<"  "<<id[i]<<endl;
       cout<<"counter:"<<_count<<endl;
   #endif
  } 
};

class UF_fast_union : public UF
{
  string name;
  public:
  UF_fast_union(int N,string uf_name)
  {
    string name(uf_name);
    cout<<endl<<name<<endl;
    _count = N;
    id = vector<int>(N);
    for (int i = 0; i < N; i++)
      id[i] = i;
  }
  int find(int p)
  {
    while (p != id[p])
      p = id[p];
    return p;
  }
  
  void uf_union(int p, int q)
  {
    int pRoot = find(p);
    int qRoot = find(q);
    if (pRoot == qRoot)
      return;
    id[pRoot] = qRoot;
    _count--;
  }

void solve_UF(int * table)
  {
   chrono::time_point<chrono::system_clock> start, end;
   start = chrono::system_clock::now();  
 
    for (int i = 0; i < 2* id.size(); i+=2)
    {
      int p = table[i];
      int q= table[i+1];
      if (connected(p, q))
        continue;
      uf_union(p, q);  
    }
   end = chrono::system_clock::now();    
   chrono::duration<double> milliseconds = end - start; 

   cout<<"Time: "<< milliseconds.count() <<endl;
   #if DEBUG
   for (int i = 0; i <  id.size(); i++)
     cout<<i<<"  "<<id[i]<<endl;
       cout<<"counter:"<<_count<<endl;
   #endif
  } 


};

class UF_weight_fast_union : public UF
{
  string name;
  vector<int> sz;
  public:
  UF_weight_fast_union(int N,string uf_name)
  {
    string name(uf_name);
    cout<<endl<<name<<endl;
    _count = N;
    id = vector<int>(N);
    sz = vector<int>(N);
    for (int i = 0; i < N; i++)
    {  
      id[i] = i;
      sz[i] = 1;
    }
  }

  int find(int p)
  {
    while (p != id[p])
      p = id[p];
    return p;
  }
  
  void uf_union(int p, int q)
  {
    int i = find(p);
    int j = find(q);
    if (i == j)
      return;
    if (sz[i] < sz[j])
    {
      id[i] = j; 
      sz[j] += sz[i];
    }
    else
    {
      id[j] = i; 
      sz[i] += sz[j];
    }
    _count--;
  }
void solve_UF(int * table)
  {
   chrono::time_point<chrono::system_clock> start, end;
   start = chrono::system_clock::now();  
 
    for (int i = 0; i < 2* id.size(); i+=2)
    {
      int p = table[i];
      int q= table[i+1];
      if (connected(p, q))
        continue;
      uf_union(p, q);  
    }
   end = chrono::system_clock::now();    
   chrono::duration<double> milliseconds = end - start; 

   cout<<"Time: "<< milliseconds.count() <<endl;
   #if DEBUG
   for (int i = 0; i <  id.size(); i++)
     cout<<i<<"  "<<id[i]<<endl;
       cout<<"counter:"<<_count<<endl;
   #endif
  } 

};


int main()
{
  srand(time(NULL));
  int N = 10000;
  int table[2*N];
  gen_data(2*N,table); 
  string name_1("UF_fast_find");
  string name_2("UF_fast_union");
  string name_3("UF_weight_fast_union");

  UF uf(N,name_1);
  uf.solve_UF(table);
  gen_data(2*N,table);

  UF_fast_union uf_fu(N,name_2); 
  uf_fu.solve_UF(table);
  gen_data(2*N,table);

  UF_weight_fast_union uf_fu_w(N,name_3);
  uf_fu_w.solve_UF(table);
}

	
