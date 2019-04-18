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

#include "PrjObjects.hpp"

#include "../src/logging.hpp"

#include <algorithm>

namespace prjmodel {

Zone::Zone() :
  m_impl(std::shared_ptr<ZoneImpl>(new ZoneImpl()))
{}

Zone::Zone(unsigned flags, std::string Vol, std::string T0, std::string name) :
  m_impl(std::shared_ptr<ZoneImpl>(new ZoneImpl))
{
  m_impl->setFlags(flags);
  m_impl->setVol(Vol);
  m_impl->setT0(T0);
  m_impl->setName(name);
}

Zone::Zone(unsigned flags, double Vol, double T0, std::string name) :
  m_impl(std::shared_ptr<ZoneImpl>(new ZoneImpl))
{
  m_impl->setFlags(flags);
  m_impl->setVol(Vol);
  m_impl->setT0(T0);
  m_impl->setName(name);
}

Zone::Zone(int nr,unsigned int flags,int ps,int pc,int pk,int pl,std::string relHt,std::string Vol,std::string T0,std::string P0,
  std::string name,int color,int u_Ht,int u_V,int u_T,int u_P,int cdaxis,int cfd,std::string cfdname,std::string X1,
  std::string Y1,std::string H1,std::string X2,std::string Y2,std::string H2,std::string celldx,std::string axialD,int u_aD,int u_L) :
  m_impl(std::shared_ptr<ZoneImpl>(new ZoneImpl(nr,flags,ps,pc,pk,pl,relHt,Vol,T0,P0,name,color,u_Ht,u_V,u_T,u_P,cdaxis,cfd,cfdname,X1,
    Y1,H1,X2,Y2,H2,celldx,axialD,u_aD,u_L)))
{}

Zone::Zone(int nr,unsigned int flags,int ps,int pc,int pk,int pl,double relHt,double Vol,double T0,double P0,
  std::string name,int color,int u_Ht,int u_V,int u_T,int u_P,int cdaxis,int cfd,std::string cfdname,double X1,
  double Y1,double H1,double X2,double Y2,double H2,double celldx,double axialD,int u_aD,int u_L) :
  m_impl(std::shared_ptr<ZoneImpl>(new ZoneImpl(nr,flags,ps,pc,pk,pl,relHt,Vol,T0,P0,name,color,u_Ht,u_V,u_T,u_P,cdaxis,cfd,cfdname,X1,
    Y1,H1,X2,Y2,H2,celldx,axialD,u_aD,u_L)))
{}

Zone::Zone(const Zone &other) : m_impl(other.m_impl)
{}

Zone::~Zone()
{}

Zone& Zone::operator=(const Zone &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool Zone::operator==(const Zone &other) const
{
  return m_impl==other.m_impl;
}

bool Zone::operator!=(const Zone &other) const
{
  return m_impl!=other.m_impl;
}

int Zone::nr() const
{
  return m_impl->nr();
}

void Zone::setNr(const int nr)
{
  m_impl->setNr(nr);
}

unsigned int Zone::flags() const
{
  return m_impl->flags();
}

void Zone::setFlags(const unsigned int flags)
{
  m_impl->setFlags(flags);
}

int Zone::ps() const
{
  return m_impl->ps();
}

void Zone::setPs(const int ps)
{
  m_impl->setPs(ps);
}

int Zone::pc() const
{
  return m_impl->pc();
}

void Zone::setPc(const int pc)
{
  m_impl->setPc(pc);
}

int Zone::pk() const
{
  return m_impl->pk();
}

void Zone::setPk(const int pk)
{
  m_impl->setPk(pk);
}

int Zone::pl() const
{
  return m_impl->pl();
}

void Zone::setPl(const int pl)
{
  m_impl->setPl(pl);
}

double Zone::relHt() const
{
  return m_impl->relHt();
}

bool Zone::setRelHt(const double relHt)
{
  return m_impl->setRelHt(relHt);
}

bool Zone::setRelHt(const std::string &relHt)
{
  return m_impl->setRelHt(relHt);
}

double Zone::Vol() const
{
  return m_impl->Vol();
}

bool Zone::setVol(const double Vol)
{
  return m_impl->setVol(Vol);
}

bool Zone::setVol(const std::string &Vol)
{
  return m_impl->setVol(Vol);
}

double Zone::T0() const
{
  return m_impl->T0();
}

bool Zone::setT0(const double T0)
{
  return m_impl->setT0(T0);
}

bool Zone::setT0(const std::string &T0)
{
  return m_impl->setT0(T0);
}

double Zone::P0() const
{
  return m_impl->P0();
}

bool Zone::setP0(const double P0)
{
  return m_impl->setP0(P0);
}

bool Zone::setP0(const std::string &P0)
{
  return m_impl->setP0(P0);
}

std::string Zone::name() const
{
  return m_impl->name();
}

void Zone::setName(const std::string &name)
{
  m_impl->setName(name);
}

int Zone::color() const
{
  return m_impl->color();
}

void Zone::setColor(const int color)
{
  m_impl->setColor(color);
}

int Zone::u_Ht() const
{
  return m_impl->u_Ht();
}

void Zone::setU_Ht(const int u_Ht)
{
  m_impl->setU_Ht(u_Ht);
}

int Zone::u_V() const
{
  return m_impl->u_V();
}

void Zone::setU_V(const int u_V)
{
  m_impl->setU_V(u_V);
}

int Zone::u_T() const
{
  return m_impl->u_T();
}

void Zone::setU_T(const int u_T)
{
  m_impl->setU_T(u_T);
}

int Zone::u_P() const
{
  return m_impl->u_P();
}

void Zone::setU_P(const int u_P)
{
  m_impl->setU_P(u_P);
}

int Zone::cdaxis() const
{
  return m_impl->cdaxis();
}

void Zone::setCdaxis(const int cdaxis)
{
  m_impl->setCdaxis(cdaxis);
}

int Zone::cfd() const
{
  return m_impl->cfd();
}

void Zone::setCfd(const int cfd)
{
  m_impl->setCfd(cfd);
}

std::string Zone::cfdname() const
{
  return m_impl->cfdname();
}

void Zone::setCfdname(const std::string &cfdname)
{
  m_impl->setCfdname(cfdname);
}

double Zone::X1() const
{
  return m_impl->X1();
}

bool Zone::setX1(const double X1)
{
  return m_impl->setX1(X1);
}

bool Zone::setX1(const std::string &X1)
{
  return m_impl->setX1(X1);
}

double Zone::Y1() const
{
  return m_impl->Y1();
}

bool Zone::setY1(const double Y1)
{
  return m_impl->setY1(Y1);
}

bool Zone::setY1(const std::string &Y1)
{
  return m_impl->setY1(Y1);
}

double Zone::H1() const
{
  return m_impl->H1();
}

bool Zone::setH1(const double H1)
{
  return m_impl->setH1(H1);
}

bool Zone::setH1(const std::string &H1)
{
  return m_impl->setH1(H1);
}

double Zone::X2() const
{
  return m_impl->X2();
}

bool Zone::setX2(const double X2)
{
  return m_impl->setX2(X2);
}

bool Zone::setX2(const std::string &X2)
{
  return m_impl->setX2(X2);
}

double Zone::Y2() const
{
  return m_impl->Y2();
}

bool Zone::setY2(const double Y2)
{
  return m_impl->setY2(Y2);
}

bool Zone::setY2(const std::string &Y2)
{
  return m_impl->setY2(Y2);
}

double Zone::H2() const
{
  return m_impl->H2();
}

bool Zone::setH2(const double H2)
{
  return m_impl->setH2(H2);
}

bool Zone::setH2(const std::string &H2)
{
  return m_impl->setH2(H2);
}

double Zone::celldx() const
{
  return m_impl->celldx();
}

bool Zone::setCelldx(const double celldx)
{
  return m_impl->setCelldx(celldx);
}

bool Zone::setCelldx(const std::string &celldx)
{
  return m_impl->setCelldx(celldx);
}

double Zone::axialD() const
{
  return m_impl->axialD();
}

bool Zone::setAxialD(const double axialD)
{
  return m_impl->setAxialD(axialD);
}

bool Zone::setAxialD(const std::string &axialD)
{
  return m_impl->setAxialD(axialD);
}

int Zone::u_aD() const
{
  return m_impl->u_aD();
}

void Zone::setU_aD(const int u_aD)
{
  return m_impl->setU_aD(u_aD);
}

int Zone::u_L() const
{
  return m_impl->u_L();
}

void Zone::setU_L(const int u_L)
{
  return m_impl->setU_L(u_L);
}

std::string Zone::write()
{
  return m_impl->write();
}

void Zone::read(Reader &input)
{
  m_impl->read(input);
}

void Zone::setVariablePressure(bool b)
{
  m_impl->setVariablePressure(b);
}

bool Zone::variablePressure() const
{
  return m_impl->variablePressure();
}

void Zone::setVariableContaminants(bool b)
{
  m_impl->setVariableContaminants(b);
}

bool Zone::variableContaminants() const
{
  return m_impl->variableContaminants();
}

void Zone::setSystem(bool b)
{
  m_impl->setSystem(b);
}

bool Zone::system() const
{
  return m_impl->system();
}

double Zone::ic(const int i) const
{
  return m_impl->ic(i);
}

std::vector<double> Zone::ic() const
{
  return m_impl->ic();
}

bool Zone::setIc(const int i, const double value)
{
  return m_impl->setIc(i,value);
}

bool Zone::setIc(const int i, const std::string &value)
{
  return m_impl->setIc(i,value);
}

bool Zone::setIc(std::vector<double> &ic)
{
  return m_impl->setIc(ic);
}

bool Zone::setIc(std::vector<std::string> &ic)
{
  return m_impl->setIc(ic);
}

Zone::ZoneImpl::ZoneImpl() : m_nr(0), m_flags(0), m_ps(0), m_pc(0), m_pk(0), m_pl(0), m_relHt(PRJFLOAT("0.0")), m_Vol(PRJFLOAT("0.0")),
m_T0(PRJFLOAT("0.0")), m_P0(PRJFLOAT("0.0")), m_color(0), m_u_Ht(0), m_u_V(0), m_u_T(0), m_u_P(0), m_cdaxis(0), m_cfd(0),
m_X1(PRJFLOAT("0.0")), m_Y1(PRJFLOAT("0.0")), m_H1(PRJFLOAT("0.0")), m_X2(PRJFLOAT("0.0")), m_Y2(PRJFLOAT("0.0")), m_H2(PRJFLOAT("0.0")),
m_celldx(PRJFLOAT("0.0")), m_axialD(PRJFLOAT("0.0")), m_u_aD(0), m_u_L(0)
{}

Zone::ZoneImpl::ZoneImpl(int nr, unsigned int flags, int ps, int pc, int pk, int pl, std::string relHt, std::string Vol, std::string T0,
  std::string P0, std::string name, int color, int u_Ht, int u_V, int u_T, int u_P, int cdaxis, int cfd,
  std::string cfdname, std::string X1, std::string Y1, std::string H1, std::string X2, std::string Y2, std::string H2, std::string celldx,
  std::string axialD, int u_aD, int u_L) : Zone::ZoneImpl()
{
  setNr(nr);
  setFlags(flags);
  setPs(ps);
  setPc(pc);
  setPk(pk);
  setPl(pl);
  setRelHt(relHt);
  setVol(Vol);
  setT0(T0);
  setP0(P0);
  setName(name);
  setColor(color);
  setU_Ht(u_Ht);
  setU_V(u_V);
  setU_T(u_T);
  setU_P(u_P);
  setCdaxis(cdaxis);
  setCfd(cfd);
  setCfdname(cfdname);
  setX1(X1);
  setY1(Y1);
  setH1(H1);
  setX2(X2);
  setY2(Y2);
  setH2(H2);
  setCelldx(celldx);
  setAxialD(axialD);
  setU_aD(u_aD);
  setU_L(u_L);
}

Zone::ZoneImpl::ZoneImpl(int nr, unsigned int flags, int ps, int pc, int pk, int pl, double relHt, double Vol, double T0,
  double P0, std::string name, int color, int u_Ht, int u_V, int u_T, int u_P, int cdaxis, int cfd,
  std::string cfdname, double X1, double Y1, double H1, double X2, double Y2, double H2, double celldx,
  double axialD, int u_aD, int u_L) : Zone::ZoneImpl()
{
  setNr(nr);
  setFlags(flags);
  setPs(ps);
  setPc(pc);
  setPk(pk);
  setPl(pl);
  setRelHt(relHt);
  setVol(Vol);
  setT0(T0);
  setP0(P0);
  setName(name);
  setColor(color);
  setU_Ht(u_Ht);
  setU_V(u_V);
  setU_T(u_T);
  setU_P(u_P);
  setCdaxis(cdaxis);
  setCfd(cfd);
  setCfdname(cfdname);
  setX1(X1);
  setY1(Y1);
  setH1(H1);
  setX2(X2);
  setY2(Y2);
  setH2(H2);
  setCelldx(celldx);
  setAxialD(axialD);
  setU_aD(u_aD);
  setU_L(u_L);
}

void Zone::ZoneImpl::read(Reader& input)
{
  setNr(input.readInt());
  setFlags(input.readInt());
  setPs(input.readInt());
  setPc(input.readInt());
  setPk(input.readInt());
  setPl(input.readInt());
  setRelHt(input.readNumber<std::string>());
  setVol(input.readNumber<std::string>());
  setT0(input.readNumber<std::string>());
  setP0(input.readNumber<std::string>());
  setName(input.readString());
  setColor(input.readInt());
  setU_Ht(input.readInt());
  setU_V(input.readInt());
  setU_T(input.readInt());
  setU_P(input.readInt());
  setCdaxis(input.readInt());
  setCfd(input.readInt());
  if (cfd()) {
    setCfdname(input.readString());
  } else if (cdaxis()) {
    input.readString();  // Read "1D:"
    setX1(input.readNumber<std::string>());
    setY1(input.readNumber<std::string>());
    setH1(input.readNumber<std::string>());
    setX2(input.readNumber<std::string>());
    setY2(input.readNumber<std::string>());
    setH2(input.readNumber<std::string>());
    setCelldx(input.readNumber<std::string>());
    setAxialD(input.readNumber<std::string>());
    setU_aD(input.readInt());
    setU_L(input.readInt());
  }
}

std::string Zone::ZoneImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_flags) + ' ' + ANY_TO_STR(m_ps) + ' ' + ANY_TO_STR(m_pc) + ' '
    + ANY_TO_STR(m_pk) + ' ' + ANY_TO_STR(m_pl) + ' ' + PRJFLOAT_TO_STR(m_relHt) + ' '
    + PRJFLOAT_TO_STR(m_Vol) + ' ' + PRJFLOAT_TO_STR(m_T0) + ' ' + PRJFLOAT_TO_STR(m_P0) + ' ' + m_name + ' '
    + ANY_TO_STR(m_color) + ' ' + ANY_TO_STR(m_u_Ht) + ' ' + ANY_TO_STR(m_u_V) + ' ' + ANY_TO_STR(m_u_T) + ' '
    + ANY_TO_STR(m_u_P) + ' ' + ANY_TO_STR(m_cdaxis) + ' ' + ANY_TO_STR(m_cfd);
  if (m_cfd)
    string += ' ' + m_cfdname;
  else if (m_cdaxis)
    string += PRJFLOAT_TO_STR(m_X1) + ' ' + PRJFLOAT_TO_STR(m_Y1) + ' ' + PRJFLOAT_TO_STR(m_H1) + ' '
    + PRJFLOAT_TO_STR(m_X2) + ' ' + PRJFLOAT_TO_STR(m_Y2) + ' ' + PRJFLOAT_TO_STR(m_H2) + ' '
    + PRJFLOAT_TO_STR(m_celldx) + ' ' + PRJFLOAT_TO_STR(m_axialD) + ' ' + ANY_TO_STR(m_u_aD) + ' '
    + ANY_TO_STR(m_u_L);
  return string + '\n';
}

int Zone::ZoneImpl::nr() const
{
  return m_nr;
}

void Zone::ZoneImpl::setNr(const int nr)
{
  m_nr = nr;
}

unsigned int Zone::ZoneImpl::flags() const
{
  return m_flags;
}

void Zone::ZoneImpl::setFlags(const unsigned int flags)
{
  m_flags = flags;
}

int Zone::ZoneImpl::ps() const
{
  return m_ps;
}

void Zone::ZoneImpl::setPs(const int ps)
{
  m_ps = ps;
}

int Zone::ZoneImpl::pc() const
{
  return m_pc;
}

void Zone::ZoneImpl::setPc(const int pc)
{
  m_pc = pc;
}

int Zone::ZoneImpl::pk() const
{
  return m_pk;
}

void Zone::ZoneImpl::setPk(const int pk)
{
  m_pk = pk;
}

int Zone::ZoneImpl::pl() const
{
  return m_pl;
}

void Zone::ZoneImpl::setPl(const int pl)
{
  m_pl = pl;
}

double Zone::ZoneImpl::relHt() const
{
  return to<double>(m_relHt);
}

bool Zone::ZoneImpl::setRelHt(const double relHt)
{
  m_relHt = to_float(relHt);
  return true;
}

bool Zone::ZoneImpl::setRelHt(const std::string& relHt)
{
  return assign_if_valid<double>(relHt, m_relHt);
}

double Zone::ZoneImpl::Vol() const
{
  return to<double>(m_Vol);
}

bool Zone::ZoneImpl::setVol(const double Vol)
{
  m_Vol = to_float(Vol);
  return true;
}

bool Zone::ZoneImpl::setVol(const std::string& Vol)
{
  return assign_if_valid<double>(Vol, m_Vol);
}

double Zone::ZoneImpl::T0() const
{
  return to<double>(m_T0);
}

bool Zone::ZoneImpl::setT0(const double T0)
{
  m_T0 = to_float(T0);
  return true;
}

bool Zone::ZoneImpl::setT0(const std::string& T0)
{
  return assign_if_valid<double>(T0, m_T0);
}

double Zone::ZoneImpl::P0() const
{
  return to<double>(m_P0);
}

bool Zone::ZoneImpl::setP0(const double P0)
{
  m_P0 = to_float(P0);
  return true;
}

bool Zone::ZoneImpl::setP0(const std::string& P0)
{
  return assign_if_valid<double>(P0, m_P0);
}

std::string Zone::ZoneImpl::name() const
{
  return m_name;
}

void Zone::ZoneImpl::setName(const std::string& name)
{
  m_name = name;
}

int Zone::ZoneImpl::color() const
{
  return m_color;
}

void Zone::ZoneImpl::setColor(const int color)
{
  m_color = color;
}

int Zone::ZoneImpl::u_Ht() const
{
  return m_u_Ht;
}

void Zone::ZoneImpl::setU_Ht(const int u_Ht)
{
  m_u_Ht = u_Ht;
}

int Zone::ZoneImpl::u_V() const
{
  return m_u_V;
}

void Zone::ZoneImpl::setU_V(const int u_V)
{
  m_u_V = u_V;
}

int Zone::ZoneImpl::u_T() const
{
  return m_u_T;
}

void Zone::ZoneImpl::setU_T(const int u_T)
{
  m_u_T = u_T;
}

int Zone::ZoneImpl::u_P() const
{
  return m_u_P;
}

void Zone::ZoneImpl::setU_P(const int u_P)
{
  m_u_P = u_P;
}

int Zone::ZoneImpl::cdaxis() const
{
  return m_cdaxis;
}

void Zone::ZoneImpl::setCdaxis(const int cdaxis)
{
  m_cdaxis = cdaxis;
}

int Zone::ZoneImpl::cfd() const
{
  return m_cfd;
}

void Zone::ZoneImpl::setCfd(const int cfd)
{
  m_cfd = cfd;
}

std::string Zone::ZoneImpl::cfdname() const
{
  return m_cfdname;
}

void Zone::ZoneImpl::setCfdname(const std::string& cfdname)
{
  m_cfdname = cfdname;
}

double Zone::ZoneImpl::X1() const
{
  return to<double>(m_X1);
}

bool Zone::ZoneImpl::setX1(const double X1)
{
  m_X1 = to_float(X1);
  return true;
}

bool Zone::ZoneImpl::setX1(const std::string& X1)
{
  return assign_if_valid<double>(X1, m_X1);
}

double Zone::ZoneImpl::Y1() const
{
  return to<double>(m_Y1);
}

bool Zone::ZoneImpl::setY1(const double Y1)
{
  m_Y1 = to_float(Y1);
  return true;
}

bool Zone::ZoneImpl::setY1(const std::string& Y1)
{
  return assign_if_valid<double>(Y1, m_Y1);
}

double Zone::ZoneImpl::H1() const
{
  return to<double>(m_H1);
}

bool Zone::ZoneImpl::setH1(const double H1)
{
  m_H1 = to_float(H1);
  return true;
}

bool Zone::ZoneImpl::setH1(const std::string& H1)
{
  return assign_if_valid<double>(H1, m_H1);
}

double Zone::ZoneImpl::X2() const
{
  return to<double>(m_X2);
}

bool Zone::ZoneImpl::setX2(const double X2)
{
  m_X2 = to_float(X2);
  return true;
}

bool Zone::ZoneImpl::setX2(const std::string& X2)
{
  return assign_if_valid<double>(X2, m_X2);
}

double Zone::ZoneImpl::Y2() const
{
  return to<double>(m_Y2);
}

bool Zone::ZoneImpl::setY2(const double Y2)
{
  m_Y2 = to_float(Y2);
  return true;
}

bool Zone::ZoneImpl::setY2(const std::string& Y2)
{
  return assign_if_valid<double>(Y2, m_Y2);
}

double Zone::ZoneImpl::H2() const
{
  return to<double>(m_H2);
}

bool Zone::ZoneImpl::setH2(const double H2)
{
  m_H2 = to_float(H2);
  return true;
}

bool Zone::ZoneImpl::setH2(const std::string& H2)
{
  return assign_if_valid<double>(H2, m_H2);
}

double Zone::ZoneImpl::celldx() const
{
  return to<double>(m_celldx);
}

bool Zone::ZoneImpl::setCelldx(const double celldx)
{
  m_celldx = to_float(celldx);
  return true;
}

bool Zone::ZoneImpl::setCelldx(const std::string& celldx)
{
  return assign_if_valid<double>(celldx, m_celldx);
}

double Zone::ZoneImpl::axialD() const
{
  return to<double>(m_axialD);
}

bool Zone::ZoneImpl::setAxialD(const double axialD)
{
  m_axialD = to_float(axialD);
  return true;
}

bool Zone::ZoneImpl::setAxialD(const std::string& axialD)
{
  return assign_if_valid<double>(axialD, m_axialD);
}

int Zone::ZoneImpl::u_aD() const
{
  return m_u_aD;
}

void Zone::ZoneImpl::setU_aD(const int u_aD)
{
  m_u_aD = u_aD;
}

int Zone::ZoneImpl::u_L() const
{
  return m_u_L;
}

void Zone::ZoneImpl::setU_L(const int u_L)
{
  m_u_L = u_L;
}

void Zone::ZoneImpl::setVariablePressure(bool b)
{
  if (b)
    m_flags |= ZoneFlags::VAR_P;
  else
    m_flags &= ZoneFlags::NVAR_P;
}

bool Zone::ZoneImpl::variablePressure() const
{
  return m_flags & ZoneFlags::VAR_P;
}

void Zone::ZoneImpl::setVariableContaminants(bool b)
{
  if (b)
    m_flags |= ZoneFlags::VAR_C;
  else
    m_flags &= ZoneFlags::NVAR_C;
}

