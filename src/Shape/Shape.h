//
// Created by zeshuang.hu on 2021/12/6.
//

#ifndef TEST_SRC_SHAPE_H_
#define TEST_SRC_SHAPE_H_

#include <bits/stdc++.h>
#include <ros/ros.h>
#include "test/GetArea.h"
#include "test/Area.h"


namespace shape {

class Shape {
 public:
  explicit Shape(std::shared_ptr<ros::NodeHandle> &p_nh);

  virtual ~Shape();

  virtual float calculateArea() = 0;

  virtual float calculatePerimeter() = 0;

  bool getArea();

  bool getPerimeter();

 protected:
  float                            *area;
  float                            *perimeter;
  std::shared_ptr<ros::NodeHandle> nh_;
  std::vector<ros::Subscriber>     v_sub_;
  ros::Publisher                   area_pub_;
};

}

#endif //TEST_SRC_SHAPE_H_
