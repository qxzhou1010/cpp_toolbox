mkdir -p build && cd build

cmake .. || exit


make -j8 || exit

./alltest