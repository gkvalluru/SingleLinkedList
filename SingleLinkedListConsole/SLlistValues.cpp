
#include "SLlistValues.h"
#include "LogManager.h"

CSLlistValues * CListData::CreateNode()
{
	m_iListCount++;
	if (pSlistData == NULL)
	{
		pSlistData = new CSLlistValues();
		pSlistData->pNextValue = NULL;
		return pSlistData;
	}
	else
	{
		CSLlistValues *pNewNode = NULL;
		pNewNode = new CSLlistValues(); 
		pNewNode->pNextValue = NULL;
		return pNewNode;
	}
}


void CListData::clearlist()
{
	CSLlistValues *pTemp = NULL;
	if (pSlistData != NULL)
		pTemp = pSlistData;

	while(pTemp != NULL)
	{
		CSLlistValues *pNextNode = NULL;
		pNextNode = pTemp->pNextValue;
		
		delete pTemp;
		pTemp = NULL;
		pTemp = pNextNode;
	}
	
	pSlistData = NULL;

}

void CListData::AddValuesToListAtFront(string sValue, int iVal)
{
	LogManager *logManger = LogManager::GetInstance();
	logManger->outPutLog(sValue);

	CSLlistValues *pNode = NULL;

	if (pSlistData == NULL)
	{
		pNode = CreateNode();
		pNode->pNextValue = NULL;
		pNode->SetValues(sValue, iVal);
		pSlistData = pNode;
		return;
	}

	pNode = CreateNode();
	pNode->pNextValue = NULL;
	pNode->SetValues(sValue, iVal);
	pNode->pNextValue = pSlistData;
	pSlistData = pNode;
}


void CListData::AddValuesToListAtheEnd(string sValue, int iVal)
{
	CSLlistValues *pNode, *pEnd = NULL;

	if (pSlistData == NULL)
	{
		pNode = CreateNode();
		pNode->pNextValue = NULL;
		pNode->SetValues(sValue, iVal);
		pSlistData = pNode;
		return;
	}

	pEnd = CreateNode();
	pEnd->SetValues(sValue, iVal);

	for (pNode = pSlistData; pNode != NULL; pNode = pNode->pNextValue)
	{
		if (pNode->pNextValue == NULL)
		{
			pNode->pNextValue = pEnd;
			break;
		}
	}
}

void CListData::AddvaluesAtSpecificPosition(string sValue, int iVal, int iPos)
{
	if (iPos <= m_iListCount && iPos != 0)
	{
		CSLlistValues *pNode, *pNext, *pCurrent = NULL;
		pNode = CreateNode();
		pNode->pNextValue = NULL;
		pNode->SetValues(sValue, iVal);

		int iCount = 1;

		for (pNext = pSlistData; pNext != NULL; pNext = pNext->pNextValue)
		{				

			if (iCount == iPos)
			{
				pCurrent = pNext;
				pNode->pNextValue = pNext->pNextValue;
				pCurrent->pNextValue = pNode;
				
				break;
			}			
		}
	}
}