bool Zone::ZoneImpl::variableContaminants() const
{
  return m_flags & ZoneFlags::VAR_C;
}

void Zone::ZoneImpl::setSystem(bool b)
{
  if (b)
    m_flags |= ZoneFlags::SYS_N;
  else
    m_flags &= ZoneFlags::NSYS_N;
}

bool Zone::ZoneImpl::system() const
{
  return m_flags & ZoneFlags::SYS_N;
}

double Zone::ZoneImpl::ic(const int i) const
{
  return to<double>(m_ic[i]);
}

std::vector<double> Zone::ZoneImpl::ic() const
{
  std::vector<double> out;
  for (std::size_t i = 0; i < m_ic.size(); i++) {
    out.push_back(to<double>(m_ic[i]));
  }
  return out;
}

bool Zone::ZoneImpl::setIc(const int i, const double value)
{
  m_ic[i] = to_float(value);
  return true;
}

bool Zone::ZoneImpl::setIc(const int i, const std::string& value)
{
  return assign_if_valid<double>(value, m_ic[i]);
}

bool Zone::ZoneImpl::setIc(const std::vector<double>& ic)
{
  std::vector<std::string> in;
  for (const auto& input : ic) {
    in.push_back(to_float(input));
  }
  return true;
}

bool Zone::ZoneImpl::setIc(const std::vector<std::string>& ic)
{
  for (const auto& input : ic) {
    if (!is_valid<double>(input)) {
      return false;
    }
  }
  m_ic = ic;
  return true;
}

Species::Species() :
  m_impl(std::shared_ptr<SpeciesImpl>(new SpeciesImpl))
{}

Species::Species(std::string molwt, std::string Dm, std::string ccdef, std::string Cp, std::string name, std::string desc) :
  m_impl(std::shared_ptr<SpeciesImpl>(new SpeciesImpl))
{
  m_impl->setMolwt(molwt);
  m_impl->setDm(Dm);
  m_impl->setCcdef(ccdef);
  m_impl->setName(name);
  m_impl->setDesc(desc);
}

Species::Species(double molwt, double Dm, double ccdef, double Cp, std::string name, std::string desc) :
  m_impl(std::shared_ptr<SpeciesImpl>(new SpeciesImpl))
{
  m_impl->setMolwt(molwt);
  m_impl->setDm(Dm);
  m_impl->setCcdef(ccdef);
  m_impl->setName(name);
  m_impl->setDesc(desc);
}

Species::Species(int nr,int sflag,int ntflag,std::string molwt,std::string mdiam,std::string edens,std::string decay,std::string Dm,
  std::string ccdef,std::string Cp,int ucc,int umd,int ued,int udm,int ucp,std::string name,std::string desc) :
  m_impl(std::shared_ptr<SpeciesImpl>(new SpeciesImpl(nr,sflag,ntflag,molwt,mdiam,edens,decay,Dm,ccdef,Cp,ucc,umd,ued,udm,ucp,name,desc)))
{}

Species::Species(int nr,int sflag,int ntflag,double molwt,double mdiam,double edens,double decay,double Dm,
  double ccdef,double Cp,int ucc,int umd,int ued,int udm,int ucp,std::string name,std::string desc) :
  m_impl(std::shared_ptr<SpeciesImpl>(new SpeciesImpl(nr,sflag,ntflag,molwt,mdiam,edens,decay,Dm,ccdef,Cp,ucc,umd,ued,udm,ucp,name,desc)))
{}

Species::Species(const Species &other) : m_impl(other.m_impl)
{}

Species::~Species()
{}

Species& Species::operator=(const Species &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool Species::operator==(const Species &other) const
{
  return m_impl==other.m_impl;
}

bool Species::operator!=(const Species &other) const
{
  return m_impl!=other.m_impl;
}

std::string Species::write()
{
  return m_impl->write();
}

void Species::read(Reader &input)
{
  m_impl->read(input);
}

int Species::nr() const
{
  return m_impl->nr();
}

void Species::setNr(const int nr)
{
  m_impl->setNr(nr);
}

bool Species::sflag() const
{
  return m_impl->sflag();
}

void Species::setSflag(const bool sflag)
{
  m_impl->setSflag(sflag);
}

bool Species::ntflag() const
{
  return m_impl->ntflag();
}

void Species::setNtflag(const bool ntflag)
{
  m_impl->setNtflag(ntflag);
}

double Species::molwt() const
{
  return m_impl->molwt();
}

bool Species::setMolwt(const double molwt)
{
  return m_impl->setMolwt(molwt);
}

bool Species::setMolwt(const std::string &molwt)
{
  return m_impl->setMolwt(molwt);
}

double Species::mdiam() const
{
  return m_impl->mdiam();
}

bool Species::setMdiam(const double mdiam)
{
  return m_impl->setMdiam(mdiam);
}

bool Species::setMdiam(const std::string &mdiam)
{
  return m_impl->setMdiam(mdiam);
}

double Species::edens() const
{
  return m_impl->edens();
}

bool Species::setEdens(const double edens)
{
  return m_impl->setEdens(edens);
}

bool Species::setEdens(const std::string &edens)
{
  return m_impl->setEdens(edens);
}

double Species::decay() const
{
  return m_impl->decay();
}

bool Species::setDecay(const double decay)
{
  return m_impl->setDecay(decay);
}

bool Species::setDecay(const std::string &decay)
{
  return m_impl->setDecay(decay);
}

double Species::Dm() const
{
  return m_impl->Dm();
}

bool Species::setDm(const double Dm)
{
  return m_impl->setDm(Dm);
}

bool Species::setDm(const std::string &Dm)
{
  return m_impl->setDm(Dm);
}

double Species::ccdef() const
{
  return m_impl->ccdef();
}

bool Species::setCcdef(const double ccdef)
{
  return m_impl->setCcdef(ccdef);
}

bool Species::setCcdef(const std::string &ccdef)
{
  return m_impl->setCcdef(ccdef);
}

double Species::Cp() const
{
  return m_impl->Cp();
}

bool Species::setCp(const double Cp)
{
  return m_impl->setCp(Cp);
}

bool Species::setCp(const std::string &Cp)
{
  return m_impl->setCp(Cp);
}

int Species::ucc() const
{
  return m_impl->ucc();
}

void Species::setUcc(const int ucc)
{
  m_impl->setUcc(ucc);
}

int Species::umd() const
{
  return m_impl->umd();
}

void Species::setUmd(const int umd)
{
  m_impl->setUmd(umd);
}

int Species::ued() const
{
  return m_impl->ued();
}

void Species::setUed(const int ued)
{
  m_impl->setUed(ued);
}

int Species::udm() const
{
  return m_impl->udm();
}

void Species::setUdm(const int udm)
{
  m_impl->setUdm(udm);
}

int Species::ucp() const
{
  return m_impl->ucp();
}

void Species::setUcp(const int ucp)
{
  m_impl->setUcp(ucp);
}

std::string Species::name() const
{
  return m_impl->name();
}

void Species::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string Species::desc() const
{
  return m_impl->desc();
}

void Species::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

Species::SpeciesImpl::SpeciesImpl() : m_nr(0), m_sflag(0), m_ntflag(0), m_molwt(PRJFLOAT("0.0")), m_mdiam(PRJFLOAT("0.0")),
  m_edens(PRJFLOAT("0.0")), m_decay(PRJFLOAT("0.0")), m_Dm(PRJFLOAT("0.0")), m_ccdef(PRJFLOAT("0.0")), m_Cp(PRJFLOAT("0.0")),
  m_ucc(0), m_umd(0), m_ued(0), m_udm(0), m_ucp(0)
{}

Species::SpeciesImpl::SpeciesImpl(int nr, int sflag, int ntflag, std::string molwt, std::string mdiam, std::string edens, std::string decay,
  std::string Dm, std::string ccdef, std::string Cp, int ucc, int umd, int ued, int udm, int ucp, std::string name,
  std::string desc) : Species::SpeciesImpl()
{
  setNr(nr);
  setSflag(sflag);
  setNtflag(ntflag);
  setMolwt(molwt);
  setMdiam(mdiam);
  setEdens(edens);
  setDecay(decay);
  setDm(Dm);
  setCcdef(ccdef);
  setCp(Cp);
  setUcc(ucc);
  setUmd(umd);
  setUed(ued);
  setUdm(udm);
  setUcp(ucp);
  setName(name);
  setDesc(desc);
}

Species::SpeciesImpl::SpeciesImpl(int nr, int sflag, int ntflag, double molwt, double mdiam, double edens, double decay,
  double Dm, double ccdef, double Cp, int ucc, int umd, int ued, int udm, int ucp, std::string name,
  std::string desc) : Species::SpeciesImpl()
{
  setNr(nr);
  setSflag(sflag);
  setNtflag(ntflag);
  setMolwt(molwt);
  setMdiam(mdiam);
  setEdens(edens);
  setDecay(decay);
  setDm(Dm);
  setCcdef(ccdef);
  setCp(Cp);
  setUcc(ucc);
  setUmd(umd);
  setUed(ued);
  setUdm(udm);
  setUcp(ucp);
  setName(name);
  setDesc(desc);
}

void Species::SpeciesImpl::read(Reader& input)
{
  setNr(input.read<int>());
  setSflag(input.read<int>());
  setNtflag(input.read<int>());
  setMolwt(input.read<std::string>());
  setMdiam(input.read<std::string>());
  setEdens(input.read<std::string>());
  setDecay(input.read<std::string>());
  setDm(input.read<std::string>());
  setCcdef(input.read<std::string>());
  setCp(input.read<std::string>());
  setUcc(input.read<int>());
  setUmd(input.read<int>());
  setUed(input.read<int>());
  setUdm(input.read<int>());
  setUcp(input.read<int>());
  setName(input.readString());
  setDesc(input.readLine());
}

std::string Species::SpeciesImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_sflag) + ' ' + ANY_TO_STR(m_ntflag) + ' ' + PRJFLOAT_TO_STR(m_molwt) + ' ' + PRJFLOAT_TO_STR(m_mdiam) + ' ' + PRJFLOAT_TO_STR(m_edens) + ' ' + PRJFLOAT_TO_STR(m_decay) + ' ' + PRJFLOAT_TO_STR(m_Dm) + ' ' + PRJFLOAT_TO_STR(m_ccdef) + ' ' + PRJFLOAT_TO_STR(m_Cp) + ' ' + ANY_TO_STR(m_ucc) + ' ' + ANY_TO_STR(m_umd) + ' ' + ANY_TO_STR(m_ued) + ' ' + ANY_TO_STR(m_udm) + ' ' + ANY_TO_STR(m_ucp) + ' ' + m_name + '\n';
  string += m_desc + '\n';
  return string;
}

int Species::SpeciesImpl::nr() const
{
  return m_nr;
}

void Species::SpeciesImpl::setNr(const int nr)
{
  m_nr = nr;
}

bool Species::SpeciesImpl::sflag() const
{
  return m_sflag == 1;
}

void Species::SpeciesImpl::setSflag(const bool sflag)
{
  m_sflag = sflag ? 1 : 0;
}

bool Species::SpeciesImpl::ntflag() const
{
  return m_ntflag == 1;
}

void Species::SpeciesImpl::setNtflag(const bool ntflag)
{
  m_ntflag = (int)ntflag;
}

double Species::SpeciesImpl::molwt() const
{
  return to<double>(m_molwt);
}

bool Species::SpeciesImpl::setMolwt(const double molwt)
{
  m_molwt = to_float(molwt);
  return true;
}

bool Species::SpeciesImpl::setMolwt(const std::string& molwt)
{
  return assign_if_valid<double>(molwt, m_molwt);
}

double Species::SpeciesImpl::mdiam() const
{
  return to<double>(m_mdiam);
}

bool Species::SpeciesImpl::setMdiam(const double mdiam)
{
  m_mdiam = to_float(mdiam);
  return true;
}

bool Species::SpeciesImpl::setMdiam(const std::string& mdiam)
{
  return assign_if_valid<double>(mdiam, m_mdiam);
}

double Species::SpeciesImpl::edens() const
{
  return to<double>(m_edens);
}

bool Species::SpeciesImpl::setEdens(const double edens)
{
  m_edens = to_float(edens);
  return true;
}

bool Species::SpeciesImpl::setEdens(const std::string& edens)
{
  return assign_if_valid<double>(edens, m_edens);
}

double Species::SpeciesImpl::decay() const
{
  return to<double>(m_decay);
}

bool Species::SpeciesImpl::setDecay(const double decay)
{
  m_decay = to_float(decay);
  return true;
}

bool Species::SpeciesImpl::setDecay(const std::string& decay)
{
  return assign_if_valid<double>(decay, m_decay);
}

double Species::SpeciesImpl::Dm() const
{
  return to<double>(m_Dm);
}

bool Species::SpeciesImpl::setDm(const double Dm)
{
  m_Dm = to_float(Dm);
  return true;
}

bool Species::SpeciesImpl::setDm(const std::string& Dm)
{
  return assign_if_valid<double>(Dm, m_Dm);
}

double Species::SpeciesImpl::ccdef() const
{
  return to<double>(m_ccdef);
}

bool Species::SpeciesImpl::setCcdef(const double ccdef)
{
  m_ccdef = to_float(ccdef);
  return true;
}

bool Species::SpeciesImpl::setCcdef(const std::string& ccdef)
{
  return assign_if_valid<double>(ccdef, m_ccdef);
}

double Species::SpeciesImpl::Cp() const
{
  return to<double>(m_Cp);
}

bool Species::SpeciesImpl::setCp(const double Cp)
{
  m_Cp = to_float(Cp);
  return true;
}

bool Species::SpeciesImpl::setCp(const std::string& Cp)
{
  return assign_if_valid<double>(Cp, m_Cp);
}

int Species::SpeciesImpl::ucc() const
{
  return m_ucc;
}

void Species::SpeciesImpl::setUcc(const int ucc)
{
  m_ucc = ucc;
}

int Species::SpeciesImpl::umd() const
{
  return m_umd;
}

void Species::SpeciesImpl::setUmd(const int umd)
{
  m_umd = umd;
}

int Species::SpeciesImpl::ued() const
{
  return m_ued;
}

void Species::SpeciesImpl::setUed(const int ued)
{
  m_ued = ued;
}

int Species::SpeciesImpl::udm() const
{
  return m_udm;
}

void Species::SpeciesImpl::setUdm(const int udm)
{
  m_udm = udm;
}

int Species::SpeciesImpl::ucp() const
{
  return m_ucp;
}

void Species::SpeciesImpl::setUcp(const int ucp)
{
  m_ucp = ucp;
}

std::string Species::SpeciesImpl::name() const
{
  return m_name;
}

void Species::SpeciesImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string Species::SpeciesImpl::desc() const
{
  return m_desc;
}

void Species::SpeciesImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

Ahs::Ahs() :
  m_impl(std::shared_ptr<AhsImpl>(new AhsImpl))
{}

Ahs::Ahs(int nr,int zone_r,int zone_s,int path_r,int path_s,int path_x,std::string name,std::string desc) :
  m_impl(std::shared_ptr<AhsImpl>(new AhsImpl(nr,zone_r,zone_s,path_r,path_s,path_x,name,desc)))
{}

Ahs::Ahs(const Ahs &other) : m_impl(other.m_impl)
{}

Ahs::~Ahs()
{}

Ahs& Ahs::operator=(const Ahs &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool Ahs::operator==(const Ahs &other) const
{
  return m_impl==other.m_impl;
}

bool Ahs::operator!=(const Ahs &other) const
{
  return m_impl!=other.m_impl;
}

std::string Ahs::write()
{
  return m_impl->write();
}

void Ahs::read(Reader &input)
{
  m_impl->read(input);
}

int Ahs::nr() const
{
  return m_impl->nr();
}

void Ahs::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int Ahs::zone_r() const
{
  return m_impl->zone_r();
}

void Ahs::setZone_r(const int zone_r)
{
  m_impl->setZone_r(zone_r);
}

int Ahs::zone_s() const
{
  return m_impl->zone_s();
}

void Ahs::setZone_s(const int zone_s)
{
  m_impl->setZone_s(zone_s);
}

int Ahs::path_r() const
{
  return m_impl->path_r();
}

void Ahs::setPath_r(const int path_r)
{
  m_impl->setPath_r(path_r);
}

int Ahs::path_s() const
{
  return m_impl->path_s();
}

void Ahs::setPath_s(const int path_s)
{
  m_impl->setPath_s(path_s);
}

int Ahs::path_x() const
{
  return m_impl->path_x();
}

void Ahs::setPath_x(const int path_x)
{
  m_impl->setPath_x(path_x);
}

std::string Ahs::name() const
{
  return m_impl->name();
}

void Ahs::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string Ahs::desc() const
{
  return m_impl->desc();
}

void Ahs::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

Ahs::AhsImpl::AhsImpl() : m_nr(0), m_zone_r(0), m_zone_s(0), m_path_r(0), m_path_s(0), m_path_x(0)
{}

Ahs::AhsImpl::AhsImpl(int nr, int zone_r, int zone_s, int path_r, int path_s, int path_x,
  std::string name, std::string desc) : Ahs::AhsImpl()
{
  setNr(nr);
  setZone_r(zone_r);
  setZone_s(zone_s);
  setPath_r(path_r);
  setPath_s(path_s);
  setPath_x(path_x);
  setName(name);
  setDesc(desc);
}

void Ahs::AhsImpl::read(Reader& input)
{
  setNr(input.read<int>());
  setZone_r(input.read<int>());
  setZone_s(input.read<int>());
  setPath_r(input.read<int>());
  setPath_s(input.read<int>());
  setPath_x(input.read<int>());
  setName(input.readString());
  setDesc(input.readLine());
}

std::string Ahs::AhsImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_zone_r) + ' ' + ANY_TO_STR(m_zone_s) + ' ' + ANY_TO_STR(m_path_r) + ' ' + ANY_TO_STR(m_path_s) + ' ' + ANY_TO_STR(m_path_x) + ' ' + m_name + '\n';
  string += m_desc + '\n';
  return string;
}

int Ahs::AhsImpl::nr() const
{
  return m_nr;
}

void Ahs::AhsImpl::setNr(const int nr)
{
  m_nr = nr;
}

int Ahs::AhsImpl::zone_r() const
{
  return m_zone_r;
}

void Ahs::AhsImpl::setZone_r(const int zone_r)
{
  m_zone_r = zone_r;
}

int Ahs::AhsImpl::zone_s() const
{
  return m_zone_s;
}

void Ahs::AhsImpl::setZone_s(const int zone_s)
{
  m_zone_s = zone_s;
}

int Ahs::AhsImpl::path_r() const
{
  return m_path_r;
}

void Ahs::AhsImpl::setPath_r(const int path_r)
{
  m_path_r = path_r;
}

int Ahs::AhsImpl::path_s() const
{
  return m_path_s;
}

void Ahs::AhsImpl::setPath_s(const int path_s)
{
  m_path_s = path_s;
}

int Ahs::AhsImpl::path_x() const
{
  return m_path_x;
}

void Ahs::AhsImpl::setPath_x(const int path_x)
{
  m_path_x = path_x;
}

std::string Ahs::AhsImpl::name() const
{
  return m_name;
}

void Ahs::AhsImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string Ahs::AhsImpl::desc() const
{
  return m_desc;
}

void Ahs::AhsImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

AirflowPath::AirflowPath() :
  m_impl(std::shared_ptr<AirflowPathImpl>(new AirflowPathImpl))
{}

AirflowPath::AirflowPath(int flags, int pzn, int pe, int pw, int pld, std::string relHt, std::string mult, std::string wPset,
  std::string wPmod, std::string wazm, unsigned int icon) :
  m_impl(std::shared_ptr<AirflowPathImpl>(new AirflowPathImpl))
{
  m_impl->setFlags(flags);
  m_impl->setPzn(pzn);
  m_impl->setPzm(-1);
  m_impl->setPe(pe);
  m_impl->setPw(pw);
  m_impl->setPld(pld);
  m_impl->setRelHt(relHt);
  m_impl->setMult(mult);
  m_impl->setWPset(wPset);
  m_impl->setWPmod(wPmod);
  m_impl->setWazm(wazm);
  m_impl->setIcon(icon);
}

AirflowPath::AirflowPath(int flags, int pzn, int pe, int pw, int pld, double relHt, double mult, double wPset,
  double wPmod, double wazm, unsigned int icon) :
  m_impl(std::shared_ptr<AirflowPathImpl>(new AirflowPathImpl))
{
  m_impl->setFlags(flags);
  m_impl->setPzn(pzn);
  m_impl->setPzm(-1);
  m_impl->setPe(pe);
  m_impl->setPw(pw);
  m_impl->setPld(pld);
  m_impl->setRelHt(relHt);
  m_impl->setMult(mult);
  m_impl->setWPset(wPset);
  m_impl->setWPmod(wPmod);
  m_impl->setWazm(wazm);
  m_impl->setIcon(icon);
}

AirflowPath::AirflowPath(int flags, int pzn, int pzm, int pe, int pld, std::string relHt, std::string mult, unsigned int icon) :
  m_impl(std::shared_ptr<AirflowPathImpl>(new AirflowPathImpl))
{
  m_impl->setFlags(flags);
  m_impl->setPzn(pzn);
  m_impl->setPzm(pzm);
  m_impl->setPe(pe);
  m_impl->setPld(pld);
  m_impl->setRelHt(relHt);
  m_impl->setMult(mult);
  m_impl->setIcon(icon);
}

AirflowPath::AirflowPath(int flags, int pzn, int pzm, int pe, int pld, double relHt, double mult, unsigned int icon) :
  m_impl(std::shared_ptr<AirflowPathImpl>(new AirflowPathImpl))
{
  m_impl->setFlags(flags);
  m_impl->setPzn(pzn);
  m_impl->setPzm(pzm);
  m_impl->setPe(pe);
  m_impl->setPld(pld);
  m_impl->setRelHt(relHt);
  m_impl->setMult(mult);
  m_impl->setIcon(icon);
}

AirflowPath::AirflowPath(int nr,int flags,int pzn,int pzm,int pe,int pf,int pw,int pa,int ps,int pc,int pld,std::string X,
  std::string Y,std::string relHt,std::string mult,std::string wPset,std::string wPmod,std::string wazm,std::string Fahs,
  std::string Xmax,std::string Xmin,unsigned int icon,unsigned int dir,int u_Ht,int u_XY,int u_dP,
  int u_F,int cfd,std::string cfd_name,int cfd_ptype,int cfd_btype,int cfd_capp) :
  m_impl(std::shared_ptr<AirflowPathImpl>(new AirflowPathImpl(nr,flags,pzn,pzm,pe,pf,pw,pa,ps,pc,pld,X,Y,relHt,mult,wPset,wPmod,wazm,Fahs,
    Xmax,Xmin,icon,dir,u_Ht,u_XY,u_dP,u_F,cfd,cfd_name,cfd_ptype,cfd_btype,cfd_capp)))
{}

AirflowPath::AirflowPath(int nr,int flags,int pzn,int pzm,int pe,int pf,int pw,int pa,int ps,int pc,int pld,double X,
  double Y,double relHt,double mult,double wPset,double wPmod,double wazm,double Fahs,
  double Xmax,double Xmin,unsigned int icon,unsigned int dir,int u_Ht,int u_XY,int u_dP,
  int u_F,int cfd,std::string cfd_name,int cfd_ptype,int cfd_btype,int cfd_capp) :
  m_impl(std::shared_ptr<AirflowPathImpl>(new AirflowPathImpl(nr,flags,pzn,pzm,pe,pf,pw,pa,ps,pc,pld,X,Y,relHt,mult,wPset,wPmod,wazm,Fahs,
    Xmax,Xmin,icon,dir,u_Ht,u_XY,u_dP,u_F,cfd,cfd_name,cfd_ptype,cfd_btype,cfd_capp)))
{}

