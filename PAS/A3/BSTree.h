#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
  int value;       // value of each node
  Node *left;      // pointer to left
  Node *right;     // pointer to right
  int search_time; // search time of each node

  // Node constructor
  Node(int val = 0, Node *l = nullptr, Node *r = nullptr)
      : value(val), left(l), right(r), search_time(0) {}
};

struct BSTree
{
public:
  // constructors
  BSTree() : size(0), root(nullptr) {}
  // copy constructor
  BSTree(const BSTree &other);
  // move constructor
  BSTree(BSTree &&other);
  // copy assignment
  BSTree &operator=(const BSTree &other);
  // move assignment
  BSTree operator=(BSTree &&other);
  ~BSTree();
  // returns root
  const Node *get_root() const { return root; }
  // return size
  const int get_size() const { return size; }
  // returns a node to be inserted
  Node *insert(int obj);
  // returns a node that has been searched
  Node *search(int obj);
  // updates search times
  void update_search_times();
  // returns the average search time
  float get_average_search_time();
  // prints in order
  ostream &inorder(ostream &out);
  // prints level by level
  ostream &print_level_by_level(ostream &out);
  // prints in pretty mode
  void pretty_print_node(ostream &out, Node *node);
  // returns summing search times from each node
  int get_total_search_time(Node *node);

private:
  int size;   // size of the binary tree (number of nodes)
  Node *root; // root of each binary tree
  int count;  //for comparisions.

  //<-----HELPER FUNCTIONS----->
  void printInorder(BSTree &tree);
  void copy_helper(Node *copy_to, const Node *copy_from) const;
  Node *insertHelper(Node *node, int obj);
  void inorderHelp(Node *node, ostream &out);
  void updateHelper(Node *node);
  Node *searchHelper(Node *node, int obj);
  Node *deleting(Node *node);
  //<-----HELPER FUNCTIONS END----->
};

// print a BSTree
ostream &operator<<(ostream &out, BSTree &tree);

// print a node
ostream &operator<<(ostream &out, Node node);

// read in a tree from a file
istream &operator>>(istream &in, BSTree &tree);

#endif
