//
// Created by zeshuang.hu on 2021/12/6.
//

#ifndef TEST_RECTANGLE_H
#define TEST_RECTANGLE_H

#include "../Shape/Shape.h"

namespace rectangle {

class Rectangle final : public shape::Shape {
 public:
  Rectangle(std::shared_ptr<ros::NodeHandle> &p_nh, const float &pw, const float &ph);

  ~Rectangle() final;

  float calculateArea() final;

  float calculatePerimeter() final;

 private:
  float *w;
  float *h;
};

}

#endif //TEST_RECTANGLE_H