AirflowPath::AirflowPath(const AirflowPath &other) : m_impl(other.m_impl)
{}

AirflowPath::~AirflowPath()
{}

AirflowPath& AirflowPath::operator=(const AirflowPath &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool AirflowPath::operator==(const AirflowPath &other) const
{
  return m_impl==other.m_impl;
}

bool AirflowPath::operator!=(const AirflowPath &other) const
{
  return m_impl!=other.m_impl;
}

void AirflowPath::read(Reader &input)
{
  m_impl->read(input);
}

std::string AirflowPath::write()
{
  return m_impl->write();
}

int AirflowPath::nr() const
{
  return m_impl->nr();
}

void AirflowPath::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int AirflowPath::flags() const
{
  return m_impl->flags();
}

void AirflowPath::setFlags(const int flags)
{
  m_impl->setFlags(flags);
}

int AirflowPath::pzn() const
{
  return m_impl->pzn();
}

void AirflowPath::setPzn(const int pzn)
{
  m_impl->setPzn(pzn);
}

int AirflowPath::pzm() const
{
  return m_impl->pzm();
}

void AirflowPath::setPzm(const int pzm)
{
  m_impl->setPzm(pzm);
}

int AirflowPath::pe() const
{
  return m_impl->pe();
}

void AirflowPath::setPe(const int pe)
{
  m_impl->setPe(pe);
}

int AirflowPath::pf() const
{
  return m_impl->pf();
}

void AirflowPath::setPf(const int pf)
{
  m_impl->setPf(pf);
}

int AirflowPath::pw() const
{
  return m_impl->pw();
}

void AirflowPath::setPw(const int pw)
{
  m_impl->setPw(pw);
}

int AirflowPath::pa() const
{
  return m_impl->pa();
}

void AirflowPath::setPa(const int pa)
{
  m_impl->setPa(pa);
}

int AirflowPath::ps() const
{
  return m_impl->ps();
}

void AirflowPath::setPs(const int ps)
{
  m_impl->setPs(ps);
}

int AirflowPath::pc() const
{
  return m_impl->pc();
}

void AirflowPath::setPc(const int pc)
{
  m_impl->setPc(pc);
}

int AirflowPath::pld() const
{
  return m_impl->pld();
}

void AirflowPath::setPld(const int pld)
{
  m_impl->setPld(pld);
}

double AirflowPath::X() const
{
  return m_impl->X();
}

bool AirflowPath::setX(const double X)
{
  return m_impl->setX(X);
}

bool AirflowPath::setX(const std::string &X)
{
  return m_impl->setX(X);
}

double AirflowPath::Y() const
{
  return m_impl->Y();
}

bool AirflowPath::setY(const double Y)
{
  return m_impl->setY(Y);
}

bool AirflowPath::setY(const std::string &Y)
{
  return m_impl->setY(Y);
}

double AirflowPath::relHt() const
{
  return m_impl->relHt();
}

bool AirflowPath::setRelHt(const std::string &relHt)
{
  return m_impl->setRelHt(relHt);
}

bool AirflowPath::setRelHt(const double relHt)
{
  return m_impl->setRelHt(relHt);
}

double AirflowPath::mult() const
{
  return m_impl->mult();
}

bool AirflowPath::setMult(const double mult)
{
  return m_impl->setMult(mult);
}

bool AirflowPath::setMult(const std::string &mult)
{
  return m_impl->setMult(mult);
}

double AirflowPath::wPset() const
{
  return m_impl->wPset();
}

bool AirflowPath::setWPset(const double wPset)
{
  return m_impl->setWPset(wPset);
}

bool AirflowPath::setWPset(const std::string &wPset)
{
  return m_impl->setWPset(wPset);
}

double AirflowPath::wPmod() const
{
  return m_impl->wPmod();
}

bool AirflowPath::setWPmod(const double wPmod)
{
  return m_impl->setWPmod(wPmod);
}

bool AirflowPath::setWPmod(const std::string &wPmod)
{
  return m_impl->setWPmod(wPmod);
}

double AirflowPath::wazm() const
{
  return m_impl->wazm();
}

bool AirflowPath::setWazm(const double wazm)
{
  return m_impl->setWazm(wazm);
}

bool AirflowPath::setWazm(const std::string &wazm)
{
  return m_impl->setWazm(wazm);
}

double AirflowPath::Fahs() const
{
  return m_impl->Fahs();
}

bool AirflowPath::setFahs(const double Fahs)
{
  return m_impl->setFahs(Fahs);
}

bool AirflowPath::setFahs(const std::string &Fahs)
{
  return m_impl->setFahs(Fahs);
}

double AirflowPath::Xmax() const
{
  return m_impl->Xmax();
}

bool AirflowPath::setXmax(const double Xmax)
{
  return m_impl->setXmax(Xmax);
}

bool AirflowPath::setXmax(const std::string &Xmax)
{
  return m_impl->setXmax(Xmax);
}

double AirflowPath::Xmin() const
{
  return m_impl->Xmin();
}

bool AirflowPath::setXmin(const double Xmin)
{
  return m_impl->setXmin(Xmin);
}

bool AirflowPath::setXmin(const std::string &Xmin)
{
  return m_impl->setXmin(Xmin);
}

unsigned int AirflowPath::icon() const
{
  return m_impl->icon();
}

void AirflowPath::setIcon(const unsigned int icon)
{
  m_impl->setIcon(icon);
}

unsigned int AirflowPath::dir() const
{
  return m_impl->dir();
}

void AirflowPath::setDir(const unsigned int dir)
{
  m_impl->setDir(dir);
}

int AirflowPath::u_Ht() const
{
  return m_impl->u_Ht();
}

void AirflowPath::setU_Ht(const int u_Ht)
{
  m_impl->setU_Ht(u_Ht);
}

int AirflowPath::u_XY() const
{
  return m_impl->u_XY();
}

void AirflowPath::setU_XY(const int u_XY)
{
  m_impl->setU_XY(u_XY);
}

int AirflowPath::u_dP() const
{
  return m_impl->u_dP();
}

void AirflowPath::setU_dP(const int u_dP)
{
  m_impl->setU_dP(u_dP);
}

int AirflowPath::u_F() const
{
  return m_impl->u_F();
}

void AirflowPath::setU_F(const int u_F)
{
  m_impl->setU_F(u_F);
}

int AirflowPath::cfd() const
{
  return m_impl->cfd();
}

void AirflowPath::setCfd(const int cfd)
{
  m_impl->setCfd(cfd);
}

std::string AirflowPath::cfd_name() const
{
  return m_impl->cfd_name();
}

void AirflowPath::setCfd_name(const std::string &cfd_name)
{
  m_impl->setCfd_name(cfd_name);
}

int AirflowPath::cfd_ptype() const
{
  return m_impl->cfd_ptype();
}

void AirflowPath::setCfd_ptype(const int cfd_ptype)
{
  m_impl->setCfd_ptype(cfd_ptype);
}

int AirflowPath::cfd_btype() const
{
  return m_impl->cfd_btype();
}

void AirflowPath::setCfd_btype(const int cfd_btype)
{
  m_impl->setCfd_btype(cfd_btype);
}

int AirflowPath::cfd_capp() const
{
  return m_impl->cfd_capp();
}

void AirflowPath::setCfd_capp(const int cfd_capp)
{
  m_impl->setCfd_capp(cfd_capp);
}

void AirflowPath::setWindPressure(bool b)
{
  m_impl->setWindPressure(b);
}

bool AirflowPath::windPressure()
{
  return m_impl->windPressure();
}

void AirflowPath::setSystem(bool b)
{
  m_impl->setSystem(b);
}

bool AirflowPath::system()
{
  return m_impl->system();
}

void AirflowPath::setExhaust(bool b)
{
  m_impl->setExhaust(b);
}

bool AirflowPath::exhaust()
{
  return m_impl->exhaust();
}

void AirflowPath::setRecirculation(bool b)
{
  m_impl->setRecirculation(b);
}

bool AirflowPath::recirculation()
{
  return m_impl->recirculation();
}

void AirflowPath::setOutsideAir(bool b)
{
  m_impl->setOutsideAir(b);
}

bool AirflowPath::outsideAir()
{
  return m_impl->outsideAir();
}


AirflowPath::AirflowPathImpl::AirflowPathImpl() :m_nr(0), m_flags(0), m_pzn(0), m_pzm(0), m_pe(0), m_pf(0), m_pw(0), m_pa(0), m_ps(0), m_pc(0),
m_pld(0), m_X(PRJFLOAT("0.0")), m_Y(PRJFLOAT("0.0")), m_relHt(PRJFLOAT("0.0")), m_mult(PRJFLOAT("0.0")), m_wPset(PRJFLOAT("0.0")),
m_wPmod(PRJFLOAT("0.0")), m_wazm(PRJFLOAT("0.0")), m_Fahs(PRJFLOAT("0.0")), m_Xmax(PRJFLOAT("0.0")), m_Xmin(PRJFLOAT("0.0")), m_icon(0),
m_dir(0), m_u_Ht(0), m_u_XY(0), m_u_dP(0), m_u_F(0), m_cfd(0), m_cfd_ptype(0), m_cfd_btype(0), m_cfd_capp(0)
{}

AirflowPath::AirflowPathImpl::AirflowPathImpl(int nr, int flags, int pzn, int pzm, int pe, int pf, int pw, int pa, int ps, int pc, int pld,
  std::string X, std::string Y, std::string relHt, std::string mult, std::string wPset, std::string wPmod, std::string wazm,
  std::string Fahs, std::string Xmax, std::string Xmin, unsigned int icon, unsigned int dir, int u_Ht, int u_XY,
  int u_dP, int u_F, int cfd, std::string cfd_name, int cfd_ptype, int cfd_btype, int cfd_capp) : AirflowPath::AirflowPathImpl()
{
  setNr(nr);
  setFlags(flags);
  setPzn(pzn);
  setPzm(pzm);
  setPe(pe);
  setPf(pf);
  setPw(pw);
  setPa(pa);
  setPs(ps);
  setPc(pc);
  setPld(pld);
  setX(X);
  setY(Y);
  setRelHt(relHt);
  setMult(mult);
  setWPset(wPset);
  setWPmod(wPmod);
  setWazm(wazm);
  setFahs(Fahs);
  setXmax(Xmax);
  setXmin(Xmin);
  setIcon(icon);
  setDir(dir);
  setU_Ht(u_Ht);
  setU_XY(u_XY);
  setU_dP(u_dP);
  setU_F(u_F);
  setCfd(cfd);
  setCfd_name(cfd_name);
  setCfd_ptype(cfd_ptype);
  setCfd_btype(cfd_btype);
  setCfd_capp(cfd_capp);
}

AirflowPath::AirflowPathImpl::AirflowPathImpl(int nr, int flags, int pzn, int pzm, int pe, int pf, int pw, int pa, int ps, int pc, int pld,
  double X, double Y, double relHt, double mult, double wPset, double wPmod, double wazm,
  double Fahs, double Xmax, double Xmin, unsigned int icon, unsigned int dir, int u_Ht, int u_XY,
  int u_dP, int u_F, int cfd, std::string cfd_name, int cfd_ptype, int cfd_btype, int cfd_capp) : AirflowPath::AirflowPathImpl()
{
  setNr(nr);
  setFlags(flags);
  setPzn(pzn);
  setPzm(pzm);
  setPe(pe);
  setPf(pf);
  setPw(pw);
  setPa(pa);
  setPs(ps);
  setPc(pc);
  setPld(pld);
  setX(X);
  setY(Y);
  setRelHt(relHt);
  setMult(mult);
  setWPset(wPset);
  setWPmod(wPmod);
  setWazm(wazm);
  setFahs(Fahs);
  setXmax(Xmax);
  setXmin(Xmin);
  setIcon(icon);
  setDir(dir);
  setU_Ht(u_Ht);
  setU_XY(u_XY);
  setU_dP(u_dP);
  setU_F(u_F);
  setCfd(cfd);
  setCfd_name(cfd_name);
  setCfd_ptype(cfd_ptype);
  setCfd_btype(cfd_btype);
  setCfd_capp(cfd_capp);
}

void AirflowPath::AirflowPathImpl::read(Reader& input)
{
  setNr(input.read<int>());
  setFlags(input.read<int>());
  setPzn(input.read<int>());
  setPzm(input.read<int>());
  setPe(input.read<int>());
  setPf(input.read<int>());
  setPw(input.read<int>());
  setPa(input.read<int>());
  setPs(input.read<int>());
  setPc(input.read<int>());
  setPld(input.read<int>());
  setX(input.readNumber<std::string>());
  setY(input.readNumber<std::string>());
  setRelHt(input.readNumber<std::string>());
  setMult(input.readNumber<std::string>());
  setWPset(input.readNumber<std::string>());
  setWPmod(input.readNumber<std::string>());
  setWazm(input.readNumber<std::string>());
  setFahs(input.readNumber<std::string>());
  setXmax(input.readNumber<std::string>());
  setXmin(input.readNumber<std::string>());
  setIcon(input.read<unsigned int>());
  setDir(input.read<unsigned int>());
  setU_Ht(input.read<int>());
  setU_XY(input.read<int>());
  setU_dP(input.read<int>());
  setU_F(input.read<int>());
  setCfd(input.read<int>());
  if (m_cfd) {
    setCfd_name(input.readString());
    setCfd_ptype(input.read<int>());
    setCfd_btype(input.read<int>());
    setCfd_capp(input.read<int>());
  }
}

std::string AirflowPath::AirflowPathImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_flags) + ' ' + ANY_TO_STR(m_pzn) + ' ' + ANY_TO_STR(m_pzm) + ' '
    + ANY_TO_STR(m_pe) + ' ' + ANY_TO_STR(m_pf) + ' ' + ANY_TO_STR(m_pw) + ' ' + ANY_TO_STR(m_pa) + ' '
    + ANY_TO_STR(m_ps) + ' ' + ANY_TO_STR(m_pc) + ' ' + ANY_TO_STR(m_pld) + ' ' + PRJFLOAT_TO_STR(m_X) + ' '
    + PRJFLOAT_TO_STR(m_Y) + ' ' + PRJFLOAT_TO_STR(m_relHt) + ' ' + PRJFLOAT_TO_STR(m_mult) + ' ' + PRJFLOAT_TO_STR(m_wPset) + ' '
    + PRJFLOAT_TO_STR(m_wPmod) + ' ' + PRJFLOAT_TO_STR(m_wazm) + ' ' + PRJFLOAT_TO_STR(m_Fahs) + ' ' + PRJFLOAT_TO_STR(m_Xmax) + ' '
    + PRJFLOAT_TO_STR(m_Xmin) + ' ' + ANY_TO_STR(m_icon) + ' ' + ANY_TO_STR(m_dir) + ' ' + ANY_TO_STR(m_u_Ht) + ' '
    + ANY_TO_STR(m_u_XY) + ' ' + ANY_TO_STR(m_u_dP) + ' ' + ANY_TO_STR(m_u_F) + ' ' + ANY_TO_STR(m_cfd);
  if (m_cfd) {
    string += ' ' + m_cfd_name + ' ' + ANY_TO_STR(m_cfd_ptype) + ' ' + ANY_TO_STR(m_cfd_btype) + ' '
      + ANY_TO_STR(m_cfd_capp);
  }
  return string + '\n';
}

int AirflowPath::AirflowPathImpl::nr() const
{
  return m_nr;
}

void AirflowPath::AirflowPathImpl::setNr(const int nr)
{
  m_nr = nr;
}

int AirflowPath::AirflowPathImpl::flags() const
{
  return m_flags;
}

void AirflowPath::AirflowPathImpl::setFlags(const int flags)
{
  m_flags = flags;
}

int AirflowPath::AirflowPathImpl::pzn() const
{
  return m_pzn;
}

void AirflowPath::AirflowPathImpl::setPzn(const int pzn)
{
  m_pzn = pzn;
}

int AirflowPath::AirflowPathImpl::pzm() const
{
  return m_pzm;
}

void AirflowPath::AirflowPathImpl::setPzm(const int pzm)
{
  m_pzm = pzm;
}

int AirflowPath::AirflowPathImpl::pe() const
{
  return m_pe;
}

void AirflowPath::AirflowPathImpl::setPe(const int pe)
{
  m_pe = pe;
}

int AirflowPath::AirflowPathImpl::pf() const
{
  return m_pf;
}

void AirflowPath::AirflowPathImpl::setPf(const int pf)
{
  m_pf = pf;
}

int AirflowPath::AirflowPathImpl::pw() const
{
  return m_pw;
}

void AirflowPath::AirflowPathImpl::setPw(const int pw)
{
  m_pw = pw;
}

int AirflowPath::AirflowPathImpl::pa() const
{
  return m_pa;
}

void AirflowPath::AirflowPathImpl::setPa(const int pa)
{
  m_pa = pa;
}

int AirflowPath::AirflowPathImpl::ps() const
{
  return m_ps;
}

void AirflowPath::AirflowPathImpl::setPs(const int ps)
{
  m_ps = ps;
}

int AirflowPath::AirflowPathImpl::pc() const
{
  return m_pc;
}

void AirflowPath::AirflowPathImpl::setPc(const int pc)
{
  m_pc = pc;
}

int AirflowPath::AirflowPathImpl::pld() const
{
  return m_pld;
}

void AirflowPath::AirflowPathImpl::setPld(const int pld)
{
  m_pld = pld;
}

double AirflowPath::AirflowPathImpl::X() const
{
  return to<double>(m_X);
}

bool AirflowPath::AirflowPathImpl::setX(const double X)
{
  m_X = to_float(X);
  return true;
}

bool AirflowPath::AirflowPathImpl::setX(const std::string& X)
{
  return assign_if_valid<double>(X, m_X);
}

double AirflowPath::AirflowPathImpl::Y() const
{
  return to<double>(m_Y);
}

bool AirflowPath::AirflowPathImpl::setY(const double Y)
{
  m_Y = to_float(Y);
  return true;
}

bool AirflowPath::AirflowPathImpl::setY(const std::string& Y)
{
  return assign_if_valid<double>(Y, m_Y);
}

double AirflowPath::AirflowPathImpl::relHt() const
{
  return to<double>(m_relHt);
}

bool AirflowPath::AirflowPathImpl::setRelHt(const double relHt)
{
  m_relHt = to_float(relHt);
  return true;
}

bool AirflowPath::AirflowPathImpl::setRelHt(const std::string& relHt)
{
  return assign_if_valid<double>(relHt, m_relHt);
}

double AirflowPath::AirflowPathImpl::mult() const
{
  return to<double>(m_mult);
}

bool AirflowPath::AirflowPathImpl::setMult(const double mult)
{
  m_mult = to_float(mult);
  return true;
}

bool AirflowPath::AirflowPathImpl::setMult(const std::string& mult)
{
  return assign_if_valid<double>(mult, m_mult);
}

double AirflowPath::AirflowPathImpl::wPset() const
{
  return to<double>(m_wPset);
}

bool AirflowPath::AirflowPathImpl::setWPset(const double wPset)
{
  m_wPset = to_float(wPset);
  return true;
}

bool AirflowPath::AirflowPathImpl::setWPset(const std::string& wPset)
{
  return assign_if_valid<double>(wPset, m_wPset);
}

double AirflowPath::AirflowPathImpl::wPmod() const
{
  return to<double>(m_wPmod);
}

bool AirflowPath::AirflowPathImpl::setWPmod(const double wPmod)
{
  m_wPmod = to_float(wPmod);
  return true;
}

bool AirflowPath::AirflowPathImpl::setWPmod(const std::string& wPmod)
{
  return assign_if_valid<double>(wPmod, m_wPmod);
}

double AirflowPath::AirflowPathImpl::wazm() const
{
  return to<double>(m_wazm);
}

bool AirflowPath::AirflowPathImpl::setWazm(const double wazm)
{
  m_wazm = to_float(wazm);
  return true;
}

bool AirflowPath::AirflowPathImpl::setWazm(const std::string& wazm)
{
  return assign_if_valid<double>(wazm, m_wazm);
}

double AirflowPath::AirflowPathImpl::Fahs() const
{
  return to<double>(m_Fahs);
}

bool AirflowPath::AirflowPathImpl::setFahs(const double Fahs)
{
  m_Fahs = to_float(Fahs);
  return true;
}

bool AirflowPath::AirflowPathImpl::setFahs(const std::string& Fahs)
{
  return assign_if_valid<double>(Fahs, m_Fahs);
}

double AirflowPath::AirflowPathImpl::Xmax() const
{
  return to<double>(m_Xmax);
}

bool AirflowPath::AirflowPathImpl::setXmax(const double Xmax)
{
  m_Xmax = to_float(Xmax);
  return true;
}

bool AirflowPath::AirflowPathImpl::setXmax(const std::string& Xmax)
{
  return assign_if_valid<double>(Xmax, m_Xmax);
}

double AirflowPath::AirflowPathImpl::Xmin() const
{
  return to<double>(m_Xmin);
}

bool AirflowPath::AirflowPathImpl::setXmin(const double Xmin)
{
  m_Xmin = to_float(Xmin);
  return true;
}

bool AirflowPath::AirflowPathImpl::setXmin(const std::string& Xmin)
{
  return assign_if_valid<double>(Xmin, m_Xmin);
}

unsigned int AirflowPath::AirflowPathImpl::icon() const
{
  return m_icon;
}

void AirflowPath::AirflowPathImpl::setIcon(const unsigned int icon)
{
  m_icon = icon;
}

unsigned int AirflowPath::AirflowPathImpl::dir() const
{
  return m_dir;
}

void AirflowPath::AirflowPathImpl::setDir(const unsigned int dir)
{
  m_dir = dir;
}

int AirflowPath::AirflowPathImpl::u_Ht() const
{
  return m_u_Ht;
}

void AirflowPath::AirflowPathImpl::setU_Ht(const int u_Ht)
{
  m_u_Ht = u_Ht;
}

int AirflowPath::AirflowPathImpl::u_XY() const
{
  return m_u_XY;
}

void AirflowPath::AirflowPathImpl::setU_XY(const int u_XY)
{
  m_u_XY = u_XY;
}

int AirflowPath::AirflowPathImpl::u_dP() const
{
  return m_u_dP;
}

void AirflowPath::AirflowPathImpl::setU_dP(const int u_dP)
{
  m_u_dP = u_dP;
}

int AirflowPath::AirflowPathImpl::u_F() const
{
  return m_u_F;
}

void AirflowPath::AirflowPathImpl::setU_F(const int u_F)
{
  m_u_F = u_F;
}

int AirflowPath::AirflowPathImpl::cfd() const
{
  return m_cfd;
}

void AirflowPath::AirflowPathImpl::setCfd(const int cfd)
{
  m_cfd = cfd;
}

std::string AirflowPath::AirflowPathImpl::cfd_name() const
{
  return m_cfd_name;
}

void AirflowPath::AirflowPathImpl::setCfd_name(const std::string& cfd_name)
{
  m_cfd_name = cfd_name;
}

int AirflowPath::AirflowPathImpl::cfd_ptype() const
{
  return m_cfd_ptype;
}

void AirflowPath::AirflowPathImpl::setCfd_ptype(const int cfd_ptype)
{
  m_cfd_ptype = cfd_ptype;
}

