/*
 * Assignment 2 - Developing List Data Structures and Artificial Neural Networks
 * file : main.cpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 26.10.2024

 ! build code :  in PDF

 * run code
    * terminal unit test array list
    !./main test_unit
    !./main test_unit nameFunctionUnitTest
*/

#include "main.hpp"
#include "test\unit_test\heap\unit_test.cpp"
#include "test\unit_test\hash\unit_test.cpp"
#ifdef TEST_HASH
// #include "random_test/hash/random_test.hpp"
#include "unit_test/hash/unit_test.hpp"
const string TEST_CASE = "HASH";
#elif defined(TEST_HEAP)
// #include "random_test/heap/random_test.hpp"
#include "unit_test/heap/unit_test.hpp"
const string TEST_CASE = "HEAP";
#elif defined(TEST_LAYER)
// #include "random_test/heap/random_test.hpp"
#include "unit_test/layer/unit_test.hpp"
const string TEST_CASE = "LAYER";
#elif defined(TEST_LOSS)
// #include "random_test/heap/random_test.hpp"
#include "unit_test/loss/unit_test.hpp"
const string TEST_CASE = "LOSS";
#endif
void printTestCase();

int main(int argc, char *argv[]) {
  // if (argc <= 1) {
  //   printTestCase();
  //   return 1;
  // }

  // std::string arg1 = argv[1];
  // if (arg1 == "test_unit") {
  //   std::cout << GREEN << BOLD << "Running unit_test/" << TEST_CASE << RESET
  //             << "\n";
  //   handleTestUnit(argc, argv);
  // } else if (arg1 == "test_random") {
  //   std::cout << GREEN << BOLD << "Running test_random/" << TEST_CASE << RESET
  //             << "\n";
  //   handleTestRandom(argc, argv);
  // } else {
  //   printTestCase();
  // }
  string name = "hash38";
  //! data ------------------------------------

  xMap<string, int *> hash(&String_keyHash, 0.2, &newINT_EQ, xMap<string, int *>::freeValue, nullptr, nullptr);

  hash.put("key1", new int(0));
  hash.put("key2", new int(0));
  hash.put("key3", new int(0));
  hash.put("key4", new int(0));
  hash.put("key5", new int(9));
  hash.put("key6", new int(0));
  hash.put("key7", new int(0));
  hash.put("key8", new int(12));
  hash.put("key9", new int(0));
  hash.put("key10", new int(0));
  hash.put("key11", new int(10));
  hash.put("key12", new int(0));

  //! hash2
  cout << hash.toString() << endl;
  xMap<string, int *> hash2 = hash;
  cout << hash2.toString() << endl;
  //! operator =
  hash2 = hash2;
  cout << hash2.toString() << endl;

  //! expect ----------------------------------
  string expect = "1\n1\n1\n0\nsize : 12\n";

  //! output ----------------------------------
  stringstream output;
  output << hash2.containsKey("key1") << endl;
  output << hash2.containsKey("key12") << endl;
  int *tmp = new int(10);
  int *tmp1 = new int(-1);
  output << hash2.containsValue(tmp) << endl;
  output << hash2.containsValue(tmp1) << endl;
  output << "size : " << hash2.size() << endl;
  delete tmp;
  delete tmp1;

  cout << "output: " << output.str() << endl;
  cout << "expect: " << expect << endl;
  if (output.str() == expect) {
    cout << GREEN << BOLD << "PASS" << RESET << endl;
  } else {
    cout << RED << BOLD << "FAIL" << RESET << endl;
  }
  return 0;
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
#elif TEST_LAYER
void handleTestUnit(int argc, char *argv[]) {
  UNIT_TEST_Layer unitTest;

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
#elif TEST_LOSS
void handleTestUnit(int argc, char *argv[]) {
  UNIT_TEST_Loss unitTest;

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