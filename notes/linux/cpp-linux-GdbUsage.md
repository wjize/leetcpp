# GDB 调试简明笔记

## 编译带调试信息

```bash
g++ -g main.cpp -o a.out
```

## 启动 GDB

```bash
gdb ./a.out
```

## 常用命令

```bash
b 行号/函数名    # 设置断点
run              # 启动程序
start            # 从头单步执行
cont             # 继续执行
print var        # 打印变量
list             # 查看源代码
bt               # 查看调用栈
set var x = 10   # 修改变量值
```
