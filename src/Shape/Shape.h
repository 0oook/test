//
// Created by zeshuang.hu on 2021/12/6.
//

#ifndef TEST_SRC_SHAPE_H_
#define TEST_SRC_SHAPE_H_

#include <bits/stdc++.h>


class Shape {
 public:
  Shape();

  virtual ~Shape();

  virtual float calculateArea() = 0;

  virtual float calculatePerimeter() = 0;

  float getArea();

  float getPerimeter();

 protected:
  float *area;
  float *perimeter;
};


#endif //TEST_SRC_SHAPE_H_
