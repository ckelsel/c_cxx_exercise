cd build
cmake --build . --target INSTALL
if errorlevel 1 (
   echo !!! build failed !!!
   goto end
)
::ctest -VV
bin\\_test.exe

:end