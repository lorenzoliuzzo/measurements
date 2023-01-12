/**
 * @file    unit.hpp
 * @author  Lorenzo Liuzzo (lorenzoliuzzo@outlook.com)
 * @brief   This file contains the definition and implementation of the unit struct,
 *          with all its methods, operators and possibly operations.
 * @date    2023-01-01
 * 
 * @copyright Copyright (c) 2023
 */


#pragma once


namespace measurements {

    
    namespace units {


        /** 
         * @brief Struct represents an unit of measurement as an union of an unit_prefix and an unit_base 
         * @see unit_prefix
         * @see unit_base
         */
        struct unit {


            // =============================================
            // constructors & destructor
            // ============================================= 

                /// @brief Construct a new default unit object
                explicit constexpr unit() noexcept = default;


                /**
                 * @brief Construct a new unit object from a prefix and a base 
                 * 
                 * @param prefix: unit_prefix as l-value const reference
                 * @param base: unit_base as l-value const reference
                 */
                constexpr unit(const unit_prefix& prefix, 
                               const unit_base& base) noexcept : 
                    
                    base_(base), 
                    prefix_(prefix) {}


                /**
                 * @brief Construct a new unit object from a unit_prefix and an unit_base
                 * 
                 * @param prefix: unit_prefix as r-value reference
                 * @param base: unit_base as r-value reference
                 */
                constexpr unit(unit_prefix&& prefix, 
                               unit_base&& base) noexcept : 
                    
                    base_(std::move(base)), 
                    prefix_(std::move(prefix)) {}


                /**
                 * @brief Construct a new unit object from an unit_base and an unit_prefix
                 * 
                 * @param base: unit_base object as l-value const reference
                 * @param prefix: unit_prefix as l-value const reference
                 */
                explicit constexpr unit(const unit_base& base, 
                                        const unit_prefix& prefix = unit_prefix()) noexcept : 
                    
                    base_(base), 
                    prefix_(prefix) {}


                /**
                 * @brief Construct a new unit object from a unit_base and unit_prefix
                 * 
                 * @param base: unit_base as r-value reference
                 * @param prefix: unit_prefix as r-value reference
                 */
                explicit constexpr unit(unit_base&& base, 
                                        unit_prefix&& prefix) noexcept : 
                    
                    base_(std::move(base)), 
                    prefix_(std::move(prefix)) {}


                /**
                 * @brief Construct a new unit from an unit_prefix and an unit object
                 * 
                 * @param prefix: unit_prefix as l-value const reference
                 * @param unit: unit as l-value const reference
                 */
                explicit constexpr unit(const unit_prefix& prefix, 
                                        const unit& unit) noexcept : 
                    
                    base_(unit.base_), 
                    prefix_(prefix * unit.prefix_) {}


                /**
                 * @brief Copy construct a new unit from another unit object
                 * 
                 * @param other: unit object to copy from as l-value const reference
                 */
                constexpr unit(const unit& other) noexcept : 

                    base_(other.base_), 
                    prefix_(other.prefix_) {}


                /**
                 * @brief Move construct a new unit from another unit object
                 * 
                 * @param other: unit object to move from as r-value reference
                 */
                constexpr unit(unit&& other) noexcept : 

                    base_(std::move(other.base_)), 
                    prefix_(std::move(other.prefix_)) {}


                /// @brief Default destructor
                ~unit() noexcept = default; 


            // =============================================
            // operators
            // ============================================= 

                /**
                 * @brief Copy assignment operator
                 * 
                 * @param other: unit object to copy from as l-value const reference
                 * 
                 * @return constexpr unit&
                 */
                constexpr unit& operator=(const unit& other) noexcept {

                    this->base_ = other.base_;
                    this->prefix_ = other.prefix_;

                    return *this;

                }


                /**
                 * @brief Move assignment operator
                 * 
                 * @param other: unit object to move from as r-value reference
                 * 
                 * @return constexpr unit& 
                 */
                constexpr unit& operator=(unit&& other) noexcept {

                    this->base_ = std::move(other.base_);
                    this->prefix_ = std::move(other.prefix_);

                    return *this;

                }


