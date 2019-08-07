#include <io.h>
#include <iostream>
#include <fstream>
using namespace std;
 
bool transfer(string fileName, int exeNum );
void dfsFolder(string folderPath, ofstream &fout);
 
int main()
{
  _finddata_t file;
  int k;
  long HANDLE;
  k = HANDLE = _findfirst("*.*", &file);
  while (k != -1)
  {
    cout << file.name << endl;
    k = _findnext(HANDLE, &file);
  }
  _findclose(HANDLE);
 
  transfer("C:\\Windows\\*.exe", 0);
  ofstream o_fstream;
 
  dfsFolder("E:\\\WHU\\Study", o_fstream);
 
 
  return 0;
}
 
//_findfirst 函数返回的是匹配到文件的句柄，数据类型为long。
//遍历过程可以指定文件类型，这通过FileName的赋值来实现，例如要遍历C : \WINDOWS下的所有.exe文件
 
bool transfer(string fileName , int exeNum)
{
  _finddata_t fileInfo;
  long handle = _findfirst(fileName.c_str(), &fileInfo);
 
  if (handle == -1L)
  {
    cerr << "failed to transfer files" << endl;
    return false;
  }
 
  do
  {
    exeNum++;
    cout << fileInfo.name << endl;
  } while (_findnext(handle, &fileInfo) == 0);
  cout << " .exe files' number: " << exeNum << endl;
 
  return true;
}
 
//遍历文件夹及其子文件夹下所有文件。操作系统中文件夹目录是树状结构，使用深度搜索策略遍历所有文件。用到_A_SUBDIR属性
 
 
//在判断有无子目录的if分支中，由于系统在进入一个子目录时，匹配到的头两个文件(夹)是"."(当前目录)，".."(上一层目录)。
//需要忽略掉这两种情况。当需要对遍历到的文件做处理时，在else分支中添加相应的代码就好
 
void dfsFolder(string folderPath, ofstream &fout)
{
  _finddata_t FileInfo;
  string strfind = folderPath + "\\*";
  long Handle = _findfirst(strfind.c_str(), &FileInfo);
 
  if (Handle == -1L)
  {
    cerr << "can not match the folder path" << endl;
    exit(-1);
  }
  do{
     //判断是否有子目录 
    if (FileInfo.attrib & _A_SUBDIR)
    {
      //这个语句很重要 
      if ((strcmp(FileInfo.name, ".") != 0) && (strcmp(FileInfo.name, "..") != 0))
      {
        string newPath = folderPath + "\\" + FileInfo.name;
        dfsFolder(newPath, fout);
      }
    }
    else
    {
      fout<<folderPath.c_str() << "\\" << FileInfo.name << " ";
      cout << folderPath.c_str() << "\\" << FileInfo.name << endl;
    }
  } while (_findnext(Handle, &FileInfo) == 0);
 
  _findclose(Handle);
  fout.close();
}
 
 
//#include <iostream>  
//#include <string>  
//#include <io.h>  
//using namespace std;
//
//int main()
//{
//  _finddata_t file;
//  long longf;
//  string tempName;
//  //_findfirst返回的是long型; long __cdecl _findfirst(const char *, struct _finddata_t *)  
//  if ((longf = _findfirst("E:\\WHU\\Study\\*.*", &file)) == -1l)
//  {
//    cout << "文件没有找到!\n";
//    return 0;
//  }
//  do
//  {
//    cout << "文件列表:\n";
//    tempName = file.name;
//    if (tempName[0] == '.')
//      continue;
//    cout << file.name<<endl;
//
//    if (file.attrib == _A_NORMAL)
//    {
//      cout << " 普通文件 ";
//    }
//    else if (file.attrib == _A_RDONLY)
//    {
//      cout << " 只读文件 ";
//    }
//    else if (file.attrib == _A_HIDDEN)
//    {
//      cout << " 隐藏文件 ";
//    }
//    else if (file.attrib == _A_SYSTEM)
//    {
//      cout << " 系统文件 ";
//    }
//    else if (file.attrib == _A_SUBDIR)
//    {
//      cout << " 子目录 ";
//    }
//    else
//    {
//      cout << " 存档文件 ";
//    }
//    cout << endl;
//  } while (_findnext(longf, &file) == 0);//int __cdecl _findnext(long, struct _finddata_t *);如果找到下个文件的名字成功的话就返回0,否则返回-1  
//
//  _findclose(longf);
//
//  return 0;
//}
