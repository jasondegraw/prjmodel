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

#include "airflowelements.hpp"

#include "logging.hpp"
#include <algorithm>

namespace prjmodel {

AirflowElement::Type AirflowElement::convertTag(std::string string)
{
  std::string tags[28] = {std::string("plr_orfc"),std::string("plr_leak1"),
    std::string("plr_leak2"),std::string("plr_leak3"),std::string("plr_conn"),
    std::string("plr_qcn"),std::string("plr_fcn"),std::string("plr_test1"),
    std::string("plr_test2"),std::string("plr_crack"),std::string("plr_stair"),
    std::string("plr_shaft"),std::string("plr_bdq"),std::string("plr_bdf"),
    std::string("qfr_qab"),std::string("qfr_fab"),std::string("qfr_crack"),
    std::string("qfr_test2"),std::string("dor_door"),std::string("dor_pl2"),
    std::string("fan_cmf"),std::string("fan_cvf"),std::string("fan_fan"),
    std::string("csf_fsp"),std::string("csf_qsp"),std::string("csf_psf"),
    std::string("csf_psq"),std::string("sup_afe")};
  AirflowElement::Type type[28] = {PL_ORFC,PL_LEAK1,PL_LEAK2,PL_LEAK3,PL_CONN,PL_QCN,PL_FCN,
    PL_TEST1,PL_TEST2,PL_CRACK,PL_STAIR,PL_SHAFT,PL_BDQ,PL_BDF,QFR_QAB,QFR_QAF,QFR_CRACK,
    QFR_TEST2,DR_DOOR,DR_PL2,FN_CMF,FN_CVF,FN_FAN,CS_FSP,CS_QSP,CS_PSF,CS_PSQ,AF_SUP};
  for(int i=0;i<28;i++)
    if(string==tags[i])
      return type[i];
  return AirflowElement::UNKNOWN;
}

AirflowElement* AirflowElement::readElement(Reader &input)
{
  AirflowElement *out=nullptr;
  int nr = input.read<int>();
  int icon = input.read<int>();
  std::string dataType = input.readString();
  std::string name = input.readString();
  std::string desc = input.readLine();
  int kind = convertTag(dataType);
  switch(kind)
  {
  case AirflowElement::PL_ORFC:
    {
      PlrOrf *obj = new PlrOrf(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::PL_LEAK1:
    {
      PlrLeak1 *obj = new PlrLeak1(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::PL_LEAK2:
    {
      PlrLeak2 *obj = new PlrLeak2(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::PL_LEAK3:
    {
      PlrLeak3 *obj = new PlrLeak3(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::PL_CONN:
    {
      PlrConn *obj = new PlrConn(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::PL_QCN:
    {
      PlrQcn *obj = new PlrQcn(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::PL_FCN:
    {
      PlrFcn *obj = new PlrFcn(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::PL_TEST1:
    {
      PlrTest1 *obj = new PlrTest1(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::PL_TEST2:
    {
      PlrTest2 *obj = new PlrTest2(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::PL_CRACK:
    {
      PlrCrack *obj = new PlrCrack(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::PL_STAIR:
    {
      PlrStair *obj = new PlrStair(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::PL_SHAFT:
    {
      PlrShaft *obj = new PlrShaft(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::PL_BDQ:
    {
      PlrBdq *obj = new PlrBdq(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::PL_BDF:
    {
      PlrBdf *obj = new PlrBdf(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::QFR_QAB:
    {
      QfrQab *obj = new QfrQab(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::QFR_QAF:
    {
      QfrFab *obj = new QfrFab(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::QFR_CRACK:
    {
      QfrCrack *obj = new QfrCrack(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::QFR_TEST2:
    {
      QfrTest2 *obj = new QfrTest2(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::DR_DOOR:
    {
      AfeDor *obj = new AfeDor(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::DR_PL2:
    {
      DrPl2 *obj = new DrPl2(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::FN_CMF:
    {
      AfeCmf *obj = new AfeCmf(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::FN_CVF:
    {
      AfeCvf *obj = new AfeCvf(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::FN_FAN:
    {
      AfeFan *obj = new AfeFan(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::CS_FSP:
    {
      AfeFsp *obj = new AfeFsp(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::CS_QSP:
    {
      AfeQsp *obj = new AfeQsp(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::CS_PSF:
    {
      AfePsf *obj = new AfePsf(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::CS_PSQ:
    {
      AfePsq *obj = new AfePsq(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::AF_SUP:
    {
      AfeSup *obj = new AfeSup(nr,icon,name,desc);
      obj->readDetails(input);
      out = static_cast<AirflowElement*>(obj);
      break;
    }
  case AirflowElement::UNKNOWN:
  default:
    std::string mesg = "Unknown airflow element type '" + dataType + "' at line " + std::to_string(input.lineNumber());
    LOG_FATAL(mesg);
  }
  return out;
}

PlrOrf::PlrOrf() :
  m_impl(std::shared_ptr<Impl>(new Impl))
{}

PlrOrf::PlrOrf(const PlrOrf &other) : m_impl(other.m_impl)
{}

PlrOrf::~PlrOrf()
{}

PlrOrf& PlrOrf::operator=(const PlrOrf &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool PlrOrf::operator==(const PlrOrf &other) const
{
  return m_impl == other.m_impl;
}

bool PlrOrf::operator!=(const PlrOrf &other) const
{
  return m_impl != other.m_impl;
}

PlrOrf::Impl::Impl() : nr(0), icon(0), lam(PRJFLOAT("0.0")), turb(PRJFLOAT("0.0")), expt(PRJFLOAT("0.0")),
area(PRJFLOAT("0.0")), dia(PRJFLOAT("0.0")), coef(PRJFLOAT("0.0")), Re(PRJFLOAT("0.0")), u_A(0), u_D(0)
{}

PlrOrf::PlrOrf(int nr, int icon, std::string name, std::string desc) : PlrOrf()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrOrf::PlrOrf(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt, double area,
  double dia, double coef, double Re, int u_A, int u_D) : PlrOrf::PlrOrf()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setArea(area);
  setDia(dia);
  setCoef(coef);
  setRe(Re);
  setU_A(u_A);
  setU_D(u_D);
}

PlrOrf::PlrOrf(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt, std::string area,
  std::string dia, std::string coef, std::string Re, int u_A, int u_D) : PlrOrf::PlrOrf()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setArea(area);
  setDia(dia);
  setCoef(coef);
  setRe(Re);
  setU_A(u_A);
  setU_D(u_D);
}

void PlrOrf::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setArea(input.readNumber<std::string>());
  setDia(input.readNumber<std::string>());
  setCoef(input.readNumber<std::string>());
  setRe(input.readNumber<std::string>());
  setU_A(input.read<int>());
  setU_D(input.read<int>());
}

std::string PlrOrf::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + " plr_orfc " + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->lam) + ' ' + PRJFLOAT_TO_STR(m_impl->turb) + ' ' + PRJFLOAT_TO_STR(m_impl->expt) + ' ' + PRJFLOAT_TO_STR(m_impl->area)
    + ' ' + PRJFLOAT_TO_STR(m_impl->dia) + ' ' + PRJFLOAT_TO_STR(m_impl->coef) + ' ' + PRJFLOAT_TO_STR(m_impl->Re) + ' '
    + ANY_TO_STR(m_impl->u_A) + ' ' + ANY_TO_STR(m_impl->u_D) + '\n';
  return string;
}

void PlrOrf::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setArea(input.readNumber<std::string>());
  setDia(input.readNumber<std::string>());
  setCoef(input.readNumber<std::string>());
  setRe(input.readNumber<std::string>());
  setU_A(input.read<int>());
  setU_D(input.read<int>());
}

int PlrOrf::nr() const
{
  return m_impl->nr;
}

void PlrOrf::setNr(const int nr)
{
  m_impl->nr = nr;
}

int PlrOrf::icon() const
{
  return m_impl->icon;
}

void PlrOrf::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string PlrOrf::name() const
{
  return m_impl->name;
}

void PlrOrf::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string PlrOrf::desc() const
{
  return m_impl->desc;
}

void PlrOrf::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API PlrOrf::lam() const
{
  return to<double>(m_impl->lam);
}

template<> std::string PRJMODEL_API PlrOrf::lam() const
{
  return m_impl->lam;
}

bool PlrOrf::setLam(const double lam)
{
  m_impl->lam = to_float(lam);
  return true;
}

bool PlrOrf::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_impl->lam);
}

template<> double PRJMODEL_API PlrOrf::turb() const
{
  return to<double>(m_impl->turb);
}

template<> std::string PRJMODEL_API PlrOrf::turb() const
{
  return m_impl->turb;
}

bool PlrOrf::setTurb(const double turb)
{
  m_impl->turb = to_float(turb);
  return true;
}

bool PlrOrf::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_impl->turb);
}

template<> double PRJMODEL_API PlrOrf::expt() const
{
  return to<double>(m_impl->expt);
}

template<> std::string PRJMODEL_API PlrOrf::expt() const
{
  return m_impl->expt;
}

bool PlrOrf::setExpt(const double expt)
{
  m_impl->expt = to_float(expt);
  return true;
}

bool PlrOrf::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_impl->expt);
}

template<> double PRJMODEL_API PlrOrf::area() const
{
  return to<double>(m_impl->area);
}

template<> std::string PRJMODEL_API PlrOrf::area() const
{
  return m_impl->area;
}

bool PlrOrf::setArea(const double area)
{
  m_impl->area = to_float(area);
  return true;
}

bool PlrOrf::setArea(const std::string& area)
{
  return assign_if_valid<double>(area, m_impl->area);
}

template<> double PRJMODEL_API PlrOrf::dia() const
{
  return to<double>(m_impl->dia);
}

template<> std::string PRJMODEL_API PlrOrf::dia() const
{
  return m_impl->dia;
}

bool PlrOrf::setDia(const double dia)
{
  m_impl->dia = to_float(dia);
  return true;
}

bool PlrOrf::setDia(const std::string& dia)
{
  return assign_if_valid<double>(dia, m_impl->dia);
}

template<> double PRJMODEL_API PlrOrf::coef() const
{
  return to<double>(m_impl->coef);
}

template<> std::string PRJMODEL_API PlrOrf::coef() const
{
  return m_impl->coef;
}

bool PlrOrf::setCoef(const double coef)
{
  m_impl->coef = to_float(coef);
  return true;
}

bool PlrOrf::setCoef(const std::string& coef)
{
  return assign_if_valid<double>(coef, m_impl->coef);
}

template<> double PRJMODEL_API PlrOrf::Re() const
{
  return to<double>(m_impl->Re);
}

template<> std::string PRJMODEL_API PlrOrf::Re() const
{
  return m_impl->Re;
}

bool PlrOrf::setRe(const double Re)
{
  m_impl->Re = to_float(Re);
  return true;
}

bool PlrOrf::setRe(const std::string& Re)
{
  return assign_if_valid<double>(Re, m_impl->Re);
}

int PlrOrf::u_A() const
{
  return m_impl->u_A;
}

void PlrOrf::setU_A(const int u_A)
{
  m_impl->u_A = u_A;
}

int PlrOrf::u_D() const
{
  return m_impl->u_D;
}

void PlrOrf::setU_D(const int u_D)
{
  m_impl->u_D = u_D;
}

PlrLeak::Impl::Impl() : nr(0), icon(0), lam(PRJFLOAT("0.0")), turb(PRJFLOAT("0.0")), expt(PRJFLOAT("0.0")), coef(PRJFLOAT("0.0")),
pres(PRJFLOAT("0.0")), area1(PRJFLOAT("0.0")), area2(PRJFLOAT("0.0")), area3(PRJFLOAT("0.0")), u_A1(0), u_A2(0), u_A3(0), u_dP(0)
{}

PlrLeak::PlrLeak() : m_impl(std::shared_ptr<Impl>(new Impl))
{}

PlrLeak::PlrLeak(const PlrLeak &other) : m_impl(other.m_impl)
{}

PlrLeak::~PlrLeak()
{}

PlrLeak& PlrLeak::operator=(const PlrLeak &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool PlrLeak::operator==(const PlrLeak &other) const
{
  return m_impl == other.m_impl;
}

bool PlrLeak::operator!=(const PlrLeak &other) const
{
  return m_impl != other.m_impl;
}

PlrLeak::PlrLeak(int nr, int icon, std::string name, std::string desc) : m_impl(std::shared_ptr<Impl>(new Impl))
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrLeak::PlrLeak(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt,
  double coef, double pres, double area1, double area2, double area3, int u_A1, int u_A2,
  int u_A3, int u_dP) : m_impl(std::shared_ptr<Impl>(new Impl))
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setCoef(coef);
  setPres(pres);
  setArea1(area1);
  setArea2(area2);
  setArea3(area3);
  setU_A1(u_A1);
  setU_A2(u_A2);
  setU_A3(u_A3);
  setU_dP(u_dP);
}

PlrLeak::PlrLeak(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt,
  std::string coef, std::string pres, std::string area1, std::string area2, std::string area3, int u_A1, int u_A2,
  int u_A3, int u_dP) : m_impl(std::shared_ptr<Impl>(new Impl))
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setCoef(coef);
  setPres(pres);
  setArea1(area1);
  setArea2(area2);
  setArea3(area3);
  setU_A1(u_A1);
  setU_A2(u_A2);
  setU_A3(u_A3);
  setU_dP(u_dP);
}

void PlrLeak::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setCoef(input.readNumber<std::string>());
  setPres(input.readNumber<std::string>());
  setArea1(input.readNumber<std::string>());
  setArea2(input.readNumber<std::string>());
  setArea3(input.readNumber<std::string>());
  setU_A1(input.read<int>());
  setU_A2(input.read<int>());
  setU_A3(input.read<int>());
  setU_dP(input.read<int>());
}

std::string PlrLeak::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + ' ' + dataType() + ' ' + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->lam) + ' ' + PRJFLOAT_TO_STR(m_impl->turb) + ' ' + PRJFLOAT_TO_STR(m_impl->expt) + ' '
    + PRJFLOAT_TO_STR(m_impl->coef) + ' ' + PRJFLOAT_TO_STR(m_impl->pres) + ' ' + PRJFLOAT_TO_STR(m_impl->area1) + ' '
    + PRJFLOAT_TO_STR(m_impl->area2) + ' ' + PRJFLOAT_TO_STR(m_impl->area3) + ' ' + ANY_TO_STR(m_impl->u_A1) + ' '
    + ANY_TO_STR(m_impl->u_A2) + ' ' + ANY_TO_STR(m_impl->u_A3) + ' ' + ANY_TO_STR(m_impl->u_dP) + '\n';
  return string;
}

void PlrLeak::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setCoef(input.readNumber<std::string>());
  setPres(input.readNumber<std::string>());
  setArea1(input.readNumber<std::string>());
  setArea2(input.readNumber<std::string>());
  setArea3(input.readNumber<std::string>());
  setU_A1(input.read<int>());
  setU_A2(input.read<int>());
  setU_A3(input.read<int>());
  setU_dP(input.read<int>());
}

int PlrLeak::nr() const
{
  return m_impl->nr;
}

void PlrLeak::setNr(const int nr)
{
  m_impl->nr = nr;
}

int PlrLeak::icon() const
{
  return m_impl->icon;
}

void PlrLeak::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string PlrLeak::name() const
{
  return m_impl->name;
}

void PlrLeak::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string PlrLeak::desc() const
{
  return m_impl->desc;
}

void PlrLeak::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API PlrLeak::lam() const
{
  return to<double>(m_impl->lam);
}

template<> std::string PRJMODEL_API PlrLeak::lam() const
{
  return m_impl->lam;
}

bool PlrLeak::setLam(const double lam)
{
  m_impl->lam = to_float(lam);
  return true;
}

bool PlrLeak::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_impl->lam);
}

template<> double PRJMODEL_API PlrLeak::turb() const
{
  return to<double>(m_impl->turb);
}

template<> std::string PRJMODEL_API PlrLeak::turb() const
{
  return m_impl->turb;
}

bool PlrLeak::setTurb(const double turb)
{
  m_impl->turb = to_float(turb);
  return true;
}

bool PlrLeak::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_impl->turb);
}

template<> double PRJMODEL_API PlrLeak::expt() const
{
  return to<double>(m_impl->expt);
}

template<> std::string PRJMODEL_API PlrLeak::expt() const
{
  return m_impl->expt;
}

bool PlrLeak::setExpt(const double expt)
{
  m_impl->expt = to_float(expt);
  return true;
}

bool PlrLeak::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_impl->expt);
}

template<> double PRJMODEL_API PlrLeak::coef() const
{
  return to<double>(m_impl->coef);
}

template<> std::string PRJMODEL_API PlrLeak::coef() const
{
  return m_impl->coef;
}

bool PlrLeak::setCoef(const double coef)
{
  m_impl->coef = to_float(coef);
  return true;
}

bool PlrLeak::setCoef(const std::string& coef)
{
  return assign_if_valid<double>(coef, m_impl->coef);
}

template<> double PRJMODEL_API PlrLeak::pres() const
{
  return to<double>(m_impl->pres);
}

template<> std::string PRJMODEL_API PlrLeak::pres() const
{
  return m_impl->pres;
}

bool PlrLeak::setPres(const double pres)
{
  m_impl->pres = to_float(pres);
  return true;
}

bool PlrLeak::setPres(const std::string& pres)
{
  return assign_if_valid<double>(pres, m_impl->pres);
}

template<> double PRJMODEL_API PlrLeak::area1() const
{
  return to<double>(m_impl->area1);
}

template<> std::string PRJMODEL_API PlrLeak::area1() const
{
  return m_impl->area1;
}

bool PlrLeak::setArea1(const double area1)
{
  m_impl->area1 = to_float(area1);
  return true;
}

bool PlrLeak::setArea1(const std::string& area1)
{
  return assign_if_valid<double>(area1, m_impl->area1);
}

template<> double PRJMODEL_API PlrLeak::area2() const
{
  return to<double>(m_impl->area2);
}

template<> std::string PRJMODEL_API PlrLeak::area2() const
{
  return m_impl->area2;
}

bool PlrLeak::setArea2(const double area2)
{
  m_impl->area2 = to_float(area2);
  return true;
}

bool PlrLeak::setArea2(const std::string& area2)
{
  return assign_if_valid<double>(area2, m_impl->area2);
}

template<> double PRJMODEL_API PlrLeak::area3() const
{
  return to<double>(m_impl->area3);
}

template<> std::string  PlrLeak::area3() const
{
  return m_impl->area3;
}

bool PlrLeak::setArea3(const double area3)
{
  m_impl->area3 = to_float(area3);
  return true;
}

bool PlrLeak::setArea3(const std::string& area3)
{
  return assign_if_valid<double>(area3, m_impl->area3);
}

int PlrLeak::u_A1() const
{
  return m_impl->u_A1;
}

void PlrLeak::setU_A1(const int u_A1)
{
  m_impl->u_A1 = u_A1;
}

int PlrLeak::u_A2() const
{
  return m_impl->u_A2;
}

void PlrLeak::setU_A2(const int u_A2)
{
  m_impl->u_A2 = u_A2;
}

int PlrLeak::u_A3() const
{
  return m_impl->u_A3;
}

void PlrLeak::setU_A3(const int u_A3)
{
  m_impl->u_A3 = u_A3;
}

int PlrLeak::u_dP() const
{
  return m_impl->u_dP;
}

void PlrLeak::setU_dP(const int u_dP)
{
  m_impl->u_dP = u_dP;
}

PlrLeak1::PlrLeak1() : PlrLeak()
{}

PlrLeak1::PlrLeak1(int nr,int icon,std::string name,std::string desc) : PlrLeak(nr,icon,name,desc)
{}

PlrLeak1::PlrLeak1(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt,double coef,
                   double pres,double area1,double area2,double area3,int u_A1,int u_A2,int u_A3,int u_dP)
                   : PlrLeak(nr,icon,name,desc,lam,turb,expt,coef,pres,area1,area2,area3,u_A1,u_A2,u_A3,u_dP)
{}

PlrLeak1::PlrLeak1(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt,std::string coef,
                   std::string pres,std::string area1,std::string area2,std::string area3,int u_A1,int u_A2,int u_A3,int u_dP)
                   : PlrLeak(nr,icon,name,desc,lam,turb,expt,coef,pres,area1,area2,area3,u_A1,u_A2,u_A3,u_dP)
{}

PlrLeak1::~PlrLeak1()
{}

PlrLeak2::PlrLeak2() : PlrLeak()
{}

PlrLeak2::PlrLeak2(int nr,int icon,std::string name,std::string desc) : PlrLeak(nr,icon,name,desc)
{}

PlrLeak2::PlrLeak2(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt,double coef,
                   double pres,double area1,double area2,double area3,int u_A1,int u_A2,int u_A3,int u_dP)
                   : PlrLeak(nr,icon,name,desc,lam,turb,expt,coef,pres,area1,area2,area3,u_A1,u_A2,u_A3,u_dP)
{}

PlrLeak2::PlrLeak2(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt,std::string coef,
                   std::string pres,std::string area1,std::string area2,std::string area3,int u_A1,int u_A2,int u_A3,int u_dP)
                   : PlrLeak(nr,icon,name,desc,lam,turb,expt,coef,pres,area1,area2,area3,u_A1,u_A2,u_A3,u_dP)
{}

PlrLeak2::PlrLeak2(int icon, std::string name, std::string desc, double lam, double turb, double expt, double coef,
  double pres, double area2)
  : PlrLeak(0, icon, name, desc, lam, turb, expt, coef, pres, 0.0, area2, 0.0, 0, 0, 0, 0)
{}

PlrLeak2::PlrLeak2(int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt, std::string coef,
  std::string pres, std::string area2)
  : PlrLeak(0, icon, name, desc, lam, turb, expt, coef, pres, "0.0", area2, "0.0", 0, 0, 0, 0)
{}

PlrLeak2::~PlrLeak2()
{}

PlrLeak3::PlrLeak3() : PlrLeak()
{}

PlrLeak3::PlrLeak3(int nr,int icon,std::string name,std::string desc) : PlrLeak(nr,icon,name,desc)
{}

PlrLeak3::PlrLeak3(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt,double coef,
                   double pres,double area1,double area2,double area3,int u_A1,int u_A2,int u_A3,int u_dP)
                   : PlrLeak(nr,icon,name,desc,lam,turb,expt,coef,pres,area1,area2,area3,u_A1,u_A2,u_A3,u_dP)
{}

PlrLeak3::PlrLeak3(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt,std::string coef,
                   std::string pres,std::string area1,std::string area2,std::string area3,int u_A1,int u_A2,int u_A3,int u_dP)
                   : PlrLeak(nr,icon,name,desc,lam,turb,expt,coef,pres,area1,area2,area3,u_A1,u_A2,u_A3,u_dP)
{}

PlrLeak3::~PlrLeak3()
{}

PlrConn::PlrConn() :
  m_impl(std::shared_ptr<Impl>(new Impl))
{}

PlrConn::PlrConn(const PlrConn &other) : m_impl(other.m_impl)
{}

PlrConn::~PlrConn()
{}

PlrConn& PlrConn::operator=(const PlrConn &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool PlrConn::operator==(const PlrConn &other) const
{
  return m_impl == other.m_impl;
}

bool PlrConn::operator!=(const PlrConn &other) const
{
  return m_impl != other.m_impl;
}

PlrConn::Impl::Impl() : nr(0), icon(0), lam(PRJFLOAT("0.0")), turb(PRJFLOAT("0.0")), expt(PRJFLOAT("0.0")), coef(PRJFLOAT("0.0")),
area(PRJFLOAT("0.0")), u_A(0)
{}

PlrConn::PlrConn(int nr, int icon, std::string name, std::string desc) : PlrConn()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrConn::PlrConn(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt,
  double area, double coef, int u_A) : PlrConn()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setCoef(coef);
  setArea(area);
  setU_A(u_A);
}

PlrConn::PlrConn(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt,
  std::string area, std::string coef, int u_A) : PlrConn()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setCoef(coef);
  setArea(area);
  setU_A(u_A);
}

void PlrConn::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setArea(input.readNumber<std::string>());
  setCoef(input.readNumber<std::string>());
  setU_A(input.read<int>());
}

std::string PlrConn::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + " plr_conn " + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->lam) + ' ' + PRJFLOAT_TO_STR(m_impl->turb) + ' ' + PRJFLOAT_TO_STR(m_impl->expt) + ' ' + PRJFLOAT_TO_STR(m_impl->area)
    + ' ' + PRJFLOAT_TO_STR(m_impl->coef) + ' ' + ANY_TO_STR(m_impl->u_A) + '\n';
  return string;
}

void PlrConn::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setArea(input.readNumber<std::string>());
  setCoef(input.readNumber<std::string>());
  setU_A(input.read<int>());
}

int PlrConn::nr() const
{
  return m_impl->nr;
}

void PlrConn::setNr(const int nr)
{
  m_impl->nr = nr;
}

int PlrConn::icon() const
{
  return m_impl->icon;
}

void PlrConn::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string PlrConn::name() const
{
  return m_impl->name;
}

void PlrConn::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string PlrConn::desc() const
{
  return m_impl->desc;
}

void PlrConn::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API PlrConn::lam() const
{
  return to<double>(m_impl->lam);
}

template<> std::string PRJMODEL_API PlrConn::lam() const
{
  return m_impl->lam;
}

bool PlrConn::setLam(const double lam)
{
  m_impl->lam = to_float(lam);
  return true;
}

bool PlrConn::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_impl->lam);
}

template<> double PRJMODEL_API PlrConn::turb() const
{
  return to<double>(m_impl->turb);
}

template<> std::string PRJMODEL_API PlrConn::turb() const
{
  return m_impl->turb;
}

bool PlrConn::setTurb(const double turb)
{
  m_impl->turb = to_float(turb);
  return true;
}

bool PlrConn::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_impl->turb);
}

template<> double PRJMODEL_API PlrConn::expt() const
{
  return to<double>(m_impl->expt);
}

template<> std::string PRJMODEL_API PlrConn::expt() const
{
  return m_impl->expt;
}

bool PlrConn::setExpt(const double expt)
{
  m_impl->expt = to_float(expt);
  return true;
}

bool PlrConn::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_impl->expt);
}

template<> double PRJMODEL_API PlrConn::area() const
{
  return to<double>(m_impl->area);
}

template<> std::string PRJMODEL_API PlrConn::area() const
{
  return m_impl->area;
}

bool PlrConn::setArea(const double area)
{
  m_impl->area = to_float(area);
  return true;
}

bool PlrConn::setArea(const std::string& area)
{
  return assign_if_valid<double>(area, m_impl->area);
}

template<> double PRJMODEL_API PlrConn::coef() const
{
  return to<double>(m_impl->coef);
}

template<> std::string PRJMODEL_API PlrConn::coef() const
{
  return m_impl->coef;
}

bool PlrConn::setCoef(const double coef)
{
  m_impl->coef = to_float(coef);
  return true;
}

bool PlrConn::setCoef(const std::string& coef)
{
  return assign_if_valid<double>(coef, m_impl->coef);
}

int PlrConn::u_A() const
{
  return m_impl->u_A;
}

void PlrConn::setU_A(const int u_A)
{
  m_impl->u_A = u_A;
}

PlrGeneral::PlrGeneral() :
  m_impl(std::shared_ptr<Impl>(new Impl))
{}

PlrGeneral::PlrGeneral(const PlrGeneral &other) : m_impl(other.m_impl)
{}

PlrGeneral::~PlrGeneral()
{}

PlrGeneral& PlrGeneral::operator=(const PlrGeneral &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool PlrGeneral::operator==(const PlrGeneral &other) const
{
  return m_impl == other.m_impl;
}

bool PlrGeneral::operator!=(const PlrGeneral &other) const
{
  return m_impl != other.m_impl;
}

PlrGeneral::Impl::Impl() : nr(0), icon(0), lam(PRJFLOAT("0.0")), turb(PRJFLOAT("0.0")), expt(PRJFLOAT("0.0"))
{}

PlrGeneral::PlrGeneral(int nr, int icon, std::string name, std::string desc) : PlrGeneral()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrGeneral::PlrGeneral(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt) : PlrGeneral()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
}

PlrGeneral::PlrGeneral(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt) : PlrGeneral()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
}

void PlrGeneral::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
}

std::string PlrGeneral::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + ' ' + dataType() + ' ' + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->lam) + ' ' + PRJFLOAT_TO_STR(m_impl->turb) + ' ' + PRJFLOAT_TO_STR(m_impl->expt) + '\n';
  return string;
}

void PlrGeneral::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
}

int PlrGeneral::nr() const
{
  return m_impl->nr;
}

void PlrGeneral::setNr(const int nr)
{
  m_impl->nr = nr;
}

int PlrGeneral::icon() const
{
  return m_impl->icon;
}

void PlrGeneral::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string PlrGeneral::name() const
{
  return m_impl->name;
}

void PlrGeneral::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string PlrGeneral::desc() const
{
  return m_impl->desc;
}

void PlrGeneral::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API PlrGeneral::lam() const
{
  return to<double>(m_impl->lam);
}

template<> std::string PRJMODEL_API PlrGeneral::lam() const
{
  return m_impl->lam;
}

bool PlrGeneral::setLam(const double lam)
{
  m_impl->lam = to_float(lam);
  return true;
}

bool PlrGeneral::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_impl->lam);
}

template<> double PRJMODEL_API PlrGeneral::turb() const
{
  return to<double>(m_impl->turb);
}

bool PlrGeneral::setTurb(const double turb)
{
  m_impl->turb = to_float(turb);
  return true;
}

bool PlrGeneral::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_impl->turb);
}

template<> double PRJMODEL_API PlrGeneral::expt() const
{
  return to<double>(m_impl->expt);
}

template<> std::string  PlrGeneral::expt() const
{
  return m_impl->expt;
}

bool PlrGeneral::setExpt(const double expt)
{
  m_impl->expt = to_float(expt);
  return true;
}

bool PlrGeneral::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_impl->expt);
}

PlrQcn::PlrQcn() : PlrGeneral()
{}

PlrQcn::PlrQcn(int nr,int icon,std::string name,std::string desc) : PlrGeneral(nr,icon,name,desc)
{}

PlrQcn::PlrQcn(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt)
: PlrGeneral(nr,icon,name,desc,lam,turb,expt)
{}

PlrQcn::PlrQcn(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt)
: PlrGeneral(nr,icon,name,desc,lam,turb,expt)
{}

PlrQcn::~PlrQcn()
{}

PlrFcn::PlrFcn() : PlrGeneral()
{}

PlrFcn::PlrFcn(int nr,int icon,std::string name,std::string desc) : PlrGeneral(nr,icon,name,desc)
{}

PlrFcn::PlrFcn(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt)
: PlrGeneral(nr,icon,name,desc,lam,turb,expt)
{}

PlrFcn::PlrFcn(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt)
: PlrGeneral(nr,icon,name,desc,lam,turb,expt)
{}

PlrFcn::~PlrFcn()
{}

PlrTest1::PlrTest1() :
  m_impl(std::shared_ptr<Impl>(new Impl))
{}

PlrTest1::PlrTest1(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<Impl>(new Impl))
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrTest1::PlrTest1(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt,double dP,
                   double Flow,int u_P,int u_F) :
  m_impl(std::shared_ptr<Impl>(new Impl))
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setDP(dP);
  setFlow(Flow);
  setU_P(u_P);
  setU_F(u_F);
}

PlrTest1::PlrTest1(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt,std::string dP,
                   std::string Flow,int u_P,int u_F) :
  m_impl(std::shared_ptr<Impl>(new Impl))
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setDP(dP);
  setFlow(Flow);
  setU_P(u_P);
  setU_F(u_F);
}

PlrTest1::PlrTest1(const PlrTest1 &other) : m_impl(other.m_impl)
{}

PlrTest1::~PlrTest1()
{}

PlrTest1& PlrTest1::operator=(const PlrTest1 &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool PlrTest1::operator==(const PlrTest1 &other) const
{
  return m_impl == other.m_impl;
}

bool PlrTest1::operator!=(const PlrTest1 &other) const
{
  return m_impl != other.m_impl;
}

PlrTest1::Impl::Impl() : nr(0), icon(0), lam(PRJFLOAT("0.0")), turb(PRJFLOAT("0.0")), expt(PRJFLOAT("0.0")), dP(PRJFLOAT("0.0")),
Flow(PRJFLOAT("0.0")), u_P(0), u_F(0)
{}

void PlrTest1::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setDP(input.readNumber<std::string>());
  setFlow(input.readNumber<std::string>());
  setU_P(input.read<int>());
  setU_F(input.read<int>());
}

std::string PlrTest1::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + " plr_test1 " + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->lam) + ' ' + PRJFLOAT_TO_STR(m_impl->turb) + ' ' + PRJFLOAT_TO_STR(m_impl->expt) + ' '
    + PRJFLOAT_TO_STR(m_impl->dP) + ' ' + PRJFLOAT_TO_STR(m_impl->Flow) + ' ' + ANY_TO_STR(m_impl->u_P) + ' '
    + ANY_TO_STR(m_impl->u_F) + '\n';
  return string;
}

void PlrTest1::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setDP(input.readNumber<std::string>());
  setFlow(input.readNumber<std::string>());
  setU_P(input.read<int>());
  setU_F(input.read<int>());
}

int PlrTest1::nr() const
{
  return m_impl->nr;
}

void PlrTest1::setNr(const int nr)
{
  m_impl->nr = nr;
}

int PlrTest1::icon() const
{
  return m_impl->icon;
}

void PlrTest1::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string PlrTest1::name() const
{
  return m_impl->name;
}

void PlrTest1::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string PlrTest1::desc() const
{
  return m_impl->desc;
}

void PlrTest1::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template <> double PRJMODEL_API PlrTest1::lam() const
{
  return to<double>(m_impl->lam);
}

template <> std::string PRJMODEL_API PlrTest1::lam() const
{
  return PRJFLOAT_TO_STR(m_impl->lam);
}

bool PlrTest1::setLam(const double lam)
{
  m_impl->lam = to_float(lam);
  return true;
}

bool PlrTest1::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_impl->lam);
}

template <> double PRJMODEL_API PlrTest1::turb() const
{
  return to<double>(m_impl->turb);
}

template <> std::string PRJMODEL_API PlrTest1::turb() const
{
  return PRJFLOAT_TO_STR(m_impl->turb);
}

bool PlrTest1::setTurb(const double turb)
{
  m_impl->turb = to_float(turb);
  return true;
}

bool PlrTest1::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_impl->turb);
}

template <> double PRJMODEL_API PlrTest1::expt() const
{
  return to<double>(m_impl->expt);
}

template <> std::string PRJMODEL_API PlrTest1::expt() const
{
  return PRJFLOAT_TO_STR(m_impl->expt);
}

bool PlrTest1::setExpt(const double expt)
{
  m_impl->expt = to_float(expt);
  return true;
}

bool PlrTest1::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_impl->expt);
}

