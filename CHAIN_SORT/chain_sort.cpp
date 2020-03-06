#include<vector>
#include<iostream>
#include<string>
#include<fstream>
#include<queue>
#include<stack>

class LSD
{
public:
  std::vector<std::string> a;
  void sort(int W)
  {
    int N = a.size();
    int R = 58;
    std::vector<std::string> aux;
    aux.resize(N);


    for (int d = W - 1; d >= 0; d--)
    {
      std::cout<<d<<std::endl; 
      
      std::vector<int> count(R+1);

      for (int i = 0; i < N; i++)
        count.at(a[i][d] + 1)++;

      for (int r = 0; r < R; r++)
        count.at(r+1) += count.at(r);

      for (int i = 0; i < N; i++)
        aux[count.at(a.at(i)[d] )++] = a[i];

      for (int i = 0; i < N; i++)
        a.at(i) = aux.at(i);
    }
  for (auto i : a)
    std::cout<<i<<std::endl; 
  }
};

 
int main()
{
  std::vector<std::string> a{"423456","222222","333531","123496","911111","909999"};
  LSD lsd;
  lsd.a = a;
  lsd.sort(6);


  return 0;
}
