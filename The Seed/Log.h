#pragma once
#include "stdafx.h"

namespace utils {

	class Log {

	public:
		~Log();

		static Log* Instance() {
			static Log instance;
			return &instance;
		}

		void logDebug(const std::string& TAG, const std::string& MESSAGE);
		void logInfo(const std::string& TAG, const std::string& MESSAGE);
		void logWarrning(const std::string& TAG, const std::string& MESSAGE);
		void logError(const std::string& TAG, const std::string& MESSAGE);

	private:
		Log();
		Log(const Log&);
		std::fstream mFile;

		void write(const std::string& PREFIX, const std::string& TAG, const std::string& MESSAGE);
	};

}