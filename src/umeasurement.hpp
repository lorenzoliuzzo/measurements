/**
 * @file    umeasurement.hpp
 * @author  Lorenzo Liuzzo (lorenzoliuzzo@outlook.com)
 * @brief   This file contains the definition and implementation of the umeasurement class,
 *          with all its methods, operators and possibly operations.
 * @date    2022-12-31
 * 
 * @copyright Copyright (c) 2023
 */


#pragma once


namespace measurements {


    /** 
     * @brief A class for representing a physical quantity with a numerical value, an uncertanty and an unit
     * @see units::unit  
     */
    class umeasurement {     
        

        public: 

        // =============================================                                                                                         
        // constructors & destructor 
        // =============================================  

            /// @brief default constructor
            explicit constexpr umeasurement() noexcept = default;


            /**
             * @brief Construct a new umeasurement object
             * 
             * @param value: scalar value as l-value const reference
             * @param uncertainty: scalar uncertainty as l-value const reference
             * @param units: unit as l-value const reference
             * 
             * @note The uncertainty must be positive
             * @note The uncertainty must be expressed as the same unit of the measurement
             */
            constexpr umeasurement(const scalar& value, 
                                            const scalar& uncertainty, 
                                            const unit& units) {

                if (uncertainty < 0.0) 
                    throw std::invalid_argument("Cannot instantiate an umeasurement with a negative uncertainty");

                else {

                    this->value_ = value; 
                    this->uncertainty_ = uncertainty; 
                    this->units_ = units;
                
                }
                        
            }


            /**
             * @brief Construct a new umeasurement object
             * 
             * @param value: scalar value as r-value reference
             * @param uncertainty: scalar uncertainty as r-value reference
             * @param units: unit as r-value reference
             * 
             * @note The uncertainty must be positive
             * @note The uncertainty must be expressed as the same unit of the measurement
             */
            constexpr umeasurement(scalar&& value, 
                                            scalar&& uncertainty, 
                                            unit&& units) {

                if (uncertainty < 0.0) 
                    throw std::invalid_argument("Cannot instantiate an umeasurement with a negative uncertainty");

                else {

                    this->value_ = std::move(value); 
                    this->uncertainty_ = std::move(uncertainty); 
                    this->units_ = std::move(units);
                
                }
                        
            }


            /**
             * @brief Construct a new umeasurement object from a measurement and an uncertainty
             * 
             * @param other: measurement value and units as a l-value const reference
             * @param uncertainty: scalar uncertainty as a l-value const reference
             * 
             * @note The uncertainty must be positive
             * @note The uncertainty must be expressed as the same unit of the measurement
             * @note The uncertainty is set to zero by default
             */
            constexpr umeasurement(const measurement& other, 
                                            const scalar& uncertainty = 0.0) {

                if (uncertainty < 0.0) 
                    throw std::invalid_argument("Cannot instantiate an umeasurement with a negative uncertainty");

                else {

                    this->value_ = other.value_; 
                    this->uncertainty_ = uncertainty; 
                    this->units_ = other.units_;
                
                }

            }     


            /**
             * @brief Construct a new umeasurement object from a measurement and an uncertainty
             * 
             * @param other: measurement value and units as a r-value reference
             * @param uncertainty: scalar uncertainty as a r-value reference
             * 
             * @note The uncertainty must be positive
             * @note The uncertainty must be expressed as the same unit of the measurement
             * @note The uncertainty is set to zero by default
             */
            constexpr umeasurement(measurement&& other, 
                                            scalar&& uncertainty = 0.0) {

                if (uncertainty < 0.0) 
                    throw std::invalid_argument("Cannot instantiate an umeasurement with a negative uncertainty");

                else {

                    this->value_ = std::move(other.value_); 
                    this->uncertainty_ = std::move(uncertainty); 
                    this->units_ = std::move(other.units_);
                
                }

            }     


            /**
             * @brief Construct a new umeasurement object from two measurements
             * 
             * @param value: measurement as l-value const reference 
             * @param uncertainty: measurement as l-value const reference
             * 
             * @note The units of the two measurements must have the same base_unit
             * @note The uncertainty value must be positive
             * @note The uncertainty value will be converted to the same units of the value measurement
             */
            constexpr umeasurement(const measurement& value, 
                                            const measurement& uncertainty) {
                        
                if (value.units_.base_ != uncertainty.units_.base_) 
                    throw std::invalid_argument("Cannot instantiate an umeasurement with two measurements that have not the same base_unit");

                if (uncertainty.value_ < 0.0) 
                    throw std::invalid_argument("Cannot instantiate an umeasurement with a negative uncertainty");

                else {

                    this->value_ = value.value_; 
                    this->uncertainty_ = uncertainty.value_as(value.units_); 
                    this->units_ = value.units_;
                
                }

            }


            /**
             * @brief Construct a new umeasurement object from two measurements
             * 
             * @param value: measurement as r-value reference 
             * @param uncertainty: measurement as r-value reference
             * 
             * @note The units of the two measurements must have the same base_unit
             * @note The uncertainty value must be positive
             * @note The uncertainty value will be converted to the same units of the value measurement
             */
            constexpr umeasurement(measurement&& value, 
                                            measurement&& uncertainty) {
                        
                if (value.units_.base_ != uncertainty.units_.base_) 
                    throw std::invalid_argument("Cannot instantiate an umeasurement with two measurements that have not the same base_unit");

                if (uncertainty.value_ < 0.0) 
                    throw std::invalid_argument("Cannot instantiate an umeasurement with a negative uncertainty");

                else {

                    this->value_ = std::move(value.value_); 
                    this->uncertainty_ = std::move(uncertainty.value_as(value.units_)); 
                    this->units_ = std::move(value.units_);
                
                }

            }


            /**
             * @brief Copy construct a new umeasurement object
             * 
             * @param other: umeasurement as a l-value const reference
             */
            constexpr umeasurement(const umeasurement& other) noexcept :

                value_{other.value_},
                uncertainty_{other.uncertainty_},
                units_(other.units_) {}


            /**
             * @brief Move construct a new umeasurement object
             * 
             * @param other: umeasurement to move from as a r-value reference
             */
            constexpr umeasurement(umeasurement&& other) noexcept :

