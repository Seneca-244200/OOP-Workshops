#include "sensorAnalysis.h"
#include <cmath>  // For std::abs

namespace seneca {

   double averageReading(const int* readings, int size) {
      double ret = 0.0;
      if (size != 0) {

         long long sum = 0;

         // Accumulate the sum of all readings
         for (int i = 0; i < size; ++i) {
            sum += readings[i];
         }

         // Compute and return the average using C-style cast
         ret = (double)sum / size;
      }
      return ret;
   }

   int countSpikes(const int* readings, int size, int threshold) {
      int count = 0;

      // Loop through the array excluding the first and last elements
      for (int i = 1; i < size - 1; ++i) {
         // Calculate the absolute difference with previous and next elements
         int diffPrev = std::abs(readings[i] - readings[i - 1]);
         int diffNext = std::abs(readings[i] - readings[i + 1]);

         // A spike occurs if both differences exceed the threshold
         if (diffPrev > threshold && diffNext > threshold) {
            count++;
         }
      }

      return count;
   }

   int maxDrop(const int* readings, int size) {
      int maximumDrop = 0;
      if (size >= 2) {
         // Loop through all adjacent pairs of readings
         for (int i = 1; i < size; ++i) {
            // Calculate the difference between the previous and current reading.
            // A positive result means the reading dropped.
            int drop = readings[i - 1] - readings[i];

            // Update the maximum drop only if the current drop is positive and larger
            if (drop > maximumDrop) {
               maximumDrop = drop;
            }
         }
      }
      return maximumDrop;
   }


   int countInRange(const int* readings, int size, int low, int high) {
      int count = 0;

      // Loop through all readings and count those within [low, high] inclusive
      for (int i = 0; i < size; ++i) {
         if (readings[i] >= low && readings[i] <= high) {
            count++;
         }
      }

      return count;
   }

} // namespace seneca
