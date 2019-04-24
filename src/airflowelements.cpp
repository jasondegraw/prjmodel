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
  m_impl(std::shared_ptr<PlrOrfImpl>(new PlrOrfImpl))
{}

PlrOrf::PlrOrf(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<PlrOrfImpl>(new PlrOrfImpl(nr,icon,name,desc)))
{}

PlrOrf::PlrOrf(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt,double area,
               double dia,double coef,double Re,int u_A,int u_D) :
  m_impl(std::shared_ptr<PlrOrfImpl>(new PlrOrfImpl(nr,icon,name,desc,lam,turb,expt,area,dia,coef,Re,u_A,u_D)))
{}

PlrOrf::PlrOrf(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt,std::string area,
               std::string dia,std::string coef,std::string Re,int u_A,int u_D) :
  m_impl(std::shared_ptr<PlrOrfImpl>(new PlrOrfImpl(nr,icon,name,desc,lam,turb,expt,area,dia,coef,Re,u_A,u_D)))
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

std::string PlrOrf::write()
{
  return m_impl->write();
}

void PlrOrf::read(Reader &input)
{
  m_impl->read(input);
}

void PlrOrf::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int PlrOrf::nr() const
{
  return m_impl->nr();
}

void PlrOrf::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int PlrOrf::icon() const
{
  return m_impl->icon();
}

void PlrOrf::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string PlrOrf::name() const
{
  return m_impl->name();
}

void PlrOrf::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string PlrOrf::desc() const
{
  return m_impl->desc();
}

void PlrOrf::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double PlrOrf::lam() const
{
  return m_impl->lam();
}

bool PlrOrf::setLam(const double lam)
{
  return m_impl->setLam(lam);
}

bool PlrOrf::setLam(const std::string &lam)
{
  return m_impl->setLam(lam);
}

double PlrOrf::turb() const
{
  return m_impl->turb();
}

bool PlrOrf::setTurb(const double turb)
{
  return m_impl->setTurb(turb);
}

bool PlrOrf::setTurb(const std::string &turb)
{
  return m_impl->setTurb(turb);
}

double PlrOrf::expt() const
{
  return m_impl->expt();
}

bool PlrOrf::setExpt(const double expt)
{
  return m_impl->setExpt(expt);
}

bool PlrOrf::setExpt(const std::string &expt)
{
  return m_impl->setExpt(expt);
}

double PlrOrf::area() const
{
  return m_impl->area();
}

bool PlrOrf::setArea(const double area)
{
  return m_impl->setArea(area);
}

bool PlrOrf::setArea(const std::string &area)
{
  return m_impl->setArea(area);
}

double PlrOrf::dia() const
{
  return m_impl->dia();
}

bool PlrOrf::setDia(const double dia)
{
  return m_impl->setDia(dia);
}

bool PlrOrf::setDia(const std::string &dia)
{
  return m_impl->setDia(dia);
}

double PlrOrf::coef() const
{
  return m_impl->coef();
}

bool PlrOrf::setCoef(const double coef)
{
  return m_impl->setCoef(coef);
}

bool PlrOrf::setCoef(const std::string &coef)
{
  return m_impl->setCoef(coef);
}

double PlrOrf::Re() const
{
  return m_impl->Re();
}

bool PlrOrf::setRe(const double Re)
{
  return m_impl->setRe(Re);
}

bool PlrOrf::setRe(const std::string &Re)
{
  return m_impl->setRe(Re);
}

int PlrOrf::u_A() const
{
  return m_impl->u_A();
}

void PlrOrf::setU_A(const int u_A)
{
  m_impl->setU_A(u_A);
}

int PlrOrf::u_D() const
{
  return m_impl->u_D();
}

void PlrOrf::setU_D(const int u_D)
{
  m_impl->setU_D(u_D);
}

PlrOrf::PlrOrfImpl::PlrOrfImpl() : m_nr(0), m_icon(0), m_lam(PRJFLOAT("0.0")), m_turb(PRJFLOAT("0.0")), m_expt(PRJFLOAT("0.0")),
m_area(PRJFLOAT("0.0")), m_dia(PRJFLOAT("0.0")), m_coef(PRJFLOAT("0.0")), m_Re(PRJFLOAT("0.0")), m_u_A(0), m_u_D(0)
{}

PlrOrf::PlrOrfImpl::PlrOrfImpl(int nr, int icon, std::string name, std::string desc) : PlrOrf::PlrOrfImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrOrf::PlrOrfImpl::PlrOrfImpl(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt, double area,
  double dia, double coef, double Re, int u_A, int u_D) : PlrOrf::PlrOrfImpl()
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

PlrOrf::PlrOrfImpl::PlrOrfImpl(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt, std::string area,
  std::string dia, std::string coef, std::string Re, int u_A, int u_D) : PlrOrf::PlrOrfImpl()
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

void PlrOrf::PlrOrfImpl::read(Reader& input)
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

std::string PlrOrf::PlrOrfImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + " plr_orfc " + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_lam) + ' ' + PRJFLOAT_TO_STR(m_turb) + ' ' + PRJFLOAT_TO_STR(m_expt) + ' ' + PRJFLOAT_TO_STR(m_area)
    + ' ' + PRJFLOAT_TO_STR(m_dia) + ' ' + PRJFLOAT_TO_STR(m_coef) + ' ' + PRJFLOAT_TO_STR(m_Re) + ' '
    + ANY_TO_STR(m_u_A) + ' ' + ANY_TO_STR(m_u_D) + '\n';
  return string;
}

void PlrOrf::PlrOrfImpl::readDetails(Reader& input)
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

int PlrOrf::PlrOrfImpl::nr() const
{
  return m_nr;
}

void PlrOrf::PlrOrfImpl::setNr(const int nr)
{
  m_nr = nr;
}

int PlrOrf::PlrOrfImpl::icon() const
{
  return m_icon;
}

void PlrOrf::PlrOrfImpl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string PlrOrf::PlrOrfImpl::name() const
{
  return m_name;
}

void PlrOrf::PlrOrfImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string PlrOrf::PlrOrfImpl::desc() const
{
  return m_desc;
}

void PlrOrf::PlrOrfImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double PlrOrf::PlrOrfImpl::lam() const
{
  return to<double>(m_lam);
}

bool PlrOrf::PlrOrfImpl::setLam(const double lam)
{
  m_lam = to_float(lam);
  return true;
}

bool PlrOrf::PlrOrfImpl::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_lam);
}

double PlrOrf::PlrOrfImpl::turb() const
{
  return to<double>(m_turb);
}

bool PlrOrf::PlrOrfImpl::setTurb(const double turb)
{
  m_turb = to_float(turb);
  return true;
}

bool PlrOrf::PlrOrfImpl::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_turb);
}

double PlrOrf::PlrOrfImpl::expt() const
{
  return to<double>(m_expt);
}

bool PlrOrf::PlrOrfImpl::setExpt(const double expt)
{
  m_expt = to_float(expt);
  return true;
}

bool PlrOrf::PlrOrfImpl::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_expt);
}

double PlrOrf::PlrOrfImpl::area() const
{
  return to<double>(m_area);
}

bool PlrOrf::PlrOrfImpl::setArea(const double area)
{
  m_area = to_float(area);
  return true;
}

bool PlrOrf::PlrOrfImpl::setArea(const std::string& area)
{
  return assign_if_valid<double>(area, m_area);
}

double PlrOrf::PlrOrfImpl::dia() const
{
  return to<double>(m_dia);
}

bool PlrOrf::PlrOrfImpl::setDia(const double dia)
{
  m_dia = to_float(dia);
  return true;
}

bool PlrOrf::PlrOrfImpl::setDia(const std::string& dia)
{
  return assign_if_valid<double>(dia, m_dia);
}

double PlrOrf::PlrOrfImpl::coef() const
{
  return to<double>(m_coef);
}

bool PlrOrf::PlrOrfImpl::setCoef(const double coef)
{
  m_coef = to_float(coef);
  return true;
}

bool PlrOrf::PlrOrfImpl::setCoef(const std::string& coef)
{
  return assign_if_valid<double>(coef, m_coef);
}

double PlrOrf::PlrOrfImpl::Re() const
{
  return to<double>(m_Re);
}

bool PlrOrf::PlrOrfImpl::setRe(const double Re)
{
  m_Re = to_float(Re);
  return true;
}

bool PlrOrf::PlrOrfImpl::setRe(const std::string& Re)
{
  return assign_if_valid<double>(Re, m_Re);
}

int PlrOrf::PlrOrfImpl::u_A() const
{
  return m_u_A;
}

void PlrOrf::PlrOrfImpl::setU_A(const int u_A)
{
  m_u_A = u_A;
}

int PlrOrf::PlrOrfImpl::u_D() const
{
  return m_u_D;
}

void PlrOrf::PlrOrfImpl::setU_D(const int u_D)
{
  m_u_D = u_D;
}

PlrLeak::PlrLeak() :
  m_impl(std::shared_ptr<PlrLeakImpl>(new PlrLeakImpl()))
{}

PlrLeak::PlrLeak(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<PlrLeakImpl>(new PlrLeakImpl(nr,icon,name,desc)))
{}

PlrLeak::PlrLeak(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt,double coef,
                 double pres,double area1,double area2,double area3,int u_A1,int u_A2,int u_A3,int u_dP) :
  m_impl(std::shared_ptr<PlrLeakImpl>(new PlrLeakImpl(nr,icon,name,desc,lam,turb,expt,coef,pres,area1,area2,area3,u_A1,u_A2,u_A3,u_dP)))
{}

PlrLeak::PlrLeak(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt,std::string coef,
                 std::string pres,std::string area1,std::string area2,std::string area3,int u_A1,int u_A2,int u_A3,int u_dP) :
  m_impl(std::shared_ptr<PlrLeakImpl>(new PlrLeakImpl(nr,icon,name,desc,lam,turb,expt,coef,pres,area1,area2,area3,u_A1,u_A2,u_A3,u_dP)))
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

std::string PlrLeak::write()
{
  return m_impl->write(dataType());
}

void PlrLeak::read(Reader &input)
{
  m_impl->read(input);
}

void PlrLeak::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int PlrLeak::nr() const
{
  return m_impl->nr();
}

void PlrLeak::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int PlrLeak::icon() const
{
  return m_impl->icon();
}

void PlrLeak::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string PlrLeak::name() const
{
  return m_impl->name();
}

void PlrLeak::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string PlrLeak::desc() const
{
  return m_impl->desc();
}

void PlrLeak::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double PlrLeak::lam() const
{
  return m_impl->lam();
}

bool PlrLeak::setLam(const double lam)
{
  return m_impl->setLam(lam);
}

bool PlrLeak::setLam(const std::string &lam)
{
  return m_impl->setLam(lam);
}

double PlrLeak::turb() const
{
  return m_impl->turb();
}

bool PlrLeak::setTurb(const double turb)
{
  return m_impl->setTurb(turb);
}

bool PlrLeak::setTurb(const std::string &turb)
{
  return m_impl->setTurb(turb);
}

double PlrLeak::expt() const
{
  return m_impl->expt();
}

bool PlrLeak::setExpt(const double expt)
{
  return m_impl->setExpt(expt);
}

bool PlrLeak::setExpt(const std::string &expt)
{
  return m_impl->setExpt(expt);
}

double PlrLeak::coef() const
{
  return m_impl->coef();
}

bool PlrLeak::setCoef(const double coef)
{
  return m_impl->setCoef(coef);
}

bool PlrLeak::setCoef(const std::string &coef)
{
  return m_impl->setCoef(coef);
}

double PlrLeak::pres() const
{
  return m_impl->pres();
}

bool PlrLeak::setPres(const double pres)
{
  return m_impl->setPres(pres);
}

bool PlrLeak::setPres(const std::string &pres)
{
  return m_impl->setPres(pres);
}

double PlrLeak::area1() const
{
  return m_impl->area1();
}

bool PlrLeak::setArea1(const double area1)
{
  return m_impl->setArea1(area1);
}

bool PlrLeak::setArea1(const std::string &area1)
{
  return m_impl->setArea1(area1);
}

double PlrLeak::area2() const
{
  return m_impl->area2();
}

bool PlrLeak::setArea2(const double area2)
{
  return m_impl->setArea2(area2);
}

bool PlrLeak::setArea2(const std::string &area2)
{
  return m_impl->setArea2(area2);
}

double PlrLeak::area3() const
{
  return m_impl->area3();
}

bool PlrLeak::setArea3(const double area3)
{
  return m_impl->setArea3(area3);
}

bool PlrLeak::setArea3(const std::string &area3)
{
  return m_impl->setArea3(area3);
}

int PlrLeak::u_A1() const
{
  return m_impl->u_A1();
}

void PlrLeak::setU_A1(const int u_A1)
{
  m_impl->setU_A1(u_A1);
}

int PlrLeak::u_A2() const
{
  return m_impl->u_A2();
}

void PlrLeak::setU_A2(const int u_A2)
{
  m_impl->setU_A2(u_A2);
}

int PlrLeak::u_A3() const
{
  return m_impl->u_A3();
}

void PlrLeak::setU_A3(const int u_A3)
{
  m_impl->setU_A3(u_A3);
}

int PlrLeak::u_dP() const
{
  return m_impl->u_dP();
}

void PlrLeak::setU_dP(const int u_dP)
{
  m_impl->setU_dP(u_dP);
}

PlrLeak::PlrLeakImpl::PlrLeakImpl() : m_nr(0), m_icon(0), m_lam(PRJFLOAT("0.0")), m_turb(PRJFLOAT("0.0")), m_expt(PRJFLOAT("0.0")), m_coef(PRJFLOAT("0.0")),
m_pres(PRJFLOAT("0.0")), m_area1(PRJFLOAT("0.0")), m_area2(PRJFLOAT("0.0")), m_area3(PRJFLOAT("0.0")), m_u_A1(0), m_u_A2(0), m_u_A3(0), m_u_dP(0)
{}

PlrLeak::PlrLeakImpl::PlrLeakImpl(int nr, int icon, std::string name, std::string desc) : PlrLeak::PlrLeakImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrLeak::PlrLeakImpl::PlrLeakImpl(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt,
  double coef, double pres, double area1, double area2, double area3, int u_A1, int u_A2,
  int u_A3, int u_dP) : PlrLeak::PlrLeakImpl()
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

PlrLeak::PlrLeakImpl::PlrLeakImpl(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt,
  std::string coef, std::string pres, std::string area1, std::string area2, std::string area3, int u_A1, int u_A2,
  int u_A3, int u_dP) : PlrLeak::PlrLeakImpl()
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

void PlrLeak::PlrLeakImpl::read(Reader& input)
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

std::string PlrLeak::PlrLeakImpl::write(std::string datatype)
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + ' ' + datatype + ' ' + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_lam) + ' ' + PRJFLOAT_TO_STR(m_turb) + ' ' + PRJFLOAT_TO_STR(m_expt) + ' '
    + PRJFLOAT_TO_STR(m_coef) + ' ' + PRJFLOAT_TO_STR(m_pres) + ' ' + PRJFLOAT_TO_STR(m_area1) + ' '
    + PRJFLOAT_TO_STR(m_area2) + ' ' + PRJFLOAT_TO_STR(m_area3) + ' ' + ANY_TO_STR(m_u_A1) + ' '
    + ANY_TO_STR(m_u_A2) + ' ' + ANY_TO_STR(m_u_A3) + ' ' + ANY_TO_STR(m_u_dP) + '\n';
  return string;
}

void PlrLeak::PlrLeakImpl::readDetails(Reader& input)
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

int PlrLeak::PlrLeakImpl::nr() const
{
  return m_nr;
}

void PlrLeak::PlrLeakImpl::setNr(const int nr)
{
  m_nr = nr;
}

int PlrLeak::PlrLeakImpl::icon() const
{
  return m_icon;
}

void PlrLeak::PlrLeakImpl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string PlrLeak::PlrLeakImpl::name() const
{
  return m_name;
}

void PlrLeak::PlrLeakImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string PlrLeak::PlrLeakImpl::desc() const
{
  return m_desc;
}

void PlrLeak::PlrLeakImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double PlrLeak::PlrLeakImpl::lam() const
{
  return to<double>(m_lam);
}

bool PlrLeak::PlrLeakImpl::setLam(const double lam)
{
  m_lam = to_float(lam);
  return true;
}

bool PlrLeak::PlrLeakImpl::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_lam);
}

double PlrLeak::PlrLeakImpl::turb() const
{
  return to<double>(m_turb);
}

bool PlrLeak::PlrLeakImpl::setTurb(const double turb)
{
  m_turb = to_float(turb);
  return true;
}

bool PlrLeak::PlrLeakImpl::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_turb);
}

double PlrLeak::PlrLeakImpl::expt() const
{
  return to<double>(m_expt);
}

bool PlrLeak::PlrLeakImpl::setExpt(const double expt)
{
  m_expt = to_float(expt);
  return true;
}

bool PlrLeak::PlrLeakImpl::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_expt);
}

double PlrLeak::PlrLeakImpl::coef() const
{
  return to<double>(m_coef);
}

bool PlrLeak::PlrLeakImpl::setCoef(const double coef)
{
  m_coef = to_float(coef);
  return true;
}

bool PlrLeak::PlrLeakImpl::setCoef(const std::string& coef)
{
  return assign_if_valid<double>(coef, m_coef);
}

double PlrLeak::PlrLeakImpl::pres() const
{
  return to<double>(m_pres);
}

bool PlrLeak::PlrLeakImpl::setPres(const double pres)
{
  m_pres = to_float(pres);
  return true;
}

bool PlrLeak::PlrLeakImpl::setPres(const std::string& pres)
{
  return assign_if_valid<double>(pres, m_pres);
}

double PlrLeak::PlrLeakImpl::area1() const
{
  return to<double>(m_area1);
}

bool PlrLeak::PlrLeakImpl::setArea1(const double area1)
{
  m_area1 = to_float(area1);
  return true;
}

