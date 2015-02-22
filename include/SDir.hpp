#ifndef _SDIR_H_
#define _SDIR_H_

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

#define SDIR_VERSION "1.0.0"

//TODO: place in cpp file
#ifdef _WIN32
  #define _SDIR_OS_USE_ 1
  #include	<io.h> // for _access on windows
  #include	<Shlobj.h>
  #include	<Shlwapi.h>
  #pragma comment(lib,"Shlwapi.lib") // instruct visual studio to link the library
  #include	<tchar.h>
  #include	<sys/types.h>
  #include	<sys/stat.h>
#elif defined(__APPLE__) || defined(__unix__)
  #define _SDOR_OS_USE_ 2
  #include <unistd.h> // for access on unix, mac
// Start Alternates to Win32 and Unix/OSX
#elif _UNDEFINED_OS
  #define _SDIR_OS_USE_ 3
  // And/Or more then 3 for more Operating systems
// End ALternates to Win32 and Unix/OSX
#endif

namespace SDir
{
  class Library
  {
    Library();
  public:
    std::string getVersion() { return SDIR_VERSION; }
  } lib();
  
  class Directory
  {
    std::string location;
  public:
    Directory(std::string location);
  };
}

#endif
