#ifndef _SDIR_H_
#define _SDIR_H_

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define SDIR_VERSION "1.0.0"

namespace SDir
{
  typedef Buffer std::string;
  typedef BufPos std::streampos;
  
  class Directory;
  
  class Library
  {
    Directory working_dir;
    
    Library(std::string working_loc = "");
  public:
    std::string getVersion() { return SDIR_VERSION; }
    
    Directory getWorkingDirectory() { return working_dir; }
  } lib();
  
  class File
  {
    friend class Directory;
    
    BufPos ppos;
    BufPos gpos;
    
    Directory parent;
    std::string name;
    
    File(Directory parent, std::string name);
  public:
    Buffer      read(bool binary = false, BufPos readAmount = -1);
    void        write(Buffer buffer, binary = false);
    void        seekg(BufPos pos);
    BufPos      tellg();
    void        seekp(BufPos pos);
    BufPos      tellp();
    std::string extension();  //gets the extension eg:.zip, .obj, .txt
    std::string name();       //gets the file name excluding the extension eg:zipfile, objectfile, textfile
    std::string fullname();   //gets the file name with extension eg:zipfile.zip. objectfile.obj, textfile.txt
    std::string absname();    //returns the file's location, name, and extension eg:C:\Windows\Users\Desktop\zipfile.zip
    bool        destroy();    //destroys/deletes the object
  };
  
  class Directory
  {
    Directory parent;
    std::string name;
    
    std::vector<File> cache;
    
    bool createDirectory();
    bool removeDirectory();
    bool doesDirectoryExist();
  public:
    Directory(std::string location);
    Directory(Directory parent, std::string name);
    
    std::string               getName() { return location; }
    File                      getFile(std::string name);
    Directory                 getDirectory(std::string name);
    Directory                 getParent();
    std::vector<File>         getAllFiles();
    bool                      doesFileExist(std::string name);
    std::vector<std::string>  getFileList();
    std::vector<std::string>  getDirectoryList();
    bool                      moveFile(Directory newDir, File file);
    bool                      moveDirectory(Directory newDir, Directory dir);
    void                      destroy(); //destroy/deletes the object
  };
}

#endif