template <> double PRJMODEL_API PlrTest1::dP() const
{
  return to<double>(m_impl->dP);
}

template <> std::string PRJMODEL_API PlrTest1::dP() const
{
  return PRJFLOAT_TO_STR(m_impl->dP);
}

bool PlrTest1::setDP(const double dP)
{
  m_impl->dP = to_float(dP);
  return true;
}

bool PlrTest1::setDP(const std::string& dP)
{
  return assign_if_valid<double>(dP, m_impl->dP);
}

template <> double PRJMODEL_API PlrTest1::Flow() const
{
  return to<double>(m_impl->Flow);
}

template <> std::string PRJMODEL_API PlrTest1::Flow() const
{
  return PRJFLOAT_TO_STR(m_impl->Flow);
}

bool PlrTest1::setFlow(const double Flow)
{
  m_impl->Flow = to_float(Flow);
  return true;
}

bool PlrTest1::setFlow(const std::string& Flow)
{
  return assign_if_valid<double>(Flow, m_impl->Flow);
}

int PlrTest1::u_P() const
{
  return m_impl->u_P;
}

void PlrTest1::setU_P(const int u_P)
{
  m_impl->u_P = u_P;
}

int PlrTest1::u_F() const
{
  return m_impl->u_F;
}

void PlrTest1::setU_F(const int u_F)
{
  m_impl->u_F = u_F;
}

