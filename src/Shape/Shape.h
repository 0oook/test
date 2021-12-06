//
// Created by zeshuang.hu on 2021/12/6.
//

#ifndef TEST_SRC_SHAPE_H_
#define TEST_SRC_SHAPE_H_

#include <bits/stdc++.h>


class Shape {
 public:
  Shape() {
    area      = new float;
    perimeter = new float;
  }

  virtual ~Shape() {
    if (area) {
      delete area;
      area = nullptr;
    }

    if (perimeter) {
      delete perimeter;
      perimeter = nullptr;
    }
  }

  virtual float calculateArea() = 0;

  virtual float calculatePerimeter() = 0;

  float getArea() {
    printf("Area: %f\n", *area);
    return *area;
  }

  float getPerimeter() {
    printf("Perimeter: %f\n", *perimeter);
    return *perimeter;
  }

 protected:
  float *area;
  float *perimeter;
};


#endif //TEST_SRC_SHAPE_H_
