//
// Created by zeshuang.hu on 2021/12/6.
//

#ifndef TEST_CIRCLE_H
#define TEST_CIRCLE_H

#include "../Shape/Shape.h"


namespace circle {

class Circle final : public shape::Shape {
 public:
  Circle(std::shared_ptr<ros::NodeHandle> &p_nh, const float &pr);

  ~Circle() final;

  float calculateArea() final;

  float calculatePerimeter() final;

 private:
  float *r;
  float pi    = 3.14;
  char  *buff = nullptr;
};

}


#endif //TEST_CIRCLE_H
