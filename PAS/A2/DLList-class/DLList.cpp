// implementation of the DLList class
#include <stdexcept>
#include "DLList.h"
// extend runtime_error from <stdexcept>
struct EmptyDLList : public std::runtime_error
{
  explicit EmptyDLList(char const *msg = nullptr) : runtime_error(msg) {}
};

struct InvalidOperation : public std::runtime_error
{
  explicit InvalidOperation(char const *msg = nullptr) : runtime_error(msg) {}
};

// copy constructor
DLList::DLList(const DLList &dll)
{
  header.next = &trailer;
  trailer.prev = &header;

  DLListNode *node = dll.first_node();
  while (node != dll.after_last_node())
  {
    insert_last(node->obj);
    node = node->next;
  }
}
// move constructor
DLList::DLList(DLList &&dll)
{
  header.next = dll.header.next;
  trailer.prev = dll.trailer.prev;

  dll.header.next->prev = &header;
  trailer.prev->next = &trailer;

  dll.header.next = &dll.trailer;
  dll.trailer.prev = &dll.header;
}

// copy assignment operator
DLList &DLList::operator=(const DLList &dll)
{
  if (this != &dll)
  {
    if (!this->is_empty())
    {
      DLListNode *prev_node, *node = header.next;
      while (node != &trailer)
      {
        prev_node = node;
        node = node->next;
        delete prev_node;
      }
    }
    header.next = &trailer;
    trailer.prev = &header;

    DLListNode *node = dll.first_node();
    while (node != dll.after_last_node())
    {
      insert_last(node->obj);
      node = node->next;
    }
  }
  return *this;
}

// move assignment operator
DLList &DLList::operator=(DLList &&dll)
{
  if (this != &dll)
  {
    if (!this->is_empty())
    {
      DLListNode *prev_node, *node = header.next;
      while (node != &trailer)
      {
        prev_node = node;
        node = node->next;
        delete prev_node;
      }
      header.next = &trailer;
      trailer.prev = &header;
    }
    header.next = dll.header.next;
    trailer.prev = dll.trailer.prev;

    dll.header.next->prev = &header;
    trailer.prev->next = &trailer;

    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;
  }
  return *this;
}

// destructor
DLList::~DLList()
{
  DLListNode *prev_node, *node = header.next;
  while (node != &trailer)
  {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}

// insert a new object as the first one
void DLList::insert_first(int obj)
{
  DLListNode *newNode = new DLListNode(obj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
}

// insert a new object as the last one
void DLList::insert_last(int obj)
{
  DLListNode *newNode = new DLListNode(obj, trailer.prev, &trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}

// remove the first node from the list
int DLList::remove_first()
{
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List! Cannot remove things when list is empty!");
  DLListNode *node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  int obj = node->obj;
  delete node;
  return obj;
}

// remove the last node from the list
int DLList::remove_last()
{
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List!");
  DLListNode *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  int obj = node->obj;
  delete node;
  return obj;
}

// return the first object (do not remove)
int DLList::first() const
{
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List!");
  return header.next->obj;
}

// return the last object (do not remove)
int DLList::last() const
{
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List!");
  return trailer.prev->obj;
}

// insert a new node after the node p
void DLList::insert_after(DLListNode &p, int obj)
{
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List!");
  DLListNode *nodeToBeInserted = new DLListNode(obj, &p, p.next);
  p.next->prev = nodeToBeInserted;
  p.next = nodeToBeInserted;
}

// insert a new node before the node p
void DLList::insert_before(DLListNode &p, int obj)
{
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List!");
  DLListNode *nodeToBeInserted = new DLListNode(obj, p.prev, &p);
  p.prev->next = nodeToBeInserted;
  p.prev = nodeToBeInserted;
}

// remove the node after the node p
int DLList::remove_after(DLListNode &p)
{
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List!");
  if (&p == &trailer)
  {
    throw InvalidOperation("Cannot remove after trailer!");
  }
  DLListNode *temp = p.next;
  temp->next->prev = &p;
  p.next = temp->next;
  int valueHeld = temp->obj;
  delete temp;
  return valueHeld;
}

// remove the node before the node p
int DLList::remove_before(DLListNode &p)
{
  if (is_empty())
    throw EmptyDLList("Empty Doubly Linked List!");
  if (&p == &header)
  {
    throw InvalidOperation("Cannot remove before header!");
  }
  DLListNode *temp = p.prev;
  temp->prev->next = &p;
  p.prev = temp->prev;
  int valueHeld = temp->obj;
  delete temp;
  return valueHeld;
}

// output operator
ostream &operator<<(ostream &out, const DLList &dll)
{
  if (dll.is_empty())
  {
    throw EmptyDLList("Empty Doubly Linked List!");
  }
  DLListNode *node = dll.first_node();
  while (node != dll.after_last_node())
  {
    out << node->obj << " ";
    node = node->next;
  }
  return out;
}