                value_{std::move(other.value_)},
                uncertainty_{std::move(other.uncertainty_)},
                units_(std::move(other.units_)) {}


            /// @brief default destructor
            ~umeasurement() = default;
            

        // =============================================                                                                                         
        // operators
        // =============================================  

            /**
             * @brief Copy assign a umeasurement from another umeasurement
             * 
             * @param other: umeasurement to copy as a l-value const reference
             * 
             * @return uncertai_measurement& 
             */
            constexpr umeasurement& operator=(const umeasurement& other) noexcept {
                
                this->value_ = other.value_;
                this->uncertainty_ = other.uncertainty_; 
                this->units_ = other.units_;

                return *this;

            }   


            /**
             * @brief Move assign a umeasurement from another umeasurement
             * 
             * @param other: umeasurement to move from as a r-value reference
             * 
             * @return uncertai_measurement& 
             */
            constexpr umeasurement& operator=(umeasurement&& other) noexcept {
                
                this->value_ = std::move(other.value_);
                this->uncertainty_ = std::move(other.uncertainty_); 
                this->units_ = std::move(other.units_);
                
                return *this;
                
            }   


            /**
             * @brief Copy assign a umeasurement from a measurement
             * 
             * @param other: umeasurement to copy as a l-value const reference
             * 
             * @return uncertai_measurement& 
             */
            constexpr umeasurement& operator=(const measurement& other) noexcept {
                
                this->value_ = other.value_;
                this->uncertainty_ = 0.0; 
                this->units_ = other.units_;

                return *this;

            }   


            /**
             * @brief Move assign a umeasurement from a measurement
             * 
             * @param other: umeasurement to move from as a r-value reference
             * 
             * @return uncertai_measurement& 
             */
            constexpr umeasurement& operator=(measurement&& other) noexcept {
                
                this->value_ = std::move(other.value_);
                this->uncertainty_ = 0.0; 
                this->units_ = std::move(other.units_);

                return *this;
                
            }   


            /**
             * @brief Compute a product and calculate the new uncertainties using the root sum of squares(rss) method
             * 
             * @param other: umeasurement to multiply with as a l-value const reference
             *  
             * @return umeasurement 
             */
            umeasurement operator*(const umeasurement& other) const noexcept {

                scalar tval1 = this->uncertainty_ / this->value_;
                scalar tval2 = other.uncertainty_ / other.value_;
                scalar nunc = std::sqrt(std::pow(tval1, 2) + std::pow(tval2, 2));
                scalar nval = this->value_ * other.value_;

                return { nval, std::fabs(nval) * nunc, this->units_ * other.units_ };

            }
    

            /**
             * @brief Compute a product and calculate the new uncertainties using the root sum of squares(rss) method
             * 
             * @param other: umeasurement to multiply with as a r-value reference
             *  
             * @return umeasurement 
             */
            umeasurement operator*(umeasurement&& other) const noexcept {

                scalar tval1 = this->uncertainty_ / this->value_;
                scalar tval2 = other.uncertainty_ / other.value_;
                scalar ntol = std::sqrt(std::pow(tval1, 2) + std::pow(tval2, 2));
                scalar nval = this->value_ * other.value_;

                return { nval, std::fabs(nval) * ntol, this->units_ * other.units_ };

            }
    

            /**
             * @brief Compute a product and calculate the new uncertainties using the simple method for uncertainty propagation
             * 
             * @param other: umeasurement to multiply with as a l-value const reference
             * 
             * @return umeasurement 
             */
            umeasurement simple_product(const umeasurement& other) const noexcept {
                
                scalar ntol = this->uncertainty_ / std::fabs(this->value_) + other.uncertainty_ / std::fabs(other.value_);
                scalar nval = this->value_ * other.value_;

                return { nval, std::fabs(nval) * ntol, this->units_ * other.units_ };
            
            }

            
            /**
             * @brief Compute a product and calculate the new uncertainties using the simple method for uncertainty propagation
             * 
             * @param other: umeasurement to multiply with as a r-value reference
             * 
             * @return umeasurement 
             */
            umeasurement simple_product(umeasurement&& other) const noexcept {
                
                scalar nunc = this->uncertainty_ / std::fabs(this->value_) + other.uncertainty_ / std::fabs(other.value_);
                scalar nval = this->value_ * other.value_;

                return { nval, std::fabs(nval) * nunc, this->units_ * other.units_ };
            
            }


            /**
             * @brief Compute a product with a measurement, equivalent to umeasurement multiplication with 0 uncertainty
             * 
             * @param other: measurement to multiply with as a l-value const reference
             *  
             * @return umeasurement 
             */
            inline umeasurement operator*(const measurement& other) const noexcept {
                
                return { this->value_ * other.value_, std::fabs(other.value_) * this->uncertainty_, this->units_ * other.units_ };
            
            }


            /**
             * @brief Compute a product with a measurement, equivalent to umeasurement multiplication with 0 uncertainty
             * 
             * @param other: measurement to multiply with as a r-value reference
             *  
             * @return umeasurement 
             */
            inline umeasurement operator*(measurement&& other) const noexcept {
                
                return { this->value_ * other.value_, std::fabs(other.value_) * this->uncertainty_, this->units_ * other.units_ };
            
            }


            /**
             * @brief Compute a product with a scalar and calculate the new uncertainties using the simple uncertainty multiplication method
             * 
             * @param val: the scalar to multiply with as a l-value const reference
             * 
             * @return umeasurement 
             */
            inline umeasurement operator*(const scalar& val) const noexcept { 
                
                return { val * this->value_, std::fabs(val) * this->uncertainty_, this->units_ }; 
            
            }


            /**
             * @brief Compute a product with a scalar and calculate the new uncertainties using the simple uncertainty multiplication method
             * 
             * @param val: the scalar to multiply with as a r-value reference
             * 
             * @return umeasurement 
             */
            inline umeasurement operator*(scalar&& val) const noexcept { 
                
                return { val * this->value_, std::fabs(val) * this->uncertainty_, this->units_ }; 
            
            }


