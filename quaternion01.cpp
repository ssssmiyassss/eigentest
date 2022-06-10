// 2022-06-10 16:55:42
// https://kukku2123.hatenablog.com/entry/2018/01/17/180000

#include <iostream>
#include <Eigen/Geometry>

typedef Eigen::Vector2d Vector2;
typedef Eigen::Vector3d Vector3;
typedef Eigen::Matrix3d Matrix3;
typedef Eigen::Quaterniond Quat;
typedef Eigen::AngleAxisd AngleAxisd;

#define print(var) std::cout << #var" = " << std::endl << (var) << "\n" << std::endl;

const double PI = 3.14159265358979323846;
inline Vector3 rad2deg(Vector3 rad) {return 180.0 / PI * rad;}
inline double rad2deg(double rad) {return 180.0 / PI * rad;}
inline Vector3 deg2rad(Vector3 deg) {return PI / 180.0 * deg;}
inline Vector3 q2rpy(Quat q) {return q.matrix().eulerAngles(0, 1, 2);}
inline Quat rpy2q(Vector3 rpy) {
  Quat q = AngleAxisd(rpy[0], Vector3::UnitX())
           * AngleAxisd(rpy[1], Vector3::UnitY())
           * AngleAxisd(rpy[2],   Vector3::UnitZ());
  return q;
}
inline Vector3 q2rpy2deg(Quat q) {return rad2deg(q2rpy(q));}


void multiplication() {
  std::cout << "-------- 1: multiplication --------" << std::endl;
  Quat q1 = rpy2q(deg2rad(Vector3(30.0, 2.0, 0.0)));
  print(q2rpy2deg(q1));
  Quat q2 = rpy2q(deg2rad(Vector3(20.0, 0.0, 0.0)));
  print(q2rpy2deg(q2));
  print(q2rpy2deg(q1 * q2));  // sum of rotation
  print(q2rpy2deg(q2 * q1));  // sum of rotation

  Quat q3 = rpy2q(deg2rad(Vector3(30.0, 20.0, -60.0)));
  print(q2rpy2deg(q3));
  Quat q4 = rpy2q(deg2rad(Vector3(20.0, -10.0, 50.0)));
  print(q2rpy2deg(q4));
  print(q2rpy2deg(q3 * q4));
  print(q2rpy2deg(q4 * q3));
}

void inverse() {
  std::cout << "------------ 2: inverse ------------" << std::endl;
  Quat q1 = rpy2q(deg2rad(Vector3(10.0, 30.0, -50.0)));
  print(q2rpy2deg(q1));
  Quat q1_inv = q1.inverse();
  print(q2rpy2deg(q1_inv));
  print(q2rpy2deg(q1 * q1_inv));
}

void conjugate(){
  std::cout << "----------- 3: conjugate -----------" << std::endl;
  Quat q1 = rpy2q(deg2rad(Vector3(10.0, 30.0, -50.0)));
  print(q2rpy2deg(q1));
  Quat q1_conj = q1.conjugate();
  print(q2rpy2deg(q1_conj));  // equal to inverse if quaternion is normalized
  print(q2rpy2deg(q1 * q1_conj));
}

void dot() {
  std::cout << "-------------- 4: dot --------------" << std::endl;
  Quat q1 = rpy2q(deg2rad(Vector3(10.0, 0.0, 0.0)));
  print(q2rpy2deg(q1));
  Quat q2 = rpy2q(deg2rad(Vector3(10.0, 0.0, 0.0)));
  print(q2rpy2deg(q2));
}

void rotation() {
  std::cout << "------------ 5: rotation ------------" << std::endl;
  Vector3 v1(1, 0, 0);
  print(v1);
  Quat q1 = rpy2q(deg2rad(Vector3(0.0, 90.0, 0.0)));
  print(q2rpy2deg(q1));
  print(q1 * v1);  // error:  v1 * q1

  Vector3 v2(1, 0, 0);
  print(v2);
  Quat q2 = q1.conjugate();
  print(q2rpy2deg(q2));
  print(q2 * v2);
}


int main(int argc, char * argv[]) {
  multiplication();
  inverse();
  conjugate();
  dot();
  rotation();
  return 0;
}