/***********************************************************************************************************************
*  OpenStudio(R), Copyright (c) 2008-2019, Alliance for Sustainable Energy, LLC, and other contributors. All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
*  following conditions are met:
*
*  (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
*  disclaimer.
*
*  (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
*  disclaimer in the documentation and/or other materials provided with the distribution.
*
*  (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote products
*  derived from this software without specific prior written permission from the respective party.
*
*  (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative works
*  may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without specific prior
*  written permission from Alliance for Sustainable Energy, LLC.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) AND ANY CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
*  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
*  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER(S), ANY CONTRIBUTORS, THE UNITED STATES GOVERNMENT, OR THE UNITED
*  STATES DEPARTMENT OF ENERGY, NOR ANY OF THEIR EMPLOYEES, BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
*  USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
*  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
*  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***********************************************************************************************************************/

#include "PrjModel.hpp"
//#include "SimFile.hpp"

#include "PrjModelImpl.hpp"
#include "../src/logging.hpp"

#include <algorithm>

namespace prjmodel {

IndexModel::IndexModel() :
  m_impl(std::shared_ptr<IndexModelImpl>(new IndexModelImpl))
{}

//IndexModel::IndexModel(openstudio::path path) :
//  m_impl(std::shared_ptr<detail::IndexModelImpl>(new detail::IndexModelImpl))
//{
//  m_impl->read(path);
//}

//IndexModel::IndexModel(std::string filename) :
//  m_impl(std::shared_ptr<detail::IndexModelImpl>(new detail::IndexModelImpl))
//{
//  m_impl->read(filename);
//}

IndexModel::IndexModel(Reader &input) :
  m_impl(std::shared_ptr<IndexModelImpl>(new IndexModelImpl))
{
  m_impl->read(input);
}

IndexModel::IndexModel(const IndexModel &other) : m_impl(other.m_impl)
{}

IndexModel::~IndexModel()
{}

IndexModel& IndexModel::operator=(const IndexModel &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool IndexModel::operator==(const IndexModel &other) const
{
  return m_impl==other.m_impl;
}

bool IndexModel::operator!=(const IndexModel &other) const
{
  return m_impl!=other.m_impl;
}

//bool IndexModel::read(openstudio::path path)
//{
//  return m_impl->read(openstudio::toString(path));
//}

//bool IndexModel::read(std::string filename)
//{
//  return m_impl->read(filename);
//}

bool IndexModel::read(Reader &input)
{
  return m_impl->read(input);
}

std::string IndexModel::toString()
{
  return m_impl->toString();
}

std::string IndexModel::programName() const
{
  return m_impl->programName();
}

void IndexModel::setProgramName(const std::string &name)
{
  m_impl->setProgramName(name);
}

std::string IndexModel::version() const
{
  return m_impl->version();
}

void IndexModel::setVersion(const std::string &version)
{
  m_impl->setVersion(version);
}

int IndexModel::echo() const
{
  return m_impl->echo();
}

void IndexModel::setEcho(const int echo)
{
  m_impl->setEcho(echo);
}

std::string IndexModel::desc() const
{
  return m_impl->desc();
}

void IndexModel::setDesc(const std::string &prjdesc)
{
  m_impl->setDesc(prjdesc);
}

int IndexModel::skheight() const
{
  return m_impl->skheight();
}

void IndexModel::setSkheight(const int skheight)
{
  m_impl->setSkheight(skheight);
}

int IndexModel::skwidth() const
{
  return m_impl->skwidth();
}

void IndexModel::setSkwidth(const int skwidth)
{
  m_impl->setSkwidth(skwidth);
}

int IndexModel::def_units() const
{
  return m_impl->def_units();
}

void IndexModel::setDef_units(const int def_units)
{
  m_impl->setDef_units(def_units);
}

int IndexModel::def_flows() const
{
  return m_impl->def_flows();
}

void IndexModel::setDef_flows(const int def_flows)
{
  m_impl->setDef_flows(def_flows);
}

double IndexModel::def_T() const
{
  return m_impl->def_T();
}

bool IndexModel::setDef_T(const double def_T)
{
  return m_impl->setDef_T(def_T);
}

bool IndexModel::setDef_T(const std::string &def_T)
{
  return m_impl->setDef_T(def_T);
}

int IndexModel::udefT() const
{
  return m_impl->udefT();
}

void IndexModel::setUdefT(const int udefT)
{
  m_impl->setUdefT(udefT);
}

double IndexModel::rel_N() const
{
  return m_impl->rel_N();
}

bool IndexModel::setRel_N(const double rel_N)
{
  return m_impl->setRel_N(rel_N);
}

bool IndexModel::setRel_N(const std::string &rel_N)
{
  return m_impl->setRel_N(rel_N);
}

double IndexModel::wind_H() const
{
  return m_impl->wind_H();
}

bool IndexModel::setWind_H(const double wind_H)
{
  return m_impl->setWind_H(wind_H);
}

bool IndexModel::setWind_H(const std::string &wind_H)
{
  return m_impl->setWind_H(wind_H);
}

int IndexModel::uwH() const
{
  return m_impl->uwH();
}

void IndexModel::setUwH(const int uwH)
{
  m_impl->setUwH(uwH);
}

double IndexModel::wind_Ao() const
{
  return m_impl->wind_Ao();
}

bool IndexModel::setWind_Ao(const double wind_Ao)
{
  return m_impl->setWind_Ao(wind_Ao);
}

bool IndexModel::setWind_Ao(const std::string &wind_Ao)
{
  return m_impl->setWind_Ao(wind_Ao);
}

double IndexModel::wind_a() const
{
  return m_impl->wind_a();
}

bool IndexModel::setWind_a(const double wind_a)
{
  return m_impl->setWind_a(wind_a);
}

bool IndexModel::setWind_a(const std::string &wind_a)
{
  return m_impl->setWind_a(wind_a);
}

double IndexModel::scale() const
{
  return m_impl->scale();
}

bool IndexModel::setScale(const double scale)
{
  return m_impl->setScale(scale);
}

bool IndexModel::setScale(const std::string &scale)
{
  return m_impl->setScale(scale);
}

int IndexModel::uScale() const
{
  return m_impl->uScale();
}

void IndexModel::setUScale(const int uScale)
{
  m_impl->setUScale(uScale);
}

int IndexModel::orgRow() const
{
  return m_impl->orgRow();
}

void IndexModel::setOrgRow(const int orgRow)
{
  m_impl->setOrgRow(orgRow);
}

int IndexModel::orgCol() const
{
  return m_impl->orgCol();
}

void IndexModel::setOrgCol(const int orgCol)
{
  m_impl->setOrgCol(orgCol);
}

int IndexModel::invYaxis() const
{
  return m_impl->invYaxis();
}

void IndexModel::setInvYaxis(const int invYaxis)
{
  m_impl->setInvYaxis(invYaxis);
}

int IndexModel::showGeom() const
{
  return m_impl->showGeom();
}

void IndexModel::setShowGeom(const int showGeom)
{
  m_impl->setShowGeom(showGeom);
}

WeatherData IndexModel::ssWeather() const
{
  return m_impl->ssWeather();
}

void IndexModel::setSsWeather(const WeatherData &ssWeather)
{
  m_impl->setSsWeather(ssWeather);
}

WeatherData IndexModel::wptWeather() const
{
  return m_impl->wptWeather();
}

void IndexModel::setWptWeather(const WeatherData &wptWeather)
{
  m_impl->setWptWeather(wptWeather);
}

std::string IndexModel::WTHpath() const
{
  return m_impl->WTHpath();
}

void IndexModel::setWTHpath(const std::string &WTHpath)
{
  m_impl->setWTHpath(WTHpath);
}

std::string IndexModel::CTMpath() const
{
  return m_impl->CTMpath();
}

void IndexModel::setCTMpath(const std::string &CTMpath)
{
  m_impl->setCTMpath(CTMpath);
}

std::string IndexModel::CVFpath() const
{
  return m_impl->CVFpath();
}

void IndexModel::setCVFpath(const std::string &CVFpath)
{
  m_impl->setCVFpath(CVFpath);
}

std::string IndexModel::DVFpath() const
{
  return m_impl->DVFpath();
}

void IndexModel::setDVFpath(const std::string &DVFpath)
{
  m_impl->setDVFpath(DVFpath);
}

std::string IndexModel::WPCfile() const
{
  return m_impl->WPCfile();
}

void IndexModel::setWPCfile(const std::string &WPCfile)
{
  m_impl->setWPCfile(WPCfile);
}

std::string IndexModel::EWCfile() const
{
  return m_impl->EWCfile();
}

void IndexModel::setEWCfile(const std::string &EWCfile)
{
  m_impl->setEWCfile(EWCfile);
}

std::string IndexModel::WPCdesc() const
{
  return m_impl->WPCdesc();
}

void IndexModel::setWPCdesc(const std::string &WPCdesc)
{
  m_impl->setWPCdesc(WPCdesc);
}

double IndexModel::X0() const
{
  return m_impl->X0();
}

bool IndexModel::setX0(const double X0)
{
  return m_impl->setX0(X0);
}

bool IndexModel::setX0(const std::string &X0)
{
  return m_impl->setX0(X0);
}

double IndexModel::Y0() const
{
  return m_impl->Y0();
}

bool IndexModel::setY0(const double Y0)
{
  return m_impl->setY0(Y0);
}

bool IndexModel::setY0(const std::string &Y0)
{
  return m_impl->setY0(Y0);
}

double IndexModel::Z0() const
{
  return m_impl->Z0();
}

bool IndexModel::setZ0(const double Z0)
{
  return m_impl->setZ0(Z0);
}

bool IndexModel::setZ0(const std::string &Z0)
{
  return m_impl->setZ0(Z0);
}

double IndexModel::angle() const
{
  return m_impl->angle();
}

bool IndexModel::setAngle(const double angle)
{
  return m_impl->setAngle(angle);
}

bool IndexModel::setAngle(const std::string &angle)
{
  return m_impl->setAngle(angle);
}

int IndexModel::u_XYZ() const
{
  return m_impl->u_XYZ();
}

void IndexModel::setU_XYZ(const int u_XYZ)
{
  m_impl->setU_XYZ(u_XYZ);
}

double IndexModel::epsPath() const
{
  return m_impl->epsPath();
}

bool IndexModel::setEpsPath(const double epsPath)
{
  return m_impl->setEpsPath(epsPath);
}

bool IndexModel::setEpsPath(const std::string &epsPath)
{
  return m_impl->setEpsPath(epsPath);
}

double IndexModel::epsSpcs() const
{
  return m_impl->epsSpcs();
}

bool IndexModel::setEpsSpcs(const double epsSpcs)
{
  return m_impl->setEpsSpcs(epsSpcs);
}

bool IndexModel::setEpsSpcs(const std::string &epsSpcs)
{
  return m_impl->setEpsSpcs(epsSpcs);
}

std::string IndexModel::tShift() const
{
  return m_impl->tShift();
}

void IndexModel::setTShift(const std::string &tShift)
{
  m_impl->setTShift(tShift);
}

std::string IndexModel::dStart() const
{
  return m_impl->dStart();
}

void IndexModel::setDStart(const std::string &dStart)
{
  m_impl->setDStart(dStart);
}

std::string IndexModel::dEnd() const
{
  return m_impl->dEnd();
}

void IndexModel::setDEnd(const std::string &dEnd)
{
  m_impl->setDEnd(dEnd);
}

int IndexModel::useWPCwp() const
{
  return m_impl->useWPCwp();
}

void IndexModel::setUseWPCwp(const int useWPCwp)
{
  m_impl->setUseWPCwp(useWPCwp);
}

int IndexModel::useWPCmf() const
{
  return m_impl->useWPCmf();
}

void IndexModel::setUseWPCmf(const int useWPCmf)
{
  m_impl->setUseWPCmf(useWPCmf);
}

int IndexModel::wpctrig() const
{
  return m_impl->wpctrig();
}

void IndexModel::setWpctrig(const int wpctrig)
{
  m_impl->setWpctrig(wpctrig);
}

double IndexModel::latd() const
{
  return m_impl->latd();
}

bool IndexModel::setLatd(const double latd)
{
  return m_impl->setLatd(latd);
}

bool IndexModel::setLatd(const std::string &latd)
{
  return m_impl->setLatd(latd);
}

double IndexModel::lgtd() const
{
  return m_impl->lgtd();
}

bool IndexModel::setLgtd(const double lgtd)
{
  return m_impl->setLgtd(lgtd);
}

bool IndexModel::setLgtd(const std::string &lgtd)
{
  return m_impl->setLgtd(lgtd);
}

double IndexModel::Tznr() const
{
  return m_impl->Tznr();
}

bool IndexModel::setTznr(const double Tznr)
{
  return m_impl->setTznr(Tznr);
}

bool IndexModel::setTznr(const std::string &Tznr)
{
  return m_impl->setTznr(Tznr);
}

double IndexModel::altd() const
{
  return m_impl->altd();
}

bool IndexModel::setAltd(const double altd)
{
  return m_impl->setAltd(altd);
}

bool IndexModel::setAltd(const std::string &altd)
{
  return m_impl->setAltd(altd);
}

double IndexModel::Tgrnd() const
{
  return m_impl->Tgrnd();
}

bool IndexModel::setTgrnd(const double Tgrnd)
{
  return m_impl->setTgrnd(Tgrnd);
}

bool IndexModel::setTgrnd(const std::string &Tgrnd)
{
  return m_impl->setTgrnd(Tgrnd);
}

int IndexModel::utg() const
{
  return m_impl->utg();
}

void IndexModel::setUtg(const int utg)
{
  m_impl->setUtg(utg);
}

int IndexModel::u_a() const
{
  return m_impl->u_a();
}

void IndexModel::setU_a(const int u_a)
{
  m_impl->setU_a(u_a);
}

RunControl IndexModel::rc() const
{
  return m_impl->rc();
}
void IndexModel::setRc(const RunControl &rc)
{
  m_impl->setRc(rc);
}

std::vector<int> IndexModel::contaminants() const
{
  return m_impl->contaminants();
}

std::vector <Species> IndexModel::species() const
{
  return m_impl->species();
}
void IndexModel::setSpecies(const std::vector<Species> &species)
{
  m_impl->setSpecies(species);
}
void IndexModel::addSpecies(Species &species)
{
  m_impl->addSpecies(species);
}
bool IndexModel::removeSpecies(const Species &species)
{
  return m_impl->removeSpecies(species);
}

std::vector <Level> IndexModel::levels() const
{
  return m_impl->levels();
}
void IndexModel::setLevels(const std::vector<Level> &levels)
{
  m_impl->setLevels(levels);
}
void IndexModel::addLevel(Level &level)
{
  m_impl->addLevel(level);
}

std::vector <DaySchedule> IndexModel::daySchedules() const
{
  return m_impl->daySchedules();
}
void IndexModel::setDaySchedules(const std::vector<DaySchedule> &daySchedules)
{
  m_impl->setDaySchedules(daySchedules);
}

std::vector <WeekSchedule> IndexModel::weekSchedules() const
{
  return m_impl->weekSchedules();
}
void IndexModel::setWeekSchedules(const std::vector<WeekSchedule> &weekSchedules)
{
  m_impl->setWeekSchedules(weekSchedules);
}

std::vector <WindPressureProfile> IndexModel::windPressureProfiles() const
{
  return m_impl->windPressureProfiles();
}
void IndexModel::setWindPressureProfiles(const std::vector<WindPressureProfile> &windPressureProfiles)
{
  m_impl->setWindPressureProfiles(windPressureProfiles);
}

std::vector<PlrTest1> IndexModel::getPlrTest1() const
{
  return m_impl->getAirflowElements<PlrTest1>();
}

std::vector<PlrTest2> IndexModel::getPlrTest2() const
{
  return m_impl->getAirflowElements<PlrTest2>();
}

std::vector<PlrLeak2> IndexModel::getPlrLeak2() const
{
  return m_impl->getAirflowElements<PlrLeak2>();
}

bool IndexModel::addAirflowElement(PlrTest1 element)
{
  return m_impl->addAirflowElement(element);
}

bool IndexModel::addAirflowElement(PlrLeak2 element)
{
  return m_impl->addAirflowElement(element);
}

int IndexModel::airflowElementNrByName(std::string name) const
{
  return m_impl->airflowElementNrByName(name);
}

bool IndexModel::replaceAirflowElement(int nr, PlrTest1 element)
{
  return m_impl->replaceAirflowElement(nr,element);
}

std::vector<CvfDat> IndexModel::getCvfDat() const
{
  return m_impl->getControlNodes<CvfDat>();
}

bool IndexModel::addControlNode(CvfDat element, bool sequence)
{
  return m_impl->addControlNode(element,sequence);
}

std::vector <Ahs> IndexModel::ahs() const
{
  return m_impl->ahs();
}
void IndexModel::setAhs(const std::vector<Ahs> &ahs)
{
  m_impl->setAhs(ahs);
}
void IndexModel::addAhs(Ahs ahs)
{
  m_impl->addAhs(ahs);
}

std::vector<Zone> IndexModel::zones() const
{
  return m_impl->zones();
}
void IndexModel::setZones(const std::vector<Zone> &zones)
{
  m_impl->setZones(zones);
}
void IndexModel::addZone(Zone zone)
{
  m_impl->addZone(zone);
}

std::vector<AirflowPath> IndexModel::airflowPaths() const
{
  return m_impl->airflowPaths();
}
void IndexModel::setAirflowPaths(const std::vector<AirflowPath> &paths)
{
  m_impl->setAirflowPaths(paths);
}
void IndexModel::addAirflowPath(AirflowPath path)
{
  m_impl->addAirflowPath(path);
}

bool IndexModel::valid() const
{
  return m_impl->valid();
}

std::vector<std::vector<int> > IndexModel::zoneExteriorFlowPaths()
{
  return m_impl->zoneExteriorFlowPaths();
}

//std::vector<TimeSeries> IndexModel::zoneInfiltration(SimFile *sim)
//{
//  return m_impl->zoneInfiltration(sim);
//}
//
//std::vector<TimeSeries> IndexModel::pathInfiltration(std::vector<int> pathNrs, SimFile *sim)
//{
//  return m_impl->pathInfiltration(pathNrs, sim);
//}

IndexModel::IndexModelImpl::IndexModelImpl() : m_echo(0), m_skheight(0), m_skwidth(0), m_def_units(0), m_def_flows(0), m_def_T(PRJFLOAT("0.0")),
m_udefT(0), m_rel_N(PRJFLOAT("0.0")), m_wind_H(PRJFLOAT("0.0")), m_uwH(0), m_wind_Ao(PRJFLOAT("0.0")), m_wind_a(PRJFLOAT("0.0")),
m_scale(PRJFLOAT("0.0")), m_uScale(0), m_orgRow(0), m_orgCol(0), m_invYaxis(0), m_showGeom(0), m_X0(PRJFLOAT("0.0")), m_Y0(PRJFLOAT("0.0")),
m_Z0(PRJFLOAT("0.0")), m_angle(PRJFLOAT("0.0")), m_u_XYZ(0), m_epsPath(PRJFLOAT("0.0")), m_epsSpcs(PRJFLOAT("0.0")), m_useWPCwp(0),
m_useWPCmf(0), m_wpctrig(0), m_latd(PRJFLOAT("0.0")), m_lgtd(PRJFLOAT("0.0")), m_Tznr(PRJFLOAT("0.0")), m_altd(PRJFLOAT("0.0")),
m_Tgrnd(PRJFLOAT("0.0")), m_utg(0), m_u_a(0)
{
  m_programName = "ContamW";
  m_valid = false;
}

//IndexModel::IndexModelImpl::IndexModelImpl(openstudio::path path)
//{
//  setDefaults();
//  read(path);
//}

//IndexModel::IndexModelImpl::IndexModelImpl(std::string filename)
//{
//  setDefaults();
//  read(filename);
//}

IndexModel::IndexModelImpl::IndexModelImpl(Reader& input) : IndexModel::IndexModelImpl()
{
  read(input);
}

//bool IndexModel::IndexModelImpl::read(openstudio::path path)
//{
//  setDefaults();
//  openstudio::filesystem::ifstream file(path);
//  m_valid = false;
//  if (file.is_open())
//  {
//    Reader input(file);
//    read(input);
//  }
//  return m_valid;
//}

//bool IndexModel::IndexModelImpl::read(std::string filename)
//{
//  return read(openstudio::toPath(filename));
//}

bool IndexModel::IndexModelImpl::read(Reader& input)
{
  m_valid = false;
  // Section 1: Project, Weather, Simulation, and Output Controls
  m_programName = input.readString();
  m_programVersion = input.readString();
  m_echo = input.read<int>();
  m_desc = input.readLine();
  setSkheight(input.read<int>());
  setSkwidth(input.read<int>());
  setDef_units(input.read<int>());
  setDef_flows(input.read<int>());
  setDef_T(input.readNumber<std::string>());
  setUdefT(input.read<int>());
  setRel_N(input.readNumber<std::string>());
  setWind_H(input.readNumber<std::string>());
  setUwH(input.read<int>());
  setWind_Ao(input.readNumber<std::string>());
  setWind_a(input.readNumber<std::string>());
  setScale(input.readNumber<std::string>());
  setUScale(input.read<int>());
  setOrgRow(input.read<int>());
  setOrgCol(input.read<int>());
  setInvYaxis(input.read<int>());
  setShowGeom(input.read<int>());
  m_ssWeather.read(input);
  m_wptWeather.read(input);
  m_WTHpath = input.readLine();
  m_CTMpath = input.readLine();
  m_CVFpath = input.readLine();
  m_DVFpath = input.readLine();
  m_WPCfile = input.readLine();
  m_EWCfile = input.readLine();
  m_WPCdesc = input.readLine();
  setX0(input.readNumber<std::string>());
  setY0(input.readNumber<std::string>());
  setZ0(input.readNumber<std::string>());
  setAngle(input.readNumber<std::string>());
  setU_XYZ(input.read<int>());
  setEpsPath(input.readNumber<std::string>());
  setEpsSpcs(input.readNumber<std::string>());
  setTShift(input.readString());
  setDStart(input.readString());
  setDEnd(input.readString());
  setUseWPCwp(input.read<int>());
  setUseWPCmf(input.read<int>());
  setWpctrig(input.read<int>());
  setLatd(input.readNumber<std::string>());
  setLgtd(input.readNumber<std::string>());
  setTznr(input.readNumber<std::string>());
  setAltd(input.readNumber<std::string>());
  setTgrnd(input.readNumber<std::string>());
  setUtg(input.read<int>());
  setU_a(input.read<int>());
  m_rc.read(input); // Read the run control section
  input.read999();
  // Section 2: Species and Contaminants
  std::vector<int> contaminants = input.readIntVector(false); // Might want to check that this matches the species data
  m_species = input.readSectionVector<Species>("species");
  // Section 3: Level and Icon Data
  m_levels = input.readSectionVector<Level>("level");
  // Section 4: Day Schedules
  m_daySchedules = input.readSectionVector<DaySchedule>("day schedule");
  // Section 5: Week Schedules
  m_weekSchedules = input.readSectionVector<WeekSchedule>("week schedule");
  // Section 6: Wind Pressure Profiles
  m_windPressureProfiles = input.readSectionVector<WindPressureProfile>("wind pressure profiles");
  // Section 7: Kinetic Reactions
  std::string kinr = input.readSection(); // Skip it
  m_unsupported["KineticReaction"] = kinr;
  // Section 8a: Filter Elements
  std::string flte = input.readSection(); // Skip it
  m_unsupported["FilterElement"] = flte;
  // Section 8b: Filters
  std::string filt = input.readSection(); // Skip it
  m_unsupported["Filter"] = filt;
  // Section 9: Source/Sink Elements
  std::string cse = input.readSection(); // Skip it
  m_unsupported["SourceSink"] = cse;
  // Section 10: Airflow Elements
  m_airflowElements = input.readElementVector<AirflowElement>("airflow element");
  // Section 11: Duct Elements
  std::string dfe = input.readSection(); // Skip it
  m_unsupported["DuctElement"] = dfe;
  // Section 12a: Control Super Elements
  std::string selmt = input.readSection(); // Skip it
  m_unsupported["ControlSuperElements"] = selmt;
  // Section 12b: Control Nodes
  //std::string ctrl = input.readSection(); // Skip it
  //m_unsupported["ControlNode"] = ctrl;
  m_controlNodes = input.readElementVector<ControlNode>("control node");
  // Section 13: Simple Air Handling System (AHS)
  m_ahs = input.readSectionVector<Ahs>("ahs");
  // Section 14: Zones
  m_zones = input.readSectionVector<Zone>("zone");
  // Section 15: Initial Zone Concentrations
  readZoneIc(input);
  // Section 16: Airflow Paths
  m_paths = input.readSectionVector<AirflowPath>("path");
  // Section 17: Duct Junctions
  std::string jct = input.readSection(); // Skip it
  m_unsupported["DuctJunction"] = jct;
  // Section 18: Initial Junction Concentrations
  std::string jctic = input.readSection(); // Skip it
  m_unsupported["JunctionIC"] = jctic;
  // Section 19: Duct Segments
  std::string dct = input.readSection(); // Skip it
  m_unsupported["DuctSegment"] = dct;
  // Section 20: Source/Sinks
  //m_sourceSinks = input.readSectionVector<SourceSink>(std::string("source/sink"));
  std::string css = input.readSection(); // Skip it
  m_unsupported["SourceSink"] = css;
  // Section 21: Occupancy Schedules
  std::string osch = input.readSection(); // Skip it
  m_unsupported["OccupancySchedule"] = osch;
  // Section 22: Exposures
  std::string pexp = input.readSection(); // Skip it
  m_unsupported["Exposure"] = pexp;
  // Section 23: Annotations
  std::string note = input.readSection(); // Skip it
  m_unsupported["Annotation"] = note;
  input.readEnd();
  m_valid = true;
  return true;
}

std::string IndexModel::IndexModelImpl::toString()
{
  std::string output;
  if (!m_valid) {
    return output;
  }
  // Section 1: Project, Weather, Simulation, and Output Controls
  output += m_programName + ' ' + m_programVersion + ' ' + ANY_TO_STR(m_echo) + '\n';
  output += m_desc + '\n';
  output += ANY_TO_STR(m_skheight) + ' ' + ANY_TO_STR(m_skwidth) + ' ' + ANY_TO_STR(m_def_units) + ' '
    + ANY_TO_STR(m_def_flows) + ' ' + PRJFLOAT_TO_STR(m_def_T) + ' ' + ANY_TO_STR(m_udefT) + ' '
    + PRJFLOAT_TO_STR(m_rel_N) + ' ' + PRJFLOAT_TO_STR(m_wind_H) + ' ' + ANY_TO_STR(m_uwH) + ' '
    + PRJFLOAT_TO_STR(m_wind_Ao) + ' ' + PRJFLOAT_TO_STR(m_wind_a) + '\n';
  output += PRJFLOAT_TO_STR(m_scale) + ' ' + ANY_TO_STR(m_uScale) + ' ' + ANY_TO_STR(m_orgRow) + ' '
    + ANY_TO_STR(m_orgCol) + ' ' + ANY_TO_STR(m_invYaxis) + ' ' + ANY_TO_STR(m_showGeom) + '\n';
  output += m_ssWeather.write();
  output += m_wptWeather.write();
  output += m_WTHpath + '\n';
  output += m_CTMpath + '\n';
  output += m_CVFpath + '\n';
  output += m_DVFpath + '\n';
  output += m_WPCfile + '\n';
  output += m_EWCfile + '\n';
  output += m_WPCdesc + '\n';
  output += PRJFLOAT_TO_STR(m_X0) + ' ' + PRJFLOAT_TO_STR(m_Y0) + ' ' + PRJFLOAT_TO_STR(m_Z0) + ' ' + PRJFLOAT_TO_STR(m_angle)
    + ' ' + ANY_TO_STR(m_u_XYZ) + '\n';
  output += PRJFLOAT_TO_STR(m_epsPath) + ' ' + PRJFLOAT_TO_STR(m_epsSpcs) + ' ' + m_tShift + ' ' + m_dStart + ' '
    + m_dEnd + ' ' + ANY_TO_STR(m_useWPCwp) + ' ' + ANY_TO_STR(m_useWPCmf) + ' ' + ANY_TO_STR(m_wpctrig)
    + '\n';
  output += PRJFLOAT_TO_STR(m_latd) + ' ' + PRJFLOAT_TO_STR(m_lgtd) + ' ' + PRJFLOAT_TO_STR(m_Tznr) + ' '
    + PRJFLOAT_TO_STR(m_altd) + ' ' + PRJFLOAT_TO_STR(m_Tgrnd) + ' ' + ANY_TO_STR(m_utg) + ' '
    + ANY_TO_STR(m_u_a) + '\n';
  output += m_rc.write();
  output += "-999\n";
  // Section 2: Species and Contaminants
  output += writeArray(contaminants(), "contaminants:");
  output += writeSectionVector(m_species, "species:");
  // Section 3: Level and Icon Data
  output += writeSectionVector(m_levels, "levels:");
  // Section 4: Day Schedules
  output += writeSectionVector(m_daySchedules, "day-schedules:");
  // Section 5: Week Schedules
  output += writeSectionVector(m_weekSchedules, "week-schedules:");
  // Section 6: Wind Pressure Profiles
  output += writeSectionVector(m_windPressureProfiles, "wind pressure profiles:");
  // Section 7: Kinetic Reactions
  output += m_unsupported["KineticReaction"];
  // Section 8a: Filter Elements
  output += m_unsupported["FilterElement"];
  // Section 8b: Filters
  output += m_unsupported["Filter"];
  // Section 9: Source/Sink Elements
  output += m_unsupported["SourceSink"];
  // Section 10: Airflow Elements
  output += writeSectionVector(m_airflowElements, "flow elements:");
  // Section 11: Duct Elements
  output += m_unsupported["DuctElement"];
  // Section 12a: Control Super Elements
  output += m_unsupported["ControlSuperElements"];
  // Section 12b: Control Nodes
  //output += m_unsupported["ControlNode"];
  output += writeSectionVector(m_controlNodes, "control nodes:");
  // Section 13: Simple Air Handling System (AHS)
  output += writeSectionVector(m_ahs, "simple AHS:");
  // Section 14: Zones
  output += writeSectionVector(m_zones, "zones:");
  // Section 15: Initial Zone Concentrations
  output += writeZoneIc();
  // Section 16: Airflow Paths
  output += writeSectionVector(m_paths, "flow paths:");
  // Section 17: Duct Junctions
  output += m_unsupported["DuctJunction"];
  // Section 18: Initial Junction Concentrations
  output += m_unsupported["JunctionIC"];
  // Section 19: Duct Segments
  output += m_unsupported["DuctSegment"];
  // Section 20: Source/Sinks
  output += m_unsupported["SourceSink"];
  // Section 21: Occupancy Schedules
  output += m_unsupported["OccupancySchedule"];
  // Section 22: Exposures
  output += m_unsupported["Exposure"];
  // Section 23: Annotations
  output += m_unsupported["Annotation"];
  // End of the PRJ file
  output += "* end project file.";
  return output;
}

std::string IndexModel::IndexModelImpl::programName() const
{
  return m_programName;
}

void IndexModel::IndexModelImpl::setProgramName(const std::string& name)
{
  m_programName = name;
}

std::string IndexModel::IndexModelImpl::version() const
{
  return m_programVersion;
}

void IndexModel::IndexModelImpl::setVersion(const std::string& version)
{
  m_programVersion = version;
}

int IndexModel::IndexModelImpl::echo() const
{
  return m_echo;
}

void IndexModel::IndexModelImpl::setEcho(const int echo)
{
  m_echo = echo;
}

std::string IndexModel::IndexModelImpl::desc() const
{
  return m_desc;
}

void IndexModel::IndexModelImpl::setDesc(const std::string& prjdesc)
{
  m_desc = prjdesc;
}

int IndexModel::IndexModelImpl::skheight() const
{
  return m_skheight;
}

void IndexModel::IndexModelImpl::setSkheight(const int skheight)
{
  m_skheight = skheight;
}

int IndexModel::IndexModelImpl::skwidth() const
{
  return m_skwidth;
}

void IndexModel::IndexModelImpl::setSkwidth(const int skwidth)
{
  m_skwidth = skwidth;
}

int IndexModel::IndexModelImpl::def_units() const
{
  return m_def_units;
}

void IndexModel::IndexModelImpl::setDef_units(const int def_units)
{
  m_def_units = def_units;
}

int IndexModel::IndexModelImpl::def_flows() const
{
  return m_def_flows;
}

void IndexModel::IndexModelImpl::setDef_flows(const int def_flows)
{
  m_def_flows = def_flows;
}

double IndexModel::IndexModelImpl::def_T() const
{
  return to<double>(m_def_T);
}

bool IndexModel::IndexModelImpl::setDef_T(const double def_T)
{
  m_def_T = to_float(def_T);
  return true;
}

bool IndexModel::IndexModelImpl::setDef_T(const std::string& def_T)
{
  return assign_if_valid<double>(def_T, m_def_T);
}

int IndexModel::IndexModelImpl::udefT() const
{
  return m_udefT;
}

void IndexModel::IndexModelImpl::setUdefT(const int udefT)
{
  m_udefT = udefT;
}

double IndexModel::IndexModelImpl::rel_N() const
{
  return to<double>(m_rel_N);
}

bool IndexModel::IndexModelImpl::setRel_N(const double rel_N)
{
  m_rel_N = to_float(rel_N);
  return true;
}

bool IndexModel::IndexModelImpl::setRel_N(const std::string& rel_N)
{
  return assign_if_valid<double>(rel_N, m_rel_N);
}

double IndexModel::IndexModelImpl::wind_H() const
{
  return to<double>(m_wind_H);
}

bool IndexModel::IndexModelImpl::setWind_H(const double wind_H)
{
  m_wind_H = to_float(wind_H);
  return true;
}

bool IndexModel::IndexModelImpl::setWind_H(const std::string& wind_H)
{
  return assign_if_valid<double>(wind_H, m_wind_H);
}

int IndexModel::IndexModelImpl::uwH() const
{
  return m_uwH;
}

void IndexModel::IndexModelImpl::setUwH(const int uwH)
{
  m_uwH = uwH;
}

double IndexModel::IndexModelImpl::wind_Ao() const
{
  return to<double>(m_wind_Ao);
}

bool IndexModel::IndexModelImpl::setWind_Ao(const double wind_Ao)
{
  m_wind_Ao = to_float(wind_Ao);
  return true;
}

bool IndexModel::IndexModelImpl::setWind_Ao(const std::string& wind_Ao)
{
  return assign_if_valid<double>(wind_Ao, m_wind_Ao);
}

double IndexModel::IndexModelImpl::wind_a() const
{
  return to<double>(m_wind_a);
}

bool IndexModel::IndexModelImpl::setWind_a(const double wind_a)
{
  m_wind_a = to_float(wind_a);
  return true;
}

bool IndexModel::IndexModelImpl::setWind_a(const std::string& wind_a)
{
  return assign_if_valid<double>(wind_a, m_wind_a);
}

double IndexModel::IndexModelImpl::scale() const
{
  return to<double>(m_scale);
}

bool IndexModel::IndexModelImpl::setScale(const double scale)
{
  m_scale = to_float(scale);
  return true;
}

bool IndexModel::IndexModelImpl::setScale(const std::string& scale)
{
  return assign_if_valid<double>(scale, m_scale);
}

int IndexModel::IndexModelImpl::uScale() const
{
  return m_uScale;
}

void IndexModel::IndexModelImpl::setUScale(const int uScale)
{
  m_uScale = uScale;
}

int IndexModel::IndexModelImpl::orgRow() const
{
  return m_orgRow;
}

void IndexModel::IndexModelImpl::setOrgRow(const int orgRow)
{
  m_orgRow = orgRow;
}

int IndexModel::IndexModelImpl::orgCol() const
{
  return m_orgCol;
}

void IndexModel::IndexModelImpl::setOrgCol(const int orgCol)
{
  m_orgCol = orgCol;
}

int IndexModel::IndexModelImpl::invYaxis() const
{
  return m_invYaxis;
}

void IndexModel::IndexModelImpl::setInvYaxis(const int invYaxis)
{
  m_invYaxis = invYaxis;
}

int IndexModel::IndexModelImpl::showGeom() const
{
  return m_showGeom;
}

void IndexModel::IndexModelImpl::setShowGeom(const int showGeom)
{
  m_showGeom = showGeom;
}

WeatherData IndexModel::IndexModelImpl::ssWeather() const
{
  return m_ssWeather;
}

void IndexModel::IndexModelImpl::setSsWeather(const WeatherData& ssWeather)
{
  m_ssWeather = ssWeather;
}

WeatherData IndexModel::IndexModelImpl::wptWeather() const
{
  return m_wptWeather;
}

void IndexModel::IndexModelImpl::setWptWeather(const WeatherData& wptWeather)
{
  m_wptWeather = wptWeather;
}

std::string IndexModel::IndexModelImpl::WTHpath() const
{
  return m_WTHpath;
}

void IndexModel::IndexModelImpl::setWTHpath(const std::string& WTHpath)
{
  m_WTHpath = WTHpath;
}

std::string IndexModel::IndexModelImpl::CTMpath() const
{
  return m_CTMpath;
}

void IndexModel::IndexModelImpl::setCTMpath(const std::string& CTMpath)
{
  m_CTMpath = CTMpath;
}

std::string IndexModel::IndexModelImpl::CVFpath() const
{
  return m_CVFpath;
}

void IndexModel::IndexModelImpl::setCVFpath(const std::string& CVFpath)
{
  m_CVFpath = CVFpath;
}

std::string IndexModel::IndexModelImpl::DVFpath() const
{
  return m_DVFpath;
}

void IndexModel::IndexModelImpl::setDVFpath(const std::string& DVFpath)
{
  m_DVFpath = DVFpath;
}

std::string IndexModel::IndexModelImpl::WPCfile() const
{
  return m_WPCfile;
}

void IndexModel::IndexModelImpl::setWPCfile(const std::string& WPCfile)
{
  m_WPCfile = WPCfile;
}

std::string IndexModel::IndexModelImpl::EWCfile() const
{
  return m_EWCfile;
}

void IndexModel::IndexModelImpl::setEWCfile(const std::string& EWCfile)
{
  m_EWCfile = EWCfile;
}

std::string IndexModel::IndexModelImpl::WPCdesc() const
{
  return m_WPCdesc;
}

void IndexModel::IndexModelImpl::setWPCdesc(const std::string& WPCdesc)
{
  m_WPCdesc = WPCdesc;
}

double IndexModel::IndexModelImpl::X0() const
{
  return to<double>(m_X0);
}

bool IndexModel::IndexModelImpl::setX0(const double X0)
{
  m_X0 = to_float(X0);
  return true;
}

bool IndexModel::IndexModelImpl::setX0(const std::string& X0)
{
  return assign_if_valid<double>(X0, m_X0);
}

double IndexModel::IndexModelImpl::Y0() const
{
  return to<double>(m_Y0);
}

bool IndexModel::IndexModelImpl::setY0(const double Y0)
{
  m_Y0 = to_float(Y0);
  return true;
}

bool IndexModel::IndexModelImpl::setY0(const std::string& Y0)
{
  return assign_if_valid<double>(Y0, m_Y0);
}

double IndexModel::IndexModelImpl::Z0() const
{
  return to<double>(m_Z0);
}

bool IndexModel::IndexModelImpl::setZ0(const double Z0)
{
  m_Z0 = to_float(Z0);
  return true;
}

bool IndexModel::IndexModelImpl::setZ0(const std::string& Z0)
{
  return assign_if_valid<double>(Z0, m_Z0);
}

double IndexModel::IndexModelImpl::angle() const
{
  return to<double>(m_angle);
}

bool IndexModel::IndexModelImpl::setAngle(const double angle)
{
  m_angle = to_float(angle);
  return true;
}

bool IndexModel::IndexModelImpl::setAngle(const std::string& angle)
{
  return assign_if_valid<double>(angle, m_angle);
}

int IndexModel::IndexModelImpl::u_XYZ() const
{
  return m_u_XYZ;
}

void IndexModel::IndexModelImpl::setU_XYZ(const int u_XYZ)
{
  m_u_XYZ = u_XYZ;
}

double IndexModel::IndexModelImpl::epsPath() const
{
  return to<double>(m_epsPath);
}

bool IndexModel::IndexModelImpl::setEpsPath(const double epsPath)
{
  m_epsPath = to_float(epsPath);
  return true;
}

bool IndexModel::IndexModelImpl::setEpsPath(const std::string& epsPath)
{
  return assign_if_valid<double>(epsPath, m_epsPath);
}

double IndexModel::IndexModelImpl::epsSpcs() const
{
  return to<double>(m_epsSpcs);
}

bool IndexModel::IndexModelImpl::setEpsSpcs(const double epsSpcs)
{
  m_epsSpcs = to_float(epsSpcs);
  return true;
}

bool IndexModel::IndexModelImpl::setEpsSpcs(const std::string& epsSpcs)
{
  return assign_if_valid<double>(epsSpcs, m_epsSpcs);
}

std::string IndexModel::IndexModelImpl::tShift() const
{
  return m_tShift;
}

void IndexModel::IndexModelImpl::setTShift(const std::string& tShift)
{
  m_tShift = tShift;
}

std::string IndexModel::IndexModelImpl::dStart() const
{
  return m_dStart;
}

void IndexModel::IndexModelImpl::setDStart(const std::string& dStart)
{
  m_dStart = dStart;
}

std::string IndexModel::IndexModelImpl::dEnd() const
{
  return m_dEnd;
}

void IndexModel::IndexModelImpl::setDEnd(const std::string& dEnd)
{
  m_dEnd = dEnd;
}

int IndexModel::IndexModelImpl::useWPCwp() const
{
  return m_useWPCwp;
}

void IndexModel::IndexModelImpl::setUseWPCwp(const int useWPCwp)
{
  m_useWPCwp = useWPCwp;
}

int IndexModel::IndexModelImpl::useWPCmf() const
{
  return m_useWPCmf;
}

void IndexModel::IndexModelImpl::setUseWPCmf(const int useWPCmf)
{
  m_useWPCmf = useWPCmf;
}

int IndexModel::IndexModelImpl::wpctrig() const
{
  return m_wpctrig;
}

void IndexModel::IndexModelImpl::setWpctrig(const int wpctrig)
{
  m_wpctrig = wpctrig;
}

double IndexModel::IndexModelImpl::latd() const
{
  return to<double>(m_latd);
}

bool IndexModel::IndexModelImpl::setLatd(const double latd)
{
  m_latd = to_float(latd);
  return true;
}

bool IndexModel::IndexModelImpl::setLatd(const std::string& latd)
{
  return assign_if_valid<double>(latd, m_latd);
}

double IndexModel::IndexModelImpl::lgtd() const
{
  return to<double>(m_lgtd);
}

bool IndexModel::IndexModelImpl::setLgtd(const double lgtd)
{
  m_lgtd = to_float(lgtd);
  return true;
}

bool IndexModel::IndexModelImpl::setLgtd(const std::string& lgtd)
{
  return assign_if_valid<double>(lgtd, m_lgtd);
}

double IndexModel::IndexModelImpl::Tznr() const
{
  return to<double>(m_Tznr);
}

bool IndexModel::IndexModelImpl::setTznr(const double Tznr)
{
  m_Tznr = to_float(Tznr);
  return true;
}

bool IndexModel::IndexModelImpl::setTznr(const std::string& Tznr)
{
  return assign_if_valid<double>(Tznr, m_Tznr);
}

double IndexModel::IndexModelImpl::altd() const
{
  return to<double>(m_altd);
}

bool IndexModel::IndexModelImpl::setAltd(const double altd)
{
  m_altd = to_float(altd);
  return true;
}

bool IndexModel::IndexModelImpl::setAltd(const std::string& altd)
{
  return assign_if_valid<double>(altd, m_altd);
}

double IndexModel::IndexModelImpl::Tgrnd() const
{
  return to<double>(m_Tgrnd);
}

bool IndexModel::IndexModelImpl::setTgrnd(const double Tgrnd)
{
  m_Tgrnd = to_float(Tgrnd);
  return true;
}

bool IndexModel::IndexModelImpl::setTgrnd(const std::string& Tgrnd)
{
  return assign_if_valid<double>(Tgrnd, m_Tgrnd);
}

int IndexModel::IndexModelImpl::utg() const
{
  return m_utg;
}

void IndexModel::IndexModelImpl::setUtg(const int utg)
{
  m_utg = utg;
}

int IndexModel::IndexModelImpl::u_a() const
{
  return m_u_a;
}

void IndexModel::IndexModelImpl::setU_a(const int u_a)
{
  m_u_a = u_a;
}

RunControl IndexModel::IndexModelImpl::rc() const
{
  return m_rc;
}
void IndexModel::IndexModelImpl::setRc(const RunControl& rc)
{
  m_rc = rc;
}

std::vector<int> IndexModel::IndexModelImpl::contaminants()
{
  std::vector<int> active;
  int nr = 1;
  for (Species& species : m_species) {
    species.setNr(nr);
    if (species.sflag()) {
      active.push_back(nr);
    }
    nr++;
  }
  return active;
}

std::vector<Species> IndexModel::IndexModelImpl::species() const
{
  return m_species;
}

void IndexModel::IndexModelImpl::setSpecies(const std::vector<Species>& species)
{
  m_species = species;
}

void IndexModel::IndexModelImpl::addSpecies(Species& species)
{
  species.setNr(m_species.size() + 1);
  m_species.push_back(species);
}

bool IndexModel::IndexModelImpl::removeSpecies(const Species & species)
{
  unsigned originalSize = m_species.size();
  m_species.erase(std::remove_if(m_species.begin(), m_species.end(), [&](Species s) { return s == species; }), m_species.end());
  // There's probably a better way to do this
  if (m_species.size() != originalSize) {
    renumberVector(m_species);
    return true;
  }
  return false;
}

std::vector<Level> IndexModel::IndexModelImpl::levels() const
{
  return m_levels;
}

void IndexModel::IndexModelImpl::setLevels(const std::vector<Level> & levels)
{
  // This could use some validation, but we don't want to interfere too much in the loaded PRJ data
  m_levels = levels;
}

void IndexModel::IndexModelImpl::addLevel(Level & level)
{
  double refHt = 0;
  if (m_levels.size() > 0) {
    // Note that CONTAM stores heights in meters, so this next statement requires no conversion
    refHt = m_levels[m_levels.size() - 1].refht() + m_levels[m_levels.size() - 1].delht();
  }
  level.setNr(m_levels.size() + 1);
  level.setRefht(refHt);
  m_levels.push_back(level);
}

std::vector<DaySchedule> IndexModel::IndexModelImpl::daySchedules() const
{
  return m_daySchedules;
}

void IndexModel::IndexModelImpl::setDaySchedules(const std::vector<DaySchedule> & daySchedules)
{
  m_daySchedules = daySchedules;
}

std::vector<WeekSchedule> IndexModel::IndexModelImpl::weekSchedules() const
{
  return m_weekSchedules;
}
void IndexModel::IndexModelImpl::setWeekSchedules(const std::vector<WeekSchedule> & weekSchedules)
{
  m_weekSchedules = weekSchedules;
}

std::vector<WindPressureProfile> IndexModel::IndexModelImpl::windPressureProfiles() const
{
  return m_windPressureProfiles;
}
void IndexModel::IndexModelImpl::setWindPressureProfiles(const std::vector<WindPressureProfile> & windPressureProfiles)
{
  m_windPressureProfiles = windPressureProfiles;
}

std::vector<Ahs> IndexModel::IndexModelImpl::ahs() const
{
  return m_ahs;
}

void IndexModel::IndexModelImpl::setAhs(const std::vector<Ahs> & ahs)
{
  m_ahs = ahs;
}

void IndexModel::IndexModelImpl::addAhs(Ahs & ahs)
{
  ahs.setNr(m_ahs.size() + 1);
  m_ahs.push_back(ahs);
}

std::vector<Zone> IndexModel::IndexModelImpl::zones() const
{
  return m_zones;
}

void IndexModel::IndexModelImpl::setZones(const std::vector<Zone> & zones)
{
  m_zones = zones;
}

void IndexModel::IndexModelImpl::addZone(Zone & zone)
{
  zone.setNr(m_zones.size() + 1);
  m_zones.push_back(zone);
}

bool IndexModel::IndexModelImpl::valid() const
{
  return m_valid;
}

std::vector<AirflowPath> IndexModel::IndexModelImpl::airflowPaths() const
{
  return m_paths;
}

void IndexModel::IndexModelImpl::setAirflowPaths(const std::vector<AirflowPath> & paths)
{
  m_paths = paths;
}

void IndexModel::IndexModelImpl::addAirflowPath(AirflowPath & path)
{
  path.setNr(m_paths.size() + 1);
  m_paths.push_back(path);
}

void IndexModel::IndexModelImpl::readZoneIc(Reader & input)
{
  unsigned int nn = input.readUInt();
  if (nn != 0) {
    unsigned int nctm = contaminants().size();
    if (nn != nctm * m_zones.size()) {
      LOG_FATAL("Mismatch between number of zones, contaminants, and initial conditions");
    }
    for (unsigned int i = 0; i < m_zones.size(); i++) {
      unsigned int nr = input.readUInt();
      if (nr != i + 1) {
        LOG_FATAL("Mismatch between zone IC number and zone number at line " + std::to_string(input.lineNumber()));
      }
      std::vector<std::string> ic;
      for (unsigned int j = 0; j < nctm; j++) {
        ic.push_back(input.readNumber<std::string>());
      }
      m_zones[i].setIc(ic);
    }
  }
  input.read999("Failed to find zone IC section termination");
}

std::string IndexModel::IndexModelImpl::writeZoneIc(int start)
{
  int offset = 1;
  if (start != 0) {
    offset = 1 - start;
  }
  int ncontaminants = contaminants().size();
  int nctm = ncontaminants * (m_zones.size() - start);
  std::string string = ANY_TO_STR(nctm) + " ! initial zone concentrations:\n";
  if (nctm) {
    for (unsigned i = start; i < m_zones.size(); i++) {
      string += ANY_TO_STR(i + offset);
      for (unsigned j = 0; j < (unsigned)ncontaminants; j++) {
        string += ' ' + ANY_TO_STR(m_zones[i].ic(j));
      }
      string += '\n';
    }
  }
  return string + "-999\n";
}

int IndexModel::IndexModelImpl::airflowElementNrByName(std::string name) const
{
  for (unsigned i = 0; i < m_airflowElements.size(); i++) {
    if (m_airflowElements[i]->name() == name) {
      return m_airflowElements[i]->nr();
    }
  }
  return 0;
}

std::vector<std::vector<int> > IndexModel::IndexModelImpl::zoneExteriorFlowPaths()
{
  std::vector<std::vector<int> > paths(m_zones.size());

  for (unsigned int i = 0; i < m_paths.size(); i++) {
    if (m_paths[i].pzn() == -1) {
      int nr = m_paths[i].pzm();
      if (nr > 0 && (unsigned int)nr <= m_zones.size()) {
        paths[nr - 1].push_back(-m_paths[i].nr()); // This flow path is negative for flow into zone
      }
    } else if (m_paths[i].pzm() == -1) {
      int nr = m_paths[i].pzn();
      if (nr > 0 && (unsigned int)nr <= m_zones.size()) {
        paths[nr - 1].push_back(m_paths[i].nr()); // This flow path is positive for flow into zone
      }
    }
  }
  return paths;
}

//std::vector<TimeSeries> IndexModel::IndexModelImpl::zoneInfiltration(SimFile *sim)
//{
//  // This should probably include a lot more checks of things and is written in
//  // somewhat strange way to avoid taking too much advantage of the specifics
//  // of the text form outputs.
//  std::vector<TimeSeries> results;
//  std::vector<std::vector<int> > paths = zoneExteriorFlowPaths();
//  unsigned int ntimes = sim->dateTimes().size();
//  for(unsigned int i=0; i<m_zones.size(); i++)
//  {
//    // This is lame, but I can't tell for sure if the values of a Vector are actually zero.
//    Vector inf = createVector(std::vector<double>(ntimes,0));
//    for(unsigned int j=0; j<paths[i].size(); j++)
//    {
//      if(paths[i][j] > 0) // Positive values are infiltration
//      {
//        boost::optional<openstudio::TimeSeries> optFlow = sim->pathFlow(paths[i][j]);
//        if(optFlow)
//        {
//          Vector flow = optFlow.get().values();
//          for(unsigned int k=0; k<ntimes; k++)
//          {
//            if(flow[k] > 0)
//            {
//              inf[k] += flow[k];
//            }
//          }
//        }
//        else
//        {
//          // Perhaps a warning? This shouldn't really happen unless someone has excluded a path from the
//          // results file for some reason - which is unlikely to be accidental. So there must be a good reason
//          // for getting here, and for now we won't issue a warning.
//        }
//      }
//      else // Negative values are infiltration
//      {
//        boost::optional<openstudio::TimeSeries> optFlow = sim->pathFlow(paths[i][j]);
//        if(optFlow)
//        {
//          Vector flow = optFlow.get().values();
//          for(unsigned int k=0; k<ntimes; k++)
//          {
//            if(flow[k] < 0)
//            {
//              inf[k] -= flow[k];
//            }
//          }
//        }
//        else
//        {
//          // See above comment
//        }
//      }
//    }
//    results.push_back(openstudio::TimeSeries(sim->dateTimes(),inf,"kg/s"));
//  }
//  return results;
//}
//
//std::vector<TimeSeries> IndexModel::IndexModelImpl::pathInfiltration(std::vector<int> pathNrs, SimFile *sim)
//{
//  // This should probably include a lot more checks of things and is written in
//  // somewhat strange way to avoid taking too much advantage of the specifics
//  // of the text form outputs.
//  std::vector<TimeSeries> results;
//  std::vector<std::vector<int> > paths = zoneExteriorFlowPaths();
//  unsigned int ntimes = 1;
//  std::vector<DateTime> dateTimes = sim->dateTimes();
//  if(sim->dateTimes().size()!=1)
//  {
//    ntimes = sim->dateTimes().size()-1;
//    dateTimes = std::vector<DateTime>(dateTimes.begin() + 1,dateTimes.end());
//  }
//  for(unsigned int i=0; i<pathNrs.size(); i++)
//  {
//    Vector inf = createVector(std::vector<double>(ntimes,0.0));
//    if(pathNrs[i]<=0 || (unsigned)pathNrs[i] > m_paths.size())
//    {
//      // Possibly should issue a warning here, the path number is out of range
//    }
//    else
//    {
//      contam::AirflowPath path = m_paths[pathNrs[i]-1];
//      if(path.pzn() == -1)
//      {
//        // This flow path is negative for flow into zone
//        boost::optional<openstudio::TimeSeries> optFlow = sim->pathFlow(path.nr());
//        if(optFlow)
//        {
//          Vector flow = optFlow.get().values();
//          for(unsigned int k=0; k<ntimes; k++)
//          {
//            if(flow[k] < 0)
//            {
//              inf[k] = -flow[k];
//            }
//          }
//        }
//        else
//        {
//          // Perhaps a warning? This shouldn't really happen unless someone has excluded a path from the
//          // results file for some reason - which is unlikely to be accidental. So there must be a good reason
//          // for getting here, and for now we won't issue a warning.
//        }
//      }
//      else if(path.pzm() == -1)
//      {
//        // This flow path is positive for flow into zone
//        boost::optional<openstudio::TimeSeries> optFlow = sim->pathFlow(path.nr());
//        if(optFlow)
//        {
//          Vector flow = optFlow.get().values();
//          for(unsigned int k=0; k<ntimes; k++)
//          {
//            if(flow[k] > 0)
//            {
//              inf[k] = flow[k];
//            }
//          }
//        }
//        else
//        {
//          // Perhaps a warning? This shouldn't really happen unless someone has excluded a path from the
//          // results file for some reason - which is unlikely to be accidental. So there must be a good reason
//          // for getting here, and for now we won't issue a warning.
//        }
//      }
//      else
//      {
//        // Another situation that might need a warning, since the path is not connected to the ambient
//      }
//    }
//    // Save the time series
//    results.push_back(openstudio::TimeSeries(dateTimes,inf,"kg/s"));
//  }
//  return results;
//}

} // prjmodel
