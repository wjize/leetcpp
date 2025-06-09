# 📘 Linux 进程相关概念

---

## 📄 程序与进程

- **程序**：编译好的二进制文件（静态文件）
- **进程**：程序的运行实例，是程序从开始运行到结束的整个过程

---

## 🔁 并发与并行

- **并发**（Concurrency）：一个 CPU 同时运行多个进程，每个进程分配一个时间片轮流执行
- **并行**（Parallelism）：多个 CPU 核心在同一时刻真正同时执行多个进程

---

## 🧱 PCB - 进程控制块（Process Control Block）

- 每个进程在内核中都有一个 PCB，用于保存该进程的所有状态信息
- 本质是一个结构体

---

## 👶 fork 函数

- 创建子进程的函数：

  ```cpp
  pid_t fork(void);
  ```

- 父子进程不共享全局变量（写时复制，读时共享）

---

## 🚀 exec 函数族（替换当前进程映像）

用于加载并执行新程序，执行后新程序替换当前进程，当前进程的后续代码不会执行。

### 📚 函数原型与说明

```cpp
int execl(const char *path, const char *arg0, ... /* (char *) NULL */);
// 示例：
execl("/bin/ls", "ls", "-l", NULL);
```

```cpp
int execv(const char *path, char *const argv[]);
// 示例：
char *args[] = {"ls", "-l", NULL};
execv("/bin/ls", args);
```

```cpp
int execle(const char *path, const char *arg0, ..., char *const envp[]);
// 示例：
char *env[] = {"PATH=/usr/bin", NULL};
execle("/bin/ls", "ls", "-l", NULL, env);
```

```cpp
int execve(const char *path, char *const argv[], char *const envp[]);
// 示例：
char *args[] = {"ls", "-l", NULL};
char *env[] = {"PATH=/usr/bin", NULL};
execve("/bin/ls", args, env);
```

```cpp
int execlp(const char *file, const char *arg0, ... /* (char *) NULL */);
// 示例：
execlp("ls", "ls", "-l", NULL);
```

```cpp
int execvp(const char *file, char *const argv[]);
// 示例：
char *args[] = {"ls", "-l", NULL};
execvp("ls", args);
```

---

## 👻 孤儿进程（Orphan Process）

- 父进程已终止，子进程仍在运行
- 系统将该子进程的父进程设置为 `init`（PID=1）
- 状态信息将由 `init` 进程回收

---

## 🧟 僵尸进程（Zombie Process）

- 子进程结束后，父进程没有调用 `wait()` 进行回收
- 会保留在进程表中，占用 PID 和其他资源
- 应该通过 `wait()` 或 `waitpid()` 及时回收子进程资源

---

## 🔚 子进程回收函数

### `wait()`

```cpp
int wait(int *status);
```

- 阻塞等待任一子进程退出，返回其 PID
- 可通过宏判断子进程状态：
  - `WIFEXITED`, `WIFSIGNALED`, `WIFSTOPPED`

### `waitpid()`

```cpp
int waitpid(pid_t pid, int *status, int options);
```

- 可以指定等待哪个子进程
- 支持非阻塞或获取停止状态

#### 常用选项

| 选项        | 说明                   |
|-------------|------------------------|
| `WNOHANG`   | 不阻塞，无子进程退出立即返回 |
| `WUNTRACED` | 获取停止状态的子进程       |
