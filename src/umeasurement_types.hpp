/**
 * @file    umeasurements_types.hpp
 * @author  Lorenzo Liuzzo (lorenzoliuzzo@outlook.com)
 * @brief   This file contains the definition and implementation of the measurement class,
 *          with all its methods, operators and possibly operations.
 * @date    2022-12-31
 *
 * @copyright Copyright (c) 2023
 */


#pragma once


namespace measurements {


    struct mass_umeasurement : public umeasurement {


        /**
         * @brief Construct a new default mass_umeasurement object 
         * 
         * @note The value and the uncertainty are set to 0.0
         * @note The unit is set to kilogram
         */
        explicit constexpr mass_umeasurement() noexcept : 

            umeasurement(0.0, 0.0, kg) {}


        /**
         * @brief Construct a new mass_umeasurement object from a value, an uncertainty and an unit of mass
         * 
         * @param value: scalar value as l-value const reference
         * @param uncertainty: scalar uncertainty as l-value const reference
         * @param mass_units: unit of mass as l-value const reference
         *
         * @note The value of the mass must be positive
         * @note The uncertainty of the mass must be positive
         * @note If the unit is not specified, the unit is set to kilogram
         */
        constexpr mass_umeasurement(const scalar& value,
                                    const scalar& uncertainty,
                                    const unit& mass_units = kg) { 

            if (mass_units.base_ != basis::kilogram) 
                throw std::invalid_argument("Cannot convert from " + mass_units.base_.to_string() + " to kilogram in initialization of mass_umeasurement");

            else if (uncertainty < 0.0)
                throw std::invalid_argument("Cannot initialize a mass_umeasurement with a negative uncertainty");

            else if (value < 0.0)
                throw std::invalid_argument("Cannot initialize a mass_umeasurement with a negative value");

            else {

                this->value_ = value;
                this->uncertainty_ = uncertainty;
                this->units_ = mass_units;

            }
            
        }


        /**
         * @brief Copy constuct a new mass_umeasurement object from an umeasurement
         * 
         * @param other: umeasurement to copy from as l-value const reference
         * 
         * @note The value of the mass must be positive
         * @note The units of the mass must have an unit_base of kilogram
         */
        constexpr mass_umeasurement(const umeasurement& other) {

            if (other.units_.base_ != basis::kilogram) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to kilogram in initialization of mass_umeasurement");

            else if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a mass_umeasurement with a negative value");

            else {

                this->value_ = other.value_;
                this->uncertainty_ = other.uncertainty_;
                this->units_ = other.units_;

            }

        }
            
        
        /**
         * @brief Move construct a new mass_umeasurement object from an umeasurement
         * 
         * @param other: umeasurement to move from as r-value reference
         * 
         * @note The value of the mass must be positive
         * @note The units of the mass must have an unit_base of kilogram
         */
        constexpr mass_umeasurement(umeasurement&& other) {

            if (other.units_.base_ != basis::kilogram) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to kilogram in initialization of mass_umeasurement");

            else if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a mass_umeasurement with a negative value");

            else {

                this->value_ = std::move(other.value_);
                this->uncertainty_ = std::move(other.uncertainty_);
                this->units_ = std::move(other.units_);

            }

        }


        /**
         * @brief Copy construct a new mass_umeasurement object from another mass_measurement
         * 
         * @param other: mass_measurement to copy from as l-value const reference
         */
        constexpr mass_umeasurement(const mass_umeasurement& other) noexcept : 

            umeasurement(other) {}


        /**
         * @brief Move construct a new mass_umeasurement object from another mass_measurement
         * 
         * @param other: mass_measurement to move from as r-value reference
         */
        constexpr mass_umeasurement(mass_umeasurement&& other) noexcept : 

            umeasurement(other) {}


        /**
         * @brief Copy assign a new mass_umeasurement object from an umeasurement
         * 
         * @param other: umeasurement to copy from as l-value const reference
         */
        constexpr mass_umeasurement& operator=(const umeasurement& other) {

            if (other.units_.base_ != basis::kilogram) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to rad in initialization of mass_umeasurement");

            else if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a mass_umeasurement with a negative value");

            else {

                this->value_ = other.value_;
                this->uncertainty_ = other.uncertainty_;
                this->units_ = other.units_;
                
            }

            return *this;
        
        }


