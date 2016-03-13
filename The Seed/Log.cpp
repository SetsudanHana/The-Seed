#include "Log.h"

std::string getDate() {
	auto now = std::chrono::system_clock::now();
	auto t = std::chrono::system_clock::to_time_t(now);
	char data[30];
	ctime_s(data, 30, &t);
	std::string out(data);
	return out;
}

utils::Log::Log() {
	this->mFile.open("logs.txt", std::fstream::out);
}

utils::Log::Log(const Log &)
{
}


utils::Log::~Log(){
	this->mFile.close();
}

void utils::Log::logDebug(const std::string& TAG, const std::string& MESSAGE) {
	this->write("DEBUG", TAG, MESSAGE);
}

void utils::Log::logInfo(const std::string& TAG, const std::string& MESSAGE) {
	this->write("INFO", TAG, MESSAGE);
}

void utils::Log::logWarning(const std::string& TAG, const std::string& MESSAGE) {
	this->write("WARRNING", TAG, MESSAGE);
}

void utils::Log::logError(const std::string& TAG, const std::string& MESSAGE) {
	this->write("ERROR", TAG, MESSAGE);
}

void utils::Log::write(const std::string& PREFIX, const std::string& TAG, const std::string& MESSAGE) {
	auto date = getDate();
	auto log = date.substr(0, date.size() - 1) + " - " + PREFIX + "/" + TAG + ":" + MESSAGE + "\n";
	this->mFile.write(log.c_str(), log.size());
}
