# 📘 Makefile 使用笔记

Makefile 是用于管理项目工程构建的文件，配合 `make` 命令使用。执行 `make` 时，系统会解析并执行当前目录下的 `Makefile` 或 `makefile` 文件。

---

## 📌 Makefile 基本语法

```makefile
目标: 依赖
<TAB>命令
```

- **目标**：要生成的目标文件
- **依赖**：目标文件所依赖的源文件
- **命令**：生成目标所需执行的命令（注意前面必须是 Tab）

---

## ⚙️ 常用变量

| 变量名    | 说明               |
|-----------|--------------------|
| `CC`      | 指定编译器，如 `gcc` 或 `g++` |
| `CPPFLAGS`| C 预处理选项（如 `-I`） |
| `CFLAGS`  | 编译选项（如 `-Wall -g -c`） |
| `LDFLAGS` | 链接选项（如 `-L`） |

---

## 🔁 自动变量

| 自动变量 | 含义                     |
|----------|--------------------------|
| `$@`     | 当前规则中的目标文件名     |
| `$<`     | 第一个依赖文件             |
| `$^`     | 所有依赖文件（去重，空格分隔） |

---

## 🔧 常用函数

### `wildcard`：查找匹配文件

```makefile
src := $(wildcard *.cpp)
# 找出当前目录下所有 .cpp 文件
```

### `patsubst`：模式替换

```makefile
obj := $(patsubst %.cpp, %.o, $(src))
# 将 .cpp 替换成 .o，生成目标对象文件名
```

---

## 🧹 清理规则

```makefile
.PHONY: clean
clean:
    rm -f *.o
```

- `.PHONY`：声明 `clean` 是伪目标，不对应实际文件
- 使用 `make clean` 清理所有中间产物

---

## 🗂️ 使用自定义 Makefile 文件

```bash
make -f mainfile
```

使用 `-f` 指定一个自定义文件名作为 makefile。