        /**
         * @brief Move assign a new mass_umeasurement object from an umeasurement
         * 
         * @param other: umeasurement to copy from as r-value reference
         */
        constexpr mass_umeasurement& operator=(umeasurement&& other) {

            if (other.units_.base_ != basis::kilogram) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to rad in initialization of mass_umeasurement");

            else if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a mass_umeasurement with a negative value");

            else {

                this->value_ = std::move(other.value_);
                this->uncertainty_ = std::move(other.uncertainty_);
                this->units_ = std::move(other.units_);
                
            }

            return *this;
        
        }


        /**
         * @brief Copy assign a new mass_umeasurement object from another mass_umeasurement
         * 
         * @param other: mass_umeasurement to copy from as l-value const reference
         */
        constexpr mass_umeasurement& operator=(const mass_umeasurement& other) noexcept {

            this->value_ = other.value_;
            this->uncertainty_ = other.uncertainty_;
            this->units_ = other.units_;

            return *this;
        
        }


        /**
         * @brief Move assign a new mass_umeasurement object from another mass_umeasurement
         * 
         * @param other: mass_umeasurement to copy from as r-value reference
         */
        constexpr mass_umeasurement& operator=(mass_umeasurement&& other) noexcept {

            this->value_ = std::move(other.value_);
            this->uncertainty_ = std::move(other.uncertainty_);
            this->units_ = std::move(other.units_);

            return *this;
        
        }


    }; // struct mass_umeasurement


    struct length_umeasurement : public umeasurement {


        /**
         * @brief Construct a new default length_umeasurement object 
         * 
         * @note The value and the uncertainty are set to 0.0
         * @note The unit is set to metre
         */
        explicit constexpr length_umeasurement() noexcept : 

            umeasurement(0.0, 0.0, m) {}


        /**
         * @brief Construct a new length_umeasurement object from a value, an uncertainty and an unit of length
         * 
         * @param value: scalar value as l-value const reference
         * @param uncertainty: scalar uncertainty as l-value const reference
         * @param length_units: unit of length as l-value const reference
         *
         * @note The value of the length must be positive
         * @note The uncertainty of the length must be positive
         * @note If the unit is not specified, the unit is set to metre
         */
        constexpr length_umeasurement(const scalar& value,
                                      const scalar& uncertainty,
                                      const unit& length_units = m) { 

            if (length_units.base_ != basis::metre) 
                throw std::invalid_argument("Cannot convert from " + length_units.base_.to_string() + " to metre in initialization of length_umeasurement");

            else if (uncertainty < 0.0)
                throw std::invalid_argument("Cannot initialize a length_umeasurement with a negative uncertainty");

            else if (value < 0.0)
                throw std::invalid_argument("Cannot initialize a length_umeasurement with a negative value");

            else {

                this->value_ = value;
                this->uncertainty_ = uncertainty;
                this->units_ = length_units;

            }
            
        }


        /**
         * @brief Copy constuct a new length_umeasurement object from an umeasurement
         * 
         * @param other: umeasurement to copy from as l-value const reference
         * 
         * @note The value of the length must be positive
         * @note The units of the length must have an unit_base of metre
         */
        constexpr length_umeasurement(const umeasurement& other) {

            if (other.units_.base_ != basis::metre) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to metre in initialization of length_umeasurement");

            else if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a length_umeasurement with a negative value");

            else {

                this->value_ = other.value_;
                this->uncertainty_ = other.uncertainty_;
                this->units_ = other.units_;

            }

        }
            
        
        /**
         * @brief Move construct a new length_umeasurement object from an umeasurement
         * 
         * @param other: umeasurement to move from as r-value reference
         * 
         * @note The value of the length must be positive
         * @note The units of the length must have an unit_base of metre
         */
        constexpr length_umeasurement(umeasurement&& other) {

            if (other.units_.base_ != basis::metre) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to metre in initialization of length_umeasurement");

            else if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a length_umeasurement with a negative value");

            else {

                this->value_ = std::move(other.value_);
                this->uncertainty_ = std::move(other.uncertainty_);
                this->units_ = std::move(other.units_);

            }

        }


        /**
         * @brief Copy construct a new length_umeasurement object from another length_measurement
         * 
         * @param other: length_measurement to copy from as l-value const reference
         */
        constexpr length_umeasurement(const length_umeasurement& other) noexcept : 

