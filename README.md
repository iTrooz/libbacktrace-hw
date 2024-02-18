Example for libbacktrace

Working as of 2023-02-18 on Arch Linux

How I run it (feel free to adapt rather than just copy/paste)
```sh
vcpkg install libbacktrace
cmake -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
cmake --build build
build/cpp_hw
```

Source: https://github.com/WerWolv/ImHex/blob/ff48d37598977af777a3b9b85511d25ea8749784/main/gui/source/stacktrace.cpp