            /**
             * @brief Compute a division and calculate the new uncertainties using the root sum of squares(rss) method
             * 
             * @param other: umeasurement to divide by as a l-value const reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement operator/(const umeasurement& other) const {
                
                if (other.value_ == 0.0) 
                    throw std::invalid_argument("Cannot divide umeasurement by 0");

                scalar tval1 = this->uncertainty_ / this->value_;
                scalar tval2 = other.uncertainty_ / other.value_;
                scalar ntol = std::sqrt(std::pow(tval1, 2) + std::pow(tval2, 2));
                scalar nval = this->value_ / other.value_;

                return { nval, std::fabs(nval) * ntol, this->units_ / other.units_ };
            
            }


            /**
             * @brief Compute a division and calculate the new uncertainties using the root sum of squares(rss) method
             * 
             * @param other: umeasurement to divide by as a r-value reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement operator/(umeasurement&& other) const {
                
                if (other.value_ == 0.0) 
                    throw std::invalid_argument("Cannot divide umeasurement by 0");

                scalar tval1 = this->uncertainty_ / this->value_;
                scalar tval2 = other.uncertainty_ / other.value_;
                scalar ntol = std::sqrt(std::pow(tval1, 2) + std::pow(tval2, 2));
                scalar nval = this->value_ / other.value_;

                return { nval, std::fabs(nval) * ntol, this->units_ / other.units_ };
            
            }


            /**
             * @brief Compute a division and calculate the new uncertainties using simple method for uncertainty propagation
             * 
             * @param other: umeasurement to divide by as a l-value const reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement simple_divide(const umeasurement& other) const {
                
                if (other.value_ == 0.0) 
                    throw std::invalid_argument("Cannot divide umeasurement by 0");

                scalar ntol = this->uncertainty_ / std::fabs(this->value_) + other.uncertainty_ / std::fabs(other.value_);
                scalar nval = this->value_ / other.value_;

                return { nval, std::fabs(nval) * ntol, this->units_ / other.units_ };
            
            }


            /**
             * @brief Compute a division and calculate the new uncertainties using simple method for uncertainty propagation
             * 
             * @param other: umeasurement to divide by as a r-value reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement simple_divide(umeasurement&& other) const {
                
                if (other.value_ == 0.0) 
                    throw std::invalid_argument("Cannot divide umeasurement by 0");

                scalar ntol = this->uncertainty_ / std::fabs(this->value_) + other.uncertainty_ / std::fabs(other.value_);
                scalar nval = this->value_ / other.value_;

                return { nval, std::fabs(nval) * ntol, this->units_ / other.units_ };
            
            }


            /**
             * @brief Compute a division with a measurement, equivalent to umeasurement division with 0 uncertainty
             * 
             * @param other: measurement to divide by as a l-value const reference 
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement operator/(const measurement& other) const {
                
                if (other.value_ == 0.0) 
                    throw std::invalid_argument("Cannot divide umeasurement by 0");

                return { this->value_ / other.value_, this->uncertainty_ / std::fabs(other.value_), this->units_ / other.units_ };
            
            }


            /**
             * @brief Compute a division with a measurement, equivalent to umeasurement division with 0 uncertainty
             * 
             * @param other: measurement to divide by as a r-value reference 
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement operator/(measurement&& other) const {
                
                if (other.value_ == 0.0) 
                    throw std::invalid_argument("Cannot divide umeasurement by 0");

                return { this->value_ / other.value_, this->uncertainty_ / std::fabs(other.value_), this->units_ / other.units_ };
            
            }


            /**
             * @brief Divide this umeasurement with a scalar
             * 
             * @param val: the scalar to divide with as a l-value const reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement operator/(const scalar& val) const {

                if (val == 0.0) 
                    throw std::invalid_argument("Cannot divide umeasurement by 0");

                return { this->value_ / val, this->uncertainty_ / std::fabs(val), this->units_ };
            
            }


            /**
             * @brief Divide this umeasurement with a scalar
             * 
             * @param val: the scalar to divide with as a r-value reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement operator/(scalar&& val) const {

                if (val == 0.0) 
                    throw std::invalid_argument("Cannot divide umeasurement by 0");

                return { this->value_ / val, this->uncertainty_ / std::fabs(val), this->units_ };
            
            }


            /**
             * @brief Compute an addition and calculate the new uncertainties using the root sum of squares(rss) method
             * 
             * @param other: umeasurement to sum with as a l-value const reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement operator+(const umeasurement& other) const {
                
                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot add umeasurements with different unit bases");

                scalar cval = other.units_.convertion_factor(this->units_);
                scalar ntol = std::sqrt(std::pow(this->uncertainty_, 2) + std::pow(cval * other.uncertainty_, 2));

                return { this->value_ + cval * other.value_, ntol, this->units_ };
            
            }


            /**
             * @brief Compute an addition and calculate the new uncertainties using the root sum of squares(rss) method
             * 
             * @param other: umeasurement to sum with as a r-value reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement operator+(umeasurement&& other) const {
                
                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot add umeasurements with different unit bases");

                scalar cval = other.units_.convertion_factor(this->units_);
                scalar ntol = std::sqrt(std::pow(this->uncertainty_, 2) + std::pow(cval * other.uncertainty_, 2));

                return { this->value_ + cval * other.value_, ntol, this->units_ };
            
            }


            /**
             * @brief Compute an addition and calculate the new uncertainties using the simple uncertainty summation method
             * 
             * @param other: umeasurement to sum with as a l-value const reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement simple_add(const umeasurement& other) const {
                
                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot add umeasurements with different unit bases");

                scalar cval = other.units_.convertion_factor(this->units_);
                scalar ntol = this->uncertainty_ + other.uncertainty_ * cval;

                return { this->value_ + cval * other.value_, ntol, this->units_ };
            
            }


            /**
             * @brief Compute an addition and calculate the new uncertainties using the simple uncertainty summation method
             * 
             * @param other: umeasurement to sum with as a r-value reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement simple_add(umeasurement&& other) const {
                
                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot add umeasurements with different unit bases");

                scalar cval = other.units_.convertion_factor(this->units_);
                scalar ntol = this->uncertainty_ + other.uncertainty_ * cval;

                return { this->value_ + cval * other.value_, ntol, this->units_ };
            
            }


            /**
             * @brief Compute an addition with a measurement and calculate the new uncertainties using the simple uncertainty summation method
             * 
             * @param other: measurement to sum with as a l-value const reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement operator+(const measurement& other) const {
                
                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot add umeasurement and measurement with different unit bases");

                return { this->value_ + other.value_as(this->units_), this->uncertainty_, this->units_ };
            
            }


            /**
             * @brief Compute an addition with a measurement and calculate the new uncertainties using the simple uncertainty summation method
             * 
             * @param other: measurement to sum with as a r-value reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement operator+(measurement&& other) const {
                
                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot add umeasurement and measurement with different unit bases");

                return { this->value_ + other.value_as(this->units_), this->uncertainty_, this->units_ };
            
            }


            /**
             * @brief Return the opposite of this umeasurement
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement operator-() const noexcept {

                return { -this->value_, this->uncertainty_, this->units_ };
            
            }
            

            /**
             * @brief Compute a subtraction and calculate the new uncertainties using the root sum of squares(rss) method
             * 
             * @param other: umeasurement to subtract with as a l-value const reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement operator-(const umeasurement& other) const {
                
                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot subtract umeasurements with different unit bases");

                scalar cval = other.units_.convertion_factor(this->units_);
                scalar ntol = std::sqrt(std::pow(this->uncertainty_, 2) + std::pow(cval * other.uncertainty_, 2));

                return { this->value_ - cval * other.value_, ntol, this->units_ };
            
            }


            /**
             * @brief Compute a subtraction and calculate the new uncertainties using the root sum of squares(rss) method
             * 
             * @param other: umeasurement to subtract with as a r-value reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement operator-(umeasurement&& other) const {
                
                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot subtract umeasurements with different unit bases");

                scalar cval = other.units_.convertion_factor(this->units_);
                scalar ntol = std::sqrt(std::pow(this->uncertainty_, 2) + std::pow(cval * other.uncertainty_, 2));

                return { this->value_ - cval * other.value_, ntol, this->units_ };
            
            }


            /**
             * @brief Compute a subtraction and calculate the new uncertainties using the simple uncertainty summation method
             * 
             * @param other: umeasurement to subtract with as a l-value const reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement simple_subtract(const umeasurement& other) const {
                
                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot subtract umeasurements with different unit bases");

                scalar cval = other.units_.convertion_factor(this->units_);
                scalar ntol = this->uncertainty_ + other.uncertainty_ * cval;

                return { this->value_ - cval * other.value_, ntol, this->units_ };
            
            }


            /**
             * @brief Compute a subtraction and calculate the new uncertainties using the simple uncertainty summation method
             * 
             * @param other: umeasurement to subtract with as a r-value reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement simple_subtract(umeasurement&& other) const {
                
                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot subtract umeasurements with different unit bases");

                scalar cval = other.units_.convertion_factor(this->units_);
                scalar ntol = this->uncertainty_ + other.uncertainty_ * cval;

                return { this->value_ - cval * other.value_, ntol, this->units_ };
            
            }

            
            /**
             * @brief Compute a subtraction with a measurement and calculate the new uncertainties using the simple uncertainty summation method
             * 
             * @param other: measurement to subtract with as a l-value const reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement operator-(const measurement& other) const {

                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot subtract umeasurement and measurement with different unit bases");

                return { this->value_ - other.value_as(this->units_), this->uncertainty_, this->units_ };
            
            }


            /**
             * @brief Compute a subtraction with a measurement and calculate the new uncertainties using the simple uncertainty summation method
             * 
             * @param other: measurement to subtract with as a r-value reference
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement operator-(measurement&& other) const {

                if (this->units_.base_ != other.units_.base_) 
                    throw std::invalid_argument("Cannot subtract umeasurement and measurement with different unit bases");

                return { this->value_ - other.value_as(this->units_), this->uncertainty_, this->units_ };
            
            }


            /**
             * @brief Equality operator between umeasurement and measurement
             * 
             * @param other: measurement to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator==(const measurement& other) const noexcept {
                
                if (this->uncertainty_ == 0.0) 
                    return this->value_ == other.value_as(this->units_); 
                
                else 
                    return (other.value_as(this->units_) >= (this->value_ - this->uncertainty_) && other.value_as(this->units_) <= (this->value_ + this->uncertainty_));
            
            }


            /**
             * @brief Equality operator
             * 
             * @param other: umeasurement to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator==(const umeasurement& other) const noexcept { 
                
                return this->simple_subtract(other) == measurement(0.0, this->units_); 
                
            }


            /**
             * @brief Inequality operator between umeasurement and measurement
             * 
             * @param other: measurement to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator!=(const measurement& other) const noexcept { 
                
                return !operator==(other); 
                
            }


            /**
             * @brief Inequality operator
             * 
             * @param other: umeasurement to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator!=(const umeasurement& other) const noexcept { 
                
                return !operator==(other); 
                
            }

            
            /**
             * @brief More than operator
             * 
             * @param other: umeasurement to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator>(const umeasurement& other) const noexcept { 
                
                return this->value_ > other.value_as(this->units_); 
                
            }

            
            /**
             * @brief More than operator
             * 
             * @param other: measurement to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator>(const measurement& other) const noexcept { 
                
                return this->value_ > other.value_as(this->units_); 
                
            }


            /** 
             * @brief More than operator
             * 
             * @param val: scalar to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator>(const scalar& val) const noexcept { 
                
                return this->value_ > val; 
                
            }

            
            /**
             * @brief Less than operator
             * 
             * @param other: umeasurement to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator<(const umeasurement& other) const noexcept { 
                
                return this->value_ < other.value_as(this->units_); 
                
            }
            
            
            /**
             * @brief Less than operator
             * 
             * @param other: measurement to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator<(const measurement& other) const noexcept { 
                
                return this->value_ < other.value_as(this->units_); 
                
            }

            
            /**
             * @brief Less than operator
             * 
             * @param val: scalar to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator<(const scalar& val) const noexcept { 
                
                return this->value_ < val; 
                
            }

            
            /**
             * @brief More than or equal operator
             * 
             * @param other: umeasurement to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator>=(const umeasurement& other) const noexcept {
                
                return this->simple_subtract(other).value_ >= 0.0;
            
            }


            /**
             * @brief More than or equal operator
             * 
             * @param other: measurement to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator>=(const measurement& other) const noexcept {
                
                return this->value_ >= other.value_as(this->units_); 
            
            }


            /**
             * @brief More than or equal operator
             * 
             * @param val: scalar to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator>=(const scalar& val) const noexcept { 

                return this->value_ >= val; 
                
            }


            /**
             * @brief Less than or equal operator
             * 
             * @param other: umeasurement to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator<=(const umeasurement& other) const noexcept {
                
                return this->simple_subtract(other).value_ <= 0.0; 
            
            }


            /**
             * @brief Less than or equal operator
             * 
             * @param other: measurement to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator<=(const measurement& other) const noexcept {
                
                return (this->value_ <= other.value_as(this->units_)); 
            
            }


            /**
             * @brief Less than or equal operator
             * 
             * @param val: scalar to compare as l-value const reference
             * 
             * @return bool
             */
            constexpr bool operator<=(const scalar& val) const noexcept { 

                return this->value_ <= val; 
                
            }

            
            /**
             * @brief Perform a product between a measurement and an umeasurement
             * 
             * @param meas: measurement as l-value const reference
             * @param umeas: umeasurement
             *  
             * @return umeasurement 
             */
            friend inline umeasurement operator*(const measurement& meas, 
                                                 const umeasurement& umeas) noexcept { 
                                
                return umeas.operator*(meas); 
                            
            }


