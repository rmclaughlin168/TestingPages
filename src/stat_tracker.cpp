/** @file stat_tracker.cpp
 *    This file contains a class for calculating the average
 *    and standard deviation of a data set containing floats,
 *    32-bit signed integers and 32-bit unsigned integers.
 * 
 *  @author Ryan McLaughlin
 *  @date   11/04/2021 Original file creation
 *  @date   11/06/2021 Final modifications made
 */

#include "stat_tracker.h"
#include "Arduino.h"
#include "cmath"


/** @brief   Initialize counter variables and summation totals.
 *  @details This constructor initializes counter variables used for 
 *           keeping track of data added to a "set", as well as summation
 *           values used for calculating average and standard deviation.
 */
StatTracker::StatTracker(void)
{
    // Set counters to zero
    count_float = 0;    // number of floats added
    count_32u = 0;      // number of unsigned 32-bit points added
    count_32s = 0;      // number of signed 32-bit points added
    countTotal = 0;     // total number of points added

    // sum of all types
    totalSum = 0.0;

    // sum of squares for all types
    totalSquaresSum = 0.0;
}


/** @brief   Add a float to the data set.
 *  @details This method adds a new data point of type @c float to the existing
 *           data set.
 *  @param   newData_f The float to be added
 */
void StatTracker::add_data(float newData_f)
{
    count_float++;
    countTotal++;
    totalSum += newData_f;
    totalSquaresSum += pow(newData_f,2.0);

}

/** @brief   Add a signed 32-bit integer to the data set.
 *  @details This method adds a new data point of type @c int32_t to the existing
 *           data set.
 *  @param   newData_32s The signed 32-bit integer to be added
 */
void StatTracker::add_data(int32_t newData_32s)
{
    count_32s++;
    countTotal++;
    totalSum += newData_32s;
    totalSquaresSum += pow(newData_32s,2.0);
}

/** @brief   Add an unsigned 32-bit integer to the data set.
 *  @details This method adds a new data point of type @c uint32_t to the existing
 *           data set.
 *  @param   newData_32u The unsigned 32-bit integer to be added
 */
void StatTracker::add_data(uint32_t newData_32u)
{
    count_32u++;
    countTotal++;
    totalSum += newData_32u;
    totalSquaresSum += pow(newData_32u,2.0);
}

/** @brief   Method for getting the number of data points in the set.
 *  @details This method is for determining how many data points have
 *           been added to the data set since the last initialization
 *           or clear.
 *  @returns Number of data points added as a @c uint32_t data type. 
 */
uint32_t StatTracker::num_points(void)
{
    return countTotal;
}

/** @brief   Method for calculating the data set average.
 *  @details This method calculates the average value of the data
 *           set from the total sum and number of data points.
 *  @returns Average of the data set as a @c float data type.
 */
float StatTracker::average(void)
{
    float avg = totalSum/countTotal;
    return avg;
}

/** @brief   Method for calculating the data set standard deviation.
 *  @details This method calculates the standard deviation of the 
 *           data set from the summation of the square of each data
 *           point and the average of the data set.
 *  @returns Standard deviation of the data set as a @c float data type.
 */
float StatTracker::std_dev(void)
{   
    // standard deviation = sqrt( squares/N + avg^2 )
    float standardDev = sqrt( totalSquaresSum/countTotal - pow(totalSum/countTotal,2.0) );
    return standardDev;
}

/** @brief   Method for clearing the data set.
 *  @details This method resets all counter variables, as well
 *           as setting summations to zero, hence resetting
 *           the data set back to an initialized state.
 */
void StatTracker::clear( void )
{
    count_float = 0;
    count_32u = 0;
    count_32s = 0;
    countTotal = 0;

    totalSum = 0.0;
    totalSquaresSum = 0.0;

}