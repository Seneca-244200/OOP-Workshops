/***********************************************************************
// OOP244 Workshop 7 lab: Employee
//
// File  Employee.h
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_EMPLOYEE_H
#define SENECA_EMPLOYEE_H
#include <iostream>
namespace seneca{
   class Employee {
      char *m_name{};
      size_t m_employeeNo{};
      double m_salary{};
   protected:
      double salary()const;
   public:
      Employee() = default;
      Employee(const char* name, size_t employeeNo, double salary);
      Employee(const Employee&) = delete;
      Employee& operator=(const Employee&) = delete;
      ~Employee();

      std::istream& read(std::istream& istr = std::cin);
      std::ostream& write(std::ostream& ostr = std::cout)const;
      std::ostream& title(std::ostream& ostr = std::cout)const;
   };

   std::ostream& operator<<( std::ostream& ostr, const Employee& E );
   std::istream& operator>>( std::istream& istr, Employee& E );
}
#endif // !SENECA_EMPLOYEE_H
