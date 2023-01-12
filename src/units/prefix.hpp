/**
 * @file    prefix.hpp
 * @author  Lorenzo Liuzzo (lorenzoliuzzo@outlook.com)
 * @brief   This file contains the definition and implementation of the unit_prefix struct,
 *          with all its methods, operators and possibly operations.
 * @date    2023-01-12
 * 
 * @copyright Copyright (c) 2023
 */


#pragma once


namespace measurements {

    
    namespace units {


        /// @brief Struct represents an unit prefix using a multiplier (double) and a symbol (char)
        struct unit_prefix {


            // =============================================
            // constructor and destructor
            // ============================================= 

                /// @brief Construct a new default unit prefix object
                explicit constexpr unit_prefix() noexcept {}


                /**
                 * @brief Create a new unit_prefix object from a multiplier and a symbol
                 * 
                 * @param mult: scalar multiplier for scaling the measurement 
                 * @param symbol: char symbol for the string reppresentation
                 * 
                 * @note mult must be positive (> 0)
                 */
                explicit constexpr unit_prefix(const scalar& mult, 
                                               const char& symbol) {

                    if (mult <= 0) 
                        throw std::invalid_argument("unit_prefix multiplier must be positive");

                    else {

                        this->multiplier_ = mult;
                        this->symbol_ = symbol;
                        
                    }

                }


                /**
                 * @brief Copy construct a new unit_prefix object from another unit_prefix
                 * 
                 * @param other: unit_prefix as l-value const reference
                 */
                constexpr unit_prefix(const unit_prefix& other) noexcept : 

                    multiplier_{other.multiplier_}, 
                    symbol_{other.symbol_} {}


                /**
                 * @brief Copy construct a new unit_prefix object from another unit_prefix
                 * 
                 * @param other: unit_prefix as r-value reference
                 */
                constexpr unit_prefix(unit_prefix&& other) noexcept : 

                    multiplier_{std::move(other.multiplier_)}, 
                    symbol_{std::move(other.symbol_)} {}


                /// @brief Default destructor
                ~unit_prefix() noexcept = default; 


            // =============================================
            // operators
            // ============================================= 

                /**
                 * @brief Copy assignment operator
                 * 
                 * @param other: unit_prefix to copy as l-value const reference
                 * 
                 * @return constexpr unit_prefix&
                 */
                constexpr unit_prefix& operator=(const unit_prefix& other) noexcept {

                    this->multiplier_ = other.multiplier_; 
                    this->symbol_ = other.symbol_; 

                    return *this; 

                }


                /**
                 * @brief Copy assignment operator
                 * 
                 * @param other: unit_prefix to copy as r-value reference
                 * 
                 * @return constexpr unit_prefix&
                 */
                constexpr unit_prefix& operator=(unit_prefix&& other) noexcept {

                    this->multiplier_ = std::move(other.multiplier_); 
                    this->symbol_ = std::move(other.symbol_); 

                    return *this; 

                }


                /**
                 * @brief Multiply this unit_prefix to an unit_prefix by multiplying the multipliers together
                 * 
                 * @param other: unit_prefix object to multiply with as l-value const reference
                 * 
                 * @return constexpr unit_prefix&
                 */
                constexpr unit_prefix& operator*=(const unit_prefix& other) noexcept {

                    this->multiplier_ *= other.multiplier_; 

                    return *this; 

                }


                /**
                 * @brief Divide this unit_prefix to an unit_prefix by dividing the multipliers together
                 * 
                 * @param other: unit_prefix object to divide with as l-value const reference
                 * 
                 * @return constexpr unit_prefix&
                 */
                constexpr unit_prefix& operator/=(const unit_prefix& other) noexcept {

                    this->multiplier_ /= other.multiplier_; 

                    return *this; 

                }


                /**
                 * @brief Perform a multiplication between unit_prefixes 
                 * 
                 * @param other: unit_prefix object to multiply with as l-value const reference
                 * 
                 * @return constexpr unit_prefix 
                 */
                constexpr unit_prefix operator*(const unit_prefix& other) const noexcept {

                    return unit_prefix(this->multiplier_ * other.multiplier_, this->symbol_); 

                }


                /**
                 * @brief Perform a division between unit_prefixes 
                 * 
                 * @param other: unit_prefix object to muldividetiply with as l-value const reference
                 * 
                 * @return constexpr unit_prefix 
                 */
                constexpr unit_prefix operator/(const unit_prefix& other) const noexcept {

                    return unit_prefix(this->multiplier_ / other.multiplier_, this->symbol_); 

                }


