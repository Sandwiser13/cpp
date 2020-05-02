#include<iostream>
class Currency {
  //TODO: data members : rupees, paise
	int rupees;
    int paise;
    
  public:
    Currency ():rupees(0),paise(0){}
    Currency (int r,int p):rupees(r),paise(p){}

    Currency operator +(Currency &r){
        int rr= rupees+r.rupees;
        int pp = paise +r.paise;
        while (pp>=100){
            rr++;
            pp-=100;
        }
        return (Currency (rr,pp));
    }
    Currency operator +(int pp){
        int rr= rupees;
        pp = pp+paise;
        while (pp>=100){
            rr++;
            pp=pp-100;
        }
        return Currency (rr,pp); 
    }
    Currency operator ++(){
            int pp = paise +1;
            int rr=rupees;
            while (pp>=100){
                rr++;
                pp=pp-100;
            }
            return (Currency(rr,pp));
    }

    bool operator == (Currency &r){
        if (rupees==r.rupees)
            return true;
        return false;
    }
    void display(){std::cout <<"\n"<<rupees<<"."<<paise;}

  //TODO: Suitable default, parameterized constructors
  //TODO: Define copy constructor
  //TODO: necessary operator overloding as per the test code in main
  //TODO: display function to print currency in suitable format
};
int main() {
  Currency c1(10,60);
  Currency c2(5, 50);
  Currency c3;         // Currency will be Rs0.0
  c3 = c1 + c2;        // c3 will be Rs.16.10
  c3.display();
  Currency c4;
  c4 = c1 + 20;      // 20 paise will be added, c4 will be 10:80
  c4.display();
  ++c1;              // c1 will be Rs.10.61
  c1.display();
  (++c2).display();  // c2 will be Rs.5.51, same will be displayed
 if(c1==c2)
     std::cout << "equal\n";
  else 
     std::cout << "Not equal";
  //Optional:-
  c4 = c1;
  c4.display();
  //c5 = c1 - 40;
 // std::cout << c1 << "\n";
 // */
   return 0;
}
