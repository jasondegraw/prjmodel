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
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) AND ANY CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER(S), ANY CONTRIBUTORS, THE UNITED STATES GOVERNMENT, OR THE UNITED
// STATES DEPARTMENT OF ENERGY, NOR ANY OF THEIR EMPLOYEES, BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
// USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef PRJMODEL_CONNECTOR_HPP
#define PRJMODEL_CONNECTOR_HPP

#include <sstream>
#include <vector>
#include <list>
#include <memory>

#include "prjmodel_api.hpp"

#include "defines.hpp"

namespace prjmodel {

template <typename I, typename T> class Connector
{
public:

  Connector(I i) : m_i(i), m_t(nullptr)
  {}

  operator I& ()
  {
    return m_i;
  }

  operator I() const
  {
    return m_i;
  }

  void connect(T* t)
  {
    m_t = t;
  }

  T* object()
  {
    return m_t;
  }

private:
  I m_i;
  T* m_t;

};

} // prjmodel

#endif // PRJMODEL_CONNECTOR_HPP