            /**
             * @brief Perform a product between a scalar and an umeasurement
             * 
             * @param value: scalar
             * @param umeas: umeasurement
             * 
             * @return umeasurement 
             */
            friend inline umeasurement operator*(const scalar& value, 
                                          const umeasurement& umeas) noexcept { 
                                
                return umeas.operator*(value); 
                            
            }


            /**
             * @brief Perform a division between a measurement and an umeasurement
             * 
             * @param meas: measurement
             * @param umeas: umeasurement
             *  
             * @return constexpr umeasurement 
             */
            friend constexpr umeasurement operator/(const measurement& meas, 
                                                             const umeasurement& umeas) {
                                                        
                if (umeas.value_ == 0.0) 
                    throw std::runtime_error("Cannot divide a measurement by a zero umeasurement");

                scalar ntol = umeas.uncertainty_ / umeas.value_;
                scalar nval = meas.value() / umeas.value_;

                return umeasurement(nval, std::fabs(nval * ntol), meas.units() / umeas.units_);
            
            }


            /**
             * @brief Perform a division between a scalar and an umeasurement
             * 
             * @param value: scalar
             * @param umeas: umeasurement
             * 
             * @return constexpr umeasurement 
             */
            friend constexpr umeasurement operator/(const scalar& v1, 
                                                             const umeasurement& umeas) {

                if (umeas.value_ == 0.0) 
                    throw std::runtime_error("Cannot divide a scalar by a zero umeasurement");

                scalar ntol = umeas.uncertainty_ / umeas.value_;
                scalar nval = v1 / umeas.value_;
                return umeasurement(nval, std::fabs(nval * ntol), umeas.units_.inv());
            
            }

            
            /**
             * @brief Perform a sum between a measurement and an umeasurement
             * 
             * @param meas: measurement as l-value const reference
             * @param umeas: umeasurement
             *  
             * @return constexpr umeasurement 
             */
            friend constexpr umeasurement operator+(const measurement& meas, 
                                                             const umeasurement& umeas) {
                
                if (meas.units().base_ != umeas.units_.base_) 
                    throw std::invalid_argument("Cannot sum measurement and umeasurement with different unit bases");

                scalar cval = umeas.units_.convertion_factor(meas.units());
                scalar ntol = umeas.uncertainty_ * cval;

                return umeasurement(meas.value() + cval * umeas.value_, ntol, meas.units());
            
            }


