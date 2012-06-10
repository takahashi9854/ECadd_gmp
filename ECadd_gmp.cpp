//June 8th.

#include <iostream>
#include "gmpxx.h"
#include "gmp.h"

class Point{
public:
  mpq_class x;
  mpq_class y;
  mpq_class z;
  void ECadd(Point P,Point Q);
  void init();
  void set(mpq_class x,mpq_class y,mpq_class z);
  static Point twice(Point P);
  Point();
  Point(mpq_class X,mpq_class Y,mpq_class Z);
  void copy(Point P);
  void show();
  static mpq_class a,b,c,;

};

// Initialize coefficients of Elliptic Curve.
mpq_class Point::a = 0;
mpq_class Point::b = 0;
mpq_class Point::c = 3;


// Default Constructor.
Point::Point(): x(0),y(0),z(1) {
}

// Constructor using initialize variables which you want.
Point::Point(mpq_class X,mpq_class Y,mpq_class Z): x(X),y(Y),z(Z){
}

void Point::copy(Point P){
  x = P.x;
  y = P.y;
  z = P.z;

  return;
}

// Showing coordinates of Point instance.
void Point::show(){
  std::cout << "(" << x << "," << y << "," << z <<")" << std::endl;
  return;
}

// Menber funciton to init instance.
// By default,initialized using original point.
void Point::init(){
  x=y="0";
  z="1";
}

// Additional two points.
void Point::ECadd(Point P,Point Q){
  mpq_class l;
  mpq_class v;
  
  if(P.x != Q.x && P.y != Q.y){
    l = (P.y - Q.y)/(P.x - Q.x);
    v = Q.y - l * Q.x;
    x = l*l - a - P.x - Q.x;
    y = -1*(l * x + v);
    z = "1";
    return;
  }else if(P.x == Q.x && P.y == Q.y){
    l = (3*P.x*P.x + 2*a*P.x + b)/(2*P.y);
    v = Q.y - l*Q.x;
    x = l*l - a - 2*P.x;
    y = -1*(l*x + v);
    z="1";
    return;
  }else{
    x=z="1";
    y="0";
    return;
  }
    
}

// Initialize coordinates that you want.
void Point::set(mpq_class X,mpq_class Y,mpq_class Z){
  x = X;
  y = Y;
  z = Z;
}

int main(int argc,char **argv){
  Point P(1,2,1);
  Point Q(1,2,1);
  // Point P;
  Point P2,P3,P4,P5,P6,P7;
  Point R;

  std::cout << "Point P." << std::endl;
  P.show();
  std::cout <<"\n";
  
  // std::cout << "Point Q." << std::endl;
  // Q.show();
  // std::cout << "\n";

  std::cout << "Addition of P and Q into P2." << std::endl;
  P2.ECadd(P,Q);
  P2.show();
  std::cout << "\n";
  
  std::cout << "Addition of P and P2 into P3." << std::endl;
  P3.ECadd(P,P2);
  P3.show();
  std::cout << "\n";

  std::cout << "Addition of P and P3 into P4" <<std::endl;
  P4.ECadd(P3,P);
  P4.show();
  std::cout << "\n";

  std::cout << "Addition of P and P4 into P5" <<std::endl;
  P5.ECadd(P4,P);
  P5.show();
  std::cout << "\n";

  std::cout << "Addition of P and P5 into P6" <<std::endl;
  P6.ECadd(P5,P);
  P6.show();
  std::cout << "\n";

  std::cout << "Addition of P and P6 into P7" <<std::endl;
  P7.ECadd(P6,P);
  P7.show();
  std::cout << "\n";

  return 0;
}