            umeasurement(other) {}


        /**
         * @brief Move construct a new length_umeasurement object from another length_measurement
         * 
         * @param other: length_measurement to move from as r-value reference
         */
        constexpr length_umeasurement(length_umeasurement&& other) noexcept : 

            umeasurement(other) {}


        /**
         * @brief Copy assign a new length_umeasurement object from an umeasurement
         * 
         * @param other: umeasurement to copy from as l-value const reference
         */
        constexpr length_umeasurement& operator=(const umeasurement& other) {

            if (other.units_.base_ != basis::metre) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to rad in initialization of length_umeasurement");

            else if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a length_umeasurement with a negative value");

            else {

                this->value_ = other.value_;
                this->uncertainty_ = other.uncertainty_;
                this->units_ = other.units_;
                
            }

            return *this;
        
        }


        /**
         * @brief Move assign a new length_umeasurement object from an umeasurement
         * 
         * @param other: umeasurement to copy from as r-value reference
         */
        constexpr length_umeasurement& operator=(umeasurement&& other) {

            if (other.units_.base_ != basis::metre) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to rad in initialization of length_umeasurement");

            else if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a length_umeasurement with a negative value");

            else {

                this->value_ = std::move(other.value_);
                this->uncertainty_ = std::move(other.uncertainty_);
                this->units_ = std::move(other.units_);
                
            }

            return *this;
        
        }


        /**
         * @brief Copy assign a new length_umeasurement object from another length_umeasurement
         * 
         * @param other: length_umeasurement to copy from as l-value const reference
         */
        constexpr length_umeasurement& operator=(const length_umeasurement& other) noexcept {

            this->value_ = other.value_;
            this->uncertainty_ = other.uncertainty_;
            this->units_ = other.units_;

            return *this;
        
        }


        /**
         * @brief Move assign a new length_umeasurement object from another length_umeasurement
         * 
         * @param other: length_umeasurement to copy from as r-value reference
         */
        constexpr length_umeasurement& operator=(length_umeasurement&& other) noexcept {

            this->value_ = std::move(other.value_);
            this->uncertainty_ = std::move(other.uncertainty_);
            this->units_ = std::move(other.units_);

            return *this;
        
        }


    }; // struct length_umeasurement


    struct time_umeasurement : public umeasurement {


        /**
         * @brief Construct a new default time_umeasurement object 
         * 
         * @note The value and the uncertainty are set to 0.0
         * @note The unit is set to second
         */
        explicit constexpr time_umeasurement() noexcept : 

            umeasurement(0.0, 0.0, s) {}


        /**
         * @brief Construct a new time_umeasurement object from a value, an uncertainty and an unit of time
         * 
         * @param value: scalar value as l-value const reference
         * @param uncertainty: scalar uncertainty as l-value const reference
         * @param time_units: unit of time as l-value const reference
         *
         * @note The value of the time must be positive
         * @note The uncertainty of the time must be positive
         * @note If the unit is not specified, the unit is set to second
         */
        constexpr time_umeasurement(const scalar& value,
                                    const scalar& uncertainty,
                                    const unit& time_units = s) { 

            if (time_units.base_ != basis::second) 
                throw std::invalid_argument("Cannot convert from " + time_units.base_.to_string() + " to second in initialization of time_umeasurement");

            else if (uncertainty < 0.0)
                throw std::invalid_argument("Cannot initialize a time_umeasurement with a negative uncertainty");

            else if (value < 0.0)
                throw std::invalid_argument("Cannot initialize a time_umeasurement with a negative value");

            else {

                this->value_ = value;
                this->uncertainty_ = uncertainty;
                this->units_ = time_units;

            }
            
        }