            /**
             * @brief Perform a subtraction between a measurement and an umeasurement
             * 
             * @param meas: measurement 
             * @param umeas: umeasurement
             *  
             * @return constexpr umeasurement 
             */
            friend constexpr umeasurement operator-(const measurement& meas, 
                                                             const umeasurement& umeas) {

                if (meas.units().base_ != umeas.units_.base_) 
                    throw std::invalid_argument("Cannot sum measurement and umeasurement with different unit bases");

                scalar cval = umeas.units_.convertion_factor(meas.units());
                scalar ntol = umeas.uncertainty_ * cval;

                return umeasurement(meas.value() - cval * umeas.value_, ntol, meas.units());
            
            }


            /**
             * @brief Equality operator between a measurement and an umeasurement
             * 
             * @param meas: measurement
             * @param umeas: umeasurement
             * 
             * @return bool
             */
            friend constexpr bool operator==(const measurement& meas, 
                                             const umeasurement& umeas) noexcept { 
                
                return umeas == meas; 
            
            }


            /**
             * @brief Inequality operator between a measurement and an umeasurement
             * 
             * @param meas: measurement
             * @param umeas: umeasurement
             * 
             * @return bool
             */
            friend constexpr bool operator!=(const measurement& meas, 
                                             const umeasurement& umeas) noexcept { 
                
                return umeas != meas; 
            
            }
            

            /**
             * @brief More operator between a measurement and an umeasurement
             * 
             * @param meas: measurement
             * @param umeas: umeasurement
             * 
             * @return bool
             */
            friend constexpr bool operator>(const measurement& meas, 
                                            const umeasurement& umeas) noexcept { 
                
                return meas.value() > umeas.value_; 
            
            }
            

            /**
             * @brief Less operator between a measurement and an umeasurement
             * 
             * @param meas: measurement
             * @param umeas: umeasurement
             * 
             * @return bool
             */
            friend constexpr bool operator<(const measurement& meas, 
                                            const umeasurement& umeas) noexcept { 
                
                return meas.value() < umeas.value_; 
            
            }
            

            /**
             * @brief More or equal operator between a measurement and an umeasurement
             * 
             * @param meas: measurement
             * @param umeas: umeasurement
             * 
             * @return bool
             */
            friend constexpr bool operator>=(const measurement& meas, 
                                             const umeasurement& umeas) noexcept { 
                
                return (meas > umeas) ? true : (umeas == meas); 
            
            }
            

