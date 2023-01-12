/**
 * @file    measurement.hpp
 * @author  Lorenzo Liuzzo (lorenzoliuzzo@outlook.com)
 * @brief   This file contains the definition and implementation of the measurement class,
 *          with all its methods, operators and possibly operations.
 * @date    2022-12-31
 * 
 * @copyright Copyright (c) 2023
 */


#pragma once


namespace measurements {


    using namespace units; 
    using namespace units::SI;


    /** 
     * @brief A class for representing a physical quantity with a numerical value and an unit
     * @see units::unit  
     */
    class measurement {


        public:

        // =============================================                                                                                         
        // constructors & destructor 
        // =============================================  

            /**
             * @brief Construct a new measurement object
             * 
             * @note The default value is 0 and the default unit is unitless
             */
            constexpr measurement() noexcept : 
                                            
                value_{0.0}, 
                units_() {} 


            /**
             * @brief Construct a new measurement object from a value and an unit of measurement
             * 
             * @param scal: scalar as l-value const referenceue: scalar as l-value const reference
             * @param units: unit as l-value const reference
             *
             * @note If the unit is not specified, the unit is set to unitless
             */
            constexpr measurement(const scalar& value, 
                                  const unit& units = unit()) noexcept : 
                                            
                value_{value}, 
                units_(units) {}



            /**
             * @brief Construct a new measurement object from a value and an unit of measurement
             * 
             * @param scal: scalar as l-value const referenceue: scalar as r-value reference
             * @param units: unit as r-value reference
             * 
             * @note If the unit is not specified, the unit is set to unitless
             */
            constexpr measurement(scalar&& value,
                                  unit&& units = unit()) noexcept : 
                                            
                value_{value}, 
                units_(units) {}


            /**
             * @brief Copy constuct a new measurement object from another measurement
             * 
             * @param other: measurement as l-value const reference
             */
            constexpr measurement(const measurement& other) noexcept : 
            
                value_{other.value_}, 
                units_(other.units_) {}
                
            
            /**
             * @brief Move construct a new measurement object from another measurement
             * 
             * @param other: measurement as r-value reference
             */
            constexpr measurement(measurement&& other) noexcept :
                
                value_{std::move(other.value_)}, 
                units_(std::move(other.units_)) {}


            /// @brief Destruct the measurement object
            ~measurement() = default;


        // =============================================                                                                                         
        // operators
        // =============================================  

            /**
             * @brief Copy assign another measurement to this measurement
             * 
             * @param other: measurement as l-value const reference
             * 
             * @return measurement& 
             */
            constexpr measurement& operator=(const measurement& other) noexcept {

                this->value_ = other.value_;
                this->units_ = other.units_;

                return *this;

            }     


            /**
             * @brief Move assign another measurement to this measurement
             * 
             * @param other: measurement as r-value reference
             * 
             * @return measurement& 
             */
            constexpr measurement& operator=(measurement&& other) noexcept {

                this->value_ = std::move(other.value_);
                this->units_ = std::move(other.units_);

                return *this;

            }


            /**
             * @brief Add another measurement to this measurement
             * 
             * @param other: measurement as l-value const reference
             * 
             * @return measurement& 
             */
            constexpr measurement& operator+=(const measurement& other) { 
                
                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot add measurements with different unit_base");
                
                if (this->units_ != unitless) 
                    this->value_ += other.value_as(this->units_); 

                else {

                    this->value_ += other.value_; 
                    this->units_ = other.units_; 

                }  

                return *this; 
            
            }


            /**
             * @brief Add another measurement to this measurement
             * 
             * @param other: measurement as r-value reference
             * 
             * @return measurement& 
             */
            constexpr measurement& operator+=(measurement&& other) { 

                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot add measurements with different unit_base");
                
                if (this->units_ != unitless) 
                    this->value_ += std::move(other.value_as(this->units_));   

                else {

                    this->value_ += std::move(other.value_);  
                    this->units_ = std::move(other.units_); 

                }   

                return *this; 
            
            }


