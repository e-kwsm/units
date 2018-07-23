// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNIT_SYSTEMS_METRIC_HARTREE_HPP_INCLUDED
#define BOOST_UNIT_SYSTEMS_METRIC_HARTREE_HPP_INCLUDED

#include <boost/units/conversion.hpp>
#include <boost/units/pow.hpp>
#include <boost/units/systems/si/energy.hpp>
#include <boost/units/systems/si/codata/atomic-nuclear_constants.hpp>
#include <boost/units/systems/si/codata/electron_constants.hpp>
#include <boost/units/systems/si/codata/universal_constants.hpp>
#include <boost/units/systems/single_unit_system.hpp>

BOOST_UNITS_DEFINE_BASE_UNIT_WITH_CONVERSIONS(metric, hartree, "hartree", "Ha", (
          boost::units::pow<2>(boost::units::si::constants::codata::hbar)
        / boost::units::si::constants::codata::m_e
        / boost::units::pow<2>(boost::units::si::constants::codata::a_0)
        / boost::units::si::joule
        ).value(), si::energy, 9999);
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric, hartree, energy)

#endif // BOOST_UNIT_SYSTEMS_METRIC_HARTREE_HPP_INCLUDED