            /**
            * @brief Less or equal operator between a measurement and an umeasurement
            * 
            * @param meas: measurement
            * @param umeas: umeasurement
            * 
            * @return bool
            * 
            */
            friend constexpr bool operator<=(const measurement& meas, 
                                             const umeasurement& umeas) noexcept { 
                
                return (meas < umeas) ? true : (umeas == meas); 
            
            }
    

            /**
             * @brief Output operator for a umeasurement
             * 
             * @param os: std::ostream&
             * @param meas: umeasurement as l-value const reference
             * 
             * @note if the precision of the umeasurement is 0, the uncertainty is not printed
             * @note scientific notation is used if the value is greater than 1e4 or less than 1e-4
             * 
             * @return std::ostream&
             */
            friend std::ostream& operator<<(std::ostream& os, const umeasurement& umeas) noexcept { 

                scalar abs_value = std::fabs(umeas.value_);
                
                // first significative digit positions
                int32_t n_val = ((umeas.uncertainty_ >= 1) ? 
                                    std::ceil(std::log10(abs_value)) : 
                                    ((abs_value >= 1) ? 
                                        std::ceil(std::log10(abs_value)) : 
                                        std::floor(std::log10(abs_value)))); 

                int32_t n_unc = ((umeas.uncertainty_ >= 1) ? 
                                    std::ceil(std::log10(umeas.uncertainty_)) : 
                                    std::floor(std::log10(umeas.uncertainty_))); 

                int32_t prec = (n_unc > n_val) ? 0 : n_val - n_unc; 

                bool scientific_notation_needed = (abs_value >= 1e4) || 
                                                    (abs_value <= 1e-4) || 
                                                    (umeas.uncertainty_ >= 1e4) || 
                                                    (umeas.uncertainty_ <= 1e-4);

                // check if the uncertainty needs to be printed
                if (umeas.uncertainty_ == 0.0) 
                    os << umeas.as_measurement(); 
                
                // check if scientific notation is needed
                if (scientific_notation_needed) {

                    os << std::scientific; 
                    os << std::setprecision(prec) << "(" << umeas.value_ << " ± "; 
                    os << std::setprecision(0) << umeas.uncertainty_ << ") " << umeas.units_;

                } else {

                    os << std::fixed; 

                    if (umeas.uncertainty_ >= 1.) 
                        os << std::setprecision(0); 
                    else 
                        os << std::setprecision(std::fabs(n_unc)); 
                        
                    os << "(" << umeas.value_ << " ± " << umeas.uncertainty_ << ") " << umeas.units_;

                }

                os << std::defaultfloat << std::setprecision(6);
                
                return os; 
                
            }


            /**
             * @brief Output operator for a umeasurement
             * 
             * @param file: std::ofstream&
             * @param meas: umeasurement as l-value const reference
             * 
             * @return std::ofstream&
             */
            friend std::ofstream& operator<<(std::ofstream& file, const umeasurement& umeas) noexcept { 

                file << umeas.value_ << '\t' << umeas.uncertainty_ << '\t' << umeas.units_;
                
                return file; 
                
            }


            /**
             * @brief Input operator for a umeasurement
             * 
             * @param file: std::ifstream&
             * @param meas: umeasurement as l-value reference
             * 
             * @return std::ifstream&
             */
            friend std::ifstream& operator>>(std::ifstream& file, umeasurement& umeas) noexcept { 

                std::string unit_string; 
                file >> umeas.value_ >> umeas.uncertainty_ >> unit_string; 
                umeas.units_ = unit(unit_string);

                return file;
            
            }
            

        // =============================================
        // operations
        // ============================================= 

            /**
             * @brief Get the absolute umeasurement object
             * 
             * @param umeas: umeasurement
             * 
             * @return constexpr umeasurement
             */
            friend constexpr umeasurement abs(const umeasurement& umeas) noexcept { 
                
                return (umeas.value_ < 0.0) ? -umeas : umeas; 
            
            }


            /**                  
             * @brief Invert the umeasurement
             * 
             * @return constexpr umeasurement 
             * 
             * @note Cannot invert an umeasurement with a zero value
             * @note The uncertainty is not inverted
             */
            constexpr umeasurement inv() const { 
                
                if (this->value_ == 0) 
                    throw std::runtime_error("Cannot invert an umeasurement with a zero value");

                return { 1 / this->value_, this->uncertainty_ / std::pow(this->value_, 2), this->units_.inv() };
                
            } 


            /**                  
             * @brief Invert the umeasurement
             * 
             * @param umeas: umeasurement as l-value const reference
             * 
             * @return constexpr umeasurement 
             * 
             * @note Cannot invert an umeasurement with a zero value
             * @note The uncertainty is not inverted
             */
            friend constexpr umeasurement inv(const umeasurement& umeas) { 
                
                if (umeas.value_ == 0) 
                    throw std::runtime_error("Cannot invert an umeasurement with a zero value");

                return { 1 / umeas.value_, umeas.uncertainty_ / std::pow(umeas.value_, 2), umeas.units_.inv() };
                
            } 


            /**
             * @brief Take the power of the umeasurement
             * 
             * @param power 
             * 
             * @return umeasurement 
             */
            inline umeasurement pow(const int& power) const noexcept { 
                
                return { std::pow(this->value_, power), std::fabs(power * std::pow(this->value_, power - 1)) * this->uncertainty_, this->units_.pow(power) };
                
            }