                /**
                 * @brief Equality operator
                 * 
                 * @param other: unit_prefix object to compare with as l-value const reference
                 * 
                 * @return bool
                 */
                constexpr bool operator==(const unit_prefix& other) const noexcept {
                
                    return (this->multiplier_ == other.multiplier_ && this->symbol_ == other.symbol_);   

                }


                /**
                 * @brief Inequality operator
                 * 
                 * @param other: unit_prefix object to !compare with as l-value const reference
                 * 
                 * @return bool
                 * 
                 */                    
                constexpr bool operator!=(const unit_prefix& other) const noexcept { 
                    
                    return (this->multiplier_ != other.multiplier_ || this->symbol_ != other.symbol_);   
                    
                }


                /**
                 * @brief Printing on video the unit_prefix litterals
                 * 
                 * @param os: std::ostream& 
                 * @param prefix: unit_prefix as l-value const reference
                 */
                friend std::ostream& operator<<(std::ostream& os, const unit_prefix& prefix) noexcept {

                    os << prefix.symbol_; 

                    return os; 

                }


                /**
                 * @brief Printing on file the unit_prefix litterals
                 * 
                 * @param file: std::ofstream& 
                 * @param prefix: unit_prefix as l-value const reference
                 */
                friend std::ofstream& operator<<(std::ofstream& file, const unit_prefix& prefix) noexcept {

                    file << prefix.symbol_; 

                    return file; 

                }


            // =============================================
            // operations
            // ============================================= 

                /**
                 * @brief Invert the unit_prefix
                 * 
                 * @return constexpr unit_prefix 
                 */
                constexpr unit_prefix inv() const noexcept { 
                    
                    return unit_prefix(1. / this->multiplier_, this->symbol_); 
                    
                }


                /**
                 * @brief Take the power of the unit_prefix
                 * 
                 * @param power 
                 * 
                 * @return unit_prefix 
                 */
                inline unit_prefix pow(const int& power) const noexcept { 
                    
                    return unit_prefix(std::pow(this->multiplier_, power), this->symbol_); 
                    
                }


                /**
                 * @brief Take the square of the unit_prefix
                 * 
                 * @return constexpr unit_prefix 
                 */
                constexpr unit_prefix square() const noexcept { 
                    
                    return unit_prefix(std::pow(this->multiplier_, 2), this->symbol_); 
                    
                }


                /**
                 * @brief Take the cube of the unit_prefix
                 * 
                 * @return constexpr unit_prefix 
                 */
                constexpr unit_prefix cube() const noexcept { 
                    
                    return unit_prefix(std::pow(this->multiplier_, 3), this->symbol_); 
                    
                }


                /**
                 * @brief Take the root of the unit_prefix
                 * 
                 * @param power 
                 * 
                 * @return constexpr unit_prefix 
                 */
                constexpr unit_prefix root(const int& power) const noexcept { 
                    
                    return unit_prefix(std::pow(this->multiplier_, power), this->symbol_); 
                    
                }


                /**
                 * @brief Take the square root of the unit_prefix
                 * 
                 * @return unit_prefix 
                 */
                inline unit_prefix sqrt() const noexcept { 
                    
                    return unit_prefix(std::pow(this->multiplier_, 1. / 2.), this->symbol_); 
                    
                }


                /**
                 * @brief Take the cube root of the unit_prefix
                 * 
                 * @return unit_prefix 
                 */
                inline unit_prefix cbrt() const noexcept { 
                    
                    return unit_prefix(std::pow(this->multiplier_, 1. / 3.), this->symbol_); 
                    
                }


            // =============================================
            // get methods
            // ============================================= 

                /**
                 * @brief Get the multiplier of the unit_prefix
                 * 
                 * @return constexpr scalar 
                 */
                constexpr const scalar& multiplier() const noexcept {

                    return this->multiplier_; 

                }


                /**
                 * @brief Get the multiplier of the unit_prefix
                 * 
                 * @return constexpr scalar& 
                 */
                constexpr scalar& multiplier() noexcept {

                    return this->multiplier_; 

                }


                /**
                 * @brief Get the symbol of the unit_prefix
                 * 
                 * @return constexpr char
                 */
                constexpr char symbol() const noexcept {

                    return this->symbol_; 

                }


                /**
                 * @brief Get the symbol of the unit_prefix
                 * 
                 * @return constexpr char&
                 */
                constexpr char& symbol() noexcept {

                    return this->symbol_; 

                }


            // =============================================
            // struct members & friends
            // =============================================

                scalar multiplier_{1.0}; ///< multiplier of the unit_prefix

                char symbol_{'\0'}; ///< symbol of the unit_prefix


                friend struct unit; ///< unit is a friend of unit_prefix


        }; // struct unit_prefix


    } // namespace units
    
    
} // namespace measurements