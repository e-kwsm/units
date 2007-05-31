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
    
\brief unit_example_9.cpp

\detailed
Demonstrate a complex number class that functions correctly with quantities.

Output:
@verbatim

//[unit_example_9_output_1
+L      = 2 + 1 i m
-L      = -2 + -1 i m
L+L     = 4 + 2 i m
L-L     = 0 + 0 i m
L*L     = 3 + 4 i m^2
L/L     = 1 + 0 i dimensionless
L^3     = 2 + 11 i m^3
L^(3/2) = 2.56713 + 2.14247 i m^(3/2)
3vL     = 1.29207 + 0.201294 i m^(1/3)
(3/2)vL = 1.62894 + 0.520175 i m^(2/3)
//]

//[unit_example_9_output_2
+L      = 2 m + 1 m i
-L      = -2 m + -1 m i
L+L     = 4 m + 2 m i
L-L     = 0 m + 0 m i
L*L     = 3 m^2 + 4 m^2 i
L/L     = 1 dimensionless + 0 dimensionless i
L^3     = 2 m^3 + 11 m^3 i
L^(3/2) = 2.56713 m^(3/2) + 2.14247 m^(3/2) i
3vL     = 1.29207 m^(1/3) + 0.201294 m^(1/3) i
(3/2)vL = 1.62894 m^(2/3) + 0.520175 m^(2/3) i
//]

@endverbatim
**/

#include <cmath>
#include <complex>
#include <iostream>
#include <sstream>
#include <algorithm>

#include <boost/mpl/list.hpp>

#include <boost/units/io.hpp>
#include <boost/units/quantity.hpp>

#include "test_system.hpp"

//[unit_example_9_class_snippet_1
namespace boost {

namespace units {

/// replacement complex class 
template<class T>
class complex
{
    public:
        typedef complex<T>  this_type;
        
        complex(const T& r = 0,const T& i = 0) : r_(r),i_(i) { }
        complex(const this_type& source) : r_(source.r_),i_(source.i_) { }
        
        this_type& operator=(const this_type& source)
        {
            if (this == &source) return *this;
            
            r_ = source.r_;
            i_ = source.i_;
            
            return *this;
        }
        
        T& real()                   { return r_; }
        T& imag()                   { return i_; }
        
        const T& real() const       { return r_; }
        const T& imag() const       { return i_; }

        this_type& operator+=(const T& val)             { r_ += val; return *this; }
        this_type& operator-=(const T& val)             { r_ -= val; return *this; }
        this_type& operator*=(const T& val)             { r_ *= val; i_ *= val; return *this; }
        this_type& operator/=(const T& val)             { r_ /= val; i_ /= val; return *this; }
        
        this_type& operator+=(const this_type& source)  { r_ += source.r_; i_ += source.i_; return *this; }
        this_type& operator-=(const this_type& source)  { r_ -= source.r_; i_ -= source.i_; return *this; }
        this_type& operator*=(const this_type& source)  { *this = *this*source; return *this; }
        this_type& operator/=(const this_type& source)  { *this = *this/source; return *this; }
        
