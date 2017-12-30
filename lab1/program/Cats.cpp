#include "Cats.h"
Cat::Cat(){
    for(int i=0;i<64;++i){
        name[i]='\0';
        breed[i]='\0';
        }
    age=0;
    gender='\0';
}
Cat::Cat(char* n,char* b,int a,char g){
    strcpy(name,n);
    strcpy(breed,b);
    age=(char)a;
    gender=g;
}
Cat& Cat::operator = (const Cat& cat) {
        if (this == &cat) {
            return *this;
        }
    	strcpy(name,cat.name);
    	strcpy(breed,cat.breed);
    	age=cat.age;
    	gender=cat.gender;
        return *this;
}
ostream & operator << (ostream & stream, const Cat & cat) {
    stream.write(cat.name , 64);
    stream.write(cat.breed , 64);
    stream.put(cat.age);
    stream.put(cat.gender);
    return stream;
}
istream & operator >> (istream & stream, Cat & cat){
    stream.read(cat.name , 64);
    stream.read(cat.breed , 64);
    stream.get(cat.age);
    stream.get(cat.gender);
    return stream;
}
void Cat::print(){
    cout<<"Имя: "<<name<<endl;
    cout<<"Порода: "<<breed<<endl;
    cout<<"Возраст: "<<(int)age<<endl;
    cout<<"Пол: "<<gender<<endl<<endl;
}
int compare(Cat cat1,Cat cat2,int type){
    if(type==1)return strcmp(cat1.name,cat2.name);
    if(type==2)return strcmp(cat1.breed,cat2.breed);
    if(type==3){
	if(cat1.age<cat2.age)return -1;
	if(cat1.age=cat2.age)return 0;
	if(cat1.age>cat2.age)return 1;
	}
}
