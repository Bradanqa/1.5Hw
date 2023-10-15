#include <iostream>

class Figure {
public:
   Figure(int a, int b, int c, int d, int A, int B, int C, int D) {
      this->a = a;
      this->b = b;
      this->c = c;
      this->d = d;
      this->A = A;
      this->B = B;
      this->C = C;
      this->D = D;
   }

   int get_a() { return a;}
   int get_b() { return b;}
   int get_c() { return c;}
   int get_d() { return d;}

   int get_A() { return A;}
   int get_B() { return B;}
   int get_C() { return C;}
   int get_D() { return D;}

   virtual void print() {
      std::cout << "Фигура: " << side << std::endl;
   }

protected:
   int side = 0;

   int a;
   int b;
   int c;
   int d = 0;

   int A;
   int B;
   int C;
   int D = 0;
};

class Triangle : public Figure {
public:
   Triangle(int a, int b, int c, int A, int B, int C) : Figure(a,b,c,0,A,B,C,0) {
      this->a = a;
      this->b = b;
      this->c = c;
      this->A = A;
      this->B = B;
      this->C = C;
   }

   void print() override {
      std::cout << "Треугольник: " << std::endl;
   }
};

class Quadrangle : public Figure {
public:
   Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(a,b,c,d,A,B,C,D){
      this->a = a;
      this->b = b;
      this->c = c;
      this->d = d;
      this->A = A;
      this->B = B;
      this->C = C;
      this->D = D;
   }

   void print() override {
      std::cout << "Четырехугольник: " << std::endl;
   }
};

class RightTriangle : public Triangle {
public:
   RightTriangle( int a, int b, int c, int A, int B) : Triangle(a,b,c,A,B,90) {
      this->a = a;
      this->b = b;
      this->c = c;
      this->A = A;
      this->B = B;
      this->C = 90;
   }

   void print() override {
      std::cout << "Прямой треугольник: " << std::endl;
   }
};

class IssoTriangle : public Triangle {
public:
   IssoTriangle(int a, int b, int A) : Triangle(a,b,a,A,180 - A * 2,A) {
      this->a = a;
      this->b = b;
      this->c = a;
      this->A = A;
      this->B = 180 - A * 2;
      this->C = A;
   }

   void print() override {
      std::cout << "Равнобедренный треугольник: " << std::endl;
   }
};

class EquTriangle : public Triangle {
public:
   EquTriangle(int side) : Triangle(side,side,side,60,60,60) {
      this->a = side;
      this->b = side;
      this->c = side;
      this->A = 60;
      this->B = 60;
      this->C = 60;
   }

   void print() override {
      std::cout << "Равносторонний треугольник: " << std::endl;
   }
};

class Rectangle : public Quadrangle {
public:
   Rectangle(int a, int b) : Quadrangle(a,b,a,b,90,90,90,90) {
      this->a = a;
      this->b = b;
      this->c = a;
      this->d = b;
      this->A = 90;
      this->B = 90;
      this->C = 90;
      this->D = 90;
   }

   void print() override {
      std::cout << "Прямоугольник: " << std::endl;
   }
};

class Square : public Quadrangle {
public:
   Square(int side) : Quadrangle(side,side,side,side,90,90,90,90)  {
      this->a = side;
      this->b = side;
      this->c = side;
      this->d = side;
      this->A = 90;
      this->B = 90;
      this->C = 90;
      this->D = 90;
   }

   void print() override {
      std::cout << "Квадрат: " << std::endl;
   }
};

class Para : public Quadrangle {
public:
   Para(int a, int b, int A, int B) : Quadrangle(a,b,a,b,A,B,A,B)  {
      this->a = a;
      this->b = b;
      this->c = a;
      this->d = b;
      this->A = A;
      this->B = B;
      this->C = A;
      this->D = B;
   }

   void print() override {
      std::cout << "Параллелограмм: " << std::endl;
   }
};

class Rhomb : public Quadrangle {
public:
   Rhomb(int side, int A, int B) : Quadrangle(side,side,side,side,A,B,A,B) {
      this->a = side;
      this->b = side;
      this->c = side;
      this->d = side;
      this->A = A;
      this->B = B;
      this->C = A;
      this->D = B;
   }

   void print() override {
      std::cout << "Ромб: " << std::endl;
   }
};

void print_info(Figure *figure) {
   int a = figure->get_a();
   int b = figure->get_b();
   int c = figure->get_c();
   int d = figure->get_d();

   int A = figure->get_A();
   int B = figure->get_B();
   int C = figure->get_C();
   int D = figure->get_D();

   figure->print();
   std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c;
   if(d != 0)
      std::cout << " d=" << d;
   std::cout << std::endl;

   std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C;
   if(d != 0)
      std::cout << " D=" << D;
   std::cout << std::endl;


}

int main() {
   setlocale(LC_ALL, "Russian");

   Triangle triangle(10, 20, 30, 50, 60, 70);
   RightTriangle rightTriangle(10, 20, 30, 50, 60);
   IssoTriangle issoTriangle(10, 20, 50);
   EquTriangle equTriangle(30);

   Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
   Rectangle rectangle(10, 20);
   Square square(20);
   Para para(20, 30, 30, 40);
   Rhomb rhomb(30, 30, 40);

   print_info(&triangle);
   print_info(&rightTriangle);
   print_info(&issoTriangle);
   print_info(&equTriangle);

   print_info(&quadrangle);
   print_info(&rectangle);
   print_info(&square);
   print_info(&para);
   print_info(&rhomb);

   return 0;
}