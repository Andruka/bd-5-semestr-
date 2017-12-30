#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <ctime>
using namespace std;
class Generator{
    class Cat{
      public:
        char name[64];
	char breed[64];
        char age;
        char gender;
        Cat(string n,string b,int a,char g);
        void print(ofstream & fout);
    };
    vector<string>vF,vM,vB;
  public:
    bool check(ifstream & fin,vector<string> & v);
    bool work(int quantity,int max_age);
};
