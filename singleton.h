/***********************************************************************
	filename: 	singleton.h
	created:	2012-11-23
	author:		ascetic85

	purpose:	Singleton Base Class
*************************************************************************/
/*************************************************************************

	The code in this file is taken from article 1.3 in the the book:
	Game Programming Gems from Charles River Media

*************************************************************************/

// Usage:
// 
// class Fire : public Singleton<Fire>
// {
// };


#ifndef _singleton_h_
#define _singleton_h_

#include <cassert>

template <typename T> class CEGUIEXPORT Singleton
{
protected:
    T* ms_Singleton;

public:
    Singleton( void )
    {
        assert( !ms_Singleton );
        ms_Singleton = static_cast<T*>(this);
    }
   ~Singleton( void )
        {  assert( ms_Singleton );  ms_Singleton = 0;  }
    static T& getSingleton( void )
        {  assert( ms_Singleton );  return ( *ms_Singleton );  }
    static T* getSingletonPtr( void )
        {  return ( ms_Singleton );  }

private:
    Singleton& operator=(const Singleton&) { return this; }
    Singleton(const Singleton&) {}
};

#endif	// end of guard _singleton_h_
