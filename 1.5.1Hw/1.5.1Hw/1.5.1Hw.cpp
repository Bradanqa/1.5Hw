#include <iostream>

class Figure {
public:
   Figure(int userSide = 0) {
      this->side = userSide;
   }

   virtual void print() {
      std::cout << "Фигура: " << side << std::endl;
   }

protected:
   int side;
};

class Triangle : protected Figure {
public:
   Triangle() {
      this->side = 3;
   }

   void print() override {
      std::cout << "Треугольник: " << side << std::endl;
   }
};

class Quadrangle : protected Figure {
public:
   Quadrangle() {
      this->side = 4;
   }
   void print() override {
      std::cout << "Четырехугольник: " << side << std::endl;
   }
};

int main() {

   setlocale(LC_ALL, "Russian");

   Figure figure;
   Triangle triangle;
   Quadrangle quadrangle;

   std::cout << "Количество сторон:" << std::endl;

   figure.print();
   triangle.print();
   quadrangle.print();

   return 0;
}