int AirflowPath::AirflowPathImpl::cfd_btype() const
{
  return m_cfd_btype;
}

void AirflowPath::AirflowPathImpl::setCfd_btype(const int cfd_btype)
{
  m_cfd_btype = cfd_btype;
}

int AirflowPath::AirflowPathImpl::cfd_capp() const
{
  return m_cfd_capp;
}

void AirflowPath::AirflowPathImpl::setCfd_capp(const int cfd_capp)
{
  m_cfd_capp = cfd_capp;
}

void AirflowPath::AirflowPathImpl::setWindPressure(bool b)
{
  if (b)
    m_flags |= PathFlags::WIND;
  else
    m_flags &= 0xFFFE;
}

bool AirflowPath::AirflowPathImpl::windPressure()
{
  return m_flags & PathFlags::WIND;
}

void AirflowPath::AirflowPathImpl::setSystem(bool b)
{
  if (b)
    m_flags |= PathFlags::AHS_S;
  else
    m_flags &= 0xFFF7;
}

bool AirflowPath::AirflowPathImpl::system()
{
  return m_flags & PathFlags::AHS_S;
}

void AirflowPath::AirflowPathImpl::setExhaust(bool b)
{
  if (b)
    m_flags |= PathFlags::AHS_X;
  else
    m_flags &= 0xFFBF;
}

bool AirflowPath::AirflowPathImpl::exhaust()
{
  return m_flags & PathFlags::AHS_X;
}


void AirflowPath::AirflowPathImpl::setRecirculation(bool b)
{
  if (b)
    m_flags |= PathFlags::AHS_R;
  else
    m_flags &= 0xFFEF;
}

bool AirflowPath::AirflowPathImpl::recirculation()
{
  return m_flags & PathFlags::AHS_R;
}

void AirflowPath::AirflowPathImpl::setOutsideAir(bool b)
{
  if (b)
    m_flags |= PathFlags::AHS_O;
  else
    m_flags &= 0xFFDF;
}

bool AirflowPath::AirflowPathImpl::outsideAir()
{
  return m_flags & PathFlags::AHS_O;
}

RunControl::RunControl() :
  m_impl(std::shared_ptr<RunControlImpl>(new RunControlImpl()))
{}
/*
RunControl::RunControl(int sim_af,int afcalc,int afmaxi,double afrcnvg,double afacnvg,double afrelax,
int uac2,double Pres,int uPres,int afslae,int afrseq,int aflmaxi,double aflcnvg,
int aflinit,int Tadj,int sim_mf,int ccmaxi,double ccrcnvg,double ccacnvg,
double ccrelax,int uccc,int mfnmthd,int mfnrseq,int mfnmaxi,double mfnrcnvg,
double mfnacnvg,double mfnrelax,double mfngamma,int uccn,int mftmthd,int mftrseq,
int mftmaxi,double mftrcnvg,double mftacnvg,double mftrelax,double mftgamma,int ucct,
int mfvmthd,int mfvrseq,int mfvmaxi,double mfvrcnvg,double mfvacnvg,double mfvrelax,
int uccv,int mf_solver,int sim_1dz,int sim_1dd,double celldx,int sim_vjt,int udx,
int cvode_mth,double cvode_rcnvg,double cvode_acnvg,double cvode_dtmax,int tsdens,
double tsrelax,int tsmaxi,int cnvgSS,int densZP,int stackD,int dodMdt,
std::string date_st,std::string time_st,std::string date_0,std::string time_0,std::string date_1,
std::string time_1,std::string time_step,std::string time_list,std::string time_scrn,int restart,
std::string rstdate,std::string rsttime,int list,int doDlg,int pfsave,int zfsave,
int zcsave,int achvol,int achsave,int abwsave,int cbwsave,int expsave,
int ebwsave,int zaasave,int zbwsave,int rzfsave,int rzmsave,int rz1save,
int csmsave,int srfsave,int logsave,std::vector<int> save,std::vector<double> rvals,
int BldgFlowZ,int BldgFlowD,int BldgFlowC,int cfd_ctype,double cfd_convcpl,
int cfd_var,int cfd_zref,int cfd_imax,int cfd_dtcmo)
{
d = new RunControlImpl(sim_af,afcalc,afmaxi,afrcnvg,afacnvg,afrelax,uac2,Pres,uPres,afslae,afrseq,
aflmaxi,aflcnvg,aflinit,Tadj,sim_mf,ccmaxi,ccrcnvg,ccacnvg,ccrelax,uccc,mfnmthd,
mfnrseq,mfnmaxi,mfnrcnvg,mfnacnvg,mfnrelax,mfngamma,uccn,mftmthd,mftrseq,mftmaxi,
mftrcnvg,mftacnvg,mftrelax,mftgamma,ucct,mfvmthd,mfvrseq,mfvmaxi,mfvrcnvg,
mfvacnvg,mfvrelax,uccv,mf_solver,sim_1dz,sim_1dd,celldx,sim_vjt,udx,cvode_mth,
cvode_rcnvg,cvode_acnvg,cvode_dtmax,tsdens,tsrelax,tsmaxi,cnvgSS,densZP,stackD,
dodMdt,date_st,time_st,date_0,time_0,date_1,time_1,time_step,time_list,time_scrn,
restart,rstdate,rsttime,list,doDlg,pfsave,zfsave,zcsave,achvol,achsave,abwsave,
cbwsave,expsave,ebwsave,zaasave,zbwsave,rzfsave,rzmsave,rz1save,csmsave,srfsave,
logsave,save,rvals,BldgFlowZ,BldgFlowD,BldgFlowC,cfd_ctype,cfd_convcpl,cfd_var,
cfd_zref,cfd_imax,cfd_dtcmo);
}

RunControl::RunControl(int sim_af,int afcalc,int afmaxi,std::string afrcnvg,std::string afacnvg,std::string afrelax,
int uac2,std::string Pres,int uPres,int afslae,int afrseq,int aflmaxi,std::string aflcnvg,
int aflinit,int Tadj,int sim_mf,int ccmaxi,std::string ccrcnvg,std::string ccacnvg,
std::string ccrelax,int uccc,int mfnmthd,int mfnrseq,int mfnmaxi,std::string mfnrcnvg,
std::string mfnacnvg,std::string mfnrelax,std::string mfngamma,int uccn,int mftmthd,int mftrseq,
int mftmaxi,std::string mftrcnvg,std::string mftacnvg,std::string mftrelax,std::string mftgamma,
int ucct,int mfvmthd,int mfvrseq,int mfvmaxi,std::string mfvrcnvg,std::string mfvacnvg,
std::string mfvrelax,int uccv,int mf_solver,int sim_1dz,int sim_1dd,std::string celldx,
int sim_vjt,int udx,int cvode_mth,std::string cvode_rcnvg,std::string cvode_acnvg,
std::string cvode_dtmax,int tsdens,std::string tsrelax,int tsmaxi,int cnvgSS,int densZP,
int stackD,int dodMdt,std::string date_st,std::string time_st,std::string date_0,std::string time_0,
std::string date_1,std::string time_1,std::string time_step,std::string time_list,std::string time_scrn,
int restart,std::string rstdate,std::string rsttime,int list,int doDlg,int pfsave,int zfsave,
int zcsave,int achvol,int achsave,int abwsave,int cbwsave,int expsave,int ebwsave,
int zaasave,int zbwsave,int rzfsave,int rzmsave,int rz1save,int csmsave,int srfsave,
int logsave,std::vector<int> save,std::vector<std::string> rvals,int BldgFlowZ,int BldgFlowD,
int BldgFlowC,int cfd_ctype,std::string cfd_convcpl,int cfd_var,int cfd_zref,
int cfd_imax,int cfd_dtcmo)
{
d = new RunControlImpl(sim_af,afcalc,afmaxi,afrcnvg,afacnvg,afrelax,uac2,Pres,uPres,afslae,afrseq,
aflmaxi,aflcnvg,aflinit,Tadj,sim_mf,ccmaxi,ccrcnvg,ccacnvg,ccrelax,uccc,mfnmthd,
mfnrseq,mfnmaxi,mfnrcnvg,mfnacnvg,mfnrelax,mfngamma,uccn,mftmthd,mftrseq,mftmaxi,
mftrcnvg,mftacnvg,mftrelax,mftgamma,ucct,mfvmthd,mfvrseq,mfvmaxi,mfvrcnvg,
mfvacnvg,mfvrelax,uccv,mf_solver,sim_1dz,sim_1dd,celldx,sim_vjt,udx,cvode_mth,
cvode_rcnvg,cvode_acnvg,cvode_dtmax,tsdens,tsrelax,tsmaxi,cnvgSS,densZP,stackD,
dodMdt,date_st,time_st,date_0,time_0,date_1,time_1,time_step,time_list,time_scrn,
restart,rstdate,rsttime,list,doDlg,pfsave,zfsave,zcsave,achvol,achsave,abwsave,
cbwsave,expsave,ebwsave,zaasave,zbwsave,rzfsave,rzmsave,rz1save,csmsave,srfsave,
logsave,save,rvals,BldgFlowZ,BldgFlowD,BldgFlowC,cfd_ctype,cfd_convcpl,cfd_var,
cfd_zref,cfd_imax,cfd_dtcmo);
}*/

RunControl::RunControl(const RunControl &other) : m_impl(other.m_impl)
{}

RunControl::~RunControl()
{}