            /**
             * @brief Take the power of the umeasurement
             * 
             * @param umeas: umeasurement as l-value const reference
             * @param power: int as l-value const reference
             * 
             * @return umeasurement 
             */
            friend inline umeasurement pow(const umeasurement& umeas, const int& power) noexcept { 
                
                return { std::pow(umeas.value_, power), std::fabs(power * std::pow(umeas.value_, power - 1)) * umeas.uncertainty_, umeas.units_.pow(power) };
                
            }
            
            
            /**
             * @brief Take the square of the umeasurement
             * 
             * @return umeasurement 
             */
            friend inline umeasurement square(const umeasurement& umeas) noexcept { 
                
                return { std::pow(umeas.value_, 2), 2. * std::fabs(umeas.value_) * umeas.uncertainty_, umeas.units_.square() }; 
                
            }

            
            /**
             * @brief Take the cube of the umeasurement
             * 
             * @return constexpr umeasurement 
             */
            friend constexpr umeasurement cube(const umeasurement& umeas) noexcept { 
                
                return { std::pow(umeas.value_, 3), 3. * std::pow(umeas.value_, 2) * umeas.uncertainty_, umeas.units_.cube() };
                
            }

            
            /**
             * @brief Take the root power of the umeasurement
             * 
             * @param power 
             * 
             * @return umeasurement 
             */
            inline umeasurement root(const int& power) const { 
                
                return { std::pow(this->value_, 1.0 / power), std::fabs(std::pow(this->value_, 1.0 / power - 1)) * this->uncertainty_ / power, this->units_.root(power) }; 
                
            }


            /**
             * @brief Take the root power of the umeasurement
             * 
             * @param umeas: umeasurement as l-value const reference
             * @param power: int as l-value const reference
             * 
             * @return umeasurement 
             */
            friend inline umeasurement root(const umeasurement &umeas, const int& power) { 
                
                return { std::pow(umeas.value_, 1.0 / power), std::fabs(std::pow(umeas.value_, 1.0 / power - 1)) * umeas.uncertainty_ / power, umeas.units_.root(power) }; 
                
            }


            /**
             * @brief Take the square root of the umeasurement
             * 
             * @return umeasurement
             */
            friend inline umeasurement sqrt(const umeasurement& umeas) { 
                
                return { std::sqrt(umeas.value_), umeas.uncertainty_ / (2. * std::sqrt(umeas.value_)), umeas.units_.sqrt() }; 
                
            }


            /**
             * @brief Take the cubic root of the umeasurement
             * 
             * @return umeasurement
             */                
            friend inline umeasurement cbrt(const umeasurement& umeas) { 
                
                return { std::cbrt(umeas.value_), std::pow(umeas.value_, - 2. / 3.) * umeas.uncertainty_ / 3., umeas.units_.cbrt() };
                
            }


            /**
             * @brief Take the sine of an umeasurement
             * 
             * @param umeas: umeasurement 
             * 
             * @return constexpr measurement
             */
            friend constexpr umeasurement sin(const umeasurement& umeas) { 
                
                if (umeas.units_ != rad) 
                    throw std::runtime_error("Cannot take the sine of an umeasurement that is not in radians"); 

                return { std::sin(umeas.value_), std::fabs(std::cos(umeas.value_)) * umeas.uncertainty_, unitless };
            
            }


            /**
             * @brief Take the cosine of an umeasurement
             * 
             * @param umeas: umeasurement 
             * 
             * @return constexpr measurement
             */
            friend constexpr umeasurement cos(const umeasurement& umeas) { 
                
                if (umeas.units_ != rad) 
                    throw std::runtime_error("Cannot take the cosine of an umeasurement that is not in radians"); 

                return { std::cos(umeas.value_), std::fabs(-std::sin(umeas.value_)) * umeas.uncertainty_, unitless };
            
            }


            /**
             * @brief Take the tangent of an umeasurement
             * 
             * @param umeas: umeasurement 
             * 
             * @return constexpr measurement
             */
            friend constexpr umeasurement tan(const umeasurement& meas) { 
                
                if (meas.units_ != rad) 
                    throw std::runtime_error("Cannot take the tangent of an umeasurement that is not in radians");

                
                return { std::tan(meas.value_), (1 + std::pow(meas.value_, 2)) * meas.uncertainty_, unitless };

            }


