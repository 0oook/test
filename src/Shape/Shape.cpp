//
// Created by zeshuang.hu on 2021/12/6.
//

#include "Shape.h"


Shape::Shape() {
  area      = new float;
  perimeter = new float;
}

Shape::~Shape() {
  if (area) {
    delete area;
    area = nullptr;
  }

  if (perimeter) {
    delete perimeter;
    perimeter = nullptr;
  }
}

float Shape::getArea() {
  printf("Area: %f\n", *area);
  return *area;
}

float Shape::getPerimeter() {
  printf("Perimeter: %f\n", *perimeter);
  return *perimeter;
}