    private:
        T   r_,i_;
};

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::complex, 1)

#endif

namespace boost {

namespace units {

template<class X>
complex<typename unary_plus_typeof_helper<X>::type>
operator+(const complex<X>& x)
{
    typedef typename unary_plus_typeof_helper<X>::type  type;
    
    return complex<type>(x.real(),x.imag());
}

template<class X>
complex<typename unary_minus_typeof_helper<X>::type>
operator-(const complex<X>& x)
{
    typedef typename unary_minus_typeof_helper<X>::type type;
    
    return complex<type>(-x.real(),-x.imag());
}

template<class X,class Y>
complex<typename add_typeof_helper<X,Y>::type>
operator+(const complex<X>& x,const complex<Y>& y)
{
    typedef typename boost::units::add_typeof_helper<X,Y>::type type;
    
    return complex<type>(x.real()+y.real(),x.imag()+y.imag());
}

template<class X,class Y>
complex<typename boost::units::subtract_typeof_helper<X,Y>::type>
operator-(const complex<X>& x,const complex<Y>& y)
{
    typedef typename boost::units::subtract_typeof_helper<X,Y>::type    type;
    
    return complex<type>(x.real()-y.real(),x.imag()-y.imag());
}

template<class X,class Y>
complex<typename boost::units::multiply_typeof_helper<X,Y>::type>
operator*(const complex<X>& x,const complex<Y>& y)
{
    typedef typename boost::units::multiply_typeof_helper<X,Y>::type    type;
    
    return complex<type>(x.real()*y.real()-x.imag()*y.imag(),x.real()*y.imag()+x.imag()*y.real());
}

template<class X,class Y>
complex<typename boost::units::divide_typeof_helper<X,Y>::type>
operator/(const complex<X>& x,const complex<Y>& y)
{
    typedef typename boost::units::divide_typeof_helper<X,Y>::type  type;
    
    return complex<type>((x.real()*y.real()+x.imag()*y.imag())/(y.real()*y.real()+y.imag()*y.imag()),
                         (x.imag()*y.real()-x.real()*y.imag())/(y.real()*y.real()+y.imag()*y.imag()));
}

template<class Y>
complex<Y> 
pow(const complex<Y>& x,const Y& y)
{
    std::complex<Y> tmp(x.real(),x.imag());
    
    tmp = std::pow(tmp,y);
    
    return complex<Y>(tmp.real(),tmp.imag());
}

template<class Y>
std::ostream& operator<<(std::ostream& os,const complex<Y>& val)
{
    os << val.real() << " + " << val.imag() << " i";

    return os;
}

/// specialize power typeof helper
template<class Y,long N,long D> 
struct power_dimof_helper<complex<Y>,static_rational<N,D> >                
{ 
    typedef complex<typename power_dimof_helper<Y,static_rational<N,D> >::type>    type; 
    
    static type value(const complex<Y>& x)  
    { 
        const static_rational<N,D>  rat;

        const Y    m = Y(rat.numerator())/Y(rat.denominator());
        
        return boost::units::pow(x,m);
    }
};

/// specialize root typeof helper
template<class Y,long N,long D> 
struct root_typeof_helper<complex<Y>,static_rational<N,D> >                
{ 
    typedef complex<typename root_typeof_helper<Y,static_rational<N,D> >::type>    type; 
    
    static type value(const complex<Y>& x)  
    { 
        const static_rational<N,D>  rat;

        const Y    m = Y(rat.denominator())/Y(rat.numerator());
        
        return boost::units::pow(x,m);
    }
};

/// specialize power typeof helper for complex<quantity<Unit,Y> >
template<class Y,class Unit,long N,long D> 
struct power_dimof_helper<complex<quantity<Unit,Y> >,static_rational<N,D> >                
{ 
    typedef typename power_dimof_helper<Y,static_rational<N,D> >::type     value_type;
    typedef typename power_dimof_helper<Unit,static_rational<N,D> >::type  unit_type;
    typedef quantity<unit_type,value_type>                                  quantity_type;
    typedef complex<quantity_type>                                          type; 
    
    static type value(const complex<quantity<Unit,Y> >& x)  
    { 
        const complex<value_type>   tmp = pow<static_rational<N,D> >(complex<Y>(x.real().value(),x.imag().value()));
        
        return type(quantity_type::from_value(tmp.real()),quantity_type::from_value(tmp.imag()));
    }
};

/// specialize root typeof helper for complex<quantity<Unit,Y> >
template<class Y,class Unit,long N,long D> 
struct root_typeof_helper<complex<quantity<Unit,Y> >,static_rational<N,D> >                
{ 
    typedef typename root_typeof_helper<Y,static_rational<N,D> >::type      value_type;
    typedef typename root_typeof_helper<Unit,static_rational<N,D> >::type   unit_type;
    typedef quantity<unit_type,value_type>                                  quantity_type;
    typedef complex<quantity_type>                                          type; 
    
