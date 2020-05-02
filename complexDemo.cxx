//TODO: implement Complex class using templates, with operator overloading
#include<iostream>
#include<stdlib.h>
//using namespace std;
template <class t>
class Complex{
    t a,b;
    public:
        Complex ():a(0),b(0){}
        Complex (t aa): a(aa),b(aa){}
        Complex (t aa ,t bb):a(aa),b(bb){}
        Complex (const Complex &ref):a(ref.a),b(ref.b){}
        Complex operator +(Complex &ref){
          return (Complex(a+ref.a, b+ref.b));

        }
        Complex operator *(Complex &ref){
             return (Complex(a*ref.a, b*ref.b));
        }
        Complex operator -(Complex &ref){
          return (Complex(a-ref.a,b-ref.b));
        }
         bool  operator ==(Complex &ref){
              if (a==ref.a&&b==ref.b)
                return true;
              return false;
        }
        void display(){std::cout<<a<<"  "<<b<<"\n";}
};
int main() {
  Complex<double> c1(2.9,3);
  Complex<double> c2(1,2.3978);
  Complex<double> res;
 /// std::cout << c1 << "," << c2  << "\n";
 c1.display();
 c2.display();
  res = c1 + c2;
  res.display();
  //print res
  res = c1 - c2;
  res.display();
  //print res
  res = c1 * c2;
    res.display();

  //print res
  Complex<double> c3(c1);
  if(c1==c3) 
     std::cout << "equal\n";
  Complex<int> c4(5);
  c4.display();
  return 0;
}
  
