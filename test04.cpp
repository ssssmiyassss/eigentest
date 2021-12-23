// https://qiita.com/kenichi-t/items/57b5a336b20f86f45ebe
// 2021-12-22 16:18:42
#include <iostream>

// Eigenのコア機能とジオメトリ機能を使う
// #include <Eigen/Core>
// #include <Eigen/Geometry>

// header
#include <Eigen/Dense>

// for std::mt19937
#include <random>

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

  ///////////////////////
  // 部分行列 2021-12-22
  ///////////////////////
  std::cout << "\n 部分行列\n" << std::endl;
  Eigen::MatrixXd X = Eigen::MatrixXd::Random(6, 6);
  std::cout << "\n X = Eigen::MatrixXd::Random(6, 6);\n" << X << std::endl;
  std::cout << "\n X.row(3)\n" << X.row(3) << std::endl;
  std::cout << "\n X.topRows(2)\n" << X.topRows(2) << std::endl;
  std::cout << "\n X.bottomRows(2)\n" << X.bottomRows(2) << std::endl;

  std::cout << "\n X = Eigen::MatrixXd::Random(6, 6);\n" << X << std::endl;
  std::cout << "\n X.col(3)\n" << X.col(3) << std::endl;
  std::cout << "\n X.leftCols(3)\n" << X.leftCols(3) << std::endl;
  std::cout << "\n X.rightCols(2)\n" << X.rightCols(2) << std::endl;

  std::cout << "\n X = Eigen::MatrixXd::Random(6, 6);\n" << X << std::endl;
  std::cout << "\n X.block(1, 1, 2, 2)\n" << X.block(1, 1, 2, 2) << std::endl;
  std::cout << "\n X.topLeftCorner(2, 2)\n" << X.topLeftCorner(2, 2) << std::endl;
  std::cout << "\n X.topRightCorner(2, 2)\n" << X.topRightCorner(2, 2) << std::endl;

  std::cout << "\n X = Eigen::MatrixXd::Random(6, 6);\n" << X << std::endl;
  std::cout << "\n X.bottomLeftCorner(2, 2)\n" << X.bottomLeftCorner(2, 2) << std::endl;
  std::cout << "\n X.bottomLeftCorner(3, 3)\n" << X.bottomLeftCorner(3, 3) << std::endl;
  std::cout << "\n X.bottomRightCorner(2, 2)\n" << X.bottomRightCorner(2, 2) << std::endl;
  std::cout << "\n X.bottomRightCorner(3, 3)\n" << X.bottomRightCorner(3, 3) << std::endl;

  ///////////////////////////////////////
  // 行をランダムにシャッフル 2021-12-23
  ///////////////////////////////////////
  X = Eigen::MatrixXd::Random(6, 8);
  std::cout << "\n X = Eigen::MatrixXd::Random(6, 8);\n" << X << std::endl;

  // 置換行列を作成（各列と各行に唯一つの非ゼロ成分を持つ行列）
  Eigen::PermutationMatrix<Eigen::Dynamic, Eigen::Dynamic> perm_row(X.rows());

  // 対角要素に1をセット
  perm_row.setIdentity();
  // std::cout << "\n perm_row.setIdentity();\n" << perm_row.setIdentity(); << std::endl;

  // 置換行列をシャッフル
  std::shuffle(perm_row.indices().data(), perm_row.indices().data() + perm_row.indices().size(), std::mt19937());

  // 左からかける
  Eigen::MatrixXd random_row_X = perm_row * X;
  std::cout << "\n Eigen::MatrixXd random_row_X = perm_row * X;\n" << random_row_X << std::endl;

  // 元に戻す
  std::cout << "\n perm_row.inverse() * random_row_X\n" << perm_row.inverse() * random_row_X << std::endl;

  //////////////////////////
  // queryとの距離で行をソート
  //////////////////////////
  X = Eigen::MatrixXd::Random(6, 3);
  Eigen::RowVectorXd query = Eigen::RowVectorXd::Random(3);
  std::cout << "\n X = Eigen::MatrixXd::Random(6, 3); \n" << X << std::endl;
  std::cout << "\n Eigen::RowVectorXd query = Eigen::RowVectorXd::Random(3);" << std::endl << query << std::endl;

  // 距離計算
  Eigen::VectorXd distance = (X.rowwise() - query).rowwise().norm();
  std::cout << "\nEigen::VectorXd distance = (X.rowwise() - query).rowwise().norm();\n" << distance << std::endl;

  // // 置換行列を作成（各列と各行に唯一つの非ゼロ成分を持つ行列）
  // Eigen::PermutationMatrix<Eigen::Dynamic, Eigen::Dynamic> perm_row(X.rows());

  // // 対角要素に1をセット
  // perm_row.setIdentity();
  // std::cout << "sorter_row" << std::endl << perm_row.toDenseMatrix() << std::endl;

  // // 置換行列を距離でソート
  // std::sort(perm_row.indices().data(), perm_row.indices().data() + perm_row.indices().size(),
  //       [&distance](size_t i1, size_t i2) {return distance(i1) < distance(i2);});
  // std::cout << "perm_row" << std::endl << perm_row.toDenseMatrix() << std::endl;

  // // 転置して左からかける
  // Eigen::MatrixXd sorted_X = perm_row.transpose() * X;
  // std::cout << "sorted_X" << std::endl << sorted_X << std::endl;

  // // 元に戻す
  // std::cout << "sorted_X" << std::endl << perm_row.transpose().inverse() * sorted_X << std::endl;

  return 0;
}