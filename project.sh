#!/bin/bash


TYPE="$1"
PROJECT_PATH=$(pwd)
BUILD=${PROJECT_PATH}/install

function init() {
  echo "Initializing project structure..."

  # 创建 build/ 目录
  if [ ! -d "build" ]; then
    mkdir build
    echo "Created build/ directory"
  else
    echo "build/ already exists, skipping"
  fi

  # 创建 test/main.cpp 文件
  if [ ! -f "test/main.cpp" ]; then
    mkdir -p test
    cat <<EOF > test/main.cpp
#include <iostream>
using namespace std;

int main() {

    cout << "Hello, LeetCode!" << endl;
    
    return 0;
}
EOF
    echo "Created test/main.cpp file"
  else
    echo "test/main.cpp already exists, skipping"
  fi

  echo "Initialization completed."
}

function build() {
    if [ ! -d "build" ]; then
        init
    fi
    cd build || exit

    if ! cmake -DCMAKE_INSTALL_PREFIX="${BUILD}" ..; then
        echo "cmake configuration failed, cleanning up build directory."
        cd ..
        rm -rf build
        exit 1
    fi

    cd ..
}

function clean() {
    if [ -d "build" ]; then
        rm -rf build
    fi
    if [ -d "install" ]; then
        rm -rf install
    fi
}

function main() {
    case "$TYPE" in
        "init")
            init
            ;;
        "build")
            build
            ;;
        "clean")
            clean
            ;;
        *)
            echo "Invalid parameter: $TYPE, Usage: ./project.sh [init|build|clean]"
            ;;
    esac
}

main