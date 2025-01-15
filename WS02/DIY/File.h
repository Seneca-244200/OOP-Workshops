#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_
namespace seneca {
   /// <summary>
   /// Opens the file for read
   /// </summary>
   /// <param name="filename">The file path to open</param>
   /// <returns>the success</returns>
   bool openFile(const char filename[]);
   /// <summary>
   /// Closes the file
   /// </summary>
   void closeFile();
   /// <summary>
   ///  Returns the number of records in the file for dynamic memory alocation purposes.
   /// </summary>
   /// <returns></returns>
   int noOfRecords();

}
#endif // !SDDS_FILE_H_