PlrTest2::PlrTest2() :
  m_impl(std::shared_ptr<Impl>(new Impl))
{}

PlrTest2::PlrTest2(const PlrTest2 &other) : m_impl(other.m_impl)
{}

PlrTest2::~PlrTest2()
{}

PlrTest2& PlrTest2::operator=(const PlrTest2 &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool PlrTest2::operator==(const PlrTest2 &other) const
{
  return m_impl == other.m_impl;
}

bool PlrTest2::operator!=(const PlrTest2 &other) const
{
  return m_impl != other.m_impl;
}

PlrTest2::Impl::Impl() : nr(0), icon(0), lam(PRJFLOAT("0.0")), turb(PRJFLOAT("0.0")), expt(PRJFLOAT("0.0")), dP1(PRJFLOAT("0.0")),
F1(PRJFLOAT("0.0")), dP2(PRJFLOAT("0.0")), F2(PRJFLOAT("0.0")), u_P1(0), u_F1(0), u_P2(0), u_F2(0)
{}

PlrTest2::PlrTest2(int nr, int icon, std::string name, std::string desc) : PlrTest2()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrTest2::PlrTest2(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt,
  double dP1, double F1, double dP2, double F2, int u_P1, int u_F1, int u_P2, int u_F2) : PlrTest2()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setDP1(dP1);
  setF1(F1);
  setDP2(dP2);
  setF2(F2);
  setU_P1(u_P1);
  setU_F1(u_F1);
  setU_P2(u_P2);
  setU_F2(u_F2);
}

PlrTest2::PlrTest2(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt,
  std::string dP1, std::string F1, std::string dP2, std::string F2, int u_P1, int u_F1, int u_P2, int u_F2) : PlrTest2()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setDP1(dP1);
  setF1(F1);
  setDP2(dP2);
  setF2(F2);
  setU_P1(u_P1);
  setU_F1(u_F1);
  setU_P2(u_P2);
  setU_F2(u_F2);
}

void PlrTest2::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setDP1(input.readNumber<std::string>());
  setF1(input.readNumber<std::string>());
  setDP2(input.readNumber<std::string>());
  setF2(input.readNumber<std::string>());
  setU_P1(input.read<int>());
  setU_F1(input.read<int>());
  setU_P2(input.read<int>());
  setU_F2(input.read<int>());
}

std::string PlrTest2::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + " plr_test2 " + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->lam) + ' ' + PRJFLOAT_TO_STR(m_impl->turb) + ' ' + PRJFLOAT_TO_STR(m_impl->expt) + ' ' + PRJFLOAT_TO_STR(m_impl->dP1)
    + ' ' + PRJFLOAT_TO_STR(m_impl->F1) + ' ' + PRJFLOAT_TO_STR(m_impl->dP2) + ' ' + PRJFLOAT_TO_STR(m_impl->F2) + ' '
    + ANY_TO_STR(m_impl->u_P1) + ' ' + ANY_TO_STR(m_impl->u_F1) + ' ' + ANY_TO_STR(m_impl->u_P2) + ' ' + ANY_TO_STR(m_impl->u_F2)
    + '\n';
  return string;
}

void PlrTest2::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setDP1(input.readNumber<std::string>());
  setF1(input.readNumber<std::string>());
  setDP2(input.readNumber<std::string>());
  setF2(input.readNumber<std::string>());
  setU_P1(input.read<int>());
  setU_F1(input.read<int>());
  setU_P2(input.read<int>());
  setU_F2(input.read<int>());
}

int PlrTest2::nr() const
{
  return m_impl->nr;
}

void PlrTest2::setNr(const int nr)
{
  m_impl->nr = nr;
}

int PlrTest2::icon() const
{
  return m_impl->icon;
}

void PlrTest2::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string PlrTest2::name() const
{
  return m_impl->name;
}

void PlrTest2::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string PlrTest2::desc() const
{
  return m_impl->desc;
}

void PlrTest2::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API PlrTest2::lam() const
{
  return to<double>(m_impl->lam);
}

template<> std::string PRJMODEL_API PlrTest2::lam() const
{
  return m_impl->lam;
}

bool PlrTest2::setLam(const double lam)
{
  m_impl->lam = to_float(lam);
  return true;
}

bool PlrTest2::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_impl->lam);
}

template<> double PRJMODEL_API PlrTest2::turb() const
{
  return to<double>(m_impl->turb);
}

template<> std::string PRJMODEL_API PlrTest2::turb() const
{
  return m_impl->turb;
}

bool PlrTest2::setTurb(const double turb)
{
  m_impl->turb = to_float(turb);
  return true;
}

bool PlrTest2::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_impl->turb);
}

template<> double PRJMODEL_API PlrTest2::expt() const
{
  return to<double>(m_impl->expt);
}

template<> std::string PRJMODEL_API PlrTest2::expt() const
{
  return m_impl->expt;
}

bool PlrTest2::setExpt(const double expt)
{
  m_impl->expt = to_float(expt);
  return true;
}

bool PlrTest2::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_impl->expt);
}

template<> double PRJMODEL_API PlrTest2::dP1() const
{
  return to<double>(m_impl->dP1);
}

template<> std::string PRJMODEL_API PlrTest2::dP1() const
{
  return m_impl->dP1;
}

bool PlrTest2::setDP1(const double dP1)
{
  m_impl->dP1 = to_float(dP1);
  return true;
}

bool PlrTest2::setDP1(const std::string& dP1)
{
  return assign_if_valid<double>(dP1, m_impl->dP1);
}

template<> double PRJMODEL_API PlrTest2::F1() const
{
  return to<double>(m_impl->F1);
}

template<> std::string PRJMODEL_API PlrTest2::F1() const
{
  return m_impl->F1;
}

bool PlrTest2::setF1(const double F1)
{
  m_impl->F1 = to_float(F1);
  return true;
}

bool PlrTest2::setF1(const std::string& F1)
{
  return assign_if_valid<double>(F1, m_impl->F1);
}

template<> double PRJMODEL_API PlrTest2::dP2() const
{
  return to<double>(m_impl->dP2);
}

template<> std::string PRJMODEL_API PlrTest2::dP2() const
{
  return m_impl->dP2;
}

bool PlrTest2::setDP2(const double dP2)
{
  m_impl->dP2 = to_float(dP2);
  return true;
}

bool PlrTest2::setDP2(const std::string& dP2)
{
  return assign_if_valid<double>(dP2, m_impl->dP2);
}

template<> double PRJMODEL_API PlrTest2::F2() const
{
  return to<double>(m_impl->F2);
}

template<> std::string PRJMODEL_API PlrTest2::F2() const
{
  return m_impl->F2;
}

bool PlrTest2::setF2(const double F2)
{
  m_impl->F2 = to_float(F2);
  return true;
}

bool PlrTest2::setF2(const std::string& F2)
{
  return assign_if_valid<double>(F2, m_impl->F2);
}

int PlrTest2::u_P1() const
{
  return m_impl->u_P1;
}

void PlrTest2::setU_P1(const int u_P1)
{
  m_impl->u_P1 = u_P1;
}

int PlrTest2::u_F1() const
{
  return m_impl->u_F1;
}

void PlrTest2::setU_F1(const int u_F1)
{
  m_impl->u_F1 = u_F1;
}

int PlrTest2::u_P2() const
{
  return m_impl->u_P2;
}

void PlrTest2::setU_P2(const int u_P2)
{
  m_impl->u_P2 = u_P2;
}

int PlrTest2::u_F2() const
{
  return m_impl->u_F2;
}

void PlrTest2::setU_F2(const int u_F2)
{
  m_impl->u_F2 = u_F2;
}


PlrCrack::PlrCrack() :
  m_impl(std::shared_ptr<Impl>(new Impl))
{}

PlrCrack::PlrCrack(const PlrCrack &other) : m_impl(other.m_impl)
{}

PlrCrack::~PlrCrack()
{}

PlrCrack& PlrCrack::operator=(const PlrCrack &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool PlrCrack::operator==(const PlrCrack &other) const
{
  return m_impl == other.m_impl;
}

bool PlrCrack::operator!=(const PlrCrack &other) const
{
  return m_impl != other.m_impl;
}

PlrCrack::Impl::Impl() : nr(0), icon(0), lam(PRJFLOAT("0.0")), turb(PRJFLOAT("0.0")), expt(PRJFLOAT("0.0")),
length(PRJFLOAT("0.0")), width(PRJFLOAT("0.0")), u_L(0), u_W(0)
{}

PlrCrack::PlrCrack(int nr, int icon, std::string name, std::string desc) : PlrCrack()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrCrack::PlrCrack(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt,
  double length, double width, int u_L, int u_W) : PlrCrack()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setLength(length);
  setWidth(width);
  setU_L(u_L);
  setU_W(u_W);
}

PlrCrack::PlrCrack(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt,
  std::string length, std::string width, int u_L, int u_W) : PlrCrack()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setLength(length);
  setWidth(width);
  setU_L(u_L);
  setU_W(u_W);
}

