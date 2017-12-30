#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Cats.h"
using namespace std;
class Dateaccess{
    Cat cat;
    char fn[20];
    void merge();    
  public:
    Cat get_cat (int index);
    int start(const char * filename);
    int* search();
    void del_cat();
    void add_cat();
};
