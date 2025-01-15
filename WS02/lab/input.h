#ifndef SENECA_INPUT_H
#define SENECA_INPUT_H
namespace seneca {
   /// <summary>
   /// Performs a foolproof integer entry from the console.
   /// </summary>
   /// <returns>The integer read from the console</returns>
   int getInt();

   /// <summary>
   /// Performs a foolproof integer entry from the console with an upper and lower acceptable limit.
   /// </summary>
   /// <param name="minVal">int: Minimum acceptable value</param>
   /// <param name="maxVal">int: Maximum acceptable value</param>
   /// <returns>The integer read from the console</returns>
   

   /// <summary>
   /// Performs an integer entry from the console only if the values are within the acceptable limits.
   /// </summary>
   /// <param name="number">A reference to an integer number to be read from the console</param>
   /// <param name="minVal">int: Minimum acceptable value</param>
   /// <param name="maxVal">int: Maximum acceptable value</param>
   /// <returns>bool: true if the number is successfully read, or false otherwise</returns>
   

}
#endif // !SENECA_IO_H


