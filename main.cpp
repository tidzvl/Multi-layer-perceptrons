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
  string name = "hash30";
  //! data ------------------------------------
  xMap<int*, int*> hash(&newINT_keyHash, 1, &newINT_EQ,
                        xMap<int*, int*>::freeKey, &newINT_EQ,
                        xMap<int*, int*>::freeValue);
  int* key1 = new int(1);
  int* key11 = new int(11);
  int* key21 = new int(21);
  int* key31 = new int(31);
  int* key41 = new int(41);
  int* key51 = new int(51);
  int* key61 = new int(61);
  int* key2 = new int(2);
  int* key3 = new int(1);

  int* value1 = new int(100);
  int* value11 = new int(200);
  int* value21 = new int(300);
  int* value31 = new int(400);
  int* value41 = new int(500);
  int* value51 = new int(600);
  int* value61 = new int(700);
  int* value2 = new int(800);
  int* value3 = new int(900);

  hash.put(key1, value1);
  hash.put(key11, value11);
  hash.put(key21, value21);
  hash.put(key31, value31);
  hash.put(key41, value41);
  hash.put(key51, value51);
  hash.put(key61, value61);
  hash.put(key2, value2);
  hash.put(key3, value3);

  hash.remove(key61, &newINT_delete);
  hash.remove(key31, value31, &newINT_delete, &newINT_delete);
  xMap<int*, int*> copy = hash;
  copy.clear();
  cout << "asdsa " << endl;

  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       0\n\
0   : \n\
1   : \n\
2   : \n\
3   : \n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  hash.clear();
  output << "\n" << hash.toString(&newINT_toString, &newINT_toString);
  //! remove data -----------------------------
  delete value1;
  delete key3;
  delete value61;

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