#include "catch.hpp"
#include "reader.hpp"

TEST_CASE("Test basic reading", "[Reader]")
{
  std::string txt{ " 1.47921e-007 0.000998165 0.65 75 0.0181269 0 4\n9 23 plr_test1 FloorLeaky\n\n 3.1045e-007" };

  prjmodel::Reader reader(txt);

  CHECK(reader.readString() == "1.47921e-007");
  CHECK(reader.readDouble() == 0.000998165);
  CHECK(reader.readString() == "0.65");
  CHECK(reader.readInt() == 75);
  //CHECK(reader.readString() == "0.0181269");
  CHECK(reader.readNumber<std::string>() == "0.0181269");
  //CHECK(reader.readNumber<double>() == 0.0181269);
  CHECK(reader.readString() == "0");
  CHECK(reader.readString() == "4");
  CHECK(reader.readInt() == 9);
  CHECK(reader.readInt() == 23);
  CHECK(reader.readString() == "plr_test1");
  CHECK(reader.readString() == "FloorLeaky");
  CHECK(reader.readLine() == "");
  CHECK(reader.readString() == "3.1045e-007");

  
}