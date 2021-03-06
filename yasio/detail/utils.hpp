//////////////////////////////////////////////////////////////////////////////////////////
// A cross platform socket APIs, support ios & android & wp8 & window store
// universal app
//////////////////////////////////////////////////////////////////////////////////////////
/*
The MIT License (MIT)

Copyright (c) 2012-2020 HALX99

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef YASIO__UTILS_HPP
#define YASIO__UTILS_HPP
#include <chrono>
#include <algorithm>
#include "yasio/cxx17/feature_test.hpp"

namespace yasio
{
// typedefs
typedef long long highp_time_t;
typedef std::chrono::high_resolution_clock highp_clock_t;
typedef std::chrono::system_clock system_clock_t;
// The high precision micro seconds timestamp
template <typename _T = highp_clock_t> inline long long highp_clock()
{
  auto duration = _T::now().time_since_epoch();
  return std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
}

#if YASIO__HAS_CXX17
using std::clamp;
#else
template <typename _T> const _T& clamp(const _T& v, const _T& lo, const _T& hi)
{
  ASSERT(!(hi < lo));
  return v < lo ? lo : hi < v ? hi : v;
}
#endif
} // namespace yasio

#endif
