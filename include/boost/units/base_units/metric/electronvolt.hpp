// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNIT_SYSTEMS_METRIC_ELECTRONVOLT_HPP_INCLUDED
#define BOOST_UNIT_SYSTEMS_METRIC_ELECTRONVOLT_HPP_INCLUDED

#include <boost/units/conversion.hpp>
#include <boost/units/systems/si/energy.hpp>
#include <boost/units/systems/si/codata/electromagnetic_constants.hpp>

BOOST_UNITS_DEFINE_BASE_UNIT_WITH_CONVERSIONS(metric, electronvolt, "electronvolt", "eV", (boost::units::si::constants::codata::e / boost::units::si::coulomb).value(), si::energy, 8888);

namespace boost {
namespace units {
namespace metric {
typedef make_system<electronvolt_base_unit>::type electronvoltsystem_;
typedef unit<energy_dimension,electronvoltsystem_> electronvolt_energy;
static BOOST_CONSTEXPR electronvolt_energy electronvolts;
}
}
}

#endif // BOOST_UNIT_SYSTEMS_METRIC_ELECTRONVOLT_HPP_INCLUDED