bool PlrLeak::PlrLeakImpl::setArea1(const std::string& area1)
{
  return assign_if_valid<double>(area1, m_area1);
}

double PlrLeak::PlrLeakImpl::area2() const
{
  return to<double>(m_area2);
}

bool PlrLeak::PlrLeakImpl::setArea2(const double area2)
{
  m_area2 = to_float(area2);
  return true;
}

bool PlrLeak::PlrLeakImpl::setArea2(const std::string& area2)
{
  return assign_if_valid<double>(area2, m_area2);
}

double PlrLeak::PlrLeakImpl::area3() const
{
  return to<double>(m_area3);
}

bool PlrLeak::PlrLeakImpl::setArea3(const double area3)
{
  m_area3 = to_float(area3);
  return true;
}

bool PlrLeak::PlrLeakImpl::setArea3(const std::string& area3)
{
  return assign_if_valid<double>(area3, m_area3);
}

int PlrLeak::PlrLeakImpl::u_A1() const
{
  return m_u_A1;
}

void PlrLeak::PlrLeakImpl::setU_A1(const int u_A1)
{
  m_u_A1 = u_A1;
}

int PlrLeak::PlrLeakImpl::u_A2() const
{
  return m_u_A2;
}

void PlrLeak::PlrLeakImpl::setU_A2(const int u_A2)
{
  m_u_A2 = u_A2;
}

int PlrLeak::PlrLeakImpl::u_A3() const
{
  return m_u_A3;
}

void PlrLeak::PlrLeakImpl::setU_A3(const int u_A3)
{
  m_u_A3 = u_A3;
}

int PlrLeak::PlrLeakImpl::u_dP() const
{
  return m_u_dP;
}

void PlrLeak::PlrLeakImpl::setU_dP(const int u_dP)
{
  m_u_dP = u_dP;
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
  m_impl(std::shared_ptr<PlrConnImpl>(new PlrConnImpl))
{}

PlrConn::PlrConn(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<PlrConnImpl>(new PlrConnImpl(nr,icon,name,desc)))
{}

PlrConn::PlrConn(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt,double area,
                 double coef,int u_A) :
  m_impl(std::shared_ptr<PlrConnImpl>(new PlrConnImpl(nr,icon,name,desc,lam,turb,expt,area,coef,u_A)))
{}

PlrConn::PlrConn(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt,std::string area,
                 std::string coef,int u_A) :
  m_impl(std::shared_ptr<PlrConnImpl>(new PlrConnImpl(nr,icon,name,desc,lam,turb,expt,area,coef,u_A)))
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

std::string PlrConn::write()
{
  return m_impl->write();
}

void PlrConn::read(Reader &input)
{
  m_impl->read(input);
}

void PlrConn::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int PlrConn::nr() const
{
  return m_impl->nr();
}

void PlrConn::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int PlrConn::icon() const
{
  return m_impl->icon();
}

void PlrConn::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string PlrConn::name() const
{
  return m_impl->name();
}

void PlrConn::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string PlrConn::desc() const
{
  return m_impl->desc();
}

void PlrConn::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double PlrConn::lam() const
{
  return m_impl->lam();
}

bool PlrConn::setLam(const double lam)
{
  return m_impl->setLam(lam);
}

bool PlrConn::setLam(const std::string &lam)
{
  return m_impl->setLam(lam);
}

double PlrConn::turb() const
{
  return m_impl->turb();
}

bool PlrConn::setTurb(const double turb)
{
  return m_impl->setTurb(turb);
}

bool PlrConn::setTurb(const std::string &turb)
{
  return m_impl->setTurb(turb);
}

double PlrConn::expt() const
{
  return m_impl->expt();
}

bool PlrConn::setExpt(const double expt)
{
  return m_impl->setExpt(expt);
}

bool PlrConn::setExpt(const std::string &expt)
{
  return m_impl->setExpt(expt);
}

double PlrConn::area() const
{
  return m_impl->area();
}

bool PlrConn::setArea(const double area)
{
  return m_impl->setArea(area);
}

bool PlrConn::setArea(const std::string &area)
{
  return m_impl->setArea(area);
}

double PlrConn::coef() const
{
  return m_impl->coef();
}

bool PlrConn::setCoef(const double coef)
{
  return m_impl->setCoef(coef);
}

bool PlrConn::setCoef(const std::string &coef)
{
  return m_impl->setCoef(coef);
}

int PlrConn::u_A() const
{
  return m_impl->u_A();
}

void PlrConn::setU_A(const int u_A)
{
  m_impl->setU_A(u_A);
}

PlrConn::PlrConnImpl::PlrConnImpl() : m_nr(0), m_icon(0), m_lam(PRJFLOAT("0.0")), m_turb(PRJFLOAT("0.0")), m_expt(PRJFLOAT("0.0")), m_coef(PRJFLOAT("0.0")),
m_area(PRJFLOAT("0.0")), m_u_A(0)
{}

PlrConn::PlrConnImpl::PlrConnImpl(int nr, int icon, std::string name, std::string desc) : PlrConn::PlrConnImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrConn::PlrConnImpl::PlrConnImpl(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt,
  double area, double coef, int u_A) : PlrConn::PlrConnImpl()
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

PlrConn::PlrConnImpl::PlrConnImpl(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt,
  std::string area, std::string coef, int u_A) : PlrConn::PlrConnImpl()
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

void PlrConn::PlrConnImpl::read(Reader& input)
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

std::string PlrConn::PlrConnImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + " plr_conn " + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_lam) + ' ' + PRJFLOAT_TO_STR(m_turb) + ' ' + PRJFLOAT_TO_STR(m_expt) + ' ' + PRJFLOAT_TO_STR(m_area)
    + ' ' + PRJFLOAT_TO_STR(m_coef) + ' ' + ANY_TO_STR(m_u_A) + '\n';
  return string;
}

void PlrConn::PlrConnImpl::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setArea(input.readNumber<std::string>());
  setCoef(input.readNumber<std::string>());
  setU_A(input.read<int>());
}

int PlrConn::PlrConnImpl::nr() const
{
  return m_nr;
}

void PlrConn::PlrConnImpl::setNr(const int nr)
{
  m_nr = nr;
}

int PlrConn::PlrConnImpl::icon() const
{
  return m_icon;
}

void PlrConn::PlrConnImpl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string PlrConn::PlrConnImpl::name() const
{
  return m_name;
}

void PlrConn::PlrConnImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string PlrConn::PlrConnImpl::desc() const
{
  return m_desc;
}

void PlrConn::PlrConnImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double PlrConn::PlrConnImpl::lam() const
{
  return to<double>(m_lam);
}

bool PlrConn::PlrConnImpl::setLam(const double lam)
{
  m_lam = to_float(lam);
  return true;
}

bool PlrConn::PlrConnImpl::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_lam);
}

double PlrConn::PlrConnImpl::turb() const
{
  return to<double>(m_turb);
}

bool PlrConn::PlrConnImpl::setTurb(const double turb)
{
  m_turb = to_float(turb);
  return true;
}

bool PlrConn::PlrConnImpl::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_turb);
}

double PlrConn::PlrConnImpl::expt() const
{
  return to<double>(m_expt);
}

bool PlrConn::PlrConnImpl::setExpt(const double expt)
{
  m_expt = to_float(expt);
  return true;
}

bool PlrConn::PlrConnImpl::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_expt);
}

double PlrConn::PlrConnImpl::area() const
{
  return to<double>(m_area);
}

bool PlrConn::PlrConnImpl::setArea(const double area)
{
  m_area = to_float(area);
  return true;
}

bool PlrConn::PlrConnImpl::setArea(const std::string& area)
{
  return assign_if_valid<double>(area, m_area);
}

double PlrConn::PlrConnImpl::coef() const
{
  return to<double>(m_coef);
}

bool PlrConn::PlrConnImpl::setCoef(const double coef)
{
  m_coef = to_float(coef);
  return true;
}

bool PlrConn::PlrConnImpl::setCoef(const std::string& coef)
{
  return assign_if_valid<double>(coef, m_coef);
}

int PlrConn::PlrConnImpl::u_A() const
{
  return m_u_A;
}

void PlrConn::PlrConnImpl::setU_A(const int u_A)
{
  m_u_A = u_A;
}

PlrGeneral::PlrGeneral() :
  m_impl(std::shared_ptr<PlrGeneralImpl>(new PlrGeneralImpl))
{}

PlrGeneral::PlrGeneral(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<PlrGeneralImpl>(new PlrGeneralImpl(nr,icon,name,desc)))
{}

PlrGeneral::PlrGeneral(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt) :
  m_impl(std::shared_ptr<PlrGeneralImpl>(new PlrGeneralImpl(nr,icon,name,desc,lam,turb,expt)))
{}

PlrGeneral::PlrGeneral(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt) :
  m_impl(std::shared_ptr<PlrGeneralImpl>(new PlrGeneralImpl(nr,icon,name,desc,lam,turb,expt)))
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

std::string PlrGeneral::write()
{
  return m_impl->write(dataType());
}

void PlrGeneral::read(Reader &input)
{
  m_impl->read(input);
}

void PlrGeneral::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int PlrGeneral::nr() const
{
  return m_impl->nr();
}

void PlrGeneral::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int PlrGeneral::icon() const
{
  return m_impl->icon();
}

void PlrGeneral::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string PlrGeneral::name() const
{
  return m_impl->name();
}

void PlrGeneral::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string PlrGeneral::desc() const
{
  return m_impl->desc();
}

void PlrGeneral::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double PlrGeneral::lam() const
{
  return m_impl->lam();
}

bool PlrGeneral::setLam(const double lam)
{
  return m_impl->setLam(lam);
}

bool PlrGeneral::setLam(const std::string &lam)
{
  return m_impl->setLam(lam);
}

double PlrGeneral::turb() const
{
  return m_impl->turb();
}

bool PlrGeneral::setTurb(const double turb)
{
  return m_impl->setTurb(turb);
}

bool PlrGeneral::setTurb(const std::string &turb)
{
  return m_impl->setTurb(turb);
}

double PlrGeneral::expt() const
{
  return m_impl->expt();
}

bool PlrGeneral::setExpt(const double expt)
{
  return m_impl->setExpt(expt);
}

bool PlrGeneral::setExpt(const std::string &expt)
{
  return m_impl->setExpt(expt);
}

PlrGeneral::PlrGeneralImpl::PlrGeneralImpl() : m_nr(0), m_icon(0), m_lam(PRJFLOAT("0.0")), m_turb(PRJFLOAT("0.0")), m_expt(PRJFLOAT("0.0"))
{}

PlrGeneral::PlrGeneralImpl::PlrGeneralImpl(int nr, int icon, std::string name, std::string desc) : PlrGeneral::PlrGeneralImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrGeneral::PlrGeneralImpl::PlrGeneralImpl(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt) : PlrGeneral::PlrGeneralImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
}

PlrGeneral::PlrGeneralImpl::PlrGeneralImpl(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt) : PlrGeneral::PlrGeneralImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setLam(lam);
  setTurb(turb);
  setExpt(expt);
}

void PlrGeneral::PlrGeneralImpl::read(Reader& input)
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

std::string PlrGeneral::PlrGeneralImpl::write(std::string dataType)
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + ' ' + dataType + ' ' + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_lam) + ' ' + PRJFLOAT_TO_STR(m_turb) + ' ' + PRJFLOAT_TO_STR(m_expt) + '\n';
  return string;
}

void PlrGeneral::PlrGeneralImpl::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
}

int PlrGeneral::PlrGeneralImpl::nr() const
{
  return m_nr;
}

void PlrGeneral::PlrGeneralImpl::setNr(const int nr)
{
  m_nr = nr;
}

int PlrGeneral::PlrGeneralImpl::icon() const
{
  return m_icon;
}

void PlrGeneral::PlrGeneralImpl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string PlrGeneral::PlrGeneralImpl::name() const
{
  return m_name;
}

void PlrGeneral::PlrGeneralImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string PlrGeneral::PlrGeneralImpl::desc() const
{
  return m_desc;
}

void PlrGeneral::PlrGeneralImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double PlrGeneral::PlrGeneralImpl::lam() const
{
  return to<double>(m_lam);
}

bool PlrGeneral::PlrGeneralImpl::setLam(const double lam)
{
  m_lam = to_float(lam);
  return true;
}

bool PlrGeneral::PlrGeneralImpl::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_lam);
}

double PlrGeneral::PlrGeneralImpl::turb() const
{
  return to<double>(m_turb);
}

bool PlrGeneral::PlrGeneralImpl::setTurb(const double turb)
{
  m_turb = to_float(turb);
  return true;
}

bool PlrGeneral::PlrGeneralImpl::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_turb);
}

double PlrGeneral::PlrGeneralImpl::expt() const
{
  return to<double>(m_expt);
}

bool PlrGeneral::PlrGeneralImpl::setExpt(const double expt)
{
  m_expt = to_float(expt);
  return true;
}

bool PlrGeneral::PlrGeneralImpl::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_expt);
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

PlrTest1::Impl::Impl() : m_nr(0), m_icon(0), m_lam(PRJFLOAT("0.0")), m_turb(PRJFLOAT("0.0")), m_expt(PRJFLOAT("0.0")), m_dP(PRJFLOAT("0.0")),
m_Flow(PRJFLOAT("0.0")), m_u_P(0), m_u_F(0)
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
  string += ANY_TO_STR(m_impl->m_nr) + ' ' + ANY_TO_STR(m_impl->m_icon) + " plr_test1 " + m_impl->m_name + '\n';
  string += m_impl->m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_impl->m_lam) + ' ' + PRJFLOAT_TO_STR(m_impl->m_turb) + ' ' + PRJFLOAT_TO_STR(m_impl->m_expt) + ' '
    + PRJFLOAT_TO_STR(m_impl->m_dP) + ' ' + PRJFLOAT_TO_STR(m_impl->m_Flow) + ' ' + ANY_TO_STR(m_impl->m_u_P) + ' '
    + ANY_TO_STR(m_impl->m_u_F) + '\n';
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
  return m_impl->m_nr;
}

void PlrTest1::setNr(const int nr)
{
  m_impl->m_nr = nr;
}

int PlrTest1::icon() const
{
  return m_impl->m_icon;
}

void PlrTest1::setIcon(const int icon)
{
  m_impl->m_icon = icon;
}

std::string PlrTest1::name() const
{
  return m_impl->m_name;
}

void PlrTest1::setName(const std::string& name)
{
  m_impl->m_name = name;
}

std::string PlrTest1::desc() const
{
  return m_impl->m_desc;
}

void PlrTest1::setDesc(const std::string& desc)
{
  m_impl->m_desc = desc;
}

template <> double PRJMODEL_API PlrTest1::lam() const
{
  return to<double>(m_impl->m_lam);
}

template <> std::string PRJMODEL_API PlrTest1::lam() const
{
  return PRJFLOAT_TO_STR(m_impl->m_lam);
}

bool PlrTest1::setLam(const double lam)
{
  m_impl->m_lam = to_float(lam);
  return true;
}

bool PlrTest1::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_impl->m_lam);
}

template <> double PRJMODEL_API PlrTest1::turb() const
{
  return to<double>(m_impl->m_turb);
}

template <> std::string PRJMODEL_API PlrTest1::turb() const
{
  return PRJFLOAT_TO_STR(m_impl->m_turb);
}

bool PlrTest1::setTurb(const double turb)
{
  m_impl->m_turb = to_float(turb);
  return true;
}

bool PlrTest1::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_impl->m_turb);
}

template <> double PRJMODEL_API PlrTest1::expt() const
{
  return to<double>(m_impl->m_expt);
}

template <> std::string PRJMODEL_API PlrTest1::expt() const
{
  return PRJFLOAT_TO_STR(m_impl->m_expt);
}

bool PlrTest1::setExpt(const double expt)
{
  m_impl->m_expt = to_float(expt);
  return true;
}

bool PlrTest1::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_impl->m_expt);
}

template <> double PRJMODEL_API PlrTest1::dP() const
{
  return to<double>(m_impl->m_dP);
}

template <> std::string PRJMODEL_API PlrTest1::dP() const
{
  return PRJFLOAT_TO_STR(m_impl->m_dP);
}

bool PlrTest1::setDP(const double dP)
{
  m_impl->m_dP = to_float(dP);
  return true;
}

bool PlrTest1::setDP(const std::string& dP)
{
  return assign_if_valid<double>(dP, m_impl->m_dP);
}

template <> double PRJMODEL_API PlrTest1::Flow() const
{
  return to<double>(m_impl->m_Flow);
}

template <> std::string PRJMODEL_API PlrTest1::Flow() const
{
  return PRJFLOAT_TO_STR(m_impl->m_Flow);
}

bool PlrTest1::setFlow(const double Flow)
{
  m_impl->m_Flow = to_float(Flow);
  return true;
}

bool PlrTest1::setFlow(const std::string& Flow)
{
  return assign_if_valid<double>(Flow, m_impl->m_Flow);
}

int PlrTest1::u_P() const
{
  return m_impl->m_u_P;
}

void PlrTest1::setU_P(const int u_P)
{
  m_impl->m_u_P = u_P;
}

int PlrTest1::u_F() const
{
  return m_impl->m_u_F;
}

void PlrTest1::setU_F(const int u_F)
{
  m_impl->m_u_F = u_F;
}

PlrTest2::PlrTest2() :
  m_impl(std::shared_ptr<PlrTest2Impl>(new PlrTest2Impl))
{}

PlrTest2::PlrTest2(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<PlrTest2Impl>(new PlrTest2Impl(nr,icon,name,desc)))
{}

PlrTest2::PlrTest2(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt,double dP1,
                   double F1,double dP2,double F2,int u_P1,int u_F1,int u_P2,int u_F2) :
  m_impl(std::shared_ptr<PlrTest2Impl>(new PlrTest2Impl(nr,icon,name,desc,lam,turb,expt,dP1,F1,dP2,F2,u_P1,u_F1,u_P2,u_F2)))
{}

