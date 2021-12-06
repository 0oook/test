//
// Created by zeshuang.hu on 2021/12/6.
//

#ifndef TEST_RECTANGLE_H
#define TEST_RECTANGLE_H

#include "../Shape/Shape.h"


class Rectangle final : public Shape {
 public:
  Rectangle(const float &pw, const float &ph) : w(new float(pw)), h(new float(ph)) {
  }

  ~Rectangle() final {
    if (w) {
      delete w;
      w = nullptr;
    }
    if (h) {
      delete h;
      h = nullptr;
    }
  }

  float calculateArea() final {
    *area = (*w) * (*h);
  }

  float calculatePerimeter() final {
    *perimeter = 2 * ((*w) + (*h));
  }

 private:
  float *w;
  float *h;
};


#endif //TEST_RECTANGLE_H
