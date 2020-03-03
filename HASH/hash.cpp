#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <vector>

class SeprateChainingHashST
{
  int N;
  int M;	
  std::vector<std::map<std::string,double> > st;
  
  int  hash(std::string key)
  {
    std::hash<std::string> h;
    return (int(h(key)) & 0x7fffffff) % M ;	
  }
public:
  double get(std::string key)
  {
	return (double)  st[hash(key)][key];  
  }
  
  void put(std::string key, double val)
  {
    st[hash(key)].insert(std::pair<std::string,double>(key,val));
  }
  
  SeprateChainingHashST(int m)
  {
    M = m;
    st.resize(M);
  }

};

class LinearProbingHashST
{
  int N;
  int M;	
  std::vector<std::string> keys;
  std::vector<double> vals;
  
  int  hash(std::string key)
  {
    std::hash<std::string> h;
    return (int(h(key)) & 0x7fffffff) % M ;	
  }
  
  void resize(int cap)
  {
    LinearProbingHashST t(cap);
    for (int i = 0; i < M;i++)
	  if (!keys[i].empty())
	    t.put(keys[i],vals[i]);
    keys = t.keys;
    vals = t.vals;
    M = t.M;
  }
public:
  double get(std::string key)
  {
	int i;
    for (i = hash(key); !keys[i].empty(); i = (i + 1) % M)
      if (keys[i] == key)
        return vals[i];    
  }7
  void put(std::string key, double val)
  {
	if (N >= M / 2)
	  resize(2 * M);
    int i;
	for (i = hash(key); !keys[i].empty(); i = (i + 1) % M)
	  if (keys[i] == key) 
	  {
        vals[i] = val;
        return;
      }
    keys[i] = key;
    vals[i] = val;
    N++;
	  
  }
 
  LinearProbingHashST(int m)
  {
	N = 0;
	M = m;
	keys.resize(M);
	vals.resize(M);
  }

};



int main()
{
  SeprateChainingHashST st(12);
  st.put("s",0);
  st.put("e",1);
  st.put("a",2);
  st.put("r",3);
  st.put("c",4);
  st.put("h",5);
  st.put("e",6);
  st.put("x",7);
  st.put("a",8);
  st.put("m",9);
  st.put("p",10);
  st.put("l",11);
  st.put("e",12);
    
  std::cout<<st.get("a");  

  LinearProbingHashST sta(12);
  sta.put("s",0);
  sta.put("e",1);
  sta.put("a",2);
  sta.put("r",3);
  sta.put("c",4);
  sta.put("h",5);
  sta.put("e",6);
  sta.put("x",7);
  sta.put("a",8);
  sta.put("m",9);
  sta.put("p",10);
  sta.put("l",11);
  sta.put("e",12);
    
  std::cout<<sta.get("a");  

  return 0;
}
