//
// Created by zeshuang.hu on 2021/12/6.
//

#include "Shape.h"

namespace shape {

Shape::Shape(std::shared_ptr<ros::NodeHandle> &p_nh) : nh_(p_nh) {
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

bool Shape::getArea() {
  printf("Area: %f\n", *area);
  return *area;
}

bool Shape::getPerimeter() {
  printf("Perimeter: %f\n", *perimeter);
  return *perimeter;
}

}

