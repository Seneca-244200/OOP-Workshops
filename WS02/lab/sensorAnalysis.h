#ifndef SENECA_SENSORANALYSIS_H
#define SENECA_SENSORANALYSIS_H

namespace seneca {

   /// <summary>
   /// Calculates the average value of all sensor readings.
   /// </summary>
   /// <param name="readings">Pointer to an array of integer sensor readings.</param>
   /// <param name="size">Number of elements in the readings array.</param>
   /// <returns>The average value as a double. Returns 0.0 if size is 0.</returns>
   double averageReading(const int* readings, int size);

   /// <summary>
   /// Counts the number of spikes in the sensor data.
   /// A spike differs from both neighbors by more than a threshold.
   /// </summary>
   /// <param name="readings">Pointer to the array of sensor readings.</param>
   /// <param name="size">Number of elements in the array.</param>
   /// <param name="threshold">Minimum difference to be considered a spike.</param>
   /// <returns>The number of spikes detected.</returns>
   int countSpikes(const int* readings, int size, int threshold = 100);

   /// <summary>
   /// Determines the maximum drop between two consecutive readings.
   /// </summary>
   /// <param name="readings">Pointer to the array of sensor readings.</param>
   /// <param name="size">Number of elements in the array.</param>
   /// <returns>Maximum drop found between adjacent readings. Returns 0 if size &lt; 2.</returns>
   int maxDrop(const int* readings, int size);

   /// <summary>
   /// Counts how many readings are within the specified safe range (inclusive).
   /// </summary>
   /// <param name="readings">Pointer to the array of sensor readings.</param>
   /// <param name="size">Number of elements in the array.</param>
   /// <param name="low">Lower bound of the range.</param>
   /// <param name="high">Upper bound of the range.</param>
   /// <returns>The number of readings that fall within the range.</returns>
   int countInRange(const int* readings, int size, int low, int high);

}

#endif // SENEC_ASENSORANALYSIS_H
