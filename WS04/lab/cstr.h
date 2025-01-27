#ifndef SENECA_CSTR_H
#define SENECA_CSTR_H
namespace seneca {
   /// <summary>
   /// Frees the dynamic memory allocated by mem and then sets it to nullptr
   /// </summary>
   /// <param name="mem">DMA's address</param>
   void freeMem(char*& mem);
   /// <summary>
   /// Allocates memory to the length of the Cstring src and stores the address in des, then copies the content of src Cstring into des.
   /// </summary>
   /// <param name="des">pointer to allocate memory and copy into</param>
   /// <param name="src">Cstring to dynamically copy from</param>
   /// <returns>true if the DMA was successull otherwise false</returns>
   bool alocpy(char*& des, const char* src);
   /// <summary>
   ///  Returns the number of characters in the Cstring src
   /// </summary>
   /// <param name="src">the Cstring whose length is returned</param>
   /// <returns>length of Cstring src</returns>
   unsigned int strlen(const char* src);
   /// <summary>
   /// Copies all the contents of Cstring src into des. The des will be null terminated.
   /// </summary>
   /// <param name="des">to copy into</param>
   /// <param name="src">to copy from</param>
   void strcpy(char* des, const char* src);
   /// <summary>
   /// Copies the contents of Cstring src into des upto maxLen characters or the end of src, whichever comes first. the des is always null terminated.
   /// </summary>
   /// <param name="des">to copy into</param>
   /// <param name="src">to copy from</param>
   /// <param name="maxLen">maximum number of characters to copy</param>
   void strcpy(char* des, const char* src, unsigned int maxLen);
   /// <summary>
   /// compares Cstrings 
   /// </summary>
   /// <param name="s1">Cstring</param>
   /// <param name="s2">Cstring</param>
   /// <returns>Posetive value if s1 &gt; s2. Negative if s1 &lt; s2. Zero if they have the same content </returns>
   int strcmp(const char* s1, const char* s2);

}
#endif // !SENECA_CSTR_H
