// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_AU_CHARGE_HPP
#define BOOST_UNITS_AU_CHARGE_HPP

#include <boost/units/systems/au/base.hpp>

namespace boost {

namespace units {

namespace au {

typedef unit<charge_dimension, au::system> charge;

BOOST_UNITS_STATIC_CONSTANT(au_charge,charge);

} // namespace au

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_AU_CHARGE_HPP
