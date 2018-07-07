rmdir /q /s build
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX="%CD%" .. -G "Visual Studio 14 2015"
cmake --build . --target INSTALL
