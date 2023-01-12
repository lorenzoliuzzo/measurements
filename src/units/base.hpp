/**
 * @file    base.hpp
 * @author  Lorenzo Liuzzo (lorenzoliuzzo@outlook.com)
 * @brief   This file contains the definition and implementation of the unit_base struct,
 *          with all its methods, operators and possibly operations.
 * @date    2023-01-12
 * 
 * @copyright Copyright (c) 2023
 */


#pragma once


namespace measurements {

    
    namespace units {


        /// @brief unit_base represents an unit_base using exponenents of the powers of the seven SI unit_bases 
        struct unit_base {


            // =============================================
            // constructors and destructor
            // =============================================  

                /// @brief Construct a new default unit_base object
                explicit constexpr unit_base() noexcept :

                    metre_{0}, second_{0}, kilogram_{0}, 
                    ampere_{0}, kelvin_{0}, mole_{0}, candela_{0} {}


                /**
                 * @brief Construct a new unit_base object with powers of the seven SI unit_bases
                 * 
                 * @param metres: power of metre
                 * @param seconds: power of second
                 * @param kilograms: power of kilogram
                 * @param amperes: power of ampere
                 * @param kelvins: power of kelvin
                 * @param moles: power of mole
                 * @param candelas: power of candela
                 */
                explicit constexpr unit_base(int metres, 
                                             int seconds, 
                                             int kilograms, 
                                             int amperes, 
                                             int kelvins,  
                                             int moles, 
                                             int candelas) noexcept : 
                        
                    metre_(metres), second_(seconds), kilogram_(kilograms), 
                    ampere_(amperes), kelvin_(kelvins), mole_(moles), candela_(candelas) {}


                /**
                 * @brief Construct a new unit_base object from a string
                 * 
                 * @param unit_string: string represents the unit_base
                 */
                constexpr unit_base(const std::string& unit_string) noexcept : 
                    
                    metre_{0}, second_{0}, kilogram_{0},
                    ampere_{0}, kelvin_{0}, mole_{0}, candela_{0} {
                    
                    if (!unit_string.empty()) {

                        std::size_t finder = unit_string.find('m');
                        if (finder != std::string::npos) {

                            if (finder == unit_string.size() - 1 || unit_string.at(finder + 1) != '^') 
                                this->metre_ = 1; 
                            else {
                                if (unit_string.at(finder + 2) == '-') 
                                    this->metre_ -= std::stoi(unit_string.substr(finder + 3));
                                else 
                                    this->metre_ = std::stoi(unit_string.substr(finder + 2));
                            }
                            
                        }

                        finder = unit_string.find('s');
                        if (finder != std::string::npos) {

                            if (finder == unit_string.size() - 1 || unit_string.at(finder + 1) != '^') 
                                this->second_ = 1; 
                            else {
                                if (unit_string.at(finder + 2) == '-') 
                                    this->second_ -= std::stoi(unit_string.substr(finder + 3));
                                else 
                                    this->second_ = std::stoi(unit_string.substr(finder + 2));
                            }
                            
                        }

                        finder = unit_string.find("kg");
                        if (finder != std::string::npos) {

                            if (finder == unit_string.size() - 1 || unit_string.at(finder + 1) != '^') 
                                this->kilogram_ = 1; 
                            else {
                                if (unit_string.at(finder + 2) == '-') 
                                    this->kilogram_ -= std::stoi(unit_string.substr(finder + 3));
                                else 
                                    this->kilogram_ = std::stoi(unit_string.substr(finder + 2));
                            }

                        }

                        finder = unit_string.find('A');
                        if (finder != std::string::npos) {

                            if (finder == unit_string.size() - 1 || unit_string.at(finder + 1) != '^') 
                                this->ampere_ = 1; 
                            else {
                                if (unit_string.at(finder + 2) == '-') 
                                    this->ampere_ -= std::stoi(unit_string.substr(finder + 3));
                                else 
                                    this->ampere_ = std::stoi(unit_string.substr(finder + 2));
                            }                            
                        }

                        finder = unit_string.find('K');
                        if (finder != std::string::npos) {

                            if (finder == unit_string.size() - 1 || unit_string.at(finder + 1) != '^') 
                                this->kelvin_ = 1; 
                            else {
                                if (unit_string.at(finder + 2) == '-') 
                                    this->kelvin_ -= std::stoi(unit_string.substr(finder + 3));
                                else 
                                    this->kelvin_ = std::stoi(unit_string.substr(finder + 2));
                            }

                        }

                        finder = unit_string.find("mol");
                        if (finder != std::string::npos) {

                            if (finder == unit_string.size() - 1 || unit_string.at(finder + 1) != '^') 
                                this->mole_ = 1; 
                            else {
                                if (unit_string.at(finder + 2) == '-') 
                                    this->mole_ -= std::stoi(unit_string.substr(finder + 3));
                                else 
                                    this->mole_ = std::stoi(unit_string.substr(finder + 2));
                            }

                        }

                        finder = unit_string.find("cd");
                        if (finder != std::string::npos) {

                            if (finder == unit_string.size() - 1 || unit_string.at(finder + 1) != '^') 
                                this->candela_ = 1; 
                            else {
                                if (unit_string.at(finder + 2) == '-') 
                                    this->candela_ -= std::stoi(unit_string.substr(finder + 3));
                                else 
                                    this->candela_ = std::stoi(unit_string.substr(finder + 2));
                            }
                            
                        }

                    } 

                }
                