PlrTest2::PlrTest2(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt,std::string dP1,
                   std::string F1,std::string dP2,std::string F2,int u_P1,int u_F1,int u_P2,int u_F2) :
  m_impl(std::shared_ptr<PlrTest2Impl>(new PlrTest2Impl(nr,icon,name,desc,lam,turb,expt,dP1,F1,dP2,F2,u_P1,u_F1,u_P2,u_F2)))
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

std::string PlrTest2::write()
{
  return m_impl->write();
}

void PlrTest2::read(Reader &input)
{
  m_impl->read(input);
}

void PlrTest2::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int PlrTest2::nr() const
{
  return m_impl->nr();
}

void PlrTest2::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int PlrTest2::icon() const
{
  return m_impl->icon();
}

void PlrTest2::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string PlrTest2::name() const
{
  return m_impl->name();
}

void PlrTest2::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string PlrTest2::desc() const
{
  return m_impl->desc();
}

void PlrTest2::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double PlrTest2::lam() const
{
  return m_impl->lam();
}

bool PlrTest2::setLam(const double lam)
{
  return m_impl->setLam(lam);
}

bool PlrTest2::setLam(const std::string &lam)
{
  return m_impl->setLam(lam);
}

double PlrTest2::turb() const
{
  return m_impl->turb();
}

bool PlrTest2::setTurb(const double turb)
{
  return m_impl->setTurb(turb);
}

bool PlrTest2::setTurb(const std::string &turb)
{
  return m_impl->setTurb(turb);
}

double PlrTest2::expt() const
{
  return m_impl->expt();
}

bool PlrTest2::setExpt(const double expt)
{
  return m_impl->setExpt(expt);
}

bool PlrTest2::setExpt(const std::string &expt)
{
  return m_impl->setExpt(expt);
}

double PlrTest2::dP1() const
{
  return m_impl->dP1();
}

bool PlrTest2::setDP1(const double dP1)
{
  return m_impl->setDP1(dP1);
}

bool PlrTest2::setDP1(const std::string &dP1)
{
  return m_impl->setDP1(dP1);
}

double PlrTest2::F1() const
{
  return m_impl->F1();
}

bool PlrTest2::setF1(const double F1)
{
  return m_impl->setF1(F1);
}

bool PlrTest2::setF1(const std::string &F1)
{
  return m_impl->setF1(F1);
}

double PlrTest2::dP2() const
{
  return m_impl->dP2();
}

bool PlrTest2::setDP2(const double dP2)
{
  return m_impl->setDP2(dP2);
}

bool PlrTest2::setDP2(const std::string &dP2)
{
  return m_impl->setDP2(dP2);
}

double PlrTest2::F2() const
{
  return m_impl->F2();
}

bool PlrTest2::setF2(const double F2)
{
  return m_impl->setF2(F2);
}

bool PlrTest2::setF2(const std::string &F2)
{
  return m_impl->setF2(F2);
}

int PlrTest2::u_P1() const
{
  return m_impl->u_P1();
}

void PlrTest2::setU_P1(const int u_P1)
{
  m_impl->setU_P1(u_P1);
}

int PlrTest2::u_F1() const
{
  return m_impl->u_F1();
}

void PlrTest2::setU_F1(const int u_F1)
{
  m_impl->setU_F1(u_F1);
}

int PlrTest2::u_P2() const
{
  return m_impl->u_P2();
}

void PlrTest2::setU_P2(const int u_P2)
{
  m_impl->setU_P2(u_P2);
}

int PlrTest2::u_F2() const
{
  return m_impl->u_F2();
}

void PlrTest2::setU_F2(const int u_F2)
{
  m_impl->setU_F2(u_F2);
}

PlrTest2::PlrTest2Impl::PlrTest2Impl() : m_nr(0), m_icon(0), m_lam(PRJFLOAT("0.0")), m_turb(PRJFLOAT("0.0")), m_expt(PRJFLOAT("0.0")), m_dP1(PRJFLOAT("0.0")),
m_F1(PRJFLOAT("0.0")), m_dP2(PRJFLOAT("0.0")), m_F2(PRJFLOAT("0.0")), m_u_P1(0), m_u_F1(0), m_u_P2(0), m_u_F2(0)
{}

PlrTest2::PlrTest2Impl::PlrTest2Impl(int nr, int icon, std::string name, std::string desc) : PlrTest2::PlrTest2Impl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrTest2::PlrTest2Impl::PlrTest2Impl(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt,
  double dP1, double F1, double dP2, double F2, int u_P1, int u_F1, int u_P2, int u_F2) : PlrTest2::PlrTest2Impl()
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

PlrTest2::PlrTest2Impl::PlrTest2Impl(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt,
  std::string dP1, std::string F1, std::string dP2, std::string F2, int u_P1, int u_F1, int u_P2, int u_F2) : PlrTest2::PlrTest2Impl()
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

void PlrTest2::PlrTest2Impl::read(Reader& input)
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

std::string PlrTest2::PlrTest2Impl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + " plr_test2 " + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_lam) + ' ' + PRJFLOAT_TO_STR(m_turb) + ' ' + PRJFLOAT_TO_STR(m_expt) + ' ' + PRJFLOAT_TO_STR(m_dP1)
    + ' ' + PRJFLOAT_TO_STR(m_F1) + ' ' + PRJFLOAT_TO_STR(m_dP2) + ' ' + PRJFLOAT_TO_STR(m_F2) + ' '
    + ANY_TO_STR(m_u_P1) + ' ' + ANY_TO_STR(m_u_F1) + ' ' + ANY_TO_STR(m_u_P2) + ' ' + ANY_TO_STR(m_u_F2)
    + '\n';
  return string;
}

void PlrTest2::PlrTest2Impl::readDetails(Reader& input)
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

int PlrTest2::PlrTest2Impl::nr() const
{
  return m_nr;
}

void PlrTest2::PlrTest2Impl::setNr(const int nr)
{
  m_nr = nr;
}

int PlrTest2::PlrTest2Impl::icon() const
{
  return m_icon;
}

void PlrTest2::PlrTest2Impl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string PlrTest2::PlrTest2Impl::name() const
{
  return m_name;
}

void PlrTest2::PlrTest2Impl::setName(const std::string& name)
{
  m_name = name;
}

std::string PlrTest2::PlrTest2Impl::desc() const
{
  return m_desc;
}

void PlrTest2::PlrTest2Impl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double PlrTest2::PlrTest2Impl::lam() const
{
  return to<double>(m_lam);
}

bool PlrTest2::PlrTest2Impl::setLam(const double lam)
{
  m_lam = to_float(lam);
  return true;
}

bool PlrTest2::PlrTest2Impl::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_lam);
}

double PlrTest2::PlrTest2Impl::turb() const
{
  return to<double>(m_turb);
}

bool PlrTest2::PlrTest2Impl::setTurb(const double turb)
{
  m_turb = to_float(turb);
  return true;
}

bool PlrTest2::PlrTest2Impl::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_turb);
}

double PlrTest2::PlrTest2Impl::expt() const
{
  return to<double>(m_expt);
}

bool PlrTest2::PlrTest2Impl::setExpt(const double expt)
{
  m_expt = to_float(expt);
  return true;
}

bool PlrTest2::PlrTest2Impl::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_expt);
}

double PlrTest2::PlrTest2Impl::dP1() const
{
  return to<double>(m_dP1);
}

bool PlrTest2::PlrTest2Impl::setDP1(const double dP1)
{
  m_dP1 = to_float(dP1);
  return true;
}

bool PlrTest2::PlrTest2Impl::setDP1(const std::string& dP1)
{
  return assign_if_valid<double>(dP1, m_dP1);
}

double PlrTest2::PlrTest2Impl::F1() const
{
  return to<double>(m_F1);
}

bool PlrTest2::PlrTest2Impl::setF1(const double F1)
{
  m_F1 = to_float(F1);
  return true;
}

bool PlrTest2::PlrTest2Impl::setF1(const std::string& F1)
{
  return assign_if_valid<double>(F1, m_F1);
}

double PlrTest2::PlrTest2Impl::dP2() const
{
  return to<double>(m_dP2);
}

bool PlrTest2::PlrTest2Impl::setDP2(const double dP2)
{
  m_dP2 = to_float(dP2);
  return true;
}

bool PlrTest2::PlrTest2Impl::setDP2(const std::string& dP2)
{
  return assign_if_valid<double>(dP2, m_dP2);
}

double PlrTest2::PlrTest2Impl::F2() const
{
  return to<double>(m_F2);
}

bool PlrTest2::PlrTest2Impl::setF2(const double F2)
{
  m_F2 = to_float(F2);
  return true;
}

bool PlrTest2::PlrTest2Impl::setF2(const std::string& F2)
{
  return assign_if_valid<double>(F2, m_F2);
}

int PlrTest2::PlrTest2Impl::u_P1() const
{
  return m_u_P1;
}

void PlrTest2::PlrTest2Impl::setU_P1(const int u_P1)
{
  m_u_P1 = u_P1;
}

int PlrTest2::PlrTest2Impl::u_F1() const
{
  return m_u_F1;
}

void PlrTest2::PlrTest2Impl::setU_F1(const int u_F1)
{
  m_u_F1 = u_F1;
}

int PlrTest2::PlrTest2Impl::u_P2() const
{
  return m_u_P2;
}

void PlrTest2::PlrTest2Impl::setU_P2(const int u_P2)
{
  m_u_P2 = u_P2;
}

int PlrTest2::PlrTest2Impl::u_F2() const
{
  return m_u_F2;
}

void PlrTest2::PlrTest2Impl::setU_F2(const int u_F2)
{
  m_u_F2 = u_F2;
}


PlrCrack::PlrCrack() :
  m_impl(std::shared_ptr<PlrCrackImpl>(new PlrCrackImpl))
{}

PlrCrack::PlrCrack(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<PlrCrackImpl>(new PlrCrackImpl(nr,icon,name,desc)))
{}

PlrCrack::PlrCrack(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt,double length,
                   double width,int u_L,int u_W) :
  m_impl(std::shared_ptr<PlrCrackImpl>(new PlrCrackImpl(nr,icon,name,desc,lam,turb,expt,length,width,u_L,u_W)))
{}

PlrCrack::PlrCrack(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt,std::string length,
                   std::string width,int u_L,int u_W) :
  m_impl(std::shared_ptr<PlrCrackImpl>(new PlrCrackImpl(nr,icon,name,desc,lam,turb,expt,length,width,u_L,u_W)))
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

std::string PlrCrack::write()
{
  return m_impl->write();
}

void PlrCrack::read(Reader &input)
{
  m_impl->read(input);
}

void PlrCrack::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int PlrCrack::nr() const
{
  return m_impl->nr();
}

void PlrCrack::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int PlrCrack::icon() const
{
  return m_impl->icon();
}

void PlrCrack::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string PlrCrack::name() const
{
  return m_impl->name();
}

void PlrCrack::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string PlrCrack::desc() const
{
  return m_impl->desc();
}

void PlrCrack::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double PlrCrack::lam() const
{
  return m_impl->lam();
}

bool PlrCrack::setLam(const double lam)
{
  return m_impl->setLam(lam);
}

bool PlrCrack::setLam(const std::string &lam)
{
  return m_impl->setLam(lam);
}

double PlrCrack::turb() const
{
  return m_impl->turb();
}

bool PlrCrack::setTurb(const double turb)
{
  return m_impl->setTurb(turb);
}

bool PlrCrack::setTurb(const std::string &turb)
{
  return m_impl->setTurb(turb);
}

double PlrCrack::expt() const
{
  return m_impl->expt();
}

bool PlrCrack::setExpt(const double expt)
{
  return m_impl->setExpt(expt);
}

bool PlrCrack::setExpt(const std::string &expt)
{
  return m_impl->setExpt(expt);
}

double PlrCrack::length() const
{
  return m_impl->length();
}

bool PlrCrack::setLength(const double length)
{
  return m_impl->setLength(length);
}

bool PlrCrack::setLength(const std::string &length)
{
  return m_impl->setLength(length);
}

double PlrCrack::width() const
{
  return m_impl->width();
}

bool PlrCrack::setWidth(const double width)
{
  return m_impl->setWidth(width);
}

bool PlrCrack::setWidth(const std::string &width)
{
  return m_impl->setWidth(width);
}

int PlrCrack::u_L() const
{
  return m_impl->u_L();
}

void PlrCrack::setU_L(const int u_L)
{
  m_impl->setU_L(u_L);
}

int PlrCrack::u_W() const
{
  return m_impl->u_W();
}

void PlrCrack::setU_W(const int u_W)
{
  m_impl->setU_W(u_W);
}

PlrCrack::PlrCrackImpl::PlrCrackImpl() : m_nr(0), m_icon(0), m_lam(PRJFLOAT("0.0")), m_turb(PRJFLOAT("0.0")), m_expt(PRJFLOAT("0.0")),
m_length(PRJFLOAT("0.0")), m_width(PRJFLOAT("0.0")), m_u_L(0), m_u_W(0)
{}

PlrCrack::PlrCrackImpl::PlrCrackImpl(int nr, int icon, std::string name, std::string desc) : PlrCrack::PlrCrackImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrCrack::PlrCrackImpl::PlrCrackImpl(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt,
  double length, double width, int u_L, int u_W) : PlrCrack::PlrCrackImpl()
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

PlrCrack::PlrCrackImpl::PlrCrackImpl(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt,
  std::string length, std::string width, int u_L, int u_W) : PlrCrack::PlrCrackImpl()
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

void PlrCrack::PlrCrackImpl::read(Reader& input)
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

std::string PlrCrack::PlrCrackImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + " plr_crack " + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_lam) + ' ' + PRJFLOAT_TO_STR(m_turb) + ' ' + PRJFLOAT_TO_STR(m_expt) + ' '
    + PRJFLOAT_TO_STR(m_length) + ' ' + PRJFLOAT_TO_STR(m_width) + ' ' + ANY_TO_STR(m_u_L) + ' '
    + ANY_TO_STR(m_u_W) + '\n';
  return string;
}

void PlrCrack::PlrCrackImpl::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setTurb(input.readNumber<std::string>());
  setExpt(input.readNumber<std::string>());
  setLength(input.readNumber<std::string>());
  setWidth(input.readNumber<std::string>());
  setU_L(input.read<int>());
  setU_W(input.read<int>());
}

int PlrCrack::PlrCrackImpl::nr() const
{
  return m_nr;
}

void PlrCrack::PlrCrackImpl::setNr(const int nr)
{
  m_nr = nr;
}

int PlrCrack::PlrCrackImpl::icon() const
{
  return m_icon;
}

void PlrCrack::PlrCrackImpl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string PlrCrack::PlrCrackImpl::name() const
{
  return m_name;
}

void PlrCrack::PlrCrackImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string PlrCrack::PlrCrackImpl::desc() const
{
  return m_desc;
}

void PlrCrack::PlrCrackImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double PlrCrack::PlrCrackImpl::lam() const
{
  return to<double>(m_lam);
}

bool PlrCrack::PlrCrackImpl::setLam(const double lam)
{
  m_lam = to_float(lam);
  return true;
}

bool PlrCrack::PlrCrackImpl::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_lam);
}

double PlrCrack::PlrCrackImpl::turb() const
{
  return to<double>(m_turb);
}

bool PlrCrack::PlrCrackImpl::setTurb(const double turb)
{
  m_turb = to_float(turb);
  return true;
}

bool PlrCrack::PlrCrackImpl::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_turb);
}

double PlrCrack::PlrCrackImpl::expt() const
{
  return to<double>(m_expt);
}

bool PlrCrack::PlrCrackImpl::setExpt(const double expt)
{
  m_expt = to_float(expt);
  return true;
}

bool PlrCrack::PlrCrackImpl::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_expt);
}

double PlrCrack::PlrCrackImpl::length() const
{
  return to<double>(m_length);
}

bool PlrCrack::PlrCrackImpl::setLength(const double length)
{
  m_length = to_float(length);
  return true;
}

bool PlrCrack::PlrCrackImpl::setLength(const std::string& length)
{
  return assign_if_valid<double>(length, m_length);
}

double PlrCrack::PlrCrackImpl::width() const
{
  return to<double>(m_width);
}

bool PlrCrack::PlrCrackImpl::setWidth(const double width)
{
  m_width = to_float(width);
  return true;
}

bool PlrCrack::PlrCrackImpl::setWidth(const std::string& width)
{
  return assign_if_valid<double>(width, m_width);
}

int PlrCrack::PlrCrackImpl::u_L() const
{
  return m_u_L;
}

void PlrCrack::PlrCrackImpl::setU_L(const int u_L)
{
  m_u_L = u_L;
}

int PlrCrack::PlrCrackImpl::u_W() const
{
  return m_u_W;
}

void PlrCrack::PlrCrackImpl::setU_W(const int u_W)
{
  m_u_W = u_W;
}

PlrStair::PlrStair() :
  m_impl(std::shared_ptr<PlrStairImpl>(new PlrStairImpl))
{}

PlrStair::PlrStair(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<PlrStairImpl>(new PlrStairImpl(nr,icon,name,desc)))
{}

PlrStair::PlrStair(int nr,int icon,std::string name,std::string desc,double lam,double turb,
                   double expt,double Ht,double Area,double peo,int tread,int u_A,int u_D) :
  m_impl(std::shared_ptr<PlrStairImpl>(new PlrStairImpl(nr,icon,name,desc,lam,turb,expt,Ht,Area,peo,tread,u_A,u_D)))
{}

PlrStair::PlrStair(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,
                   std::string expt,std::string Ht,std::string Area,std::string peo,int tread,int u_A,int u_D) :
  m_impl(std::shared_ptr<PlrStairImpl>(new PlrStairImpl(nr,icon,name,desc,lam,turb,expt,Ht,Area,peo,tread,u_A,u_D)))
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

std::string PlrStair::write()
{
  return m_impl->write();
}