    static type value(const complex<quantity<Unit,Y> >& x)  
    { 
        const complex<value_type>   tmp = root<static_rational<N,D> >(complex<Y>(x.real().value(),x.imag().value()));
        
        return type(quantity_type::from_value(tmp.real()),quantity_type::from_value(tmp.imag()));
    }
};

} // namespace units

} // namespace boost
//]

int main(void)
{
    using namespace boost::math;
    using namespace boost::units;
    using namespace boost::units::test;

    std::stringstream sstream1, sstream2;
    
    {
    //[unit_example_9_snippet_1
    typedef quantity<length,complex<double> >     length_dimension;
        
    length_dimension    L(complex<double>(2.0,1.0)*meters);
    //]
    
    sstream1  << "+L      = " << +L << std::endl
              << "-L      = " << -L << std::endl
              << "L+L     = " << L+L << std::endl
              << "L-L     = " << L-L << std::endl
              << "L*L     = " << L*L << std::endl
              << "L/L     = " << L/L << std::endl
              << "L^3     = " << pow<3>(L) << std::endl
              << "L^(3/2) = " << pow< static_rational<3,2> >(L) << std::endl
              << "3vL     = " << root<3>(L) << std::endl
              << "(3/2)vL = " << root< static_rational<3,2> >(L) << std::endl
              << std::endl;
    }
    
    {
    //[unit_example_9_snippet_2
    typedef complex<quantity<length> >     length_dimension;
        
    length_dimension    L(2.0*meters,1.0*meters);
    //]
    
    sstream1  << "+L      = " << +L << std::endl
              << "-L      = " << -L << std::endl
              << "L+L     = " << L+L << std::endl
              << "L-L     = " << L-L << std::endl
              << "L*L     = " << L*L << std::endl
              << "L/L     = " << L/L << std::endl
              << "L^3     = " << pow<3>(L) << std::endl
              << "L^(3/2) = " << pow< static_rational<3,2> >(L) << std::endl
              << "3vL     = " << root<3>(L) << std::endl
              << "(3/2)vL = " << root< static_rational<3,2> >(L) << std::endl
              << std::endl;
    }

    sstream2 << "+L      = 2 + 1 i m" << std::endl;
    sstream2 << "-L      = -2 + -1 i m" << std::endl;
    sstream2 << "L+L     = 4 + 2 i m" << std::endl;
    sstream2 << "L-L     = 0 + 0 i m" << std::endl;
    sstream2 << "L*L     = 3 + 4 i m^2" << std::endl;
    sstream2 << "L/L     = 1 + 0 i dimensionless" << std::endl;
    sstream2 << "L^3     = 2 + 11 i m^3" << std::endl;
    sstream2 << "L^(3/2) = 2.56713 + 2.14247 i m^(3/2)" << std::endl;
    sstream2 << "3vL     = 1.29207 + 0.201294 i m^(1/3)" << std::endl;
    sstream2 << "(3/2)vL = 1.62894 + 0.520175 i m^(2/3)" << std::endl;
    sstream2 << std::endl;
    sstream2 << "+L      = 2 m + 1 m i" << std::endl;
    sstream2 << "-L      = -2 m + -1 m i" << std::endl;
    sstream2 << "L+L     = 4 m + 2 m i" << std::endl;
    sstream2 << "L-L     = 0 m + 0 m i" << std::endl;
    sstream2 << "L*L     = 3 m^2 + 4 m^2 i" << std::endl;
    sstream2 << "L/L     = 1 dimensionless + 0 dimensionless i" << std::endl;
    sstream2 << "L^3     = 2 m^3 + 11 m^3 i" << std::endl;
    sstream2 << "L^(3/2) = 2.56713 m^(3/2) + 2.14247 m^(3/2) i" << std::endl;
    sstream2 << "3vL     = 1.29207 m^(1/3) + 0.201294 m^(1/3) i" << std::endl;
    sstream2 << "(3/2)vL = 1.62894 m^(2/3) + 0.520175 m^(2/3) i" << std::endl;
    sstream2 << std::endl;

    std::string str1(sstream1.str());
    std::string str2(sstream2.str());

    std::cout << str1;
    
    if(str1 == str2) 
    {
        return(0);
    } 
    else 
    {
        std::cout << std::endl << str2 << std::endl;
        
        if(str1.size() < str2.size()) 
        {
            std::string::iterator iter = std::mismatch(str1.begin(), str1.end(), str2.begin()).first;
            
            std::cout << iter - str1.begin() << std::endl;
            std::cout << std::count(str1.begin(), iter, '\n') << std::endl;
        } 
        else 
        {
            std::string::iterator iter = std::mismatch(str2.begin(), str2.end(), str1.begin()).first;
            
            std::cout << iter - str2.begin() << std::endl;
            std::cout << std::count(str2.begin(), iter, '\n') << std::endl;
        }
        
        return(-1);
    }
}