void PlrCrack::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setLength(input.readNumber<std::string>());
  setWidth(input.readNumber<std::string>());
  setU_L(input.read<int>());
  setU_W(input.read<int>());
}

std::string PlrCrack::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + " plr_crack " + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->lam) + ' ' + PRJFLOAT_TO_STR(m_impl->turb) + ' ' + PRJFLOAT_TO_STR(m_impl->expt) + ' '
    + PRJFLOAT_TO_STR(m_impl->length) + ' ' + PRJFLOAT_TO_STR(m_impl->width) + ' ' + ANY_TO_STR(m_impl->u_L) + ' '
    + ANY_TO_STR(m_impl->u_W) + '\n';
  return string;
}

void PlrCrack::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setLength(input.readNumber<std::string>());
  setWidth(input.readNumber<std::string>());
  setU_L(input.read<int>());
  setU_W(input.read<int>());
}

int PlrCrack::nr() const
{
  return m_impl->nr;
}

void PlrCrack::setNr(const int nr)
{
  m_impl->nr = nr;
}

int PlrCrack::icon() const
{
  return m_impl->icon;
}

void PlrCrack::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string PlrCrack::name() const
{
  return m_impl->name;
}

void PlrCrack::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string PlrCrack::desc() const
{
  return m_impl->desc;
}

void PlrCrack::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API PlrCrack::lam() const
{
  return to<double>(m_impl->lam);
}

template<> std::string PRJMODEL_API PlrCrack::lam() const
{
  return m_impl->lam;
}

bool PlrCrack::setLam(const double lam)
{
  m_impl->lam = to_float(lam);
  return true;
}

bool PlrCrack::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_impl->lam);
}

template<> double PRJMODEL_API PlrCrack::turb() const
{
  return to<double>(m_impl->turb);
}

template<> std::string PRJMODEL_API PlrCrack::turb() const
{
  return m_impl->turb;
}

bool PlrCrack::setTurb(const double turb)
{
  m_impl->turb = to_float(turb);
  return true;
}

bool PlrCrack::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_impl->turb);
}

template<> double PRJMODEL_API PlrCrack::expt() const
{
  return to<double>(m_impl->expt);
}

template<> std::string PRJMODEL_API PlrCrack::expt() const
{
  return m_impl->expt;
}

bool PlrCrack::setExpt(const double expt)
{
  m_impl->expt = to_float(expt);
  return true;
}

bool PlrCrack::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_impl->expt);
}

template<> double PRJMODEL_API PlrCrack::length() const
{
  return to<double>(m_impl->length);
}

template<> std::string PRJMODEL_API PlrCrack::length() const
{
  return m_impl->length;
}

bool PlrCrack::setLength(const double length)
{
  m_impl->length = to_float(length);
  return true;
}

bool PlrCrack::setLength(const std::string& length)
{
  return assign_if_valid<double>(length, m_impl->length);
}

template<> double PRJMODEL_API PlrCrack::width() const
{
  return to<double>(m_impl->width);
}

template<> std::string PRJMODEL_API PlrCrack::width() const
{
  return m_impl->width;
}

bool PlrCrack::setWidth(const double width)
{
  m_impl->width = to_float(width);
  return true;
}

bool PlrCrack::setWidth(const std::string& width)
{
  return assign_if_valid<double>(width, m_impl->width);
}

int PlrCrack::u_L() const
{
  return m_impl->u_L;
}

void PlrCrack::setU_L(const int u_L)
{
  m_impl->u_L = u_L;
}

int PlrCrack::u_W() const
{
  return m_impl->u_W;
}

void PlrCrack::setU_W(const int u_W)
{
  m_impl->u_W = u_W;
}

PlrStair::PlrStair() :
  m_impl(std::shared_ptr<Impl>(new Impl))
{}

PlrStair::PlrStair(const PlrStair &other) : m_impl(other.m_impl)
{}

PlrStair::~PlrStair()
{}

PlrStair& PlrStair::operator=(const PlrStair &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool PlrStair::operator==(const PlrStair &other) const
{
  return m_impl == other.m_impl;
}

bool PlrStair::operator!=(const PlrStair &other) const
{
  return m_impl != other.m_impl;
}

PlrStair::Impl::Impl() : nr(0), icon(0), lam(PRJFLOAT("0.0")), turb(PRJFLOAT("0.0")), expt(PRJFLOAT("0.0")),
Ht(PRJFLOAT("0.0")), Area(PRJFLOAT("0.0")), peo(PRJFLOAT("0.0")), tread(0), u_A(0), u_D(0)
{}

PlrStair::PlrStair(int nr, int icon, std::string name, std::string desc) : PlrStair()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrStair::PlrStair(int nr, int icon, std::string name, std::string desc, double lam, double turb,
  double expt, double Ht, double Area, double peo, int tread, int u_A,
  int u_D) : PlrStair()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setHt(Ht);
  setArea(Area);
  setPeople(peo);
  setTread(tread);
  setU_A(u_A);
  setU_D(u_D);
}

PlrStair::PlrStair(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb,
  std::string expt, std::string Ht, std::string Area, std::string peo, int tread, int u_A,
  int u_D) : PlrStair()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setHt(Ht);
  setArea(Area);
  setPeople(peo);
  setTread(tread);
  setU_A(u_A);
  setU_D(u_D);
}

void PlrStair::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setHt(input.readNumber<std::string>());
  setArea(input.readNumber<std::string>());
  setPeople(input.readNumber<std::string>());
  setTread(input.read<int>());
  setU_A(input.read<int>());
  setU_D(input.read<int>());
}

std::string PlrStair::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + " plr_stair " + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->lam) + ' ' + PRJFLOAT_TO_STR(m_impl->turb) + ' ' + PRJFLOAT_TO_STR(m_impl->expt) + ' '
    + PRJFLOAT_TO_STR(m_impl->Ht) + ' ' + PRJFLOAT_TO_STR(m_impl->Area) + ' ' + PRJFLOAT_TO_STR(m_impl->peo) + ' '
    + ANY_TO_STR(m_impl->tread) + ' ' + ANY_TO_STR(m_impl->u_A) + ' ' + ANY_TO_STR(m_impl->u_D) + '\n';
  return string;
}

void PlrStair::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setHt(input.readNumber<std::string>());
  setArea(input.readNumber<std::string>());
  setPeople(input.readNumber<std::string>());
  setTread(input.read<int>());
  setU_A(input.read<int>());
  setU_D(input.read<int>());
}

int PlrStair::nr() const
{
  return m_impl->nr;
}

void PlrStair::setNr(const int nr)
{
  m_impl->nr = nr;
}

int PlrStair::icon() const
{
  return m_impl->icon;
}

void PlrStair::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string PlrStair::name() const
{
  return m_impl->name;
}

void PlrStair::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string PlrStair::desc() const
{
  return m_impl->desc;
}

void PlrStair::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API PlrStair::lam() const
{
  return to<double>(m_impl->lam);
}

template<> std::string PRJMODEL_API PlrStair::lam() const
{
  return m_impl->lam;
}

bool PlrStair::setLam(const double lam)
{
  m_impl->lam = to_float(lam);
  return true;
}

bool PlrStair::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_impl->lam);
}

template<> double PRJMODEL_API PlrStair::turb() const
{
  return to<double>(m_impl->turb);
}

template<> std::string PRJMODEL_API PlrStair::turb() const
{
  return m_impl->turb;
}

bool PlrStair::setTurb(const double turb)
{
  m_impl->turb = to_float(turb);
  return true;
}

bool PlrStair::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_impl->turb);
}

template<> double PRJMODEL_API PlrStair::expt() const
{
  return to<double>(m_impl->expt);
}

template<> std::string PRJMODEL_API PlrStair::expt() const
{
  return m_impl->expt;
}

bool PlrStair::setExpt(const double expt)
{
  m_impl->expt = to_float(expt);
  return true;
}

bool PlrStair::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_impl->expt);
}

template<> double PRJMODEL_API PlrStair::Ht() const
{
  return to<double>(m_impl->Ht);
}

template<> std::string PRJMODEL_API PlrStair::Ht() const
{
  return m_impl->Ht;
}

bool PlrStair::setHt(const double Ht)
{
  m_impl->Ht = to_float(Ht);
  return true;
}

bool PlrStair::setHt(const std::string& Ht)
{
  return assign_if_valid<double>(Ht, m_impl->Ht);
}

template<> double PRJMODEL_API PlrStair::area() const
{
  return to<double>(m_impl->Area);
}

template<> std::string PRJMODEL_API PlrStair::area() const
{
  return m_impl->Area;
}

bool PlrStair::setArea(const double Area)
{
  m_impl->Area = to_float(Area);
  return true;
}

bool PlrStair::setArea(const std::string& Area)
{
  return assign_if_valid<double>(Area, m_impl->Area);
}

template<> double PRJMODEL_API PlrStair::people() const
{
  return to<double>(m_impl->peo);
}

template<> std::string PRJMODEL_API PlrStair::people() const
{
  return m_impl->peo;
}

bool PlrStair::setPeople(const double peo)
{
  m_impl->peo = to_float(peo);
  return true;
}

bool PlrStair::setPeople(const std::string& peo)
{
  return assign_if_valid<double>(peo, m_impl->peo);
}

int PlrStair::tread() const
{
  return m_impl->tread;
}

void PlrStair::setTread(const int tread)
{
  m_impl->tread = tread;
}

int PlrStair::u_A() const
{
  return m_impl->u_A;
}

void PlrStair::setU_A(const int u_A)
{
  m_impl->u_A = u_A;
}

int PlrStair::u_D() const
{
  return m_impl->u_D;
}

void PlrStair::setU_D(const int u_D)
{
  m_impl->u_D = u_D;
}

PlrShaft::PlrShaft() :
  m_impl(std::shared_ptr<Impl>(new Impl))
{}

PlrShaft::PlrShaft(const PlrShaft &other) : m_impl(other.m_impl)
{}

PlrShaft::~PlrShaft()
{}

PlrShaft& PlrShaft::operator=(const PlrShaft &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool PlrShaft::operator==(const PlrShaft &other) const
{
  return m_impl == other.m_impl;
}

bool PlrShaft::operator!=(const PlrShaft &other) const
{
  return m_impl != other.m_impl;
}

PlrShaft::Impl::Impl() : nr(0), icon(0), lam(PRJFLOAT("0.0")), turb(PRJFLOAT("0.0")), expt(PRJFLOAT("0.0")),
Ht(PRJFLOAT("0.0")), area(PRJFLOAT("0.0")), perim(PRJFLOAT("0.0")), rough(PRJFLOAT("0.0")), u_A(0), u_D(0), u_P(0), u_R(0)
{}

PlrShaft::PlrShaft(int nr, int icon, std::string name, std::string desc) : PlrShaft()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrShaft::PlrShaft(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt,
  double Ht, double area, double perim, double rough, int u_A, int u_D, int u_P, int u_R) : PlrShaft()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setHt(Ht);
  setArea(area);
  setPerim(perim);
  setRough(rough);
  setU_A(u_A);
  setU_D(u_D);
  setU_P(u_P);
  setU_R(u_R);
}

PlrShaft::PlrShaft(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt,
  std::string Ht, std::string area, std::string perim, std::string rough, int u_A, int u_D, int u_P, int u_R) : PlrShaft()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setHt(Ht);
  setArea(area);
  setPerim(perim);
  setRough(rough);
  setU_A(u_A);
  setU_D(u_D);
  setU_P(u_P);
  setU_R(u_R);
}

void PlrShaft::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setHt(input.readNumber<std::string>());
  setArea(input.readNumber<std::string>());
  setPerim(input.readNumber<std::string>());
  setRough(input.readNumber<std::string>());
  setU_A(input.read<int>());
  setU_D(input.read<int>());
  setU_P(input.read<int>());
  setU_R(input.read<int>());
}

std::string PlrShaft::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + " plr_shaft " + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->lam) + ' ' + PRJFLOAT_TO_STR(m_impl->turb) + ' ' + PRJFLOAT_TO_STR(m_impl->expt) + ' ' + PRJFLOAT_TO_STR(m_impl->Ht)
    + ' ' + PRJFLOAT_TO_STR(m_impl->area) + ' ' + PRJFLOAT_TO_STR(m_impl->perim) + ' ' + PRJFLOAT_TO_STR(m_impl->rough) + ' '
    + ANY_TO_STR(m_impl->u_A) + ' ' + ANY_TO_STR(m_impl->u_D) + ' ' + ANY_TO_STR(m_impl->u_P) + ' ' + ANY_TO_STR(m_impl->u_R)
    + '\n';
  return string;
}

void PlrShaft::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setHt(input.readNumber<std::string>());
  setArea(input.readNumber<std::string>());
  setPerim(input.readNumber<std::string>());
  setRough(input.readNumber<std::string>());
  setU_A(input.read<int>());
  setU_D(input.read<int>());
  setU_P(input.read<int>());
  setU_R(input.read<int>());
}

int PlrShaft::nr() const
{
  return m_impl->nr;
}

void PlrShaft::setNr(const int nr)
{
  m_impl->nr = nr;
}

int PlrShaft::icon() const
{
  return m_impl->icon;
}

void PlrShaft::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string PlrShaft::name() const
{
  return m_impl->name;
}

void PlrShaft::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string PlrShaft::desc() const
{
  return m_impl->desc;
}

void PlrShaft::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API PlrShaft::lam() const
{
  return to<double>(m_impl->lam);
}

template<> std::string PRJMODEL_API PlrShaft::lam() const
{
  return m_impl->lam;
}

bool PlrShaft::setLam(const double lam)
{
  m_impl->lam = to_float(lam);
  return true;
}

bool PlrShaft::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_impl->lam);
}

template<> double PRJMODEL_API PlrShaft::turb() const
{
  return to<double>(m_impl->turb);
}

template<> std::string PRJMODEL_API PlrShaft::turb() const
{
  return m_impl->turb;
}

bool PlrShaft::setTurb(const double turb)
{
  m_impl->turb = to_float(turb);
  return true;
}

bool PlrShaft::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_impl->turb);
}

template<> double PRJMODEL_API PlrShaft::expt() const
{
  return to<double>(m_impl->expt);
}

template<> std::string PRJMODEL_API PlrShaft::expt() const
{
  return m_impl->expt;
}

bool PlrShaft::setExpt(const double expt)
{
  m_impl->expt = to_float(expt);
  return true;
}

bool PlrShaft::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_impl->expt);
}

template<> double PRJMODEL_API PlrShaft::Ht() const
{
  return to<double>(m_impl->Ht);
}

template<> std::string PRJMODEL_API PlrShaft::Ht() const
{
  return m_impl->Ht;
}

bool PlrShaft::setHt(const double Ht)
{
  m_impl->Ht = to_float(Ht);
  return true;
}

bool PlrShaft::setHt(const std::string& Ht)
{
  return assign_if_valid<double>(Ht, m_impl->Ht);
}

template<> double PRJMODEL_API PlrShaft::area() const
{
  return to<double>(m_impl->area);
}

template<> std::string PRJMODEL_API PlrShaft::area() const
{
  return m_impl->area;
}

bool PlrShaft::setArea(const double area)
{
  m_impl->area = to_float(area);
  return true;
}