void PlrStair::read(Reader &input)
{
  m_impl->read(input);
}

void PlrStair::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int PlrStair::nr() const
{
  return m_impl->nr();
}

void PlrStair::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int PlrStair::icon() const
{
  return m_impl->icon();
}

void PlrStair::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string PlrStair::name() const
{
  return m_impl->name();
}

void PlrStair::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string PlrStair::desc() const
{
  return m_impl->desc();
}

void PlrStair::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double PlrStair::lam() const
{
  return m_impl->lam();
}

bool PlrStair::setLam(const double lam)
{
  return m_impl->setLam(lam);
}

bool PlrStair::setLam(const std::string &lam)
{
  return m_impl->setLam(lam);
}

double PlrStair::turb() const
{
  return m_impl->turb();
}

bool PlrStair::setTurb(const double turb)
{
  return m_impl->setTurb(turb);
}

bool PlrStair::setTurb(const std::string &turb)
{
  return m_impl->setTurb(turb);
}

double PlrStair::expt() const
{
  return m_impl->expt();
}

bool PlrStair::setExpt(const double expt)
{
  return m_impl->setExpt(expt);
}

bool PlrStair::setExpt(const std::string &expt)
{
  return m_impl->setExpt(expt);
}

double PlrStair::Ht() const
{
  return m_impl->Ht();
}

bool PlrStair::setHt(const double Ht)
{
  return m_impl->setHt(Ht);
}

bool PlrStair::setHt(const std::string &Ht)
{
  return m_impl->setHt(Ht);
}

double PlrStair::area() const
{
  return m_impl->area();
}

bool PlrStair::setArea(const double Area)
{
  return m_impl->setArea(Area);
}

bool PlrStair::setArea(const std::string &Area)
{
  return m_impl->setArea(Area);
}

double PlrStair::people() const
{
  return m_impl->people();
}

bool PlrStair::setPeople(const double peo)
{
  return m_impl->setPeople(peo);
}

bool PlrStair::setPeople(const std::string &peo)
{
  return m_impl->setPeople(peo);
}

int PlrStair::tread() const
{
  return m_impl->tread();
}

void PlrStair::setTread(const int tread)
{
  m_impl->setTread(tread);
}

int PlrStair::u_A() const
{
  return m_impl->u_A();
}

void PlrStair::setU_A(const int u_A)
{
  m_impl->setU_A(u_A);
}

int PlrStair::u_D() const
{
  return m_impl->u_D();
}

void PlrStair::setU_D(const int u_D)
{
  m_impl->setU_D(u_D);
}

PlrStair::PlrStairImpl::PlrStairImpl() : m_nr(0), m_icon(0), m_lam(PRJFLOAT("0.0")), m_turb(PRJFLOAT("0.0")), m_expt(PRJFLOAT("0.0")),
m_Ht(PRJFLOAT("0.0")), m_Area(PRJFLOAT("0.0")), m_peo(PRJFLOAT("0.0")), m_tread(0), m_u_A(0), m_u_D(0)
{}

PlrStair::PlrStairImpl::PlrStairImpl(int nr, int icon, std::string name, std::string desc) : PlrStair::PlrStairImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrStair::PlrStairImpl::PlrStairImpl(int nr, int icon, std::string name, std::string desc, double lam, double turb,
  double expt, double Ht, double Area, double peo, int tread, int u_A,
  int u_D) : PlrStair::PlrStairImpl()
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

PlrStair::PlrStairImpl::PlrStairImpl(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb,
  std::string expt, std::string Ht, std::string Area, std::string peo, int tread, int u_A,
  int u_D) : PlrStair::PlrStairImpl()
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

void PlrStair::PlrStairImpl::read(Reader& input)
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

std::string PlrStair::PlrStairImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + " plr_stair " + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_lam) + ' ' + PRJFLOAT_TO_STR(m_turb) + ' ' + PRJFLOAT_TO_STR(m_expt) + ' '
    + PRJFLOAT_TO_STR(m_Ht) + ' ' + PRJFLOAT_TO_STR(m_Area) + ' ' + PRJFLOAT_TO_STR(m_peo) + ' '
    + ANY_TO_STR(m_tread) + ' ' + ANY_TO_STR(m_u_A) + ' ' + ANY_TO_STR(m_u_D) + '\n';
  return string;
}

void PlrStair::PlrStairImpl::readDetails(Reader& input)
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

int PlrStair::PlrStairImpl::nr() const
{
  return m_nr;
}

void PlrStair::PlrStairImpl::setNr(const int nr)
{
  m_nr = nr;
}

int PlrStair::PlrStairImpl::icon() const
{
  return m_icon;
}

void PlrStair::PlrStairImpl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string PlrStair::PlrStairImpl::name() const
{
  return m_name;
}

void PlrStair::PlrStairImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string PlrStair::PlrStairImpl::desc() const
{
  return m_desc;
}

void PlrStair::PlrStairImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double PlrStair::PlrStairImpl::lam() const
{
  return to<double>(m_lam);
}

bool PlrStair::PlrStairImpl::setLam(const double lam)
{
  m_lam = to_float(lam);
  return true;
}

bool PlrStair::PlrStairImpl::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_lam);
}

double PlrStair::PlrStairImpl::turb() const
{
  return to<double>(m_turb);
}

bool PlrStair::PlrStairImpl::setTurb(const double turb)
{
  m_turb = to_float(turb);
  return true;
}

bool PlrStair::PlrStairImpl::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_turb);
}

double PlrStair::PlrStairImpl::expt() const
{
  return to<double>(m_expt);
}

bool PlrStair::PlrStairImpl::setExpt(const double expt)
{
  m_expt = to_float(expt);
  return true;
}

bool PlrStair::PlrStairImpl::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_expt);
}

double PlrStair::PlrStairImpl::Ht() const
{
  return to<double>(m_Ht);
}

bool PlrStair::PlrStairImpl::setHt(const double Ht)
{
  m_Ht = to_float(Ht);
  return true;
}

bool PlrStair::PlrStairImpl::setHt(const std::string& Ht)
{
  return assign_if_valid<double>(Ht, m_Ht);
}

double PlrStair::PlrStairImpl::area() const
{
  return to<double>(m_Area);
}

bool PlrStair::PlrStairImpl::setArea(const double Area)
{
  m_Area = to_float(Area);
  return true;
}

bool PlrStair::PlrStairImpl::setArea(const std::string& Area)
{
  return assign_if_valid<double>(Area, m_Area);
}

double PlrStair::PlrStairImpl::people() const
{
  return to<double>(m_peo);
}

bool PlrStair::PlrStairImpl::setPeople(const double peo)
{
  m_peo = to_float(peo);
  return true;
}

bool PlrStair::PlrStairImpl::setPeople(const std::string& peo)
{
  return assign_if_valid<double>(peo, m_peo);
}

int PlrStair::PlrStairImpl::tread() const
{
  return m_tread;
}

void PlrStair::PlrStairImpl::setTread(const int tread)
{
  m_tread = tread;
}

int PlrStair::PlrStairImpl::u_A() const
{
  return m_u_A;
}

void PlrStair::PlrStairImpl::setU_A(const int u_A)
{
  m_u_A = u_A;
}

int PlrStair::PlrStairImpl::u_D() const
{
  return m_u_D;
}

void PlrStair::PlrStairImpl::setU_D(const int u_D)
{
  m_u_D = u_D;
}

PlrShaft::PlrShaft() :
  m_impl(std::shared_ptr<PlrShaftImpl>(new PlrShaftImpl))
{}

PlrShaft::PlrShaft(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<PlrShaftImpl>(new PlrShaftImpl(nr,icon,name,desc)))
{}

PlrShaft::PlrShaft(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt,double Ht,
                   double area,double perim,double rough,int u_A,int u_D,int u_P,int u_R) :
  m_impl(std::shared_ptr<PlrShaftImpl>(new PlrShaftImpl(nr,icon,name,desc,lam,turb,expt,Ht,area,perim,rough,u_A,u_D,u_P,u_R)))
{}

PlrShaft::PlrShaft(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt,std::string Ht,
                   std::string area,std::string perim,std::string rough,int u_A,int u_D,int u_P,int u_R) :
  m_impl(std::shared_ptr<PlrShaftImpl>(new PlrShaftImpl(nr,icon,name,desc,lam,turb,expt,Ht,area,perim,rough,u_A,u_D,u_P,u_R)))
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

std::string PlrShaft::write()
{
  return m_impl->write();
}

void PlrShaft::read(Reader &input)
{
  m_impl->read(input);
}

void PlrShaft::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int PlrShaft::nr() const
{
  return m_impl->nr();
}

void PlrShaft::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int PlrShaft::icon() const
{
  return m_impl->icon();
}

void PlrShaft::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string PlrShaft::name() const
{
  return m_impl->name();
}

void PlrShaft::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string PlrShaft::desc() const
{
  return m_impl->desc();
}

void PlrShaft::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double PlrShaft::lam() const
{
  return m_impl->lam();
}

bool PlrShaft::setLam(const double lam)
{
  return m_impl->setLam(lam);
}

bool PlrShaft::setLam(const std::string &lam)
{
  return m_impl->setLam(lam);
}

double PlrShaft::turb() const
{
  return m_impl->turb();
}

bool PlrShaft::setTurb(const double turb)
{
  return m_impl->setTurb(turb);
}

bool PlrShaft::setTurb(const std::string &turb)
{
  return m_impl->setTurb(turb);
}

double PlrShaft::expt() const
{
  return m_impl->expt();
}

bool PlrShaft::setExpt(const double expt)
{
  return m_impl->setExpt(expt);
}

bool PlrShaft::setExpt(const std::string &expt)
{
  return m_impl->setExpt(expt);
}

double PlrShaft::Ht() const
{
  return m_impl->Ht();
}

bool PlrShaft::setHt(const double Ht)
{
  return m_impl->setHt(Ht);
}

bool PlrShaft::setHt(const std::string &Ht)
{
  return m_impl->setHt(Ht);
}

double PlrShaft::area() const
{
  return m_impl->area();
}

bool PlrShaft::setArea(const double area)
{
  return m_impl->setArea(area);
}

bool PlrShaft::setArea(const std::string &area)
{
  return m_impl->setArea(area);
}

double PlrShaft::perim() const
{
  return m_impl->perim();
}

bool PlrShaft::setPerim(const double perim)
{
  return m_impl->setPerim(perim);
}

bool PlrShaft::setPerim(const std::string &perim)
{
  return m_impl->setPerim(perim);
}

double PlrShaft::rough() const
{
  return m_impl->rough();
}

bool PlrShaft::setRough(const double rough)
{
  return m_impl->setRough(rough);
}

bool PlrShaft::setRough(const std::string &rough)
{
  return m_impl->setRough(rough);
}

int PlrShaft::u_A() const
{
  return m_impl->u_A();
}

void PlrShaft::setU_A(const int u_A)
{
  m_impl->setU_A(u_A);
}

int PlrShaft::u_D() const
{
  return m_impl->u_D();
}

void PlrShaft::setU_D(const int u_D)
{
  m_impl->setU_D(u_D);
}

int PlrShaft::u_P() const
{
  return m_impl->u_P();
}

void PlrShaft::setU_P(const int u_P)
{
  m_impl->setU_P(u_P);
}

int PlrShaft::u_R() const
{
  return m_impl->u_R();
}

void PlrShaft::setU_R(const int u_R)
{
  m_impl->setU_R(u_R);
}


void PlrShaft::PlrShaftImpl::setDefaults()
{
 
}

PlrShaft::PlrShaftImpl::PlrShaftImpl() : m_nr(0), m_icon(0), m_lam(PRJFLOAT("0.0")), m_turb(PRJFLOAT("0.0")), m_expt(PRJFLOAT("0.0")),
m_Ht(PRJFLOAT("0.0")), m_area(PRJFLOAT("0.0")), m_perim(PRJFLOAT("0.0")), m_rough(PRJFLOAT("0.0")), m_u_A(0), m_u_D(0), m_u_P(0), m_u_R(0)
{}

PlrShaft::PlrShaftImpl::PlrShaftImpl(int nr, int icon, std::string name, std::string desc) : PlrShaft::PlrShaftImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrShaft::PlrShaftImpl::PlrShaftImpl(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt,
  double Ht, double area, double perim, double rough, int u_A, int u_D, int u_P, int u_R) : PlrShaft::PlrShaftImpl()
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

PlrShaft::PlrShaftImpl::PlrShaftImpl(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt,
  std::string Ht, std::string area, std::string perim, std::string rough, int u_A, int u_D, int u_P, int u_R) : PlrShaft::PlrShaftImpl()
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

void PlrShaft::PlrShaftImpl::read(Reader& input)
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

std::string PlrShaft::PlrShaftImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + " plr_shaft " + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_lam) + ' ' + PRJFLOAT_TO_STR(m_turb) + ' ' + PRJFLOAT_TO_STR(m_expt) + ' ' + PRJFLOAT_TO_STR(m_Ht)
    + ' ' + PRJFLOAT_TO_STR(m_area) + ' ' + PRJFLOAT_TO_STR(m_perim) + ' ' + PRJFLOAT_TO_STR(m_rough) + ' '
    + ANY_TO_STR(m_u_A) + ' ' + ANY_TO_STR(m_u_D) + ' ' + ANY_TO_STR(m_u_P) + ' ' + ANY_TO_STR(m_u_R)
    + '\n';
  return string;
}

void PlrShaft::PlrShaftImpl::readDetails(Reader& input)
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

int PlrShaft::PlrShaftImpl::nr() const
{
  return m_nr;
}

void PlrShaft::PlrShaftImpl::setNr(const int nr)
{
  m_nr = nr;
}

int PlrShaft::PlrShaftImpl::icon() const
{
  return m_icon;
}

void PlrShaft::PlrShaftImpl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string PlrShaft::PlrShaftImpl::name() const
{
  return m_name;
}

void PlrShaft::PlrShaftImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string PlrShaft::PlrShaftImpl::desc() const
{
  return m_desc;
}

void PlrShaft::PlrShaftImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double PlrShaft::PlrShaftImpl::lam() const
{
  return to<double>(m_lam);
}

bool PlrShaft::PlrShaftImpl::setLam(const double lam)
{
  m_lam = to_float(lam);
  return true;
}

bool PlrShaft::PlrShaftImpl::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_lam);
}

double PlrShaft::PlrShaftImpl::turb() const
{
  return to<double>(m_turb);
}

bool PlrShaft::PlrShaftImpl::setTurb(const double turb)
{
  m_turb = to_float(turb);
  return true;
}

bool PlrShaft::PlrShaftImpl::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_turb);
}

double PlrShaft::PlrShaftImpl::expt() const
{
  return to<double>(m_expt);
}

bool PlrShaft::PlrShaftImpl::setExpt(const double expt)
{
  m_expt = to_float(expt);
  return true;
}

bool PlrShaft::PlrShaftImpl::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_expt);
}

double PlrShaft::PlrShaftImpl::Ht() const
{
  return to<double>(m_Ht);
}

bool PlrShaft::PlrShaftImpl::setHt(const double Ht)
{
  m_Ht = to_float(Ht);
  return true;
}

bool PlrShaft::PlrShaftImpl::setHt(const std::string& Ht)
{
  return assign_if_valid<double>(Ht, m_Ht);
}

double PlrShaft::PlrShaftImpl::area() const
{
  return to<double>(m_area);
}

bool PlrShaft::PlrShaftImpl::setArea(const double area)
{
  m_area = to_float(area);
  return true;
}

bool PlrShaft::PlrShaftImpl::setArea(const std::string& area)
{
  return assign_if_valid<double>(area, m_area);
}

double PlrShaft::PlrShaftImpl::perim() const
{
  return to<double>(m_perim);
}

bool PlrShaft::PlrShaftImpl::setPerim(const double perim)
{
  m_perim = to_float(perim);
  return true;
}

bool PlrShaft::PlrShaftImpl::setPerim(const std::string& perim)
{
  return assign_if_valid<double>(perim, m_perim);
}

double PlrShaft::PlrShaftImpl::rough() const
{
  return to<double>(m_rough);
}

bool PlrShaft::PlrShaftImpl::setRough(const double rough)
{
  m_rough = to_float(rough);
  return true;
}

bool PlrShaft::PlrShaftImpl::setRough(const std::string& rough)
{
  return assign_if_valid<double>(rough, m_rough);
}

int PlrShaft::PlrShaftImpl::u_A() const
{
  return m_u_A;
}

void PlrShaft::PlrShaftImpl::setU_A(const int u_A)
{
  m_u_A = u_A;
}

int PlrShaft::PlrShaftImpl::u_D() const
{
  return m_u_D;
}

void PlrShaft::PlrShaftImpl::setU_D(const int u_D)
{
  m_u_D = u_D;
}

int PlrShaft::PlrShaftImpl::u_P() const
{
  return m_u_P;
}

void PlrShaft::PlrShaftImpl::setU_P(const int u_P)
{
  m_u_P = u_P;
}

int PlrShaft::PlrShaftImpl::u_R() const
{
  return m_u_R;
}

void PlrShaft::PlrShaftImpl::setU_R(const int u_R)
{
  m_u_R = u_R;
}

PlrBackDamper::PlrBackDamper() :
  m_impl(std::shared_ptr<PlrBackDamperImpl>(new PlrBackDamperImpl))
{}

PlrBackDamper::PlrBackDamper(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<PlrBackDamperImpl>(new PlrBackDamperImpl(nr,icon,name,desc)))
{}

PlrBackDamper::PlrBackDamper(int nr,int icon,std::string name,std::string desc,double lam,double Cp,double xp,double Cn,double xn) :
  m_impl(std::shared_ptr<PlrBackDamperImpl>(new PlrBackDamperImpl(nr,icon,name,desc,lam,Cp,xp,Cn,xn)))
{}

