//
// Created by zeshuang.hu on 2021/12/6.
//

#ifndef TEST_CIRCLE_H
#define TEST_CIRCLE_H

#include "../Shape/Shape.h"


class Circle final : public Shape {
 public:
  explicit Circle(const float &pr) : r(new float(pr)), buff(new char [1024 * 1024 * 1024]) {
    printf("This is a Circle r: %f\n", pr);
    memset(buff, 'X', 1024 * 1024 * 1024);
  }
  ~Circle() final {
    if (r) {
      delete r;
      r = nullptr;
    }

    // if (buff) {
    //   delete[] buff;
    //   buff = nullptr;
    // }
  }

  float calculateArea() final {
    *area = pi * (*r) * (*r);
  }
  float calculatePerimeter() final {
    *perimeter = 2 * pi * (*r);
  }
 private:
  float *r;
  float pi = 3.14;
  char *buff = nullptr;
};


#endif //TEST_CIRCLE_H
