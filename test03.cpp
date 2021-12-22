#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

int main() {
  using namespace Eigen;

  Matrix3f m;
  
  // あらかじめ用意された値
  m = Matrix3f::Identity();
  std::cout << "m = Matrix3f::Identity();\n" << m << std::endl;
  m = Matrix3f::Zero();
  std::cout << "m = Matrix3f::Zero();\n" << m << std::endl;
  m = Matrix3f::Ones();
  std::cout << "m = Matrix3f::Ones();\n" << m << std::endl;
  m = Matrix3f::Random();
  std::cout << "m = Matrix3f::Random();\n" << m << std::endl;
  m = Matrix3f::Constant(0.25f);
  std::cout << "m = Matrix3f::Constant(0.25f);\n" << m << std::endl;

  // 行列の要素へのアクセス
  // matrix(列, 行)
  // 「行」が横方向のインデックス
  // 「列」が縦方向のインデックス
  // m2[0, 1] や m2[0][1] などの書き方はできない
  m(2, 0) = 1.0f;
  std::cout << "m(2, 0) = 1.0f;\n" << m << std::endl;

  float value = m(0, 2);
  std::cout << "float value = m(0, 2);\n" << value << std::endl;

  Matrix3f m1;
  m1 << 0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f;
  std::cout << "  m1 << 0.0f, 0.0f, 1.0f,         0.0f, 0.0f, 1.0f,         0.0f, 1.0f, 0.0f; \n" << m1 << std::endl;

  // 加算・減算
  Matrix3f m2;
  std::cout << "m\n" << m << std::endl;
  std::cout << "m1\n" << m1 << std::endl;
  m2 = m + m1;
  std::cout << "m2 = m + m1;\n" << m2 << std::endl;
  m2 = m - m1;
  std::cout << "m2 = m - m1;\n" << m2 << std::endl;

  // 乗算・減算
  m2 = m * 2.0f;
  std::cout << "m2 = m * 2.0f;\n" << m2 << std::endl;
  m2 = m / 2.0f;
  std::cout << "m2 = m / 2.0f;\n" << m2 << std::endl;
  
  m = Matrix3f::Random();
  std::cout << "m = Matrix3f::Random();\n" << m << std::endl;
  // 転置行列
  // | a b c |    | a d g |
  // | d e f | -> | b e h |
  // | g h i |    | c f i |
  m2 = m.transpose();
  std::cout << "m2 = m.transpose();\n" << m2 << std::endl;

  // 逆行列
  m2 = m.inverse();
  std::cout << "m2 = m.inverse();\n" << m2 << std::endl;


  // 共役行列
  m2 = m.conjugate();
  std::cout << "m2 = m.conjugate();\n" << m2 << std::endl;

  {
    // 4x4行列の一部を切り取って3x3行列へコピー
    // | a b c d |    | a b c |
    // | e f g h | -> | e f g |
    // | i j k l |    | i j k |
    // | m n o p |
    Matrix4f m_in;
    m_in <<  0.0f,  1.0f,  2.0f,  3.0f,
             4.0f,  5.0f,  6.0f,  7.0f,
             8.0f,  9.0f, 10.0f, 11.0f,
            12.0f, 13.0f, 14.0f, 15.0f;
    std::cout << "m_in = \n" << m_in << std::endl;

    Matrix3f m_out = m_in.block(0, 0, 3, 3);
    std::cout << "Matrix3f m_out = m_in.block(0, 0, 3, 3); \n" << m_out << std::endl;

    // 4x4行列の一部を切り取ってベクトルへコピー
    // | a b c d |
    // | e f g h | -> | g k o |
    // | i j k l |
    // | m n o p |
    Vector3f v_out = m_in.block(1, 2, 3, 1);
    std::cout << "Vector3f v_out = m_in.block(1, 2, 3, 1); \n" << v_out << std::endl;
  }

}