                /**
                 * @brief Copy construct a new unit_base from an other unit_base object
                 * 
                 * @param other: unit_base object to copy as l-value const reference
                 */
                constexpr unit_base(const unit_base& other) noexcept : 

                    metre_(other.metre_), second_(other.second_), 
                    kilogram_(other.kilogram_), ampere_(other.ampere_), 
                    kelvin_(other.kelvin_), mole_(other.mole_), candela_(other.candela_) {}


                /// @brief Default destructor
                ~unit_base() = default; 


            // =============================================
            // operators
            // ============================================= 

                /**
                 * @brief Copy assignment operator
                 * 
                 * @param other: unit_base to copy as l-value const reference
                 * 
                 * @return constexpr unit_base&
                 */
                constexpr unit_base& operator=(const unit_base& other) noexcept {

                    if (*this != other) {

                        this->metre_ = other.metre_; 
                        this->second_ = other.second_; 
                        this->kilogram_ = other.kilogram_; 
                        this->ampere_ = other.ampere_; 
                        this->kelvin_ = other.kelvin_; 
                        this->mole_ = other.mole_; 
                        this->candela_ = other.candela_; 

                    }

                    return *this; 

                }


                /**
                 * @brief Multiply this unit_base to an unit_base by adding the powers together
                 * 
                 * @param other: unit_base object to multiply with as l-value const reference
                 * 
                 * @return constexpr unit_base&
                 */
                constexpr unit_base& operator*=(const unit_base& other) noexcept {

                    this->metre_ += other.metre_; 
                    this->second_ += other.second_; 
                    this->kilogram_ += other.kilogram_; 
                    this->ampere_ += other.ampere_; 
                    this->kelvin_ += other.kelvin_; 
                    this->mole_ += other.mole_; 
                    this->candela_ += other.candela_; 

                    return *this; 

                }


                /**
                 * @brief Divide this unit_base to an unit_base by subtracting the powers together
                 * 
                 * @param other: unit_base object to divide with as l-value const reference
                 * 
                 * @return constexpr unit_base&
                 */
                constexpr unit_base& operator/=(const unit_base& other) noexcept {

                    this->metre_ -= other.metre_; 
                    this->second_ -= other.second_; 
                    this->kilogram_ -= other.kilogram_; 
                    this->ampere_ -= other.ampere_; 
                    this->kelvin_ -= other.kelvin_; 
                    this->mole_ -= other.mole_; 
                    this->candela_ -= other.candela_; 

                    return *this; 

                }


                /**
                 * @brief Perform a multiplication by adding the powers together
                 * 
                 * @param other: unit_base object to multiply with as l-value const reference
                 * 
                 * @return constexpr unit_base 
                 */
                constexpr unit_base operator*(const unit_base& other) const noexcept {

                    return unit_base(this->metre_ + other.metre_, 
                                     this->second_ + other.second_, 
                                     this->kilogram_ + other.kilogram_, 
                                     this->ampere_ + other.ampere_, 
                                     this->kelvin_ + other.kelvin_, 
                                     this->mole_ + other.mole_, 
                                     this->candela_ + other.candela_); 

                }


