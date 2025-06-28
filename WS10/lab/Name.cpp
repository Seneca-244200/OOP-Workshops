/***********************************************************************
// OOP244 workshop 10, Name module
//
// File	Name.cpp
// Author Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Name.h"
#include "Utils.h"
using namespace std;
namespace seneca {



   Name::Name( const char* name ) {
      m_name = ut.alocpy( name );
   }

   Name::Name( const Name& other ) {
      m_name = ut.alocpy( other.m_name );
   }

   Name& Name::operator=( const Name& other ) {
      // be careful since the current object is already created and it may have data
      if ( this != &other ) {
         ut.alocpy( m_name, other.m_name ); // this deletes m_name first (see Utils.cpp)
      }
      return *this;
   }

   Name::~Name( ) {
      delete[] m_name;
   }

   ostream& Name::display(ostream& ostr ) const {
      if ( m_name ) {
         ostr << m_name;
      }
      return ostr;
   }

   istream& Name::read( istream& istr ) {
      char* buffer = new char[1024];
      istr.getline( buffer, 1024 );
      if ( istr ) {
         ut.alocpy( m_name, buffer );
      }
      delete[] buffer;
      return istr;
   }

   Name::operator bool( ) const {
      return m_name != nullptr;
   }

   ostream& operator<<( ostream& ostr, const Name& N ) {
      return N.display( ostr );
   }

   istream& operator>>( istream& istr, Name& N ) {
      return N.read( istr );
   }

}