            /**
             * @brief Subtract another measurement to this measurement
             * 
             * @param other: measurement l-value const reference
             * 
             * @return measurement& 
             */
            constexpr measurement& operator-=(const measurement& other) { 

                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot subtract measurements with different unit_base");
                
                if (this->units_ != unitless) 
                    this->value_ -= other.value_as(this->units_);   

                else {

                    this->value_ -= other.value_;    
                    this->units_ = other.units_; 

                }   

                return *this; 
            
            }


            /**
             * @brief Subtract another measurement to this measurement
             * 
             * @param other: measurement as r-value reference
             * 
             * @return measurement& 
             */
            constexpr measurement& operator-=(measurement&& other) { 

                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot subtract measurements with different unit_base");
                
                if (this->units_ != unitless)
                    this->value_ -= std::move(other.value_as(this->units_));

                else {

                    this->value_ -= std::move(other.value_);    
                    this->units_ = std::move(other.units_); 

                }     

                return *this;   

            }


            /**
             * @brief Multiply this measurement by another measurement
             * 
             * @param other: measurement as l-value const reference
             * 
             * @return measurement& 
             */
            constexpr measurement& operator*=(const measurement& other) noexcept { 

                this->value_ *= other.value_;
                this->units_ *= other.units_;    

                return *this; 
            
            }


            /**
             * @brief Multiply this measurement by another measurement
             * 
             * @param other: measurement as r-value reference
             * 
             * @return measurement& 
             */
            constexpr measurement& operator*=(measurement&& meas) noexcept { 

                this->value_ *= std::move(meas.value_);
                this->units_ *= std::move(meas.units_);   

                return *this; 
            
            }


            /**
             * @brief Divide this measurement by another measurement
             * 
             * @param other: measurement as l-value const reference
             * 
             * @return measurement& 
             */
            constexpr measurement& operator/=(const measurement& other) { 

                if (other.value_ == 0.0)
                    throw std::runtime_error("Cannot divide a measurement by a zero measurement");
                
                this->value_ /= other.value_;
                this->units_ /= other.units_;                                    
                
                return *this; 
            
            }


            /**
             * @brief Divide this measurement by another measurement
             * 
             * @param other: measurement as r-value reference
             * 
             * @return measurement& 
             */
            constexpr measurement& operator/=(measurement&& other) { 
                
                if (other.value_ == 0.0) 
                    throw std::runtime_error("Cannot divide a measurement by a zero measurement");
                
                this->value_ /= std::move(other.value_);
                this->units_ /= std::move(other.units_);                                    
                
                return *this; 
            
            }


            /**
             * @brief Multiply this measurement by a scalar
             * 
             * @param scal: scalar as l-value const reference 
             * 
             * @return constexpr measurement& 
             */
            constexpr measurement& operator*=(const scalar& scal) noexcept { 

                this->value_ *= scal;    

                return *this; 
            
            }


            /**
             * @brief Multiply this measurement by a scalar
             * 
             * @param scal: scalar as r-value reference
             * 
             * @return constexpr measurement& 
             */
            constexpr measurement& operator*=(scalar&& scal) noexcept { 

                this->value_ *= scal;    

                return *this; 
            
            }


            /**
             * @brief Divide this measurement by a scalar
             * 
             * @param scal: scalar as l-value const reference
             * 
             * @return constexpr measurement& 
             */
            constexpr measurement& operator/=(const scalar& scal) { 
                
                if (scal == 0.0) 
                    throw std::runtime_error("Cannot divide a measurement by 0");
                
                this->value_ /= scal;                    
                
                return *this; 
            
            }


            /**
             * @brief Divide this measurement by a scalar
             * 
             * @param scal: scalar as r-value reference
             * 
             * @return constexpr measurement& 
             */
            constexpr measurement& operator/=(scalar&& scal) { 
                
                if (scal == 0.0) 
                    throw std::runtime_error("Cannot divide a measurement by 0");
                
                this->value_ /= scal;                    
                
                return *this; 
            
            }