        /**
         * @brief Copy constuct a new time_umeasurement object from an umeasurement
         * 
         * @param other: umeasurement to copy from as l-value const reference
         * 
         * @note The value of the time must be positive
         * @note The units of the time must have an unit_base of second
         */
        constexpr time_umeasurement(const umeasurement& other) {

            if (other.units_.base_ != basis::second) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to second in initialization of time_umeasurement");

            else if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a time_umeasurement with a negative value");

            else {

                this->value_ = other.value_;
                this->uncertainty_ = other.uncertainty_;
                this->units_ = other.units_;

            }

        }
            
        
        /**
         * @brief Move construct a new time_umeasurement object from an umeasurement
         * 
         * @param other: umeasurement to move from as r-value reference
         * 
         * @note The value of the time must be positive
         * @note The units of the time must have an unit_base of second
         */
        constexpr time_umeasurement(umeasurement&& other) {

            if (other.units_.base_ != basis::second) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to second in initialization of time_umeasurement");

            else if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a time_umeasurement with a negative value");

            else {

                this->value_ = std::move(other.value_);
                this->uncertainty_ = std::move(other.uncertainty_);
                this->units_ = std::move(other.units_);

            }

        }


        /**
         * @brief Copy construct a new time_umeasurement object from another time_measurement
         * 
         * @param other: time_measurement to copy from as l-value const reference
         */
        constexpr time_umeasurement(const time_umeasurement& other) noexcept : 

            umeasurement(other) {}


        /**
         * @brief Move construct a new time_umeasurement object from another time_measurement
         * 
         * @param other: time_measurement to move from as r-value reference
         */
        constexpr time_umeasurement(time_umeasurement&& other) noexcept : 

            umeasurement(other) {}


        /**
         * @brief Copy assign a new time_umeasurement object from an umeasurement
         * 
         * @param other: umeasurement to copy from as l-value const reference
         */
        constexpr time_umeasurement& operator=(const umeasurement& other) {

            if (other.units_.base_ != basis::second) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to rad in initialization of time_umeasurement");

            else if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a time_umeasurement with a negative value");

            else {

                this->value_ = other.value_;
                this->uncertainty_ = other.uncertainty_;
                this->units_ = other.units_;
                
            }

            return *this;
        
        }


        /**
         * @brief Move assign a new time_umeasurement object from an umeasurement
         * 
         * @param other: umeasurement to copy from as r-value reference
         */
        constexpr time_umeasurement& operator=(umeasurement&& other) {

            if (other.units_.base_ != basis::second) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to rad in initialization of time_umeasurement");

            else if (other.value_ < 0.0)
                throw std::invalid_argument("Cannot initialize a time_umeasurement with a negative value");

            else {

                this->value_ = std::move(other.value_);
                this->uncertainty_ = std::move(other.uncertainty_);
                this->units_ = std::move(other.units_);
                
            }

            return *this;
        
        }


        /**
         * @brief Copy assign a new time_umeasurement object from another time_umeasurement
         * 
         * @param other: time_umeasurement to copy from as l-value const reference
         */
        constexpr time_umeasurement& operator=(const time_umeasurement& other) noexcept {

            this->value_ = other.value_;
            this->uncertainty_ = other.uncertainty_;
            this->units_ = other.units_;

            return *this;
        
        }


        /**
         * @brief Move assign a new time_umeasurement object from another time_umeasurement
         * 
         * @param other: time_umeasurement to copy from as r-value reference
         */
        constexpr time_umeasurement& operator=(time_umeasurement&& other) noexcept {

            this->value_ = std::move(other.value_);
            this->uncertainty_ = std::move(other.uncertainty_);
            this->units_ = std::move(other.units_);

            return *this;
        
        }

                    
    }; // struct time_umeasurement


    struct speed_umeasurement : public umeasurement {


        /**
         * @brief Construct a new default speed_umeasurement object 
         * 
         * @note The value is set to 0.0
         * @note The uncertainty is set to 0.0
         * @note The unit is set to rad
         */
        explicit constexpr speed_umeasurement() noexcept : 

            umeasurement(0.0, 0.0, m / s) {}


        /**
         * @brief Construct a new speed_umeasurement object from a value and an unit of speed
         * 
         * @param value: scalar value as l-value const reference
         * @param uncertainty: scalar uncertainty as l-value const reference
         * @param speed_units: unit of speed as l-value const reference
         *
         * @note If the unit is not specified, the unit is set to metre / second
         */
        constexpr speed_umeasurement(const scalar& value, 
                                     const scalar& uncertainty = 0.0,
                                     const unit& speed_units = m / s) {

            if (speed_units.base_ != basis::metre / basis::second) 
                throw std::invalid_argument("Cannot convert from " + speed_units.base_.to_string() + " to metre / second in initialization of speed_umeasurement");

            else if (uncertainty < 0.0)
                throw std::invalid_argument("Cannot initialize a speed_umeasurement with a negative uncertainty");

            else {

                this->value_ = value;
                this->uncertainty_ = uncertainty;
                this->units_ = speed_units;            
            
            }
            
        }


