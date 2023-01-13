/**
 * @file    measurements_types.hpp
 * @author  Lorenzo Liuzzo (lorenzoliuzzo@outlook.com)
 * @brief   This file contains the definition and implementation of the measurement class,
 *          with all its methods, operators and possibly operations.
 * @date    2022-12-12
 * 
 * @copyright Copyright (c) 2023
 */


#pragma once


namespace measurements {


    struct length_measurement : public measurement {


        /**
         * @brief Construct a new default length_measurement object 
         * 
         * @note the value is set to 0.0
         * @note the unit is set to metre
         */
        explicit constexpr length_measurement() noexcept : 

            measurement(0.0, m) {}


        /**
         * @brief Construct a new length_measurement object from a value and an unit of length
         * 
         * @param value: scalar value of the measurement as l-value const reference
         * @param length_units: unit of length as l-value const reference
         *
         * @note If the unit is not specified, the unit is set to metre
         */
        explicit constexpr length_measurement(const scalar& value, 
                                              const unit& length_units = m) {

            if (length_units.base_ != basis::metre) 
                throw std::invalid_argument("Cannot convert from " + length_units.base_.to_string() + " to metre in initialization of length_measurement");

            else {

                this->value_ = value;
                this->units_ = length_units;

            }
            
        }


        /**
         * @brief Copy constuct a new length_measurement object from another measurement
         * 
         * @param other: measurement to copy from as l-value const reference
         */
        constexpr length_measurement(const measurement& other) {

            if (other.units_.base_ != basis::metre) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to metre in initialization of length_measurement");

            else {

                this->value_ = other.value_;
                this->units_ = other.units_;

            }

        }
            
        
        /**
         * @brief Move construct a new length_measurement object from another measurement
         * 
         * @param other: measurement to move from as r-value reference
         */
        constexpr length_measurement(measurement&& other)  {

            if (other.units_.base_ != basis::metre) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to metre in initialization of length_measurement");

            else {

                this->value_ = other.value_;
                this->units_ = other.units_;

            }

        }
            
            
    }; // struct length_measurement


    struct time_measurement : public measurement {


        /**
         * @brief Construct a new default time_measurement object 
         * 
         * @note the value is set to 0.0
         * @note the unit is set to second
         */
        explicit constexpr time_measurement() noexcept : 

            measurement(0.0, s) {}


        /**
         * @brief Construct a new time_measurement object from a value and an unit of length
         * 
         * @param value: scalar value of the measurement as l-value const reference
         * @param length_units: unit of length as l-value const reference
         *
         * @note If the unit is not specified, the unit is set to second
         */
        constexpr time_measurement(const scalar& value, 
                                   const unit& length_units = s) {

            if (value < 0.0)
                throw std::invalid_argument("Cannot initialize a time_measurement with a negative value");

            else if (length_units.base_ != basis::second) 
                throw std::invalid_argument("Cannot convert from " + length_units.base_.to_string() + " to second in initialization of time_measurement");

            else {

                this->value_ = value;
                this->units_ = length_units;

            }
            
        }


        /**
         * @brief Copy constuct a new time_measurement object from another measurement
         * 
         * @param other: measurement to copy from as l-value const reference
         */
        constexpr time_measurement(const measurement& other) {

            if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a time_measurement with a negative value");

            else if (other.units_.base_ != basis::second) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to second in initialization of time_measurement");

            else {

                this->value_ = other.value_;
                this->units_ = other.units_;

            }

        }
            
        
        /**
         * @brief Move construct a new time_measurement object from another measurement
         * 
         * @param other: measurement to move from as r-value reference
         */
        constexpr time_measurement(measurement&& other)  {

            if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a time_measurement with a negative value");

            else if (other.units_.base_ != basis::second) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to second in initialization of time_measurement");

            else {

                this->value_ = other.value_;
                this->units_ = other.units_;

            }

        }
            
            
    }; // struct time_measurement

    
    struct speed_measurement : public measurement {


        /**
         * @brief Construct a new default speed_measurement object 
         * 
         * @note the value is set to 0.0
         * @note the unit is set to metre / second
         */
        explicit constexpr speed_measurement() noexcept : 

            measurement(0.0, m_s) {}


        /**
         * @brief Construct a new speed_measurement object from a value and an unit of length
         * 
         * @param value: scalar value of the measurement as l-value const reference
         * @param length_units: unit of length as l-value const reference
         *
         * @note If the unit is not specified, the unit is set to metre / second
         */
        explicit constexpr speed_measurement(const scalar& value, 
                                             const unit& length_units = m_s) {

            if (length_units.base_ != basis::metre / basis::second) 
                throw std::invalid_argument("Cannot convert from " + length_units.base_.to_string() + " to metre / second in initialization of speed_measurement");

            else {

                this->value_ = value;
                this->units_ = length_units;

            }
            
        }


