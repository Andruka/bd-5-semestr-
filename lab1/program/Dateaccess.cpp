#include "Dateaccess.h"
Cat Dateaccess::get_cat (int index) {
        ifstream in (fn);
        if (!in.is_open()) return Cat();
        in.seekg (index * CAT_SIZE);
        in>>cat;
        return cat;
    }
int Dateaccess::start(const char * filename){
    strcpy(fn,filename);
    const char * F1="1.txt";
    const char * F2="2.txt";
    ifstream in(fn);
    in.unsetf (std::ios::skipws);
    if(!in)return 1;
    ofstream out1(F1);
    ofstream out2(F2);
    for(int i=0;;++i){
	in>>cat;
        if(in.eof())break;
	if(i%2)out1<<cat;
	else out2<<cat;
	}
    in.close();
    out1.close();
    out2.close();
    merge();
    remove("1.txt");
    remove("2.txt");
    remove("3.txt");
    remove("4.txt");
}
void Dateaccess::del_cat(){
    int num=0;
    int size=0;
    int count=1;
    cout<<"Введите номер кота для удаления:  ";
    cin>>num;
    ifstream in(fn);
    ofstream out("temp");
    in.seekg(0,in.end);
    size=in.tellg()/130+1;
    if(size<num)return;
    in.seekg(0,in.beg);
    while(1){
        in>>cat;
	++count;
	if(in.eof())break;
	if((count)!=num+1){
	    out<<cat;
	    }
	}
    in.close();
    out.close();
    remove(fn);
    rename("temp",fn);
    }
void Dateaccess::add_cat(){
    char name[64];
    char breed[64];
    int age;
    char gender;
    ofstream out;
    out.open(fn,ios::app);
    cout<<"Введите имя кота: "<<endl;
    cin>>name;
    cout<<"Введите породу кота: "<<endl;
    cin>>breed;
    cout<<"Введите возраст кота: "<<endl;
    cin>>age;
    cout<<"Введите пол кота: "<<endl;
    cin>>gender;
    Cat cat1(name,breed,(char)age,gender);
    out<<cat1;
    out.close();
    start(fn);
    }
void Dateaccess::merge(){
    ifstream fin[2];
    ofstream fout[2]; 
    int block[2];
    int x=1;
    int a;
    int checkCat,actualFin;
    Cat cat[2];
    while(true){
	block[0]=block[1]=x;
	fin[0].open("1.txt");
	fin[1].open("2.txt");
	fout[0].open("3.txt");
	fout[1].open("4.txt");
   	for(int i=1;;++i){
	    a=(i%2);
	    if(fin[0].eof() && fin[1].eof())break;
	    for(int j=(x*2);j>0;--j){
		if(!fin[0].eof() || !fin[1].eof()){
	            if(j==(x*2) && !fin[0].eof()){
		        fin[0]>>cat[0];
			if(fin[0].eof()){
			    if(i==1 && j==x*2){
	    			rename("2.txt",fn);
	    			return;
				}
			    ++j;
			    block[1]+=block[0];
			    block[0]=0;
			    continue;
			    }
			--block[0];
			continue;
			}
		    if(j==(x*2)){
			fin[1]>>cat[0];
			if(fin[1].eof()){
			    ++j;
			    block[0]+=block[1];
			    block[1]=0;
			    continue;
			    }
			--block[1];
			continue;
			}
		    if(j==(x*2-1)){
			fin[1]>>cat[1];
			if(fin[1].eof()){
			    ++j;
			    block[0]+=block[1];
			    block[1]=0;
			    fout[a]<<cat[0];			    
			    continue;
			    }
			--block[1];
		    	if(compare(cat[0],cat[1],1)<=0)checkCat=0;
			else checkCat=1;
		        fout[a]<<cat[checkCat];
		        if(j==1){
			    if(checkCat==0)fout[a]<<cat[1];
			    else fout[a]<<cat[0];
			    }
			continue;						
			}
		    if(block[0]!=0 && block[1]!=0){
		    	fin[checkCat]>>cat[checkCat];
			if(fin[checkCat].eof()){
			    if(fin[0].eof()){
			        block[1]+=block[0];
			        block[0]=0;				
				}
			    else{
			        block[0]+=block[1];
			        block[1]=0;				
				}
			    ++j;
			    continue;
			    }
			--block[checkCat];
		    	if(compare(cat[0],cat[1],1)<=0)checkCat=0;
			else checkCat=1;
		    	fout[a]<<cat[checkCat];
			}
		    else{
			if(block[0]==0)actualFin=1;
			else actualFin=0;
		        fin[actualFin]>>cat[checkCat];
			if(fin[actualFin].eof()){
			    if(fin[0].eof()){
			        block[1]+=block[0];
			        block[0]=0;				
				}
			    else{
			        block[0]+=block[1];
			        block[1]=0;				
				}
			    if(fin[0].eof() && fin[1].eof()){
				if(checkCat==0)fout[a]<<cat[1];
				else fout[a]<<cat[0];				
				}
			    ++j;
			    continue;
			    }
			--block[actualFin];
		    	if(compare(cat[0],cat[1],1)<=0)checkCat=0;
			else checkCat=1;
		        fout[a]<<cat[checkCat];			
			}
		    if(j==1){
			if(checkCat==0)fout[a]<<cat[1];
			else fout[a]<<cat[0];
			}
		    }
		else break;
	    	}
	    block[0]=block[1]=x;
	    }
	fin[0].close();
	fin[1].close();
	fout[0].close();
	fout[1].close();
	rename("1.txt","temp.txt");
	rename("3.txt","1.txt");
	rename("temp.txt","3.txt");
	rename("2.txt","temp.txt");
	rename("4.txt","2.txt");
	rename("temp.txt","4.txt");
	x=x*2;		
	}
}
int* Dateaccess::search(){
    ifstream in(fn);
    int* diap=new int[2];   
    if(!in){
	diap[0]=-1; 
        return diap;
        }
    int temp=0;
    int maxAge=0;
    char n[64];
    char b[64];
    for(int i=0;i<64;++i){
        n[i]='\0';
        b[i]='\0';
        }
    int a=0;
    char g='\0';
    Cat cat1;
    cout<<"Введите имя кота для поиска: ";
    cin>>n;
    Cat cat2(n,b,a,g);
    streampos middle,end,beg=0;
    in.seekg(0,in.end);
    end=in.tellg();
    while(true){
	if((end-beg)==130)break;
	middle=(((end+beg)/130)/2)*130;
        in.seekg(middle);
        in>>cat1;
	if(compare(cat1,cat2,1)<0)beg=middle;
	else end=middle;
	}
    in.seekg(beg);
    in>>cat1;
    if(compare(cat1,cat2,1)<0)in>>cat1;
    while(true){
	if(in.eof()||compare(cat1,cat2,1)>0){
	    if(temp==0){
		cout<<"Коты не найдены!"<<endl;
	    	diap[0]=-1;
		}
	    if(temp==1)diap[1]=diap[0];
	    return diap;
	    }
	if(temp==0)diap[0]=(in.tellg()/130);
	else diap[1]=(in.tellg()/130);
        ++temp;
	in>>cat1;
	}
    diap[1]=(in.tellg()/130);
    in.close();
    return diap;
}
