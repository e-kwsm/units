// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_AU_ENERGY_HPP
#define BOOST_UNITS_AU_ENERGY_HPP

#include <boost/units/systems/au/base.hpp>

namespace boost {

namespace units {

namespace au {

typedef unit<energy_dimension, au::system> energy;

BOOST_UNITS_STATIC_CONSTANT(au_energy,energy);

} // namespace au

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_AU_ENERGY_HPP
