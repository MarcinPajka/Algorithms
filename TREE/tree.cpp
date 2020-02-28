#include "search.h"
template<class Key, class Val>
Node<Key,Val>::Node(Key key, Val val, int N)
{
  this.key = key;
  this.val = val;
  this.N = N;
}

template<class Key, class Val>
int BST<Key, Val>::size()
{
  return size(root);
}

template<class Key, class Val>
int BST<Key, Val>::size(Node x)
{
  if (x == NULL)
    return 0;
  else
    return x.N;
}

template<class Key, class Val>
int BST<Key, Val>::get(Key key)
{
  return get(root,key);
}

template<class Key, class Val>
Val BST<Key, Val>::get(Node x, Key key)
{
  if( x == NULL)
    return;
  if (key < x.key)
    return get(x->left,key);
  else if (key > x.key)
    return get(x->right,key);
  else
    return x.val;
}

template<class Key, class Val>
int BST<Key, Val>::put(Key key, Val val)
{
  root = put(root,key,val);
}

template<class Key, class Val>
Node BST<Key, Val>::put(Node x,Key key, Val val);
{
  if (x == NULL)
    return  new Node(key,val,1);
  if (key < x.key)
    x.left = put(x->left,key,val);
  else if (key > x.key)
    x.right = put(x->right,key,val);
  else
     x.val = val;
  x.N = size(x.left) + size(x.right) + 1;
  return x;
  
}
