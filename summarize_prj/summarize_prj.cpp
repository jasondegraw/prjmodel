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

#include "model.hpp"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>

std::string sanitize_name(const std::string& in)
{
  return in;
}

std::string zone_summary(prjmodel::Zone& zone)
{
  return std::string();
}

int main(int argc, char* argv[])
{
  prjmodel::IndexModel model(argv[1]);

  std::cout << "Summary of PRJ" << std::endl;
  std::cout << "Number of zones: " << model.zones().size() << std::endl;
  std::cout << "Number of paths: " << model.airflowPaths().size() << std::endl;
  std::cout << "  PL_ORFC: " << model.getAirflowElements<prjmodel::PlrOrf>().size() << std::endl;
  std::cout << " PL_LEAK1: " << model.getAirflowElements<prjmodel::PlrLeak1>().size() << std::endl;
  std::cout << " PL_LEAK2: " << model.getAirflowElements<prjmodel::PlrLeak2>().size() << std::endl;
  std::cout << " PL_LEAK3: " << model.getAirflowElements<prjmodel::PlrLeak3>().size() << std::endl;
  std::cout << "  PL_CONN: " << model.getAirflowElements<prjmodel::PlrConn>().size() << std::endl;
  std::cout << "   PL_QCN: " << model.getAirflowElements<prjmodel::PlrQcn>().size() << std::endl;
  std::cout << "   PL_FCN: " << model.getAirflowElements<prjmodel::PlrFcn>().size() << std::endl;
  std::cout << " PL_TEST1: " << model.getAirflowElements<prjmodel::PlrTest1>().size() << std::endl;
  std::cout << " PL_TEST2: " << model.getAirflowElements<prjmodel::PlrTest2>().size() << std::endl;
  std::cout << " PL_CRACK: " << model.getAirflowElements<prjmodel::PlrCrack>().size() << std::endl;
  std::cout << " PL_STAIR: " << model.getAirflowElements<prjmodel::PlrStair>().size() << std::endl;
  std::cout << " PL_SHAFT: " << model.getAirflowElements<prjmodel::PlrShaft>().size() << std::endl;
  std::cout << "   PL_BDQ: " << model.getAirflowElements<prjmodel::PlrBdq>().size() << std::endl;
  std::cout << "   PL_BDF: " << model.getAirflowElements<prjmodel::PlrBdf>().size() << std::endl;
  std::cout << "  QFR_QAB: " << model.getAirflowElements<prjmodel::QfrQab>().size() << std::endl;
  std::cout << "  QFR_QAF: " << model.getAirflowElements<prjmodel::QfrFab>().size() << std::endl; // Check this one
  std::cout << "QFR_CRACK: " << model.getAirflowElements<prjmodel::QfrCrack>().size() << std::endl;
  std::cout << "QFR_TEST2: " << model.getAirflowElements<prjmodel::QfrTest2>().size() << std::endl;
  std::cout << "  DR_DOOR: " << model.getAirflowElements<prjmodel::AfeDor>().size() << std::endl; // Check this one
  std::cout << "QFR_TEST2: " << model.getAirflowElements<prjmodel::QfrTest2>().size() << std::endl;
  std::cout << "   DR_PL2: " << model.getAirflowElements<prjmodel::DrPl2>().size() << std::endl;
  std::cout << "   FN_CMF: " << model.getAirflowElements<prjmodel::AfeCmf>().size() << std::endl;
  std::cout << "   FN_CVF: " << model.getAirflowElements<prjmodel::AfeCvf>().size() << std::endl;
  std::cout << "   FN_FAN: " << model.getAirflowElements<prjmodel::AfeFan>().size() << std::endl;
  //std::cout << "   CS_FSP: " << model.getAirflowElements<prjmodel::AfeCsf>().size() << std::endl; // Something wonky here
  std::cout << "   CS_QSP: " << model.getAirflowElements<prjmodel::AfeQsp>().size() << std::endl;
  std::cout << "   CS_PSF: " << model.getAirflowElements<prjmodel::AfePsf>().size() << std::endl;
  std::cout << "   CS_PSQ: " << model.getAirflowElements<prjmodel::AfePsq>().size() << std::endl;
  std::cout << "   AF_SUP: " << model.getAirflowElements<prjmodel::AfeSup>().size() << std::endl;

  return EXIT_SUCCESS;
}