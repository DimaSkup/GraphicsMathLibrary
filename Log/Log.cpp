////////////////////////////////////////////////////////////////////////////////////////////
// Filename:    Log.cpp
// Description: there is an implementation of the log system functional
//
// Created:     19.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#include "Log.h"


// initialize static members of the Log class
Log* Log::pInstance_ = nullptr;
//FILE* Log::pFile_ = nullptr;
HANDLE Log::handle_ = GetStdHandle(STD_OUTPUT_HANDLE);
std::ofstream Log::fout_;
//std::stringstream Log::ss_;



////////////////////////////////////////////////////////////////////////////////////////////
//                                PUBLIC FUNCTIONS
////////////////////////////////////////////////////////////////////////////////////////////

Log::Log()
{
	if (!pInstance_)   // we can have only one instance of logger
	{
		pInstance_ = this;
		Init_Helper();
		

		Log::Print(__FUNCTION__, __LINE__, "a log system is initialized successfully");
	}
	else
	{
		std::string errorMsg{ "Log::Log(): can't create an instance of the Log class" };
		std::cout << errorMsg << std::endl;
		throw std::runtime_error(errorMsg);
	}
}

/////////////////////////////////////////////////////////////

Log::~Log()
{
	if (fout_.is_open())
	{
		Close_Helper();
	}

	std::string message{ "Log::~Log(): the log system is destroyed" };
	std::cout << message << std::endl;
}

/////////////////////////////////////////////////////////////

Log* Log::Get()
{
	// returns a pointe to the instance of the Log class
	return Log::pInstance_;
}

/////////////////////////////////////////////////////////////

void Log::Print(const char* funcName, const int codeLine, const std::string & message)
{
	assert(funcName != nullptr);
	assert(message.empty() != true);

	// prints a usual message into the console and the log file
	std::stringstream ss;
	ss << funcName << "() (line: " << codeLine << "): " << message;
	Print_Helper("", ss.str().c_str());

} // end Print

/////////////////////////////////////////////////////////////

void Log::Print(const char* funcName, const int codeLine, const char* message)
{
	assert(funcName != nullptr);
	assert((message != nullptr) && (message[0] != '\0'));

	// prints a usual message into the console and the log file
	std::stringstream ss;
	ss << funcName << "() (line: " << codeLine << "): " << message;
	Print_Helper("", ss.str().c_str());
}



////////////////////////////////////////////////////////////////////////////////////////////
//                                PRIVATE FUNCTIONS
////////////////////////////////////////////////////////////////////////////////////////////

void Log::Init_Helper()
{
	// create, open a logger text file, and print a message about it

	try
	{
		fout_.open(this->logFilename_, std::ofstream::out);

		if (fout_.is_open())
		{
			std::cout << "Log::InitHelper(): the log file is created successfully" << std::endl;

			char time[9]{ '\0' };
			char date[9]{ '\0' };

			_strtime_s(time, 9);
			_strdate_s(date, 9);

			fout_ << time << ":" << date << ":\t the log file is created\n";
			fout_ << "--------------------------------------------\n\n";
		}
	}
	catch (std::ofstream::failure & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		std::cout << "Log::InitHelper(): can't open/write the log file" << std::endl;
	}

} // end Init_Helper

  /////////////////////////////////////////////////////////////

void Log::Close_Helper()
{
	// print message about closing of the logger file

	try
	{
		char time[9]{ '\0' };
		char date[9]{ '\0' };

		_strtime_s(time, 9);
		_strdate_s(date, 9);

		fout_ << "\n\n--------------------------------------------\n";
		fout_ << time << ":" << date << ":\t the end of the log file\n";
		fout_ << std::endl;

		// close the log file
		fout_.close();
	}
	catch (std::ofstream::failure & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		std::cout << "Log::InitHelper(): can't write/close the log file" << std::endl;
	}

} // end Close_Helper

/////////////////////////////////////////////////////////////

void Log::Print_Helper(const char* levtext, const char* text)
{
	// prints a message into the command prompt and into the log file
	clock_t cl = clock();
	char time[9]{ '\0' };

	_strtime_s(time, 9);
	std::cout << time << "::" << cl << "|\t" << levtext << text << std::endl;
	fout_ << time << "::" << cl << "|\t" << levtext << text << std::endl;
	fout_.flush();

} // end Print_Helper