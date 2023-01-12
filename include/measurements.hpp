/**
 * @file    measurements.hpp
 * @author  Lorenzo Liuzzo (lorenzoliuzzo@outlook.com)
 * @brief   This file contains all the headers of the measurements library
 * @date    2023-01-12
 * 
 * @copyright Copyright (c) 2023
 */


#define SCIPP_MEASUREMENTS_HPP

    
    using scalar = double;


    #include <cmath>
    #include <cstdint>
    #include <fstream>
    #include <iomanip>
    #include <iostream>
    #include <stdexcept>


    #include "../src/units/bitwidth.hpp"
    #include "../src/units/base.hpp"
    #include "../src/units/prefix.hpp"
    #include "../src/units/unit.hpp"
    #include "../src/units/types.hpp"
        
    #include "../src/measurement.hpp"
    #include "../src/measurement_types.hpp"
    #include "../src/umeasurement.hpp"
    #include "../src/umeasurement_types.hpp"