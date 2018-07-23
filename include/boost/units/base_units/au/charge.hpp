// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_AU_CHARGE_BASE_UNIT_HPP
#define BOOST_UNITS_AU_CHARGE_BASE_UNIT_HPP

#include <string>

#include <boost/units/config.hpp>
#include <boost/units/base_unit.hpp>
//#include <boost/units/scaled_base_unit.hpp>
#include <boost/units/physical_dimensions/charge.hpp>

namespace boost {

namespace units {

namespace au {

struct charge_base_unit : public base_unit<charge_base_unit, charge_dimension, 98752442>
{
    static std::string name()   { return("au (charge)"); }
    static std::string symbol() { return("e"); }
};

} // namespace au

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::au::charge_base_unit)

#endif

#endif // BOOST_UNITS_AU_CHARGE_BASE_UNIT_HPP
