#include <iostream>

class Figure {
public:
   virtual void print_info() {
      std::cout << "Фигура: " << std::endl;

      if (check())
         std::cout << "Правильная" << std::endl;
      else
         std::cout << "Неправильная" << std::endl;

      std::cout << "Количество сторон: " << side << "\n\n";
   }

protected:
   virtual bool check() {
      return true;
   }

   int side = 0;
};

class Triangle : public Figure {
public:
   Triangle(int a, int b, int c, int A, int B, int C) : Figure() {
      this->a = a;
      this->b = b;
      this->c = c;
      this->A = A;
      this->B = B;
      this->C = C;
   }

   void print_info() override {
      std::cout << "Треугольник: " << std::endl;

      if (check())
         std::cout << "Правильная" << std::endl;
      else
         std::cout << "Неправильная" << std::endl;

      std::cout << "Количество сторон: " << side << "\n";

      std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << std::endl;

      std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C;
      std::cout << "\n\n";
   }

protected:
   bool check() override {
      if (a!=0)
         this->side++;
      if (b!=0)
         this->side++;
      if (c!=0)
         this->side++;

      if (A+B+C == 180) {
         if (a != 0 && b != 0 && c != 0) {
            return true;
         }
         else {
            return false;
         }
      }
      else {
         return false;
      }
   }

   int a = 0;
   int b = 0;
   int c = 0;

   int A = 0;
   int B = 0;
   int C = 0;
};

class Quadrangle : public Figure {
public:
   Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(){
      this->a = a;
      this->b = b;
      this->c = c;
      this->d = d;
      this->A = A;
      this->B = B;
      this->C = C;
      this->D = D;
   }

   void print_info() override {
      std::cout << "Четырехугольник: " << std::endl;

      if (check())
         std::cout << "Правильная" << std::endl;
      else
         std::cout << "Неправильная" << std::endl;

      std::cout << "Количество сторон: " << side << "\n";

      std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c;
      if(d != 0)
         std::cout << " d=" << d;
      std::cout << std::endl;

      std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C;
      if(d != 0)
         std::cout << " D=" << D;
      std::cout << "\n\n";
   }

protected:
   bool check() override {
      if (a!=0)
         this->side++;
      if (b!=0)
         this->side++;
      if (c!=0)
         this->side++;
      if (d!=0)
         this->side++;

      if (A+B+C+D == 360) {
         if (a != 0 && b != 0 && c != 0 && d != 0) {
            side = 4;
            return true;
         }
         else
            return false;
      }
      else
         return false;
   }

   int a = 0;
   int b = 0;
   int c = 0;
   int d = 0;

   int A = 0;
   int B = 0;
   int C = 0;
   int D = 0;
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

   void print_info() override {
      std::cout << "Прямой треугольник: " << std::endl;

      if (check())
         std::cout << "Правильная" << std::endl;
      else
         std::cout << "Неправильная" << std::endl;

      std::cout << "Количество сторон: " << side << "\n";

      std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << std::endl;

      std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C;
      std::cout << "\n\n";
   }

protected:
   bool check() override {
      if (A==90 || B==90 || C==90)
         return Triangle::check();
      else
         return false;
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

   void print_info() override {
      std::cout << "Равнобедренный треугольник: " << std::endl;

      if (check())
         std::cout << "Правильная" << std::endl;
      else
         std::cout << "Неправильная" << std::endl;

      std::cout << "Количество сторон: " << side << "\n";

      std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << std::endl;

      std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C;
      std::cout << "\n\n";
   }

protected:
   bool check() override {
      if (A==C && a==c)
         return Triangle::check();
      else
         return false;
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

   void print_info() override {
      std::cout << "Равносторонний треугольник: " << std::endl;

      if (check())
         std::cout << "Правильная" << std::endl;
      else
         std::cout << "Неправильная" << std::endl;

      std::cout << "Количество сторон: " << side << "\n";

      std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << std::endl;

      std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C;
      std::cout << "\n\n";
   }

protected:
   bool check() override {
      if (a == b && a == c) {
         if (A == 60 && B == 60 && C == 60)
            return Triangle::check();
         else
            return false;
      }
      else
         return false;
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

   void print_info() override {
      std::cout << "Прямоугольник: " << std::endl;

      if (check())
         std::cout << "Правильная" << std::endl;
      else
         std::cout << "Неправильная" << std::endl;

      std::cout << "Количество сторон: " << side << "\n";

      std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c;
      if(d != 0)
         std::cout << " d=" << d;
      std::cout << std::endl;

      std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C;
      if(d != 0)
         std::cout << " D=" << D;
      std::cout << "\n\n";
   }

protected:
   bool check() override {
      if ((a==c && b==d) && (A==90 && B==90 && C==90 && D==90))
         return Quadrangle::check();
      else
         return false;
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

   void print_info() override {
      std::cout << "Квадрат: " << std::endl;

      if (check())
         std::cout << "Правильная" << std::endl;
      else
         std::cout << "Неправильная" << std::endl;

      std::cout << "Количество сторон: " << side << "\n";

      std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c;
      if(d != 0)
         std::cout << " d=" << d;
      std::cout << std::endl;

      std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C;
      if(d != 0)
         std::cout << " D=" << D;
      std::cout << "\n\n";
   }

protected:
   bool check() override {
      if (A==90 && B==90 && C==90 && D==90) {
         if (a==c && b==d && a==d)
            return Quadrangle::check();
      }
      else
         return false;
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

   void print_info() override {
      std::cout << "Параллелограмм: " << std::endl;

      if (check())
         std::cout << "Правильная" << std::endl;
      else
         std::cout << "Неправильная" << std::endl;

      std::cout << "Количество сторон: " << side << "\n";

      std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c;
      if(d != 0)
         std::cout << " d=" << d;
      std::cout << std::endl;

      std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C;
      if(d != 0)
         std::cout << " D=" << D;
      std::cout << "\n\n";
   }

protected:
   bool check() override {
      if ((a==c && b==d) && (A==C && B==D))
         return Quadrangle::check();
      else
         return false;
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

   void print_info() override {
      std::cout << "Ромб: " << std::endl;

      if (check())
         std::cout << "Правильная" << std::endl;
      else
         std::cout << "Неправильная" << std::endl;

      std::cout << "Количество сторон: " << side << "\n";

      std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c;
      if(d != 0)
         std::cout << " d=" << d;
      std::cout << std::endl;

      std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C;
      if(d != 0)
         std::cout << " D=" << D;
      std::cout << "\n\n";
   }

protected:
   bool check() override {
      if (a==b && a==c && a==d && A==C && B==D)
         return Quadrangle::check();
      else
         return false;
   }
};

int main() {
   setlocale(LC_ALL, "Russian");

   Figure figure;
   Triangle triangle(10, 20, 30, 50, 60, 70);
   RightTriangle rightTriangle(10, 20, 30, 50, 60);
   IssoTriangle issoTriangle(10, 20, 50);
   EquTriangle equTriangle(30);

   Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
   Rectangle rectangle(10, 20);
   Square square(20);
   Para para(20, 30, 30, 40);
   Rhomb rhomb(30, 30, 40);

   figure.print_info();
   triangle.print_info();
   rightTriangle.print_info();
   issoTriangle.print_info();
   equTriangle.print_info();

   quadrangle.print_info();
   rectangle.print_info();
   square.print_info();
   para.print_info();
   rhomb.print_info();

   return 0;
}