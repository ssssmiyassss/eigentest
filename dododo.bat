
set EIGEN_INCLUDE=c:\\eigen\\include\\eigen3

:: 2021-12-17 16:14:28
cl /openmp test01.cpp -I%EIGEN_INCLUDE%

:: 2021-12-17 17:19:39
cl /openmp test02.cpp -I%EIGEN_INCLUDE%

:: 2021-12-17 17:19:39
cl /openmp test03.cpp -I%EIGEN_INCLUDE%

test01.exe
test02.exe
test03.exe

:: 2021-12-22 16:20:43
cl /openmp test04.cpp -I%EIGEN_INCLUDE%
test04.exe

:: 2022-06-10 16:51:13
cl /openmp quaternion01.cpp -I%EIGEN_INCLUDE%
quaternion01.exe > hoge
