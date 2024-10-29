/*
 * Assignment 2 - Developing List Data Structures and Artificial Neural Networks
 * file : main.cpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 17.10.2024

 ! build code :     g++ -fsanitize=hashress -fsanitize=undefined -std=c++17
    -o main -Iinclude -Itest -Isrc
    main.cpp
    test/unit_test/hash/unit_test.cpp
    test/unit_test/heap/unit_test.cpp src/hash/hash.cpp src/heap/heap.cpp
 -DTEST_HASH

 * run code
    * terminal unit test array list
    !./main test_unit
    !./main test_unit nameFunctionUnitTest
*/

#include "main.hpp"
#include "F:\DSA2\ASS2\template\test\unit_test\hash\unit_test.cpp"
#include "F:\DSA2\ASS2\template\test\unit_test\hash\unit_test.hpp"
#include "F:\DSA2\ASS2\Multi-layer-perceptrons\test\unit_test\heap\unit_test.hpp"
#include "F:\DSA2\ASS2\template\include\list\DLinkedList.h"
#include "F:\DSA2\ASS2\template\include\list\XArrayList.h"
#ifdef TEST_HASH
// #include "random_test/hash/random_test.hpp"
#include "unit_test/hash/unit_test.hpp"
const string TEST_CASE = "HASH";
#elif defined(TEST_HEAP)
// #include "random_test/heap/random_test.hpp"
#include "unit_test/heap/unit_test.hpp"
const string TEST_CASE = "HEAP";
#endif
void printTestCase();

int main(int argc, char *argv[]) {
  string name = "heap01";
  //! data ------------------------------------
  Heap<int> heap;

  //! expect ----------------------------------
  string expect = "size=0;empty=1;[]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //output
  cout<< "output : " << output.str() << endl;
  cout << "expect : " << expect << endl;
  if(expect == output.str()) {
    cout << "test " + name + " --------------- PASS" <<"\n";
  } else {
    cout << "test " + name + " --------------- FAIL" << "\n";
  }
}

#ifdef TEST_HASH
void handleTestUnit(int argc, char *argv[]) {
  UNIT_TEST_Hash unitTest;

  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    unitTest.runAllTests();
  } else if (argc == 3) {
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}

void handleTestRandom(int argc, char *argv[]) {
  // HEAPMIT CODE
}
#elif TEST_HEAP
void handleTestUnit(int argc, char *argv[]) {
  UNIT_TEST_Heap unitTest;

  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    std::cout << "Running all unit tests array: ----------\n";
    unitTest.runAllTests();
  } else if (argc == 3) {
    std::cout << "Running unit test array: " << argv[2] << " ----------\n";
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}

void handleTestRandom(int argc, char *argv[]) {
  // HEAPMIT CODE
}
#endif

void printTestCase() {
  std::cout << GREEN << BOLD << "terminal unit test" << RESET << std::endl;
  std::cout << RED << "./main test_unit" << RESET << std::endl;
  std::cout << RED << "./main test_unit nameFunctionUnitTest" << RESET
            << std::endl
            << std::endl;

  // std::cout << GREEN << BOLD << "terminal auto test" << RESET << std::endl;
  // std::cout << RED << "./main test_random number_1 number_2" << RESET
  //           << std::endl;
  // std::cout << RED << "./main test_random number" << RESET << std::endl;
}