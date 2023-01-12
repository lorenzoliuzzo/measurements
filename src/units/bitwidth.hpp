/**
 * @file    unit_bitwidth.hpp
 * @author  Lorenzo Liuzzo (lorenzoliuzzo@outlook.com)
 * @brief   Bit guidelines for encoding unit_base exponents
 * @date    2023-01-01
 * 
 * @copyright Copyright (c) 2023
 */


#pragma once


namespace measurements {


    namespace units {


        namespace bitwidth {


            constexpr uint32_t base_size{sizeof(uint32_t) == 8 ? 8 : 4};
                
            constexpr uint32_t metre{(base_size == 8) ? 8 : 4};
                
            constexpr uint32_t second{(base_size == 8) ? 8 : 4};
                
            constexpr uint32_t kilogram{(base_size == 8) ? 6 : 3};
                
            constexpr uint32_t ampere{(base_size == 8) ? 6 : 3};
                
            constexpr uint32_t candela{(base_size == 8) ? 4 : 2};
                
            constexpr uint32_t kelvin{(base_size == 8) ? 6 : 3};
                
            constexpr uint32_t mole{(base_size == 8) ? 4 : 2};


        } // namespace bitwidth


    } // namespace units


} // namespace measurements