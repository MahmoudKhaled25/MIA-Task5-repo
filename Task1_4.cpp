/**
 ******************************************************************
 * @file              :   main.c
 * @brief             :   Kalman Filter Implementation for Sensor Fusion
 *                        This code calculates the filtered results using a Kalman filter.
 *                        It combines readings from two different sensors with different accuracies
 *                        and estimates the state using a mathematical model.
 * @author            :   Mahmoud Khaled
 ******************************************************************
 */

#include <iostream>

// Number of readings
#define NUM_READS 10

// Sensor accuracies
#define MPU_ACCURACY 0.79f
#define BNO_ACCURACY 0.92f

// Combined accuracy
#define COMB_ACCURACY (((MPU_ACCURACY) + (BNO_ACCURACY)) / (2.0f))

// Initial and final estimation error values
#define START_ESTIMATION_ERROR_VAL 0.9f
#define END_ESTIMATION_ERROR_VAL 0.01f

// Arrays to store sensor readings and state estimates
float mpu6050[NUM_READS]        =
        {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};

float bno55[NUM_READS]          =
        {0.0, 9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};

float stateEstimate[NUM_READS]  = // From mathematical model
        {0.0, 9.56, 16.67, 21.33, 23.54, 23.29, 20.59, 15.44, 7.84, -2.21};

// Arrays to store calculated values
float averageMeasurement[NUM_READS];
float filteredResults[NUM_READS];

// Estimation error variable
float estimationError = START_ESTIMATION_ERROR_VAL;

// Function prototypes
void calculateAverage();
void updateKalmanFilter();
void printFilteredResults();

int main()
{

    calculateAverage();
    updateKalmanFilter();
    printFilteredResults();

    return 0;
}


    //Calculate the average of the sensor readings
void calculateAverage()
{
    unsigned int counter;

    for (counter = 0; counter < NUM_READS; ++counter)
    {
        // Calculate the weights based on sensor accuracies
        float weight1 = MPU_ACCURACY / (MPU_ACCURACY + BNO_ACCURACY);
        float weight2 = BNO_ACCURACY / (MPU_ACCURACY + BNO_ACCURACY);

        // Calculate the average measurement using weighted sum
        averageMeasurement[counter] = weight1 * mpu6050[counter] + weight2 * bno55[counter];
    }
}


    // Update the Kalman filter to obtain filtered results
void updateKalmanFilter()
{
    float KG;
    unsigned int counter;

    for (counter = 0; counter < NUM_READS; ++counter)
    {
        // Iterate until the estimation error reaches the desired threshold
        while (estimationError > END_ESTIMATION_ERROR_VAL)
        {
            // Calculate the Kalman gain
            KG = (estimationError) / (estimationError + (1 - COMB_ACCURACY));

            // Update the filtered result using the Kalman gain
            filteredResults[counter] = stateEstimate[counter] + KG * (averageMeasurement[counter] - stateEstimate[counter]);

            // Update the estimation error using the Kalman gain
            estimationError *= (1 - KG);
        }

        // Reset the estimation error for the next iteration
        estimationError = START_ESTIMATION_ERROR_VAL;
    }
}


 // Print the filtered results
void printFilteredResults()
{
    unsigned int counter;
    printf("Filtered Results: ");
    for (counter = 0; counter < NUM_READS; ++counter)
    {
        printf("%0.2f ", filteredResults[counter]);
    }
}