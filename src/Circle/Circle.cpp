//
// Created by zeshuang.hu on 2021/12/6.
//

#include "Circle.h"

namespace circle {

Circle::Circle(std::shared_ptr<ros::NodeHandle> &p_nh, const float &pr) : Shape(p_nh), r(new float(pr)), buff(new char[1024 * 1024 * 1024]) {
  printf("This is a Circle r: %f\n", pr);
  memset(buff, 'X', 1024 * 1024 * 1024);
//  v_sub_.push_back(nh_->subscribe("/area", 1, &shape::Shape::updateOccMapCallback, (RobotMap * )
//  this));
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

}
