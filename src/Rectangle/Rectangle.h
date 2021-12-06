//
// Created by zeshuang.hu on 2021/12/6.
//

#ifndef TEST_RECTANGLE_H
#define TEST_RECTANGLE_H

#include "../Shape/Shape.h"


class Rectangle final : public Shape {
 public:
  Rectangle(const float &pw, const float &ph);

  ~Rectangle() final;

  float calculateArea() final;

  float calculatePerimeter() final;

 private:
  float *w;
  float *h;
};


#endif //TEST_RECTANGLE_H
