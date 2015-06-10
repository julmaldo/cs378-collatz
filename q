sudo: required
language: cpp

compiler: gcc

before_install:
    - sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
    - sudo apt-get update

install:
    - sudo apt-get install clang-3.4
    - sudo apt-get install g++-4.8
    - sudo apt-get install libgtest-dev
    - cd /usr/src/gtest
    - sudo cmake .
    - sudo make
    - sudo mv libg* /usr/local/lib/
    - cd -
    - sudo apt-get install libboost-all-dev
    - sudo apt-get install valgrind
    - sudo apt-get install doxygen

before_script:
    - uname -a
    - printenv
    - clang++ --version 2>&1 | grep clang
    - g++-4.8 --version 2>&1 | grep g++-4.8
    - dpkg -l libgtest-dev | grep libgtest
    - gcov-4.6 --version | grep gcov
    - gcov-4.8 --version | grep gcov
    - valgrind --version
    - grep "#define BOOST_VERSION " /usr/include/boost/version.hpp
    - doxygen --version

script:
    - date
    - ls -al
    - make Collatz.log
    - make collatz-tests
    - ls -al
    - make html
    - ls -al
    - make test
    - make clean
    - make test CXX=clang++
    - ls -al
    - make check
