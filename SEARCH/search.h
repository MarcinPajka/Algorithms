#include<vector>

template<class Key, class Val>
class BinarySearch 
{
  std::vector<Key> keys;
  std::vector<Val> vals;
  int N;


  public:

  int size();
  Val get(Key key);
  int rank(T key);
  void put(Key key, Val val);
}
