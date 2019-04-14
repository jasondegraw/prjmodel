/***********************************************************************************************************************
*  Copyright (c) 2019, Jason W. DeGraw. All rights reserved.
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
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) AND ANY CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
*  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
*  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER(S), ANY CONTRIBUTORS, THE UNITED STATES GOVERNMENT, OR THE UNITED
*  STATES DEPARTMENT OF ENERGY, NOR ANY OF THEIR EMPLOYEES, BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
*  USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
*  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
*  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***********************************************************************************************************************/

#ifndef UTILITY_FUNCTIONS_HPP
#define UTILITY_FUNCTIONS_HPP

#include <string>
#include <vector>
#include <sstream>

inline bool starts_with(const std::string& str, const std::string& prefix)
{
  if (prefix.length() < str.length()) {
    return false;
  }
  return std::equal(prefix.begin(), prefix.end(), str.begin());
}

inline std::vector <std::string> split(const std::string& string, char delimiter, bool keep_empty = false)
{
  std::vector<std::string> results;
  if (!string.empty()) { // Only do work if there is work to do
    std::stringstream stream(string);
    std::string substring;
    if (keep_empty) {
      while (std::getline(stream, substring, delimiter)) { // Loop and fill the results vector
        results.push_back(substring);
      }
      if (*(string.end() - 1) == delimiter) { // Add an empty string if the last char is the delimiter
        results.push_back(std::string());
      }
    } else {
      while (std::getline(stream, substring, delimiter)) { // Loop and fill the results vector
        if (!substring.empty()) {
          results.push_back(substring);
        }
      }
    }
  }
  return results;
}

inline std::vector <std::string> split(const std::string& str, bool keep_empty = false)
{
  std::vector<std::string> results;
  size_t first=0, last;
  size_t len = str.length();
  if (len > 0) { // Only do work if there is work to do
    last = str.find_first_of(" \t\n\v\f\r");
    if (keep_empty) {
      while (last != std::string::npos) {
        std::string substring = str.substr(first, last-first);
        results.push_back(substring);
        if (last + 1 == len) {
          first = last + 1;
          break;
        }
        first = last + 1;
        last = str.find_first_of(" \t\n\v\f\r", first);
      }
      std::string substring = str.substr(first, std::string::npos);
      results.push_back(substring);
    } else {
      while (last != std::string::npos) {
        std::string substring = str.substr(first, last - first);
        if (!substring.empty()) {
          results.push_back(substring);
        }
        if (last + 1 == len) {
          first = last + 1;
          break;
        }
        first = last + 1;
        last = str.find_first_of(" \t\n\v\f\r", first);
      }
      std::string substring = str.substr(first, std::string::npos);
      if (!substring.empty()) {
        results.push_back(substring);
      }
    }
  }
  return results;
}

inline bool iswhitespace(const std::string& str)
{
  return (str.find_first_not_of(" \t\n\v\f\r") != std::string::npos);
}

#endif