            /**
             * @brief Sum this measurement and another measurement
             * 
             * @param other: measurement as l-value const reference
             * 
             * @return measurement 
             */
            constexpr measurement operator+(const measurement& other) const { 
                
                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot sum measurements with different unit_base");
                
                return { this->value_ + other.value_as(this->units_), this->units_ }; 
            
            }


            /**
             * @brief Sum this measurement and another measurement
             * 
             * @param other: measurement as r-value reference
             * 
             * @return measurement 
             */
            constexpr measurement operator+(measurement&& other) const { 
                
                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot sum measurements with different unit_base");
                
                return { this->value_ + other.value_as(this->units_), this->units_ }; 
            
            }


            /**
             * @brief Subtract this measurement and another measurement 
             * 
             * @param other: measurement as l-value const reference
             *  
             * @return constexpr measurement 
             */
            constexpr measurement operator-(const measurement& other) const { 

                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot subtract measurements with different unit_base");
                
                return { this->value_ - other.value_as(this->units_), this->units_ }; 
            
            }


            /**
             * @brief Subtract this measurement and another measurement 
             * 
             * @param other: measurement as r-value reference
             *  
             * @return constexpr measurement 
             */
            constexpr measurement operator-(measurement&& other) const { 

                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot subtract measurements with different unit_base");
                
                return { this->value_ - other.value_as(this->units_), this->units_ }; 
            
            }
            

            /**
             * @brief Multiply this measurement by another measurement
             * 
             * @param other: measurement as l-value const reference
             * 
             * @return constexpr measurement 
             */
            constexpr measurement operator*(const measurement& other) const noexcept { 
                
                return { this->value_ * other.value_, this->units_ * other.units_ }; 
            
            }


            /**
             * @brief Multiply this measurement by another measurement
             * 
             * @param other: measurement as r-value reference
             * 
             * @return constexpr measurement 
             */
            constexpr measurement operator*(measurement&& other) const noexcept { 
                
                return { this->value_ * other.value_, this->units_ * other.units_ }; 
            
            }


            /**
             * @brief Divide this measurement by another measurement
             * 
             * @param other: measurement as l-value const reference
             * 
             * @return constexpr measurement 
             */
            constexpr measurement operator/(const measurement& other) const { 
                
                if (other.value_ == 0.0) 
                    throw std::runtime_error("Cannot divide a measurement by a zero measurement");
                
                return { this->value_ / other.value_, this->units_ / other.units_ }; 
            
            }


            /**
             * @brief Divide this measurement by another measurement
             * 
             * @param other: measurement as r-value reference
             * 
             * @return constexpr measurement 
             */
            constexpr measurement operator/(measurement&& other) const { 
                
                if (other.value_ == 0.0) 
                    throw std::runtime_error("Cannot divide a measurement by a zero measurement");
                
                return { this->value_ / other.value_, this->units_ / other.units_ }; 
            
            }


            /**
             * @brief Multiply this measurement and a scalar
             * 
             * @param scal: scalar as l-value const reference
             * 
             * @return constexpr measurement 
             */
            constexpr measurement operator*(const scalar& scal) const noexcept { 
                
                return { this->value_ * scal, this->units_ }; 
                
            }
            

            /**
             * @brief Multiply this measurement and a scalar
             * 
             * @param scal: scalar as r-value reference
             * 
             * @return constexpr measurement 
             */
            constexpr measurement operator*(scalar&& scal) const noexcept { 
                
                return { this->value_ * scal, this->units_ }; 
                
            }


            /**
             * @brief Divide this measurement and a scalar
             * 
             * @param scal: scalar as l-value const reference
             * 
             * @return constexpr measurement 
             */
            constexpr measurement operator/(const scalar& scal) const { 
                
                if (this->value_ == 0.0) 
                    throw std::runtime_error("Cannot divide a measurement by 0");
                
                return { this->value_ / scal, this->units_ }; 
                
            } 


