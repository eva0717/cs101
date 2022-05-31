#include<iostream>
#include<string>
using namespace std;

class Clock{
    public:
    int hour,minute,second;
    string meridian;
    Clock(int H,int M,int S,string mer){
        hour = H;
        minute = M;
        second = S;
        meridian = mer;
    }
    display(){
        cout << hour << ":" << minute << ":" << second << " " << meridian << endl;
    }
};

class StandardClock : Clock{
    public:
    StandardClock(int H,int M,int S,string mer):Clock(H,M,S,mer){
        if(meridian=="AM") meridian = "上午";
        else if(meridian=="PM") meridian = "下午";
    }
    display(){
        cout << meridian << " " << hour << ":" << minute << ":" << second << endl;
    }
};

class MilitaryClock : Clock{
    public:
    MilitaryClock(int H,int M,int S,string mer):Clock(H,M,S,mer){
        if(meridian=="PM") hour+=12;
    }
    display(){
        cout <<  hour << ":" << minute << ":" << second;
    }
};

int main(){
    Clock cc(10,25,43,"AM");
    StandardClock sc(10,25,43,"AM");
    MilitaryClock mc(10,25,43,"PM");
    cc.display();
    sc.display();
    mc.display();
    return 0;
}
