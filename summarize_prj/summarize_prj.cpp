#include "model.hpp"
#include <iostream>
#include <unordered_map>

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
  // Build a name table to preserve the index-name relationship
  std::unordered_map<int, std::string> lookup;
  int count = 1;
  for (auto& path : model.airflowPaths()) {
    int id = path.pe();
    if (id < 1) {
      std::cout << path.nr() << ": Negative or zero ID" << std::endl;
      continue;
    }
    --id;
    if (id >= afe.size()) {
      std::cout << "ID out of range" << std::endl;
      continue;
    }
    lookup[id] = afe[id]->name();
    std::cout << count << ' ' << id << ' ' << afe[id]->name() << std::endl;
    ++count;
  }

  return EXIT_SUCCESS;
}