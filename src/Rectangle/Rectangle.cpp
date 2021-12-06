//
// Created by zeshuang.hu on 2021/12/6.
//

#include "Rectangle.h"

Rectangle::Rectangle(const float &pw, const float &ph) : w(new float(pw)), h(new float(ph)) {
}

Rectangle::~Rectangle() {
  if (w) {
    delete w;
    w = nullptr;
  }
  if (h) {
    delete h;
    h = nullptr;
  }
}

float Rectangle::calculateArea() {
  *area = (*w) * (*h);
}

float Rectangle::calculatePerimeter() {
  *perimeter = 2 * ((*w) + (*h));
}

