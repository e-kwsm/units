// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_US_MIL_BASE_UNIT_HPP
#define BOOST_UNITS_US_MIL_BASE_UNIT_HPP

#include <boost/units/scaled_base_unit.hpp>
#include <boost/units/static_rational.hpp>
#include <boost/units/scale.hpp>
#include <boost/units/base_units/us/yard.hpp>
#include <boost/units/systems/single_unit_system.hpp>

namespace boost {

namespace units {

namespace us {

typedef scaled_base_unit<yard_base_unit, scale<36000, static_rational<-1> > > mil_base_unit;

} // namespace us

template<>
struct base_unit_info<us::mil_base_unit> {
    static BOOST_CONSTEXPR const char* name()   { return("mil"); }
    static BOOST_CONSTEXPR const char* symbol() { return("mil"); }
};

} // namespace units

} // namespace boost

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(us, mil, length)

#endif // BOOST_UNITS_US_MIL_BASE_UNIT_HPP
