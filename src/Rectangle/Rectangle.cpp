//
// Created by zeshuang.hu on 2021/12/6.
//

#include "Rectangle.h"

namespace rectangle {

Rectangle::Rectangle(std::shared_ptr<ros::NodeHandle> &p_nh, const float &pw, const float &ph) : Shape(p_nh), w(new float(pw)), h(new float(ph)) {
//  v_sub_.push_back(nh_->advertise("/set_width", 1, &shape::Shape::getArea, (shape::Shape *)this));
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

}