                /**
                 * @brief Perform a division by subtracting the powers
                 * 
                 * @param other: unit_base object to divide with as l-value const reference
                 * 
                 * @return constexpr unit_base 
                 */
                constexpr unit_base operator/(const unit_base& other) const noexcept {
                
                    return unit_base(this->metre_ - other.metre_, 
                                     this->second_ - other.second_, 
                                     this->kilogram_ - other.kilogram_, 
                                     this->ampere_ - other.ampere_, 
                                     this->kelvin_ - other.kelvin_, 
                                     this->mole_ - other.mole_, 
                                     this->candela_ - other.candela_); 

                }


                /**
                 * @brief Equality operator
                 * 
                 * @param other: unit_base object to compare with as l-value const reference
                 * 
                 * @return bool
                 */
                constexpr bool operator==(const unit_base& other) const noexcept {
                
                    return this->metre_ == other.metre_ &&
                           this->second_ == other.second_ &&
                           this->kilogram_ == other.kilogram_ &&
                           this->ampere_ == other.ampere_ &&
                           this->candela_ == other.candela_ &&
                           this->kelvin_ == other.kelvin_ &&
                           this->mole_ == other.mole_;   

                }


                /**
                 * @brief Inequality operator
                 * 
                 * @param other: unit_base object to !compare with as l-value const reference
                 * 
                 * @return bool
                 */                    
                constexpr bool operator!=(const unit_base& other) const noexcept { 
                    
                    return this->metre_ != other.metre_ ||
                           this->second_ != other.second_ ||
                           this->kilogram_ != other.kilogram_ ||
                           this->ampere_ != other.ampere_ ||
                           this->candela_ != other.candela_ ||
                           this->kelvin_ != other.kelvin_ ||
                           this->mole_ != other.mole_;   
                    
                }


                /**
                 * @brief Printing on video the unit_base litterals
                 * 
                 * @param os: std::ostream& 
                 * @param base: unit_base as l-value const reference
                 * 
                 * @return std::ostream&
                 */
                friend std::ostream& operator<<(std::ostream& os, const unit_base& base) noexcept {

                    os << base.to_string(); 

                    return os; 

                }


                /**
                 * @brief Printing on file the unit_base litterals
                 * 
                 * @param file: std::ofstream& 
                 * @param base: unit_base as l-value const reference
                 * 
                 * @return std::ofstream&
                 */
                friend std::ofstream& operator<<(std::ofstream& file, const unit_base& base) noexcept {

                    file << base.to_string(); 

                    return file; 

                }


            // =============================================
            // operations
            // ============================================= 

                /**
                 * @brief Invert the unit_base
                 * 
                 * @return constexpr unit_base
                 */
                constexpr unit_base inv() const noexcept {
                
                    return unit_base(-this->metre_, 
                                     -this->second_, 
                                     -this->kilogram_, 
                                     -this->ampere_, 
                                     -this->kelvin_, 
                                     -this->mole_, 
                                     -this->candela_);

                }


                /**
                 * @brief Take the power of the unit_base
                 * 
                 * @param power 
                 * 
                 * @return constexpr unit_base 
                 */
                constexpr unit_base pow(const int& power) const noexcept { 

                    return unit_base(this->metre_ * power, 
                                     this->second_ * power, 
                                     this->kilogram_ * power, 
                                     this->ampere_ * power, 
                                     this->kelvin_ * power, 
                                     this->mole_ * power, 
                                     this->candela_ * power);

                }


                /**
                 * @brief Take the square unit_base
                 * 
                 * @return constexpr unit_base 
                 */
                constexpr unit_base square() const noexcept { 
                    
                    return unit_base(this->metre_ * 2, 
                                     this->second_ * 2, 
                                     this->kilogram_ * 2, 
                                     this->ampere_ * 2, 
                                     this->kelvin_ * 2, 
                                     this->mole_ * 2, 
                                     this->candela_ * 2);

                }


                /**
                 * @brief  Take the cube unit_base
                 * 
                 * @return constexpr unit_base 
                 */
                constexpr unit_base cube() const noexcept { 
                    
                    return unit_base(this->metre_ * 3, 
                                     this->second_ * 3, 
                                     this->kilogram_ * 3, 
                                     this->ampere_ * 3, 
                                     this->kelvin_ * 3, 
                                     this->mole_ * 3, 
                                     this->candela_ * 3);

                }