            /**
             * @brief Take the arcsine of an umeasurement
             * 
             * @param umeas: umeasurement
             * 
             * @return constexpr measurement
             */
            friend constexpr umeasurement asin(const umeasurement& umeas) { 
                
                if (umeas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the arcsine of an umeasurement that is not unitless"); 
                
                return { std::asin(umeas.value_), umeas.uncertainty_ / std::sqrt(1 - std::pow(umeas.value_, 2)), rad };

            }


            /**
             * @brief Take the arccosine of an umeasurement
             * 
             * @param umeas: umeasurement
             * 
             * @return constexpr measurement
             */
            friend constexpr umeasurement acos(const umeasurement& umeas) { 
                
                if (umeas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the arccosine of an umeasurement that is not unitless"); 
                
                return { std::acos(umeas.value_), umeas.uncertainty_ / std::sqrt(1 - std::pow(umeas.value_, 2)), rad };

            }


            /**
             * @brief Take the arctangent of an umeasurement
             * 
             * @param umeas: umeasurement
             * 
             * @return constexpr measurement
             */
            friend constexpr umeasurement atan(const umeasurement& umeas) { 
                
                if (umeas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the arctangent of an umeasurement that is not unitless"); 
                
                return { std::atan(umeas.value_), umeas.uncertainty_ / (1 + std::pow(umeas.value_, 2)), rad };

            }


            /**
             * @brief Take the hyperbolic sine of an umeasurement
             * 
             * @param umeas: umeasurement
             * 
             * @return constexpr measurement
             */
            friend constexpr umeasurement sinh(const umeasurement& umeas) { 
                
                if (umeas.units_ != rad) 
                    throw std::runtime_error("Cannot take the hyperbolic sine of an umeasurement that is not in radians"); 
                
                return { std::sinh(umeas.value_), std::cosh(umeas.value_) * umeas.uncertainty_, unitless };

            }


            /**
             * @brief Take the hyperbolic cosine of an umeasurement
             * 
             * @param umeas: umeasurement
             * 
             * @return constexpr measurement
             */
            friend constexpr umeasurement cosh(const umeasurement& umeas) { 
                
                if (umeas.units_ != rad) 
                    throw std::runtime_error("Cannot take the hyperbolic cosine of an umeasurement that is not in radians"); 
                
                return { std::cosh(umeas.value_), std::fabs(std::sinh(umeas.value_)) * umeas.uncertainty_, unitless };
            
            }


            /**
             * @brief Take the hyperbolic tangent of an umeasurement
             * 
             * @param umeas: umeasurement
             * 
             * @return constexpr measurement
             */
            friend constexpr umeasurement tanh(const umeasurement& umeas) { 
                
                if (umeas.units_ != rad) 
                    throw std::runtime_error("Cannot take the hyperbolic tangent of an umeasurement that is not in radians"); 
                
                return { std::tanh(umeas.value_), std::fabs((1 - std::pow(umeas.value_, 2))) * umeas.uncertainty_, unitless };

            }


            /**
             * @brief Take the hyperbolic arcsine of an umeasurement
             * 
             * @param umeas: umeasurement
             * 
             * @return constexpr measurement
             */
            friend constexpr umeasurement asinh(const umeasurement& umeas) { 
                
                if (umeas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the hyperbolic arcsine of an umeasurement that is not unitless"); 
                
                return { std::asinh(umeas.value_), umeas.uncertainty_ / std::sqrt(std::pow(umeas.value_, 2) + 1), rad };

            }


            /**
             * @brief Take the hyperbolic arccosine of an umeasurement
             * 
             * @param umeas: umeasurement
             * 
             * @return constexpr measurement
             */
            friend constexpr umeasurement acosh(const umeasurement& umeas) { 
                
                if (umeas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the hyperbolic arccosine of an umeasurement that is not unitless"); 
                
                return { std::acosh(umeas.value_), umeas.uncertainty_ / std::fabs(std::sqrt(std::pow(umeas.value_, 2) - 1)), rad };
            
            }


            /**
             * @brief Take the hyperbolic arctangent of an umeasurement
             * 
             * @param umeas: umeasurement
             * 
             * @return constexpr measurement
             */
            friend constexpr umeasurement atanh(const umeasurement& umeas) { 
                
                if (umeas.units_ != unitless) 
                    throw std::runtime_error("Cannot take the hyperbolic arctangent of an umeasurement that is not unitless"); 
                
                return { std::atanh(umeas.value_), umeas.uncertainty_ / std::fabs(std::sqrt(1 - std::pow(umeas.value_, 2))), rad };

            }


        // =============================================                                                                                         
        // set & get methods
        // =============================================  
            
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
             * @return constexpr scalar 
             */
            constexpr scalar value_as(const unit& desired_units) const { 
                
                return (this->units_ == desired_units) ? this->value_ : this->units_.convert(this->value_, desired_units); 
            
            }


            /**
             * @brief Cast to a measurement
             * 
             * @return measurement 
             */
            constexpr measurement as_measurement() const noexcept { 
                
                return { this->value_, this->units_ };
                
            }


            /**
             * @brief Get the uncertainty of the measurement
             * 
             * @return constexpr const scalar
             */
            constexpr scalar uncertainty() const noexcept { 
                
                return this->uncertainty_; 
            
            }                        
            
            
            /**
             * @brief Get the uncertainty of the measurement
             * 
             * @return constexpr scalar& 
             */
            constexpr scalar& uncertainty() noexcept { 
                
                return this->uncertainty_; 
            
            }  


            /**
             * @brief Get the uncertainty of the measurement expressed in another units of the measurement
             * 
             * @param desired_units: unit desired as l-value const reference
             * @return constexpr scalar 
             */
            constexpr scalar uncertainty_as(const unit& desired_units) const { 
                
                return (this->units_ == desired_units) ? this->uncertainty_ : this->units_.convert(this->uncertainty_, desired_units); 
            
            }


            /**
             * @brief Get the relative uncertainty of the measurement
             * 
             * @return constexpr scalar
             */
            constexpr scalar relative_uncertainty() const noexcept { 
                
                return this->uncertainty_ / this->value_;

            }


            /**
             * @brief Get the weight of the measurement
             * 
             * @return constexpr measurement 
             */
            constexpr measurement weight() const {
                    
                return square(this->uncertainty_as_measurement().inv());

            }


            /**
             * @brief Get the uncertainty as a separate measurement
             * 
             * @return constexpr measurement 
             */
            constexpr measurement uncertainty_as_measurement() const noexcept { 
                
                return { this->uncertainty_, this->units_ }; 
            
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
             * @brief Get the umeasurement object
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement as_umeasurement() const noexcept {

                return *this; 

            }


            /**
             * @brief Get the umeasurement object
             * 
             * @return constexpr umeasurement&
             */
            constexpr umeasurement& as_umeasurement() noexcept {

                return *this; 

            }


            /**
             * @brief Add uncertainty to the umeasurement
             * 
             * @param uncertainty: scalar
             * 
             * @return void
             */
            inline void add_uncertainty(const scalar new_uncertainty) noexcept { 
                
                this->uncertainty_ = std::sqrt(std::pow(this->uncertainty_, 2) + std::pow(new_uncertainty, 2));

            }


            /**
             * @brief Convert the umeasurement to another units
             * 
             * @param desired_units: desired unit of measurement 
             * 
             * @return constexpr umeasurement 
             */
            constexpr umeasurement convert_to(const unit& newUnits) const noexcept {

                scalar cval = this->units_.convertion_factor(newUnits);

                return umeasurement(cval * this->value_, this->uncertainty_ * cval, newUnits);

            }


            /**
             * @brief Print the measurement to a ostream
             * 
             * @param newLine: bool
             * 
             * @return void
             */
            void print(const bool& newline = true) const noexcept { 

                std::cout << *this; 
                if (newline) 
                    std::cout << "\n";

            }


        private:

        // =============================================                                                                                         
        // class members
        // =============================================  

            scalar value_{}; ///< the numerical value of the measurement
            
            scalar uncertainty_{}; ///< the uncertainty of the measurement

            unit units_; ///< the units of the measurement


            friend class length_umeasurement; ///< length_umeasurement is a friend of umeasurement
            friend class time_umeasurement; ///< time_umeasurement is a friend of umeasurement
            friend class speed_umeasurement; ///< speed_umeasurement is a friend of umeasurement
            friend class acceleration_umeasurement; ///< acceleration_umeasurement is a friend of umeasurement
            friend class mass_umeasurement; ///< mass_umeasurement is a friend of umeasurement
            friend class force_umeasurement; ///< force_umeasurement is a friend of umeasurement
            friend class energy_umeasurement; ///< energy_umeasurement is a friend of umeasurement
            friend class angle_umeasurement; ///< angle_umeasurement is a friend of umeasurement


    }; // class umeasurement
    
    
} // namespace measurements