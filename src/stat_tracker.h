/** @file stat_tracker.h
 *    This header file is for a class that calculates the average
 *    and standard deviation of arrays
 * 
 *  @author Ryan McLaughlin
 *  @date   11/04/2021 Original file creation
 *  @date   11/06/2021 Final modifications made
 */

#include "Arduino.h"


class StatTracker
{
    protected:

        // might need 3 seperate for looping correctly
        uint32_t count_float;
        uint32_t count_32u;
        uint32_t count_32s;
        uint32_t countTotal;

        // sum 
        float totalSum;

        // sum of squares
        float totalSquaresSum;

    public:
        // constructor
        StatTracker(void);
        
        // add a float to data set
        void add_data(float newData_f);
        // add a signed integer
        void add_data(int32_t newData_32s);
        // add an unsigned integer
        void add_data(uint32_t newData_32u);

        // return number of data points added
        uint32_t num_points(void);

        // returns average of data
        float average(void);
        // returns standard deviation of data
        float std_dev(void);
        // clear all
        void clear( void );

};