RunControl& RunControl::operator=(const RunControl &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool RunControl::operator==(const RunControl &other) const
{
  return m_impl==other.m_impl;
}

bool RunControl::operator!=(const RunControl &other) const
{
  return m_impl!=other.m_impl;
}

std::string RunControl::write()
{
  return m_impl->write();
}

void RunControl::read(Reader &input)
{
  m_impl->read(input);
}

int RunControl::sim_af() const
{
  return m_impl->sim_af();
}

void RunControl::setSim_af(const int sim_af)
{
  m_impl->setSim_af(sim_af);
}

int RunControl::afcalc() const
{
  return m_impl->afcalc();
}

void RunControl::setAfcalc(const int afcalc)
{
  m_impl->setAfcalc(afcalc);
}

int RunControl::afmaxi() const
{
  return m_impl->afmaxi();
}

void RunControl::setAfmaxi(const int afmaxi)
{
  m_impl->setAfmaxi(afmaxi);
}

double RunControl::afrcnvg() const
{
  return m_impl->afrcnvg();
}

bool RunControl::setAfrcnvg(const double afrcnvg)
{
  return m_impl->setAfrcnvg(afrcnvg);
}

bool RunControl::setAfrcnvg(const std::string &afrcnvg)
{
  return m_impl->setAfrcnvg(afrcnvg);
}

double RunControl::afacnvg() const
{
  return m_impl->afacnvg();
}

bool RunControl::setAfacnvg(const double afacnvg)
{
  return m_impl->setAfacnvg(afacnvg);
}

bool RunControl::setAfacnvg(const std::string &afacnvg)
{
  return m_impl->setAfacnvg(afacnvg);
}

double RunControl::afrelax() const
{
  return m_impl->afrelax();
}

bool RunControl::setAfrelax(const double afrelax)
{
  return m_impl->setAfrelax(afrelax);
}

bool RunControl::setAfrelax(const std::string &afrelax)
{
  return m_impl->setAfrelax(afrelax);
}

int RunControl::uac2() const
{
  return m_impl->uac2();
}

void RunControl::setUac2(const int uac2)
{
  m_impl->setUac2(uac2);
}

double RunControl::Pres() const
{
  return m_impl->Pres();
}

bool RunControl::setPres(const double Pres)
{
  return m_impl->setPres(Pres);
}

bool RunControl::setPres(const std::string &Pres)
{
  return m_impl->setPres(Pres);
}

int RunControl::uPres() const
{
  return m_impl->uPres();
}

void RunControl::setUPres(const int uPres)
{
  m_impl->setUPres(uPres);
}

int RunControl::afslae() const
{
  return m_impl->afslae();
}

void RunControl::setAfslae(const int afslae)
{
  m_impl->setAfslae(afslae);
}

int RunControl::afrseq() const
{
  return m_impl->afrseq();
}

void RunControl::setAfrseq(const int afrseq)
{
  m_impl->setAfrseq(afrseq);
}

int RunControl::aflmaxi() const
{
  return m_impl->aflmaxi();
}

void RunControl::setAflmaxi(const int aflmaxi)
{
  m_impl->setAflmaxi(aflmaxi);
}

double RunControl::aflcnvg() const
{
  return m_impl->aflcnvg();
}

bool RunControl::setAflcnvg(const double aflcnvg)
{
  return m_impl->setAflcnvg(aflcnvg);
}

bool RunControl::setAflcnvg(const std::string &aflcnvg)
{
  return m_impl->setAflcnvg(aflcnvg);
}

int RunControl::aflinit() const
{
  return m_impl->aflinit();
}

void RunControl::setAflinit(const int aflinit)
{
  m_impl->setAflinit(aflinit);
}

int RunControl::Tadj() const
{
  return m_impl->Tadj();
}

void RunControl::setTadj(const int Tadj)
{
  m_impl->setTadj(Tadj);
}

int RunControl::sim_mf() const
{
  return m_impl->sim_mf();
}

void RunControl::setSim_mf(const int sim_mf)
{
  m_impl->setSim_mf(sim_mf);
}

int RunControl::ccmaxi() const
{
  return m_impl->ccmaxi();
}

void RunControl::setCcmaxi(const int ccmaxi)
{
  m_impl->setCcmaxi(ccmaxi);
}

double RunControl::ccrcnvg() const
{
  return m_impl->ccrcnvg();
}

bool RunControl::setCcrcnvg(const double ccrcnvg)
{
  return m_impl->setCcrcnvg(ccrcnvg);
}

bool RunControl::setCcrcnvg(const std::string &ccrcnvg)
{
  return m_impl->setCcrcnvg(ccrcnvg);
}

double RunControl::ccacnvg() const
{
  return m_impl->ccacnvg();
}

bool RunControl::setCcacnvg(const double ccacnvg)
{
  return m_impl->setCcacnvg(ccacnvg);
}

bool RunControl::setCcacnvg(const std::string &ccacnvg)
{
  return m_impl->setCcacnvg(ccacnvg);
}

double RunControl::ccrelax() const
{
  return m_impl->ccrelax();
}

bool RunControl::setCcrelax(const double ccrelax)
{
  return m_impl->setCcrelax(ccrelax);
}

bool RunControl::setCcrelax(const std::string &ccrelax)
{
  return m_impl->setCcrelax(ccrelax);
}

int RunControl::uccc() const
{
  return m_impl->uccc();
}

void RunControl::setUccc(const int uccc)
{
  m_impl->setUccc(uccc);
}

int RunControl::mfnmthd() const
{
  return m_impl->mfnmthd();
}

void RunControl::setMfnmthd(const int mfnmthd)
{
  m_impl->setMfnmthd(mfnmthd);
}

int RunControl::mfnrseq() const
{
  return m_impl->mfnrseq();
}

void RunControl::setMfnrseq(const int mfnrseq)
{
  m_impl->setMfnrseq(mfnrseq);
}

int RunControl::mfnmaxi() const
{
  return m_impl->mfnmaxi();
}

void RunControl::setMfnmaxi(const int mfnmaxi)
{
  m_impl->setMfnmaxi(mfnmaxi);
}

double RunControl::mfnrcnvg() const
{
  return m_impl->mfnrcnvg();
}

bool RunControl::setMfnrcnvg(const double mfnrcnvg)
{
  return m_impl->setMfnrcnvg(mfnrcnvg);
}

bool RunControl::setMfnrcnvg(const std::string &mfnrcnvg)
{
  return m_impl->setMfnrcnvg(mfnrcnvg);
}

double RunControl::mfnacnvg() const
{
  return m_impl->mfnacnvg();
}

bool RunControl::setMfnacnvg(const double mfnacnvg)
{
  return m_impl->setMfnacnvg(mfnacnvg);
}

bool RunControl::setMfnacnvg(const std::string &mfnacnvg)
{
  return m_impl->setMfnacnvg(mfnacnvg);
}

double RunControl::mfnrelax() const
{
  return m_impl->mfnrelax();
}

bool RunControl::setMfnrelax(const double mfnrelax)
{
  return m_impl->setMfnrelax(mfnrelax);
}

bool RunControl::setMfnrelax(const std::string &mfnrelax)
{
  return m_impl->setMfnrelax(mfnrelax);
}

double RunControl::mfngamma() const
{
  return m_impl->mfngamma();
}

bool RunControl::setMfngamma(const double mfngamma)
{
  return m_impl->setMfngamma(mfngamma);
}

bool RunControl::setMfngamma(const std::string &mfngamma)
{
  return m_impl->setMfngamma(mfngamma);
}

int RunControl::uccn() const
{
  return m_impl->uccn();
}

void RunControl::setUccn(const int uccn)
{
  m_impl->setUccn(uccn);
}

int RunControl::mftmthd() const
{
  return m_impl->mftmthd();
}

void RunControl::setMftmthd(const int mftmthd)
{
  m_impl->setMftmthd(mftmthd);
}

int RunControl::mftrseq() const
{
  return m_impl->mftrseq();
}

void RunControl::setMftrseq(const int mftrseq)
{
  m_impl->setMftrseq(mftrseq);
}

int RunControl::mftmaxi() const
{
  return m_impl->mftmaxi();
}

void RunControl::setMftmaxi(const int mftmaxi)
{
  m_impl->setMftmaxi(mftmaxi);
}

double RunControl::mftrcnvg() const
{
  return m_impl->mftrcnvg();
}

bool RunControl::setMftrcnvg(const double mftrcnvg)
{
  return m_impl->setMftrcnvg(mftrcnvg);
}

bool RunControl::setMftrcnvg(const std::string &mftrcnvg)
{
  return m_impl->setMftrcnvg(mftrcnvg);
}

double RunControl::mftacnvg() const
{
  return m_impl->mftacnvg();
}

bool RunControl::setMftacnvg(const double mftacnvg)
{
  return m_impl->setMftacnvg(mftacnvg);
}

bool RunControl::setMftacnvg(const std::string &mftacnvg)
{
  return m_impl->setMftacnvg(mftacnvg);
}

double RunControl::mftrelax() const
{
  return m_impl->mftrelax();
}

bool RunControl::setMftrelax(const double mftrelax)
{
  return m_impl->setMftrelax(mftrelax);
}

bool RunControl::setMftrelax(const std::string &mftrelax)
{
  return m_impl->setMftrelax(mftrelax);
}

double RunControl::mftgamma() const
{
  return m_impl->mftgamma();
}

bool RunControl::setMftgamma(const double mftgamma)
{
  return m_impl->setMftgamma(mftgamma);
}

bool RunControl::setMftgamma(const std::string &mftgamma)
{
  return m_impl->setMftgamma(mftgamma);
}

int RunControl::ucct() const
{
  return m_impl->ucct();
}

void RunControl::setUcct(const int ucct)
{
  m_impl->setUcct(ucct);
}

int RunControl::mfvmthd() const
{
  return m_impl->mfvmthd();
}

void RunControl::setMfvmthd(const int mfvmthd)
{
  m_impl->setMfvmthd(mfvmthd);
}

int RunControl::mfvrseq() const
{
  return m_impl->mfvrseq();
}

void RunControl::setMfvrseq(const int mfvrseq)
{
  m_impl->setMfvrseq(mfvrseq);
}

int RunControl::mfvmaxi() const
{
  return m_impl->mfvmaxi();
}

void RunControl::setMfvmaxi(const int mfvmaxi)
{
  m_impl->setMfvmaxi(mfvmaxi);
}

double RunControl::mfvrcnvg() const
{
  return m_impl->mfvrcnvg();
}

bool RunControl::setMfvrcnvg(const double mfvrcnvg)
{
  return m_impl->setMfvrcnvg(mfvrcnvg);
}

bool RunControl::setMfvrcnvg(const std::string &mfvrcnvg)
{
  return m_impl->setMfvrcnvg(mfvrcnvg);
}

double RunControl::mfvacnvg() const
{
  return m_impl->mfvacnvg();
}

bool RunControl::setMfvacnvg(const double mfvacnvg)
{
  return m_impl->setMfvacnvg(mfvacnvg);
}

bool RunControl::setMfvacnvg(const std::string &mfvacnvg)
{
  return m_impl->setMfvacnvg(mfvacnvg);
}

double RunControl::mfvrelax() const
{
  return m_impl->mfvrelax();
}

bool RunControl::setMfvrelax(const double mfvrelax)
{
  return m_impl->setMfvrelax(mfvrelax);
}

bool RunControl::setMfvrelax(const std::string &mfvrelax)
{
  return m_impl->setMfvrelax(mfvrelax);
}

int RunControl::uccv() const
{
  return m_impl->uccv();
}

void RunControl::setUccv(const int uccv)
{
  m_impl->setUccv(uccv);
}

int RunControl::mf_solver() const
{
  return m_impl->mf_solver();
}

void RunControl::setMf_solver(const int mf_solver)
{
  m_impl->setMf_solver(mf_solver);
}

int RunControl::sim_1dz() const
{
  return m_impl->sim_1dz();
}

void RunControl::setSim_1dz(const int sim_1dz)
{
  m_impl->setSim_1dz(sim_1dz);
}

int RunControl::sim_1dd() const
{
  return m_impl->sim_1dd();
}

void RunControl::setSim_1dd(const int sim_1dd)
{
  m_impl->setSim_1dd(sim_1dd);
}

double RunControl::celldx() const
{
  return m_impl->celldx();
}

bool RunControl::setCelldx(const double celldx)
{
  return m_impl->setCelldx(celldx);
}

bool RunControl::setCelldx(const std::string &celldx)
{
  return m_impl->setCelldx(celldx);
}

int RunControl::sim_vjt() const
{
  return m_impl->sim_vjt();
}

void RunControl::setSim_vjt(const int sim_vjt)
{
  m_impl->setSim_vjt(sim_vjt);
}

int RunControl::udx() const
{
  return m_impl->udx();
}

void RunControl::setUdx(const int udx)
{
  m_impl->setUdx(udx);
}

int RunControl::cvode_mth() const
{
  return m_impl->cvode_mth();
}

void RunControl::setCvode_mth(const int cvode_mth)
{
  m_impl->setCvode_mth(cvode_mth);
}

double RunControl::cvode_rcnvg() const
{
  return m_impl->cvode_rcnvg();
}

bool RunControl::setCvode_rcnvg(const double cvode_rcnvg)
{
  return m_impl->setCvode_rcnvg(cvode_rcnvg);
}

bool RunControl::setCvode_rcnvg(const std::string &cvode_rcnvg)
{
  return m_impl->setCvode_rcnvg(cvode_rcnvg);
}

double RunControl::cvode_acnvg() const
{
  return m_impl->cvode_acnvg();
}

bool RunControl::setCvode_acnvg(const double cvode_acnvg)
{
  return m_impl->setCvode_acnvg(cvode_acnvg);
}

bool RunControl::setCvode_acnvg(const std::string &cvode_acnvg)
{
  return m_impl->setCvode_acnvg(cvode_acnvg);
}

double RunControl::cvode_dtmax() const
{
  return m_impl->cvode_dtmax();
}

bool RunControl::setCvode_dtmax(const double cvode_dtmax)
{
  return m_impl->setCvode_dtmax(cvode_dtmax);
}

bool RunControl::setCvode_dtmax(const std::string &cvode_dtmax)
{
  return m_impl->setCvode_dtmax(cvode_dtmax);
}

int RunControl::tsdens() const
{
  return m_impl->tsdens();
}

void RunControl::setTsdens(const int tsdens)
{
  m_impl->setTsdens(tsdens);
}

double RunControl::tsrelax() const
{
  return m_impl->tsrelax();
}

bool RunControl::setTsrelax(const double tsrelax)
{
  return m_impl->setTsrelax(tsrelax);
}

bool RunControl::setTsrelax(const std::string &tsrelax)
{
  return m_impl->setTsrelax(tsrelax);
}

int RunControl::tsmaxi() const
{
  return m_impl->tsmaxi();
}

void RunControl::setTsmaxi(const int tsmaxi)
{
  m_impl->setTsmaxi(tsmaxi);
}

int RunControl::cnvgSS() const
{
  return m_impl->cnvgSS();
}

void RunControl::setCnvgSS(const int cnvgSS)
{
  m_impl->setCnvgSS(cnvgSS);
}

int RunControl::densZP() const
{
  return m_impl->densZP();
}

void RunControl::setDensZP(const int densZP)
{
  m_impl->setDensZP(densZP);
}

int RunControl::stackD() const
{
  return m_impl->stackD();
}

void RunControl::setStackD(const int stackD)
{
  m_impl->setStackD(stackD);
}

int RunControl::dodMdt() const
{
  return m_impl->dodMdt();
}

void RunControl::setDodMdt(const int dodMdt)
{
  m_impl->setDodMdt(dodMdt);
}

std::string RunControl::date_st() const
{
  return m_impl->date_st();
}

void RunControl::setDate_st(const std::string &date_st)
{
  m_impl->setDate_st(date_st);
}

std::string RunControl::time_st() const
{
  return m_impl->time_st();
}

void RunControl::setTime_st(const std::string &time_st)
{
  m_impl->setTime_st(time_st);
}

std::string RunControl::date_0() const
{
  return m_impl->date_0();
}

void RunControl::setDate_0(const std::string &date_0)
{
  m_impl->setDate_0(date_0);
}

std::string RunControl::time_0() const
{
  return m_impl->time_0();
}

void RunControl::setTime_0(const std::string &time_0)
{
  m_impl->setTime_0(time_0);
}

std::string RunControl::date_1() const
{
  return m_impl->date_1();
}

void RunControl::setDate_1(const std::string &date_1)
{
  m_impl->setDate_1(date_1);
}

std::string RunControl::time_1() const
{
  return m_impl->time_1();
}

void RunControl::setTime_1(const std::string &time_1)
{
  m_impl->setTime_1(time_1);
}

std::string RunControl::time_step() const
{
  return m_impl->time_step();
}

void RunControl::setTime_step(const std::string &time_step)
{
  m_impl->setTime_step(time_step);
}

std::string RunControl::time_list() const
{
  return m_impl->time_list();
}

void RunControl::setTime_list(const std::string &time_list)
{
  m_impl->setTime_list(time_list);
}

std::string RunControl::time_scrn() const
{
  return m_impl->time_scrn();
}

void RunControl::setTime_scrn(const std::string &time_scrn)
{
  m_impl->setTime_scrn(time_scrn);
}

int RunControl::restart() const
{
  return m_impl->restart();
}

void RunControl::setRestart(const int restart)
{
  m_impl->setRestart(restart);
}

std::string RunControl::rstdate() const
{
  return m_impl->rstdate();
}

void RunControl::setRstdate(const std::string &rstdate)
{
  m_impl->setRstdate(rstdate);
}

std::string RunControl::rsttime() const
{
  return m_impl->rsttime();
}

void RunControl::setRsttime(const std::string &rsttime)
{
  m_impl->setRsttime(rsttime);
}

int RunControl::list() const
{
  return m_impl->list();
}

void RunControl::setList(const int list)
{
  m_impl->setList(list);
}

int RunControl::doDlg() const
{
  return m_impl->doDlg();
}

void RunControl::setDoDlg(const int doDlg)
{
  m_impl->setDoDlg(doDlg);
}

int RunControl::pfsave() const
{
  return m_impl->pfsave();
}

void RunControl::setPfsave(const int pfsave)
{
  m_impl->setPfsave(pfsave);
}

int RunControl::zfsave() const
{
  return m_impl->zfsave();
}

void RunControl::setZfsave(const int zfsave)
{
  m_impl->setZfsave(zfsave);
}

int RunControl::zcsave() const
{
  return m_impl->zcsave();
}

void RunControl::setZcsave(const int zcsave)
{
  m_impl->setZcsave(zcsave);
}

int RunControl::achvol() const
{
  return m_impl->achvol();
}

void RunControl::setAchvol(const int achvol)
{
  m_impl->setAchvol(achvol);
}

int RunControl::achsave() const
{
  return m_impl->achsave();
}

void RunControl::setAchsave(const int achsave)
{
  m_impl->setAchsave(achsave);
}

int RunControl::abwsave() const
{
  return m_impl->abwsave();
}

void RunControl::setAbwsave(const int abwsave)
{
  m_impl->setAbwsave(abwsave);
}

int RunControl::cbwsave() const
{
  return m_impl->cbwsave();
}

void RunControl::setCbwsave(const int cbwsave)
{
  m_impl->setCbwsave(cbwsave);
}

int RunControl::expsave() const
{
  return m_impl->expsave();
}

void RunControl::setExpsave(const int expsave)
{
  m_impl->setExpsave(expsave);
}

int RunControl::ebwsave() const
{
  return m_impl->ebwsave();
}

void RunControl::setEbwsave(const int ebwsave)
{
  m_impl->setEbwsave(ebwsave);
}

int RunControl::zaasave() const
{
  return m_impl->zaasave();
}

void RunControl::setZaasave(const int zaasave)
{
  m_impl->setZaasave(zaasave);
}

int RunControl::zbwsave() const
{
  return m_impl->zbwsave();
}

void RunControl::setZbwsave(const int zbwsave)
{
  m_impl->setZbwsave(zbwsave);
}

int RunControl::rzfsave() const
{
  return m_impl->rzfsave();
}

void RunControl::setRzfsave(const int rzfsave)
{
  m_impl->setRzfsave(rzfsave);
}

int RunControl::rzmsave() const
{
  return m_impl->rzmsave();
}

void RunControl::setRzmsave(const int rzmsave)
{
  m_impl->setRzmsave(rzmsave);
}

int RunControl::rz1save() const
{
  return m_impl->rz1save();
}

void RunControl::setRz1save(const int rz1save)
{
  m_impl->setRz1save(rz1save);
}

int RunControl::csmsave() const
{
  return m_impl->csmsave();
}

void RunControl::setCsmsave(const int csmsave)
{
  m_impl->setCsmsave(csmsave);
}

int RunControl::srfsave() const
{
  return m_impl->srfsave();
}

void RunControl::setSrfsave(const int srfsave)
{
  m_impl->setSrfsave(srfsave);
}

int RunControl::logsave() const
{
  return m_impl->logsave();
}

void RunControl::setLogsave(const int logsave)
{
  m_impl->setLogsave(logsave);
}

std::vector<int> RunControl::save() const
{
  return m_impl->save();
}

void RunControl::setSave(const std::vector<int> &save)
{
  m_impl->setSave(save);
}

std::vector<double> RunControl::rvals() const
{
  return m_impl->rvals();
}

bool RunControl::setRvals(const std::vector<double> &rvals)
{
  return m_impl->setRvals(rvals);
}

bool RunControl::setRvals(const std::vector<std::string> &rvals)
{
  return m_impl->setRvals(rvals);
}

int RunControl::BldgFlowZ() const
{
  return m_impl->BldgFlowZ();
}

void RunControl::setBldgFlowZ(const int BldgFlowZ)
{
  m_impl->setBldgFlowZ(BldgFlowZ);
}

int RunControl::BldgFlowD() const
{
  return m_impl->BldgFlowD();
}

void RunControl::setBldgFlowD(const int BldgFlowD)
{
  m_impl->setBldgFlowD(BldgFlowD);
}

int RunControl::BldgFlowC() const
{
  return m_impl->BldgFlowC();
}

void RunControl::setBldgFlowC(const int BldgFlowC)
{
  m_impl->setBldgFlowC(BldgFlowC);
}

int RunControl::cfd_ctype() const
{
  return m_impl->cfd_ctype();
}

void RunControl::setCfd_ctype(const int cfd_ctype)
{
  m_impl->setCfd_ctype(cfd_ctype);
}

double RunControl::cfd_convcpl() const
{
  return m_impl->cfd_convcpl();
}

bool RunControl::setCfd_convcpl(const double cfd_convcpl)
{
  return m_impl->setCfd_convcpl(cfd_convcpl);
}

bool RunControl::setCfd_convcpl(const std::string &cfd_convcpl)
{
  return m_impl->setCfd_convcpl(cfd_convcpl);
}

int RunControl::cfd_var() const
{
  return m_impl->cfd_var();
}

void RunControl::setCfd_var(const int cfd_var)
{
  m_impl->setCfd_var(cfd_var);
}

int RunControl::cfd_zref() const
{
  return m_impl->cfd_zref();
}

void RunControl::setCfd_zref(const int cfd_zref)
{
  m_impl->setCfd_zref(cfd_zref);
}

int RunControl::cfd_imax() const
{
  return m_impl->cfd_imax();
}

void RunControl::setCfd_imax(const int cfd_imax)
{
  m_impl->setCfd_imax(cfd_imax);
}

int RunControl::cfd_dtcmo() const
{
  return m_impl->cfd_dtcmo();
}

void RunControl::setCfd_dtcmo(const int cfd_dtcmo)
{
  m_impl->setCfd_dtcmo(cfd_dtcmo);
}

RunControl::RunControlImpl::RunControlImpl() : m_sim_af(0), m_afcalc(0), m_afmaxi(0), m_afrcnvg(PRJFLOAT("0.0")), m_afacnvg(PRJFLOAT("0.0")),
m_afrelax(PRJFLOAT("0.0")), m_uac2(0), m_Pres(PRJFLOAT("0.0")), m_uPres(0), m_afslae(0), m_afrseq(0), m_aflmaxi(0), m_aflcnvg(PRJFLOAT("0.0")),
m_aflinit(0), m_Tadj(0), m_sim_mf(0), m_ccmaxi(0), m_ccrcnvg(PRJFLOAT("0.0")), m_ccacnvg(PRJFLOAT("0.0")), m_ccrelax(PRJFLOAT("0.0")), m_uccc(0),
m_mfnmthd(0), m_mfnrseq(0), m_mfnmaxi(0), m_mfnrcnvg(PRJFLOAT("0.0")), m_mfnacnvg(PRJFLOAT("0.0")), m_mfnrelax(PRJFLOAT("0.0")),
m_mfngamma(PRJFLOAT("0.0")), m_uccn(0), m_mftmthd(0), m_mftrseq(0), m_mftmaxi(0), m_mftrcnvg(PRJFLOAT("0.0")), m_mftacnvg(PRJFLOAT("0.0")),
m_mftrelax(PRJFLOAT("0.0")), m_mftgamma(PRJFLOAT("0.0")), m_ucct(0), m_mfvmthd(0), m_mfvrseq(0), m_mfvmaxi(0), m_mfvrcnvg(PRJFLOAT("0.0")),
m_mfvacnvg(PRJFLOAT("0.0")), m_mfvrelax(PRJFLOAT("0.0")), m_uccv(0), m_mf_solver(0), m_sim_1dz(0), m_sim_1dd(0), m_celldx(PRJFLOAT("0.0")),
m_sim_vjt(0), m_udx(0), m_cvode_mth(0), m_cvode_rcnvg(PRJFLOAT("0.0")), m_cvode_acnvg(PRJFLOAT("0.0")), m_cvode_dtmax(PRJFLOAT("0.0")),
m_tsdens(0), m_tsrelax(PRJFLOAT("0.0")), m_tsmaxi(0), m_cnvgSS(0), m_densZP(0), m_stackD(0), m_dodMdt(0), m_restart(0), m_list(0), m_doDlg(0),
m_pfsave(0), m_zfsave(0), m_zcsave(0), m_achvol(0), m_achsave(0), m_abwsave(0), m_cbwsave(0), m_expsave(0), m_ebwsave(0), m_zaasave(0),
m_zbwsave(0), m_rzfsave(0), m_rzmsave(0), m_rz1save(0), m_csmsave(0), m_srfsave(0), m_logsave(0), m_BldgFlowZ(0), m_BldgFlowD(0),
m_BldgFlowC(0), m_cfd_ctype(0), m_cfd_convcpl(PRJFLOAT("0.0")), m_cfd_var(0), m_cfd_zref(0), m_cfd_imax(0), m_cfd_dtcmo(0)
{}

RunControl::RunControlImpl::RunControlImpl(int sim_af, int afcalc, int afmaxi, double afrcnvg, double afacnvg, double afrelax,
  int uac2, double Pres, int uPres, int afslae, int afrseq, int aflmaxi,
  double aflcnvg, int aflinit, int Tadj, int sim_mf, int ccmaxi, double ccrcnvg,
  double ccacnvg, double ccrelax, int uccc, int mfnmthd, int mfnrseq, int mfnmaxi,
  double mfnrcnvg, double mfnacnvg, double mfnrelax, double mfngamma, int uccn,
  int mftmthd, int mftrseq, int mftmaxi, double mftrcnvg, double mftacnvg,
  double mftrelax, double mftgamma, int ucct, int mfvmthd, int mfvrseq,
  int mfvmaxi, double mfvrcnvg, double mfvacnvg, double mfvrelax, int uccv,
  int mf_solver, int sim_1dz, int sim_1dd, double celldx, int sim_vjt, int udx,
  int cvode_mth, double cvode_rcnvg, double cvode_acnvg, double cvode_dtmax,
  int tsdens, double tsrelax, int tsmaxi, int cnvgSS, int densZP, int stackD,
  int dodMdt, std::string date_st, std::string time_st, std::string date_0, std::string time_0,
  std::string date_1, std::string time_1, std::string time_step, std::string time_list,
  std::string time_scrn, int restart, std::string rstdate, std::string rsttime, int list,
  int doDlg, int pfsave, int zfsave, int zcsave, int achvol, int achsave,
  int abwsave, int cbwsave, int expsave, int ebwsave, int zaasave, int zbwsave,
  int rzfsave, int rzmsave, int rz1save, int csmsave, int srfsave, int logsave,
  std::vector<int> save, std::vector<double> rvals, int BldgFlowZ, int BldgFlowD,
  int BldgFlowC, int cfd_ctype, double cfd_convcpl, int cfd_var, int cfd_zref,
  int cfd_imax, int cfd_dtcmo) : RunControl::RunControlImpl()
{
  setSim_af(sim_af);
  setAfcalc(afcalc);
  setAfmaxi(afmaxi);
  setAfrcnvg(afrcnvg);
  setAfacnvg(afacnvg);
  setAfrelax(afrelax);
  setUac2(uac2);
  setPres(Pres);
  setUPres(uPres);
  setAfslae(afslae);
  setAfrseq(afrseq);
  setAflmaxi(aflmaxi);
  setAflcnvg(aflcnvg);
  setAflinit(aflinit);
  setTadj(Tadj);
  setSim_mf(sim_mf);
  setCcmaxi(ccmaxi);
  setCcrcnvg(ccrcnvg);
  setCcacnvg(ccacnvg);
  setCcrelax(ccrelax);
  setUccc(uccc);
  setMfnmthd(mfnmthd);
  setMfnrseq(mfnrseq);
  setMfnmaxi(mfnmaxi);
  setMfnrcnvg(mfnrcnvg);
  setMfnacnvg(mfnacnvg);
  setMfnrelax(mfnrelax);
  setMfngamma(mfngamma);
  setUccn(uccn);
  setMftmthd(mftmthd);
  setMftrseq(mftrseq);
  setMftmaxi(mftmaxi);
  setMftrcnvg(mftrcnvg);
  setMftacnvg(mftacnvg);
  setMftrelax(mftrelax);
  setMftgamma(mftgamma);
  setUcct(ucct);
  setMfvmthd(mfvmthd);
  setMfvrseq(mfvrseq);
  setMfvmaxi(mfvmaxi);
  setMfvrcnvg(mfvrcnvg);
  setMfvacnvg(mfvacnvg);
  setMfvrelax(mfvrelax);
  setUccv(uccv);
  setMf_solver(mf_solver);
  setSim_1dz(sim_1dz);
  setSim_1dd(sim_1dd);
  setCelldx(celldx);
  setSim_vjt(sim_vjt);
  setUdx(udx);
  setCvode_mth(cvode_mth);
  setCvode_rcnvg(cvode_rcnvg);
  setCvode_acnvg(cvode_acnvg);
  setCvode_dtmax(cvode_dtmax);
  setTsdens(tsdens);
  setTsrelax(tsrelax);
  setTsmaxi(tsmaxi);
  setCnvgSS(cnvgSS);
  setDensZP(densZP);
  setStackD(stackD);
  setDodMdt(dodMdt);
  setDate_st(date_st);
  setTime_st(time_st);
  setDate_0(date_0);
  setTime_0(time_0);
  setDate_1(date_1);
  setTime_1(time_1);
  setTime_step(time_step);
  setTime_list(time_list);
  setTime_scrn(time_scrn);
  setRestart(restart);
  setRstdate(rstdate);
  setRsttime(rsttime);
  setList(list);
  setDoDlg(doDlg);
  setPfsave(pfsave);
  setZfsave(zfsave);
  setZcsave(zcsave);
  setAchvol(achvol);
  setAchsave(achsave);
  setAbwsave(abwsave);
  setCbwsave(cbwsave);
  setExpsave(expsave);
  setEbwsave(ebwsave);
  setZaasave(zaasave);
  setZbwsave(zbwsave);
  setRzfsave(rzfsave);
  setRzmsave(rzmsave);
  setRz1save(rz1save);
  setCsmsave(csmsave);
  setSrfsave(srfsave);
  setLogsave(logsave);
  setSave(save);
  setRvals(rvals);
  setBldgFlowZ(BldgFlowZ);
  setBldgFlowD(BldgFlowD);
  setBldgFlowC(BldgFlowC);
  setCfd_ctype(cfd_ctype);
  setCfd_convcpl(cfd_convcpl);
  setCfd_var(cfd_var);
  setCfd_zref(cfd_zref);
  setCfd_imax(cfd_imax);
  setCfd_dtcmo(cfd_dtcmo);
}

RunControl::RunControlImpl::RunControlImpl(int sim_af, int afcalc, int afmaxi, std::string afrcnvg, std::string afacnvg,
  std::string afrelax, int uac2, std::string Pres, int uPres, int afslae, int afrseq,
  int aflmaxi, std::string aflcnvg, int aflinit, int Tadj, int sim_mf, int ccmaxi,
  std::string ccrcnvg, std::string ccacnvg, std::string ccrelax, int uccc, int mfnmthd,
  int mfnrseq, int mfnmaxi, std::string mfnrcnvg, std::string mfnacnvg, std::string mfnrelax,
  std::string mfngamma, int uccn, int mftmthd, int mftrseq, int mftmaxi,
  std::string mftrcnvg, std::string mftacnvg, std::string mftrelax, std::string mftgamma,
  int ucct, int mfvmthd, int mfvrseq, int mfvmaxi, std::string mfvrcnvg,
  std::string mfvacnvg, std::string mfvrelax, int uccv, int mf_solver, int sim_1dz,
  int sim_1dd, std::string celldx, int sim_vjt, int udx, int cvode_mth,
  std::string cvode_rcnvg, std::string cvode_acnvg, std::string cvode_dtmax, int tsdens,
  std::string tsrelax, int tsmaxi, int cnvgSS, int densZP, int stackD, int dodMdt,
  std::string date_st, std::string time_st, std::string date_0, std::string time_0, std::string date_1,
  std::string time_1, std::string time_step, std::string time_list, std::string time_scrn,
  int restart, std::string rstdate, std::string rsttime, int list, int doDlg, int pfsave,
  int zfsave, int zcsave, int achvol, int achsave, int abwsave, int cbwsave,
  int expsave, int ebwsave, int zaasave, int zbwsave, int rzfsave, int rzmsave,
  int rz1save, int csmsave, int srfsave, int logsave, std::vector<int> save,
  std::vector<std::string> rvals, int BldgFlowZ, int BldgFlowD, int BldgFlowC,
  int cfd_ctype, std::string cfd_convcpl, int cfd_var, int cfd_zref, int cfd_imax,
  int cfd_dtcmo) : RunControl::RunControlImpl()
{
  setSim_af(sim_af);
  setAfcalc(afcalc);
  setAfmaxi(afmaxi);
  setAfrcnvg(afrcnvg);
  setAfacnvg(afacnvg);
  setAfrelax(afrelax);
  setUac2(uac2);
  setPres(Pres);
  setUPres(uPres);
  setAfslae(afslae);
  setAfrseq(afrseq);
  setAflmaxi(aflmaxi);
  setAflcnvg(aflcnvg);
  setAflinit(aflinit);
  setTadj(Tadj);
  setSim_mf(sim_mf);
  setCcmaxi(ccmaxi);
  setCcrcnvg(ccrcnvg);
  setCcacnvg(ccacnvg);
  setCcrelax(ccrelax);
  setUccc(uccc);
  setMfnmthd(mfnmthd);
  setMfnrseq(mfnrseq);
  setMfnmaxi(mfnmaxi);
  setMfnrcnvg(mfnrcnvg);
  setMfnacnvg(mfnacnvg);
  setMfnrelax(mfnrelax);
  setMfngamma(mfngamma);
  setUccn(uccn);
  setMftmthd(mftmthd);
  setMftrseq(mftrseq);
  setMftmaxi(mftmaxi);
  setMftrcnvg(mftrcnvg);
  setMftacnvg(mftacnvg);
  setMftrelax(mftrelax);
  setMftgamma(mftgamma);
  setUcct(ucct);
  setMfvmthd(mfvmthd);
  setMfvrseq(mfvrseq);
  setMfvmaxi(mfvmaxi);
  setMfvrcnvg(mfvrcnvg);
  setMfvacnvg(mfvacnvg);
  setMfvrelax(mfvrelax);
  setUccv(uccv);
  setMf_solver(mf_solver);
  setSim_1dz(sim_1dz);
  setSim_1dd(sim_1dd);
  setCelldx(celldx);
  setSim_vjt(sim_vjt);
  setUdx(udx);
  setCvode_mth(cvode_mth);
  setCvode_rcnvg(cvode_rcnvg);
  setCvode_acnvg(cvode_acnvg);
  setCvode_dtmax(cvode_dtmax);
  setTsdens(tsdens);
  setTsrelax(tsrelax);
  setTsmaxi(tsmaxi);
  setCnvgSS(cnvgSS);
  setDensZP(densZP);
  setStackD(stackD);
  setDodMdt(dodMdt);
  setDate_st(date_st);
  setTime_st(time_st);
  setDate_0(date_0);
  setTime_0(time_0);
  setDate_1(date_1);
  setTime_1(time_1);
  setTime_step(time_step);
  setTime_list(time_list);
  setTime_scrn(time_scrn);
  setRestart(restart);
  setRstdate(rstdate);
  setRsttime(rsttime);
  setList(list);
  setDoDlg(doDlg);
  setPfsave(pfsave);
  setZfsave(zfsave);
  setZcsave(zcsave);
  setAchvol(achvol);
  setAchsave(achsave);
  setAbwsave(abwsave);
  setCbwsave(cbwsave);
  setExpsave(expsave);
  setEbwsave(ebwsave);
  setZaasave(zaasave);
  setZbwsave(zbwsave);
  setRzfsave(rzfsave);
  setRzmsave(rzmsave);
  setRz1save(rz1save);
  setCsmsave(csmsave);
  setSrfsave(srfsave);
  setLogsave(logsave);
  setSave(save);
  setRvals(rvals);
  setBldgFlowZ(BldgFlowZ);
  setBldgFlowD(BldgFlowD);
  setBldgFlowC(BldgFlowC);
  setCfd_ctype(cfd_ctype);
  setCfd_convcpl(cfd_convcpl);
  setCfd_var(cfd_var);
  setCfd_zref(cfd_zref);
  setCfd_imax(cfd_imax);
  setCfd_dtcmo(cfd_dtcmo);
}

void RunControl::RunControlImpl::read(Reader& input)
{
  setSim_af(input.read<int>());
  setAfcalc(input.read<int>());
  setAfmaxi(input.read<int>());
  setAfrcnvg(input.readNumber<std::string>());
  setAfacnvg(input.readNumber<std::string>());
  setAfrelax(input.readNumber<std::string>());
  setUac2(input.read<int>());
  setPres(input.readNumber<std::string>());
  setUPres(input.read<int>());
  setAfslae(input.read<int>());
  setAfrseq(input.read<int>());
  setAflmaxi(input.read<int>());
  setAflcnvg(input.readNumber<std::string>());
  setAflinit(input.read<int>());
  setTadj(input.read<int>());
  setSim_mf(input.read<int>());
  setCcmaxi(input.read<int>());
  setCcrcnvg(input.readNumber<std::string>());
  setCcacnvg(input.readNumber<std::string>());
  setCcrelax(input.readNumber<std::string>());
  setUccc(input.read<int>());
  setMfnmthd(input.read<int>());
  setMfnrseq(input.read<int>());
  setMfnmaxi(input.read<int>());
  setMfnrcnvg(input.readNumber<std::string>());
  setMfnacnvg(input.readNumber<std::string>());
  setMfnrelax(input.readNumber<std::string>());
  setMfngamma(input.readNumber<std::string>());
  setUccn(input.read<int>());
  setMftmthd(input.read<int>());
  setMftrseq(input.read<int>());
  setMftmaxi(input.read<int>());
  setMftrcnvg(input.readNumber<std::string>());
  setMftacnvg(input.readNumber<std::string>());
  setMftrelax(input.readNumber<std::string>());
  setMftgamma(input.readNumber<std::string>());
  setUcct(input.read<int>());
  setMfvmthd(input.read<int>());
  setMfvrseq(input.read<int>());
  setMfvmaxi(input.read<int>());
  setMfvrcnvg(input.readNumber<std::string>());
  setMfvacnvg(input.readNumber<std::string>());
  setMfvrelax(input.readNumber<std::string>());
  setUccv(input.read<int>());
  setMf_solver(input.read<int>());
  setSim_1dz(input.read<int>());
  setSim_1dd(input.read<int>());
  setCelldx(input.readNumber<std::string>());
  setSim_vjt(input.read<int>());
  setUdx(input.read<int>());
  setCvode_mth(input.read<int>());
  setCvode_rcnvg(input.readNumber<std::string>());
  setCvode_acnvg(input.readNumber<std::string>());
  setCvode_dtmax(input.readNumber<std::string>());
  setTsdens(input.read<int>());
  setTsrelax(input.readNumber<std::string>());
  setTsmaxi(input.read<int>());
  setCnvgSS(input.read<int>());
  setDensZP(input.read<int>());
  setStackD(input.read<int>());
  setDodMdt(input.read<int>());
  setDate_st(input.readString());
  setTime_st(input.readString());
  setDate_0(input.readString());
  setTime_0(input.readString());
  setDate_1(input.readString());
  setTime_1(input.readString());
  setTime_step(input.readString());
  setTime_list(input.readString());
  setTime_scrn(input.readString());
  setRestart(input.read<int>());
  setRstdate(input.readString());
  setRsttime(input.readString());
  setList(input.read<int>());
  setDoDlg(input.read<int>());
  setPfsave(input.read<int>());
  setZfsave(input.read<int>());
  setZcsave(input.read<int>());
  setAchvol(input.read<int>());
  setAchsave(input.read<int>());
  setAbwsave(input.read<int>());
  setCbwsave(input.read<int>());
  setExpsave(input.read<int>());
  setEbwsave(input.read<int>());
  setZaasave(input.read<int>());
  setZbwsave(input.read<int>());
  setRzfsave(input.read<int>());
  setRzmsave(input.read<int>());
  setRz1save(input.read<int>());
  setCsmsave(input.read<int>());
  setSrfsave(input.read<int>());
  setLogsave(input.read<int>());
  std::vector<int> save;
  for (int i = 0; i < 16; i++) {
    save.push_back(input.read<int>());
  }
  setSave(save);
  int nrvals = input.read<int>();
  std::vector<std::string> rvals;
  for (int i = 0; i < nrvals; i++) {
    rvals.push_back(input.read<std::string>());
  }
  setRvals(rvals);
  setBldgFlowZ(input.read<int>());
  setBldgFlowD(input.read<int>());
  setBldgFlowC(input.read<int>());
  setCfd_ctype(input.read<int>());
  setCfd_convcpl(input.readNumber<std::string>());
  setCfd_var(input.read<int>());
  setCfd_zref(input.read<int>());
  setCfd_imax(input.read<int>());
  setCfd_dtcmo(input.read<int>());
}

std::string RunControl::RunControlImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_sim_af) + ' ' + ANY_TO_STR(m_afcalc) + ' ' + ANY_TO_STR(m_afmaxi) + ' '
    + PRJFLOAT_TO_STR(m_afrcnvg) + ' ' + PRJFLOAT_TO_STR(m_afacnvg) + ' ' + PRJFLOAT_TO_STR(m_afrelax) + ' '
    + ANY_TO_STR(m_uac2) + ' ' + PRJFLOAT_TO_STR(m_Pres) + ' ' + ANY_TO_STR(m_uPres) + '\n';
  string += ANY_TO_STR(m_afslae) + ' ' + ANY_TO_STR(m_afrseq) + ' ' + ANY_TO_STR(m_aflmaxi) + ' '
    + PRJFLOAT_TO_STR(m_aflcnvg) + ' ' + ANY_TO_STR(m_aflinit) + ' ' + ANY_TO_STR(m_Tadj) + '\n';
  string += ANY_TO_STR(m_sim_mf) + ' ' + ANY_TO_STR(m_ccmaxi) + ' ' + PRJFLOAT_TO_STR(m_ccrcnvg) + ' '
    + PRJFLOAT_TO_STR(m_ccacnvg) + ' ' + PRJFLOAT_TO_STR(m_ccrelax) + ' ' + ANY_TO_STR(m_uccc) + '\n';
  string += ANY_TO_STR(m_mfnmthd) + ' ' + ANY_TO_STR(m_mfnrseq) + ' ' + ANY_TO_STR(m_mfnmaxi) + ' '
    + PRJFLOAT_TO_STR(m_mfnrcnvg) + ' ' + PRJFLOAT_TO_STR(m_mfnacnvg) + ' ' + PRJFLOAT_TO_STR(m_mfnrelax) + ' '
    + PRJFLOAT_TO_STR(m_mfngamma) + ' ' + ANY_TO_STR(m_uccn) + '\n';
  string += ANY_TO_STR(m_mftmthd) + ' ' + ANY_TO_STR(m_mftrseq) + ' ' + ANY_TO_STR(m_mftmaxi) + ' '
    + PRJFLOAT_TO_STR(m_mftrcnvg) + ' ' + PRJFLOAT_TO_STR(m_mftacnvg) + ' ' + PRJFLOAT_TO_STR(m_mftrelax) + ' '
    + PRJFLOAT_TO_STR(m_mftgamma) + ' ' + ANY_TO_STR(m_ucct) + '\n';
  string += ANY_TO_STR(m_mfvmthd) + ' ' + ANY_TO_STR(m_mfvrseq) + ' ' + ANY_TO_STR(m_mfvmaxi) + ' '
    + PRJFLOAT_TO_STR(m_mfvrcnvg) + ' ' + PRJFLOAT_TO_STR(m_mfvacnvg) + ' ' + PRJFLOAT_TO_STR(m_mfvrelax) + ' '
    + ANY_TO_STR(m_uccv) + '\n';
  string += ANY_TO_STR(m_mf_solver) + ' ' + ANY_TO_STR(m_sim_1dz) + ' ' + ANY_TO_STR(m_sim_1dd) + ' '
    + PRJFLOAT_TO_STR(m_celldx) + ' ' + ANY_TO_STR(m_sim_vjt) + ' ' + ANY_TO_STR(m_udx) + '\n';
  string += ANY_TO_STR(m_cvode_mth) + ' ' + PRJFLOAT_TO_STR(m_cvode_rcnvg) + ' ' + PRJFLOAT_TO_STR(m_cvode_acnvg) + ' '
    + PRJFLOAT_TO_STR(m_cvode_dtmax) + '\n';
  string += ANY_TO_STR(m_tsdens) + ' ' + PRJFLOAT_TO_STR(m_tsrelax) + ' ' + ANY_TO_STR(m_tsmaxi) + ' '
    + ANY_TO_STR(m_cnvgSS) + ' ' + ANY_TO_STR(m_densZP) + ' ' + ANY_TO_STR(m_stackD) + ' '
    + ANY_TO_STR(m_dodMdt) + '\n';
  string += m_date_st + ' ' + m_time_st + ' ' + m_date_0 + ' ' + m_time_0 + ' ' + m_date_1 + ' '
    + m_time_1 + ' ' + m_time_step + ' ' + m_time_list + ' ' + m_time_scrn + '\n';
  string += ANY_TO_STR(m_restart) + ' ' + m_rstdate + ' ' + m_rsttime + '\n';
  string += ANY_TO_STR(m_list) + ' ' + ANY_TO_STR(m_doDlg) + ' ' + ANY_TO_STR(m_pfsave) + ' '
    + ANY_TO_STR(m_zfsave) + ' ' + ANY_TO_STR(m_zcsave) + '\n';
  string += ANY_TO_STR(m_achvol) + ' ' + ANY_TO_STR(m_achsave) + ' ' + ANY_TO_STR(m_abwsave) + ' '
    + ANY_TO_STR(m_cbwsave) + ' ' + ANY_TO_STR(m_expsave) + ' ' + ANY_TO_STR(m_ebwsave) + ' '
    + ANY_TO_STR(m_zaasave) + ' ' + ANY_TO_STR(m_zbwsave) + '\n';
  string += ANY_TO_STR(m_rzfsave) + ' ' + ANY_TO_STR(m_rzmsave) + ' ' + ANY_TO_STR(m_rz1save) + ' '
    + ANY_TO_STR(m_csmsave) + ' ' + ANY_TO_STR(m_srfsave) + ' ' + ANY_TO_STR(m_logsave) + '\n';
  for (int i = 0; i < 16; i++)
    string += ANY_TO_STR(m_save[i]) + ' ';
  string += '\n';
  string += ANY_TO_STR((int)m_rvals.size()) + '\n';
  for (unsigned int i = 0; i < m_rvals.size(); i++)
    string += PRJFLOAT_TO_STR(m_rvals[i]) + ' ';
  string += '\n';
  string += ANY_TO_STR(m_BldgFlowZ) + ' ' + ANY_TO_STR(m_BldgFlowD) + ' ' + ANY_TO_STR(m_BldgFlowC) + '\n';
  string += ANY_TO_STR(m_cfd_ctype) + ' ' + PRJFLOAT_TO_STR(m_cfd_convcpl) + ' ' + ANY_TO_STR(m_cfd_var) + ' '
    + ANY_TO_STR(m_cfd_zref) + ' ' + ANY_TO_STR(m_cfd_imax) + ' ' + ANY_TO_STR(m_cfd_dtcmo) + '\n';
  return string;
}

