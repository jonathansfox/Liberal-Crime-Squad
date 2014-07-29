/*
    File created by Rich McGrew.

    This file includes useful macros and functions for universal use, not just
    in .cpp files, but in .h files too. Having them in includes.h isn't good
    enough because then they are not accessible to header files that are
    included in includes.h. You can't have 2 header files both include each
    other. Thus this file was designed to be something any file could include
    and make full use of, with general-purpose functions and macros that help
    simplify common coding tasks.

    All code released under GNU GPL.
*/

#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

/* some compilers sometimes define _WIN32 but not WIN32 on Windows, but LCS usually
   just checks if WIN32's defined, so the next couple lines fix that so it works */
#ifdef _WIN32
   #ifndef WIN32
      #define WIN32 _WIN32
   #endif /* !WIN32 */
#endif /* _WIN32 */

#include <string.h>

/* Macro definition */
#ifndef MAX
   // maximum of 2 numbers
   #define MAX(a,b) (((a)<(b))?(b):(a))
#endif

#ifndef MIN
   // minimum of 2 numbers
   #define MIN(a,b) (((a)>(b))?(b):(a))
#endif

#ifndef ABS
   // absolute value of a number
   #define ABS(x) ((x)<0)?(-x):(x)
#endif

#ifndef DIFF
   // difference between 2 numbers (absolute value of subtracting one from the other)
   #define DIFF(x,y) ((x)<(y)?((y)-(x)):((x)-(y)))
#endif

#define BIT1  (1<<0 )
#define BIT2  (1<<1 )
#define BIT3  (1<<2 )
#define BIT4  (1<<3 )
#define BIT5  (1<<4 )
#define BIT6  (1<<5 )
#define BIT7  (1<<6 )
#define BIT8  (1<<7 )
#define BIT9  (1<<8 )
#define BIT10 (1<<9 )
#define BIT11 (1<<10)
#define BIT12 (1<<11)
#define BIT13 (1<<12)
#define BIT14 (1<<13)
#define BIT15 (1<<14)
#define BIT16 (1<<15)
#define BIT17 (1<<16)
#define BIT18 (1<<17)
#define BIT19 (1<<18)
#define BIT20 (1<<19)
#define BIT21 (1<<20)
#define BIT22 (1<<21)
#define BIT23 (1<<22)
#define BIT24 (1<<23)
#define BIT25 (1<<24)
#define BIT26 (1<<25)
#define BIT27 (1<<26)
#define BIT28 (1<<27)
#define BIT29 (1<<28)
#define BIT30 (1<<29)
#define BIT31 (1<<30)
#define BIT32 (1<<31)

/* r_num() and LCSrandom() are implemented in game.cpp */
int r_num();
int LCSrandom(int max);

/* Determine size of vectors and any other container that implements the size() function.
   This basically includes all types of containers except for the C++11 std::forward_list. */
template <class Container> inline long len(const Container& x)
{
   return x.size();
}

/* Determine array size in pickrandom() and various functions throughout the code.
   Only works on actual arrays, not on vectors or other containers. */
template <typename T,size_t N> inline long len(const T (&x)[N])
{
   return N;
}

/* Override of the prior function for null-terminated C-strings as char arrays.
   This override allows pickrandom() to pick a random character from a C-string we have as a char array. */
template <size_t N> inline long len(const char (&x)[N])
{
   return strlen(x);
}

/* Override of the prior function for null-terminated C-strings as char pointers.
   This override allows pickrandom() to pick a random character from a C-string we have as a char pointer. */
inline long len(const char* x)
{
   return strlen(x);
}

/* Override for when it doesn't work with const in front of the char*
   (compilers are weird about template function overrides) */
inline long len(char* x)
{
   return strlen(x);
}

/* Pick a random element from a vector/deque/map/std::string/C++11 std::array/etc. (e.g. a random string from a vector of strings).
   It works on any container class that implements the [] operator, size() function, and value_type typename.
   This doesn't work if the vector/deque/map/std::string/C++11 std::array/etc. has zero elements. */
template <class Container> inline typename Container::value_type& pickrandom(const Container& x)
{
   return const_cast<typename Container::value_type&>(x[LCSrandom(len(x))]);
}

/* Pick a random element from an array (e.g. a random string from an array of strings).
   This doesn't work if the array has zero elements. */
template <typename T,size_t N> inline T& pickrandom(const T (&x)[N])
{
   return const_cast<T&>(x[LCSrandom(len(x))]);
}

/* Pick a random element from a C-string.
   Returns '\x0' (null character) for empty string. */
inline char& pickrandom(const char* x)
{
   return const_cast<char&>(x[LCSrandom(len(x))]);
}

/* Override for when it doesn't work with const in front of the char*
   (compilers are weird about template function overrides) */
inline char& pickrandom(char* x)
{
   return x[LCSrandom(len(x))];
}

/* Deletes a specified pointer and sets it to NULL. */
template <typename T> inline void delete_and_nullify(T* &o)
{
   delete o;
   o=NULL;
}

/* Deletes and removes a specified pointer from a container. */
template <class Container> inline void delete_and_remove(Container& c,int i)
{
   if(i<=-1) return; // check for invalid index, and don't delete anything in this case
	delete c[i];
   c.erase(c.begin()+i);
}

/* Deletes and removes a specified pointer from 2 containers it's in.
   c1 and c2 must not be the same container! */
template <class Container> inline void delete_and_remove(Container& c1,int i1,Container& c2,int i2)
{
   if(i1<=-1||i2<=-1) return; // check for invalid index, and don't delete anything in this case
   if(c1[i1]==c2[i2])
   { // it's the same pointer, so just delete it once, then remove it from both containers
      delete_and_remove(c1,i1);
      if(c1!=c2||i1!=i2) c2.erase(c2.begin()+i2); // remove it from 2nd location, unless 2nd location is identical to 1st location
   }
   else
   { // it's 2 different pointers, so delete them both and remove them from both containers
      delete_and_remove(c1,i1);
      delete_and_remove(c2,i2);
   }
}

/* Deletes and removes all pointers in a container. */
template <class Container> inline void delete_and_clear(Container& c)
{
   while(len(c))
   {
      delete c.back();
      c.pop_back();
   }
}

/* Deletes and removes all pointers that 2 containers have in common. */
template <class Container> inline void delete_and_clear(Container& c1,Container& c2)
{
   for(int i1=len(c1)-1;i1>=0;i1--)
      for(int i2=len(c2)-1;i2>=0;i2--)
         if(c1[i1]==c2[i2]) delete_and_remove(c1,i1,c2,i2);
}

#endif