bool PlrShaft::setArea(const std::string& area)
{
  return assign_if_valid<double>(area, m_impl->area);
}

template<> double PRJMODEL_API PlrShaft::perim() const
{
  return to<double>(m_impl->perim);
}

template<> std::string PRJMODEL_API PlrShaft::perim() const
{
  return m_impl->perim;
}

bool PlrShaft::setPerim(const double perim)
{
  m_impl->perim = to_float(perim);
  return true;
}

bool PlrShaft::setPerim(const std::string& perim)
{
  return assign_if_valid<double>(perim, m_impl->perim);
}

template<> double PRJMODEL_API PlrShaft::rough() const
{
  return to<double>(m_impl->rough);
}

template<> std::string PRJMODEL_API PlrShaft::rough() const
{
  return m_impl->rough;
}

bool PlrShaft::setRough(const double rough)
{
  m_impl->rough = to_float(rough);
  return true;
}

bool PlrShaft::setRough(const std::string& rough)
{
  return assign_if_valid<double>(rough, m_impl->rough);
}

int PlrShaft::u_A() const
{
  return m_impl->u_A;
}

void PlrShaft::setU_A(const int u_A)
{
  m_impl->u_A = u_A;
}

int PlrShaft::u_D() const
{
  return m_impl->u_D;
}

void PlrShaft::setU_D(const int u_D)
{
  m_impl->u_D = u_D;
}

int PlrShaft::u_P() const
{
  return m_impl->u_P;
}

void PlrShaft::setU_P(const int u_P)
{
  m_impl->u_P = u_P;
}

int PlrShaft::u_R() const
{
  return m_impl->u_R;
}

void PlrShaft::setU_R(const int u_R)
{
  m_impl->u_R = u_R;
}

PlrBackDamper::PlrBackDamper() : m_impl(std::shared_ptr<Impl>(new Impl))
{}

PlrBackDamper::PlrBackDamper(const PlrBackDamper &other) : m_impl(other.m_impl)
{}

PlrBackDamper::~PlrBackDamper()
{}

PlrBackDamper& PlrBackDamper::operator=(const PlrBackDamper &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool PlrBackDamper::operator==(const PlrBackDamper &other) const
{
  return m_impl == other.m_impl;
}

bool PlrBackDamper::operator!=(const PlrBackDamper &other) const
{
  return m_impl != other.m_impl;
}

PlrBackDamper::Impl::Impl() : nr(0), icon(0), lam(PRJFLOAT("0.0")), Cp(PRJFLOAT("0.0")), xp(PRJFLOAT("0.0")),
Cn(PRJFLOAT("0.0")), xn(PRJFLOAT("0.0"))
{}

PlrBackDamper::PlrBackDamper(int nr, int icon, std::string name, std::string desc) : PlrBackDamper()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrBackDamper::PlrBackDamper(int nr, int icon, std::string name, std::string desc, double lam, double Cp, double xp, double Cn,
  double xn) : PlrBackDamper()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setCp(Cp);
  setXp(xp);
  setCn(Cn);
  setXn(xn);
}

PlrBackDamper::PlrBackDamper(int nr, int icon, std::string name, std::string desc, std::string lam, std::string Cp, std::string xp, std::string Cn,
  std::string xn) : PlrBackDamper()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setCp(Cp);
  setXp(xp);
  setCn(Cn);
  setXn(xn);
}

void PlrBackDamper::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setLam(input.readNumber<std::string>());
  setCp(input.readNumber<std::string>());
  setXp(input.readNumber<std::string>());
  setCn(input.readNumber<std::string>());
  setXn(input.readNumber<std::string>());
}

std::string PlrBackDamper::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + ' ' + dataType() + ' ' + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->lam) + ' ' + PRJFLOAT_TO_STR(m_impl->Cp) + ' ' + PRJFLOAT_TO_STR(m_impl->xp) + ' ' + PRJFLOAT_TO_STR(m_impl->Cn)
    + ' ' + PRJFLOAT_TO_STR(m_impl->xn) + '\n';
  return string;
}

void PlrBackDamper::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setCp(input.readNumber<std::string>());
  setXp(input.readNumber<std::string>());
  setCn(input.readNumber<std::string>());
  setXn(input.readNumber<std::string>());
}

int PlrBackDamper::nr() const
{
  return m_impl->nr;
}

void PlrBackDamper::setNr(const int nr)
{
  m_impl->nr = nr;
}

int PlrBackDamper::icon() const
{
  return m_impl->icon;
}

void PlrBackDamper::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string PlrBackDamper::name() const
{
  return m_impl->name;
}

void PlrBackDamper::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string PlrBackDamper::desc() const
{
  return m_impl->desc;
}

void PlrBackDamper::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API PlrBackDamper::lam() const
{
  return to<double>(m_impl->lam);
}

template<> std::string PRJMODEL_API PlrBackDamper::lam() const
{
  return m_impl->lam;
}

bool PlrBackDamper::setLam(const double lam)
{
  m_impl->lam = to_float(lam);
  return true;
}

bool PlrBackDamper::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_impl->lam);
}

template<> double PRJMODEL_API PlrBackDamper::Cp() const
{
  return to<double>(m_impl->Cp);
}

template<> std::string PRJMODEL_API PlrBackDamper::Cp() const
{
  return m_impl->Cp;
}

bool PlrBackDamper::setCp(const double Cp)
{
  m_impl->Cp = to_float(Cp);
  return true;
}

bool PlrBackDamper::setCp(const std::string& Cp)
{
  return assign_if_valid<double>(Cp, m_impl->Cp);
}

template<> double PRJMODEL_API PlrBackDamper::xp() const
{
  return to<double>(m_impl->xp);
}

template<> std::string PRJMODEL_API PlrBackDamper::xp() const
{
  return m_impl->xp;
}

bool PlrBackDamper::setXp(const double xp)
{
  m_impl->xp = to_float(xp);
  return true;
}

bool PlrBackDamper::setXp(const std::string& xp)
{
  return assign_if_valid<double>(xp, m_impl->xp);
}

template<> double PRJMODEL_API PlrBackDamper::Cn() const
{
  return to<double>(m_impl->Cn);
}

template<> std::string PRJMODEL_API PlrBackDamper::Cn() const
{
  return m_impl->Cn;
}

bool PlrBackDamper::setCn(const double Cn)
{
  m_impl->Cn = to_float(Cn);
  return true;
}

bool PlrBackDamper::setCn(const std::string& Cn)
{
  return assign_if_valid<double>(Cn, m_impl->Cn);
}

template<> double PRJMODEL_API PlrBackDamper::xn() const
{
  return to<double>(m_impl->xn);
}

template<> std::string PRJMODEL_API PlrBackDamper::xn() const
{
  return m_impl->xn;
}

bool PlrBackDamper::setXn(const double xn)
{
  m_impl->xn = to_float(xn);
  return true;
}

bool PlrBackDamper::setXn(const std::string& xn)
{
  return assign_if_valid<double>(xn, m_impl->xn);
}


PlrBdq::PlrBdq() : PlrBackDamper()
{}

PlrBdq::PlrBdq(int nr,int icon,std::string name,std::string desc)
: PlrBackDamper(nr,icon,name,desc)
{}

PlrBdq::PlrBdq(int nr,int icon,std::string name,std::string desc,double lam,double Cp,double xp,double Cn,double xn)
: PlrBackDamper(nr,icon,name,desc,lam,Cp,xp,Cn,xn)
{}

PlrBdq::PlrBdq(int nr,int icon,std::string name,std::string desc,std::string lam,std::string Cp,std::string xp,std::string Cn,std::string xn)
: PlrBackDamper(nr,icon,name,desc,lam,Cp,xp,Cn,xn)
{}

PlrBdq::~PlrBdq()
{}

PlrBdf::PlrBdf() : PlrBackDamper()
{}

PlrBdf::PlrBdf(int nr,int icon,std::string name,std::string desc)
: PlrBackDamper(nr,icon,name,desc)
{}

PlrBdf::PlrBdf(int nr,int icon,std::string name,std::string desc,double lam,double Cp,double xp,double Cn,double xn)
: PlrBackDamper(nr,icon,name,desc,lam,Cp,xp,Cn,xn)
{}

PlrBdf::PlrBdf(int nr,int icon,std::string name,std::string desc,std::string lam,std::string Cp,std::string xp,std::string Cn,std::string xn)
: PlrBackDamper(nr,icon,name,desc,lam,Cp,xp,Cn,xn)
{}

PlrBdf::~PlrBdf()
{}

QfrGeneral::QfrGeneral() :
  m_impl(std::shared_ptr<Impl>(new Impl))
{}

QfrGeneral::QfrGeneral(const QfrGeneral &other) : m_impl(other.m_impl)
{}

QfrGeneral::~QfrGeneral()
{}

QfrGeneral& QfrGeneral::operator=(const QfrGeneral &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool QfrGeneral::operator==(const QfrGeneral &other) const
{
  return m_impl == other.m_impl;
}

bool QfrGeneral::operator!=(const QfrGeneral &other) const
{
  return m_impl != other.m_impl;
}

QfrGeneral::Impl::Impl() : nr(0), icon(0), a(PRJFLOAT("0.0")), b(PRJFLOAT("0.0"))
{}

QfrGeneral::QfrGeneral(int nr, int icon, std::string name, std::string desc) : QfrGeneral()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

QfrGeneral::QfrGeneral(int nr, int icon, std::string name, std::string desc, double a, double b) : QfrGeneral()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setA(a);
  setB(b);
}

QfrGeneral::QfrGeneral(int nr, int icon, std::string name, std::string desc, std::string a, std::string b) : QfrGeneral()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setA(a);
  setB(b);
}

void QfrGeneral::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setA(input.readNumber<std::string>());
  setB(input.readNumber<std::string>());
}

std::string QfrGeneral::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + ' ' + dataType() + ' ' + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->a) + ' ' + PRJFLOAT_TO_STR(m_impl->b) + '\n';
  return string;
}

void QfrGeneral::readDetails(Reader& input)
{
  setA(input.readNumber<std::string>());
  setB(input.readNumber<std::string>());
}

int QfrGeneral::nr() const
{
  return m_impl->nr;
}

void QfrGeneral::setNr(const int nr)
{
  m_impl->nr = nr;
}

int QfrGeneral::icon() const
{
  return m_impl->icon;
}

void QfrGeneral::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string QfrGeneral::name() const
{
  return m_impl->name;
}

void QfrGeneral::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string QfrGeneral::desc() const
{
  return m_impl->desc;
}

void QfrGeneral::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API QfrGeneral::a() const
{
  return to<double>(m_impl->a);
}

template<> std::string PRJMODEL_API QfrGeneral::a() const
{
  return m_impl->a;
}

bool QfrGeneral::setA(const double a)
{
  m_impl->a = to_float(a);
  return true;
}

bool QfrGeneral::setA(const std::string& a)
{
  return assign_if_valid<double>(a, m_impl->a);
}

template<> double PRJMODEL_API QfrGeneral::b() const
{
  return to<double>(m_impl->b);
}

template<> std::string PRJMODEL_API QfrGeneral::b() const
{
  return m_impl->b;
}

bool QfrGeneral::setB(const double b)
{
  m_impl->b = to_float(b);
  return true;
}

bool QfrGeneral::setB(const std::string& b)
{
  return assign_if_valid<double>(b, m_impl->b);
}

QfrQab::QfrQab() : QfrGeneral()
{}

QfrQab::QfrQab(int nr,int icon,std::string name,std::string desc) : QfrGeneral(nr,icon,name,desc)
{}

QfrQab::QfrQab(int nr,int icon,std::string name,std::string desc,double a,double b)
: QfrGeneral(nr,icon,name,desc,a,b)
{}

QfrQab::QfrQab(int nr,int icon,std::string name,std::string desc,std::string a,std::string b)
: QfrGeneral(nr,icon,name,desc,a,b)
{}

QfrQab::~QfrQab()
{}

QfrFab::QfrFab() : QfrGeneral()
{}

QfrFab::QfrFab(int nr,int icon,std::string name,std::string desc) : QfrGeneral(nr,icon,name,desc)
{}

QfrFab::QfrFab(int nr,int icon,std::string name,std::string desc,double a,double b)
: QfrGeneral(nr,icon,name,desc,a,b)
{}

QfrFab::QfrFab(int nr,int icon,std::string name,std::string desc,std::string a,std::string b)
: QfrGeneral(nr,icon,name,desc,a,b)
{}

QfrFab::~QfrFab()
{}

QfrCrack::QfrCrack() :
  m_impl(std::shared_ptr<Impl>(new Impl))
{}

QfrCrack::QfrCrack(const QfrCrack &other) : m_impl(other.m_impl)
{}

QfrCrack::~QfrCrack()
{}

QfrCrack& QfrCrack::operator=(const QfrCrack &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool QfrCrack::operator==(const QfrCrack &other) const
{
  return m_impl == other.m_impl;
}

bool QfrCrack::operator!=(const QfrCrack &other) const
{
  return m_impl != other.m_impl;
}

QfrCrack::Impl::Impl() : nr(0), icon(0), a(PRJFLOAT("0.0")), b(PRJFLOAT("0.0")), length(PRJFLOAT("0.0")),
width(PRJFLOAT("0.0")), depth(PRJFLOAT("0.0")), nB(0), u_L(0), u_W(0), u_D(0)
{}

QfrCrack::QfrCrack(int nr, int icon, std::string name, std::string desc) : QfrCrack()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

QfrCrack::QfrCrack(int nr, int icon, std::string name, std::string desc, double a, double b, double length,
  double width, double depth, int nB, int u_L, int u_W, int u_D) : QfrCrack()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setA(a);
  setB(b);
  setLength(length);
  setWidth(width);
  setDepth(depth);
  setNB(nB);
  setU_L(u_L);
  setU_W(u_W);
  setU_D(u_D);
}

QfrCrack::QfrCrack(int nr, int icon, std::string name, std::string desc, std::string a, std::string b, std::string length,
  std::string width, std::string depth, int nB, int u_L, int u_W, int u_D) : QfrCrack()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setA(a);
  setB(b);
  setLength(length);
  setWidth(width);
  setDepth(depth);
  setNB(nB);
  setU_L(u_L);
  setU_W(u_W);
  setU_D(u_D);
}

void QfrCrack::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setA(input.readNumber<std::string>());
  setB(input.readNumber<std::string>());
  setLength(input.readNumber<std::string>());
  setWidth(input.readNumber<std::string>());
  setDepth(input.readNumber<std::string>());
  setNB(input.read<int>());
  setU_L(input.read<int>());
  setU_W(input.read<int>());
  setU_D(input.read<int>());
}

std::string QfrCrack::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + " qfr_crack " + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->a) + ' ' + PRJFLOAT_TO_STR(m_impl->b) + ' ' + PRJFLOAT_TO_STR(m_impl->length) + ' ' + PRJFLOAT_TO_STR(m_impl->width)
    + ' ' + PRJFLOAT_TO_STR(m_impl->depth) + ' ' + ANY_TO_STR(m_impl->nB) + ' ' + ANY_TO_STR(m_impl->u_L) + ' '
    + ANY_TO_STR(m_impl->u_W) + ' ' + ANY_TO_STR(m_impl->u_D) + '\n';
  return string;
}