            /**
             * @brief Divide this measurement and a scalar
             * 
             * @param scal: scalar as r-value reference
             * 
             * @return constexpr measurement 
             */
            constexpr measurement operator/(scalar&& scal) const { 
                
                if (this->value_ == 0.0) 
                    throw std::runtime_error("Cannot divide a measurement by 0");
                
                return { this->value_ / scal, this->units_ }; 
                
            } 


            /**
             * @brief Perform a product between a scalar and a measurement
             * 
             * @param scal: scalar as l-value const reference
             * @param meas: measurement as l-value const reference
             * 
             * @return constexpr measurement 
             */
            friend constexpr measurement operator*(const scalar& scal, 
                                                   const measurement& meas) noexcept { 
                                                
                return { scal * meas.value_, meas.units_ }; 
                
            }
            

            /**
             * @brief Perform a product between a scalar and a measurement
             * 
             * @param scal: scalar as r-value reference
             * @param meas: measurement as r-value reference
             * 
             * @return constexpr measurement 
             */
            friend constexpr measurement operator*(scalar&& scal, 
                                                   measurement&& meas) noexcept { 
                                                
                return { scal * meas.value_, meas.units_ }; 
                
            }


            /**
             * @brief Divide a scalar by a measurement
             * 
             * @param scal: scalar as l-value const reference
             * @param meas: measurement as l-value const reference
             * 
             * @return constexpr measurement 
             */
            friend constexpr measurement operator/(const scalar& scal, 
                                                   const measurement& meas) { 

                if (meas.value_ == 0.0) 
                    throw std::runtime_error("Cannot divide a scalar by a zero measurement");          
                
                return { scal / meas.value_, meas.units_.inv() }; 
                
            }


            /**
             * @brief Divide a scalar by a measurement
             * 
             * @param scal: scalar as r-value reference
             * @param meas: measurement as r-value reference
             * 
             * @return constexpr measurement 
             */
            friend constexpr measurement operator/(scalar&& scal, 
                                                   measurement&& meas) { 

                if (meas.value_ == 0.0) 
                    throw std::runtime_error("Cannot divide a scalar by a zero measurement");          
                
                return { scal / meas.value_, meas.units_.inv() }; 
                
            }

            
            /**
             * @brief Get the opposite of this measurement
             * 
             * @return constexpr measurement 
             */
            constexpr measurement operator-() const noexcept { 
                
                return { -this->value_, this->units_ }; 
            
            }


            /**
             * @brief Equality operator
             * 
             * @param other: measurement to compare as l-value const reference
             */
            constexpr bool operator==(const measurement& other) const noexcept { 
                
                return this->value_ == other.value_as(this->units_); 
                
            }

            
            /**
             * @brief Inequality operator
             * 
             * @param other: measurement to compare as l-value const reference
             */
            constexpr bool operator!=(const measurement& other) const noexcept { 
                
                return this->value_ != other.value_as(this->units_); 
                
            }
            
            
            /**
             * @brief More than operator
             * 
             * @param other: measurement to compare as l-value const reference
             */
            constexpr bool operator>(const measurement& other) const noexcept { 
                
                return this->value_ > other.value_as(this->units_); 
                
            }

            
            /**
             * @brief Less than operator
             * 
             * @param other: measurement to compare as l-value const reference
             */
            constexpr bool operator<(const measurement& other) const noexcept { 
                
                return this->value_ < other.value_as(this->units_); 
                
            }

            
            /**
             * @brief More than or equal operator
             * 
             * @param other: measurement to compare as l-value const reference
             */
            constexpr bool operator>=(const measurement& other) const noexcept { 
                
                return this->value_ > other.value_as(this->units_) ? true : this->value_ == other.value_as(this->units_);
                
            }

            
            /**
             * @brief Less than or equal operator
             * 
             * @param other: measurement to compare as l-value const reference 
             */
            constexpr bool operator<=(const measurement& other) const noexcept { 
                
                return this->value_ < other.value_as(this->units_) ? true : this->value_ == other.value_as(this->units_);
                
            }       


