////////////////////////////////////////////////////////////////////////////////////////////
// Filename:    Log.h
// Description: there is a log system header
//
// Created:     19.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#pragma once


//////////////////////////////////
//       LOGGER MACROSES
//////////////////////////////////
#define LOG_MACRO  __FUNCTION__, __LINE__   // == "func_name() line_num"


//////////////////////////////////
//          INCLUDES
//////////////////////////////////
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <iostream>    // for using I/O streams
#include <ctime>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>

class Log
{
public:
	Log();
	~Log();

	static Log* Get();    // to get a static pointer to this class instance

	// print messages of different kinds
	static void Print(const char* funcName, const int codeLine, const std::string & message);
	static void Print(const char* funcName, const int codeLine, const char* message);
	static void Debug(const char* funcName, const int codeLine, const std::string & message);
	static void Debug(const char* funcName, const int codeLine, const char* message);
	static void Error(const char* funcName, const int codeLine, const std::string & message);
	static void Error(const char* funcName, const int codeLine, const char* message);


private:
	static void Print_Helper(const char* levtext, const char* text); // prints a message(text) into the command prompt and into the log file
	void Init_Helper();   // create, open a logger text file, and print a message about it
	void Close_Helper();  // close the logger file, and print a message about it

private:
	static HANDLE handle_;   // we need it for changing the text colour in the command prompt
	static Log* pInstance_;  // a pointer to the instance of this class
	static std::ofstream fout_;
private:
	const char* logFilename_{ "log_math_lib.txt" };
	
};


