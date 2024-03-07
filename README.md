# leetForCpp

## CMakeLists.txt
```c++
cmake_minimum_required(VERSION 3.25)
project(leetForCpp)

set(CMAKE_CXX_STANDARD 11)

#boost库
set(BOOST_ROOT "/opt/homebrew/Cellar/boost/1.81.0_1/include/boost")
include_directories(/opt/homebrew/Cellar/boost/1.81.0_1/include)
link_directories(/opt/homebrew/Cellar/boost/1.81.0_1/lib)

#pcre++库
set(PCRE "/opt/homebrew/Cellar/pcre/8.45/include/*")
include_directories(/opt/homebrew/Cellar/pcre/8.45/include)
link_directories(/opt/homebrew/Cellar/pcre/8.45/lib)

add_executable(leetForCpp main.cpp)
```

## C++ 标准库中，共有以下几种常用的容器：
```log
1.顺序容器（Sequence Containers）：按顺序存储元素，包括：
    std::vector：动态数组，支持随机访问。
    std::deque：双端队列，支持在两端高效插入和删除元素。
    std::list：双向链表，支持在任意位置高效插入和删除元素。
    std::forward_list：单向链表，只支持从头部插入和删除元素，适用于对内存要求苛刻的场景。
2.关联容器（Associative Containers）：根据键值快速查找元素，包括：
    std::set：基于红黑树实现的集合，元素按照键值自动排序，不允许重复。
    std::multiset：与 std::set 类似，但允许重复元素。
    std::map：基于红黑树实现的映射表，键值对按照键值自动排序，不允许重复的键。
    std::multimap：与 std::map 类似，但允许重复的键。
3.无序容器（Unordered Containers）：基于哈希表实现，元素无序存储，但支持快速查找，包括：
    std::unordered_set：基于哈希表的集合，元素无序存储，不允许重复。
    std::unordered_multiset：与 std::unordered_set 类似，但允许重复元素。
    std::unordered_map：基于哈希表的映射表，键值对无序存储，不允许重复的键。
    std::unordered_multimap：与 std::unordered_map 类似，但允许重复的键。
4.适配器容器（Adapter Containers）：基于其他容器提供不同接口或限制，包括：
    std::stack：栈，基于 deque、list 或 vector 实现。
    std::queue：队列，基于 deque 或 list 实现。
    std::priority_queue：优先队列，基于 vector 实现。
```

## unique函数 与 erase函数
```log
unique()
    1.  template< class ForwardIt >
        ForwardIt unique( ForwardIt first, ForwardIt last );
        第一个版本接受两个迭代器参数 first 和 last，表示要去重的范围是 [first, last)，返回一个新的尾部迭代器，指向去重后的范围的尾部(最后一个的下一个元素)。
    2.  template< class ForwardIt, class BinaryPredicate >
        ForwardIt unique( ForwardIt first, ForwardIt last, BinaryPredicate p );
        第二个版本还接受一个二元谓词 p，用于自定义去重的判定条件。
erase()
    1.  iterator erase(const_iterator pos);
        erase 函数接受一个迭代器参数 pos，表示要删除的元素的位置，返回一个迭代器，指向被删除元素的后一个元素（如果存在）或容器的 end()。
    2.  iterator erase(const_iterator first, const_iterator last);
        erase 函数接受两个迭代器参数 first 和 last，表示要删除的元素范围，返回一个迭代器，指向被删除元素的后一个元素（如果存在）或容器的 end()。
    3.  iterator erase(Iterator first, Iterator last, Predicate pred);
        erase 函数接受三个参数，first 和 last 表示要删除的元素范围，pred 是一个谓词函数，用于指定删除条件。这个版本通常与 std::remove_if 算法一起使用，结合起来可以删除容器中满足特定条件的元素。
```