        /**
         * @brief Copy constuct a new speed_umeasurement object from another umeasurement
         * 
         * @param other: umeasurement to copy from as l-value const reference
         */
        constexpr speed_umeasurement(const umeasurement& other) {


            if (other.units_.base_ != basis::metre / basis::second) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to metre / second in initialization of speed_umeasurement");

            else {

                this->value_ = other.value_;
                this->uncertainty_ = other.uncertainty_;
                this->units_ = other.units_;
                
            }

        }
            
        
        /**
         * @brief Move construct a new speed_umeasurement object from another umeasurement
         * 
         * @param other: umeasurement to move from as r-value reference
         */
        constexpr speed_umeasurement(umeasurement&& other)  {

            if (other.units_.base_ != basis::metre / basis::second) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to metre / second in initialization of speed_umeasurement");

            else {

                this->value_ = std::move(other.value_);
                this->uncertainty_ = std::move(other.uncertainty_);
                this->units_ = std::move(other.units_);

            }

        }


        /**
         * @brief Copy construct a new speed_umeasurement object from another speed_measurement
         * 
         * @param other: speed_measurement to copy from as l-value const reference
         */
        constexpr speed_umeasurement(const speed_umeasurement& other) noexcept : 

            umeasurement(other) {}


        /**
         * @brief Move construct a new speed_umeasurement object from another speed_measurement
         * 
         * @param other: speed_measurement to move from as r-value reference
         */
        constexpr speed_umeasurement(speed_umeasurement&& other) noexcept : 

            umeasurement(other) {}

                        
    }; // struct speed_umeasurement


    struct acceleration_umeasurement : public umeasurement {


        /**
         * @brief Construct a new default acceleration_umeasurement object 
         * 
         * @note the value is set to 0.0
         * @note the uncertainty is set to 0.0
         * @note the unit is set to metre / second^2
         */
        explicit constexpr acceleration_umeasurement() noexcept : 

            umeasurement(0.0, 0.0, m / s.square()) {}


        /**
         * @brief Construct a new acceleration_umeasurement object from a value and an unit of acceleration
         * 
         * @param value: scalar value as l-value const reference
         * @param uncertainty: scalar uncertainty as l-value const reference
         * @param acceleration_units: unit of acceleration as l-value const reference
         *
         * @note If the unit is not specified, the unit is set to metre / second^2
         */
        constexpr acceleration_umeasurement(const scalar& value, 
                                            const scalar& uncertainty = 0.0,
                                            const unit& acceleration_units = m / s.square()) {

            if (acceleration_units.base_ != basis::metre / basis::second.square()) 
                throw std::invalid_argument("Cannot convert from " + acceleration_units.base_.to_string() + " to metre / second^2 in initialization of acceleration_umeasurement");

            else if (uncertainty < 0.0)
                throw std::invalid_argument("Cannot initialize a acceleration_umeasurement with a negative uncertainty");

            else {

                this->value_ = value;
                this->uncertainty_ = uncertainty;
                this->units_ = acceleration_units;            
            
            }
            
        }


        /**
         * @brief Copy constuct a new acceleration_umeasurement object from another umeasurement
         * 
         * @param other: umeasurement to copy from as l-value const reference
         */
        constexpr acceleration_umeasurement(const umeasurement& other) {


            if (other.units_.base_ != basis::metre / basis::second.square()) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to metre / second^2 in initialization of acceleration_umeasurement");

            else {

                this->value_ = other.value_;
                this->uncertainty_ = other.uncertainty_;
                this->units_ = other.units_;
                
            }

        }
            
        
        /**
         * @brief Move construct a new acceleration_umeasurement object from another umeasurement
         * 
         * @param other: umeasurement to move from as r-value reference
         */
        constexpr acceleration_umeasurement(umeasurement&& other)  {

            if (other.units_.base_ != basis::metre / basis::second.square()) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to metre / second^2 in initialization of acceleration_umeasurement");

            else {

                this->value_ = std::move(other.value_);
                this->uncertainty_ = std::move(other.uncertainty_);
                this->units_ = std::move(other.units_);

            }

        }


