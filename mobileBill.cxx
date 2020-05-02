#include<iostream>
#include<sstream>
class Customer {
    int id;
    std:: string name;
    std :: string  phone;
   // double balance;
    public:
    Customer ():id(),name(),phone(){}
    Customer (int id , std ::string name,std :: string phone , double bal):id(id),name(name),phone(phone){}
    Customer (int id ,std :: string name ,std ::string phone ):id(id),name(name),phone(phone){}
    Customer (Customer &r):id(r.id),name(r.name),phone(r.phone){}
    void display(){
        std :: cout <<"\n"<< id <<" "<<name<<" "<<phone; 
    }
    virtual void recharge(double d){}
    virtual void call(double d){}
    virtual double getBal(){}
};
class Prepaid : public Customer{
double balance;
public:
    Prepaid ():Customer (),balance(00.00){}
    Prepaid (Customer c):Customer (c),balance (00.00){}
    Prepaid (Customer c,double bal):Customer (c),balance (bal){}
    Prepaid (int id , std ::string name,std :: string phone ):Customer(id,name,phone),balance(00.00){}
    Prepaid (int id , std ::string name,std :: string phone , double bal):Customer(id,name,phone),balance(bal){}
    double getBal(){
        return balance;
    }
     void recharge(double bal){
        balance += bal;
    }
    void call(double d){
        balance -= d;
    }
} ;
class Postpaid : public Customer{
double balance;
public:
    Postpaid ():Customer (),balance(00.00){}
    Postpaid (int id , std ::string name,std :: string phone ):Customer(id,name,phone),balance(00.00){}
    Postpaid (int id , std ::string name,std :: string phone , double bal):Customer(id,name,phone),balance(bal){}
    Postpaid (Customer c):Customer (c),balance (00.00){}
   Postpaid (Customer c,double bal):Customer (c),balance (bal){}
 double getBal(){
        return balance;
    }
    void recharge(double bal){
        balance -= bal;
    }
    void call(double d){
        balance += d;
    }
  //  void addPostpaid(Customer r2){
   //    Postpaid(r2);
    //} 
};
int main(){
    /*Postpaid pobj(1001, "Richard", "9845012345");
    Prepaid pre (1000,"saneeth","4567890262"); 
  pobj.display();
  pre.display();
  Customer *ptr = new Postpaid(1001, "Scott", "98223 12345", 500);
  Customer *ptr1 = new Prepaid(1000,"samba","656565656565",500);
  ptr->recharge(100);  //should invoke from derived class
  ptr1->recharge(100);
  ptr->call(5);    //should invike from derived class
  ptr1->call(5);
  int bal = ptr->getBal();
  int bal1 = ptr1 ->getBal();
   ptr->display();
  std::cout << "\nBalance is :" << bal << "\n";
  ptr1->display();
  std::cout << "\nBalance is :" << bal1 << "\n";
 

  //Customer c1(1003, "Meyers","9845012346",200 ); 
  //uncommenting this line should be an error 
  //TODO: release the memory for object pointed by ptr
  delete ptr;
  delete ptr1;*/

  // in this program user can have both prepaid and post paid accounts 
    Customer c1;
    Customer c2(1,"abcd","1234567890");
    Postpaid c3(2,"saneeth","3567892565",200);
    Prepaid c4(3,"edscdfcds","3645783653",200);
    Postpaid p(c2,100);
    Prepaid p1(c2,200);
     p.recharge(20);
     p.display();
    std:: cout <<" "<< p.getBal();
    c2.display(); 
    c3.recharge(100);
    c4.recharge(100);
    //
    //c5.recharge(100);
    c3.display();
    std:: cout <<" "<< c3.getBal();
    c4.display();
    std:: cout <<" "<< c4.getBal();
    return 0;
}