#if defined(__clang__) && defined(__linux__)
#define CATCH_CONFIG_NO_CPP17_UNCAUGHT_EXCEPTIONS
#endif
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "utility_functions.hpp"

TEST_CASE("Test string splitting", "[split]")
{
  std::string str("This  is a test ");

  auto result = split(str, ' ', true);
  REQUIRE(result.size() == 6);
  CHECK(result[0] == "This");
  CHECK(result[1] == "");
  CHECK(result[2] == "is");
  CHECK(result[3] == "a");
  CHECK(result[4] == "test");
  CHECK(result[5] == "");

  result = split(str, ' ');
  REQUIRE(result.size() == 4);
  CHECK(result[0] == "This");
  CHECK(result[1] == "is");
  CHECK(result[2] == "a");
  CHECK(result[3] == "test");

  result = split(str, true);
  REQUIRE(result.size() == 6);
  CHECK(result[0] == "This");
  CHECK(result[1] == "");
  CHECK(result[2] == "is");
  CHECK(result[3] == "a");
  CHECK(result[4] == "test");
  CHECK(result[5] == "");

  result = split(str);
  REQUIRE(result.size() == 4);
  CHECK(result[0] == "This");
  CHECK(result[1] == "is");
  CHECK(result[2] == "a");
  CHECK(result[3] == "test");

  std::string str2("This \tis\na test ");

  result = split(str2, true);
  REQUIRE(result.size() == 6);
  CHECK(result[0] == "This");
  CHECK(result[1] == "");
  CHECK(result[2] == "is");
  CHECK(result[3] == "a");
  CHECK(result[4] == "test");
  CHECK(result[5] == "");

  result = split(str2);
  REQUIRE(result.size() == 4);
  CHECK(result[0] == "This");
  CHECK(result[1] == "is");
  CHECK(result[2] == "a");
  CHECK(result[3] == "test");
}