                /**
                 * @brief Take the root of the unit_base
                 * 
                 * @param power 
                 * 
                 * @return constexpr unit_base 
                 */
                constexpr unit_base root(const int& power) const {

                    if (this->has_valid_root(power)) 
                        return unit_base(this->metre_ / power,
                                         this->second_ / power,
                                         this->kilogram_ / power,
                                         this->ampere_ / power,
                                         this->kelvin_ / power,
                                         this->mole_ / power,
                                         this->candela_ / power);

                    else 
                        throw std::invalid_argument("Invalid root power"); 

                }


                /**
                 * @brief Take the square root of the unit_base
                 * 
                 * @return constexpr unit_base 
                 */
                constexpr unit_base sqrt() const { 
                    
                    return this->root(2); 
                
                }


                /**
                 * @brief Take the cubic root of the unit_base
                 * 
                 * @return constexpr unit_base 
                 */
                constexpr unit_base cbrt() const { 
                    
                    return this->root(3);
                
                }


            // =============================================
            // get methods
            // =============================================

                /**
                 * @brief Check if the unit_base has a valid root
                 * 
                 * @param power: int as l-value const reference
                 * 
                 * @return bool 
                 */
                constexpr bool has_valid_root(const int& power) const noexcept {
                
                    return (this->metre_ % power == 0) &&
                           (this->second_ % power == 0) &&
                           (this->kilogram_ % power == 0) &&
                           (this->ampere_ % power == 0) &&
                           (this->candela_ % power == 0) &&
                           (this->kelvin_ % power == 0) &&
                           (this->mole_ % power == 0);

                }      


                /**
                 * @brief Units litterals to string
                 * 
                 * @return std::string 
                 */
                std::string to_string() const noexcept {
                    
                    std::string unit_base_string("");   
                    
                    if (this->metre_ == 1) 
                        unit_base_string.append("m");
                    else if (this->metre_ != 0) 
                        unit_base_string.append("m^" + std::to_string(metre_)); 

                    if (this->second_ == 1) 
                        unit_base_string.append("s"); 
                    else if (this->second_ != 0) 
                        unit_base_string.append("s^" + std::to_string(second_)); 

                    if (this->kilogram_ == 1) 
                        unit_base_string.append("kg"); 
                    else if (this->kilogram_ != 0)    
                        unit_base_string.append("kg^" + std::to_string(kilogram_)); 

                    if (this->ampere_ == 1) 
                        unit_base_string.append("A"); 
                    else if (this->ampere_ != 0)  
                        unit_base_string.append("A^" + std::to_string(ampere_)); 

                    if (this->kelvin_ == 1) 
                        unit_base_string.append("K");
                    else if (this->kelvin_ != 0) 
                        unit_base_string.append("K^" + std::to_string(kelvin_)); 

                    if (this->mole_ == 1) 
                        unit_base_string.append("mol"); 
                    else if (this->mole_ != 0) 
                        unit_base_string.append("mol^" + std::to_string(mole_)); 

                    if (this->candela_ == 1) 
                        unit_base_string.append("cd"); 
                    else if (this->candela_ != 0) 
                        unit_base_string.append("cd^" + std::to_string(candela_)); 

                    return unit_base_string; 
                
                }


                /// @brief Print the unit_base to the standard output
                inline void print() const noexcept {

                    std::cout << this->to_string(); 

                }


            // =============================================
            // struct members & friends
            // =============================================

                signed int metre_    : bitwidth::metre;    ///< Metre exponent
                
                signed int second_   : bitwidth::second;   ///< Second exponent
                
                signed int kilogram_ : bitwidth::kilogram; ///< Kilogram exponent
                
                signed int ampere_   : bitwidth::ampere;   ///< Ampere exponent
                
                signed int kelvin_   : bitwidth::kelvin;   ///< Kelvin exponent
                
                signed int mole_     : bitwidth::mole;     ///< Mole exponent
                
                signed int candela_  : bitwidth::candela;  ///< Candela exponent
    

                static constexpr uint32_t bits[7] = { bitwidth::metre, 
                                                      bitwidth::second, 
                                                      bitwidth::kilogram, 
                                                      bitwidth::ampere, 
                                                      bitwidth::kelvin, 
                                                      bitwidth::mole, 
                                                      bitwidth::candela }; ///< Static array with the SI exponents


                friend struct unit; ///< unit is a friend of unit_prefix 


        }; // struct unit_base


    } // namespace units
        

} // namespace measurements