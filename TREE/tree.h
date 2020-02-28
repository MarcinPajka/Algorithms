#include<vector>
template<class Key, class Val>
class Node
{
  Key key;
  Val val;
  Node * left, right;
  int N;
}


template<class Key, class Val>
class BST
{
  Node<Key,Val> root;
  int size(Node x);
  Val get(Node x, Key key);
  Node put(Node x,Key key, Val val);
  public:
  int size();
  Val get(Key key);
  void put(Key key, Val val);
}
