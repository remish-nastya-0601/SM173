#include <iostream>
#include "pch.h"
using namespace System;
using namespace System::IO;
using namespace std;
namespace SM17
{
	public ref class Program
	{
	public:

		static void Main()
		{
			// Список всех папок в текущем
			for each (String ^ entry in Directory::GetDirectories("C:\\Users\\remis\\source\\repos\\SM173\\"))
			{
				DisplayFileSystemInfoAttributes(gcnew DirectoryInfo(entry));
			}

			// Loop through all the files in C.
			for each (String ^ entry in Directory::GetFiles("C:\\Users\\remis\\source\\repos\\SM173\\"))
			{
				DisplayFileSystemInfoAttributes(gcnew FileInfo(entry));
			}

			// Список всех папок в папках
			for each (String ^ entry in Directory::GetDirectories("C:\\Users\\remis\\source\\repos\\SM173\\"))
			{
				for each (String ^ entry1 in Directory::GetDirectories((gcnew DirectoryInfo(entry))->FullName + "\\"))
					DisplayFileSystemInfoAttributes(gcnew DirectoryInfo(entry1));
			}

			//Все файлы в папках
			for each (String ^ entry in Directory::GetDirectories("C:\\Users\\remis\\source\\repos\\SM173\\"))
			{
				for each (String ^ entry1 in Directory::GetFiles((gcnew DirectoryInfo(entry))->FullName + "\\"))
					DisplayFileSystemInfoAttributes(gcnew FileInfo(entry1));
			}

			
		}


		static void DisplayFileSystemInfoAttributes(FileSystemInfo^ fsi)
		{
			// Assume that this entry is a file.
			String^ entryType = "File";
			// Determine if entry is really a directory
			if ((fsi->Attributes & FileAttributes::Directory) == FileAttributes::Directory)
			{
				entryType = "Directory";
			}
			// Show this entry's type, name, and creation date.
			Console::WriteLine("{0} entry {1} was created on {2:D}", entryType, fsi->FullName, fsi->CreationTime);
		}


	};
};
int main()
{
	SM17::Program::Main();
	return(0);
}