int RunControl::RunControlImpl::sim_af() const
{
  return m_sim_af;
}

void RunControl::RunControlImpl::setSim_af(const int sim_af)
{
  m_sim_af = sim_af;
}

int RunControl::RunControlImpl::afcalc() const
{
  return m_afcalc;
}

void RunControl::RunControlImpl::setAfcalc(const int afcalc)
{
  m_afcalc = afcalc;
}

int RunControl::RunControlImpl::afmaxi() const
{
  return m_afmaxi;
}

void RunControl::RunControlImpl::setAfmaxi(const int afmaxi)
{
  m_afmaxi = afmaxi;
}

double RunControl::RunControlImpl::afrcnvg() const
{
  return to<double>(m_afrcnvg);
}

bool RunControl::RunControlImpl::setAfrcnvg(const double afrcnvg)
{
  m_afrcnvg = to_float(afrcnvg);
  return true;
}

bool RunControl::RunControlImpl::setAfrcnvg(const std::string & afrcnvg)
{
  return assign_if_valid<double>(afrcnvg, m_afrcnvg);
}

double RunControl::RunControlImpl::afacnvg() const
{
  return to<double>(m_afacnvg);
}

bool RunControl::RunControlImpl::setAfacnvg(const double afacnvg)
{
  m_afacnvg = to_float(afacnvg);
  return true;
}

bool RunControl::RunControlImpl::setAfacnvg(const std::string & afacnvg)
{
  return assign_if_valid<double>(afacnvg, m_afacnvg);
}

double RunControl::RunControlImpl::afrelax() const
{
  return to<double>(m_afrelax);
}

bool RunControl::RunControlImpl::setAfrelax(const double afrelax)
{
  m_afrelax = to_float(afrelax);
  return true;
}

bool RunControl::RunControlImpl::setAfrelax(const std::string & afrelax)
{
  return assign_if_valid<double>(afrelax, m_afrelax);
}

int RunControl::RunControlImpl::uac2() const
{
  return m_uac2;
}

void RunControl::RunControlImpl::setUac2(const int uac2)
{
  m_uac2 = uac2;
}

double RunControl::RunControlImpl::Pres() const
{
  return to<double>(m_Pres);
}

bool RunControl::RunControlImpl::setPres(const double Pres)
{
  m_Pres = to_float(Pres);
  return true;
}

bool RunControl::RunControlImpl::setPres(const std::string & Pres)
{
  return assign_if_valid<double>(Pres, m_Pres);
}

int RunControl::RunControlImpl::uPres() const
{
  return m_uPres;
}

void RunControl::RunControlImpl::setUPres(const int uPres)
{
  m_uPres = uPres;
}

int RunControl::RunControlImpl::afslae() const
{
  return m_afslae;
}

void RunControl::RunControlImpl::setAfslae(const int afslae)
{
  m_afslae = afslae;
}

int RunControl::RunControlImpl::afrseq() const
{
  return m_afrseq;
}

void RunControl::RunControlImpl::setAfrseq(const int afrseq)
{
  m_afrseq = afrseq;
}

int RunControl::RunControlImpl::aflmaxi() const
{
  return m_aflmaxi;
}

void RunControl::RunControlImpl::setAflmaxi(const int aflmaxi)
{
  m_aflmaxi = aflmaxi;
}

double RunControl::RunControlImpl::aflcnvg() const
{
  return to<double>(m_aflcnvg);
}

bool RunControl::RunControlImpl::setAflcnvg(const double aflcnvg)
{
  m_aflcnvg = to_float(aflcnvg);
  return true;
}

bool RunControl::RunControlImpl::setAflcnvg(const std::string & aflcnvg)
{
  return assign_if_valid<double>(aflcnvg, m_aflcnvg);
}

int RunControl::RunControlImpl::aflinit() const
{
  return m_aflinit;
}

void RunControl::RunControlImpl::setAflinit(const int aflinit)
{
  m_aflinit = aflinit;
}

int RunControl::RunControlImpl::Tadj() const
{
  return m_Tadj;
}

void RunControl::RunControlImpl::setTadj(const int Tadj)
{
  m_Tadj = Tadj;
}

int RunControl::RunControlImpl::sim_mf() const
{
  return m_sim_mf;
}

void RunControl::RunControlImpl::setSim_mf(const int sim_mf)
{
  m_sim_mf = sim_mf;
}

int RunControl::RunControlImpl::ccmaxi() const
{
  return m_ccmaxi;
}

void RunControl::RunControlImpl::setCcmaxi(const int ccmaxi)
{
  m_ccmaxi = ccmaxi;
}

double RunControl::RunControlImpl::ccrcnvg() const
{
  return to<double>(m_ccrcnvg);
}

bool RunControl::RunControlImpl::setCcrcnvg(const double ccrcnvg)
{
  m_ccrcnvg = to_float(ccrcnvg);
  return true;
}

bool RunControl::RunControlImpl::setCcrcnvg(const std::string & ccrcnvg)
{
  return assign_if_valid<double>(ccrcnvg, m_ccrcnvg);
}

double RunControl::RunControlImpl::ccacnvg() const
{
  return to<double>(m_ccacnvg);
}

bool RunControl::RunControlImpl::setCcacnvg(const double ccacnvg)
{
  m_ccacnvg = to_float(ccacnvg);
  return true;
}

bool RunControl::RunControlImpl::setCcacnvg(const std::string & ccacnvg)
{
  return assign_if_valid<double>(ccacnvg, m_ccacnvg);
}

double RunControl::RunControlImpl::ccrelax() const
{
  return to<double>(m_ccrelax);
}

bool RunControl::RunControlImpl::setCcrelax(const double ccrelax)
{
  m_ccrelax = to_float(ccrelax);
  return true;
}

bool RunControl::RunControlImpl::setCcrelax(const std::string & ccrelax)
{
  return assign_if_valid<double>(ccrelax, m_ccrelax);
}

int RunControl::RunControlImpl::uccc() const
{
  return m_uccc;
}

void RunControl::RunControlImpl::setUccc(const int uccc)
{
  m_uccc = uccc;
}

int RunControl::RunControlImpl::mfnmthd() const
{
  return m_mfnmthd;
}

void RunControl::RunControlImpl::setMfnmthd(const int mfnmthd)
{
  m_mfnmthd = mfnmthd;
}

int RunControl::RunControlImpl::mfnrseq() const
{
  return m_mfnrseq;
}

void RunControl::RunControlImpl::setMfnrseq(const int mfnrseq)
{
  m_mfnrseq = mfnrseq;
}

int RunControl::RunControlImpl::mfnmaxi() const
{
  return m_mfnmaxi;
}

void RunControl::RunControlImpl::setMfnmaxi(const int mfnmaxi)
{
  m_mfnmaxi = mfnmaxi;
}

double RunControl::RunControlImpl::mfnrcnvg() const
{
  return to<double>(m_mfnrcnvg);
}

bool RunControl::RunControlImpl::setMfnrcnvg(const double mfnrcnvg)
{
  m_mfnrcnvg = to_float(mfnrcnvg);
  return true;
}

bool RunControl::RunControlImpl::setMfnrcnvg(const std::string & mfnrcnvg)
{
  return assign_if_valid<double>(mfnrcnvg, m_mfnrcnvg);
}

double RunControl::RunControlImpl::mfnacnvg() const
{
  return to<double>(m_mfnacnvg);
}

bool RunControl::RunControlImpl::setMfnacnvg(const double mfnacnvg)
{
  m_mfnacnvg = to_float(mfnacnvg);
  return true;
}

bool RunControl::RunControlImpl::setMfnacnvg(const std::string & mfnacnvg)
{
  return assign_if_valid<double>(mfnacnvg, m_mfnacnvg);
}

double RunControl::RunControlImpl::mfnrelax() const
{
  return to<double>(m_mfnrelax);
}

bool RunControl::RunControlImpl::setMfnrelax(const double mfnrelax)
{
  m_mfnrelax = to_float(mfnrelax);
  return true;
}

bool RunControl::RunControlImpl::setMfnrelax(const std::string & mfnrelax)
{
  return assign_if_valid<double>(mfnrelax, m_mfnrelax);
}

double RunControl::RunControlImpl::mfngamma() const
{
  return to<double>(m_mfngamma);
}

bool RunControl::RunControlImpl::setMfngamma(const double mfngamma)
{
  m_mfngamma = to_float(mfngamma);
  return true;
}

bool RunControl::RunControlImpl::setMfngamma(const std::string & mfngamma)
{
  return assign_if_valid<double>(mfngamma, m_mfngamma);
}

int RunControl::RunControlImpl::uccn() const
{
  return m_uccn;
}

void RunControl::RunControlImpl::setUccn(const int uccn)
{
  m_uccn = uccn;
}

int RunControl::RunControlImpl::mftmthd() const
{
  return m_mftmthd;
}

void RunControl::RunControlImpl::setMftmthd(const int mftmthd)
{
  m_mftmthd = mftmthd;
}

int RunControl::RunControlImpl::mftrseq() const
{
  return m_mftrseq;
}

void RunControl::RunControlImpl::setMftrseq(const int mftrseq)
{
  m_mftrseq = mftrseq;
}

int RunControl::RunControlImpl::mftmaxi() const
{
  return m_mftmaxi;
}

void RunControl::RunControlImpl::setMftmaxi(const int mftmaxi)
{
  m_mftmaxi = mftmaxi;
}

double RunControl::RunControlImpl::mftrcnvg() const
{
  return to<double>(m_mftrcnvg);
}

bool RunControl::RunControlImpl::setMftrcnvg(const double mftrcnvg)
{
  m_mftrcnvg = to_float(mftrcnvg);
  return true;
}

bool RunControl::RunControlImpl::setMftrcnvg(const std::string & mftrcnvg)
{
  return assign_if_valid<double>(mftrcnvg, m_mftrcnvg);
}

double RunControl::RunControlImpl::mftacnvg() const
{
  return to<double>(m_mftacnvg);
}

bool RunControl::RunControlImpl::setMftacnvg(const double mftacnvg)
{
  m_mftacnvg = to_float(mftacnvg);
  return true;
}

bool RunControl::RunControlImpl::setMftacnvg(const std::string & mftacnvg)
{
  return assign_if_valid<double>(mftacnvg, m_mftacnvg);
}

double RunControl::RunControlImpl::mftrelax() const
{
  return to<double>(m_mftrelax);
}

bool RunControl::RunControlImpl::setMftrelax(const double mftrelax)
{
  m_mftrelax = to_float(mftrelax);
  return true;
}

bool RunControl::RunControlImpl::setMftrelax(const std::string & mftrelax)
{
  return assign_if_valid<double>(mftrelax, m_mftrelax);
}

double RunControl::RunControlImpl::mftgamma() const
{
  return to<double>(m_mftgamma);
}

bool RunControl::RunControlImpl::setMftgamma(const double mftgamma)
{
  m_mftgamma = to_float(mftgamma);
  return true;
}

bool RunControl::RunControlImpl::setMftgamma(const std::string & mftgamma)
{
  return assign_if_valid<double>(mftgamma, m_mftgamma);
}

int RunControl::RunControlImpl::ucct() const
{
  return m_ucct;
}

void RunControl::RunControlImpl::setUcct(const int ucct)
{
  m_ucct = ucct;
}

int RunControl::RunControlImpl::mfvmthd() const
{
  return m_mfvmthd;
}

void RunControl::RunControlImpl::setMfvmthd(const int mfvmthd)
{
  m_mfvmthd = mfvmthd;
}

int RunControl::RunControlImpl::mfvrseq() const
{
  return m_mfvrseq;
}

void RunControl::RunControlImpl::setMfvrseq(const int mfvrseq)
{
  m_mfvrseq = mfvrseq;
}

int RunControl::RunControlImpl::mfvmaxi() const
{
  return m_mfvmaxi;
}

void RunControl::RunControlImpl::setMfvmaxi(const int mfvmaxi)
{
  m_mfvmaxi = mfvmaxi;
}

