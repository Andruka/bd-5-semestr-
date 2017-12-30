#include "User.h"

int User::open(){
    int a=0;
    while(1){
    	cout<<"1-Использовать существующую базу"<<endl<<"2-Создать новую базу"<<endl<<"0-Выход из программы"<<endl;
    	cin>>a;
    	if(a==1){
	    cout<<"Введите имя файла: ";
	    cin>>fn;
    	    ob.start(fn);
    	    remove("1.txt");
    	    remove("3.txt");
    	    remove("4.txt");
    	    system("clear");
    	    cout<<"Коты отсортированы,программа готова к работе!"<<endl;
	    return 0;
	    }
        if(a==2){
	    cout<<"Введите имя файла: ";
	    cin>>fn;
	    cout<<"Создана новая пустая база!"<<endl;
	    return 0;
	    }
	if(a==0)return 1;
	}
    }
void User::show(int type){
    Cat temp;
    int end;
    int* diap=new int[2];
    ifstream in(fn);
    in.seekg(0,in.end);
    end=in.tellg()/CAT_SIZE;
    in.close();
    if(type==1){
        for(int i=0;i<end;++i){ 
	    cat=ob.get_cat(i);
            cout<<"-----Кот №"<<i+1<<"-----"<<endl;
	    cat.print();
	    }
  	}
    if(type==2){
	diap=ob.search();
	if(diap[0]<0)return;
        for(int i=diap[0]-1;i<=diap[1]-1;++i){ 
	    cat=ob.get_cat(i);
            cout<<"-----Кот №"<<i+1<<"-----"<<endl;
	    cat.print();
	    }
        }
    }
void User::work(){
    int a=1;
    int b=0;
    if(open())return;
    while(a!=0){
	cout<<"1-Вывести базу данных на экран"<<endl<<"2-Поиск кота в базе"<<endl<<"3-Добавление нового кота в базу"<<endl<<"4-Удаление кота из базы"<<endl<<"0-Выход из программы"<<endl;
	cin>>a;
    	switch(a){
	    case 1:system("clear");show(1);break;
	    case 2:system("clear");show(2);break;
	    case 3:system("clear");ob.add_cat();break;
	    case 4:system("clear");ob.del_cat();break;
	    }
    	}
    }


