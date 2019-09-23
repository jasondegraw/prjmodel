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

  auto afe = model.airflowElements();
  // Build name tables to preserve the index-name relationship
  std::unordered_map<int, std::string> afe_lookup;
  int count = 1;
  for (auto& path : model.airflowPaths()) {
    int id = path.pe();
    if (id < 1) {
      std::cout << path.nr() << ": Negative or zero ID" << std::endl;
      continue;
    }
    if (id > afe.size()) {
      std::cout << "ID out of range" << std::endl;
      continue;
    }
    afe_lookup[id] = afe[id]->name();
    std::cout << count << ' ' << id << ' ' << afe[id]->name() << std::endl;
    ++count;
  }

  // Write out XML
  std::ofstream xml("out.xml");
  if (!xml.is_open()) {
    return EXIT_FAILURE;
  }
  xml << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
  xml << "<AirflowNetwork xmlns=\"http://github.com/jasondegraw/AirflowNetwork\"" << std::endl;
  xml << "                xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"" << std::endl;
  xml << "                xsi:schemaLocation=\"http://github.com/jasondegraw/AirflowNetwork airflownetwork.xsd\">" << std::endl;

  if (model.airflowElements().size() > 0) {
    xml << "  <Elements>" << std::endl;
    for (auto& element : model.getAirflowElements<prjmodel::PlrTest1>()) {
      xml << "    <PowerLaw ID=\"" << sanitize_name(element.name()) << "\">" << std::endl;
      if (!element.desc().empty()) {
        xml << "      <Description>" << element.desc() << "</Description>" << std::endl;
      }
      xml << "      <FlowBasis>Mass</FlowBasis>" << std::endl;
      xml << "      <Coefficient>" << element.turb<std::string>() << "</Coefficient>" << std::endl;
      xml << "      <LaminarCoefficient>" << element.lam<std::string>() << "</LaminarCoefficient>" << std::endl;
      xml << "      <Exponent>" << element.expt<std::string>() << "</Exponent>" << std::endl;
      xml << "      <Transition><ByMinimum/></Transition>" << std::endl;
      xml << "      <CoefficientRelationship><TransitionReynoldsNumber>30</TransitionReynoldsNumber></CoefficientRelationship>" << std::endl;
      xml << "      <Data>" << std::endl;
      xml << "        <DataPoint>" << std::endl;
      xml << "          <MassFlowRate units=\"kg/s\">" << element.Flow<std::string>() << "</MassFlowRate>" << std::endl;
      xml << "          <PressureDifference units=\"Pa\">" << element.dP<std::string>() << "</PressureDifference>" << std::endl;
      xml << "        </DataPoint>" << std::endl;
      xml << "      </Data>" << std::endl;
      xml << "    </PowerLaw>" << std::endl;
    }
    xml << "  </Elements>" << std::endl;
  }

  if (model.levels().size() > 0) {
    xml << "  <Levels>" << std::endl;
    int count = 1;
    for (auto& level : model.levels()) {
      auto name = level.name();
      if (name.empty()) {
        name = 'L' + std::to_string(count);
      } else {
        // Do something else here at some point
        name = 'L' + std::to_string(count);
      }
      level.setName(name);
      xml << "    <Level ID=\"" << sanitize_name(level.name()) << "\">" << std::endl;
      xml << "      <Height units=\"m\">" << level.delht<std::string>() << "</Height>" << std::endl;
      xml << "      <Elevation units=\"m\">" << level.refht<std::string>() << "</Elevation>" << std::endl;
      xml << "    </Level>" << std::endl;
      ++count;
    }
    xml << "  </Levels>" << std::endl;
  }

  std::stringstream ssxml;
  std::vector<std::string> external_nodes;
  if (model.airflowPaths().size() > 0) {
    // Make some external nodes, assume
    //  * fixed pressure
    //  * the first zone in the link is the only one that will be external
    for (auto& path : model.airflowPaths()) {
      if (path.pzn() < 0) {
        path.setPzn(-count);
        ssxml << "    <Node ID=\"external_" << path.nr() << "\">" << std::endl;
        ssxml << "      <PressureHandling>Fixed</PressureHandling>" << std::endl;
        //ssxml << "      <RelativeElevation units=\"m\">" << zone.relHt<std::string>() << "</RelativeElevation>" << std::endl;
        ssxml << "      <DefaultState>" << std::endl;
        //ssxml << "        <Temperature units=\"K\">" << zone.T0<std::string>() << "</Temperature>" << std::endl;
        ssxml << "        <Pressure units=\"Pag\">" << path.wPset<std::string>() << "</Pressure>" << std::endl;
        ssxml << "      </DefaultState>" << std::endl;
        std::string level_id = sanitize_name(model.levels()[path.pld() - 1].name());
        ssxml << "      <LevelID IDref=\"" << level_id << "\"/>" << std::endl;
        ssxml << "    </Node>" << std::endl;
      }
    }
  }

  auto zones = model.zones();

  if (zones.size() > 0) {
    xml << "  <Nodes>" << std::endl;
    for (auto& zone : zones) {
      std::string level_id = sanitize_name(model.levels()[zone.pl() - 1].name());
      // Need to do something better here:
      zone.setName(zone.name() + '_' + level_id);
      xml << "    <Node ID=\"" << sanitize_name(zone.name()) << "\">" << std::endl;
      if (zone.variablePressure()) {
        xml << "      <PressureHandling>Simulated</PressureHandling>" << std::endl;
      } else {
        xml << "      <PressureHandling>Fixed</PressureHandling>" << std::endl;
      }
      xml << "      <Volume>" << std::endl;
      xml << "        <SpecifiedVolume units=\"m^3\">" << zone.Vol<std::string>() <<  "</SpecifiedVolume>" << std::endl;
      xml << "      </Volume>" << std::endl;
      xml << "      <RelativeElevation units=\"m\">" << zone.relHt<std::string>() << "</RelativeElevation>" << std::endl;
      xml << "      <DefaultState>" << std::endl;
      xml << "        <Temperature units=\"K\">" << zone.T0<std::string>() << "</Temperature>" << std::endl;
      xml << "        <Pressure units=\"Pag\">" << zone.P0<std::string>() << "</Pressure>" << std::endl;
      xml << "      </DefaultState>" << std::endl;
      //std::string level_id = sanitize_name(model.levels()[zone.pl() - 1].name());
      xml << "      <LevelID IDref=\"" << level_id << "\"/>" << std::endl;
      xml << "    </Node>" << std::endl;
    }
    if (!ssxml.str().empty()) {
      xml << ssxml.str();
    }
    xml << "  </Nodes>" << std::endl;
  }

  if (model.airflowPaths().size() > 0) {
    xml << "  <Links>" << std::endl;
    int number{ 1 };
    for (auto& path : model.airflowPaths()) {
      xml << "    <Link ID=\"path_" << number << "\">" << std::endl;
      xml << "      <ElementID IDref=\"" << afe_lookup[path.pe()] << "\"/>" << std::endl;
      xml << "      <Multiplier>" << path.mult<std::string>() << "</Multiplier>" << std::endl;
      xml << "      <Nodes>" << std::endl;
      xml << "        <Node>" << std::endl;
      // Assume only the first node could be external
      if (path.pzn() < 0) {
        xml << "          <NodeID IDref=\"external_" << path.nr() << "\"/>" << std::endl;
      } else {
        xml << "          <NodeID IDref=\"" << sanitize_name(zones[path.pzn() - 1].name()) << "\"/>" << std::endl;
      }
      xml << "        </Node>" << std::endl;
      xml << "        <Node>" << std::endl;
      xml << "          <NodeID IDref=\"" << sanitize_name(zones[path.pzm() - 1].name()) << "\"/>" << std::endl;
      //xml << "          <Value>" << zone.Vol<std::string>() << "</Value>" << std::endl;
      //xml << "          <Units>m^3</Units>" << std::endl;
      xml << "        </Node>" << std::endl;
      xml << "      </Nodes>" << std::endl;
      xml << "    </Link>" << std::endl;
      ++number;
    }
    xml << "  </Links>" << std::endl;
  }

  xml << "</AirflowNetwork>" << std::endl;
  xml.close();
  return EXIT_SUCCESS;
}