        /**
         * @brief Copy constuct a new speed_measurement object from another measurement
         * 
         * @param other: measurement to copy from as l-value const reference
         */
        constexpr speed_measurement(const measurement& other) {

            if (other.units_.base_ != basis::metre / basis::second) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to metre / second in initialization of speed_measurement");

            else {

                this->value_ = other.value_;
                this->units_ = other.units_;

            }

        }
            
        
        /**
         * @brief Move construct a new speed_measurement object from another measurement
         * 
         * @param other: measurement to move from as r-value reference
         */
        constexpr speed_measurement(measurement&& other)  {

            if (other.units_.base_ != basis::metre / basis::second) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to metre / second in initialization of speed_measurement");

            else {

                this->value_ = other.value_;
                this->units_ = other.units_;

            }

        }
            
            
    }; // struct speed_measurement


    struct acceleration_measurement : public measurement {


        /**
         * @brief Construct a new default acceleration_measurement object 
         * 
         * @note the value is set to 0.0
         * @note the unit is set to metre / second^2
         */
        explicit constexpr acceleration_measurement() noexcept : 

            measurement(0.0, m_ss) {}


        /**
         * @brief Construct a new acceleration_measurement object from a value and an unit of length
         * 
         * @param value: scalar value of the measurement as l-value const reference
         * @param length_units: unit of length as l-value const reference
         *
         * @note If the unit is not specified, the unit is set to metre / second^2
         */
        explicit constexpr acceleration_measurement(const scalar& value, 
                                                    const unit& length_units = m_ss) {

            if (length_units.base_ != basis::metre / basis::second.square()) 
                throw std::invalid_argument("Cannot convert from " + length_units.base_.to_string() + " to metre / second^2 in initialization of acceleration_measurement");

            else {

                this->value_ = value;
                this->units_ = length_units;

            }
            
        }


        /**
         * @brief Copy constuct a new acceleration_measurement object from another measurement
         * 
         * @param other: measurement to copy from as l-value const reference
         */
        constexpr acceleration_measurement(const measurement& other) {

            if (other.units_.base_ != basis::metre / basis::second.square()) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to metre / second^2 in initialization of acceleration_measurement");

            else {

                this->value_ = other.value_;
                this->units_ = other.units_;

            }

        }
            
        
        /**
         * @brief Move construct a new acceleration_measurement object from another measurement
         * 
         * @param other: measurement to move from as r-value reference
         */
        constexpr acceleration_measurement(measurement&& other)  {

            if (other.units_.base_ != basis::metre / basis::second.square()) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to metre / second^2 in initialization of acceleration_measurement");

            else {

                this->value_ = other.value_;
                this->units_ = other.units_;

            }

        }
            
            
    }; // struct acceleration_measurement


    struct mass_measurement : public measurement {


        /**
         * @brief Construct a new default mass_measurement object 
         * 
         * @note the value is set to 0.0
         * @note the unit is set to kilogram
         */
        explicit constexpr mass_measurement() noexcept : 

            measurement(0.0, kg) {}


        /**
         * @brief Construct a new mass_measurement object from a value and an unit of length
         * 
         * @param value: scalar value of the measurement as l-value const reference
         * @param length_units: unit of length as l-value const reference
         *
         * @note If the unit is not specified, the unit is set to kilogram
         */
        explicit constexpr mass_measurement(const scalar& value, 
                                            const unit& length_units = kg) {

            if (value < 0.0)
                throw std::invalid_argument("Cannot initialize a mass_measurement with a negative value");

            else if (length_units.base_ != basis::kilogram) 
                throw std::invalid_argument("Cannot convert from " + length_units.base_.to_string() + " to kilogram in initialization of mass_measurement");

            else {

                this->value_ = value_;
                this->units_ = length_units;

            }
            
        }


        /**
         * @brief Copy constuct a new mass_measurement object from another measurement
         * 
         * @param other: measurement to copy from as l-value const reference
         */
        constexpr mass_measurement(const measurement& other) {

            if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a mass_measurement with a negative value");

            else if (other.units_.base_ != basis::kilogram) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to kilogram in initialization of mass_measurement");

            else {

                this->value_ = other.value_;
                this->units_ = other.units_;

            }

        }
            
        
        /**
         * @brief Move construct a new mass_measurement object from another measurement
         * 
         * @param other: measurement to move from as r-value reference
         */
        constexpr mass_measurement(measurement&& other)  {

            if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a mass_measurement with a negative value");

            else if (other.units_.base_ != basis::kilogram) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to kilogram in initialization of mass_measurement");

            else {

                this->value_ = other.value_;
                this->units_ = other.units_;

            }

        }
            
            
    }; // struct mass_measurement