PlrBackDamper::PlrBackDamper(int nr,int icon,std::string name,std::string desc,std::string lam,std::string Cp,std::string xp,std::string Cn,std::string xn) :
  m_impl(std::shared_ptr<PlrBackDamperImpl>(new PlrBackDamperImpl(nr,icon,name,desc,lam,Cp,xp,Cn,xn)))
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

std::string PlrBackDamper::write()
{
  return m_impl->write("plr_bdq");
}

void PlrBackDamper::read(Reader &input)
{
  m_impl->read(input);
}

void PlrBackDamper::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int PlrBackDamper::nr() const
{
  return m_impl->nr();
}

void PlrBackDamper::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int PlrBackDamper::icon() const
{
  return m_impl->icon();
}

void PlrBackDamper::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string PlrBackDamper::name() const
{
  return m_impl->name();
}

void PlrBackDamper::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string PlrBackDamper::desc() const
{
  return m_impl->desc();
}

void PlrBackDamper::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double PlrBackDamper::lam() const
{
  return m_impl->lam();
}

bool PlrBackDamper::setLam(const double lam)
{
  return m_impl->setLam(lam);
}

bool PlrBackDamper::setLam(const std::string &lam)
{
  return m_impl->setLam(lam);
}

double PlrBackDamper::Cp() const
{
  return m_impl->Cp();
}

bool PlrBackDamper::setCp(const double Cp)
{
  return m_impl->setCp(Cp);
}

bool PlrBackDamper::setCp(const std::string &Cp)
{
  return m_impl->setCp(Cp);
}

double PlrBackDamper::xp() const
{
  return m_impl->xp();
}

bool PlrBackDamper::setXp(const double xp)
{
  return m_impl->setXp(xp);
}

bool PlrBackDamper::setXp(const std::string &xp)
{
  return m_impl->setXp(xp);
}

double PlrBackDamper::Cn() const
{
  return m_impl->Cn();
}

bool PlrBackDamper::setCn(const double Cn)
{
  return m_impl->setCn(Cn);
}

bool PlrBackDamper::setCn(const std::string &Cn)
{
  return m_impl->setCn(Cn);
}

double PlrBackDamper::xn() const
{
  return m_impl->xn();
}

bool PlrBackDamper::setXn(const double xn)
{
  return m_impl->setXn(xn);
}

bool PlrBackDamper::setXn(const std::string &xn)
{
  return m_impl->setXn(xn);
}

PlrBackDamper::PlrBackDamperImpl::PlrBackDamperImpl() : m_nr(0), m_icon(0), m_lam(PRJFLOAT("0.0")), m_Cp(PRJFLOAT("0.0")), m_xp(PRJFLOAT("0.0")),
m_Cn(PRJFLOAT("0.0")), m_xn(PRJFLOAT("0.0"))
{}

PlrBackDamper::PlrBackDamperImpl::PlrBackDamperImpl(int nr, int icon, std::string name, std::string desc) : PlrBackDamper::PlrBackDamperImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

PlrBackDamper::PlrBackDamperImpl::PlrBackDamperImpl(int nr, int icon, std::string name, std::string desc, double lam, double Cp, double xp, double Cn,
  double xn) : PlrBackDamper::PlrBackDamperImpl()
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

PlrBackDamper::PlrBackDamperImpl::PlrBackDamperImpl(int nr, int icon, std::string name, std::string desc, std::string lam, std::string Cp, std::string xp, std::string Cn,
  std::string xn) : PlrBackDamper::PlrBackDamperImpl()
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

void PlrBackDamper::PlrBackDamperImpl::read(Reader& input)
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

std::string PlrBackDamper::PlrBackDamperImpl::write(std::string dataType)
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + ' ' + dataType + ' ' + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_lam) + ' ' + PRJFLOAT_TO_STR(m_Cp) + ' ' + PRJFLOAT_TO_STR(m_xp) + ' ' + PRJFLOAT_TO_STR(m_Cn)
    + ' ' + PRJFLOAT_TO_STR(m_xn) + '\n';
  return string;
}

void PlrBackDamper::PlrBackDamperImpl::readDetails(Reader& input)
{
  setLam(input.readNumber<std::string>());
  setCp(input.readNumber<std::string>());
  setXp(input.readNumber<std::string>());
  setCn(input.readNumber<std::string>());
  setXn(input.readNumber<std::string>());
}

int PlrBackDamper::PlrBackDamperImpl::nr() const
{
  return m_nr;
}

void PlrBackDamper::PlrBackDamperImpl::setNr(const int nr)
{
  m_nr = nr;
}

int PlrBackDamper::PlrBackDamperImpl::icon() const
{
  return m_icon;
}

void PlrBackDamper::PlrBackDamperImpl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string PlrBackDamper::PlrBackDamperImpl::name() const
{
  return m_name;
}

void PlrBackDamper::PlrBackDamperImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string PlrBackDamper::PlrBackDamperImpl::desc() const
{
  return m_desc;
}

void PlrBackDamper::PlrBackDamperImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double PlrBackDamper::PlrBackDamperImpl::lam() const
{
  return to<double>(m_lam);
}

bool PlrBackDamper::PlrBackDamperImpl::setLam(const double lam)
{
  m_lam = to_float(lam);
  return true;
}

bool PlrBackDamper::PlrBackDamperImpl::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_lam);
}

double PlrBackDamper::PlrBackDamperImpl::Cp() const
{
  return to<double>(m_Cp);
}

bool PlrBackDamper::PlrBackDamperImpl::setCp(const double Cp)
{
  m_Cp = to_float(Cp);
  return true;
}

bool PlrBackDamper::PlrBackDamperImpl::setCp(const std::string& Cp)
{
  return assign_if_valid<double>(Cp, m_Cp);
}

double PlrBackDamper::PlrBackDamperImpl::xp() const
{
  return to<double>(m_xp);
}

bool PlrBackDamper::PlrBackDamperImpl::setXp(const double xp)
{
  m_xp = to_float(xp);
  return true;
}

bool PlrBackDamper::PlrBackDamperImpl::setXp(const std::string& xp)
{
  return assign_if_valid<double>(xp, m_xp);
}

double PlrBackDamper::PlrBackDamperImpl::Cn() const
{
  return to<double>(m_Cn);
}

bool PlrBackDamper::PlrBackDamperImpl::setCn(const double Cn)
{
  m_Cn = to_float(Cn);
  return true;
}

bool PlrBackDamper::PlrBackDamperImpl::setCn(const std::string& Cn)
{
  return assign_if_valid<double>(Cn, m_Cn);
}

double PlrBackDamper::PlrBackDamperImpl::xn() const
{
  return to<double>(m_xn);
}

bool PlrBackDamper::PlrBackDamperImpl::setXn(const double xn)
{
  m_xn = to_float(xn);
  return true;
}

bool PlrBackDamper::PlrBackDamperImpl::setXn(const std::string& xn)
{
  return assign_if_valid<double>(xn, m_xn);
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
  m_impl(std::shared_ptr<QfrGeneralImpl>(new QfrGeneralImpl))
{}

QfrGeneral::QfrGeneral(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<QfrGeneralImpl>(new QfrGeneralImpl(nr,icon,name,desc)))
{}

QfrGeneral::QfrGeneral(int nr,int icon,std::string name,std::string desc,double a,double b) :
  m_impl(std::shared_ptr<QfrGeneralImpl>(new QfrGeneralImpl(nr,icon,name,desc,a,b)))
{}

QfrGeneral::QfrGeneral(int nr,int icon,std::string name,std::string desc,std::string a,std::string b) :
  m_impl(std::shared_ptr<QfrGeneralImpl>(new QfrGeneralImpl(nr,icon,name,desc,a,b)))
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

std::string QfrGeneral::write()
{
  return m_impl->write(dataType());
}

void QfrGeneral::read(Reader &input)
{
  m_impl->read(input);
}

void QfrGeneral::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int QfrGeneral::nr() const
{
  return m_impl->nr();
}

void QfrGeneral::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int QfrGeneral::icon() const
{
  return m_impl->icon();
}

void QfrGeneral::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string QfrGeneral::name() const
{
  return m_impl->name();
}

void QfrGeneral::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string QfrGeneral::desc() const
{
  return m_impl->desc();
}

void QfrGeneral::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double QfrGeneral::a() const
{
  return m_impl->a();
}

bool QfrGeneral::setA(const double a)
{
  return m_impl->setA(a);
}

bool QfrGeneral::setA(const std::string &a)
{
  return m_impl->setA(a);
}

double QfrGeneral::b() const
{
  return m_impl->b();
}

bool QfrGeneral::setB(const double b)
{
  return m_impl->setB(b);
}

bool QfrGeneral::setB(const std::string &b)
{
  return m_impl->setB(b);
}

QfrGeneral::QfrGeneralImpl::QfrGeneralImpl() : m_nr(0), m_icon(0), m_a(PRJFLOAT("0.0")), m_b(PRJFLOAT("0.0"))
{}

QfrGeneral::QfrGeneralImpl::QfrGeneralImpl(int nr, int icon, std::string name, std::string desc) : QfrGeneral::QfrGeneralImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

QfrGeneral::QfrGeneralImpl::QfrGeneralImpl(int nr, int icon, std::string name, std::string desc, double a, double b) : QfrGeneral::QfrGeneralImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setA(a);
  setB(b);
}

QfrGeneral::QfrGeneralImpl::QfrGeneralImpl(int nr, int icon, std::string name, std::string desc, std::string a, std::string b) : QfrGeneral::QfrGeneralImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setA(a);
  setB(b);
}

void QfrGeneral::QfrGeneralImpl::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setA(input.readNumber<std::string>());
  setB(input.readNumber<std::string>());
}

std::string QfrGeneral::QfrGeneralImpl::write(std::string dataType)
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + ' ' + dataType + ' ' + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_a) + ' ' + PRJFLOAT_TO_STR(m_b) + '\n';
  return string;
}

void QfrGeneral::QfrGeneralImpl::readDetails(Reader& input)
{
  setA(input.readNumber<std::string>());
  setB(input.readNumber<std::string>());
}

int QfrGeneral::QfrGeneralImpl::nr() const
{
  return m_nr;
}

void QfrGeneral::QfrGeneralImpl::setNr(const int nr)
{
  m_nr = nr;
}

int QfrGeneral::QfrGeneralImpl::icon() const
{
  return m_icon;
}

void QfrGeneral::QfrGeneralImpl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string QfrGeneral::QfrGeneralImpl::name() const
{
  return m_name;
}

void QfrGeneral::QfrGeneralImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string QfrGeneral::QfrGeneralImpl::desc() const
{
  return m_desc;
}

void QfrGeneral::QfrGeneralImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double QfrGeneral::QfrGeneralImpl::a() const
{
  return to<double>(m_a);
}

bool QfrGeneral::QfrGeneralImpl::setA(const double a)
{
  m_a = to_float(a);
  return true;
}

bool QfrGeneral::QfrGeneralImpl::setA(const std::string& a)
{
  return assign_if_valid<double>(a, m_a);
}

double QfrGeneral::QfrGeneralImpl::b() const
{
  return to<double>(m_b);
}

bool QfrGeneral::QfrGeneralImpl::setB(const double b)
{
  m_b = to_float(b);
  return true;
}

bool QfrGeneral::QfrGeneralImpl::setB(const std::string& b)
{
  return assign_if_valid<double>(b, m_b);
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
  m_impl(std::shared_ptr<QfrCrackImpl>(new QfrCrackImpl))
{}

QfrCrack::QfrCrack(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<QfrCrackImpl>(new QfrCrackImpl(nr,icon,name,desc)))
{}

QfrCrack::QfrCrack(int nr,int icon,std::string name,std::string desc,double a,double b,double length,double width,
                   double depth,int nB,int u_L,int u_W,int u_D) :
  m_impl(std::shared_ptr<QfrCrackImpl>(new QfrCrackImpl(nr,icon,name,desc,a,b,length,width,depth,nB,u_L,u_W,u_D)))
{}

QfrCrack::QfrCrack(int nr,int icon,std::string name,std::string desc,std::string a,std::string b,std::string length,std::string width,
                   std::string depth,int nB,int u_L,int u_W,int u_D) :
  m_impl(std::shared_ptr<QfrCrackImpl>(new QfrCrackImpl(nr,icon,name,desc,a,b,length,width,depth,nB,u_L,u_W,u_D)))
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

std::string QfrCrack::write()
{
  return m_impl->write();
}

void QfrCrack::read(Reader &input)
{
  m_impl->read(input);
}

void QfrCrack::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int QfrCrack::nr() const
{
  return m_impl->nr();
}

void QfrCrack::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int QfrCrack::icon() const
{
  return m_impl->icon();
}

void QfrCrack::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string QfrCrack::name() const
{
  return m_impl->name();
}

void QfrCrack::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string QfrCrack::desc() const
{
  return m_impl->desc();
}

void QfrCrack::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double QfrCrack::a() const
{
  return m_impl->a();
}

bool QfrCrack::setA(const double a)
{
  return m_impl->setA(a);
}

bool QfrCrack::setA(const std::string &a)
{
  return m_impl->setA(a);
}

double QfrCrack::b() const
{
  return m_impl->b();
}

bool QfrCrack::setB(const double b)
{
  return m_impl->setB(b);
}

bool QfrCrack::setB(const std::string &b)
{
  return m_impl->setB(b);
}

double QfrCrack::length() const
{
  return m_impl->length();
}

bool QfrCrack::setLength(const double length)
{
  return m_impl->setLength(length);
}

bool QfrCrack::setLength(const std::string &length)
{
  return m_impl->setLength(length);
}

double QfrCrack::width() const
{
  return m_impl->width();
}

bool QfrCrack::setWidth(const double width)
{
  return m_impl->setWidth(width);
}

bool QfrCrack::setWidth(const std::string &width)
{
  return m_impl->setWidth(width);
}

double QfrCrack::depth() const
{
  return m_impl->depth();
}

bool QfrCrack::setDepth(const double depth)
{
  return m_impl->setDepth(depth);
}

bool QfrCrack::setDepth(const std::string &depth)
{
  return m_impl->setDepth(depth);
}

int QfrCrack::nB() const
{
  return m_impl->nB();
}

void QfrCrack::setNB(const int nB)
{
  m_impl->setNB(nB);
}

int QfrCrack::u_L() const
{
  return m_impl->u_L();
}

void QfrCrack::setU_L(const int u_L)
{
  m_impl->setU_L(u_L);
}

int QfrCrack::u_W() const
{
  return m_impl->u_W();
}

void QfrCrack::setU_W(const int u_W)
{
  m_impl->setU_W(u_W);
}

int QfrCrack::u_D() const
{
  return m_impl->u_D();
}

void QfrCrack::setU_D(const int u_D)
{
  m_impl->setU_D(u_D);
}

QfrCrack::QfrCrackImpl::QfrCrackImpl() : m_nr(0), m_icon(0), m_a(PRJFLOAT("0.0")), m_b(PRJFLOAT("0.0")), m_length(PRJFLOAT("0.0")),
m_width(PRJFLOAT("0.0")), m_depth(PRJFLOAT("0.0")), m_nB(0), m_u_L(0), m_u_W(0), m_u_D(0)
{}

QfrCrack::QfrCrackImpl::QfrCrackImpl(int nr, int icon, std::string name, std::string desc) : QfrCrack::QfrCrackImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

QfrCrack::QfrCrackImpl::QfrCrackImpl(int nr, int icon, std::string name, std::string desc, double a, double b, double length,
  double width, double depth, int nB, int u_L, int u_W, int u_D) : QfrCrack::QfrCrackImpl()
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

QfrCrack::QfrCrackImpl::QfrCrackImpl(int nr, int icon, std::string name, std::string desc, std::string a, std::string b, std::string length,
  std::string width, std::string depth, int nB, int u_L, int u_W, int u_D) : QfrCrack::QfrCrackImpl()
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

void QfrCrack::QfrCrackImpl::read(Reader& input)
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

std::string QfrCrack::QfrCrackImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + " qfr_crack " + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_a) + ' ' + PRJFLOAT_TO_STR(m_b) + ' ' + PRJFLOAT_TO_STR(m_length) + ' ' + PRJFLOAT_TO_STR(m_width)
    + ' ' + PRJFLOAT_TO_STR(m_depth) + ' ' + ANY_TO_STR(m_nB) + ' ' + ANY_TO_STR(m_u_L) + ' '
    + ANY_TO_STR(m_u_W) + ' ' + ANY_TO_STR(m_u_D) + '\n';
  return string;
}

void QfrCrack::QfrCrackImpl::readDetails(Reader& input)
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

int QfrCrack::QfrCrackImpl::nr() const
{
  return m_nr;
}

void QfrCrack::QfrCrackImpl::setNr(const int nr)
{
  m_nr = nr;
}

int QfrCrack::QfrCrackImpl::icon() const
{
  return m_icon;
}

void QfrCrack::QfrCrackImpl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string QfrCrack::QfrCrackImpl::name() const
{
  return m_name;
}

void QfrCrack::QfrCrackImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string QfrCrack::QfrCrackImpl::desc() const
{
  return m_desc;
}

void QfrCrack::QfrCrackImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double QfrCrack::QfrCrackImpl::a() const
{
  return to<double>(m_a);
}

bool QfrCrack::QfrCrackImpl::setA(const double a)
{
  m_a = to_float(a);
  return true;
}

bool QfrCrack::QfrCrackImpl::setA(const std::string& a)
{
  return assign_if_valid<double>(a, m_a);
}

double QfrCrack::QfrCrackImpl::b() const
{
  return to<double>(m_b);
}

bool QfrCrack::QfrCrackImpl::setB(const double b)
{
  m_b = to_float(b);
  return true;
}

bool QfrCrack::QfrCrackImpl::setB(const std::string& b)
{
  return assign_if_valid<double>(b, m_b);
}

double QfrCrack::QfrCrackImpl::length() const
{
  return to<double>(m_length);
}

bool QfrCrack::QfrCrackImpl::setLength(const double length)
{
  m_length = to_float(length);
  return true;
}

