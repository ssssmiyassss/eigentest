// https://qiita.com/kenichi-t/items/57b5a336b20f86f45ebe
// 2021-12-22 16:18:42
#include <iostream>

// Eigenのコア機能とジオメトリ機能を使う
// #include <Eigen/Core>
// #include <Eigen/Geometry>

// header
#include <Eigen/Dense>

int main() {
  //////////////////////
  // 初期化  2021-12-22
  //////////////////////
  Eigen::MatrixXd X1(3, 3);
  X1 << 1, 2, 3, 4, 5, 6, 7, 8, 9;
  std::cout << "\nX1\n" << X1 << std::endl;

  Eigen::MatrixXd X2 = Eigen::MatrixXd::Zero(3, 10);
  std::cout << "\nX2\n" << X2 << std::endl;

  Eigen::MatrixXd X3 = Eigen::MatrixXd::Ones(3, 10);
  std::cout << "\nX3\n" << X3 << std::endl;

  Eigen::MatrixXd X4 = Eigen::MatrixXd::Random(4, 4);
  std::cout << "\nX4\n" << X4 << std::endl;

  Eigen::MatrixXd X5 = Eigen::MatrixXd::Identity(3, 3);
  std::cout << "\nX5\n" << X5 << std::endl;

  //////////////////////
  // resize 2021-12-22
  //////////////////////
  std::cout << "\nresize\n" << std::endl;
  std::cout << "\nX1\n" << X1 << std::endl;
  X1.resize(X1.rows()+1, X1.cols()+1); // 要素を保持しない
  std::cout << "\nX1\n" << X1 << std::endl;

  std::cout << "\nX4\n" << X4 << std::endl;
  X4.conservativeResize(X4.rows()+1, Eigen::NoChange); // 要素を保持する
  std::cout << "\nX4\n" << X4 << std::endl;

  /////////////////
  // 部分行列
  /////////////////
  std::cout << "\n 部分行列\n" << std::endl;
  Eigen::MatrixXd X = Eigen::MatrixXd::Random(6, 6);
  std::cout << "\n X = Eigen::MatrixXd::Random(6, 6);\n" << X << std::endl;

  std::cout << "\n X.row(3)\n" << X.row(3) << std::endl;
  std::cout << "\n X.topRows(2)\n" << X.topRows(2) << std::endl;
  std::cout << "\n X.bottomRows(2)\n" << X.bottomRows(2) << std::endl;

  std::cout << "\n X.col(3)\n" << X.col(3) << std::endl;
  std::cout << "\n X.leftCols(3)\n" << X.leftCols(3) << std::endl;
  std::cout << "\n X.rightCols(2)\n" << X.rightCols(2) << std::endl;

  // 2021-12-22 16:45:19 次ここから。
  // std::cout << X.block(2, 3, 4, 5) << std::endl;
  // std::cout << X.topLeftCorner(2, 3) << std::endl;
  // std::cout << X.topRightCorner(2, 3) << std::endl;
  // std::cout << X.bottomLeftCorner(2, 3) << std::endl;
  // std::cout << X.bottomRightCorner(2, 3) << std::endl;
}