            /**
             * @brief Equality operator of value
             * 
             * @param scal: scalar as l-value const reference
             */
            constexpr bool operator==(const scalar& scal) const noexcept { 
                
                return this->value_ == scal; 
                
            }

            
            /**
             * @brief Inequality operator of value
             * 
             * @param scal: scalar as l-value const reference
             */
            constexpr bool operator!=(const scalar& scal) const noexcept { 
                
                return this->value_ != scal; 
                
            }
            
            
            /**
             * @brief More than with value
             * 
             * @param scal: scalar as l-value const reference 
             */
            constexpr bool operator>(const scalar& scal) const noexcept { 
                
                return this->value_ > scal; 
                
            }
            
            
            /**
             * @brief Less than with value
             * 
             * @param scal: scalar as l-value const reference 
             */
            constexpr bool operator<(const scalar& scal) const noexcept { 
                
                return this->value_ < scal; 
                
            }
            
            
            /**
             * @brief More than or equal with value
             * 
             * @param scal: scalar as l-value const reference 
             */
            constexpr bool operator>=(const scalar& scal) const noexcept { 
                
                return this->value_ >= scal; 
                
            }
            
            
            /**
             * @brief Less than or equal with value
             * 
             * @param scal: scalar as l-value const reference 
             */
            constexpr bool operator<=(const scalar& scal) const noexcept { 
                
                return this->value_ <= scal; 
                
            }


            /**
             * @brief Output operator for a measurement
             * 
             * @param os: std::ostream&
             * @param meas: measurement as l-value const reference
             * 
             * @return std::ostream&
             *  
             */
            friend std::ostream& operator<<(std::ostream& os, 
                                            const measurement& meas) noexcept { 
                
                os << meas.value_ << " " << meas.units_; 
                return os; 
                
            }


            /**
             * @brief Output operator for a measurement
             * 
             * @param file: std::ofstream&
             * @param meas: measurement as l-value const reference
             * 
             * @return std::ofstream&
             *  
             */
            friend std::ofstream& operator<<(std::ofstream& file,   
                                             const measurement& meas) noexcept { 
                
                file << meas.value_ << " " << meas.units_; 
                return file; 
                
            }


            /**
             * @brief Input operator for a measurement
             * 
             * @param is: std::istream&
             */
            friend std::istream& operator>>(std::istream& is, 
                                            measurement& meas) noexcept { 
                
                std::string unit_string; 
                is >> meas.value_ >> unit_string;
                meas.units_ = unit(unit_string);

                return is;

            }


        // =============================================
        // operations
        // ============================================= 

            /**
             * @brief Invert the measurement
             * 
             * @return constexpr measurement 
             * 
             * @note Cannot invert a measurement with a zero value
             */
            constexpr measurement inv() const { 
                
                if (this->value_ == 0) 
                    throw std::runtime_error("Cannot invert a measurement with a zero value");
                    
                return { 1 / this->value_, this->units_.inv() }; 
            
            }
            
            
            /**
             * @brief Get the absolute measurement object
             * 
             * @param meas: measurement as l-value const reference
             * @return constexpr measurement
             */
            friend constexpr measurement abs(const measurement& meas) noexcept { 
                
                return (meas.value_ < 0.0) ? -meas : meas; 
            
            }

            
            /**
             * @brief Take the power of the measurement
             * 
             * @param meas: measurement as l-value const reference
             * @param power: int as l-value const reference
             * 
             * @return measurement 
             */
            friend inline measurement pow(const measurement& meas, 
                                          const int& power) noexcept { 
                
                return { std::pow(meas.value_, power), meas.units_.pow(power) }; 
            
            }


