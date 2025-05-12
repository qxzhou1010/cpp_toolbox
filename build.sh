mkdir -p build && cd build

cmake .. || exit


make -j8 || exit

mv compile_commands.json ..