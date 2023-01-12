/**
 * @file    types.hpp
 * @author  Lorenzo Liuzzo (lorenzoliuzzo@outlook.com)
 * @brief   
 * @date    2023-01-12
 * 
 * @copyright Copyright (c) 2023
 */


#pragma once


namespace measurements {

    
    namespace units {

        
        struct radians : public unit {


            constexpr radians() noexcept :

                unit() {}

            
            /**
             * @brief Output operator for a radians unit of measurement
             * 
             * @param os: std::ostream&
             * @param rad: radians unit of measurement as l-value const reference
             * 
             * @return std::ostream&
             *  
             */
            friend std::ostream& operator<<(std::ostream& os, const radians& rad) noexcept {

                os << "rad"; 

                return os; 

            }


            /**
             * @brief Output operator for a radians unit of measurement
             * 
             * @param os: std::ofstream&
             * @param rad: radians unit of measurement as l-value const reference
             * 
             * @return std::ofstream&
             *  
             */
            friend std::ofstream& operator<<(std::ofstream& os, const radians& rad) noexcept {

                os << "rad"; 

                return os; 

            }


            inline void print() const noexcept {

                std::cout << "rad";

            }


        }; // struct radians


        struct degrees : public unit {


            constexpr degrees() noexcept :

                unit() {}


            /**
             * @brief Output operator for a degrees unit of measurement
             * 
             * @param os: std::ostream&
             * @param deg: degrees unit of measurement as l-value const reference
             * 
             * @return std::ostream&
             *  
             */
            friend std::ostream& operator<<(std::ostream& os, const degrees& deg) noexcept {

                os << "°"; 

                return os; 

            }


            /**
             * @brief Output operator for a degrees unit of measurement
             * 
             * @param os: std::ofstream&
             * @param deg: degrees unit of measurement as l-value const reference
             * 
             * @return std::ofstream&
             *  
             */
            friend std::ofstream& operator<<(std::ofstream& os, const degrees& deg) noexcept {

                os << "°"; 

                return os; 

            }



            inline void print() const noexcept {

                std::cout << "°";

            }


        }; // struct degrees


        /// @brief Namespace containing the units of measurement
        namespace SI {


            /// @brief Namespace with the SI unit bases
            namespace basis {


                constexpr unit_base default_type(0, 0, 0, 0, 0, 0, 0);

                constexpr unit_base metre(1, 0, 0, 0, 0, 0, 0);
                
                constexpr unit_base second(0, 1, 0, 0, 0, 0, 0);
                
                constexpr unit_base kilogram(0, 0, 1, 0, 0, 0, 0);
                
                constexpr unit_base Ampere(0, 0, 0, 1, 0, 0, 0);
                
                constexpr unit_base Kelvin(0, 0, 0, 0, 1, 0, 0);
                
                constexpr unit_base mole(0, 0, 0, 0, 0, 1, 0);
                
                constexpr unit_base candela(0, 0, 0, 0, 0, 0, 1);
            

            } // namespace SI


            /// @brief Namespace containg the SI prefixes
            namespace prefixes {


                constexpr unit_prefix default_type(1, '\0');

                constexpr unit_prefix yocto(1e-24, 'y');
                
                constexpr unit_prefix zepto(1e-21, 'z');
                
                constexpr unit_prefix atto(1e-18, 'a');
                
                constexpr unit_prefix femto(1e-15, 'f');
                
                constexpr unit_prefix pico(1e-12, 'p');
                
                constexpr unit_prefix nano(1e-9, 'n');
                
                constexpr unit_prefix micro(1e-6, 'u');
                
                constexpr unit_prefix milli(1e-3, 'm');
                
                constexpr unit_prefix centi(1e-2, 'c');
                
                constexpr unit_prefix deci(1e-1, 'd');
                                
                constexpr unit_prefix hecto(1e2, 'h');
                
                constexpr unit_prefix kilo(1e3, 'k');
                
                constexpr unit_prefix mega(1e6, 'M');
                
                constexpr unit_prefix giga(1e9, 'G');
                
                constexpr unit_prefix tera(1e12, 'T');
                
                constexpr unit_prefix peta(1e15, 'P');
                
                constexpr unit_prefix exa(1e18, 'E');
                
                constexpr unit_prefix zetta(1e21, 'Z');
                
                constexpr unit_prefix yotta(1e24, 'Y');


            } // namespace prefix


            // unitless 
            constexpr unit unitless(prefixes::default_type, basis::default_type);

