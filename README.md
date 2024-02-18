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
binfile=build/cpp_hw,srcfile=/home/itrooz/ram/libbacktrace-hw/main.cpp,function=showStacktrace(),line=16
binfile=build/cpp_hw,srcfile=/home/itrooz/ram/libbacktrace-hw/main.cpp,function=baz(),line=38
binfile=build/cpp_hw,srcfile=/usr/include/c++/13.2.1/bits/invoke.h,function=void std::__invoke_impl<void, void (*&)()>(std::__invoke_other, void (*&)()),line=61
binfile=build/cpp_hw,srcfile=/usr/include/c++/13.2.1/bits/invoke.h,function=std::enable_if<is_invocable_r_v<void, void (*&)()>, void>::type std::__invoke_r<void, void (*&)()>(void (*&)()),line=111
binfile=build/cpp_hw,srcfile=/usr/include/c++/13.2.1/bits/std_function.h,function=std::_Function_handler<void (), void (*)()>::_M_invoke(std::_Any_data const&),line=290
binfile=build/cpp_hw,srcfile=/usr/include/c++/13.2.1/bits/std_function.h,function=std::function<void ()>::operator()() const,line=591
binfile=build/cpp_hw,srcfile=/home/itrooz/ram/libbacktrace-hw/main.cpp,function=bar(),line=43
binfile=build/cpp_hw,srcfile=/home/itrooz/ram/libbacktrace-hw/main.cpp,function=foo(),line=47
binfile=build/cpp_hw,srcfile=/home/itrooz/ram/libbacktrace-hw/main.cpp,function=main,line=52
binfile=/usr/lib/libc.so.6,srcfile=??,function=??,line=0
binfile=/usr/lib/libc.so.6,srcfile=??,function=??,line=0
binfile=build/cpp_hw,srcfile=??,function=??,line=0
binfile=(null),srcfile=??,function=??,line=0
```

Source: https://github.com/WerWolv/ImHex/blob/ff48d37598977af777a3b9b85511d25ea8749784/main/gui/source/stacktrace.cpp