    struct force_measurement : public measurement {


        /**
         * @brief Construct a new default force_measurement object 
         * 
         * @note the value is set to 0.0
         * @note the unit is set to Newton
         */
        explicit constexpr force_measurement() noexcept : 

            measurement(0.0, N) {}


        /**
         * @brief Construct a new force_measurement object from a value and an unit of length
         * 
         * @param value: scalar value of the measurement as l-value const reference
         * @param force_units: unit of length as l-value const reference
         *
         * @note If the unit is not specified, the unit is set to Newton
         */
        explicit constexpr force_measurement(const scalar& value, 
                                             const unit& force_units = N) {

            if (force_units.base_ != basis::kilogram * basis::metre / basis::second.square()) 
                throw std::invalid_argument("Cannot convert from " + force_units.base_.to_string() + " to Newton in initialization of force_measurement");

            else {

                this->value_ = value;
                this->units_ = force_units;

            }
            
        }


        /**
         * @brief Copy constuct a new force_measurement object from another measurement
         * 
         * @param other: measurement to copy from as l-value const reference
         */
        constexpr force_measurement(const measurement& other) {

            if (other.units_.base_ != basis::kilogram * basis::metre / basis::second.square()) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to Newton in initialization of force_measurement");

            else {

                this->value_ = other.value_;
                this->units_ = other.units_;

            }

        }
            
        
        /**
         * @brief Move construct a new force_measurement object from another measurement
         * 
         * @param other: measurement to move from as r-value reference
         */
        constexpr force_measurement(measurement&& other)  {

            if (other.units_.base_ != basis::kilogram * basis::metre / basis::second.square()) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to Newton in initialization of force_measurement");

            else {

                this->value_ = other.value_;
                this->units_ = other.units_;

            }

        }
            
            
    }; // struct force_measurement


    struct energy_measurement : public measurement {}; // struct energy_measurement


    struct angle_measurement : public measurement {


        /**
         * @brief Construct a new default angle_measurement object 
         * 
         * @note the value is set to 0.0
         * @note the unit is set to radians
         */
        constexpr angle_measurement() noexcept : 

            measurement(0.0, rad) {}


        /**
         * @brief Construct a new angle_measurement object from a value and an unit of length
         * 
         * @param value: scalar value of the measurement as l-value const reference
         * @param angle_units: unit of length as l-value const reference
         *
         * @note If the unit is not specified, the unit is set to radians
         */
        explicit constexpr angle_measurement(const scalar& value, 
                                             const unit& angle_units = rad) {

            if (angle_units != unitless)
                throw std::invalid_argument("Cannot convert from " + angle_units.base_.to_string() + " to radians in initialization of angle_measurement");

            else {

                this->value_ = value;
                this->units_ = angle_units;

            }
            
        }


        /**
         * @brief Copy constuct a new angle_measurement object from another measurement
         * 
         * @param other: measurement to copy from as l-value const reference
         */
        constexpr angle_measurement(const measurement& other) {

            if (other.units_ != unitless)
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to radians in initialization of angle_measurement");

            else {

                this->value_ = other.value_;
                this->units_ = other.units_;

            }

        }
            
        
        /**
         * @brief Move construct a new angle_measurement object from another measurement
         * 
         * @param other: measurement to move from as r-value reference
         */
        constexpr angle_measurement(measurement&& other)  {

            if (other.units_ != unitless)
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to radians in initialization of angle_measurement");

            else {

                this->value_ = other.value_;
                this->units_ = other.units_;

            }

        }


        /**
        * @brief Convert the angle_measurement to another units
        *
        * @param desired_units: desired unit of angle_measurement 
        * 
        * @return constexpr angle_measurement 
        */
        constexpr angle_measurement convert_to(const unit& desired_units) const { 
            
            if (desired_units == degrees())

                return measurement(this->value_ * 180. / M_PI, desired_units); 

            else if (desired_units == radians())

                return measurement(this->value_ * M_PI / 180., desired_units);

            else 

                throw std::invalid_argument("Cannot convert from " + this->units_.base_.to_string() + " to " + desired_units.base_.to_string() + " in angle_measurement::convert_to()");
        
        }

            
    }; // struct angle_measurement

        

} // namespace measurements