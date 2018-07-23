// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_AU_BASE_HPP
#define BOOST_UNITS_AU_BASE_HPP

//#include <string>

#include <boost/units/static_constant.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/make_system.hpp>

#include <boost/units/base_units/au/action.hpp>
#include <boost/units/base_units/au/energy.hpp>
#include <boost/units/base_units/au/charge.hpp>
#include <boost/units/base_units/au/length.hpp>
#include <boost/units/base_units/au/mass.hpp>
//#include <boost/units/base_units/si/candela.hpp>
//#include <boost/units/base_units/angle/radian.hpp>
//#include <boost/units/base_units/angle/steradian.hpp>

namespace boost {

namespace units {

namespace au {

/// placeholder class defining atomic unit system
typedef make_system<action_base_unit,
                    charge_base_unit,
                    energy_base_unit,
                    length_base_unit,
                    mass_base_unit>::type system;

/// dimensionless au unit
//typedef unit<dimensionless_type,system> dimensionless;

} // namespace au

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_AU_BASE_HPP