void QfrCrack::readDetails(Reader& input)
{
  setA(input.readNumber<std::string>());
  setB(input.readNumber<std::string>());
  setLength(input.readNumber<std::string>());
  setWidth(input.readNumber<std::string>());
  setDepth(input.readNumber<std::string>());
  setNB(input.read<int>());
  setU_L(input.read<int>());
  setU_W(input.read<int>());
  setU_D(input.read<int>());
}

int QfrCrack::nr() const
{
  return m_impl->nr;
}

void QfrCrack::setNr(const int nr)
{
  m_impl->nr = nr;
}

int QfrCrack::icon() const
{
  return m_impl->icon;
}

void QfrCrack::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string QfrCrack::name() const
{
  return m_impl->name;
}

void QfrCrack::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string QfrCrack::desc() const
{
  return m_impl->desc;
}

void QfrCrack::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API QfrCrack::a() const
{
  return to<double>(m_impl->a);
}

template<> std::string PRJMODEL_API QfrCrack::a() const
{
  return m_impl->a;
}

bool QfrCrack::setA(const double a)
{
  m_impl->a = to_float(a);
  return true;
}

bool QfrCrack::setA(const std::string& a)
{
  return assign_if_valid<double>(a, m_impl->a);
}

template<> double PRJMODEL_API QfrCrack::b() const
{
  return to<double>(m_impl->b);
}

template<> std::string PRJMODEL_API QfrCrack::b() const
{
  return m_impl->b;
}

bool QfrCrack::setB(const double b)
{
  m_impl->b = to_float(b);
  return true;
}

bool QfrCrack::setB(const std::string& b)
{
  return assign_if_valid<double>(b, m_impl->b);
}

template<> double PRJMODEL_API QfrCrack::length() const
{
  return to<double>(m_impl->length);
}

template<> std::string PRJMODEL_API QfrCrack::length() const
{
  return m_impl->length;
}

bool QfrCrack::setLength(const double length)
{
  m_impl->length = to_float(length);
  return true;
}

bool QfrCrack::setLength(const std::string& length)
{
  return assign_if_valid<double>(length, m_impl->length);
}

template<> double PRJMODEL_API QfrCrack::width() const
{
  return to<double>(m_impl->width);
}

template<> std::string PRJMODEL_API QfrCrack::width() const
{
  return m_impl->width;
}

bool QfrCrack::setWidth(const double width)
{
  m_impl->width = to_float(width);
  return true;
}

bool QfrCrack::setWidth(const std::string& width)
{
  return assign_if_valid<double>(width, m_impl->width);
}

template<> double PRJMODEL_API QfrCrack::depth() const
{
  return to<double>(m_impl->depth);
}

template<> std::string PRJMODEL_API QfrCrack::depth() const
{
  return m_impl->depth;
}

bool QfrCrack::setDepth(const double depth)
{
  m_impl->depth = to_float(depth);
  return true;
}

bool QfrCrack::setDepth(const std::string& depth)
{
  return assign_if_valid<double>(depth, m_impl->depth);
}

int QfrCrack::nB() const
{
  return m_impl->nB;
}

void QfrCrack::setNB(const int nB)
{
  m_impl->nB = nB;
}

int QfrCrack::u_L() const
{
  return m_impl->u_L;
}

void QfrCrack::setU_L(const int u_L)
{
  m_impl->u_L = u_L;
}

int QfrCrack::u_W() const
{
  return m_impl->u_W;
}

void QfrCrack::setU_W(const int u_W)
{
  m_impl->u_W = u_W;
}

int QfrCrack::u_D() const
{
  return m_impl->u_D;
}

void QfrCrack::setU_D(const int u_D)
{
  m_impl->u_D = u_D;
}

QfrTest2::QfrTest2() :
  m_impl(std::shared_ptr<Impl>(new Impl))
{}

QfrTest2::QfrTest2(const QfrTest2 &other) : m_impl(other.m_impl)
{}

QfrTest2::~QfrTest2()
{}

QfrTest2& QfrTest2::operator=(const QfrTest2 &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool QfrTest2::operator==(const QfrTest2 &other) const
{
  return m_impl == other.m_impl;
}

bool QfrTest2::operator!=(const QfrTest2 &other) const
{
  return m_impl != other.m_impl;
}

QfrTest2::Impl::Impl() : nr(0), icon(0), a(PRJFLOAT("0.0")), b(PRJFLOAT("0.0")), dP1(PRJFLOAT("0.0")),
F1(PRJFLOAT("0.0")), dP2(PRJFLOAT("0.0")), F2(PRJFLOAT("0.0")), u_P1(0), u_F1(0), u_P2(0), u_F2(0)
{}

QfrTest2::QfrTest2(int nr, int icon, std::string name, std::string desc) : QfrTest2()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

QfrTest2::QfrTest2(int nr, int icon, std::string name, std::string desc, double a, double b, double dP1, double F1,
  double dP2, double F2, int u_P1, int u_F1, int u_P2, int u_F2) : QfrTest2()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setA(a);
  setB(b);
  setDP1(dP1);
  setF1(F1);
  setDP2(dP2);
  setF2(F2);
  setU_P1(u_P1);
  setU_F1(u_F1);
  setU_P2(u_P2);
  setU_F2(u_F2);
}

QfrTest2::QfrTest2(int nr, int icon, std::string name, std::string desc, std::string a, std::string b, std::string dP1, std::string F1,
  std::string dP2, std::string F2, int u_P1, int u_F1, int u_P2, int u_F2) : QfrTest2()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setA(a);
  setB(b);
  setDP1(dP1);
  setF1(F1);
  setDP2(dP2);
  setF2(F2);
  setU_P1(u_P1);
  setU_F1(u_F1);
  setU_P2(u_P2);
  setU_F2(u_F2);
}

void QfrTest2::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setA(input.readNumber<std::string>());
  setB(input.readNumber<std::string>());
  setDP1(input.readNumber<std::string>());
  setF1(input.readNumber<std::string>());
  setDP2(input.readNumber<std::string>());
  setF2(input.readNumber<std::string>());
  setU_P1(input.read<int>());
  setU_F1(input.read<int>());
  setU_P2(input.read<int>());
  setU_F2(input.read<int>());
}

std::string QfrTest2::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + " qfr_test2 " + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->a) + ' ' + PRJFLOAT_TO_STR(m_impl->b) + ' ' + PRJFLOAT_TO_STR(m_impl->dP1) + ' ' + PRJFLOAT_TO_STR(m_impl->F1)
    + ' ' + PRJFLOAT_TO_STR(m_impl->dP2) + ' ' + PRJFLOAT_TO_STR(m_impl->F2) + ' ' + ANY_TO_STR(m_impl->u_P1) + ' '
    + ANY_TO_STR(m_impl->u_F1) + ' ' + ANY_TO_STR(m_impl->u_P2) + ' ' + ANY_TO_STR(m_impl->u_F2) + '\n';
  return string;
}

void QfrTest2::readDetails(Reader& input)
{
  setA(input.readNumber<std::string>());
  setB(input.readNumber<std::string>());
  setDP1(input.readNumber<std::string>());
  setF1(input.readNumber<std::string>());
  setDP2(input.readNumber<std::string>());
  setF2(input.readNumber<std::string>());
  setU_P1(input.read<int>());
  setU_F1(input.read<int>());
  setU_P2(input.read<int>());
  setU_F2(input.read<int>());
}

int QfrTest2::nr() const
{
  return m_impl->nr;
}

void QfrTest2::setNr(const int nr)
{
  m_impl->nr = nr;
}

int QfrTest2::icon() const
{
  return m_impl->icon;
}

void QfrTest2::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string QfrTest2::name() const
{
  return m_impl->name;
}

void QfrTest2::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string QfrTest2::desc() const
{
  return m_impl->desc;
}

void QfrTest2::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API QfrTest2::a() const
{
  return to<double>(m_impl->a);
}

template<> std::string PRJMODEL_API QfrTest2::a() const
{
  return m_impl->a;
}

bool QfrTest2::setA(const double a)
{
  m_impl->a = to_float(a);
  return true;
}

bool QfrTest2::setA(const std::string& a)
{
  return assign_if_valid<double>(a, m_impl->a);
}

template<> double PRJMODEL_API QfrTest2::b() const
{
  return to<double>(m_impl->b);
}

template<> std::string PRJMODEL_API QfrTest2::b() const
{
  return m_impl->b;
}

bool QfrTest2::setB(const double b)
{
  m_impl->b = to_float(b);
  return true;
}

bool QfrTest2::setB(const std::string& b)
{
  return assign_if_valid<double>(b, m_impl->b);
}

template<> double PRJMODEL_API QfrTest2::dP1() const
{
  return to<double>(m_impl->dP1);
}

template<> std::string PRJMODEL_API QfrTest2::dP1() const
{
  return m_impl->dP1;
}

bool QfrTest2::setDP1(const double dP1)
{
  m_impl->dP1 = to_float(dP1);
  return true;
}

bool QfrTest2::setDP1(const std::string& dP1)
{
  return assign_if_valid<double>(dP1, m_impl->dP1);
}

template<> double PRJMODEL_API QfrTest2::F1() const
{
  return to<double>(m_impl->F1);
}

template<> std::string PRJMODEL_API QfrTest2::F1() const
{
  return m_impl->F1;
}

bool QfrTest2::setF1(const double F1)
{
  m_impl->F1 = to_float(F1);
  return true;
}

bool QfrTest2::setF1(const std::string& F1)
{
  return assign_if_valid<double>(F1, m_impl->F1);
}

template<> double PRJMODEL_API QfrTest2::dP2() const
{
  return to<double>(m_impl->dP2);
}

template<> std::string PRJMODEL_API QfrTest2::dP2() const
{
  return m_impl->dP2;
}

bool QfrTest2::setDP2(const double dP2)
{
  m_impl->dP2 = to_float(dP2);
  return true;
}

bool QfrTest2::setDP2(const std::string& dP2)
{
  return assign_if_valid<double>(dP2, m_impl->dP2);
}

template<> double PRJMODEL_API QfrTest2::F2() const
{
  return to<double>(m_impl->F2);
}

template<> std::string PRJMODEL_API QfrTest2::F2() const
{
  return m_impl->F2;
}

bool QfrTest2::setF2(const double F2)
{
  m_impl->F2 = to_float(F2);
  return true;
}

bool QfrTest2::setF2(const std::string& F2)
{
  return assign_if_valid<double>(F2, m_impl->F2);
}

int QfrTest2::u_P1() const
{
  return m_impl->u_P1;
}

void QfrTest2::setU_P1(const int u_P1)
{
  m_impl->u_P1 = u_P1;
}

int QfrTest2::u_F1() const
{
  return m_impl->u_F1;
}

void QfrTest2::setU_F1(const int u_F1)
{
  m_impl->u_F1 = u_F1;
}

int QfrTest2::u_P2() const
{
  return m_impl->u_P2;
}

void QfrTest2::setU_P2(const int u_P2)
{
  m_impl->u_P2 = u_P2;
}

int QfrTest2::u_F2() const
{
  return m_impl->u_F2;
}

void QfrTest2::setU_F2(const int u_F2)
{
  m_impl->u_F2 = u_F2;
}

AfeDor::AfeDor() :
  m_impl(std::shared_ptr<Impl>(new Impl))
{}

AfeDor::AfeDor(const AfeDor &other) : m_impl(other.m_impl)
{}

AfeDor::~AfeDor()
{}

AfeDor& AfeDor::operator=(const AfeDor &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool AfeDor::operator==(const AfeDor &other) const
{
  return m_impl == other.m_impl;
}

bool AfeDor::operator!=(const AfeDor &other) const
{
  return m_impl != other.m_impl;
}

AfeDor::Impl::Impl() : nr(0), icon(0), lam(PRJFLOAT("0.0")), turb(PRJFLOAT("0.0")), expt(PRJFLOAT("0.0")),
dTmin(PRJFLOAT("0.0")), ht(PRJFLOAT("0.0")), wd(PRJFLOAT("0.0")), cd(PRJFLOAT("0.0")), u_T(0), u_H(0), u_W(0)
{}

AfeDor::AfeDor(int nr, int icon, std::string name, std::string desc) : AfeDor()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

AfeDor::AfeDor(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt,
  double dTmin, double ht, double wd, double cd, int u_T, int u_H, int u_W) : AfeDor()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setDTmin(dTmin);
  setHeight(ht);
  setWidth(wd);
  setCd(cd);
  setU_T(u_T);
  setU_H(u_H);
  setU_W(u_W);
}

AfeDor::AfeDor(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt,
  std::string dTmin, std::string ht, std::string wd, std::string cd, int u_T, int u_H, int u_W) : AfeDor()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setDTmin(dTmin);
  setHeight(ht);
  setWidth(wd);
  setCd(cd);
  setU_T(u_T);
  setU_H(u_H);
  setU_W(u_W);
}

void AfeDor::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setDTmin(input.readNumber<std::string>());
  setHeight(input.readNumber<std::string>());
  setWidth(input.readNumber<std::string>());
  setCd(input.readNumber<std::string>());
  setU_T(input.read<int>());
  setU_H(input.read<int>());
  setU_W(input.read<int>());
}

std::string AfeDor::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + " dor_door " + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->lam) + ' ' + PRJFLOAT_TO_STR(m_impl->turb) + ' ' + PRJFLOAT_TO_STR(m_impl->expt) + ' '
    + PRJFLOAT_TO_STR(m_impl->dTmin) + ' ' + PRJFLOAT_TO_STR(m_impl->ht) + ' ' + PRJFLOAT_TO_STR(m_impl->wd) + ' '
    + PRJFLOAT_TO_STR(m_impl->cd) + ' ' + ANY_TO_STR(m_impl->u_T) + ' ' + ANY_TO_STR(m_impl->u_H) + ' '
    + ANY_TO_STR(m_impl->u_W) + '\n';
  return string;
}

void AfeDor::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setDTmin(input.readNumber<std::string>());
  setHeight(input.readNumber<std::string>());
  setWidth(input.readNumber<std::string>());
  setCd(input.readNumber<std::string>());
  setU_T(input.read<int>());
  setU_H(input.read<int>());
  setU_W(input.read<int>());
}

int AfeDor::nr() const
{
  return m_impl->nr;
}

void AfeDor::setNr(const int nr)
{
  m_impl->nr = nr;
}

int AfeDor::icon() const
{
  return m_impl->icon;
}

void AfeDor::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string AfeDor::name() const
{
  return m_impl->name;
}

void AfeDor::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string AfeDor::desc() const
{
  return m_impl->desc;
}

void AfeDor::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API AfeDor::lam() const
{
  return to<double>(m_impl->lam);
}

template<> std::string PRJMODEL_API AfeDor::lam() const
{
  return m_impl->lam;
}

bool AfeDor::setLam(const double lam)
{
  m_impl->lam = to_float(lam);
  return true;
}

bool AfeDor::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_impl->lam);
}

template<> double PRJMODEL_API AfeDor::turb() const
{
  return to<double>(m_impl->turb);
}