double RunControl::RunControlImpl::mfvrcnvg() const
{
  return to<double>(m_mfvrcnvg);
}

bool RunControl::RunControlImpl::setMfvrcnvg(const double mfvrcnvg)
{
  m_mfvrcnvg = to_float(mfvrcnvg);
  return true;
}

bool RunControl::RunControlImpl::setMfvrcnvg(const std::string & mfvrcnvg)
{
  return assign_if_valid<double>(mfvrcnvg, m_mfvrcnvg);
}

double RunControl::RunControlImpl::mfvacnvg() const
{
  return to<double>(m_mfvacnvg);
}

bool RunControl::RunControlImpl::setMfvacnvg(const double mfvacnvg)
{
  m_mfvacnvg = to_float(mfvacnvg);
  return true;
}

bool RunControl::RunControlImpl::setMfvacnvg(const std::string & mfvacnvg)
{
  return assign_if_valid<double>(mfvacnvg, m_mfvacnvg);
}

double RunControl::RunControlImpl::mfvrelax() const
{
  return to<double>(m_mfvrelax);
}

bool RunControl::RunControlImpl::setMfvrelax(const double mfvrelax)
{
  m_mfvrelax = to_float(mfvrelax);
  return true;
}

bool RunControl::RunControlImpl::setMfvrelax(const std::string & mfvrelax)
{
  return assign_if_valid<double>(mfvrelax, m_mfvrelax);
}

int RunControl::RunControlImpl::uccv() const
{
  return m_uccv;
}

void RunControl::RunControlImpl::setUccv(const int uccv)
{
  m_uccv = uccv;
}

int RunControl::RunControlImpl::mf_solver() const
{
  return m_mf_solver;
}

void RunControl::RunControlImpl::setMf_solver(const int mf_solver)
{
  m_mf_solver = mf_solver;
}

int RunControl::RunControlImpl::sim_1dz() const
{
  return m_sim_1dz;
}

void RunControl::RunControlImpl::setSim_1dz(const int sim_1dz)
{
  m_sim_1dz = sim_1dz;
}

int RunControl::RunControlImpl::sim_1dd() const
{
  return m_sim_1dd;
}

void RunControl::RunControlImpl::setSim_1dd(const int sim_1dd)
{
  m_sim_1dd = sim_1dd;
}

double RunControl::RunControlImpl::celldx() const
{
  return to<double>(m_celldx);
}

bool RunControl::RunControlImpl::setCelldx(const double celldx)
{
  m_celldx = to_float(celldx);
  return true;
}

bool RunControl::RunControlImpl::setCelldx(const std::string & celldx)
{
  return assign_if_valid<double>(celldx, m_celldx);
}

int RunControl::RunControlImpl::sim_vjt() const
{
  return m_sim_vjt;
}

void RunControl::RunControlImpl::setSim_vjt(const int sim_vjt)
{
  m_sim_vjt = sim_vjt;
}

int RunControl::RunControlImpl::udx() const
{
  return m_udx;
}

void RunControl::RunControlImpl::setUdx(const int udx)
{
  m_udx = udx;
}

int RunControl::RunControlImpl::cvode_mth() const
{
  return m_cvode_mth;
}

void RunControl::RunControlImpl::setCvode_mth(const int cvode_mth)
{
  m_cvode_mth = cvode_mth;
}

double RunControl::RunControlImpl::cvode_rcnvg() const
{
  return to<double>(m_cvode_rcnvg);
}

bool RunControl::RunControlImpl::setCvode_rcnvg(const double cvode_rcnvg)
{
  m_cvode_rcnvg = to_float(cvode_rcnvg);
  return true;
}

bool RunControl::RunControlImpl::setCvode_rcnvg(const std::string & cvode_rcnvg)
{
  return assign_if_valid<double>(cvode_rcnvg, m_cvode_rcnvg);
}

double RunControl::RunControlImpl::cvode_acnvg() const
{
  return to<double>(m_cvode_acnvg);
}

bool RunControl::RunControlImpl::setCvode_acnvg(const double cvode_acnvg)
{
  m_cvode_acnvg = to_float(cvode_acnvg);
  return true;
}

bool RunControl::RunControlImpl::setCvode_acnvg(const std::string & cvode_acnvg)
{
  return assign_if_valid<double>(cvode_acnvg, m_cvode_acnvg);
}

double RunControl::RunControlImpl::cvode_dtmax() const
{
  return to<double>(m_cvode_dtmax);
}

bool RunControl::RunControlImpl::setCvode_dtmax(const double cvode_dtmax)
{
  m_cvode_dtmax = to_float(cvode_dtmax);
  return true;
}

bool RunControl::RunControlImpl::setCvode_dtmax(const std::string & cvode_dtmax)
{
  return assign_if_valid<double>(cvode_dtmax, m_cvode_dtmax);
}

int RunControl::RunControlImpl::tsdens() const
{
  return m_tsdens;
}

void RunControl::RunControlImpl::setTsdens(const int tsdens)
{
  m_tsdens = tsdens;
}

double RunControl::RunControlImpl::tsrelax() const
{
  return to<double>(m_tsrelax);
}

bool RunControl::RunControlImpl::setTsrelax(const double tsrelax)
{
  m_tsrelax = to_float(tsrelax);
  return true;
}

bool RunControl::RunControlImpl::setTsrelax(const std::string & tsrelax)
{
  return assign_if_valid<double>(tsrelax, m_tsrelax);
}

int RunControl::RunControlImpl::tsmaxi() const
{
  return m_tsmaxi;
}

void RunControl::RunControlImpl::setTsmaxi(const int tsmaxi)
{
  m_tsmaxi = tsmaxi;
}

int RunControl::RunControlImpl::cnvgSS() const
{
  return m_cnvgSS;
}

void RunControl::RunControlImpl::setCnvgSS(const int cnvgSS)
{
  m_cnvgSS = cnvgSS;
}

int RunControl::RunControlImpl::densZP() const
{
  return m_densZP;
}

void RunControl::RunControlImpl::setDensZP(const int densZP)
{
  m_densZP = densZP;
}

int RunControl::RunControlImpl::stackD() const
{
  return m_stackD;
}

void RunControl::RunControlImpl::setStackD(const int stackD)
{
  m_stackD = stackD;
}

int RunControl::RunControlImpl::dodMdt() const
{
  return m_dodMdt;
}

void RunControl::RunControlImpl::setDodMdt(const int dodMdt)
{
  m_dodMdt = dodMdt;
}

std::string RunControl::RunControlImpl::date_st() const
{
  return m_date_st;
}

void RunControl::RunControlImpl::setDate_st(const std::string & date_st)
{
  m_date_st = date_st;
}

std::string RunControl::RunControlImpl::time_st() const
{
  return m_time_st;
}

void RunControl::RunControlImpl::setTime_st(const std::string & time_st)
{
  m_time_st = time_st;
}

std::string RunControl::RunControlImpl::date_0() const
{
  return m_date_0;
}

void RunControl::RunControlImpl::setDate_0(const std::string & date_0)
{
  m_date_0 = date_0;
}

std::string RunControl::RunControlImpl::time_0() const
{
  return m_time_0;
}

void RunControl::RunControlImpl::setTime_0(const std::string & time_0)
{
  m_time_0 = time_0;
}

std::string RunControl::RunControlImpl::date_1() const
{
  return m_date_1;
}

void RunControl::RunControlImpl::setDate_1(const std::string & date_1)
{
  m_date_1 = date_1;
}

std::string RunControl::RunControlImpl::time_1() const
{
  return m_time_1;
}

void RunControl::RunControlImpl::setTime_1(const std::string & time_1)
{
  m_time_1 = time_1;
}

std::string RunControl::RunControlImpl::time_step() const
{
  return m_time_step;
}

void RunControl::RunControlImpl::setTime_step(const std::string & time_step)
{
  m_time_step = time_step;
}

std::string RunControl::RunControlImpl::time_list() const
{
  return m_time_list;
}

void RunControl::RunControlImpl::setTime_list(const std::string & time_list)
{
  m_time_list = time_list;
}

std::string RunControl::RunControlImpl::time_scrn() const
{
  return m_time_scrn;
}

void RunControl::RunControlImpl::setTime_scrn(const std::string & time_scrn)
{
  m_time_scrn = time_scrn;
}

int RunControl::RunControlImpl::restart() const
{
  return m_restart;
}

void RunControl::RunControlImpl::setRestart(const int restart)
{
  m_restart = restart;
}

std::string RunControl::RunControlImpl::rstdate() const
{
  return m_rstdate;
}

void RunControl::RunControlImpl::setRstdate(const std::string & rstdate)
{
  m_rstdate = rstdate;
}

std::string RunControl::RunControlImpl::rsttime() const
{
  return m_rsttime;
}

void RunControl::RunControlImpl::setRsttime(const std::string & rsttime)
{
  m_rsttime = rsttime;
}

int RunControl::RunControlImpl::list() const
{
  return m_list;
}

void RunControl::RunControlImpl::setList(const int list)
{
  m_list = list;
}

int RunControl::RunControlImpl::doDlg() const
{
  return m_doDlg;
}

void RunControl::RunControlImpl::setDoDlg(const int doDlg)
{
  m_doDlg = doDlg;
}

int RunControl::RunControlImpl::pfsave() const
{
  return m_pfsave;
}

void RunControl::RunControlImpl::setPfsave(const int pfsave)
{
  m_pfsave = pfsave;
}

int RunControl::RunControlImpl::zfsave() const
{
  return m_zfsave;
}

void RunControl::RunControlImpl::setZfsave(const int zfsave)
{
  m_zfsave = zfsave;
}

int RunControl::RunControlImpl::zcsave() const
{
  return m_zcsave;
}

void RunControl::RunControlImpl::setZcsave(const int zcsave)
{
  m_zcsave = zcsave;
}

int RunControl::RunControlImpl::achvol() const
{
  return m_achvol;
}

void RunControl::RunControlImpl::setAchvol(const int achvol)
{
  m_achvol = achvol;
}

int RunControl::RunControlImpl::achsave() const
{
  return m_achsave;
}

void RunControl::RunControlImpl::setAchsave(const int achsave)
{
  m_achsave = achsave;
}

int RunControl::RunControlImpl::abwsave() const
{
  return m_abwsave;
}

void RunControl::RunControlImpl::setAbwsave(const int abwsave)
{
  m_abwsave = abwsave;
}

int RunControl::RunControlImpl::cbwsave() const
{
  return m_cbwsave;
}

void RunControl::RunControlImpl::setCbwsave(const int cbwsave)
{
  m_cbwsave = cbwsave;
}

int RunControl::RunControlImpl::expsave() const
{
  return m_expsave;
}

void RunControl::RunControlImpl::setExpsave(const int expsave)
{
  m_expsave = expsave;
}

int RunControl::RunControlImpl::ebwsave() const
{
  return m_ebwsave;
}

void RunControl::RunControlImpl::setEbwsave(const int ebwsave)
{
  m_ebwsave = ebwsave;
}

int RunControl::RunControlImpl::zaasave() const
{
  return m_zaasave;
}

void RunControl::RunControlImpl::setZaasave(const int zaasave)
{
  m_zaasave = zaasave;
}

int RunControl::RunControlImpl::zbwsave() const
{
  return m_zbwsave;
}

void RunControl::RunControlImpl::setZbwsave(const int zbwsave)
{
  m_zbwsave = zbwsave;
}

int RunControl::RunControlImpl::rzfsave() const
{
  return m_rzfsave;
}

void RunControl::RunControlImpl::setRzfsave(const int rzfsave)
{
  m_rzfsave = rzfsave;
}

int RunControl::RunControlImpl::rzmsave() const
{
  return m_rzmsave;
}

void RunControl::RunControlImpl::setRzmsave(const int rzmsave)
{
  m_rzmsave = rzmsave;
}

int RunControl::RunControlImpl::rz1save() const
{
  return m_rz1save;
}

void RunControl::RunControlImpl::setRz1save(const int rz1save)
{
  m_rz1save = rz1save;
}

int RunControl::RunControlImpl::csmsave() const
{
  return m_csmsave;
}

void RunControl::RunControlImpl::setCsmsave(const int csmsave)
{
  m_csmsave = csmsave;
}

int RunControl::RunControlImpl::srfsave() const
{
  return m_srfsave;
}

void RunControl::RunControlImpl::setSrfsave(const int srfsave)
{
  m_srfsave = srfsave;
}

int RunControl::RunControlImpl::logsave() const
{
  return m_logsave;
}

void RunControl::RunControlImpl::setLogsave(const int logsave)
{
  m_logsave = logsave;
}

std::vector<int> RunControl::RunControlImpl::save() const
{
  return m_save;
}

void RunControl::RunControlImpl::setSave(const std::vector<int> & save)
{
  m_save = save;
}

std::vector<double> RunControl::RunControlImpl::rvals() const
{
  std::vector<double> out;
  for (const auto& val : m_rvals) {
    out.push_back(to<double>(val));
  }
  return out;
}

bool RunControl::RunControlImpl::setRvals(const std::vector<double> & rvals)
{
  std::vector<std::string> new_vals;
  for (const auto& val : rvals) {
    new_vals.push_back(to_float(val));
  }
  m_rvals = new_vals;
  return true;
}

bool RunControl::RunControlImpl::setRvals(const std::vector<std::string> & rvals)
{
  if (std::all_of(rvals.begin(), rvals.end(), is_valid<double, std::string>)) {
    m_rvals = rvals;
    return true;
  } else {
    return false;
  }
}

int RunControl::RunControlImpl::BldgFlowZ() const
{
  return m_BldgFlowZ;
}

void RunControl::RunControlImpl::setBldgFlowZ(const int BldgFlowZ)
{
  m_BldgFlowZ = BldgFlowZ;
}

int RunControl::RunControlImpl::BldgFlowD() const
{
  return m_BldgFlowD;
}

void RunControl::RunControlImpl::setBldgFlowD(const int BldgFlowD)
{
  m_BldgFlowD = BldgFlowD;
}

int RunControl::RunControlImpl::BldgFlowC() const
{
  return m_BldgFlowC;
}

void RunControl::RunControlImpl::setBldgFlowC(const int BldgFlowC)
{
  m_BldgFlowC = BldgFlowC;
}

int RunControl::RunControlImpl::cfd_ctype() const
{
  return m_cfd_ctype;
}

void RunControl::RunControlImpl::setCfd_ctype(const int cfd_ctype)
{
  m_cfd_ctype = cfd_ctype;
}

double RunControl::RunControlImpl::cfd_convcpl() const
{
  return to<double>(m_cfd_convcpl);
}

bool RunControl::RunControlImpl::setCfd_convcpl(const double cfd_convcpl)
{
  m_cfd_convcpl = to_float(cfd_convcpl);
  return true;
}

bool RunControl::RunControlImpl::setCfd_convcpl(const std::string & cfd_convcpl)
{
  return assign_if_valid<double>(cfd_convcpl, m_cfd_convcpl);
}

int RunControl::RunControlImpl::cfd_var() const
{
  return m_cfd_var;
}

void RunControl::RunControlImpl::setCfd_var(const int cfd_var)
{
  m_cfd_var = cfd_var;
}

int RunControl::RunControlImpl::cfd_zref() const
{
  return m_cfd_zref;
}

void RunControl::RunControlImpl::setCfd_zref(const int cfd_zref)
{
  m_cfd_zref = cfd_zref;
}

int RunControl::RunControlImpl::cfd_imax() const
{
  return m_cfd_imax;
}

void RunControl::RunControlImpl::setCfd_imax(const int cfd_imax)
{
  m_cfd_imax = cfd_imax;
}

int RunControl::RunControlImpl::cfd_dtcmo() const
{
  return m_cfd_dtcmo;
}

void RunControl::RunControlImpl::setCfd_dtcmo(const int cfd_dtcmo)
{
  m_cfd_dtcmo = cfd_dtcmo;
}

Level::Level() :
  m_impl(std::shared_ptr<LevelImpl>(new LevelImpl))
{}

Level::Level(double delht, std::string name) :
  m_impl(std::shared_ptr<LevelImpl>(new LevelImpl))
{
  m_impl->setDelht(delht);
  m_impl->setName(name);
}

Level::Level(std::string delht, std::string name) :
  m_impl(std::shared_ptr<LevelImpl>(new LevelImpl))
{
  m_impl->setDelht(delht);
  m_impl->setName(name);
}

Level::Level(int nr,double refht,double delht,int u_rfht,int u_dlht,std::string name,std::vector<Icon> icons) :
  m_impl(std::shared_ptr<LevelImpl>(new LevelImpl(nr,refht,delht,u_rfht,u_dlht,name,icons)))
{}

Level::Level(int nr,std::string refht,std::string delht,int u_rfht,int u_dlht,std::string name,std::vector<Icon> icons) :
  m_impl(std::shared_ptr<LevelImpl>(new LevelImpl(nr,refht,delht,u_rfht,u_dlht,name,icons)))
{}

Level::Level(const Level &other) : m_impl(other.m_impl)
{}

Level::~Level()
{}

Level& Level::operator=(const Level &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool Level::operator==(const Level &other) const
{
  return m_impl==other.m_impl;
}

bool Level::operator!=(const Level &other) const
{
  return m_impl!=other.m_impl;
}

std::string Level::write()
{
  return m_impl->write();
}

void Level::read(Reader &input)
{
  m_impl->read(input);
}

int Level::nr() const
{
  return m_impl->nr();
}

void Level::setNr(const int nr)
{
  m_impl->setNr(nr);
}

double Level::refht() const
{
  return m_impl->refht();
}

bool Level::setRefht(const double refht)
{
  return m_impl->setRefht(refht);
}

bool Level::setRefht(const std::string &refht)
{
  return m_impl->setRefht(refht);
}

double Level::delht() const
{
  return m_impl->delht();
}

bool Level::setDelht(const double delht)
{
  return m_impl->setDelht(delht);
}

bool Level::setDelht(const std::string &delht)
{
  return m_impl->setDelht(delht);
}

int Level::u_rfht() const
{
  return m_impl->u_rfht();
}

void Level::setU_rfht(const int u_rfht)
{
  m_impl->setU_rfht(u_rfht);
}

int Level::u_dlht() const
{
  return m_impl->u_dlht();
}

void Level::setU_dlht(const int u_dlht)
{
  m_impl->setU_dlht(u_dlht);
}

std::string Level::name() const
{
  return m_impl->name();
}

void Level::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::vector<Icon> Level::icons() const
{
  return m_impl->icons();
}

void Level::setIcons(const std::vector<Icon> &icons)
{
  m_impl->setIcons(icons);
}

Level::LevelImpl::LevelImpl() : m_nr(0), m_refht(PRJFLOAT("0.0")), m_delht(PRJFLOAT("0.0")), m_u_rfht(0), m_u_dlht(0)
{}

Level::LevelImpl::LevelImpl(int nr, double refht, double delht, int u_rfht, int u_dlht, std::string name, std::vector<Icon> icons)
  : Level::LevelImpl()
{
  setNr(nr);
  setRefht(refht);
  setDelht(delht);
  setU_rfht(u_rfht);
  setU_dlht(u_dlht);
  setName(name);
  setIcons(icons);
}

Level::LevelImpl::LevelImpl(int nr, std::string refht, std::string delht, int u_rfht, int u_dlht, std::string name, std::vector<Icon> icons)
  : Level::LevelImpl()
{
  setNr(nr);
  setRefht(refht);
  setDelht(delht);
  setU_rfht(u_rfht);
  setU_dlht(u_dlht);
  setName(name);
  setIcons(icons);
}

void Level::LevelImpl::read(Reader& input)
{
  setNr(input.read<int>());
  setRefht(input.readNumber<std::string>());
  setDelht(input.readNumber<std::string>());
  int nicon = input.read<int>();
  setU_rfht(input.read<int>());
  setU_dlht(input.read<int>());
  setName(input.readString());
  std::vector<Icon> icons;
  for (int i = 0; i < nicon; i++) {
    Icon object;
    object.read(input);
    icons.push_back(object);
  }
  setIcons(icons);
}

std::string Level::LevelImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + PRJFLOAT_TO_STR(m_refht) + ' ' + PRJFLOAT_TO_STR(m_delht) + ' ' + ANY_TO_STR((int)m_icons.size())
    + ' ' + ANY_TO_STR(m_u_rfht) + ' ' + ANY_TO_STR(m_u_dlht) + ' ' + PRJFLOAT_TO_STR(m_name) + '\n';
  for (unsigned i = 0; i < m_icons.size(); i++) {
    string += m_icons[i].write();
  }
  return string;
}

int Level::LevelImpl::nr() const
{
  return m_nr;
}

void Level::LevelImpl::setNr(const int nr)
{
  m_nr = nr;
}

double Level::LevelImpl::refht() const
{
  return to<double>(m_refht);
}

bool Level::LevelImpl::setRefht(const double refht)
{
  m_refht = to_float(refht);
  return true;
}

bool Level::LevelImpl::setRefht(const std::string& refht)
{
  return assign_if_valid<double>(refht, m_refht);
}

double Level::LevelImpl::delht() const
{
  return to<double>(m_delht);
}

bool Level::LevelImpl::setDelht(const double delht)
{
  m_delht = to_float(delht);
  return true;
}

bool Level::LevelImpl::setDelht(const std::string& delht)
{
  return assign_if_valid<double>(delht, m_delht);
}

int Level::LevelImpl::u_rfht() const
{
  return m_u_rfht;
}

void Level::LevelImpl::setU_rfht(const int u_rfht)
{
  m_u_rfht = u_rfht;
}

int Level::LevelImpl::u_dlht() const
{
  return m_u_dlht;
}

void Level::LevelImpl::setU_dlht(const int u_dlht)
{
  m_u_dlht = u_dlht;
}

std::string Level::LevelImpl::name() const
{
  return m_name;
}

void Level::LevelImpl::setName(const std::string& name)
{
  m_name = name;
}

std::vector<Icon> Level::LevelImpl::icons() const
{
  return m_icons;
}

void Level::LevelImpl::setIcons(const std::vector<Icon>& icons)
{
  m_icons = icons;
}

DaySchedule::DaySchedule() :
  m_impl(std::shared_ptr<DayScheduleImpl>(new DayScheduleImpl()))
{}

DaySchedule::DaySchedule(int nr,int shape,int utyp,int ucnv,std::string name,std::string desc,
  std::vector<SchedulePoint> points) :
  m_impl(std::shared_ptr<DayScheduleImpl>(new DayScheduleImpl(nr,shape,utyp,ucnv,name,desc,points)))
{}

DaySchedule::DaySchedule(const DaySchedule &other) : m_impl(other.m_impl)
{}

DaySchedule::~DaySchedule()
{}