                /**
                 * @brief Multiply this unit with an unit
                 * 
                 * @param other: unit object to multiply with as l-value const reference
                 *                      
                 * @return constexpr unit&
                 */
                constexpr unit& operator*=(const unit& other) noexcept { 
                    
                    this->base_ *= other.base_; 
                    this->prefix_ *= other.prefix_; 

                    return *this; 
                    
                }


                /**
                 * @brief Multiply this unit with an unit
                 * 
                 * @param other: unit object to multiply with as r-value reference
                 *                      
                 * @return constexpr unit&
                 */
                constexpr unit& operator*=(unit&& other) noexcept { 
                    
                    this->base_ *= std::move(other.base_); 
                    this->prefix_ *= std::move(other.prefix_); 

                    return *this; 
                    
                }


                /**
                 * @brief Divide this unit with an unit
                 * 
                 * @param other: unit object to divide with as l-value const reference
                 *                      
                 * @return constexpr unit&
                 */
                constexpr unit& operator/=(const unit& other) noexcept { 
                    
                    this->base_ /= other.base_; 
                    this->prefix_ /= other.prefix_; 

                    return *this; 
                    
                }                 


                /**
                 * @brief Divide this unit with an unit
                 * 
                 * @param other: unit object to divide with as r-value reference
                 *                      
                 * @return constexpr unit&
                 */
                constexpr unit& operator/=(unit&& other) noexcept { 
                    
                    this->base_ /= std::move(other.base_); 
                    this->prefix_ /= std::move(other.prefix_); 

                    return *this; 
                    
                }  


                /**
                 * @brief Perform a multiplication by multiply the bases and the prefixes
                 * 
                 * @param other: unit object to multiply with as l-value const reference
                 *                      
                 * @return constexpr unit
                 */
                constexpr unit operator*(const unit& other) const noexcept { 
                    
                    return { this->prefix_ * other.prefix_, this->base_ * other.base_ }; 
                    
                }


                /**
                 * @brief Perform a division by divide the bases and the prefixes
                 * 
                 * @param other: unit object to divide with as l-value const reference
                 *                      
                 * @return constexpr unit
                 */
                constexpr unit operator/(const unit& other) const noexcept { 
                    
                    return { this->prefix_ / other.prefix_, this->base_ / other.base_ }; 
                    
                }                    


                /**
                 * @brief Equality operator
                 * 
                 * @param other: unit object to compare with as l-value const reference
                 * 
                 * @return constexpr bool 
                 */
                constexpr bool operator==(const unit& other) const noexcept {

                    if (this->base_ != other.base_) 
                        return false; 

                    else 
                        return this->prefix_ == other.prefix_;

                }


                /**
                 * @brief Inequality operator
                 * 
                 * @param other: unit object to !compare with as l-value const reference
                 * 
                 * @return constexpr bool 
                 */
                constexpr bool operator!=(const unit& other) const noexcept { 

                    if (this->base_ == other.base_) 
                        return this->prefix_ == other.prefix_;

                    else 
                        return true;
                    
                }


                /**
                 * @brief Output operator for an unit of measurement
                 * 
                 * @param os: std::ostream&
                 * @param units: unit of measurement as l-value const reference
                 * 
                 * @return std::ostream&
                 *  
                 */
                friend std::ostream& operator<<(std::ostream& os, const unit& units) noexcept {

                    os << units.to_string(); 

                    return os; 

                }


                /**
                 * @brief Output operator for an unit of measurement
                 * 
                 * @param file: std::ofstream&
                 * @param units: unit of measurement as l-value const reference
                 * 
                 * @return std::ofstream&
                 *  
                 */
                friend std::ofstream& operator<<(std::ofstream& file, const unit& units) noexcept {

                    file << units.to_string();

                    return file; 

                }


            // =============================================
            // operations
            // ============================================= 

                /**
                 * @brief Invert the unit
                 * 
                 * @return constexpr unit
                 */
                constexpr unit inv() const noexcept { 
                    
                    return { this->prefix_.inv(), this->base_.inv() }; 
                    
                }


                /**
                 * @brief Take the power of the unit
                 * 
                 * @param power
                 * 
                 * @return unit 
                 */
                inline unit pow(const int& power) const noexcept { 
                    
                    return { this->prefix_.pow(power), this->base_.pow(power) }; 
                    
                }


