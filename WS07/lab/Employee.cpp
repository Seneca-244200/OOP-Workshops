/***********************************************************************
// OOP244 Workshop 7 lab: Employee
//
// File  Employee.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Employee.h"
#include "Utils.h"
using namespace std;
namespace seneca {
   double Employee::salary() const{
      return m_salary;
   }
   Employee::Employee(const char* name, size_t employeeNo, double salary)
      :m_name(ut.alocpy(name)), m_employeeNo(employeeNo), m_salary(salary) {}

   Employee::~Employee(){
      delete[] m_name;
   }

   std::ostream& Employee::title(ostream& ostr)const{
      return ostr << "| Name            | Emp No | $alary |";
   }

   std::istream& Employee::read(std::istream& istr){
      char buffer[1024];
      istr.getline(buffer, 1024, ',');
      ut.alocpy(m_name, buffer);
      istr >> m_employeeNo;
      istr.ignore();
      return istr >> m_salary;
   }

   std::ostream& Employee::write(std::ostream& ostr)const{
      char name2print[16]{};
      if(m_name) ut.strcpy(name2print, m_name,15);
      ostr << "| ";
      ostr.width(15);
      ostr.setf(ios::left);
      ostr << name2print << " | ";
      ostr.unsetf(ios::left);
      ostr.width(6);
      ostr.fill('0');
      ostr.setf(ios::right);
      ostr << m_employeeNo << " |";
      ostr.fill(' ');
      ostr.setf(ios::fixed);
      ostr.precision(0);
      ostr.width(7);
      ostr << m_salary << " |";
      ostr.unsetf(ios::right);
      return ostr;
   }

   ostream& operator<<( ostream& ostr, const Employee& E ) {
      return E.write( ostr );
   }
   std::istream& operator>>( std::istream& istr, Employee& E ) {
      return E.read( istr );
   }
}

