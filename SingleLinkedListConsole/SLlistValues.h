#pragma once

#include <string>
#include "LogManager.h"

using namespace std;

class CSLlistValues
{

public:
	CSLlistValues()
	{		
	}

	~CSLlistValues()
	{

	}

	void SetValues(string sValue, int iVal)
	{
		m_sValue = sValue;
		m_iVal = iVal;
	}

	CSLlistValues *pNextValue;
	
private:	
	string m_sValue;
	int m_iVal;
};


class CListData
{
public:
	CListData()
	{
		pSlistData = NULL;
		m_iListCount = 0;
	}

	~CListData() 
	{
		clearlist();
	}

	void clearlist();	
	CSLlistValues * CreateNode();
	void AddValuesToListAtFront(string sValue, int iVal);
	//traverse value list and plug this one in at the end
	void AddValuesToListAtheEnd(string sValue, int iVal);

	void AddvaluesAtSpecificPosition(string sValue, int iVal, int iPos);
	

private:
	CSLlistValues *pSlistData;
	int m_iListCount;
};