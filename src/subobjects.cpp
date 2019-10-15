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

#include "subobjects.hpp"

#include "utility_functions.hpp"

namespace prjmodel {

WeatherData::WeatherData() :
  m_impl(std::shared_ptr<WeatherData::Impl>(new WeatherData::Impl))
{}

WeatherData::WeatherData(const WeatherData &other) : m_impl(other.m_impl)
{}

WeatherData::~WeatherData()
{}

WeatherData& WeatherData::operator=(const WeatherData &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool WeatherData::operator==(const WeatherData &other) const
{
  return m_impl==other.m_impl;
}

bool WeatherData::operator!=(const WeatherData &other) const
{
  return m_impl!=other.m_impl;
}

WeatherData::WeatherData::Impl::Impl() : m_Tambt(PRJFLOAT("0.0")), m_barpres(PRJFLOAT("0.0")), m_windspd(PRJFLOAT("0.0")),
m_winddir(PRJFLOAT("0.0")), m_relhum(PRJFLOAT("0.0")), m_daytyp(0), m_uTa(0), m_ubP(0), m_uws(0), m_uwd(0)
{}

WeatherData::WeatherData(std::string Tambt, std::string barpres, std::string windspd, std::string winddir, std::string relhum,
  int daytyp, int uTa, int ubP, int uws, int uwd) : WeatherData()
{
  setTambt(Tambt);
  setBarpres(barpres);
  setWindspd(windspd);
  setWinddir(winddir);
  setRelhum(relhum);
  setDaytyp(daytyp);
  setUTa(uTa);
  setUbP(ubP);
  setUws(uws);
  setUwd(uwd);
}

WeatherData::WeatherData(double Tambt, double barpres, double windspd, double winddir, double relhum,
  int daytyp, int uTa, int ubP, int uws, int uwd) : WeatherData()
{
  setTambt(Tambt);
  setBarpres(barpres);
  setWindspd(windspd);
  setWinddir(winddir);
  setRelhum(relhum);
  setDaytyp(daytyp);
  setUTa(uTa);
  setUbP(ubP);
  setUws(uws);
  setUwd(uwd);
}

void WeatherData::read(Reader& input)
{
  setTambt(input.readNumber<std::string>());
  setBarpres(input.readNumber<std::string>());
  setWindspd(input.readNumber<std::string>());
  setWinddir(input.readNumber<std::string>());
  setRelhum(input.readNumber<std::string>());
  setDaytyp(input.read<int>());
  setUTa(input.read<int>());
  setUbP(input.read<int>());
  setUws(input.read<int>());
  setUwd(input.read<int>());
}

std::string WeatherData::write()
{
  std::string string;
  string += PRJFLOAT_TO_STR(m_impl->m_Tambt) + ' ' + PRJFLOAT_TO_STR(m_impl->m_barpres) + ' ' + PRJFLOAT_TO_STR(m_impl->m_windspd) + ' ' + PRJFLOAT_TO_STR(m_impl->m_winddir) + ' ' + PRJFLOAT_TO_STR(m_impl->m_relhum) + ' ' + ANY_TO_STR(m_impl->m_daytyp) + ' ' + ANY_TO_STR(m_impl->m_uTa) + ' ' + ANY_TO_STR(m_impl->m_ubP) + ' ' + ANY_TO_STR(m_impl->m_uws) + ' ' + ANY_TO_STR(m_impl->m_uwd) + '\n';
  return string;
}

template<> double PRJMODEL_API WeatherData::Tambt() const
{
  return to<double>(m_impl->m_Tambt);
}

template<> std::string PRJMODEL_API WeatherData::Tambt() const
{
  return m_impl->m_Tambt;
}

bool WeatherData::setTambt(const double Tambt)
{
  m_impl->m_Tambt = to_float(Tambt);
  return true;
}

bool WeatherData::setTambt(const std::string& Tambt)
{
  return assign_if_valid<double>(Tambt, m_impl->m_Tambt);
}

template<> double PRJMODEL_API WeatherData::barpres() const
{
  return to<double>(m_impl->m_barpres);
}

template<> std::string PRJMODEL_API WeatherData::barpres() const
{
  return m_impl->m_barpres;
}

bool WeatherData::setBarpres(const double barpres)
{
  m_impl->m_barpres = to_float(barpres);
  return true;
}

bool WeatherData::setBarpres(const std::string& barpres)
{
  return assign_if_valid<double>(barpres, m_impl->m_barpres);
}

template<> double PRJMODEL_API WeatherData::windspd() const
{
  return to<double>(m_impl->m_windspd);
}

template<> std::string PRJMODEL_API WeatherData::windspd() const
{
  return m_impl->m_windspd;
}

bool WeatherData::setWindspd(const double windspd)
{
  m_impl->m_windspd = to_float(windspd);
  return true;
}

bool WeatherData::setWindspd(const std::string& windspd)
{
  return assign_if_valid<double>(windspd, m_impl->m_windspd);
}

template<> double PRJMODEL_API WeatherData::winddir() const
{
  return to<double>(m_impl->m_winddir);
}

template<> std::string PRJMODEL_API WeatherData::winddir() const
{
  return m_impl->m_winddir;
}

bool WeatherData::setWinddir(const double winddir)
{
  m_impl->m_winddir = to_float(winddir);
  return true;
}

bool WeatherData::setWinddir(const std::string& winddir)
{
  return assign_if_valid<double>(winddir, m_impl->m_winddir);
}

template<> double PRJMODEL_API WeatherData::relhum() const
{
  return to<double>(m_impl->m_relhum);
}

template<> std::string PRJMODEL_API WeatherData::relhum() const
{
  return m_impl->m_relhum;
}

bool WeatherData::setRelhum(const double relhum)
{
  m_impl->m_relhum = to_float(relhum);
  return true;
}

bool WeatherData::setRelhum(const std::string& relhum)
{
  return assign_if_valid<double>(relhum, m_impl->m_relhum);
}

int WeatherData::daytyp() const
{
  return  m_impl->m_daytyp;
}

void WeatherData::setDaytyp(const int daytyp)
{
  m_impl->m_daytyp = daytyp;
}

int WeatherData::uTa() const
{
  return  m_impl->m_uTa;
}

void WeatherData::setUTa(const int uTa)
{
  m_impl->m_uTa = uTa;
}

int WeatherData::ubP() const
{
  return  m_impl->m_ubP;
}

void WeatherData::setUbP(const int ubP)
{
  m_impl->m_ubP = ubP;
}

int WeatherData::uws() const
{
  return  m_impl->m_uws;
}

void WeatherData::setUws(const int uws)
{
  m_impl->m_uws = uws;
}

int WeatherData::uwd() const
{
  return  m_impl->m_uwd;
}

void WeatherData::setUwd(const int uwd)
{
  m_impl->m_uwd = uwd;
}

Icon::Icon() :
  m_impl(std::shared_ptr<IconImpl>(new IconImpl()))
{}

Icon::Icon(int icon,int col,int row,int nr) :
  m_impl(std::shared_ptr<IconImpl>(new IconImpl(icon,col,row,nr)))
{}

Icon::Icon(const Icon &other) : m_impl(other.m_impl)
{}

Icon::~Icon()
{}

Icon& Icon::operator=(const Icon &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool Icon::operator==(const Icon &other) const
{
  return m_impl==other.m_impl;
}

bool Icon::operator!=(const Icon &other) const
{
  return m_impl!=other.m_impl;
}

std::string Icon::write()
{
  return m_impl->write();
}

void Icon::read(Reader &input)
{
  m_impl->read(input);
}

int Icon::icon() const
{
  return m_impl->icon();
}

void Icon::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

int Icon::col() const
{
  return m_impl->col();
}

void Icon::setCol(const int col)
{
  m_impl->setCol(col);
}

int Icon::row() const
{
  return m_impl->row();
}

void Icon::setRow(const int row)
{
  m_impl->setRow(row);
}

int Icon::nr() const
{
  return m_impl->nr();
}

void Icon::setNr(const int nr)
{
  m_impl->setNr(nr);
}

bool Icon::isWall()
{
  return m_impl->isWall();
}

Icon::IconImpl::IconImpl() : m_icon(0), m_col(0), m_row(0), m_nr(0)
{}

Icon::IconImpl::IconImpl(int icon, int col, int row, int nr) : Icon::IconImpl()
{
  setIcon(icon);
  setCol(col);
  setRow(row);
  setNr(nr);
}

void Icon::IconImpl::read(Reader& input)
{
  setIcon(input.read<int>());
  setCol(input.read<int>());
  setRow(input.read<int>());
  setNr(input.read<int>());
}

std::string Icon::IconImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_icon) + ' ' + ANY_TO_STR(m_col) + ' ' + ANY_TO_STR(m_row) + ' ' + ANY_TO_STR(m_nr) + '\n';
  return string;
}

int Icon::IconImpl::icon() const
{
  return m_icon;
}

void Icon::IconImpl::setIcon(const int icon)
{
  m_icon = icon;
}

int Icon::IconImpl::col() const
{
  return m_col;
}

void Icon::IconImpl::setCol(const int col)
{
  m_col = col;
}

int Icon::IconImpl::row() const
{
  return m_row;
}

void Icon::IconImpl::setRow(const int row)
{
  m_row = row;
}

int Icon::IconImpl::nr() const
{
  return m_nr;
}

void Icon::IconImpl::setNr(const int nr)
{
  m_nr = nr;
}

bool Icon::IconImpl::isWall()
{
  return (m_icon >= WL_EW) && (m_icon <= WL_NESW);
}

FanDataPoint::FanDataPoint() : m_mF(PRJFLOAT("0.0")), m_u_mF(0), m_dP(PRJFLOAT("0.0")), m_u_dP(0), m_rP(PRJFLOAT("0.0")), m_u_rP(0)
{}

FanDataPoint::FanDataPoint(double mF,int u_mF,double dP,int u_dP,double rP,int u_rP) : FanDataPoint()
{
  setMF(mF);
  setU_mF(u_mF);
  setDP(dP);
  setU_dP(u_dP);
  setRP(rP);
  setU_rP(u_rP);
}

FanDataPoint::FanDataPoint(std::string mF,int u_mF,std::string dP,int u_dP,std::string rP,int u_rP) : FanDataPoint()
{
  setMF(mF);
  setU_mF(u_mF);
  setDP(dP);
  setU_dP(u_dP);
  setRP(rP);
  setU_rP(u_rP);
}

void FanDataPoint::read(Reader &input)
{
  setMF(input.readNumber<std::string>());
  setU_mF(input.read<int>());
  setDP(input.readNumber<std::string>());
  setU_dP(input.read<int>());
  setRP(input.readNumber<std::string>());
  setU_rP(input.read<int>());
}

std::string FanDataPoint::write()
{
  std::string string;
  string += PRJFLOAT_TO_STR(m_mF) + ' ' + ANY_TO_STR(m_u_mF) + ' ' + PRJFLOAT_TO_STR(m_dP) + ' ' + ANY_TO_STR(m_u_dP) + ' ' + PRJFLOAT_TO_STR(m_rP) + ' ' + ANY_TO_STR(m_u_rP) + '\n';
  return string;
}

double FanDataPoint::mF() const
{
  return to<double>(m_mF);
}

bool FanDataPoint::setMF(const double mF)
{
  m_mF = to_float(mF);
  return true;
}

bool FanDataPoint::setMF(const std::string &mF)
{
  return assign_if_valid<double>(mF, m_mF);
}

int FanDataPoint::u_mF() const
{
  return m_u_mF;
}

void FanDataPoint::setU_mF(const int u_mF)
{
  m_u_mF = u_mF;
}

double FanDataPoint::dP() const
{
  return to<double>(m_dP);
}

bool FanDataPoint::setDP(const double dP)
{
  m_dP = to_float(dP);
  return true;
}

bool FanDataPoint::setDP(const std::string &dP)
{
  return assign_if_valid<double>(dP, m_dP);
}

int FanDataPoint::u_dP() const
{
  return m_u_dP;
}

void FanDataPoint::setU_dP(const int u_dP)
{
  m_u_dP = u_dP;
}

double FanDataPoint::rP() const
{
  return to<double>(m_rP);
}

bool FanDataPoint::setRP(const double rP)
{
  m_rP = to_float(rP);
  return true;
}

bool FanDataPoint::setRP(const std::string &rP)
{
  return assign_if_valid<double>(rP, m_rP);
}

int FanDataPoint::u_rP() const
{
  return m_u_rP;
}

void FanDataPoint::setU_rP(const int u_rP)
{
  m_u_rP = u_rP;
}

void XyDataPoint::setDefaults()
{
  m_x = PRJFLOAT("0.0");
  m_y = PRJFLOAT("0.0");
}

XyDataPoint::XyDataPoint()
{
  setDefaults();
}

XyDataPoint::XyDataPoint(double x,double y)
{
  setDefaults();
  setX(x);
  setY(y);
}

XyDataPoint::XyDataPoint(std::string x,std::string y)
{
  setDefaults();
  setX(x);
  setY(y);
}

void XyDataPoint::read(Reader &input)
{
  setX(input.readNumber<std::string>());
  setY(input.readNumber<std::string>());
}

std::string XyDataPoint::write()
{
  std::string string;
  string += PRJFLOAT_TO_STR(m_x) + ' ' + PRJFLOAT_TO_STR(m_y) + '\n';
  return string;
}

double XyDataPoint::x() const
{
  return to<double>(m_x);
}

bool XyDataPoint::setX(const double x)
{
  m_x = to_float(x);
  return true;
}

bool XyDataPoint::setX(const std::string &x)
{
  return assign_if_valid<double>(x, m_x);
}

double XyDataPoint::y() const
{
  return to<double>(m_y);
}

bool XyDataPoint::setY(const double y)
{
  m_y = to_float(y);
  return true;
}

bool XyDataPoint::setY(const std::string &y)
{
  return assign_if_valid<double>(y, m_y);
}

AirflowSubelementData::AirflowSubelementData() : m_nr(0), m_relHt(PRJFLOAT("0.0")), m_filt(0)
{}

AirflowSubelementData::AirflowSubelementData(int nr,double relHt,int filt) : AirflowSubelementData()
{
  setNr(nr);
  setRelHt(relHt);
  setFilt(filt);
}

AirflowSubelementData::AirflowSubelementData(int nr,std::string relHt,int filt) : AirflowSubelementData()
{
  setNr(nr);
  setRelHt(relHt);
  setFilt(filt);
}

void AirflowSubelementData::read(Reader &input)
{
  setNr(input.read<int>());
  setRelHt(input.readNumber<std::string>());
  setFilt(input.read<int>());
}

std::string AirflowSubelementData::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + PRJFLOAT_TO_STR(m_relHt) + ' ' + ANY_TO_STR(m_filt) + '\n';
  return string;
}