        /**
         * @brief Copy construct a new acceleration_umeasurement object from another acceleration_measurement
         * 
         * @param other: acceleration_measurement to copy from as l-value const reference
         */
        constexpr acceleration_umeasurement(const acceleration_umeasurement& other) noexcept : 

            umeasurement(other) {}


        /**
         * @brief Move construct a new acceleration_umeasurement object from another acceleration_measurement
         * 
         * @param other: acceleration_measurement to move from as r-value reference
         */
        constexpr acceleration_umeasurement(acceleration_umeasurement&& other) noexcept : 

            umeasurement(other) {}

                        
    }; // struct acceleration_umeasurement


    struct force_umeasurement : public umeasurement {


        /**
         * @brief Construct a new default force_umeasurement object 
         * 
         * @note the value is set to 0.0
         * @note the uncertainty is set to 0.0
         * @note the unit is set to kilogram * metre / second^2
         */
        explicit constexpr force_umeasurement() noexcept : 

            umeasurement(0.0, 0.0, N) {}


        /**
         * @brief Construct a new force_umeasurement object from a value and an unit of force
         * 
         * @param value: scalar value as l-value const reference
         * @param uncertainty: scalar uncertainty as l-value const reference
         * @param force_units: unit of force as l-value const reference
         *
         * @note If the unit is not specified, the unit is set to N (kilogram * metre / second^2)
         */
        constexpr force_umeasurement(const scalar& value, 
                                     const scalar& uncertainty = 0.0,
                                     const unit& force_units = N) {

            if (force_units.base_ != basis::kilogram * basis::metre / basis::second.square()) 
                throw std::invalid_argument("Cannot convert from " + force_units.base_.to_string() + " to kilogram * metre / second^2 in initialization of force_umeasurement");

            else if (uncertainty < 0.0)
                throw std::invalid_argument("Cannot initialize a force_umeasurement with a negative uncertainty");

            else {

                this->value_ = value;
                this->uncertainty_ = uncertainty;
                this->units_ = force_units;            
            
            }
            
        }


        /**
         * @brief Copy constuct a new force_umeasurement object from another umeasurement
         * 
         * @param other: umeasurement to copy from as l-value const reference
         */
        constexpr force_umeasurement(const umeasurement& other) {


            if (other.units_.base_ != basis::kilogram * basis::metre / basis::second.square()) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to kilogram * metre / second^2 in initialization of force_umeasurement");

            else {

                this->value_ = other.value_;
                this->uncertainty_ = other.uncertainty_;
                this->units_ = other.units_;
                
            }

        }
            
        
        /**
         * @brief Move construct a new force_umeasurement object from another umeasurement
         * 
         * @param other: umeasurement to move from as r-value reference
         */
        constexpr force_umeasurement(umeasurement&& other)  {

            if (other.units_.base_ != basis::kilogram * basis::metre / basis::second.square()) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to kilogram * metre / second^2 in initialization of force_umeasurement");

            else {

                this->value_ = std::move(other.value_);
                this->uncertainty_ = std::move(other.uncertainty_);
                this->units_ = std::move(other.units_);

            }

        }


        /**
         * @brief Copy construct a new force_umeasurement object from another force_measurement
         * 
         * @param other: force_measurement to copy from as l-value const reference
         */
        constexpr force_umeasurement(const force_umeasurement& other) noexcept : 

            umeasurement(other) {}


        /**
         * @brief Move construct a new force_umeasurement object from another force_measurement
         * 
         * @param other: force_measurement to move from as r-value reference
         */
        constexpr force_umeasurement(force_umeasurement&& other) noexcept : 

            umeasurement(other) {}

                        
    }; // struct force_umeasurement


    struct angle_umeasurement : public umeasurement {


        /**
         * @brief Construct a new default angle_umeasurement object 
         * 
         * @note The value is set to 0.0
         * @note The uncertainty is set to 0.0
         * @note The unit is set to rad
         */
        explicit constexpr angle_umeasurement() noexcept : 

            umeasurement(0.0, 0.0, rad) {}


