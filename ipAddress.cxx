#include<iostream>
#include<sstream>
//#include<string.h>
//TODO: Implement IP Address class in suitable file hierarchy
// Data members - a, b, c, d
class IPAddress{
    int a,b,c,d;
public:
    IPAddress():a(127),b(0),c(0),d(1){}
    IPAddress(int aa,int bb,int cc,int dd):a(aa),b(bb),c(cc),d(dd){}
    IPAddress(std::string str, int pos=0) :a(stoi(sub(str,&pos))),b(stoi(sub(str,&pos))),c(stoi(sub(str,&pos))),d(stoi(sub(str,&pos))){}
    std :: string sub(const std:: string str,int *pos){
        std::string temp="";
        for (int i=*pos,j=0;i<str.length();i++,j++){
            if (str[i]=='.'){
                *pos = i+1;
                return temp;
            }
            temp[j]=str[i];
        }
        return temp;
    }
    void display(){std ::cout <<a<<" "<<b<<" "<<c<<" "<<d<<"\n";}
};
int main() {
  IPAddress ip1;        //Loopback 127.0.0.1
  IPAddress ip2(192, 168, 72, 25);
  IPAddress ip3("192.168.76.25");
  //ip1.isLoopback()
  ip1.display();
  ip2.display();   // "192.168.72.25"
  ip3.display();
  return 0;
}