                /**
                 * @brief Take the square of the unit
                 * 
                 * @return constexpr unit 
                 */
                constexpr unit square() const noexcept { 
                    
                    return { this->prefix_.square(), this->base_.square() }; 
                    
                }


                /**
                 * @brief Take the cube of the unit
                 * 
                 * @return constexpr unit 
                 */
                constexpr unit cube() const noexcept { 
                    
                    return { this->prefix_.cube(), this->base_.cube() }; 
                    
                }


                /**
                 * @brief Take the root of the unit
                 * 
                 * @param power
                 * 
                 * @return constexpr unit 
                 */
                constexpr unit root(const int& power) const { 
                    
                    return { this->prefix_.root(power), this->base_.root(power) }; 
                    
                }


                /**
                 * @brief Take the square root of the unit
                 * 
                 * @return unit 
                 */
                inline unit sqrt() const { 
                    
                    return { this->prefix_.sqrt(), this->base_.sqrt() }; 
                    
                }


                /**
                 * @brief Take the cube root of the unit
                 * 
                 * @return unit 
                 */
                inline unit cbrt() const { 
                    
                    return { this->prefix_.cbrt(), this->base_.cbrt() }; 
                    
                }


            // =============================================
            // setters & getters
            // ============================================= 

                /**
                 * @brief Get the unit base object
                 * 
                 * @return constexpr unit_base 
                 */
                constexpr const unit_base& base() const noexcept { 
                    
                    return this->base_; 
                    
                }


                /**
                 * @brief Get the unit base object
                 * 
                 * @return constexpr unit_base& 
                 */
                constexpr unit_base& base() noexcept { 
                    
                    return this->base_; 
                    
                }


                /**
                 * @brief Get the unit prefix object
                 * 
                 * @return constexpr unit_prefix 
                 */
                constexpr const unit_prefix& prefix() const noexcept { 
                    
                    return this->prefix_; 
                    
                }


                /**
                 * @brief Get the unit prefix object
                 * 
                 * @return constexpr unit_prefix&
                 */
                constexpr unit_prefix& prefix() noexcept { 
                    
                    return this->prefix_; 
                    
                }


                /**
                 * @brief Get the unit object
                 * 
                 * @return constexpr unit
                 */
                constexpr const unit& units() const noexcept { 
                    
                    return *this; 
                    
                }


                /**
                 * @brief Get the unit object
                 * 
                 * @return constexpr unit& 
                 */
                constexpr unit& units() noexcept { 
                    
                    return *this; 
                    
                }


                /**
                * @brief Generate a conversion factor between this unit and another unit 
                * 
                * @param result: desired unit
                * 
                * @return constexpr scalar 
                * @note the units will only convert if they have the same base unit
                */
                constexpr scalar convertion_factor(const unit& other) const noexcept { 
                    
                    return (this->base_ == other.base_) ? this->prefix_.multiplier_ / other.prefix_.multiplier_ : std::numeric_limits<scalar>::signaling_NaN();                     
                }


                /**
                * @brief Convert a value in the current unit to the target unit 
                * 
                * @param value: value to convert 
                * @param other: desired unit unit
                * 
                * @return constexpr scalar 
                * @note the units will only convert if they have the same base unit
                */
                constexpr scalar convert(const scalar& value, const unit& other) const noexcept { 
                    
                    return value * this->convertion_factor(other);
                
                }


                /**
                 * @brief Get the unit string
                 * 
                 * @return std::string 
                 */
                inline std::string to_string() const noexcept {

                    return (this->prefix_.symbol_ == '\0') ? this->base_.to_string() : this->prefix_.symbol_ + this->base_.to_string(); 

                }


                /// @brief Print the unit to the standard output
                inline void print() const noexcept {

                    std::cout << this->to_string();

                }

        
            // =============================================
            // struct members & friends
            // ============================================= 

                unit_base base_; ///< unit base

                unit_prefix prefix_; ///< unit prefix


                friend class measurement; ///< measurement class is a friend of unit

                friend class umeasurement; ///< umeasurement class is a friend of unit


        }; // struct unit     


    } // namespace units
    
    
} // namespace measurements