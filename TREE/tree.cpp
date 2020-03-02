#include<iostream>
#define COUNT 10
#define RED true
#define BLACK false

class BST
{
  struct node
  {
    int data;
    node* left;
    node* right;
    bool color;
  };
  
  node* root;

  node* makeEmpty(node* t)
  {
    if (t == NULL)
      return NULL;
  
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
    return NULL;
  }

  node* insert(int x, node* t)
  {
    if (t == NULL)
    {
      t = new node;
      t->data = x;
      t->left = t->right = NULL;
      t->color = RED;
    }
    else if (x < t->data)
    {
      t->left  = insert(x, t->left);      
    }
    else if (x > t->data)
    {
      t->right  = insert(x, t->right);      
    }

    if (isRed(t->right) && !isRed(t->left) )
      t = rotateLeft(t);
    if (isRed(t->left) && isRed(t->left->left))
      t = rotateRight(t);
    if (isRed(t->left) && isRed(t->right) )
      flipColors(t);  
    return t;
  }

  node* findMin(node* t)
  {
    if (t == NULL)
      return NULL;
    else if (t->left == NULL)
      return NULL;
    else
      return findMin(t->left);
  }

  node* findMax(node* t)
  {
    if (t == NULL)
      return NULL;
    else if (t->right == NULL)
      return NULL;
    else
      return findMin(t->right);
  }

  node* remove(int x, node* t)
  {
    node* tmp;
    if (t == NULL)
      return NULL;
    else if (x < t->data)
      t->left = remove(x, t->left);  
    else if (x > t->data)
      t->right = remove(x, t->right);  
    else if (t->left && t->right)
    {
      tmp = findMin(t->right);
      t->data = tmp->data;
      t->right = remove(t->data, t->right);
    }
    else
    {
      tmp = t;
      if (t->left == NULL)
        t = t->right;
      else if (t->right == NULL)
        t = t->left;
      delete tmp;
    }
    return t;
  }

  void inorder(node* t, int space)
  {
    if (t == NULL)
      return;

    space += COUNT;
    inorder(t->right, space);

    std::cout<<std::endl;
    for (int i = COUNT; i < space; i++)
      std::cout<<" ";
    std::cout<<t->data<<" ("<<t->color<<")\n";
    inorder(t->left, space);
  }

  node* find(node* t, int x)
  {
    if (t == NULL)
      return NULL;
    else if( x < t->data)
      return find(t->left, x);
    else if( x > t->data)
      return find(t->right, x);
    else
      return t;
  }

  bool isRed(node* t)
  {
    if (t == NULL)
      return BLACK; 
    return t->color == RED; 
  } 
  
  node* rotateLeft(node* t)
  {
    node * x = t->right;
    t->right = x->left;
    x->left = t;
    x->color = t->color;
    t->color = RED;
    return x;
  }

  node* rotateRight(node* t)
  {
    node * x = t->left;
    t->left = x->right;
    x->right = t;
    x->color = t->color;
    t->color = RED;
    return x;
  }

  void flipColors(node* t)
  {
    t->color = RED;
    t->left->color = BLACK;
    t->right->color = BLACK;
  }

public:
  BST()
  {
    root = NULL;
  }
  ~BST()
  {
    root = makeEmpty(root);
  }

  void insert(int x)
  {
    root = insert(x, root);
    root->color = BLACK;
  }
 
  void remove(int x)
  {
   root = insert(x, root);
  }  
  void display()
  {
    inorder(root,0);
  }

  void search(int x)
  {
    root = find(root, x);
  }
};

int main()
{
  BST t;

  t.insert(1);
  t.insert(3);
  t.insert(5);
  t.insert(8);
  t.insert(12);
  t.insert(13);
  t.insert(15);
  t.insert(16);
  t.insert(17);
  t.insert(20);
  t.display();

}
