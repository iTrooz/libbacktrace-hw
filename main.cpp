#include<stdio.h>
#include<filesystem>
#include<functional>

#include<llvm/Demangle/Demangle.h>
#include<backtrace.h>

static char* exec_path;

void showStacktrace() {
    auto backtraceState = backtrace_create_state(exec_path, 1, [](void *, const char *msg, int) { printf("%s\n", msg); }, nullptr);

    // backtrace_print(backtraceState, 0, stdout);

    backtrace_full(backtraceState, 0, [](void *, uintptr_t, const char *fileName, int lineNumber, const char *function) -> int {
        if (fileName == nullptr)
            fileName = "??";
        if (function == nullptr)
            function = "??";
        
        printf("file=%s,function=%s,line=%d\n",
            fileName,
            llvm::demangle(function).c_str(),
            lineNumber
        );

        return 0;
    }, nullptr, nullptr);
}

void baz() {
    showStacktrace();
}

void bar() {
    std::function<void(void)> func = baz;
    func();
}

void foo() {
    bar();
}

int main(int argc, char *argv[]){
    exec_path = argv[0];
    foo();
}
