#include <iostream>
#include <string>

using namespace std;

class Clock{
   public:
        int hour;
        int min;
        int sec;
        string ti;
        
    
        Clock(int x,int y,int z,string f){
            hour=x;
            min=y;
            sec=z;
            ti=f;
        }
       
        void display(){
            cout<<hour<<":"<<min<<":"<<sec<<" ";
            cout<<ti<<endl;
        }
        
};
class StandardClock : Clock{
  private:
    int flag;
    
  public:
    StandardClock(int x,int y,int z,string f):Clock(x,y,z,f){
        if(ti=="AM"){
           flag=0;
        }else{
           flag=1;
        }
    }
    void display(){
        if(!flag){
        cout<<"上午"<<" ";
        }else{
        cout<<"下午"<<" ";    
        }
        cout<<hour<<":"<<min<<":"<<sec<<endl;
    }
};
class MilitaryClock : Clock{
  private:
    int flag;
  public:
    MilitaryClock(int x,int y,int z,string f):Clock(x,y,z,f){
     if(ti=="AM"){
           flag=0;
        }else{
           flag=1;
        }
    }
    void display(){
       if(flag){
            cout<<hour+12<<":";
        }else{
            cout<<hour<<":";
        }
        cout<<min<<":"<<sec<<endl;
    }
};
int main(){
   Clock cc(10,25,43,"AM");
   StandardClock sc(10,25,43,"AM");
   MilitaryClock mc(10,25,43,"AM");
   cc.display();
   sc.display();
   mc.display();
    return 0;
}
