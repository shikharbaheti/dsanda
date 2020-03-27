#include "BSTree.h"

// input / output operators
ostream &operator<<(ostream &out, BSTree &tree)
{
  if (tree.get_size() <= 16)
  {
    out << "/// --- Level by Level --- ///" << endl;
    tree.print_level_by_level(out) << endl;
    out << "/// --- IN ORDER --- ///" << endl;
    tree.inorder(out) << endl;
  }
  else
  {
    out << "/// --- IN ORDER --- ///" << endl;
    tree.inorder(out) << endl;
  }
  return out;
}

ostream &operator<<(ostream &out, Node node)
{
  return out << "( " << node.value << ", "
             << node.search_time << " )";
}

istream &operator>>(istream &in, BSTree &tree)
{
  int next;
  while (in >> next)
    tree.insert(next);
  return in;
}

///////////// Implementation To Do ////////////////////

// copy constructor
BSTree::BSTree(const BSTree &other)
{
  size = other.size;
  if (other.root == nullptr)
  {
    root = nullptr;
  }
  else
  {
    root = new Node(*other.root);
    copy_helper(root, other.root);
  }
};

// move constructor
BSTree::BSTree(BSTree &&other)
{
  this->size = other.size;
  this->root = other.root;

  // delete other
  other.size = 0;
  other.root = nullptr;
};

//copy assignment
BSTree &BSTree::operator=(const BSTree &other)
{
  if (this != &other)
  {
    size = other.size;
    if (other.root == nullptr)
    {
      root = nullptr;
    }
    else
    {
      root = new Node(*other.root);
      copy_helper(root, other.root);
    }
  }
  return *this;
};

// move assignment
BSTree BSTree::operator=(BSTree &&other)
{
  if (this != &other)
  {
    this->size = other.size;
    this->root = other.root;

    // delete other
    other.size = 0;
    other.root = nullptr;
  }
  return *this;
};

//HELPER FOR DESTRUCTOR
Node *BSTree::deleting(Node *node)
{
  if (node == NULL)
    return NULL;
  {
    deleting(node->left);
    deleting(node->right);
    delete node;
    node = nullptr;
  }
  return NULL;
}

// destructor
BSTree::~BSTree()
{
  deleting(root);
  root = nullptr;
};

// recursive
void BSTree::copy_helper(Node *copy_to,
                         const Node *copy_from) const
{
  if (copy_from == nullptr)
    return;
  if (copy_from->left != nullptr)
  {
    copy_to->left = new Node(*copy_from->left);
    copy_helper(copy_to->left, copy_from->left);
  }
  else
  {
    copy_to->left = nullptr;
  }

  if (copy_from->right != nullptr)
  {
    copy_to->right = new Node(*copy_from->right);
    copy_helper(copy_to->right, copy_from->right);
  }
  else
  {
    copy_to->right = nullptr;
  }
};

//helper
Node *BSTree::insertHelper(Node *node, int obj)
{
  count++;
  if (node->value < obj)
  {
    if (node->right == nullptr)
    {
      Node *newNode = new Node(obj);
      newNode->search_time = count;
      node->right = newNode;
      return newNode;
    }
    else
    {
      return insertHelper(node->right, obj);
    }
  }
  else
  {
    if (node->left == nullptr)
    {
      Node *newNode = new Node(obj);
      node->left = newNode;
      newNode->search_time = count;
      return newNode;
    }
    else
    {
      return insertHelper(node->left, obj);
    }
  }
};

Node *BSTree::insert(int obj)
{
  count = 1;
  size++;
  if (root == nullptr)
  {
    root = new Node(obj);
    root->search_time = count;
    return root;
  }
  else
  {

    return insertHelper(root, obj);
  }
};

Node *BSTree::searchHelper(Node *node, int obj)
{
  if (node->value == obj)
  {
    return node;
  }
  else if (obj > node->value && node->right != nullptr)
  {
    return searchHelper(node->right, obj);
  }
  else if (obj < node->value && node->left != nullptr)
  {
    return searchHelper(node->left, obj);
  }
  else
  {
    return nullptr;
  }
};

Node *BSTree::search(int obj)
{

  if (root == nullptr)
  {
    return NULL;
  }
  else
  {
    return searchHelper(root, obj);
  }
};

void BSTree::updateHelper(Node *node)
{
  if (node == nullptr)
  {
    return;
  }
  if (node->right != nullptr)
  {
    node->right->search_time = node->search_time + 1;
    updateHelper(node->right);
  }
  if (node->left != nullptr)
  {
    node->left->search_time = node->search_time + 1;
    updateHelper(node->left);
  }
}

void BSTree::update_search_times()
{
  root->search_time = 1;
  updateHelper(root);
};

void BSTree::inorderHelp(Node *node, ostream &out)
{
  if (node->left != nullptr)
  {
    inorderHelp(node->left, out);
  }
  out << node->value << "[" << node->search_time << "]"
      << " ";
  if (node->right != nullptr)
  {
    inorderHelp(node->right, out);
  }
};

ostream &BSTree::inorder(ostream &out)
{
  if (root != nullptr)
  {
    inorderHelp(root, out);
    out << endl;
  }

  return out;
};

// implemented
void BSTree::pretty_print_node(ostream &out, Node *node)
{
  out << node->value << "[" << node->search_time << "] ";
};

// implemented
ostream &BSTree::print_level_by_level(ostream &out)
{
  if (root == nullptr)
    return out;

  bool hasNodes = true;
  vector<Node *> current_level;
  vector<Node *> next_level;
  current_level.push_back(root);
  while (hasNodes)
  {
    hasNodes = false;
    for (auto node : current_level)
    {
      if (node != nullptr)
      {
        pretty_print_node(out, node);
        if (node->left != nullptr)
          hasNodes = true;
        if (node->right != nullptr)
          hasNodes = true;

        next_level.push_back(node->left);
        next_level.push_back(node->right);
      }
      else
      {
        out << "X ";
        next_level.push_back(nullptr);
        next_level.push_back(nullptr);
      }
    }
    out << endl;
    current_level.clear();
    current_level = next_level;
    next_level.clear();
  }

  return out;
};

// implemented
int BSTree::get_total_search_time(Node *node)
{
  if (node == nullptr)
    return 0;

  return get_total_search_time(node->left) +
         get_total_search_time(node->right) + node->search_time;
};

// implemented
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if (total_search_time == 0)
    return -1;

  return ((float)total_search_time) / size;
};