template<> std::string PRJMODEL_API AfeDor::turb() const
{
  return m_impl->turb;
}

bool AfeDor::setTurb(const double turb)
{
  m_impl->turb = to_float(turb);
  return true;
}

bool AfeDor::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_impl->turb);
}

template<> double PRJMODEL_API AfeDor::expt() const
{
  return to<double>(m_impl->expt);
}

template<> std::string PRJMODEL_API AfeDor::expt() const
{
  return m_impl->expt;
}

bool AfeDor::setExpt(const double expt)
{
  m_impl->expt = to_float(expt);
  return true;
}

bool AfeDor::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_impl->expt);
}

template<> double PRJMODEL_API AfeDor::dTmin() const
{
  return to<double>(m_impl->dTmin);
}

template<> std::string PRJMODEL_API AfeDor::dTmin() const
{
  return m_impl->dTmin;
}

bool AfeDor::setDTmin(const double dTmin)
{
  m_impl->dTmin = to_float(dTmin);
  return true;
}

bool AfeDor::setDTmin(const std::string& dTmin)
{
  return assign_if_valid<double>(dTmin, m_impl->dTmin);
}

template<> double PRJMODEL_API AfeDor::height() const
{
  return to<double>(m_impl->ht);
}

template<> std::string PRJMODEL_API AfeDor::height() const
{
  return m_impl->ht;
}

bool AfeDor::setHeight(const double ht)
{
  m_impl->ht = to_float(ht);
  return true;
}

bool AfeDor::setHeight(const std::string& ht)
{
  return assign_if_valid<double>(ht, m_impl->ht);
}

template<> double PRJMODEL_API AfeDor::width() const
{
  return to<double>(m_impl->wd);
}

template<> std::string PRJMODEL_API AfeDor::width() const
{
  return m_impl->wd;
}

bool AfeDor::setWidth(const double wd)
{
  m_impl->wd = to_float(wd);
  return true;
}

bool AfeDor::setWidth(const std::string& wd)
{
  return assign_if_valid<double>(wd, m_impl->wd);
}

template<> double PRJMODEL_API AfeDor::cd() const
{
  return to<double>(m_impl->cd);
}

bool AfeDor::setCd(const double cd)
{
  m_impl->cd = to_float(cd);
  return true;
}

bool AfeDor::setCd(const std::string& cd)
{
  return assign_if_valid<double>(cd, m_impl->cd);
}

int AfeDor::u_T() const
{
  return m_impl->u_T;
}

void AfeDor::setU_T(const int u_T)
{
  m_impl->u_T = u_T;
}

int AfeDor::u_H() const
{
  return m_impl->u_H;
}

void AfeDor::setU_H(const int u_H)
{
  m_impl->u_H = u_H;
}

int AfeDor::u_W() const
{
  return m_impl->u_W;
}

void AfeDor::setU_W(const int u_W)
{
  m_impl->u_W = u_W;
}

DrPl2::DrPl2() :
  m_impl(std::shared_ptr<Impl>(new Impl))
{}

DrPl2::DrPl2(const DrPl2 &other) : m_impl(other.m_impl)
{}

DrPl2::~DrPl2()
{}

DrPl2& DrPl2::operator=(const DrPl2 &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool DrPl2::operator==(const DrPl2 &other) const
{
  return m_impl == other.m_impl;
}

bool DrPl2::operator!=(const DrPl2 &other) const
{
  return m_impl != other.m_impl;
}

DrPl2::Impl::Impl() : nr(0), icon(0), lam(PRJFLOAT("0.0")), turb(PRJFLOAT("0.0")), expt(PRJFLOAT("0.0")),
dH(PRJFLOAT("0.0")), ht(PRJFLOAT("0.0")), wd(PRJFLOAT("0.0")), cd(PRJFLOAT("0.0")), u_H(0), u_W(0)
{}

DrPl2::DrPl2(int nr, int icon, std::string name, std::string desc) : DrPl2()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

DrPl2::DrPl2(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt, double dH,
  double ht, double wd, double cd, int u_H, int u_W) : DrPl2()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setDH(dH);
  setHeight(ht);
  setWidth(wd);
  setCd(cd);
  setU_H(u_H);
  setU_W(u_W);
}

DrPl2::DrPl2(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt, std::string dH,
  std::string ht, std::string wd, std::string cd, int u_H, int u_W) : DrPl2()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setDH(dH);
  setHeight(ht);
  setWidth(wd);
  setCd(cd);
  setU_H(u_H);
  setU_W(u_W);
}

void DrPl2::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setDH(input.readNumber<std::string>());
  setHeight(input.readNumber<std::string>());
  setWidth(input.readNumber<std::string>());
  setCd(input.readNumber<std::string>());
  setU_H(input.read<int>());
  setU_W(input.read<int>());
}

std::string DrPl2::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + " dor_pl2 " + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->lam) + ' ' + PRJFLOAT_TO_STR(m_impl->turb) + ' ' + PRJFLOAT_TO_STR(m_impl->expt) + ' '
    + PRJFLOAT_TO_STR(m_impl->dH) + ' ' + PRJFLOAT_TO_STR(m_impl->ht) + ' ' + PRJFLOAT_TO_STR(m_impl->wd) + ' ' + PRJFLOAT_TO_STR(m_impl->cd)
    + ' ' + ANY_TO_STR(m_impl->u_H) + ' ' + ANY_TO_STR(m_impl->u_W) + '\n';
  return string;
}

void DrPl2::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setDH(input.readNumber<std::string>());
  setHeight(input.readNumber<std::string>());
  setWidth(input.readNumber<std::string>());
  setCd(input.readNumber<std::string>());
  setU_H(input.read<int>());
  setU_W(input.read<int>());
}

int DrPl2::nr() const
{
  return m_impl->nr;
}

void DrPl2::setNr(const int nr)
{
  m_impl->nr = nr;
}

int DrPl2::icon() const
{
  return m_impl->icon;
}

void DrPl2::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string DrPl2::name() const
{
  return m_impl->name;
}

void DrPl2::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string DrPl2::desc() const
{
  return m_impl->desc;
}

void DrPl2::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API DrPl2::lam() const
{
  return to<double>(m_impl->lam);
}

template<> std::string PRJMODEL_API DrPl2::lam() const
{
  return m_impl->lam;
}

bool DrPl2::setLam(const double lam)
{
  m_impl->lam = to_float(lam);
  return true;
}

bool DrPl2::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_impl->lam);
}

template<> double PRJMODEL_API DrPl2::turb() const
{
  return to<double>(m_impl->turb);
}

template<> std::string PRJMODEL_API DrPl2::turb() const
{
  return m_impl->turb;
}

bool DrPl2::setTurb(const double turb)
{
  m_impl->turb = to_float(turb);
  return true;
}

bool DrPl2::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_impl->turb);
}

template<> double PRJMODEL_API DrPl2::expt() const
{
  return to<double>(m_impl->expt);
}

template<> std::string PRJMODEL_API DrPl2::expt() const
{
  return m_impl->expt;
}

bool DrPl2::setExpt(const double expt)
{
  m_impl->expt = to_float(expt);
  return true;
}

bool DrPl2::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_impl->expt);
}

template<> double PRJMODEL_API DrPl2::dH() const
{
  return to<double>(m_impl->dH);
}

template<> std::string PRJMODEL_API DrPl2::dH() const
{
  return m_impl->dH;
}

bool DrPl2::setDH(const double dH)
{
  m_impl->dH = to_float(dH);
  return true;
}

bool DrPl2::setDH(const std::string& dH)
{
  return assign_if_valid<double>(dH, m_impl->dH);
}

template<> double PRJMODEL_API DrPl2::height() const
{
  return to<double>(m_impl->ht);
}

template<> std::string PRJMODEL_API DrPl2::height() const
{
  return m_impl->ht;
}

bool DrPl2::setHeight(const double ht)
{
  m_impl->ht = to_float(ht);
  return true;
}

bool DrPl2::setHeight(const std::string& ht)
{
  return assign_if_valid<double>(ht, m_impl->ht);
}

template<> double PRJMODEL_API DrPl2::width() const
{
  return to<double>(m_impl->wd);
}

template<> std::string PRJMODEL_API DrPl2::width() const
{
  return m_impl->wd;
}

bool DrPl2::setWidth(const double wd)
{
  m_impl->wd = to_float(wd);
  return true;
}

bool DrPl2::setWidth(const std::string& wd)
{
  return assign_if_valid<double>(wd, m_impl->wd);
}

template<> double PRJMODEL_API DrPl2::cd() const
{
  return to<double>(m_impl->cd);
}

template<> std::string PRJMODEL_API DrPl2::cd() const
{
  return m_impl->cd;
}

bool DrPl2::setCd(const double cd)
{
  m_impl->cd = to_float(cd);
  return true;
}

bool DrPl2::setCd(const std::string& cd)
{
  return assign_if_valid<double>(cd, m_impl->cd);
}

int DrPl2::u_H() const
{
  return m_impl->u_H;
}

void DrPl2::setU_H(const int u_H)
{
  m_impl->u_H = u_H;
}

int DrPl2::u_W() const
{
  return m_impl->u_W;
}

void DrPl2::setU_W(const int u_W)
{
  m_impl->u_W = u_W;
}

AfeFlow::AfeFlow() : m_impl(std::shared_ptr<Impl>(new Impl))
{}

AfeFlow::AfeFlow(const AfeFlow &other) : m_impl(other.m_impl)
{}

AfeFlow::~AfeFlow()
{}

AfeFlow& AfeFlow::operator=(const AfeFlow &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool AfeFlow::operator==(const AfeFlow &other) const
{
  return m_impl == other.m_impl;
}

bool AfeFlow::operator!=(const AfeFlow &other) const
{
  return m_impl != other.m_impl;
}

AfeFlow::Impl::Impl() : nr(0), icon(0), Flow(PRJFLOAT("0.0")), u_F(0)
{}

AfeFlow::AfeFlow(int nr, int icon, std::string name, std::string desc) : AfeFlow()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

AfeFlow::AfeFlow(int nr, int icon, std::string name, std::string desc, double Flow, int u_F) : AfeFlow()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setFlow(Flow);
  setU_F(u_F);
}

AfeFlow::AfeFlow(int nr, int icon, std::string name, std::string desc, std::string Flow, int u_F) : AfeFlow()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setFlow(Flow);
  setU_F(u_F);
}

void AfeFlow::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setFlow(input.readNumber<std::string>());
  setU_F(input.read<int>());
}

std::string AfeFlow::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + ' ' + dataType() + ' ' + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->Flow) + ' ' + ANY_TO_STR(m_impl->u_F) + '\n';
  return string;
}

void AfeFlow::readDetails(Reader& input)
{
  setFlow(input.readNumber<std::string>());
  setU_F(input.read<int>());
}

int AfeFlow::nr() const
{
  return m_impl->nr;
}

void AfeFlow::setNr(const int nr)
{
  m_impl->nr = nr;
}

int AfeFlow::icon() const
{
  return m_impl->icon;
}

void AfeFlow::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string AfeFlow::name() const
{
  return m_impl->name;
}

void AfeFlow::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string AfeFlow::desc() const
{
  return m_impl->desc;
}

void AfeFlow::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API AfeFlow::Flow() const
{
  return to<double>(m_impl->Flow);
}

template<> std::string PRJMODEL_API AfeFlow::Flow() const
{
  return m_impl->Flow;
}

bool AfeFlow::setFlow(const double Flow)
{
  m_impl->Flow = to_float(Flow);
  return true;
}

bool AfeFlow::setFlow(const std::string& Flow)
{
  return assign_if_valid<double>(Flow, m_impl->Flow);
}

int AfeFlow::u_F() const
{
  return m_impl->u_F;
}

void AfeFlow::setU_F(const int u_F)
{
  m_impl->u_F = u_F;
}


AfeCmf::AfeCmf() : AfeFlow()
{}

AfeCmf::AfeCmf(int nr,int icon,std::string name,std::string desc) : AfeFlow(nr,icon,name,desc)
{}

AfeCmf::AfeCmf(int nr,int icon,std::string name,std::string desc,double Flow,int u_F)
: AfeFlow(nr,icon,name,desc,Flow,u_F)
{}

AfeCmf::AfeCmf(int nr,int icon,std::string name,std::string desc,std::string Flow,int u_F)
: AfeFlow(nr,icon,name,desc,Flow,u_F)
{}

AfeCmf::~AfeCmf()
{}

AfeCvf::AfeCvf() : AfeFlow()
{}

AfeCvf::AfeCvf(int nr,int icon,std::string name,std::string desc) : AfeFlow(nr,icon,name,desc)
{}

AfeCvf::AfeCvf(int nr,int icon,std::string name,std::string desc,double Flow,int u_F)
: AfeFlow(nr,icon,name,desc,Flow,u_F)
{}

AfeCvf::AfeCvf(int nr,int icon,std::string name,std::string desc,std::string Flow,int u_F)
: AfeFlow(nr,icon,name,desc,Flow,u_F)
{}

AfeCvf::~AfeCvf()
{}

AfeFan::AfeFan() :
  m_impl(std::shared_ptr<Impl>(new Impl))
{}

AfeFan::AfeFan(const AfeFan &other) : m_impl(other.m_impl)
{}

AfeFan::~AfeFan()
{}

AfeFan& AfeFan::operator=(const AfeFan &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool AfeFan::operator==(const AfeFan &other) const
{
  return m_impl == other.m_impl;
}

bool AfeFan::operator!=(const AfeFan &other) const
{
  return m_impl != other.m_impl;
}

AfeFan::Impl::Impl() : nr(0), icon(0), lam(PRJFLOAT("0.0")), turb(PRJFLOAT("0.0")), expt(PRJFLOAT("0.0")),
rdens(PRJFLOAT("0.0")), fdf(PRJFLOAT("0.0")), sop(PRJFLOAT("0.0")), off(PRJFLOAT("0.0")), Sarea(PRJFLOAT("0.0")), u_Sa(0)
{}

AfeFan::AfeFan(int nr, int icon, std::string name, std::string desc) : AfeFan()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

AfeFan::AfeFan(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt,
  double rdens, double fdf, double sop, double off, std::vector<double> fpc, double Sarea,
  int u_Sa, std::vector<FanDataPoint> data) : AfeFan()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setRdens(rdens);
  setFdf(fdf);
  setSop(sop);
  setOff(off);
  setFpc(fpc);
  setSarea(Sarea);
  setU_Sa(u_Sa);
  setData(data);
}

AfeFan::AfeFan(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt,
  std::string rdens, std::string fdf, std::string sop, std::string off, std::vector<std::string> fpc, std::string Sarea,
  int u_Sa, std::vector<FanDataPoint> data) : AfeFan()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
  setRdens(rdens);
  setFdf(fdf);
  setSop(sop);
  setOff(off);
  setFpc(fpc);
  setSarea(Sarea);
  setU_Sa(u_Sa);
  setData(data);
}

