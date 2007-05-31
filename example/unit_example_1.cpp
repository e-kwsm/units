// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

/** 
\file
    
\brief unit_example_1.cpp

\detailed
Test dimension list manipulation.

Output:
@verbatim

//[unit_example_1_output
length_dimension  = dimension_list<dim<length_base_dimension, static_rational<1l, 1l> >, dimensionless_type>
mass_dimension    = dimension_list<dim<mass_base_dimension, static_rational<1l, 1l> >, dimensionless_type>
time_dimension    = dimension_list<dim<time_base_dimension, static_rational<1l, 1l> >, dimensionless_type>
energy_dim  = dimension_list<dim<length_base_dimension, static_rational<2l, 1l> >, dimension_list<dim<mass_base_dimension, static_rational<1l, 1l> >, dimension_list<dim<time_base_dimension, static_rational<-2l, 1l> >, dimensionless_type> > >
LM_type      = dimension_list<dim<length_base_dimension, static_rational<1l, 1l> >, dimension_list<dim<mass_base_dimension, static_rational<1l, 1l> >, dimensionless_type> >
L_T_type     = dimension_list<dim<length_base_dimension, static_rational<1l, 1l> >, dimension_list<dim<time_base_dimension, static_rational<-1l, 1l> >, dimensionless_type> >
V_type       = dimension_list<dim<length_base_dimension, static_rational<1l, 1l> >, dimension_list<dim<time_base_dimension, static_rational<-1l, 1l> >, dimensionless_type> >
//]

@endverbatim
**/

// undefine this if you don't want to demangle symbols
// need to link with libboost_regex to get demangling functionality
#define MCS_USE_DEMANGLING
//#define MCS_USE_BOOST_REGEX_DEMANGLING

#include <boost/type_traits/is_same.hpp>

#include <boost/mpl/assert.hpp>

#include <boost/units/detail/utility.hpp>

#include "test_system.hpp"

namespace mpl = boost::mpl;

int main(void)
{   
    using namespace boost::units;

    BOOST_MPL_ASSERT((boost::is_same<length_dimension, mpl::push_front<dimensionless_type, dim<length_base_dimension, static_rational<1L, 1L> > >::type>));
    BOOST_MPL_ASSERT((boost::is_same<mass_dimension, mpl::push_front<dimensionless_type, dim<mass_base_dimension, static_rational<1L, 1L> > >::type>));
    BOOST_MPL_ASSERT((boost::is_same<energy_dim, 
        mpl::push_front<
        mpl::push_front<
        mpl::push_front<
        dimensionless_type,
        dim<time_base_dimension, static_rational<-2L, 1L> > >::type,
        dim<mass_base_dimension, static_rational<1L, 1L> > >::type,
        dim<length_base_dimension, static_rational<2L, 1L> > >::type>));
                              
    std::cout << "length_dimension  = " << simplify_typename(length_dimension()) << std::endl
              << "mass_dimension    = " << simplify_typename(mass_dimension()) << std::endl
              << "time_dimension    = " << simplify_typename(time_dimension()) << std::endl
              << "energy_dim  = " << simplify_typename(energy_dim()) << std::endl;
    
    //[unit_example_1_snippet_1
    typedef mpl::times<length_dimension,mass_dimension>::type                                             LM_type;
    typedef mpl::divides<length_dimension,time_dimension>::type                                           L_T_type;
    typedef static_root<mpl::divides<energy_dim,mass_dimension>::type,static_rational<2> >::type    V_type;
    //]
    
    BOOST_MPL_ASSERT((boost::is_same<LM_type, 
        mpl::push_front<
        mpl::push_front<
        dimensionless_type,
        dim<mass_base_dimension, static_rational<1L, 1L> > >::type,
        dim<length_base_dimension, static_rational<1L, 1L> > >::type>));

    BOOST_MPL_ASSERT((boost::is_same<L_T_type, 
        mpl::push_front<
        mpl::push_front<
        dimensionless_type,
        dim<time_base_dimension, static_rational<-1L, 1L> > >::type,
        dim<length_base_dimension, static_rational<1L, 1L> > >::type>));

    BOOST_MPL_ASSERT((boost::is_same<V_type, 
        mpl::push_front<
        mpl::push_front<
        dimensionless_type,
        dim<time_base_dimension, static_rational<-1L, 1L> > >::type,
        dim<length_base_dimension, static_rational<1L, 1L> > >::type>));
    
    std::cout << "LM_type      = " << simplify_typename(LM_type()) << std::endl
              << "L_T_type     = " << simplify_typename(L_T_type()) << std::endl
              << "V_type       = " << simplify_typename(V_type()) << std::endl;
              
    return 0;
}
