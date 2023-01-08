#pragma once

#include<string>
using namespace std;

class LogManager
{
public:
	virtual ~LogManager();
	static LogManager* GetInstance();
	void outPutLog(string slog);
	
private:
	LogManager();

	static LogManager* m_pInstance;
	static LogManager m_logManager;

};