bool QfrCrack::QfrCrackImpl::setLength(const std::string& length)
{
  return assign_if_valid<double>(length, m_length);
}

double QfrCrack::QfrCrackImpl::width() const
{
  return to<double>(m_width);
}

bool QfrCrack::QfrCrackImpl::setWidth(const double width)
{
  m_width = to_float(width);
  return true;
}

bool QfrCrack::QfrCrackImpl::setWidth(const std::string& width)
{
  return assign_if_valid<double>(width, m_width);
}

double QfrCrack::QfrCrackImpl::depth() const
{
  return to<double>(m_depth);
}

bool QfrCrack::QfrCrackImpl::setDepth(const double depth)
{
  m_depth = to_float(depth);
  return true;
}

bool QfrCrack::QfrCrackImpl::setDepth(const std::string& depth)
{
  return assign_if_valid<double>(depth, m_depth);
}

int QfrCrack::QfrCrackImpl::nB() const
{
  return m_nB;
}

void QfrCrack::QfrCrackImpl::setNB(const int nB)
{
  m_nB = nB;
}

int QfrCrack::QfrCrackImpl::u_L() const
{
  return m_u_L;
}

void QfrCrack::QfrCrackImpl::setU_L(const int u_L)
{
  m_u_L = u_L;
}

int QfrCrack::QfrCrackImpl::u_W() const
{
  return m_u_W;
}

void QfrCrack::QfrCrackImpl::setU_W(const int u_W)
{
  m_u_W = u_W;
}

int QfrCrack::QfrCrackImpl::u_D() const
{
  return m_u_D;
}

void QfrCrack::QfrCrackImpl::setU_D(const int u_D)
{
  m_u_D = u_D;
}

QfrTest2::QfrTest2() :
  m_impl(std::shared_ptr<QfrTest2Impl>(new QfrTest2Impl))
{}

QfrTest2::QfrTest2(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<QfrTest2Impl>(new QfrTest2Impl(nr,icon,name,desc)))
{}

QfrTest2::QfrTest2(int nr,int icon,std::string name,std::string desc,double a,double b,double dP1,double F1,
                   double dP2,double F2,int u_P1,int u_F1,int u_P2,int u_F2) :
  m_impl(std::shared_ptr<QfrTest2Impl>(new QfrTest2Impl(nr,icon,name,desc,a,b,dP1,F1,dP2,F2,u_P1,u_F1,u_P2,u_F2)))
{}

QfrTest2::QfrTest2(int nr,int icon,std::string name,std::string desc,std::string a,std::string b,std::string dP1,std::string F1,
                   std::string dP2,std::string F2,int u_P1,int u_F1,int u_P2,int u_F2) :
  m_impl(std::shared_ptr<QfrTest2Impl>(new QfrTest2Impl(nr,icon,name,desc,a,b,dP1,F1,dP2,F2,u_P1,u_F1,u_P2,u_F2)))
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

std::string QfrTest2::write()
{
  return m_impl->write();
}

void QfrTest2::read(Reader &input)
{
  m_impl->read(input);
}

void QfrTest2::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int QfrTest2::nr() const
{
  return m_impl->nr();
}

void QfrTest2::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int QfrTest2::icon() const
{
  return m_impl->icon();
}

void QfrTest2::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string QfrTest2::name() const
{
  return m_impl->name();
}

void QfrTest2::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string QfrTest2::desc() const
{
  return m_impl->desc();
}

void QfrTest2::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double QfrTest2::a() const
{
  return m_impl->a();
}

bool QfrTest2::setA(const double a)
{
  return m_impl->setA(a);
}

bool QfrTest2::setA(const std::string &a)
{
  return m_impl->setA(a);
}

double QfrTest2::b() const
{
  return m_impl->b();
}

bool QfrTest2::setB(const double b)
{
  return m_impl->setB(b);
}

bool QfrTest2::setB(const std::string &b)
{
  return m_impl->setB(b);
}

double QfrTest2::dP1() const
{
  return m_impl->dP1();
}

bool QfrTest2::setDP1(const double dP1)
{
  return m_impl->setDP1(dP1);
}

bool QfrTest2::setDP1(const std::string &dP1)
{
  return m_impl->setDP1(dP1);
}

double QfrTest2::F1() const
{
  return m_impl->F1();
}

bool QfrTest2::setF1(const double F1)
{
  return m_impl->setF1(F1);
}

bool QfrTest2::setF1(const std::string &F1)
{
  return m_impl->setF1(F1);
}

double QfrTest2::dP2() const
{
  return m_impl->dP2();
}

bool QfrTest2::setDP2(const double dP2)
{
  return m_impl->setDP2(dP2);
}

bool QfrTest2::setDP2(const std::string &dP2)
{
  return m_impl->setDP2(dP2);
}

double QfrTest2::F2() const
{
  return m_impl->F2();
}

bool QfrTest2::setF2(const double F2)
{
  return m_impl->setF2(F2);
}

bool QfrTest2::setF2(const std::string &F2)
{
  return m_impl->setF2(F2);
}

int QfrTest2::u_P1() const
{
  return m_impl->u_P1();
}

void QfrTest2::setU_P1(const int u_P1)
{
  m_impl->setU_P1(u_P1);
}

int QfrTest2::u_F1() const
{
  return m_impl->u_F1();
}

void QfrTest2::setU_F1(const int u_F1)
{
  m_impl->setU_F1(u_F1);
}

int QfrTest2::u_P2() const
{
  return m_impl->u_P2();
}

void QfrTest2::setU_P2(const int u_P2)
{
  m_impl->setU_P2(u_P2);
}

int QfrTest2::u_F2() const
{
  return m_impl->u_F2();
}

void QfrTest2::setU_F2(const int u_F2)
{
  m_impl->setU_F2(u_F2);
}

QfrTest2::QfrTest2Impl::QfrTest2Impl() : m_nr(0), m_icon(0), m_a(PRJFLOAT("0.0")), m_b(PRJFLOAT("0.0")), m_dP1(PRJFLOAT("0.0")),
m_F1(PRJFLOAT("0.0")), m_dP2(PRJFLOAT("0.0")), m_F2(PRJFLOAT("0.0")), m_u_P1(0), m_u_F1(0), m_u_P2(0), m_u_F2(0)
{}

QfrTest2::QfrTest2Impl::QfrTest2Impl(int nr, int icon, std::string name, std::string desc) : QfrTest2::QfrTest2Impl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

QfrTest2::QfrTest2Impl::QfrTest2Impl(int nr, int icon, std::string name, std::string desc, double a, double b, double dP1, double F1,
  double dP2, double F2, int u_P1, int u_F1, int u_P2, int u_F2) : QfrTest2::QfrTest2Impl()
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

QfrTest2::QfrTest2Impl::QfrTest2Impl(int nr, int icon, std::string name, std::string desc, std::string a, std::string b, std::string dP1, std::string F1,
  std::string dP2, std::string F2, int u_P1, int u_F1, int u_P2, int u_F2) : QfrTest2::QfrTest2Impl()
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

void QfrTest2::QfrTest2Impl::read(Reader& input)
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

std::string QfrTest2::QfrTest2Impl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + " qfr_test2 " + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_a) + ' ' + PRJFLOAT_TO_STR(m_b) + ' ' + PRJFLOAT_TO_STR(m_dP1) + ' ' + PRJFLOAT_TO_STR(m_F1)
    + ' ' + PRJFLOAT_TO_STR(m_dP2) + ' ' + PRJFLOAT_TO_STR(m_F2) + ' ' + ANY_TO_STR(m_u_P1) + ' '
    + ANY_TO_STR(m_u_F1) + ' ' + ANY_TO_STR(m_u_P2) + ' ' + ANY_TO_STR(m_u_F2) + '\n';
  return string;
}

void QfrTest2::QfrTest2Impl::readDetails(Reader& input)
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

int QfrTest2::QfrTest2Impl::nr() const
{
  return m_nr;
}

void QfrTest2::QfrTest2Impl::setNr(const int nr)
{
  m_nr = nr;
}

int QfrTest2::QfrTest2Impl::icon() const
{
  return m_icon;
}

void QfrTest2::QfrTest2Impl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string QfrTest2::QfrTest2Impl::name() const
{
  return m_name;
}

void QfrTest2::QfrTest2Impl::setName(const std::string& name)
{
  m_name = name;
}

std::string QfrTest2::QfrTest2Impl::desc() const
{
  return m_desc;
}

void QfrTest2::QfrTest2Impl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double QfrTest2::QfrTest2Impl::a() const
{
  return to<double>(m_a);
}

bool QfrTest2::QfrTest2Impl::setA(const double a)
{
  m_a = to_float(a);
  return true;
}

bool QfrTest2::QfrTest2Impl::setA(const std::string& a)
{
  return assign_if_valid<double>(a, m_a);
}

double QfrTest2::QfrTest2Impl::b() const
{
  return to<double>(m_b);
}

bool QfrTest2::QfrTest2Impl::setB(const double b)
{
  m_b = to_float(b);
  return true;
}

bool QfrTest2::QfrTest2Impl::setB(const std::string& b)
{
  return assign_if_valid<double>(b, m_b);
}

double QfrTest2::QfrTest2Impl::dP1() const
{
  return to<double>(m_dP1);
}

bool QfrTest2::QfrTest2Impl::setDP1(const double dP1)
{
  m_dP1 = to_float(dP1);
  return true;
}

bool QfrTest2::QfrTest2Impl::setDP1(const std::string& dP1)
{
  return assign_if_valid<double>(dP1, m_dP1);
}

double QfrTest2::QfrTest2Impl::F1() const
{
  return to<double>(m_F1);
}

bool QfrTest2::QfrTest2Impl::setF1(const double F1)
{
  m_F1 = to_float(F1);
  return true;
}

bool QfrTest2::QfrTest2Impl::setF1(const std::string& F1)
{
  return assign_if_valid<double>(F1, m_F1);
}

double QfrTest2::QfrTest2Impl::dP2() const
{
  return to<double>(m_dP2);
}

bool QfrTest2::QfrTest2Impl::setDP2(const double dP2)
{
  m_dP2 = to_float(dP2);
  return true;
}

bool QfrTest2::QfrTest2Impl::setDP2(const std::string& dP2)
{
  return assign_if_valid<double>(dP2, m_dP2);
}

double QfrTest2::QfrTest2Impl::F2() const
{
  return to<double>(m_F2);
}

bool QfrTest2::QfrTest2Impl::setF2(const double F2)
{
  m_F2 = to_float(F2);
  return true;
}

bool QfrTest2::QfrTest2Impl::setF2(const std::string& F2)
{
  return assign_if_valid<double>(F2, m_F2);
}

int QfrTest2::QfrTest2Impl::u_P1() const
{
  return m_u_P1;
}

void QfrTest2::QfrTest2Impl::setU_P1(const int u_P1)
{
  m_u_P1 = u_P1;
}

int QfrTest2::QfrTest2Impl::u_F1() const
{
  return m_u_F1;
}

void QfrTest2::QfrTest2Impl::setU_F1(const int u_F1)
{
  m_u_F1 = u_F1;
}

int QfrTest2::QfrTest2Impl::u_P2() const
{
  return m_u_P2;
}

void QfrTest2::QfrTest2Impl::setU_P2(const int u_P2)
{
  m_u_P2 = u_P2;
}

int QfrTest2::QfrTest2Impl::u_F2() const
{
  return m_u_F2;
}

void QfrTest2::QfrTest2Impl::setU_F2(const int u_F2)
{
  m_u_F2 = u_F2;
}

AfeDor::AfeDor() :
  m_impl(std::shared_ptr<AfeDorImpl>(new AfeDorImpl))
{}

AfeDor::AfeDor(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<AfeDorImpl>(new AfeDorImpl(nr,icon,name,desc)))
{}

AfeDor::AfeDor(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt,double dTmin,
               double ht,double wd,double cd,int u_T,int u_H,int u_W) :
  m_impl(std::shared_ptr<AfeDorImpl>(new AfeDorImpl(nr,icon,name,desc,lam,turb,expt,dTmin,ht,wd,cd,u_T,u_H,u_W)))
{}

AfeDor::AfeDor(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt,std::string dTmin,
               std::string ht,std::string wd,std::string cd,int u_T,int u_H,int u_W) :
  m_impl(std::shared_ptr<AfeDorImpl>(new AfeDorImpl(nr,icon,name,desc,lam,turb,expt,dTmin,ht,wd,cd,u_T,u_H,u_W)))
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

std::string AfeDor::write()
{
  return m_impl->write();
}

void AfeDor::read(Reader &input)
{
  m_impl->read(input);
}

void AfeDor::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int AfeDor::nr() const
{
  return m_impl->nr();
}

void AfeDor::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int AfeDor::icon() const
{
  return m_impl->icon();
}

void AfeDor::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string AfeDor::name() const
{
  return m_impl->name();
}

void AfeDor::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string AfeDor::desc() const
{
  return m_impl->desc();
}

void AfeDor::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double AfeDor::lam() const
{
  return m_impl->lam();
}

bool AfeDor::setLam(const double lam)
{
  return m_impl->setLam(lam);
}

bool AfeDor::setLam(const std::string &lam)
{
  return m_impl->setLam(lam);
}

double AfeDor::turb() const
{
  return m_impl->turb();
}

bool AfeDor::setTurb(const double turb)
{
  return m_impl->setTurb(turb);
}

bool AfeDor::setTurb(const std::string &turb)
{
  return m_impl->setTurb(turb);
}

double AfeDor::expt() const
{
  return m_impl->expt();
}

bool AfeDor::setExpt(const double expt)
{
  return m_impl->setExpt(expt);
}

bool AfeDor::setExpt(const std::string &expt)
{
  return m_impl->setExpt(expt);
}

double AfeDor::dTmin() const
{
  return m_impl->dTmin();
}

bool AfeDor::setDTmin(const double dTmin)
{
  return m_impl->setDTmin(dTmin);
}

bool AfeDor::setDTmin(const std::string &dTmin)
{
  return m_impl->setDTmin(dTmin);
}

double AfeDor::height() const
{
  return m_impl->height();
}

bool AfeDor::setHeight(const double ht)
{
  return m_impl->setHeight(ht);
}

bool AfeDor::setHeight(const std::string &ht)
{
  return m_impl->setHeight(ht);
}

double AfeDor::width() const
{
  return m_impl->width();
}

bool AfeDor::setWidth(const double wd)
{
  return m_impl->setWidth(wd);
}

bool AfeDor::setWidth(const std::string &wd)
{
  return m_impl->setWidth(wd);
}

double AfeDor::cd() const
{
  return m_impl->cd();
}

bool AfeDor::setCd(const double cd)
{
  return m_impl->setCd(cd);
}

bool AfeDor::setCd(const std::string &cd)
{
  return m_impl->setCd(cd);
}

int AfeDor::u_T() const
{
  return m_impl->u_T();
}

void AfeDor::setU_T(const int u_T)
{
  m_impl->setU_T(u_T);
}

int AfeDor::u_H() const
{
  return m_impl->u_H();
}

void AfeDor::setU_H(const int u_H)
{
  m_impl->setU_H(u_H);
}

int AfeDor::u_W() const
{
  return m_impl->u_W();
}

void AfeDor::setU_W(const int u_W)
{
  m_impl->setU_W(u_W);
}

AfeDor::AfeDorImpl::AfeDorImpl() : m_nr(0), m_icon(0), m_lam(PRJFLOAT("0.0")), m_turb(PRJFLOAT("0.0")), m_expt(PRJFLOAT("0.0")),
m_dTmin(PRJFLOAT("0.0")), m_ht(PRJFLOAT("0.0")), m_wd(PRJFLOAT("0.0")), m_cd(PRJFLOAT("0.0")), m_u_T(0), m_u_H(0), m_u_W(0)
{}

AfeDor::AfeDorImpl::AfeDorImpl(int nr, int icon, std::string name, std::string desc) : AfeDor::AfeDorImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

AfeDor::AfeDorImpl::AfeDorImpl(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt,
  double dTmin, double ht, double wd, double cd, int u_T, int u_H, int u_W) : AfeDor::AfeDorImpl()
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

AfeDor::AfeDorImpl::AfeDorImpl(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt,
  std::string dTmin, std::string ht, std::string wd, std::string cd, int u_T, int u_H, int u_W) : AfeDor::AfeDorImpl()
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

void AfeDor::AfeDorImpl::read(Reader& input)
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

std::string AfeDor::AfeDorImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + " dor_door " + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_lam) + ' ' + PRJFLOAT_TO_STR(m_turb) + ' ' + PRJFLOAT_TO_STR(m_expt) + ' '
    + PRJFLOAT_TO_STR(m_dTmin) + ' ' + PRJFLOAT_TO_STR(m_ht) + ' ' + PRJFLOAT_TO_STR(m_wd) + ' '
    + PRJFLOAT_TO_STR(m_cd) + ' ' + ANY_TO_STR(m_u_T) + ' ' + ANY_TO_STR(m_u_H) + ' '
    + ANY_TO_STR(m_u_W) + '\n';
  return string;
}

void AfeDor::AfeDorImpl::readDetails(Reader& input)
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

int AfeDor::AfeDorImpl::nr() const
{
  return m_nr;
}

void AfeDor::AfeDorImpl::setNr(const int nr)
{
  m_nr = nr;
}

int AfeDor::AfeDorImpl::icon() const
{
  return m_icon;
}

void AfeDor::AfeDorImpl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string AfeDor::AfeDorImpl::name() const
{
  return m_name;
}

void AfeDor::AfeDorImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string AfeDor::AfeDorImpl::desc() const
{
  return m_desc;
}

void AfeDor::AfeDorImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double AfeDor::AfeDorImpl::lam() const
{
  return to<double>(m_lam);
}

bool AfeDor::AfeDorImpl::setLam(const double lam)
{
  m_lam = to_float(lam);
  return true;
}