        /**
         * @brief Construct a new angle_umeasurement object from a value and an unit of angle
         * 
         * @param value: scalar value as l-value const reference
         * @param uncertainty: scalar uncertainty as l-value const reference
         * @param angle_units: unit of angle as l-value const reference
         *
         * @note If the unit is not specified, the unit is set to rad
         */
        constexpr angle_umeasurement(const scalar& value, 
                                     const scalar& uncertainty = 0.0,
                                     const unit& angle_units = rad) {

            if (angle_units.base_ != basis::default_type) 
                throw std::invalid_argument("Cannot convert from " + angle_units.base_.to_string() + " to rad in initialization of angle_umeasurement");

            else if (uncertainty < 0.0)
                throw std::invalid_argument("Cannot initialize a angle_umeasurement with a negative uncertainty");

            else {

                this->value_ = value;
                this->uncertainty_ = uncertainty;
                this->units_ = angle_units;            
            
            }
            
        }


        /**
         * @brief Copy constuct a new angle_umeasurement object from another umeasurement
         * 
         * @param other: umeasurement to copy from as l-value const reference
         */
        constexpr angle_umeasurement(const umeasurement& other) {


            if (other.units_.base_ != basis::default_type) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to rad in initialization of angle_umeasurement");

            else {

                this->value_ = other.value_;
                this->uncertainty_ = other.uncertainty_;
                this->units_ = other.units_;
                
            }

        }
            
        
        /**
         * @brief Move construct a new angle_umeasurement object from another umeasurement
         * 
         * @param other: umeasurement to move from as r-value reference
         */
        constexpr angle_umeasurement(umeasurement&& other)  {

            if (other.units_.base_ != basis::default_type) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to rad in initialization of angle_umeasurement");

            else {

                this->value_ = std::move(other.value_);
                this->uncertainty_ = std::move(other.uncertainty_);
                this->units_ = std::move(other.units_);

            }

        }


        /**
         * @brief Copy construct a new angle_umeasurement object from another angle_umeasurement
         * 
         * @param other: angle_umeasurement to copy from as l-value const reference
         */
        constexpr angle_umeasurement(const angle_umeasurement& other) noexcept : 

            umeasurement(other) {}


        /**
         * @brief Move construct a new angle_umeasurement object from another angle_umeasurement
         * 
         * @param other: angle_umeasurement to move from as r-value reference
         */
        constexpr angle_umeasurement(angle_umeasurement&& other) noexcept : 

            umeasurement(other) {}

        
        /**
         * @brief Copy assign a new angle_umeasurement object from an umeasurement
         * 
         * @param other: umeasurement to copy from as l-value const reference
         */
        constexpr angle_umeasurement& operator=(const umeasurement& other) {

            if (other.units_.base_ != basis::default_type) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to rad in initialization of angle_umeasurement");

            else {

                this->value_ = other.value_;
                this->uncertainty_ = other.uncertainty_;
                this->units_ = other.units_;
                
            }

            return *this;
        
        }


        /**
         * @brief Move assign a new angle_umeasurement object from an umeasurement
         * 
         * @param other: umeasurement to copy from as r-value reference
         */
        constexpr angle_umeasurement& operator=(umeasurement&& other) {

            if (other.units_.base_ != basis::default_type) 
                throw std::invalid_argument("Cannot convert from " + other.units_.base_.to_string() + " to rad in initialization of angle_umeasurement");

            else {

                this->value_ = other.value_;
                this->uncertainty_ = other.uncertainty_;
                this->units_ = other.units_;
                
            }

            return *this;
        
        }


        /**
         * @brief Copy assign a new angle_umeasurement object from another angle_umeasurement
         * 
         * @param other: angle_umeasurement to copy from as l-value const reference
         */
        constexpr angle_umeasurement& operator=(const angle_umeasurement& other) noexcept {

            this->value_ = other.value_;
            this->uncertainty_ = other.uncertainty_;
            this->units_ = other.units_;

            return *this;
        
        }


        /**
         * @brief Move assign a new angle_umeasurement object from another angle_umeasurement
         * 
         * @param other: angle_umeasurement to copy from as r-value reference
         */
        constexpr angle_umeasurement& operator=(angle_umeasurement&& other) noexcept {

            this->value_ = other.value_;
            this->uncertainty_ = other.uncertainty_;
            this->units_ = other.units_;

            return *this;
        
        }


    }; // struct angle_umeasurement


} // namespace measurements