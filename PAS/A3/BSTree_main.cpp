#include <iostream>
#include <fstream>
#include <sstream> //only thing I added
#include "BSTree.h"
using namespace std;

BSTree read_file(string file_name)
{
     BSTree new_tree;
     ifstream infile(file_name);
     infile >> new_tree;
     return new_tree;
}

int main()
{
     cout << "////////////////////////////////////////////////////////" << endl
          << endl;

     cout << "PRINTING TREE ONE \n";
     BSTree amazingTree = read_file("data-files/4p"); //constructing a test tree.
     cout << amazingTree << endl;

     cout << "////////////////////////////////////////////////////////" << endl
          << endl;

     cout << "SEARCHING TEST" << endl;
     int search = 68;
     cout << "Searching for: " << search << endl;
     Node *n = amazingTree.search(search); //return a node if certain node is found
     if (n == nullptr)
     {
          cout << "Did not find the node in the tree" << endl
               << endl;
     }
     else
     {
          cout << "Found! It is: " << *n << endl
               << endl;
     }
     cout << "////////////////////////////////////////////////////////" << endl
          << endl;

     cout << "UPDATE SEARCH TIMES" << endl;
     amazingTree.update_search_times();
     cout << amazingTree << endl;

     cout << "////////////////////////////////////////////////////////" << endl
          << endl;

     cout << "Testing COPY CONSTRUCTOR" << endl;
     cout << "/// Printing Tree 1 ///" << endl;
     BSTree tree1(amazingTree);
     cout << tree1 << endl;

     cout << "////////////////////////////////////////////////////////" << endl
          << endl;

     cout << "TESTING COPY ASSIGNMENT" << endl;
     cout << "/// Printing Tree 2 ///" << endl;
     BSTree tree2;
     tree2 = amazingTree;
     cout << tree2 << endl;

     cout << "////////////////////////////////////////////////////////" << endl
          << endl;

     cout << "TESTING MOVE CONSTRUCTOR" << endl;
     cout << "/// Printing Tree 3 ///" << endl;
     BSTree tree3(move(tree1));
     cout << tree3 << endl;

     cout << "////////////////////////////////////////////////////////" << endl
          << endl;

     cout << "TESTING MOVE ASSIGNMENT" << endl;
     cout << "/// Printing Tree 4 ///" << endl;
     BSTree tree4;
     tree4 = move(tree2);
     cout << tree4 << endl;

     cout << "<------////////////////////////////////////////////////////////------>" << endl;
     cout << "//// APPLICATION ////" << endl; //PART TWO OF THE ASSIGNMENT

     for (int i = 1; i <= 12; i++)
     {
          cout << "////////////////////////////////////////////////////////////////" << endl
               << endl;
          string dir = "data-files/" + std::to_string(i);
          BSTree l = read_file(dir + "l");
          cout << "[" << i << "] Total number of nodes: " << l.get_size() << endl;
          cout << "Average search time linear " << i << "l: "
               << l.get_average_search_time() << endl;
          BSTree p = read_file(dir + "p");
          cout << "Average search time perfect " << i << "p: "
               << p.get_average_search_time() << endl;
          BSTree r = read_file(dir + "r");
          cout << "Average search time random " << i << "r: "
               << r.get_average_search_time() << endl
               << endl;

          if (i <= 4)
          {
               cout << "<---PERFECT Tree name--->: " << i << "p" << endl;
               cout << p << endl;

               cout << "<---LINEAR Tree name--->: " << i << "l" << endl;
               cout << l << endl;

               cout << "<---RANDOM Tree name--->: " << i << "r" << endl;
               cout << r << endl;
          }
     }

     // FOR PRINTING IN FILES
     for (int i = 1; i <= 12; i++)
     {
          string dir = "data-files/" + std::to_string(i);

          //LINEAR
          BSTree l = read_file(dir + "l");
          string name = "output/" + to_string(i) + "l"; // PRINT IN THE OUTPUT FOLDER
          ofstream outfilel(name);
          outfilel << "<---LINEAR TREE " << i << "--->" << endl;
          outfilel << "Average search time: " << l.get_average_search_time() << endl;
          outfilel << "Total number of nodes: " << l.get_size() << endl;
          outfilel << l;
          outfilel.close();

          //PERFECT
          BSTree p = read_file(dir + "p");
          name = "output/" + to_string(i) + "p"; // PRINT IN THE OUTPUT FOLDER
          ofstream outfilep(name);
          outfilep << "<---PERFECT TREE " << i << "--->" << endl;
          outfilep << "Average search time: " << p.get_average_search_time() << endl;
          outfilep << "Total number of nodes: " << p.get_size() << endl;
          outfilep << p;
          outfilep.close();

          //RANDOM
          BSTree r = read_file(dir + "r");
          name = "output/" + to_string(i) + "r"; // PRINT IN THE OUTPUT FOLDER
          ofstream outfiler(name);
          outfiler << "<---RANDOM TREE " << i << "--->" << endl;
          outfiler << "Average search time: " << r.get_average_search_time() << endl;
          outfiler << "Total number of nodes: " << r.get_size() << endl;
          outfiler << r;
          outfiler.close();
     }
}