bool AfeDor::AfeDorImpl::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_lam);
}

double AfeDor::AfeDorImpl::turb() const
{
  return to<double>(m_turb);
}

bool AfeDor::AfeDorImpl::setTurb(const double turb)
{
  m_turb = to_float(turb);
  return true;
}

bool AfeDor::AfeDorImpl::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_turb);
}

double AfeDor::AfeDorImpl::expt() const
{
  return to<double>(m_expt);
}

bool AfeDor::AfeDorImpl::setExpt(const double expt)
{
  m_expt = to_float(expt);
  return true;
}

bool AfeDor::AfeDorImpl::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_expt);
}

double AfeDor::AfeDorImpl::dTmin() const
{
  return to<double>(m_dTmin);
}

bool AfeDor::AfeDorImpl::setDTmin(const double dTmin)
{
  m_dTmin = to_float(dTmin);
  return true;
}

bool AfeDor::AfeDorImpl::setDTmin(const std::string& dTmin)
{
  return assign_if_valid<double>(dTmin, m_dTmin);
}

double AfeDor::AfeDorImpl::height() const
{
  return to<double>(m_ht);
}

bool AfeDor::AfeDorImpl::setHeight(const double ht)
{
  m_ht = to_float(ht);
  return true;
}

bool AfeDor::AfeDorImpl::setHeight(const std::string& ht)
{
  return assign_if_valid<double>(ht, m_ht);
}

double AfeDor::AfeDorImpl::width() const
{
  return to<double>(m_wd);
}

bool AfeDor::AfeDorImpl::setWidth(const double wd)
{
  m_wd = to_float(wd);
  return true;
}

bool AfeDor::AfeDorImpl::setWidth(const std::string& wd)
{
  return assign_if_valid<double>(wd, m_wd);
}

double AfeDor::AfeDorImpl::cd() const
{
  return to<double>(m_cd);
}

bool AfeDor::AfeDorImpl::setCd(const double cd)
{
  m_cd = to_float(cd);
  return true;
}

bool AfeDor::AfeDorImpl::setCd(const std::string& cd)
{
  return assign_if_valid<double>(cd, m_cd);
}

int AfeDor::AfeDorImpl::u_T() const
{
  return m_u_T;
}

void AfeDor::AfeDorImpl::setU_T(const int u_T)
{
  m_u_T = u_T;
}

int AfeDor::AfeDorImpl::u_H() const
{
  return m_u_H;
}

void AfeDor::AfeDorImpl::setU_H(const int u_H)
{
  m_u_H = u_H;
}

int AfeDor::AfeDorImpl::u_W() const
{
  return m_u_W;
}

void AfeDor::AfeDorImpl::setU_W(const int u_W)
{
  m_u_W = u_W;
}

DrPl2::DrPl2() :
  m_impl(std::shared_ptr<DrPl2Impl>(new DrPl2Impl))
{}

DrPl2::DrPl2(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<DrPl2Impl>(new DrPl2Impl(nr,icon,name,desc)))
{}

DrPl2::DrPl2(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt,double dH,double ht,
             double wd,double cd,int u_H,int u_W) :
  m_impl(std::shared_ptr<DrPl2Impl>(new DrPl2Impl(nr,icon,name,desc,lam,turb,expt,dH,ht,wd,cd,u_H,u_W)))
{}

DrPl2::DrPl2(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt,std::string dH,std::string ht,
             std::string wd,std::string cd,int u_H,int u_W) :
  m_impl(std::shared_ptr<DrPl2Impl>(new DrPl2Impl(nr,icon,name,desc,lam,turb,expt,dH,ht,wd,cd,u_H,u_W)))
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

std::string DrPl2::write()
{
  return m_impl->write();
}

void DrPl2::read(Reader &input)
{
  m_impl->read(input);
}

void DrPl2::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int DrPl2::nr() const
{
  return m_impl->nr();
}

void DrPl2::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int DrPl2::icon() const
{
  return m_impl->icon();
}

void DrPl2::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string DrPl2::name() const
{
  return m_impl->name();
}

void DrPl2::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string DrPl2::desc() const
{
  return m_impl->desc();
}

void DrPl2::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double DrPl2::lam() const
{
  return m_impl->lam();
}

bool DrPl2::setLam(const double lam)
{
  return m_impl->setLam(lam);
}

bool DrPl2::setLam(const std::string &lam)
{
  return m_impl->setLam(lam);
}

double DrPl2::turb() const
{
  return m_impl->turb();
}

bool DrPl2::setTurb(const double turb)
{
  return m_impl->setTurb(turb);
}

bool DrPl2::setTurb(const std::string &turb)
{
  return m_impl->setTurb(turb);
}

double DrPl2::expt() const
{
  return m_impl->expt();
}

bool DrPl2::setExpt(const double expt)
{
  return m_impl->setExpt(expt);
}

bool DrPl2::setExpt(const std::string &expt)
{
  return m_impl->setExpt(expt);
}

double DrPl2::dH() const
{
  return m_impl->dH();
}

bool DrPl2::setDH(const double dH)
{
  return m_impl->setDH(dH);
}

bool DrPl2::setDH(const std::string &dH)
{
  return m_impl->setDH(dH);
}

double DrPl2::height() const
{
  return m_impl->height();
}

bool DrPl2::setHeight(const double ht)
{
  return m_impl->setHeight(ht);
}

bool DrPl2::setHeight(const std::string &ht)
{
  return m_impl->setHeight(ht);
}

double DrPl2::width() const
{
  return m_impl->width();
}

bool DrPl2::setWidth(const double wd)
{
  return m_impl->setWidth(wd);
}

bool DrPl2::setWidth(const std::string &wd)
{
  return m_impl->setWidth(wd);
}

double DrPl2::cd() const
{
  return m_impl->cd();
}

bool DrPl2::setCd(const double cd)
{
  return m_impl->setCd(cd);
}

bool DrPl2::setCd(const std::string &cd)
{
  return m_impl->setCd(cd);
}

int DrPl2::u_H() const
{
  return m_impl->u_H();
}

void DrPl2::setU_H(const int u_H)
{
  m_impl->setU_H(u_H);
}

int DrPl2::u_W() const
{
  return m_impl->u_W();
}

void DrPl2::setU_W(const int u_W)
{
  m_impl->setU_W(u_W);
}

DrPl2::DrPl2Impl::DrPl2Impl() : m_nr(0), m_icon(0), m_lam(PRJFLOAT("0.0")), m_turb(PRJFLOAT("0.0")), m_expt(PRJFLOAT("0.0")),
m_dH(PRJFLOAT("0.0")), m_ht(PRJFLOAT("0.0")), m_wd(PRJFLOAT("0.0")), m_cd(PRJFLOAT("0.0")), m_u_H(0), m_u_W(0)
{}

DrPl2::DrPl2Impl::DrPl2Impl(int nr, int icon, std::string name, std::string desc) : DrPl2::DrPl2Impl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

DrPl2::DrPl2Impl::DrPl2Impl(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt, double dH,
  double ht, double wd, double cd, int u_H, int u_W) : DrPl2::DrPl2Impl()
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

DrPl2::DrPl2Impl::DrPl2Impl(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt, std::string dH,
  std::string ht, std::string wd, std::string cd, int u_H, int u_W) : DrPl2::DrPl2Impl()
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

void DrPl2::DrPl2Impl::read(Reader& input)
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

std::string DrPl2::DrPl2Impl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + " dor_pl2 " + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_lam) + ' ' + PRJFLOAT_TO_STR(m_turb) + ' ' + PRJFLOAT_TO_STR(m_expt) + ' '
    + PRJFLOAT_TO_STR(m_dH) + ' ' + PRJFLOAT_TO_STR(m_ht) + ' ' + PRJFLOAT_TO_STR(m_wd) + ' ' + PRJFLOAT_TO_STR(m_cd)
    + ' ' + ANY_TO_STR(m_u_H) + ' ' + ANY_TO_STR(m_u_W) + '\n';
  return string;
}

void DrPl2::DrPl2Impl::readDetails(Reader& input)
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

int DrPl2::DrPl2Impl::nr() const
{
  return m_nr;
}

void DrPl2::DrPl2Impl::setNr(const int nr)
{
  m_nr = nr;
}

int DrPl2::DrPl2Impl::icon() const
{
  return m_icon;
}

void DrPl2::DrPl2Impl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string DrPl2::DrPl2Impl::name() const
{
  return m_name;
}

void DrPl2::DrPl2Impl::setName(const std::string& name)
{
  m_name = name;
}

std::string DrPl2::DrPl2Impl::desc() const
{
  return m_desc;
}

void DrPl2::DrPl2Impl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double DrPl2::DrPl2Impl::lam() const
{
  return to<double>(m_lam);
}

bool DrPl2::DrPl2Impl::setLam(const double lam)
{
  m_lam = to_float(lam);
  return true;
}

bool DrPl2::DrPl2Impl::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_lam);
}

double DrPl2::DrPl2Impl::turb() const
{
  return to<double>(m_turb);
}

bool DrPl2::DrPl2Impl::setTurb(const double turb)
{
  m_turb = to_float(turb);
  return true;
}

bool DrPl2::DrPl2Impl::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_turb);
}

double DrPl2::DrPl2Impl::expt() const
{
  return to<double>(m_expt);
}

bool DrPl2::DrPl2Impl::setExpt(const double expt)
{
  m_expt = to_float(expt);
  return true;
}

bool DrPl2::DrPl2Impl::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_expt);
}

double DrPl2::DrPl2Impl::dH() const
{
  return to<double>(m_dH);
}

bool DrPl2::DrPl2Impl::setDH(const double dH)
{
  m_dH = to_float(dH);
  return true;
}

bool DrPl2::DrPl2Impl::setDH(const std::string& dH)
{
  return assign_if_valid<double>(dH, m_dH);
}

double DrPl2::DrPl2Impl::height() const
{
  return to<double>(m_ht);
}

bool DrPl2::DrPl2Impl::setHeight(const double ht)
{
  m_ht = to_float(ht);
  return true;
}

bool DrPl2::DrPl2Impl::setHeight(const std::string& ht)
{
  return assign_if_valid<double>(ht, m_ht);
}

double DrPl2::DrPl2Impl::width() const
{
  return to<double>(m_wd);
}

bool DrPl2::DrPl2Impl::setWidth(const double wd)
{
  m_wd = to_float(wd);
  return true;
}

bool DrPl2::DrPl2Impl::setWidth(const std::string& wd)
{
  return assign_if_valid<double>(wd, m_wd);
}

double DrPl2::DrPl2Impl::cd() const
{
  return to<double>(m_cd);
}

bool DrPl2::DrPl2Impl::setCd(const double cd)
{
  m_cd = to_float(cd);
  return true;
}

bool DrPl2::DrPl2Impl::setCd(const std::string& cd)
{
  return assign_if_valid<double>(cd, m_cd);
}

int DrPl2::DrPl2Impl::u_H() const
{
  return m_u_H;
}

void DrPl2::DrPl2Impl::setU_H(const int u_H)
{
  m_u_H = u_H;
}

int DrPl2::DrPl2Impl::u_W() const
{
  return m_u_W;
}

void DrPl2::DrPl2Impl::setU_W(const int u_W)
{
  m_u_W = u_W;
}

AfeFlow::AfeFlow() :
  m_impl(std::shared_ptr<AfeFlowImpl>(new AfeFlowImpl))
{}

AfeFlow::AfeFlow(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<AfeFlowImpl>(new AfeFlowImpl(nr,icon,name,desc)))
{}

AfeFlow::AfeFlow(int nr,int icon,std::string name,std::string desc,double Flow,int u_F) :
  m_impl(std::shared_ptr<AfeFlowImpl>(new AfeFlowImpl(nr,icon,name,desc,Flow,u_F)))
{}

AfeFlow::AfeFlow(int nr,int icon,std::string name,std::string desc,std::string Flow,int u_F) :
  m_impl(std::shared_ptr<AfeFlowImpl>(new AfeFlowImpl(nr,icon,name,desc,Flow,u_F)))
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

std::string AfeFlow::write()
{
  return m_impl->write(dataType());
}

void AfeFlow::read(Reader &input)
{
  m_impl->read(input);
}

void AfeFlow::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int AfeFlow::nr() const
{
  return m_impl->nr();
}

void AfeFlow::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int AfeFlow::icon() const
{
  return m_impl->icon();
}

void AfeFlow::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string AfeFlow::name() const
{
  return m_impl->name();
}

void AfeFlow::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string AfeFlow::desc() const
{
  return m_impl->desc();
}

void AfeFlow::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double AfeFlow::Flow() const
{
  return m_impl->Flow();
}

bool AfeFlow::setFlow(const double Flow)
{
  return m_impl->setFlow(Flow);
}

bool AfeFlow::setFlow(const std::string &Flow)
{
  return m_impl->setFlow(Flow);
}

int AfeFlow::u_F() const
{
  return m_impl->u_F();
}

void AfeFlow::setU_F(const int u_F)
{
  m_impl->setU_F(u_F);
}

AfeFlow::AfeFlowImpl::AfeFlowImpl() : m_nr(0), m_icon(0), m_Flow(PRJFLOAT("0.0")), m_u_F(0)
{}

AfeFlow::AfeFlowImpl::AfeFlowImpl(int nr, int icon, std::string name, std::string desc) : AfeFlow::AfeFlowImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

AfeFlow::AfeFlowImpl::AfeFlowImpl(int nr, int icon, std::string name, std::string desc, double Flow, int u_F) : AfeFlow::AfeFlowImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setFlow(Flow);
  setU_F(u_F);
}

AfeFlow::AfeFlowImpl::AfeFlowImpl(int nr, int icon, std::string name, std::string desc, std::string Flow, int u_F) : AfeFlow::AfeFlowImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setFlow(Flow);
  setU_F(u_F);
}

void AfeFlow::AfeFlowImpl::read(Reader& input)
{
  setNr(input.read<int>());
  setIcon(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setName(input.readString());
  setDesc(input.readLine());
  setFlow(input.readNumber<std::string>());
  setU_F(input.read<int>());
}

std::string AfeFlow::AfeFlowImpl::write(std::string dataType)
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + ' ' + dataType + ' ' + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_Flow) + ' ' + ANY_TO_STR(m_u_F) + '\n';
  return string;
}

void AfeFlow::AfeFlowImpl::readDetails(Reader& input)
{
  setFlow(input.readNumber<std::string>());
  setU_F(input.read<int>());
}

int AfeFlow::AfeFlowImpl::nr() const
{
  return m_nr;
}

void AfeFlow::AfeFlowImpl::setNr(const int nr)
{
  m_nr = nr;
}

int AfeFlow::AfeFlowImpl::icon() const
{
  return m_icon;
}

void AfeFlow::AfeFlowImpl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string AfeFlow::AfeFlowImpl::name() const
{
  return m_name;
}

void AfeFlow::AfeFlowImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string AfeFlow::AfeFlowImpl::desc() const
{
  return m_desc;
}

void AfeFlow::AfeFlowImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double AfeFlow::AfeFlowImpl::Flow() const
{
  return to<double>(m_Flow);
}

bool AfeFlow::AfeFlowImpl::setFlow(const double Flow)
{
  m_Flow = to_float(Flow);
  return true;
}

bool AfeFlow::AfeFlowImpl::setFlow(const std::string& Flow)
{
  return assign_if_valid<double>(Flow, m_Flow);
}

int AfeFlow::AfeFlowImpl::u_F() const
{
  return m_u_F;
}

