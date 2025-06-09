# C++ 静态库与动态库

## Static Library

```bash
# 创建静态库
g++ -c func1.cpp func2.cpp
ar rcs libfunc.a func1.o func2.o

# 使用静态库
g++ -o hello main.cpp -I./include -L./lib -lfunc
```

## Shared Library

```bash
# 创建动态库
g++ -fpic -c func1.cpp func2.cpp
g++ -shared func1.o func2.o -o libfunc.so

# 使用动态库
g++ -o hello main.cpp -I./include -L./lib -lfunc
```
