#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

int main() {
  using namespace Eigen;

  // あらかじめ用意されている値
  // 単位ベクトル(1, 0, 0)
  Vector3f v;
  v = Vector3f::Identity();
  std::cout << "v = Vector3f::Identity()\n" << v << std::endl;

  // (0, 0, 0)
  v = Vector3f::Zero();
  std::cout << "v = Vector3f::Zero();\n" << v << std::endl;

  // (1, 1, 1)
  v = Vector3f::Ones();
  std::cout << "v = Vector3f::Ones();\n" << v << std::endl;

  // (1, 0, 0)
  v = Vector3f::UnitX();
  std::cout << "v = Vector3f::UnitX();\n" << v << std::endl;

  // (0, 1, 0)
  v = Vector3f::UnitY();
  std::cout << "v = Vector3f::UnitY();\n" << v << std::endl;

  // (0, 0, 1)
  v = Vector3f::UnitZ();
  std::cout << "v = Vector3f::UnitZ();\n" << v << std::endl;

  // ランダムな値
  // FIXME:std::rand()を使っている
  v = Vector3f::Random();
  std::cout << "v = Vector3f::Random();\n" << v << std::endl;

  // 定数
  v = Vector3f::Constant(0.5f);
  std::cout << "v = Vector3f::Constant(0.5f);\n" << v << std::endl;


  // 各要素への読み書き
  float x, y, z;
  x = v.x();
  y = v.y();
  z = v.z();

  x = 114.;
  y = 514.;
  z = 931.;

  v.x() = x;
  v.y() = y;
  v.z() = z;
  std::cout << "  v.x() = x; v.y() = y;  v.z() = z; v\n" << v << std::endl;

  // こういう書き方もできる
  v(0) = x;
  v(1) = y;
  v(2) = z;
  std::cout << "  v(0) = x;   v(1) = y;   v(2) = z; v\n" << v << std::endl;

  // []の場合は添え字の正当性をチェックしない
  x = v[0];
  y = v[1];
  z = v[2];

  // こういう代入も可能
  v << 0.5f, 1.2f, -2.0f;
  std::cout << "v << 0.5f, 1.2f, -2.0f;\n" << v << std::endl;

  // コピー
  Vector3f v1;
  v1 = v;
  std::cout << "  Vector3f v1; v1 = v;\n" << v1 << std::endl;

  // 加算・減算
  Vector3f v2;
  v2 = v + v1;
  std::cout << "v2 = v + v1;\n" << v2 << std::endl;
  v2 = v - v1;
  std::cout << "v2 = v - v1;\n" << v2 << std::endl;

  // 乗算・除算(ベクトル同士の乗算、除算は無い)
  std::cout << "v\n" << v << std::endl;
  v1 = v * 2.0f;
  std::cout << "v1 = v * 2.0f;\n" << v1 << std::endl;
  v1 = v / 2.0f;
  std::cout << "v1 = v / 2.0f;\n" << v1 << std::endl;

  // 内積・外積
  float dot = v.dot(v1);
  std::cout << "v\n" << v << std::endl;
  std::cout << "v1\n" << v1 << std::endl;
  std::cout << "dot = v.dot(v1);\n" << dot << std::endl;

  Vector3f cross = v.cross(v1);
  std::cout << "v\n" << v << std::endl;
  std::cout << "v1\n" << v1 << std::endl;
  std::cout << "cross = v.cross(v1);\n" << cross << std::endl;

  // ベクトルの長さ
  float norm = v.norm();
  std::cout << "float norm = v.norm();\n" << norm << std::endl;

  // 正規化(長さ1)したベクトルを生成
  Vector3f n = v.normalized();
  std::cout << "Vector3f n = v.normalized();\n" << n << std::endl;

  // ベクトルを正規化する
  v.normalize();

  VectorXd vv(10);
  vv << 1,2,3,4,5,6,7,8,9,10;
  std::cout << "VectorXd vv(10)" << std::endl;
  std::cout << "vv << 1,2,3,4,5,6,7,8,9,10;\n" << vv << std::endl;
  
}