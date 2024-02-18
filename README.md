Example for libbacktrace

Working as of 2023-02-18 on Arch Linux

How I run it (feel free to adapt rather than just copy/paste)
```sh
vcpkg install libbacktrace
cmake -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
cmake --build build
build/cpp_hw
```

Output for me:
```
file=/home/itrooz/ram/cpp-hw/main.cpp,function=showStacktrace(),line=15
file=/home/itrooz/ram/cpp-hw/main.cpp,function=baz(),line=32
file=/usr/include/c++/13.2.1/bits/invoke.h,function=void std::__invoke_impl<void, void (*&)()>(std::__invoke_other, void (*&)()),line=61
file=/usr/include/c++/13.2.1/bits/invoke.h,function=std::enable_if<is_invocable_r_v<void, void (*&)()>, void>::type std::__invoke_r<void, void (*&)()>(void (*&)()),line=111
file=/usr/include/c++/13.2.1/bits/std_function.h,function=std::_Function_handler<void (), void (*)()>::_M_invoke(std::_Any_data const&),line=290
file=/usr/include/c++/13.2.1/bits/std_function.h,function=std::function<void ()>::operator()() const,line=591
file=/home/itrooz/ram/cpp-hw/main.cpp,function=bar(),line=37
file=/home/itrooz/ram/cpp-hw/main.cpp,function=foo(),line=41
file=/home/itrooz/ram/cpp-hw/main.cpp,function=main,line=46
file=??,function=??,line=0
file=??,function=??,line=0
file=??,function=??,line=0
file=??,function=??,line=0
```

Source: https://github.com/WerWolv/ImHex/blob/ff48d37598977af777a3b9b85511d25ea8749784/main/gui/source/stacktrace.cpp