            /**
             * @brief Take the root power of the measurement
             * 
             * @param meas: measurement as l-value const reference
             * @param power: int as l-value const reference
             * 
             * @return measurement 
             */
            friend inline measurement root(const measurement& meas, 
                                           const int& power) { 
                
                return { std::pow(meas.value_, 1.0 / power), meas.units_.root(power) }; 
            
            }


            /**
             * @brief Take the square of the measurement
             * 
             * @param meas: measurement as l-value const reference
             * 
             * @return constexpr measurement 
             */
            friend constexpr measurement square(const measurement& meas) noexcept { 
                
                return measurement(std::pow(meas.value_, 2), meas.units_.square()); 
            
            }

            
            /**
             * @brief Take the cube of the measurement
             * 
             * @param meas: measurement as l-value const reference
             * 
             * @return constexpr measurement 
             */
            friend constexpr measurement cube(const measurement& meas) noexcept { 
                
                return measurement(std::pow(meas.value_, 3), meas.units_.cube()); 
            
            }

            
            /**
             * @brief Take the square root of the measurement
             * 
             * @param meas: measurement as l-value const reference
             * 
             * @return measurement
             */
            friend inline measurement sqrt(const measurement& meas) { 
                
                if (meas.value_ < 0.0) 
                    throw std::runtime_error("Cannot take the square root of a negative measurement");
                
                return measurement(std::sqrt(meas.value_), meas.units_.sqrt()); 
            
            }

            
            /**
             * @brief Take the cubic root of the measurement
             * 
             * @param meas: measurement as l-value const reference
             * 
             * @return measurement
             */
            friend inline measurement cbrt(const measurement& meas) { 
                
                return measurement(std::cbrt(meas.value_), meas.units_.cbrt()); 
            
            }