            // SI units
            constexpr unit m(prefixes::default_type, basis::metre);
            constexpr unit s(prefixes::default_type, basis::second);
            constexpr unit kg(prefixes::default_type, basis::kilogram);
            constexpr unit K(prefixes::default_type, basis::Kelvin);
            constexpr unit A(prefixes::default_type, basis::Ampere);
            constexpr unit mol(prefixes::default_type, basis::mole);
            constexpr unit cd(prefixes::default_type, basis::candela);

            // length units
            constexpr unit ym(prefixes::yocto, basis::metre);
            constexpr unit zm(prefixes::zepto, basis::metre);
            constexpr unit am(prefixes::atto, basis::metre);
            constexpr unit fm(prefixes::femto, basis::metre);
            constexpr unit pm(prefixes::pico, basis::metre);
            constexpr unit nm(prefixes::nano, basis::metre);
            constexpr unit um(prefixes::micro, basis::metre);
            constexpr unit mm(prefixes::milli, basis::metre);
            constexpr unit cm(prefixes::centi, basis::metre);
            constexpr unit dm(prefixes::deci, basis::metre);
            constexpr unit hm(prefixes::hecto, basis::metre);
            constexpr unit km(prefixes::kilo, basis::metre);
            constexpr unit Mm(prefixes::mega, basis::metre);
            constexpr unit Gm(prefixes::giga, basis::metre);
            constexpr unit Tm(prefixes::tera, basis::metre);
            constexpr unit Pm(prefixes::peta, basis::metre);
            constexpr unit Em(prefixes::exa, basis::metre);

            // time units
            constexpr unit ys(prefixes::yocto, basis::second);
            constexpr unit zs(prefixes::zepto, basis::second);
            constexpr unit as(prefixes::atto, basis::second);
            constexpr unit fs(prefixes::femto, basis::second);
            constexpr unit ps(prefixes::pico, basis::second);
            constexpr unit ns(prefixes::nano, basis::second);
            constexpr unit us(prefixes::micro, basis::second);
            constexpr unit ms(prefixes::milli, basis::second);
            constexpr unit cs(prefixes::centi, basis::second);
            constexpr unit ds(prefixes::deci, basis::second);
            constexpr unit hs(prefixes::hecto, basis::second);
            constexpr unit ks(prefixes::kilo, basis::second);
            constexpr unit Ms(prefixes::mega, basis::second);
            constexpr unit Gs(prefixes::giga, basis::second);
            constexpr unit Ts(prefixes::tera, basis::second);
            constexpr unit Ps(prefixes::peta, basis::second);
            constexpr unit Es(prefixes::exa, basis::second);


            // angle units
            constexpr radians rad;
            constexpr degrees deg;


            constexpr unit m_s(prefixes::default_type, basis::metre / basis::second); 
            constexpr unit km_s(prefixes::kilo, basis::metre / basis::second); 
            constexpr unit m_ss(prefixes::default_type, basis::metre / basis::second.square()); 


            // composed units
            constexpr unit hertz(unit_base(0, -1, 0, 0, 0, 0, 0));
            constexpr unit Hz = hertz;

            constexpr unit volt(unit_base(2, -3, 1, -1, 0, 0, 0));
            constexpr unit V = volt;

            constexpr unit newton(unit_base(1, -2, 1, 0, 0, 0, 0));
            constexpr unit N = newton;

            constexpr unit Pa(unit_base(-1, -2, 1, 0, 0, 0, 0));
            constexpr unit pascal = Pa;

            constexpr unit joule(unit_base(2, -2, 1, 0, 0, 0, 0));
            constexpr unit J = joule;

            constexpr unit watt(unit_base(2, -3, 1, 0, 0, 0, 0));
            constexpr unit W = watt;

            constexpr unit coulomb(unit_base(0, 1, 0, 1, 0, 0, 0));
            constexpr unit C = coulomb;

            constexpr unit farad(unit_base(-2, 4, -1, 2, 0, 0, 0));
            constexpr unit F = farad;

            constexpr unit weber(unit_base(2, -2, 1, -1, 0, 0, 0));
            constexpr unit Wb = weber;

            constexpr unit tesla(unit_base(0, -2, 1, -1, 0, 0, 0));
            constexpr unit T = tesla;

            constexpr unit henry(unit_base(2, -2, 1, -2, 0, 0, 0));                    
            constexpr unit H = henry;


        } // namespace SI


    } // namespace units
    
    
} // namespace measurements