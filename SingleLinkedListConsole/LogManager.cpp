#include "LogManager.h"
#include <cassert>
#include <stdio.h>

LogManager* LogManager::m_pInstance = NULL;
LogManager LogManager::m_logManager;

LogManager::LogManager()
{
	if (m_pInstance == 0)
		m_pInstance = const_cast<LogManager*>(this);

}

LogManager* LogManager::GetInstance()
{	
	assert(m_pInstance != 0);
	return m_pInstance;
}


LogManager::~LogManager()
{
	
}

void LogManager::outPutLog(string slog)
{
	printf("%s\r\n", slog);
}