int AirflowSubelementData::nr() const
{
  return m_nr;
}

void AirflowSubelementData::setNr(const int nr)
{
  m_nr = nr;
}

double AirflowSubelementData::relHt() const
{
  return to<double>(m_relHt);
}

bool AirflowSubelementData::setRelHt(const double relHt)
{
  m_relHt = to_float(relHt);
  return true;
}

bool AirflowSubelementData::setRelHt(const std::string &relHt)
{
  return assign_if_valid<double>(relHt, m_relHt);
}

int AirflowSubelementData::filt() const
{
  return m_filt;
}

void AirflowSubelementData::setFilt(const int filt)
{
  m_filt = filt;
}

void PressureCoefficientPoint::setDefaults()
{
  m_azm = PRJFLOAT("0.0");
  m_coef = PRJFLOAT("0.0");
}

PressureCoefficientPoint::PressureCoefficientPoint()
{
  setDefaults();
}

PressureCoefficientPoint::PressureCoefficientPoint(double azm,double coef)
{
  setDefaults();
  setAzm(azm);
  setCoef(coef);
}

PressureCoefficientPoint::PressureCoefficientPoint(std::string azm,std::string coef)
{
  setDefaults();
  setAzm(azm);
  setCoef(coef);
}

void PressureCoefficientPoint::read(Reader &input)
{
  setAzm(input.readNumber<std::string>());
  setCoef(input.readNumber<std::string>());
}

