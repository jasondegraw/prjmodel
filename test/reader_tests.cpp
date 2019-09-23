// OpenStudio(R), Copyright (c) 2008-2019, Alliance for Sustainable Energy, LLC, and other contributors
// Copyright (c) 2019, Jason W. DeGraw
// All rights reserved.
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
// (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative works
// may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without specific prior
// written permission from Alliance for Sustainable Energy, LLC.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) AND ANY CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER(S), ANY CONTRIBUTORS, THE UNITED STATES GOVERNMENT, OR THE UNITED
// STATES DEPARTMENT OF ENERGY, NOR ANY OF THEIR EMPLOYEES, BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
// USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "catch.hpp"
#include "reader.hpp"

TEST_CASE("Test basic reading", "[Reader]")
{
  std::string txt{ " 1.47921e-007 0.000998165 0.65 75 0.0181269 0 4\n9 23 plr_test1 FloorLeaky\n\n 3.1045e-007" };

  prjmodel::Reader reader(txt, 0);

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