void AfeFan::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setRdens(input.readNumber<std::string>());
  setFdf(input.readNumber<std::string>());
  setSop(input.readNumber<std::string>());
  setOff(input.readNumber<std::string>());
  std::vector<std::string> fpc;
  for (int i = 0; i < 4; i++) {
    fpc.push_back(input.read<std::string>());
  }
  setFpc(fpc);
  int npts = input.read<int>();
  setSarea(input.readNumber<std::string>());
  setU_Sa(input.read<int>());
  std::vector<FanDataPoint> data;
  for (int i = 0; i < npts; i++) {
    FanDataPoint object;
    object.read(input);
    data.push_back(object);
  }
  setData(data);
}

std::string AfeFan::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + " fan_fan " + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->lam) + ' ' + PRJFLOAT_TO_STR(m_impl->turb) + ' ' + PRJFLOAT_TO_STR(m_impl->expt) + ' ' + PRJFLOAT_TO_STR(m_impl->rdens)
    + ' ' + PRJFLOAT_TO_STR(m_impl->fdf) + ' ' + PRJFLOAT_TO_STR(m_impl->sop) + ' ' + PRJFLOAT_TO_STR(m_impl->off) + '\n';
  for (int i = 0; i < 4; i++)
    string += PRJFLOAT_TO_STR(m_impl->fpc[i]) + ' ';
  string += '\n';
  string += ANY_TO_STR((int)m_impl->data.size()) + ' ' + PRJFLOAT_TO_STR(m_impl->Sarea) + ' ' + ANY_TO_STR(m_impl->u_Sa) + '\n';
  for (unsigned int i = 0; i < m_impl->data.size(); i++) {
    string += m_impl->data[i].write();
  }
  return string;
}

void AfeFan::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setRdens(input.readNumber<std::string>());
  setFdf(input.readNumber<std::string>());
  setSop(input.readNumber<std::string>());
  setOff(input.readNumber<std::string>());
  std::vector<std::string> fpc;
  for (int i = 0; i < 4; i++) {
    fpc.push_back(input.read<std::string>());
  }
  setFpc(fpc);
  int npts = input.read<int>();
  setSarea(input.readNumber<std::string>());
  setU_Sa(input.read<int>());
  std::vector<FanDataPoint> data;
  for (int i = 0; i < npts; i++) {
    FanDataPoint object;
    object.read(input);
    data.push_back(object);
  }
  setData(data);
}

int AfeFan::nr() const
{
  return m_impl->nr;
}

void AfeFan::setNr(const int nr)
{
  m_impl->nr = nr;
}

int AfeFan::icon() const
{
  return m_impl->icon;
}

void AfeFan::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string AfeFan::name() const
{
  return m_impl->name;
}

void AfeFan::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string AfeFan::desc() const
{
  return m_impl->desc;
}

void AfeFan::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

template<> double PRJMODEL_API AfeFan::lam() const
{
  return to<double>(m_impl->lam);
}

template<> std::string PRJMODEL_API AfeFan::lam() const
{
  return m_impl->lam;
}

bool AfeFan::setLam(const double lam)
{
  m_impl->lam = to_float(lam);
  return true;
}

bool AfeFan::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_impl->lam);
}

template<> double PRJMODEL_API AfeFan::turb() const
{
  return to<double>(m_impl->turb);
}

template<> std::string PRJMODEL_API AfeFan::turb() const
{
  return m_impl->turb;
}

bool AfeFan::setTurb(const double turb)
{
  m_impl->turb = to_float(turb);
  return true;
}

bool AfeFan::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_impl->turb);
}

template<> double PRJMODEL_API AfeFan::expt() const
{
  return to<double>(m_impl->expt);
}

template<> std::string PRJMODEL_API AfeFan::expt() const
{
  return m_impl->expt;
}

bool AfeFan::setExpt(const double expt)
{
  m_impl->expt = to_float(expt);
  return true;
}

bool AfeFan::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_impl->expt);
}

template<> double PRJMODEL_API AfeFan::rdens() const
{
  return to<double>(m_impl->rdens);
}

template<> std::string PRJMODEL_API AfeFan::rdens() const
{
  return m_impl->rdens;
}

bool AfeFan::setRdens(const double rdens)
{
  m_impl->rdens = to_float(rdens);
  return true;
}

bool AfeFan::setRdens(const std::string& rdens)
{
  return assign_if_valid<double>(rdens, m_impl->rdens);
}

template<> double PRJMODEL_API AfeFan::fdf() const
{
  return to<double>(m_impl->fdf);
}

template<> std::string PRJMODEL_API AfeFan::fdf() const
{
  return m_impl->fdf;
}

bool AfeFan::setFdf(const double fdf)
{
  m_impl->fdf = to_float(fdf);
  return true;
}

bool AfeFan::setFdf(const std::string& fdf)
{
  return assign_if_valid<double>(fdf, m_impl->fdf);
}

template<> double PRJMODEL_API AfeFan::sop() const
{
  return to<double>(m_impl->sop);
}

template<> std::string PRJMODEL_API AfeFan::sop() const
{
  return m_impl->sop;
}

bool AfeFan::setSop(const double sop)
{
  m_impl->sop = to_float(sop);
  return true;
}

bool AfeFan::setSop(const std::string& sop)
{
  return assign_if_valid<double>(sop, m_impl->sop);
}

template<> double PRJMODEL_API AfeFan::off() const
{
  return to<double>(m_impl->off);
}

template<> std::string PRJMODEL_API AfeFan::off() const
{
  return m_impl->off;
}

bool AfeFan::setOff(const double off)
{
  m_impl->off = to_float(off);
  return true;
}

bool AfeFan::setOff(const std::string& off)
{
  return assign_if_valid<double>(off, m_impl->off);
}

std::vector<double> AfeFan::fpc() const
{
  std::vector<double> out;
  for (int i = 0; i < 4; i++) {
    out.push_back(to<double>(m_impl->fpc[i]));
  }
  return out;
}

bool AfeFan::setFpc(const std::vector<double>& fpc)
{
  for (int i = 0; i < 4; i++) {
    m_impl->fpc.push_back(to_float(fpc[i]));
  }
  return true;
}

bool AfeFan::setFpc(const std::vector<std::string>& fpc)
{
  if (std::all_of(fpc.begin(), fpc.end(), is_valid<double, std::string>)) {
    m_impl->fpc = fpc;
    return true;
  } else {
    return false;
  }
}

template<> double PRJMODEL_API AfeFan::Sarea() const
{
  return to<double>(m_impl->Sarea);
}

template<> std::string PRJMODEL_API AfeFan::Sarea() const
{
  return m_impl->Sarea;
}

bool AfeFan::setSarea(const double Sarea)
{
  m_impl->Sarea = to_float(Sarea);
  return true;
}

bool AfeFan::setSarea(const std::string& Sarea)
{
  return assign_if_valid<double>(Sarea, m_impl->Sarea);
}

int AfeFan::u_Sa() const
{
  return m_impl->u_Sa;
}

void AfeFan::setU_Sa(const int u_Sa)
{
  m_impl->u_Sa = u_Sa;
}

std::vector<FanDataPoint> AfeFan::data() const
{
  return m_impl->data;
}

void AfeFan::setData(const std::vector<FanDataPoint>& data)
{
  m_impl->data = data;
}

AfeCsf::AfeCsf() :
  m_impl(std::shared_ptr<Impl>(new Impl()))
{}

AfeCsf::AfeCsf(const AfeCsf &other) : m_impl(other.m_impl)
{}

AfeCsf::~AfeCsf()
{}

AfeCsf& AfeCsf::operator=(const AfeCsf &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool AfeCsf::operator==(const AfeCsf &other) const
{
  return m_impl == other.m_impl;
}

bool AfeCsf::operator!=(const AfeCsf &other) const
{
  return m_impl != other.m_impl;
}

AfeCsf::Impl::Impl() : nr(0), icon(0), u_x(0), u_y(0)
{}

AfeCsf::AfeCsf(int nr, int icon, std::string name, std::string desc) : AfeCsf()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

AfeCsf::AfeCsf(int nr, int icon, std::string name, std::string desc, int u_x, int u_y,
  std::vector<XyDataPoint> data) : AfeCsf()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setU_x(u_x);
  setU_y(u_y);
  setData(data);
}

void AfeCsf::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  int npts = input.read<int>();
  setU_x(input.read<int>());
  setU_y(input.read<int>());
  for (int i = 0; i < npts; i++) {
    XyDataPoint object;
    object.read(input);
    m_impl->data.push_back(object);
  }
}

void AfeCsf::readDetails(Reader& input)
{
  int npts = input.read<int>();
  setU_x(input.read<int>());
  setU_y(input.read<int>());
  for (int i = 0; i < npts; i++) {
    XyDataPoint object;
    object.read(input);
    m_impl->data.push_back(object);
  }

}

std::string AfeCsf::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + ' ' + dataType() + ' ' + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += ANY_TO_STR((int)m_impl->data.size()) + ' ' + ANY_TO_STR(m_impl->u_x) + ' ' + ANY_TO_STR(m_impl->u_y) + '\n';
  for (unsigned int i = 0; i < m_impl->data.size(); i++) {
    string += m_impl->data[i].write();
  }
  return string;
}

int AfeCsf::nr() const
{
  return m_impl->nr;
}

void AfeCsf::setNr(const int nr)
{
  m_impl->nr = nr;
}

int AfeCsf::icon() const
{
  return m_impl->icon;
}

void AfeCsf::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string AfeCsf::name() const
{
  return m_impl->name;
}

void AfeCsf::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string AfeCsf::desc() const
{
  return m_impl->desc;
}

void AfeCsf::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

int AfeCsf::u_x() const
{
  return m_impl->u_x;
}

void AfeCsf::setU_x(const int u_x)
{
  m_impl->u_x = u_x;
}

int AfeCsf::u_y() const
{
  return m_impl->u_y;
}

void AfeCsf::setU_y(const int u_y)
{
  m_impl->u_y = u_y;
}

std::vector<XyDataPoint> AfeCsf::data() const
{
  return m_impl->data;
}

void AfeCsf::setData(const std::vector<XyDataPoint>& data)
{
  m_impl->data = data;
}

AfeFsp::AfeFsp() : AfeCsf()
{}

AfeFsp::AfeFsp(int nr,int icon,std::string name,std::string desc) : AfeCsf(nr,icon,name,desc)
{}

AfeFsp::AfeFsp(int nr,int icon,std::string name,std::string desc,int u_x,int u_y,std::vector<XyDataPoint> data)
: AfeCsf(nr,icon,name,desc,u_x,u_y,data)
{}

AfeFsp::~AfeFsp()
{}

AfeQsp::AfeQsp() : AfeCsf()
{}

AfeQsp::AfeQsp(int nr,int icon,std::string name,std::string desc) : AfeCsf(nr,icon,name,desc)
{}

AfeQsp::AfeQsp(int nr,int icon,std::string name,std::string desc,int u_x,int u_y,std::vector<XyDataPoint> data)
: AfeCsf(nr,icon,name,desc,u_x,u_y,data)
{}

AfeQsp::~AfeQsp()
{}

AfePsf::AfePsf() : AfeCsf()
{}

AfePsf::AfePsf(int nr,int icon,std::string name,std::string desc) : AfeCsf(nr,icon,name,desc)
{}

AfePsf::AfePsf(int nr,int icon,std::string name,std::string desc,int u_x,int u_y,std::vector<XyDataPoint> data)
: AfeCsf(nr,icon,name,desc,u_x,u_y,data)
{}

AfePsf::~AfePsf()
{}

AfePsq::AfePsq() : AfeCsf()
{}

AfePsq::AfePsq(int nr,int icon,std::string name,std::string desc) : AfeCsf(nr,icon,name,desc)
{}

AfePsq::AfePsq(int nr,int icon,std::string name,std::string desc,int u_x,int u_y,std::vector<XyDataPoint> data)
: AfeCsf(nr,icon,name,desc,u_x,u_y,data)
{}

AfePsq::~AfePsq()
{}

AfeSup::AfeSup() :
  m_impl(std::shared_ptr<Impl>(new Impl))
{}

AfeSup::AfeSup(const AfeSup &other) : m_impl(other.m_impl)
{}

AfeSup::~AfeSup()
{}

AfeSup& AfeSup::operator=(const AfeSup &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool AfeSup::operator==(const AfeSup &other) const
{
  return m_impl == other.m_impl;
}

bool AfeSup::operator!=(const AfeSup &other) const
{
  return m_impl != other.m_impl;
}

AfeSup::Impl::Impl() : nr(0), icon(0), sched(0), u_H(0)
{}

AfeSup::AfeSup(int nr, int icon, std::string name, std::string desc) : AfeSup()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

AfeSup::AfeSup(int nr, int icon, std::string name, std::string desc, int sched, int u_H,
  std::vector<AirflowSubelementData> subelements) : AfeSup()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setSched(sched);
  setU_H(u_H);
  setSubelements(subelements);
}

void AfeSup::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  int nse = input.read<int>();
  setSched(input.read<int>());
  setU_H(input.read<int>());
  std::vector<AirflowSubelementData> subelements;
  for (int i = 0; i < nse; i++) {
    AirflowSubelementData object;
    object.read(input);
    subelements.push_back(object);
  }
  setSubelements(subelements);
}

std::string AfeSup::write()
{
  std::string string;
  string += ANY_TO_STR(m_impl->nr) + ' ' + ANY_TO_STR(m_impl->icon) + " sup_afe " + m_impl->name + '\n';
  string += m_impl->desc + '\n';
  string += ANY_TO_STR((int)m_impl->subelements.size()) + ' ' + ANY_TO_STR(m_impl->sched) + ' ' + ANY_TO_STR(m_impl->u_H) + '\n';
  for (unsigned int i = 0; i < m_impl->subelements.size(); i++) {
    string += m_impl->subelements[i].write();
  }
  return string;
}

void AfeSup::readDetails(Reader& input)
{
  int nse = input.read<int>();
  setSched(input.read<int>());
  setU_H(input.read<int>());
  std::vector<AirflowSubelementData> subelements;
  for (int i = 0; i < nse; i++) {
    AirflowSubelementData object;
    object.read(input);
    subelements.push_back(object);
  }
  setSubelements(subelements);
}

int AfeSup::nr() const
{
  return m_impl->nr;
}

void AfeSup::setNr(const int nr)
{
  m_impl->nr = nr;
}

int AfeSup::icon() const
{
  return m_impl->icon;
}

void AfeSup::setIcon(const int icon)
{
  m_impl->icon = icon;
}

std::string AfeSup::name() const
{
  return m_impl->name;
}

void AfeSup::setName(const std::string& name)
{
  m_impl->name = name;
}

std::string AfeSup::desc() const
{
  return m_impl->desc;
}

void AfeSup::setDesc(const std::string& desc)
{
  m_impl->desc = desc;
}

int AfeSup::sched() const
{
  return m_impl->sched;
}

void AfeSup::setSched(const int sched)
{
  m_impl->sched = sched;
}

int AfeSup::u_H() const
{
  return m_impl->u_H;
}

void AfeSup::setU_H(const int u_H)
{
  m_impl->u_H = u_H;
}

std::vector<AirflowSubelementData> AfeSup::subelements() const
{
  return m_impl->subelements;
}

void AfeSup::setSubelements(const std::vector<AirflowSubelementData>& subelements)
{
  m_impl->subelements = subelements;
}

} // prjmodel
