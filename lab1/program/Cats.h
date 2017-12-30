#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#define CAT_SIZE 130

using namespace std;
class Cat{
    char name[64];
    char breed[64];
    char age;
    char gender;
  public:
    Cat();
    Cat(char* n,char* b,int a,char g);
    void print();
    Cat& operator = (const Cat& cat);
    friend ostream & operator << (ostream & stream, const Cat& cat);
    friend istream & operator >> (istream & stream, Cat& cat);
    friend int compare(Cat cat1,Cat cat2,int type);
};