void AfeFlow::AfeFlowImpl::setU_F(const int u_F)
{
  m_u_F = u_F;
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
  m_impl(std::shared_ptr<AfeFanImpl>(new AfeFanImpl))
{}

AfeFan::AfeFan(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<AfeFanImpl>(new AfeFanImpl(nr,icon,name,desc)))
{}

AfeFan::AfeFan(int nr,int icon,std::string name,std::string desc,double lam,double turb,double expt,double rdens,
               double fdf,double sop,double off,std::vector<double> fpc,double Sarea,int u_Sa,
               std::vector<FanDataPoint> data) :
  m_impl(std::shared_ptr<AfeFanImpl>(new AfeFanImpl(nr,icon,name,desc,lam,turb,expt,rdens,fdf,sop,off,fpc,Sarea,u_Sa,data)))
{}

AfeFan::AfeFan(int nr,int icon,std::string name,std::string desc,std::string lam,std::string turb,std::string expt,std::string rdens,
               std::string fdf,std::string sop,std::string off,std::vector<std::string> fpc,std::string Sarea,int u_Sa,
               std::vector<FanDataPoint> data) :
  m_impl(std::shared_ptr<AfeFanImpl>(new AfeFanImpl(nr,icon,name,desc,lam,turb,expt,rdens,fdf,sop,off,fpc,Sarea,u_Sa,data)))
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

std::string AfeFan::write()
{
  return m_impl->write();
}

void AfeFan::read(Reader &input)
{
  m_impl->read(input);
}

void AfeFan::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int AfeFan::nr() const
{
  return m_impl->nr();
}

void AfeFan::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int AfeFan::icon() const
{
  return m_impl->icon();
}

void AfeFan::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string AfeFan::name() const
{
  return m_impl->name();
}

void AfeFan::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string AfeFan::desc() const
{
  return m_impl->desc();
}

void AfeFan::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

double AfeFan::lam() const
{
  return m_impl->lam();
}

bool AfeFan::setLam(const double lam)
{
  return m_impl->setLam(lam);
}

bool AfeFan::setLam(const std::string &lam)
{
  return m_impl->setLam(lam);
}

double AfeFan::turb() const
{
  return m_impl->turb();
}

bool AfeFan::setTurb(const double turb)
{
  return m_impl->setTurb(turb);
}

bool AfeFan::setTurb(const std::string &turb)
{
  return m_impl->setTurb(turb);
}

double AfeFan::expt() const
{
  return m_impl->expt();
}

bool AfeFan::setExpt(const double expt)
{
  return m_impl->setExpt(expt);
}

bool AfeFan::setExpt(const std::string &expt)
{
  return m_impl->setExpt(expt);
}

double AfeFan::rdens() const
{
  return m_impl->rdens();
}

bool AfeFan::setRdens(const double rdens)
{
  return m_impl->setRdens(rdens);
}

bool AfeFan::setRdens(const std::string &rdens)
{
  return m_impl->setRdens(rdens);
}

double AfeFan::fdf() const
{
  return m_impl->fdf();
}

bool AfeFan::setFdf(const double fdf)
{
  return m_impl->setFdf(fdf);
}

bool AfeFan::setFdf(const std::string &fdf)
{
  return m_impl->setFdf(fdf);
}

double AfeFan::sop() const
{
  return m_impl->sop();
}

bool AfeFan::setSop(const double sop)
{
  return m_impl->setSop(sop);
}

bool AfeFan::setSop(const std::string &sop)
{
  return m_impl->setSop(sop);
}

double AfeFan::off() const
{
  return m_impl->off();
}

bool AfeFan::setOff(const double off)
{
  return m_impl->setOff(off);
}

bool AfeFan::setOff(const std::string &off)
{
  return m_impl->setOff(off);
}

std::vector<double> AfeFan::fpc() const
{
  return m_impl->fpc();
}

bool AfeFan::setFpc(const std::vector<double> &fpc)
{
  return m_impl->setFpc(fpc);
}

bool AfeFan::setFpc(const std::vector<std::string> &fpc)
{
  return m_impl->setFpc(fpc);
}

double AfeFan::Sarea() const
{
  return m_impl->Sarea();
}

bool AfeFan::setSarea(const double Sarea)
{
  return m_impl->setSarea(Sarea);
}

bool AfeFan::setSarea(const std::string &Sarea)
{
  return m_impl->setSarea(Sarea);
}

int AfeFan::u_Sa() const
{
  return m_impl->u_Sa();
}

void AfeFan::setU_Sa(const int u_Sa)
{
  m_impl->setU_Sa(u_Sa);
}

std::vector<FanDataPoint> AfeFan::data() const
{
  return m_impl->data();
}

void AfeFan::setData(const std::vector<FanDataPoint> &data)
{
  m_impl->setData(data);
}

AfeFan::AfeFanImpl::AfeFanImpl() : m_nr(0), m_icon(0), m_lam(PRJFLOAT("0.0")), m_turb(PRJFLOAT("0.0")), m_expt(PRJFLOAT("0.0")),
m_rdens(PRJFLOAT("0.0")), m_fdf(PRJFLOAT("0.0")), m_sop(PRJFLOAT("0.0")), m_off(PRJFLOAT("0.0")), m_Sarea(PRJFLOAT("0.0")), m_u_Sa(0)
{}

AfeFan::AfeFanImpl::AfeFanImpl(int nr, int icon, std::string name, std::string desc) : AfeFan::AfeFanImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

AfeFan::AfeFanImpl::AfeFanImpl(int nr, int icon, std::string name, std::string desc, double lam, double turb, double expt,
  double rdens, double fdf, double sop, double off, std::vector<double> fpc, double Sarea,
  int u_Sa, std::vector<FanDataPoint> data) : AfeFan::AfeFanImpl()
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

AfeFan::AfeFanImpl::AfeFanImpl(int nr, int icon, std::string name, std::string desc, std::string lam, std::string turb, std::string expt,
  std::string rdens, std::string fdf, std::string sop, std::string off, std::vector<std::string> fpc, std::string Sarea,
  int u_Sa, std::vector<FanDataPoint> data) : AfeFan::AfeFanImpl()
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

void AfeFan::AfeFanImpl::read(Reader& input)
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

std::string AfeFan::AfeFanImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + " fan_fan " + m_name + '\n';
  string += m_desc + '\n';
  string += PRJFLOAT_TO_STR(m_lam) + ' ' + PRJFLOAT_TO_STR(m_turb) + ' ' + PRJFLOAT_TO_STR(m_expt) + ' ' + PRJFLOAT_TO_STR(m_rdens)
    + ' ' + PRJFLOAT_TO_STR(m_fdf) + ' ' + PRJFLOAT_TO_STR(m_sop) + ' ' + PRJFLOAT_TO_STR(m_off) + '\n';
  for (int i = 0; i < 4; i++)
    string += PRJFLOAT_TO_STR(m_fpc[i]) + ' ';
  string += '\n';
  string += ANY_TO_STR((int)m_data.size()) + ' ' + PRJFLOAT_TO_STR(m_Sarea) + ' ' + ANY_TO_STR(m_u_Sa) + '\n';
  for (unsigned int i = 0; i < m_data.size(); i++) {
    string += m_data[i].write();
  }
  return string;
}

void AfeFan::AfeFanImpl::readDetails(Reader& input)
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

int AfeFan::AfeFanImpl::nr() const
{
  return m_nr;
}

void AfeFan::AfeFanImpl::setNr(const int nr)
{
  m_nr = nr;
}

int AfeFan::AfeFanImpl::icon() const
{
  return m_icon;
}

void AfeFan::AfeFanImpl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string AfeFan::AfeFanImpl::name() const
{
  return m_name;
}

void AfeFan::AfeFanImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string AfeFan::AfeFanImpl::desc() const
{
  return m_desc;
}

void AfeFan::AfeFanImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

double AfeFan::AfeFanImpl::lam() const
{
  return to<double>(m_lam);
}

bool AfeFan::AfeFanImpl::setLam(const double lam)
{
  m_lam = to_float(lam);
  return true;
}

bool AfeFan::AfeFanImpl::setLam(const std::string& lam)
{
  return assign_if_valid<double>(lam, m_lam);
}

double AfeFan::AfeFanImpl::turb() const
{
  return to<double>(m_turb);
}

bool AfeFan::AfeFanImpl::setTurb(const double turb)
{
  m_turb = to_float(turb);
  return true;
}

bool AfeFan::AfeFanImpl::setTurb(const std::string& turb)
{
  return assign_if_valid<double>(turb, m_turb);
}

double AfeFan::AfeFanImpl::expt() const
{
  return to<double>(m_expt);
}

bool AfeFan::AfeFanImpl::setExpt(const double expt)
{
  m_expt = to_float(expt);
  return true;
}

bool AfeFan::AfeFanImpl::setExpt(const std::string& expt)
{
  return assign_if_valid<double>(expt, m_expt);
}

double AfeFan::AfeFanImpl::rdens() const
{
  return to<double>(m_rdens);
}

bool AfeFan::AfeFanImpl::setRdens(const double rdens)
{
  m_rdens = to_float(rdens);
  return true;
}

bool AfeFan::AfeFanImpl::setRdens(const std::string& rdens)
{
  return assign_if_valid<double>(rdens, m_rdens);
}

double AfeFan::AfeFanImpl::fdf() const
{
  return to<double>(m_fdf);
}

bool AfeFan::AfeFanImpl::setFdf(const double fdf)
{
  m_fdf = to_float(fdf);
  return true;
}

bool AfeFan::AfeFanImpl::setFdf(const std::string& fdf)
{
  return assign_if_valid<double>(fdf, m_fdf);
}

double AfeFan::AfeFanImpl::sop() const
{
  return to<double>(m_sop);
}

bool AfeFan::AfeFanImpl::setSop(const double sop)
{
  m_sop = to_float(sop);
  return true;
}

bool AfeFan::AfeFanImpl::setSop(const std::string& sop)
{
  return assign_if_valid<double>(sop, m_sop);
}

double AfeFan::AfeFanImpl::off() const
{
  return to<double>(m_off);
}

bool AfeFan::AfeFanImpl::setOff(const double off)
{
  m_off = to_float(off);
  return true;
}

bool AfeFan::AfeFanImpl::setOff(const std::string& off)
{
  return assign_if_valid<double>(off, m_off);
}

std::vector<double> AfeFan::AfeFanImpl::fpc() const
{
  std::vector<double> out;
  for (int i = 0; i < 4; i++) {
    out.push_back(to<double>(m_fpc[i]));
  }
  return out;
}

bool AfeFan::AfeFanImpl::setFpc(const std::vector<double>& fpc)
{
  for (int i = 0; i < 4; i++) {
    m_fpc.push_back(to_float(fpc[i]));
  }
  return true;
}

bool AfeFan::AfeFanImpl::setFpc(const std::vector<std::string>& fpc)
{
  if (std::all_of(fpc.begin(), fpc.end(), is_valid<double, std::string>)) {
    m_fpc = fpc;
    return true;
  } else {
    return false;
  }
}

double AfeFan::AfeFanImpl::Sarea() const
{
  return to<double>(m_Sarea);
}

bool AfeFan::AfeFanImpl::setSarea(const double Sarea)
{
  m_Sarea = to_float(Sarea);
  return true;
}

bool AfeFan::AfeFanImpl::setSarea(const std::string& Sarea)
{
  return assign_if_valid<double>(Sarea, m_Sarea);
}

int AfeFan::AfeFanImpl::u_Sa() const
{
  return m_u_Sa;
}

void AfeFan::AfeFanImpl::setU_Sa(const int u_Sa)
{
  m_u_Sa = u_Sa;
}

std::vector<FanDataPoint> AfeFan::AfeFanImpl::data() const
{
  return m_data;
}

void AfeFan::AfeFanImpl::setData(const std::vector<FanDataPoint>& data)
{
  m_data = data;
}

AfeCsf::AfeCsf() :
  m_impl(std::shared_ptr<AfeCsfImpl>(new AfeCsfImpl()))
{}

AfeCsf::AfeCsf(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<AfeCsfImpl>(new AfeCsfImpl(nr,icon,name,desc)))
{}

AfeCsf::AfeCsf(int nr,int icon,std::string name,std::string desc,int u_x,int u_y,std::vector<XyDataPoint> data) :
  m_impl(std::shared_ptr<AfeCsfImpl>(new AfeCsfImpl(nr,icon,name,desc,u_x,u_y,data)))
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

std::string AfeCsf::write()
{
  return m_impl->write(dataType());
}

void AfeCsf::read(Reader &input)
{
  m_impl->read(input);
}

void AfeCsf::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int AfeCsf::nr() const
{
  return m_impl->nr();
}

void AfeCsf::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int AfeCsf::icon() const
{
  return m_impl->icon();
}

void AfeCsf::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string AfeCsf::name() const
{
  return m_impl->name();
}

void AfeCsf::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string AfeCsf::desc() const
{
  return m_impl->desc();
}

void AfeCsf::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

int AfeCsf::u_x() const
{
  return m_impl->u_x();
}

void AfeCsf::setU_x(const int u_x)
{
  m_impl->setU_x(u_x);
}

int AfeCsf::u_y() const
{
  return m_impl->u_y();
}

void AfeCsf::setU_y(const int u_y)
{
  m_impl->setU_y(u_y);
}

std::vector<XyDataPoint> AfeCsf::data() const
{
  return m_impl->data();
}

void AfeCsf::setData(const std::vector<XyDataPoint> &data)
{
  m_impl->setData(data);
}

AfeCsf::AfeCsfImpl::AfeCsfImpl() : m_nr(0), m_icon(0), m_u_x(0), m_u_y(0)
{}

AfeCsf::AfeCsfImpl::AfeCsfImpl(int nr, int icon, std::string name, std::string desc) : AfeCsf::AfeCsfImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

AfeCsf::AfeCsfImpl::AfeCsfImpl(int nr, int icon, std::string name, std::string desc, int u_x, int u_y,
  std::vector<XyDataPoint> data) : AfeCsf::AfeCsfImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setU_x(u_x);
  setU_y(u_y);
  setData(data);
}

void AfeCsf::AfeCsfImpl::read(Reader& input)
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
    m_data.push_back(object);
  }
}

void AfeCsf::AfeCsfImpl::readDetails(Reader& input)
{
  int npts = input.read<int>();
  setU_x(input.read<int>());
  setU_y(input.read<int>());
  for (int i = 0; i < npts; i++) {
    XyDataPoint object;
    object.read(input);
    m_data.push_back(object);
  }

}

std::string AfeCsf::AfeCsfImpl::write(std::string datatype)
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + ' ' + datatype + ' ' + m_name + '\n';
  string += m_desc + '\n';
  string += ANY_TO_STR((int)m_data.size()) + ' ' + ANY_TO_STR(m_u_x) + ' ' + ANY_TO_STR(m_u_y) + '\n';
  for (unsigned int i = 0; i < m_data.size(); i++) {
    string += m_data[i].write();
  }
  return string;
}

int AfeCsf::AfeCsfImpl::nr() const
{
  return m_nr;
}

void AfeCsf::AfeCsfImpl::setNr(const int nr)
{
  m_nr = nr;
}

int AfeCsf::AfeCsfImpl::icon() const
{
  return m_icon;
}

void AfeCsf::AfeCsfImpl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string AfeCsf::AfeCsfImpl::name() const
{
  return m_name;
}

void AfeCsf::AfeCsfImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string AfeCsf::AfeCsfImpl::desc() const
{
  return m_desc;
}

void AfeCsf::AfeCsfImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

int AfeCsf::AfeCsfImpl::u_x() const
{
  return m_u_x;
}

void AfeCsf::AfeCsfImpl::setU_x(const int u_x)
{
  m_u_x = u_x;
}

int AfeCsf::AfeCsfImpl::u_y() const
{
  return m_u_y;
}

void AfeCsf::AfeCsfImpl::setU_y(const int u_y)
{
  m_u_y = u_y;
}

std::vector<XyDataPoint> AfeCsf::AfeCsfImpl::data() const
{
  return m_data;
}

void AfeCsf::AfeCsfImpl::setData(const std::vector<XyDataPoint>& data)
{
  m_data = data;
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
  m_impl(std::shared_ptr<AfeSupImpl>(new AfeSupImpl))
{}

AfeSup::AfeSup(int nr,int icon,std::string name,std::string desc) :
  m_impl(std::shared_ptr<AfeSupImpl>(new AfeSupImpl(nr,icon,name,desc)))
{}

AfeSup::AfeSup(int nr,int icon,std::string name,std::string desc,int sched,int u_H,
               std::vector<AirflowSubelementData> subelements) :
  m_impl(std::shared_ptr<AfeSupImpl>(new AfeSupImpl(nr,icon,name,desc,sched,u_H,subelements)))
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

std::string AfeSup::write()
{
  return m_impl->write();
}

void AfeSup::read(Reader &input)
{
  m_impl->read(input);
}

void AfeSup::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int AfeSup::nr() const
{
  return m_impl->nr();
}

void AfeSup::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int AfeSup::icon() const
{
  return m_impl->icon();
}

void AfeSup::setIcon(const int icon)
{
  m_impl->setIcon(icon);
}

std::string AfeSup::name() const
{
  return m_impl->name();
}

void AfeSup::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string AfeSup::desc() const
{
  return m_impl->desc();
}

void AfeSup::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

int AfeSup::sched() const
{
  return m_impl->sched();
}

void AfeSup::setSched(const int sched)
{
  m_impl->setSched(sched);
}

int AfeSup::u_H() const
{
  return m_impl->u_H();
}

void AfeSup::setU_H(const int u_H)
{
  m_impl->setU_H(u_H);
}

std::vector<AirflowSubelementData> AfeSup::subelements() const
{
  return m_impl->subelements();
}

void AfeSup::setSubelements(const std::vector<AirflowSubelementData> &subelements)
{
  m_impl->setSubelements(subelements);
}

AfeSup::AfeSupImpl::AfeSupImpl() : m_nr(0), m_icon(0), m_sched(0), m_u_H(0)
{}

AfeSup::AfeSupImpl::AfeSupImpl(int nr, int icon, std::string name, std::string desc) : AfeSup::AfeSupImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
}

AfeSup::AfeSupImpl::AfeSupImpl(int nr, int icon, std::string name, std::string desc, int sched, int u_H,
  std::vector<AirflowSubelementData> subelements) : AfeSup::AfeSupImpl()
{
  setNr(nr);
  setIcon(icon);
  setName(name);
  setDesc(desc);
  setSched(sched);
  setU_H(u_H);
  setSubelements(subelements);
}

void AfeSup::AfeSupImpl::read(Reader& input)
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

std::string AfeSup::AfeSupImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_icon) + " sup_afe " + m_name + '\n';
  string += m_desc + '\n';
  string += ANY_TO_STR((int)m_subelements.size()) + ' ' + ANY_TO_STR(m_sched) + ' ' + ANY_TO_STR(m_u_H) + '\n';
  for (unsigned int i = 0; i < m_subelements.size(); i++) {
    string += m_subelements[i].write();
  }
  return string;
}

void AfeSup::AfeSupImpl::readDetails(Reader& input)
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

int AfeSup::AfeSupImpl::nr() const
{
  return m_nr;
}

void AfeSup::AfeSupImpl::setNr(const int nr)
{
  m_nr = nr;
}

int AfeSup::AfeSupImpl::icon() const
{
  return m_icon;
}

void AfeSup::AfeSupImpl::setIcon(const int icon)
{
  m_icon = icon;
}

std::string AfeSup::AfeSupImpl::name() const
{
  return m_name;
}

void AfeSup::AfeSupImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string AfeSup::AfeSupImpl::desc() const
{
  return m_desc;
}

void AfeSup::AfeSupImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

int AfeSup::AfeSupImpl::sched() const
{
  return m_sched;
}

void AfeSup::AfeSupImpl::setSched(const int sched)
{
  m_sched = sched;
}

int AfeSup::AfeSupImpl::u_H() const
{
  return m_u_H;
}

void AfeSup::AfeSupImpl::setU_H(const int u_H)
{
  m_u_H = u_H;
}

std::vector<AirflowSubelementData> AfeSup::AfeSupImpl::subelements() const
{
  return m_subelements;
}

void AfeSup::AfeSupImpl::setSubelements(const std::vector<AirflowSubelementData>& subelements)
{
  m_subelements = subelements;
}

} // prjmodel