            /**
             * @brief Take the exponential of a measurement
             * @note The base of the exponential is e
             * 
             * @param meas: measurement as l-value const reference
             * 
             * @return constexpr measurement
             */
            friend constexpr measurement exp(const measurement& meas) { 
                
                if (meas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the exponential of a measurement that is not unitless"); 
                
                return measurement(std::exp(meas.value_), unitless); 
            
            }


            /**
             * @brief Take the logarithm of a measurement
             * @note The base of the logarithm is e
             * 
             * @param meas: measurement as l-value const reference
             * 
             * @return constexpr measurement
             */
            friend constexpr measurement log(const measurement& meas) { 
                
                if (meas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the logarithm of a measurement that is not unitless"); 
                
                return measurement(std::log(meas.value_), unitless); 
            
            }
            

            /**
             * @brief Take the exponential base 10 of a measurement
             * 
             * @param meas: measurement as l-value const reference
             * 
             * @return constexpr measurement
             */
            friend constexpr measurement exp10(const measurement& meas) { 
                
                if (meas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the exponential of a measurement that is not unitless"); 
                
                return measurement(std::pow(10, meas.value_), unitless); 
            
            }


            /**
             * @brief Take the logarithm base 10 of a measurement
             * 
             * @param meas: measurement as l-value const reference
             * 
             * @return constexpr measurement
             */
            friend constexpr measurement log10(const measurement& meas) { 
                
                if (meas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the logarithm of a measurement that is not unitless"); 
                
                return measurement(std::log10(meas.value_), unitless); 
            
            }


            /**
             * @brief Take the sine of a measurement
             * 
             * @param meas: measurement as l-value const reference
             * 
             * @return constexpr measurement
             */
            friend constexpr measurement sin(const measurement& meas) { 
                
                if (meas.units_ != rad) 
                    throw std::runtime_error("Cannot take the sine of a measurement that is not in radians"); 
                
                return measurement(std::sin(meas.value_), unitless); 
            
            }


            /**
                * @brief Take the cosine of a measurement
                * 
                * @param meas: measurement as l-value const reference
                * 
                * @return constexpr measurement
                */
            friend constexpr measurement cos(const measurement& meas) { 
                
                if (meas.units_ != rad) 
                    throw std::runtime_error("Cannot take the cosine of a measurement that is not in radians"); 
                
                return measurement(std::cos(meas.value_), unitless); 
            
            }


            /**
                * @brief Take the tangent of a measurement
                * 
                * @param meas: measurement as l-value const reference
                * 
                * @return constexpr measurement
                */
            friend constexpr measurement tan(const measurement& meas) { 
                
                if (meas.units_ != rad) 
                    throw std::runtime_error("Cannot take the tangent of a measurement that is not in radians"); 
                
                return measurement(std::tan(meas.value_), unitless);

            }


            /**
                * @brief Take the arcsine of a measurement
                * 
                * @param meas: measurement as l-value const reference
                * 
                * @return constexpr measurement
                */
            friend constexpr measurement asin(const measurement& meas) { 
                
                if (meas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the arcsine of a measurement that is not unitless"); 
                
                return measurement(std::asin(meas.value_), rad);

            }


            /**
                * @brief Take the arccosine of a measurement
                * 
                * @param meas: measurement as l-value const reference
                * 
                * @return constexpr measurement
                */
            friend constexpr measurement acos(const measurement& meas) { 
                
                if (meas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the arccosine of a measurement that is not unitless"); 
                
                return measurement(std::acos(meas.value_), rad);

            }


            /**
                * @brief Take the arctangent of a measurement
                * 
                * @param meas: measurement as l-value const reference
                * 
                * @return constexpr measurement
                */
            friend constexpr measurement atan(const measurement& meas) { 
                
                if (meas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the arctangent of a measurement that is not unitless"); 
                
                return measurement(std::atan(meas.value_), rad);

            }


            /**
                * @brief Take the hyperbolic sine of a measurement
                * 
                * @param meas: measurement as l-value const reference
                * 
                * @return constexpr measurement
                */
            friend constexpr measurement sinh(const measurement& meas) { 
                
                if (meas.units_ != rad) 
                    throw std::runtime_error("Cannot take the hyperbolic sine of a measurement that is not in radians"); 
                
                return measurement(std::sinh(meas.value_), unitless);

            }


            /**
                * @brief Take the hyperbolic cosine of a measurement
                * 
                * @param meas: measurement as l-value const reference
                * 
                * @return constexpr measurement
                */
            friend constexpr measurement cosh(const measurement& meas) { 
                
                if (meas.units_ != rad) 
                    throw std::runtime_error("Cannot take the hyperbolic cosine of a measurement that is not in radians"); 
                
                return measurement(std::cosh(meas.value_), unitless);
            
            }


            /**
                * @brief Take the hyperbolic tangent of a measurement
                * 
                * @param meas: measurement as l-value const reference
                * 
                * @return constexpr measurement
                */
            friend constexpr measurement tanh(const measurement& meas) { 
                
                if (meas.units_ != rad) 
                    throw std::runtime_error("Cannot take the hyperbolic tangent of a measurement that is not in radians"); 
                
                return measurement(std::tanh(meas.value_), unitless);

            }


            /**
                * @brief Take the hyperbolic arcsine of a measurement
                * 
                * @param meas: measurement as l-value const reference
                * 
                * @return constexpr measurement
                */
            friend constexpr measurement asinh(const measurement& meas) { 
                
                if (meas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the hyperbolic arcsine of a measurement that is not unitless"); 
                
                return measurement(std::asinh(meas.value_), rad);

            }


            /**
                * @brief Take the hyperbolic arccosine of a measurement
                * 
                * @param meas: measurement as l-value const reference
                * 
                * @return constexpr measurement
                */
            friend constexpr measurement acosh(const measurement& meas) { 
                
                if (meas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the hyperbolic arccosine of a measurement that is not unitless"); 
                
                return measurement(std::acosh(meas.value_), rad);
            
            }


            /**
                * @brief Take the hyperbolic arctangent of a measurement
                * 
                * @param meas: measurement as l-value const reference
                * 
                * @return constexpr measurement
                */
            friend constexpr measurement atanh(const measurement& meas) { 
                
                if (meas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the hyperbolic arctangent of a measurement that is not unitless"); 
                
                return measurement(std::atanh(meas.value_), rad);

            }


        // =============================================                                                                                         
        // get methods
        // =============================================  

            /**
                * @brief Get the sign of the measurement 
                * 
                * @return constexpr int32_t
                */
            constexpr int32_t sign() const noexcept { 
                
                if (this->value_ == 0.) 
                    return 0; 

                else 
                    return (this->value_ > 0) ? 1 : -1; 
                
            }


            /**
                * @brief Get the value of the measurement
                * 
                * @return constexpr const scalar
                */
            constexpr scalar value() const noexcept { 
                
                return this->value_; 
            
            }                        
            
            
            /**
                * @brief Get the value of the measurement
                * 
                * @return constexpr scalar& 
                */
            constexpr scalar& value() noexcept { 
                
                return this->value_; 
            
            }  


            /**
            * @brief Get the value of the measurement expressed in another units of the measurement
            * 
            * @param desired_units 
            * 
            * @return constexpr scalar 
            */
            constexpr scalar value_as(const unit& desired_units) const { 
                
                return (this->units_ == desired_units) ? this->value_ : this->units_.convert(this->value_, desired_units); 
            
            }


            /**
            * @brief Get the units of the measurement
            * 
            * @return constexpr unit 
            */
            constexpr unit units() const noexcept { 
                
                return this->units_; 
            
            }


            /**
            * @brief Get the units of the measurement
            * 
            * @return constexpr unit&
            */
            constexpr unit& units() noexcept { 
                
                return this->units_; 
            
            }


            /**
            * @brief Get the measurement object
            * 
            * @return constexpr measurement 
            */
            constexpr measurement as_measurement() const noexcept {

                return *this; 

            }


            /**
            * @brief Get the measurement object
            * 
            * @return constexpr measurement&
            *  
            */
            constexpr measurement& as_measurement() noexcept {

                return *this; 

            }
        
            
            /**
            * @brief Convert the measurement to another units
            *
            * @param desired_units: desired unit of measurement 
            * 
            * @return constexpr measurement 
            */
            constexpr measurement convert_to(const unit& desired_units) const { 
                
                return { this->units_.convert(this->value_, desired_units), desired_units }; 
            
            }


            /**
            * @brief Print the measurement
            * 
            * @param newline: if set to true it prints a newline character at the end of the measurement
            */
            inline void print(const bool& newline = true) const noexcept { 

                std::cout << this->value_ << " " << this->units_;
                if (newline) 
                    std::cout << "\n"; 

            }


        protected:

        // =============================================                                                                                         
        // class members & friends
        // =============================================  

            scalar value_; ///< The numerical value of the measurement

            unit units_; ///< The units of the measurement


            friend class length_measurement; ///< length_measurement is a friend of measurement
            friend class time_measurement; ///< time_measurement is a friend of measurement
            friend class speed_measurement; ///< speed_measurement is a friend of measurement
            friend class acceleration_measurement; ///< acceleration_measurement is a friend of measurement
            friend class mass_measurement; ///< mass_measurement is a friend of measurement
            friend class force_measurement; ///< force_measurement is a friend of measurement
            friend class energy_measurement; ///< energy_measurement is a friend of measurement
            friend class angle_measurement; ///< angle_measurement is a friend of measurement


            friend class umeasurement; ///< umeasurement is a friend of measurement


    }; // class measurement
    

    /**
     * @brief Create a measurement by multiplying a scalar with an unit
     * 
     * @param scal: scalar as l-value const reference: scalar
     * @param units: unit
     * 
     * @return constexpr measurement 
     */
    constexpr measurement operator*(const scalar& val, 
                                    const unit& units) noexcept { 
                                        
        return measurement(val, units); 
        
    }

 
} // namespace measurements