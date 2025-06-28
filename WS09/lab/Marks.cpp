/***********************************************************************
// OOP244 workshop 9, Marks module
//
// File	Marks.cpp
// Version 1.0
// Author by Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Marks.h"
#include "Utils.h"
#include <iostream>
using namespace std;
namespace seneca {
   Mark::~Mark(){
      delete[] m_title;
   }
   const char* Mark::title() const{
      return m_title;
   }
   int Mark::mark() const{
      return m_mark;
   }
   Mark& Mark::set(const char* title, int mark) {
      ut.alocpy(m_title,title);
      m_mark = mark;
      return *this;
   }

   Mark& Mark::operator=(const Mark& other) {
      set(other.m_title, other.m_mark);
      return *this;
   }

   Marks::Marks(const Marks& other){
      operator=(other);
   }

   Marks& Marks::operator=(const Marks& other){
      if (this != &other) {
         delete[] m_marks;
         m_marks = nullptr;
         m_noOfMarks = 0;
         for (size_t i = 0; i < other.size(); i++) {
            addMark(other[i].m_title, other[i].m_mark);
         }
      }
      return *this;
   }

   Marks& Marks::addMark(const char* title, int mark){
      Mark* temp = new Mark[m_noOfMarks + 1];
      size_t i = 0;
      for (i = 0; i < m_noOfMarks; i++) {
         temp[i] = m_marks[i];
      }
      delete[] m_marks;
      m_marks = temp;
      m_marks[m_noOfMarks].set(title, mark);
      m_noOfMarks++;
      return *this;
   }
   const Mark& Marks::operator[](size_t index) const{
      return m_marks[index % m_noOfMarks];
   }
   size_t Marks::size() const{
      return m_noOfMarks;
   }
   std::ostream& Marks::display(std::ostream& ostr)const{
      for (size_t i = 0; i < size(); i++) {
         ostr.width(70);
         ostr.setf(ios::left);
         ostr << m_marks[i].title();
         ostr.unsetf(ios::left);
         ostr.width(3);
         ostr.setf(ios::right);
         ostr << m_marks[i].mark() << endl;
         ostr.unsetf(ios::right);
      }
      return ostr;
   }

   Marks::~Marks(){
      delete[] m_marks;
   }

   std::ostream& operator<<(std::ostream& ostr, const Marks& M){
      return M.display(ostr);
   }

}


