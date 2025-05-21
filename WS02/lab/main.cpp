/***********************************************************************
// OOP244 Workshop #2: main module
//
// File        main.cpp
// Version     1.0
// Date        2025-05-20
// Author      Fardad Soleimanloo
// Description:
// A Sensor analysis program using dma module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>        // For FILE, fopen, fscanf
#include "dma.h"
#include "sensorAnalysis.h"
#include "cstr.h"         // For strlen, strcpy

using namespace seneca;
using namespace std;
const int CHUNK_SIZE = 50;

/// <summary>
/// Reads a sensor data file and loads readings into a dynamically allocated Samples structure.
/// The first line of the file is treated as the title (prefixed by #).
/// The readings are added in chunks of 50 using the add() function.
/// </summary>
/// <param name="filename">The path to the data file.</param>
/// <returns>A dynamically allocated Samples pointer, or nullptr if the file can't be opened.</returns>
Samples* loadStats(const char* filename) {
   FILE* file = fopen(filename, "r");
   Samples* samples = nullptr;
   if (file) {

      char title[256];

      // Read the first line: title of the readings
      if (fscanf(file, "%[^\n]\n", title) != 1) {
         fclose(file);
         return nullptr;
      }

      samples = CreateSamples(title);

      int buffer[CHUNK_SIZE];
      int value;
      int count = 0;

      // Read integers in chunks of 50
      while (fscanf(file, "%d", &value) == 1) {
         buffer[count++] = value;

         if (count == CHUNK_SIZE) {
            add(*samples, buffer, count);
            count = 0;
         }
      }

      // Add the remaining integers if any
      if (count > 0) {
         add(*samples, buffer, count);
      }

      fclose(file);
   }
   return samples;
}

int main() {
   const char* filename = "sensor_readings.txt";

   Samples* sample = loadStats(filename);

   if (sample) {
      cout << "--- Sensor Analysis Report ---\n";
      cout << "Title: " << sample->m_title << "\n";
      cout << "Number of Readings: " << sample->m_size << "\n";

      double avg = averageReading(sample->m_data, sample->m_size);
      cout << "Average Temperature: " << avg << " C\n";

      int spikes = countSpikes(sample->m_data, sample->m_size);
      cout << "Spikes Detected: " << spikes << "\n";

      int drop = maxDrop(sample->m_data, sample->m_size);
      cout << "Maximum Drop Between Readings: " << drop << " C\n";

      int inRange = countInRange(sample->m_data, sample->m_size, 90, 110);
      double percent = (double)inRange / sample->m_size * 100;
      cout << "Readings in Optimal Range (90-110C): "
         << inRange << " (" << percent << "%)\n";

      cout << "--------------------------------\n";

      freemem(sample);
   }
   else {
      cerr << "Failed to load data from file: " << filename << "\n";
   }

   return 0;
}
