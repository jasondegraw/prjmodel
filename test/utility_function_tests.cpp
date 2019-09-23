// Copyright (c) 2019, Jason W. DeGraw. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
// following conditions are met:
//
// (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
// disclaimer.
//
// (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
// disclaimer in the documentation and/or other materials provided with the distribution.
//
// (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote products
// derived from this software without specific prior written permission from the respective party.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) AND ANY CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER(S), ANY CONTRIBUTORS, THE UNITED STATES GOVERNMENT, OR THE UNITED
// STATES DEPARTMENT OF ENERGY, NOR ANY OF THEIR EMPLOYEES, BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
// USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

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