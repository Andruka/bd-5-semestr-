#include"Generator.h"
Generator::Cat::Cat(string n,string b,int a,char g){
    for(int i=0;i<64;++i){
	if(i<n.size())name[i]=tolower(n[i]);
        else name[i]='\0';
        }
    for(int i=0;i<64;++i){
	if(i<b.size())breed[i]=tolower(b[i]);
        else breed[i]='\0';
        }
    age=(char)a;
    gender=g;
}
void Generator::Cat::print(ofstream & fout){
    fout.write((char*)&name,64);
    fout.write((char*)&breed,64);
    fout<<age;
    fout<<gender;
}
bool Generator::check(ifstream & fin,vector<string> & v){
    string buf;
    if(fin.eof())return 1;
    while(true){
        getline(fin,buf);
	if(fin.eof())return 0;
	v.push_back(buf);
        }
}
bool Generator::work(int quantity,int max_age){
    char gender;
    ifstream fm("male.txt");
    ifstream ff("female.txt");
    ifstream fb("breed.txt");
    ofstream fr("../program/base");
    srand(time(0));
    cout<<"Идёт чтение файлов,ожидайте..."<<endl;
    if(check(fm,vM)){cout<<"Файл male.txt пуст! "<<endl;return 1;}
    if(check(ff,vF)){cout<<"Файл female.txt пуст! "<<endl;return 1;}
    if(check(fb,vB)){cout<<"Файл breed.txt пуст! "<<endl;return 1;}
    cout<<endl<<"Файлы считаны,идёт генерация базы котов,подождите ещё чуть чуть..."<<endl;
    for(int i=0;i<quantity;++i){
	if(rand() % 2)gender='m';
	else gender='f';
  	if(gender == 'm'){
	    Cat cat(vM[rand() % vM.size()],vB[rand() % vB.size()],rand() % max_age + 1,gender);
	    cat.print(fr);
	    }
	else{
	    Cat cat(vF[rand() % vF.size()],vB[rand() % vB.size()],rand() % max_age + 1,gender);
	    cat.print(fr);
	    }
        }
    return 0;
}
int main(int argc , char ** argv ){
    int quantity;
    int max_age;
    if(argc!=3)cout<<"Ошибка!"<<endl;
    quantity=atoi(argv[1]);
    max_age=atoi(argv[2]);
    Generator gen;
    if(gen.work(quantity,max_age)){cout<<"Какой-то входной файл оказался пустым"<<endl;return 1;}
    cout<<"База котов сгенерирована!"<<endl;
}
