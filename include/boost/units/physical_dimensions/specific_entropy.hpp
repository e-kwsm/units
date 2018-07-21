// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2018 Eisuke Kawashima
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SPECIFIC_ENTROPY_DERIVED_DIMENSION_HPP
#define BOOST_UNITS_SPECIFIC_ENTROPY_DERIVED_DIMENSION_HPP

#include <boost/units/derived_dimension.hpp>
#include <boost/units/physical_dimensions/length.hpp>
#include <boost/units/physical_dimensions/time.hpp>
#include <boost/units/physical_dimensions/temperature.hpp>

namespace boost {

namespace units {

/// derived dimension for specific entropy : L^2 T^-2 Theta^-1
typedef derived_dimension<length_base_dimension,2,
                          time_base_dimension,-2,
                          temperature_base_dimension,-1>::type specific_entropy_dimension;

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SPECIFIC_ENTROPY_DERIVED_DIMENSION_HPP
