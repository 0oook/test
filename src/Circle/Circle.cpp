//
// Created by zeshuang.hu on 2021/12/6.
//

#include "Circle.h"

Circle::Circle(const float &pr) : r(new float(pr)), buff(new char[1024 * 1024 * 1024]) {
  printf("This is a Circle r: %f\n", pr);
  memset(buff, 'X', 1024 * 1024 * 1024);
}

Circle::~Circle() {
  if (r) {
    delete r;
    r = nullptr;
  }

  if (buff) {
    delete[] buff;
    buff = nullptr;
  }
}

float Circle::calculateArea() {
  *area = pi * (*r) * (*r);
}

float Circle::calculatePerimeter() {
  *perimeter = 2 * pi * (*r);
}
