//
// Created by zeshuang.hu on 2021/12/6.
//

#include "Circle/Circle.h"
#include "Rectangle/Rectangle.h"
#include <armadillo>

using std::cout;
using std::endl;

struct PixelPose {
  float x;
  float y;
  float theta;
  float loc_confidence;
  float loc_threshold;
};

struct ChargerPoi {
  std::string name;  // 充电桩名字
  bool        is_default;  // 是否是默认充电桩
  PixelPose   pixel_pose;  // 充电桩位置
  PixelPose   pixel_pose_navi;  // 导航的上桩点
};

void foo() {

  PixelPose  pixel_pose{
      1, 1, 1, 1, 1
  };
  ChargerPoi charger_poi_0 = {"a", true, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
  ChargerPoi charger_poi_1 = {"b", true, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2};
  ChargerPoi charger_poi_2 = {"c", true, 3, 1, 1, 1, 1, 2, 2, 2, 2, 2};
  ChargerPoi charger_poi_3 = {"d", true, 4, 1, 1, 1, 1, 2, 2, 2, 2, 2};
  ChargerPoi charger_poi_4 = {"e", true, 5, 1, 1, 1, 1, 2, 2, 2, 2, 2};
  charger_poi_3.is_default = true;
  std::unordered_map<std::string, ChargerPoi> charger_poi_{
      {"a", charger_poi_0},
      {"b", charger_poi_1},
      {"c", charger_poi_2},
      {"d", charger_poi_3},
      {"e", charger_poi_4},
  };

  for (const auto &item: charger_poi_) {
    if (item.second.is_default) printf("%s => %s: %f, %f, %f\n", item.first.c_str(), item.second.name.c_str(), item.second.pixel_pose.x, item.second.pixel_pose.y, item.second.pixel_pose.theta);
  }

  printf("============================  find default charger ===============================\n");
  for (const auto &charger_poi: charger_poi_) {
    if (charger_poi.second.is_default) {
      printf("Find a default charger named %s\n", charger_poi.first.c_str());
    }
  }

  std::string charger_name = "a";
  PixelPose   pose{1, 1, 1, 1, 1};
  printf("===========================  set %s to default charger  =======================================\n", charger_name.c_str());
  auto find_res = charger_poi_.find(charger_name);
  if (find_res == charger_poi_.end()) {
    printf("no charger named %s\n", charger_name.c_str());
  } else {

    if (find_res->second.pixel_pose.x != pose.x || find_res->second.pixel_pose.y != pose.y || find_res->second.pixel_pose.theta != pose.theta) {
      printf("Using charger pose(%f, %f, %f) !=  request poe(%f, %f, %f)\n",
             find_res->second.pixel_pose.x, find_res->second.pixel_pose.y, find_res->second.pixel_pose.theta,
             pose.x, pose.y, pose.theta);
    } else {
      for (auto &item_pair: charger_poi_) {
        if (item_pair.second.is_default && item_pair.first != charger_name) {
          item_pair.second.is_default = false;
          printf("Find a default charger named %s, set it to no default charget\n", item_pair.second.name.c_str());
        }
      }

      if (find_res->second.is_default) {
        printf("This charger named %s already is defauld charger\n", charger_name.c_str());
      } else {
        find_res->second.is_default = true;
        printf("Find a charger named %s, now set it to default charger\n", charger_name.c_str());
      }
    }

    printf("============================  find default charger ===============================\n");
    for (const auto &charger_poi: charger_poi_) {
      if (charger_poi.second.is_default) {
        printf("Find a default charger named %s\n", charger_poi.second.name.c_str());
      }
    }

  }

}

int main() {
  cout << "Hello world!" << endl;

  std::shared_ptr<ros::NodeHandle> p_nh = std::make_shared<ros::NodeHandle>();
  auto *c1 = new circle::Circle(p_nh, 100);
  c1->calculateArea();
  c1->calculatePerimeter();

  c1->getArea();
  c1->getPerimeter();

  delete c1;

  auto *c2 = new circle::Circle(p_nh, 10);
  c2->calculateArea();
  c2->calculatePerimeter();

  c2->getArea();
  c2->getPerimeter();

  delete c2;

  auto *r1 = new rectangle::Rectangle(p_nh, 10, 20);
  r1->calculateArea();
  r1->calculatePerimeter();

  r1->getArea();
  r1->getPerimeter();

  delete r1;

  for (int i = 0; i < 10000; ++i) {
    cout << "Hello world!" << endl;
    sleep(1);
  }

}