std::string PressureCoefficientPoint::write()
{
  std::string string;
  string += PRJFLOAT_TO_STR(m_azm) + ' ' + PRJFLOAT_TO_STR(m_coef) + '\n';
  return string;
}

double PressureCoefficientPoint::azm() const
{
  return to<double>(m_azm);
}

bool PressureCoefficientPoint::setAzm(const double azm)
{
  m_azm = to_float(azm);
  return true;
}

bool PressureCoefficientPoint::setAzm(const std::string &azm)
{
  return assign_if_valid<double>(azm, m_azm);
}

double PressureCoefficientPoint::coef() const
{
  return to<double>(m_coef);
}

bool PressureCoefficientPoint::setCoef(const double coef)
{
  m_coef = to_float(coef);
  return true;
}

bool PressureCoefficientPoint::setCoef(const std::string &coef)
{
  return assign_if_valid<double>(coef, m_coef);
}

void SchedulePoint::setDefaults()
{
  m_time = std::string("00:00:00");
  m_ctrl = PRJFLOAT("0.0");
}

SchedulePoint::SchedulePoint()
{
  setDefaults();
}

SchedulePoint::SchedulePoint(std::string time,double ctrl)
{
  setDefaults();
  setTime(time);
  setCtrl(ctrl);
}

SchedulePoint::SchedulePoint(std::string time,std::string ctrl)
{
  setDefaults();
  setTime(time);
  setCtrl(ctrl);
}

void SchedulePoint::read(Reader &input)
{
  setTime(input.readString());
  setCtrl(input.readNumber<std::string>());
}

std::string SchedulePoint::write()
{
  std::string string;
  string += m_time + ' ' + PRJFLOAT_TO_STR(m_ctrl) + '\n';
  return string;
}

std::string SchedulePoint::time() const
{
  return m_time;
}

void SchedulePoint::setTime(const std::string &time)
{
  m_time = time;
}

double SchedulePoint::ctrl() const
{
  return to<double>(m_ctrl);
}

bool SchedulePoint::setCtrl(const double ctrl)
{
  m_ctrl = to_float(ctrl);
  return true;
}

bool SchedulePoint::setCtrl(const std::string &ctrl)
{
  return assign_if_valid<double>(ctrl, m_ctrl);
}

} // prjmodel