DaySchedule& DaySchedule::operator=(const DaySchedule &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool DaySchedule::operator==(const DaySchedule &other) const
{
  return m_impl==other.m_impl;
}

bool DaySchedule::operator!=(const DaySchedule &other) const
{
  return m_impl!=other.m_impl;
}

std::string DaySchedule::write()
{
  return m_impl->write();
}

void DaySchedule::read(Reader &input)
{
  m_impl->read(input);
}

int DaySchedule::nr() const
{
  return m_impl->nr();
}

void DaySchedule::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int DaySchedule::shape() const
{
  return m_impl->shape();
}

void DaySchedule::setShape(const int shape)
{
  m_impl->setShape(shape);
}

int DaySchedule::utyp() const
{
  return m_impl->utyp();
}

void DaySchedule::setUtyp(const int utyp)
{
  m_impl->setUtyp(utyp);
}

int DaySchedule::ucnv() const
{
  return m_impl->ucnv();
}

void DaySchedule::setUcnv(const int ucnv)
{
  m_impl->setUcnv(ucnv);
}

std::string DaySchedule::name() const
{
  return m_impl->name();
}

void DaySchedule::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string DaySchedule::desc() const
{
  return m_impl->desc();
}

void DaySchedule::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

std::vector<SchedulePoint> DaySchedule::points() const
{
  return m_impl->points();
}

void DaySchedule::setPoints(const std::vector<SchedulePoint> &points)
{
  m_impl->setPoints(points);
}

DaySchedule::DayScheduleImpl::DayScheduleImpl() : m_nr(0), m_shape(0), m_utyp(0), m_ucnv(0)
{}

DaySchedule::DayScheduleImpl::DayScheduleImpl(int nr, int shape, int utyp, int ucnv, std::string name, std::string desc,
  std::vector<SchedulePoint> points) : DaySchedule::DayScheduleImpl()
{
  setNr(nr);
  setShape(shape);
  setUtyp(utyp);
  setUcnv(ucnv);
  setName(name);
  setDesc(desc);
  setPoints(points);
}

void DaySchedule::DayScheduleImpl::read(Reader& input)
{
  setNr(input.read<int>());
  int npts = input.read<int>();
  setShape(input.read<int>());
  setUtyp(input.read<int>());
  setUcnv(input.read<int>());
  setName(input.readString());
  setDesc(input.readLine());
  std::vector<SchedulePoint> points;
  for (int i = 0; i < npts; i++) {
    SchedulePoint object;
    object.read(input);
    points.push_back(object);
  }
  setPoints(points);

}

std::string DaySchedule::DayScheduleImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR((int)m_points.size()) + ' ' + ANY_TO_STR(m_shape) + ' ' + ANY_TO_STR(m_utyp) + ' ' + ANY_TO_STR(m_ucnv) + ' ' + m_name + '\n';
  string += m_desc + '\n';
  for (unsigned i = 0; i < m_points.size(); i++) {
    string += m_points[i].write();
  }
  return string;
}

int DaySchedule::DayScheduleImpl::nr() const
{
  return m_nr;
}

void DaySchedule::DayScheduleImpl::setNr(const int nr)
{
  m_nr = nr;
}

int DaySchedule::DayScheduleImpl::shape() const
{
  return m_shape;
}

void DaySchedule::DayScheduleImpl::setShape(const int shape)
{
  m_shape = shape;
}

int DaySchedule::DayScheduleImpl::utyp() const
{
  return m_utyp;
}

void DaySchedule::DayScheduleImpl::setUtyp(const int utyp)
{
  m_utyp = utyp;
}

int DaySchedule::DayScheduleImpl::ucnv() const
{
  return m_ucnv;
}

void DaySchedule::DayScheduleImpl::setUcnv(const int ucnv)
{
  m_ucnv = ucnv;
}

std::string DaySchedule::DayScheduleImpl::name() const
{
  return m_name;
}

void DaySchedule::DayScheduleImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string DaySchedule::DayScheduleImpl::desc() const
{
  return m_desc;
}

void DaySchedule::DayScheduleImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

std::vector<SchedulePoint> DaySchedule::DayScheduleImpl::points() const
{
  return m_points;
}

void DaySchedule::DayScheduleImpl::setPoints(const std::vector<SchedulePoint>& points)
{
  m_points = points;
}

WeekSchedule::WeekSchedule() :
  m_impl(std::shared_ptr<WeekScheduleImpl>(new WeekScheduleImpl()))
{}

WeekSchedule::WeekSchedule(int nr,int utyp,int ucnv,std::string name,std::string desc,std::vector<int> j) :
  m_impl(std::shared_ptr<WeekScheduleImpl>(new WeekScheduleImpl(nr,utyp,ucnv,name,desc,j)))
{}

WeekSchedule::WeekSchedule(const WeekSchedule &other) : m_impl(other.m_impl)
{}

WeekSchedule::~WeekSchedule()
{}

WeekSchedule& WeekSchedule::operator=(const WeekSchedule &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool WeekSchedule::operator==(const WeekSchedule &other) const
{
  return m_impl==other.m_impl;
}

bool WeekSchedule::operator!=(const WeekSchedule &other) const
{
  return m_impl!=other.m_impl;
}

std::string WeekSchedule::write()
{
  return m_impl->write();
}

void WeekSchedule::read(Reader &input)
{
  m_impl->read(input);
}

int WeekSchedule::nr() const
{
  return m_impl->nr();
}

void WeekSchedule::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int WeekSchedule::utyp() const
{
  return m_impl->utyp();
}

void WeekSchedule::setUtyp(const int utyp)
{
  m_impl->setUtyp(utyp);
}

int WeekSchedule::ucnv() const
{
  return m_impl->ucnv();
}

void WeekSchedule::setUcnv(const int ucnv)
{
  m_impl->setUcnv(ucnv);
}

std::string WeekSchedule::name() const
{
  return m_impl->name();
}

void WeekSchedule::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string WeekSchedule::desc() const
{
  return m_impl->desc();
}

void WeekSchedule::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

std::vector<int> WeekSchedule::j() const
{
  return m_impl->j();
}

void WeekSchedule::setJ(const std::vector<int> &j)
{
  m_impl->setJ(j);
}

WeekSchedule::WeekScheduleImpl::WeekScheduleImpl() : m_nr(0), m_utyp(0), m_ucnv(0)
{}

WeekSchedule::WeekScheduleImpl::WeekScheduleImpl(int nr, int utyp, int ucnv, std::string name, std::string desc, std::vector<int> j)
  : WeekSchedule::WeekScheduleImpl()
{
  setNr(nr);
  setUtyp(utyp);
  setUcnv(ucnv);
  setName(name);
  setDesc(desc);
  setJ(j);
}

void WeekSchedule::WeekScheduleImpl::read(Reader& input)
{
  setNr(input.read<int>());
  setUtyp(input.read<int>());
  setUcnv(input.read<int>());
  setName(input.readString());
  setDesc(input.readLine());
  std::vector<int> j;
  for (int i = 0; i < 12; i++) {
    j.push_back(input.read<int>());
  }
  setJ(j);
}

std::string WeekSchedule::WeekScheduleImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR(m_utyp) + ' ' + ANY_TO_STR(m_ucnv) + ' ' + m_name + '\n';
  string += m_desc + '\n';
  for (int i = 0; i < 12; i++) {
    string += ANY_TO_STR(m_j[i]) + ' ';
  }
  string += '\n';
  return string;
}

int WeekSchedule::WeekScheduleImpl::nr() const
{
  return m_nr;
}

void WeekSchedule::WeekScheduleImpl::setNr(const int nr)
{
  m_nr = nr;
}

int WeekSchedule::WeekScheduleImpl::utyp() const
{
  return m_utyp;
}

void WeekSchedule::WeekScheduleImpl::setUtyp(const int utyp)
{
  m_utyp = utyp;
}

int WeekSchedule::WeekScheduleImpl::ucnv() const
{
  return m_ucnv;
}

void WeekSchedule::WeekScheduleImpl::setUcnv(const int ucnv)
{
  m_ucnv = ucnv;
}

std::string WeekSchedule::WeekScheduleImpl::name() const
{
  return m_name;
}

void WeekSchedule::WeekScheduleImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string WeekSchedule::WeekScheduleImpl::desc() const
{
  return m_desc;
}

void WeekSchedule::WeekScheduleImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

std::vector<int> WeekSchedule::WeekScheduleImpl::j() const
{
  return m_j;
}

void WeekSchedule::WeekScheduleImpl::setJ(const std::vector<int>& j)
{
  m_j = j;
}

WindPressureProfile::WindPressureProfile() :
  m_impl(std::shared_ptr<WindPressureProfileImpl>(new WindPressureProfileImpl()))
{}

WindPressureProfile::WindPressureProfile(int nr,int type,std::string name,std::string desc,
  std::vector<PressureCoefficientPoint> coeffs) :
  m_impl(std::shared_ptr<WindPressureProfileImpl>(new WindPressureProfileImpl(nr,type,name,desc,coeffs)))
{}

WindPressureProfile::WindPressureProfile(const WindPressureProfile &other) : m_impl(other.m_impl)
{}

WindPressureProfile::~WindPressureProfile()
{}

WindPressureProfile& WindPressureProfile::operator=(const WindPressureProfile &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool WindPressureProfile::operator==(const WindPressureProfile &other) const
{
  return m_impl==other.m_impl;
}

bool WindPressureProfile::operator!=(const WindPressureProfile &other) const
{
  return m_impl!=other.m_impl;
}


std::string WindPressureProfile::write()
{
  return m_impl->write();
}

void WindPressureProfile::read(Reader &input)
{
  m_impl->read(input);
}

int WindPressureProfile::nr() const
{
  return m_impl->nr();
}

void WindPressureProfile::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int WindPressureProfile::type() const
{
  return m_impl->type();
}

void WindPressureProfile::setType(const int type)
{
  m_impl->setType(type);
}

std::string WindPressureProfile::name() const
{
  return m_impl->name();
}

void WindPressureProfile::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string WindPressureProfile::desc() const
{
  return m_impl->desc();
}

void WindPressureProfile::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

std::vector<PressureCoefficientPoint> WindPressureProfile::coeffs() const
{
  return m_impl->coeffs();
}

void WindPressureProfile::setCoeffs(const std::vector<PressureCoefficientPoint> &coeffs)
{
  m_impl->setCoeffs(coeffs);
}

WindPressureProfile::WindPressureProfileImpl::WindPressureProfileImpl() : m_nr(0), m_type(0)
{}

WindPressureProfile::WindPressureProfileImpl::WindPressureProfileImpl(int nr, int type, std::string name, std::string desc,
  std::vector<PressureCoefficientPoint> coeffs) : WindPressureProfile::WindPressureProfileImpl()
{
  setNr(nr);
  setType(type);
  setName(name);
  setDesc(desc);
  setCoeffs(coeffs);
}

void WindPressureProfile::WindPressureProfileImpl::read(Reader& input)
{
  setNr(input.read<int>());
  int npts = input.read<int>();
  setType(input.read<int>());
  setName(input.readString());
  setDesc(input.readLine());
  std::vector<PressureCoefficientPoint> coeffs;
  for (int i = 0; i < npts; i++) {
    PressureCoefficientPoint object;
    object.read(input);
    coeffs.push_back(object);
  }
  setCoeffs(coeffs);
}

std::string WindPressureProfile::WindPressureProfileImpl::write()
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + ANY_TO_STR((int)m_coeffs.size()) + ' ' + ANY_TO_STR(m_type) + ' ' + m_name + '\n';
  string += m_desc + '\n';
  for (unsigned i = 0; i < m_coeffs.size(); i++) {
    string += m_coeffs[i].write();
  }
  return string;
}

int WindPressureProfile::WindPressureProfileImpl::nr() const
{
  return m_nr;
}

void WindPressureProfile::WindPressureProfileImpl::setNr(const int nr)
{
  m_nr = nr;
}

int WindPressureProfile::WindPressureProfileImpl::type() const
{
  return m_type;
}

void WindPressureProfile::WindPressureProfileImpl::setType(const int type)
{
  m_type = type;
}

std::string WindPressureProfile::WindPressureProfileImpl::name() const
{
  return m_name;
}

void WindPressureProfile::WindPressureProfileImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string WindPressureProfile::WindPressureProfileImpl::desc() const
{
  return m_desc;
}

void WindPressureProfile::WindPressureProfileImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

std::vector<PressureCoefficientPoint> WindPressureProfile::WindPressureProfileImpl::coeffs() const
{
  return m_coeffs;
}

void WindPressureProfile::WindPressureProfileImpl::setCoeffs(const std::vector<PressureCoefficientPoint>& coeffs)
{
  m_coeffs = coeffs;
}

ControlNode::Type ControlNode::convertTag(std::string &string)
{
  std::string tags[37] = {"sns","sch","set",
    "cvf","dvf","log","pas",
    "mod","hys","abs","bin",
    "dls","dlx","int","rav",
    "inv","and","od","xor",
    "add","sub","mul","div",
    "sum","avg","max","min",
    "lls","uls","lbs","ubs",
    "llc","ulc","pc1","pi1",
    "sup","sph"};
  ControlNode::Type type[37] = {CT_SNS,CT_SCH,CT_SET,CT_CVF,CT_DVF,CT_LOG,CT_PAS,CT_MOD,
    CT_HYS,CT_ABS,CT_BIN,CT_DLS,CT_DLX,CT_INT,CT_RAV,CT_INV,CT_AND,CT_OR,CT_XOR,CT_ADD,
    CT_SUB,CT_MUL,CT_DIV,CT_SUM,CT_AVG,CT_MAX,CT_MIN,CT_LLS,CT_ULS,CT_LBS,CT_UBS,CT_LLC,
    CT_ULC,CT_PC1,CT_PI1,CT_SUP,CT_SPH};
  for(int i=0;i<37;i++)
    if(string==tags[i])
      return type[i];
  return ControlNode::UNKNOWN;
}

ControlNode* ControlNode::readElement(Reader &input)
{
  ControlNode *out=nullptr;
  int nr = input.read<int>();
  std::string dataType = input.readString();
  int seqnr = input.read<int>();
  unsigned int flags = input.read<unsigned int>();
  int inreq = input.read<int>();
  int n1 = input.read<int>();
  int n2 = input.read<int>();
  std::string name = input.readString();
  std::string desc = input.readLine();
  int kind = convertTag(dataType);
  switch(kind)
  {
  case ControlNode::CT_CVF:
    {
      CvfDat *obj = new CvfDat(nr,seqnr,flags,inreq,n1,n2,name,desc);
      obj->readDetails(input);
      out = static_cast<ControlNode*>(obj);
      break;
    }
  case ControlNode::CT_DVF:
    {
      DvfDat *obj = new DvfDat(nr,seqnr,flags,inreq,n1,n2,name,desc);
      obj->readDetails(input);
      out = static_cast<ControlNode*>(obj);
      break;
    }
  case ControlNode::CT_PAS:
  case ControlNode::CT_ABS:
  case ControlNode::CT_BIN:
  case ControlNode::CT_INT:
  case ControlNode::CT_INV:
  case ControlNode::CT_AND:
  case ControlNode::CT_OR:
  case ControlNode::CT_XOR:
  case ControlNode::CT_ADD:
  case ControlNode::CT_SUB:
  case ControlNode::CT_MUL:
  case ControlNode::CT_DIV:
  case ControlNode::CT_LLS:
  case ControlNode::CT_ULS:
  case ControlNode::CT_LLC:
  case ControlNode::CT_ULC:
  case ControlNode::CT_SPH:
  case ControlNode::CT_SNS:
  case ControlNode::CT_SCH:
  case ControlNode::CT_SET:
  case ControlNode::CT_LOG:
  case ControlNode::CT_MOD:
  case ControlNode::CT_HYS:
  case ControlNode::CT_DLS:
  case ControlNode::CT_DLX:
  case ControlNode::CT_RAV:
  case ControlNode::CT_SUM:
  case ControlNode::CT_AVG:
  case ControlNode::CT_MAX:
  case ControlNode::CT_MIN:
  case ControlNode::CT_LBS:
  case ControlNode::CT_UBS:
  case ControlNode::CT_PC1:
  case ControlNode::CT_PI1:
  case ControlNode::CT_SUP:
    {
      std::string mesg = "Control node type '" + dataType + "' is not supported.";
      LOG_FATAL(mesg);
    }
  case ControlNode::UNKNOWN:
  default:
    std::string mesg = "Unknown control node type '" + dataType + "' at line " + std::to_string(input.lineNumber());
    LOG_FATAL(mesg);
  }
  return out;
}

CdvDat::CdvDat() :
  m_impl(std::shared_ptr<CdvDatImpl>(new CdvDatImpl()))
{}

CdvDat::CdvDat(int nr,int seqnr,unsigned int flags,int inreq,int n1,int n2,std::string name,std::string desc) :
  m_impl(std::shared_ptr<CdvDatImpl>(new CdvDatImpl(nr,seqnr,flags,inreq,n1,n2,name,desc)))
{}

CdvDat::CdvDat(int nr,int seqnr,unsigned int flags,int inreq,int n1,int n2,std::string name,std::string desc,
  std::string valuename) :
  m_impl(std::shared_ptr<CdvDatImpl>(new CdvDatImpl(nr,seqnr,flags,inreq,n1,n2,name,desc,valuename)))
{}

CdvDat::CdvDat(const CdvDat &other) : m_impl(other.m_impl)
{}

CdvDat::~CdvDat()
{}

CdvDat& CdvDat::operator=(const CdvDat &other)
{
  m_impl = other.m_impl;
  return *this;
}

bool CdvDat::operator==(const CdvDat &other) const
{
  return m_impl==other.m_impl;
}

bool CdvDat::operator!=(const CdvDat &other) const
{
  return m_impl!=other.m_impl;
}

std::string CdvDat::write()
{
  return m_impl->write(dataType());
}

void CdvDat::read(Reader &input)
{
  m_impl->read(input);
}

void CdvDat::readDetails(Reader &input)
{
  m_impl->readDetails(input);
}

int CdvDat::nr() const
{
  return m_impl->nr();
}

void CdvDat::setNr(const int nr)
{
  m_impl->setNr(nr);
}

int CdvDat::seqnr() const
{
  return m_impl->seqnr();
}

void CdvDat::setSeqnr(const int seqnr)
{
  m_impl->setSeqnr(seqnr);
}

unsigned int CdvDat::flags() const
{
  return m_impl->flags();
}

void CdvDat::setFlags(const unsigned int flags)
{
  m_impl->setFlags(flags);
}

int CdvDat::inreq() const
{
  return m_impl->inreq();
}

void CdvDat::setInreq(const int inreq)
{
  m_impl->setInreq(inreq);
}

int CdvDat::n1() const
{
  return m_impl->n1();
}

void CdvDat::setN1(const int n1)
{
  m_impl->setN1(n1);
}

int CdvDat::n2() const
{
  return m_impl->n2();
}

void CdvDat::setN2(const int n2)
{
  m_impl->setN2(n2);
}

std::string CdvDat::name() const
{
  return m_impl->name();
}

void CdvDat::setName(const std::string &name)
{
  m_impl->setName(name);
}

std::string CdvDat::desc() const
{
  return m_impl->desc();
}

void CdvDat::setDesc(const std::string &desc)
{
  m_impl->setDesc(desc);
}

std::string CdvDat::valuename() const
{
  return m_impl->valuename();
}

void CdvDat::setValuename(const std::string &valuename)
{
  m_impl->setValuename(valuename);
}

CdvDat::CdvDatImpl::CdvDatImpl() : m_nr(0), m_seqnr(0), m_flags(0), m_inreq(0), m_n1(0), m_n2(0)
{}

CdvDat::CdvDatImpl::CdvDatImpl(int nr, int seqnr, unsigned int flags, int inreq, int n1, int n2, std::string name, std::string desc)
  : CdvDat::CdvDatImpl()
{
  setNr(nr);
  setSeqnr(seqnr);
  setFlags(flags);
  setInreq(inreq);
  setN1(n1);
  setN2(n2);
  setName(name);
  setDesc(desc);
}

CdvDat::CdvDatImpl::CdvDatImpl(int nr, int seqnr, unsigned int flags, int inreq, int n1, int n2, std::string name, std::string desc,
  std::string valuename) : CdvDat::CdvDatImpl()
{
  setNr(nr);
  setSeqnr(seqnr);
  setFlags(flags);
  setInreq(inreq);
  setN1(n1);
  setN2(n2);
  setName(name);
  setDesc(desc);
  setValuename(valuename);
}

void CdvDat::CdvDatImpl::read(Reader& input)
{
  setNr(input.read<int>());
  std::string dataType = input.readString(); // Should really check this
  setSeqnr(input.read<int>());
  setFlags(input.read<unsigned int>());
  setInreq(input.read<int>());
  setN1(input.read<int>());
  setN2(input.read<int>());
  setName(input.readString());
  setDesc(input.readLine());
  setValuename(input.readLine());
}

std::string CdvDat::CdvDatImpl::write(std::string datatype)
{
  std::string string;
  string += ANY_TO_STR(m_nr) + ' ' + datatype + '\n';
  string += ANY_TO_STR(m_seqnr) + ' ' + ANY_TO_STR(m_flags) + ' ' + ANY_TO_STR(m_inreq) + ' '
    + ANY_TO_STR(m_n1) + ' ' + ANY_TO_STR(m_n2) + ' ' + m_name + '\n';
  string += m_desc + '\n';
  string += m_valuename + '\n';
  return string;
}

void CdvDat::CdvDatImpl::readDetails(Reader& input)
{
  setValuename(input.readLine());
}

int CdvDat::CdvDatImpl::nr() const
{
  return m_nr;
}

void CdvDat::CdvDatImpl::setNr(const int nr)
{
  m_nr = nr;
}

int CdvDat::CdvDatImpl::seqnr() const
{
  return m_seqnr;
}

void CdvDat::CdvDatImpl::setSeqnr(const int seqnr)
{
  m_seqnr = seqnr;
}

unsigned int CdvDat::CdvDatImpl::flags() const
{
  return m_flags;
}

void CdvDat::CdvDatImpl::setFlags(const unsigned int flags)
{
  m_flags = flags;
}

int CdvDat::CdvDatImpl::inreq() const
{
  return m_inreq;
}

void CdvDat::CdvDatImpl::setInreq(const int inreq)
{
  m_inreq = inreq;
}

int CdvDat::CdvDatImpl::n1() const
{
  return m_n1;
}

void CdvDat::CdvDatImpl::setN1(const int n1)
{
  m_n1 = n1;
}

int CdvDat::CdvDatImpl::n2() const
{
  return m_n2;
}

void CdvDat::CdvDatImpl::setN2(const int n2)
{
  m_n2 = n2;
}

std::string CdvDat::CdvDatImpl::name() const
{
  return m_name;
}

void CdvDat::CdvDatImpl::setName(const std::string& name)
{
  m_name = name;
}

std::string CdvDat::CdvDatImpl::desc() const
{
  return m_desc;
}

void CdvDat::CdvDatImpl::setDesc(const std::string& desc)
{
  m_desc = desc;
}

std::string CdvDat::CdvDatImpl::valuename() const
{
  return m_valuename;
}

void CdvDat::CdvDatImpl::setValuename(const std::string& valuename)
{
  m_valuename = valuename;
}

CvfDat::CvfDat() : CdvDat()
{}

CvfDat::CvfDat(int nr,int seqnr,unsigned int flags,int inreq,int n1,int n2,std::string name,std::string desc)
  : CdvDat(nr,seqnr,flags,inreq,n1,n2,name,desc)
{}

CvfDat::CvfDat(int nr,int seqnr,unsigned int flags,int inreq,int n1,int n2,std::string name,std::string desc,
  std::string valuename) : CdvDat(nr,seqnr,flags,inreq,n1,n2,name,desc,valuename)
{}

DvfDat::DvfDat() : CdvDat()
{}

DvfDat::DvfDat(int nr,int seqnr,unsigned int flags,int inreq,int n1,int n2,std::string name,std::string desc)
  : CdvDat(nr,seqnr,flags,inreq,n1,n2,name,desc)
{}

DvfDat::DvfDat(int nr,int seqnr,unsigned int flags,int inreq,int n1,int n2,std::string name,std::string desc,
  std::string valuename) : CdvDat(nr,seqnr,flags,inreq,n1,n2,name,desc,valuename)
{}

} 
