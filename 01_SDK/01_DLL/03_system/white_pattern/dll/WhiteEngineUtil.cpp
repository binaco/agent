/*
 * Copyright (C) 2021-2026 ASHINi Corp. 
 * 
 * This program is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU General Public 
 * License as published by the Free Software Foundation; either 
 * version 3 of the License, or any later version, with the additional
 * special exception to link portions of this program with the OpenSSL
 * library. See LICENSE for more details. 
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details. 
 * 
 * You should have received a copy of the GNU General Public 
 * License along with this program. If not, see <https://www.gnu.org/licenses/>.  
 *
 */

#include "stdafx.h"
#include "com_struct.h"
#include "WhiteListDef.h"
#include "AriaEx.h"
#include "WhiteEngineUtil.h"


CWhiteEngineUtil::CWhiteEngineUtil()
{

}

CWhiteEngineUtil::~CWhiteEngineUtil()
{

}

/**************************************************************************************************************
	�Լ��� :  we_init_db
	Input :
	Output :
		char *acLogMsg : ���� �޽���
	RetVal : INT32
			0 : Hash Table �޸� �ʱ�ȭ ����
			FALSE : Hash Table �޸� �ʱ�ȭ ����
	Information :
		�ؽ� ���̺� �޸𸮸� �ʱ�ȭ �ϴ� �Լ�, ��� ���� ����
**************************************************************************************************************/
INT32 CWhiteEngineUtil::InitDB(char *acLogMsg)
{
	INT32 nRetVal = 0;
	nRetVal = m_tWPtnUtil.m_tHashUtil.InitHash(acLogMsg);
	return nRetVal;
}

/**************************************************************************************************************
	�Լ��� :  we_load_db
	Input :
		char *acEnginePath : ���� ������ ���ԵǾ� �ִ� ��� (wdb ������ ��� �ε�)
	Output :
		char *acLogMsg : ���� �޽���
	RetVal : INT32
			0 : ���� ���� �޸� �ε� ����
			FALSE : ���� ���� �޸� �ε� ����
	Information :
		���� ���Ͽ� ���ִ� ���� ����Ʈ�� �޸𸮿� �ε��ϴ� �Լ�, we_load_white_list �� ��ü �Ǿ���
**************************************************************************************************************/
INT32 CWhiteEngineUtil::LoadDB(char *acEnginePath, char *acLogMsg)
{
	INT32 nRetVal = 0;
	nRetVal = m_tWPtnUtil.we_pattern_load(acEnginePath, acLogMsg);
	return nRetVal;
}

/**************************************************************************************************************
	�Լ��� :  we_create_db
	Input :
		char *acWhitePath : ȭ��Ʈ����Ʈ�� �߰��� ������ ���ԵǾ� �ִ� ��� (���� ��� ��� �˻��Ͽ� ����Ʈ�� �߰�)
		char *acEnginePath : ���� ������ ������ ���
		char *acDbName : ���� ���ϸ� (Ȯ���� ����)
	Output :
		char *acLogMsg : ���� �޽���
	RetVal : INT32
			0 : ���� ���� ���� ����
			FALSE : ���� ���� ���� ����
	Information :
		PE���� �˻��Ͽ� �޸� �ε� �� �Էµ� ���ϸ����� ���� ���� ����, �������� �ʴ� ��� we_make_wdb �ǰ�
**************************************************************************************************************/

INT32 CWhiteEngineUtil::CreateDB(char *acWhitePath, char *acEnginePath, char *acDbName, char *acLogMsg)
{
	INT32 nRetVal = 0;
	nRetVal = m_tWPtnUtil.we_pattern_create(acWhitePath, acEnginePath, acDbName, acLogMsg);
	return nRetVal;
}

/**************************************************************************************************************
	�Լ��� :  we_add_file
	Input :
		char *szPath : ȭ��Ʈ����Ʈ�� �߰��� ���� ���
	Output :
		char *acLogMsg : ���� �޽���
	RetVal : INT32
			0 : ���� �߰� ����
			FALSE : ���� �߰� ����
	Information :
		�Էµ� PE���Ͽ� ���� ���� ���� �� ����Ʈ�� �߰�, we_add_white_list�� ����
**************************************************************************************************************/

INT32 CWhiteEngineUtil::AddFile(char *szPath, char *acLogMsg)
{
	return m_tWPtnUtil.we_fadd(szPath, acLogMsg);
}

/**************************************************************************************************************
	�Լ��� :  we_del_file
	Input :
		char *szPath : ȭ��Ʈ����Ʈ���� ������ ���� ���
	Output :
		char *acLogMsg : ���� �޽���
	RetVal : INT32
			0 : ���� ���� ����
			FALSE : ���� ���� ����
	Information :
		�Էµ� PE���Ͽ� ���� ���� ���� �� ������ �ؽ��� ������ �ִ� ������ ����Ʈ���� ����, we_del_white_list�� ����
**************************************************************************************************************/

INT32 CWhiteEngineUtil::DelFile(char *szPath, char *acLogMsg)
{
	return m_tWPtnUtil.we_fdel(szPath, acLogMsg);;
}

/**************************************************************************************************************
	�Լ��� :  we_clear_file
	Input :
	Output :
	RetVal :
	Information :
		��ü ȭ��Ʈ ����Ʈ �޸� ����
**************************************************************************************************************/

void CWhiteEngineUtil::ClearFile()
{
	m_tWPtnUtil.we_fclear();
}

/**************************************************************************************************************
	�Լ��� :  we_make_db
	Input :
		char *acEnginePath : ���� ������ ������ ���
		char *acDbName : ���� ���ϸ� (Ȯ���� ����)
	Output :
		char *acLogMsg : ���� �޽���
	RetVal :
		0 : ���� ���� ���� ����
		FALSE : ���� ���� ���� ����
	Information :
		�޸𸮿� �ִ� ��ü ����Ʈ�� �Էµ� ���ϸ����� ���� ���� ����, we_make_wdb�� ����
**************************************************************************************************************/

INT32 CWhiteEngineUtil::MakeDB(char *acEnginePath, char *acDbName, char *acLogMsg)
{
	return m_tWPtnUtil.we_dbmake(acEnginePath, acDbName, acLogMsg);
}

/**************************************************************************************************************
	�Լ��� :  we_uninit_db
	Input :
	Output :
	RetVal :
	Information :
		�ؽ� ���̺� �޸𸮸� ���� �ϴ� �Լ�
**************************************************************************************************************/

void CWhiteEngineUtil::UnInitDB()
{
	m_tWPtnUtil.m_tHashUtil.UninitHashWithLock();
}

/**************************************************************************************************************
	�Լ��� :  AddWL
	Input :
		char *szPath : �߰��� ���� ���ϸ� (NULL�̸� ȭ��Ʈ����Ʈ �޸𸮷� �߰�)
		DWORD dwListSize : ȭ��Ʈ����Ʈ �޸� ������ (Ȯ�忡 ����Ͽ� ������� ����)
	Input/Output :
		PVOID pWhiteList : �߰��� ȭ��Ʈ����Ʈ �޸� (��η� �߰��ϴ� ��� �߰��� �����͸� ��ȯ)
	Output :
		char *acLogMsg : ���� �޽���
	RetVal :
		0 : ���� �߰� ����
		< 0 : ���� �߰� ����
	Information :
		���Ϸ� �߰��ϴ� ��� �� ȭ��Ʈ ����Ʈ�� �߰��ϴ� ��� ����, ���Ϸ� �߰��ϴ� ��� �߰��Ǵ� ������ ��ȯ
**************************************************************************************************************/

INT32 CWhiteEngineUtil::AddWL(char *szPath, PVOID pWhiteList, DWORD dwListSize, char *acLogMsg)
{
	PASI_WENG_WL_EX pWhiteListEx = NULL;
	INT32 nRetVal = 0;
	if(szPath == NULL && pWhiteList == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[AddWL] invalid input data");
		return -1;
	}

	pWhiteListEx = (PASI_WENG_WL_EX)malloc(sizeof(ASI_WENG_WL_EX));
	if(pWhiteListEx == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[AddWL] fail to allocate memory (%d)", errno);
		return -2;
	}
	memset(pWhiteListEx, 0, sizeof(ASI_WENG_WL_EX));

	do{
		if(szPath == NULL || szPath[0] == 0)
		{
			if(dwListSize != sizeof(ASI_WENG_WL_EX) || pWhiteList == NULL)
			{
				if(acLogMsg)
					snprintf(acLogMsg, MAX_LOGMSG, "[AddWL] invalid list addr (sz:%d)", dwListSize);
				nRetVal = -3;
				break;
			}
			memcpy(pWhiteListEx, pWhiteList, sizeof(ASI_WENG_WL_EX));
		}
		nRetVal = m_tWPtnUtil.asi_add_white_list(szPath, pWhiteListEx, acLogMsg);
		if(nRetVal < 0)
		{
			nRetVal -= 100;
			break;
		}
		if(dwListSize == sizeof(ASI_WENG_WL_EX) && pWhiteList != NULL)
		{
			memcpy(pWhiteList, pWhiteListEx, sizeof(ASI_WENG_WL_EX));
		}
		nRetVal = 0;
	}while(FALSE);
	safe_free(pWhiteListEx);
	return nRetVal;
}

/**************************************************************************************************************
	�Լ��� :  ModWL
	Input :
		PVOID pWhiteList : ������ ȭ��Ʈ����Ʈ �޸�
		DWORD dwListSize : ȭ��Ʈ����Ʈ �޸� ������ (Ȯ�忡 ����Ͽ� ������� ����)
	Output :
		char *acLogMsg : ���� �޽���
	RetVal :
		0 : ���� ���� ���� ����
		< 0 : ���� ���� ���� ����
	Information :
		�Էµ� ȭ��Ʈ ����Ʈ ����ü�� �޸𸮻��� ������ �ؽ��� ȭ��Ʈ ����Ʈ ���� ����
**************************************************************************************************************/

INT32 CWhiteEngineUtil::ModWL(PVOID pWhiteList, DWORD dwListSize, char *acLogMsg)
{
	PASI_WENG_WL_EX pWhiteListEx = NULL;
	INT32 nRetVal = 0;
	if(pWhiteList == NULL || dwListSize == 0)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[ModWL] invalid input data");
		return -1;
	}
	pWhiteListEx = (PASI_WENG_WL_EX)malloc(sizeof(ASI_WENG_WL_EX));
	if(pWhiteListEx == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[ModWL] fail to allocate memory (%d)", errno);
		return -2;
	}
	do{
		if(dwListSize != sizeof(ASI_WENG_WL_EX))
		{
			if(acLogMsg)
				snprintf(acLogMsg, MAX_LOGMSG, "[ModWL] invalid list size (%d)", dwListSize);
			nRetVal = -3;
			break;
		}
		memcpy(pWhiteListEx, pWhiteList, sizeof(ASI_WENG_WL_EX));

		nRetVal = m_tWPtnUtil.asi_mod_white_list(pWhiteListEx, acLogMsg);
		if(nRetVal < 0)
		{
			nRetVal -= 100;
			break;
		}
		nRetVal = 0;
	}while(FALSE);
	safe_free(pWhiteListEx);
	return nRetVal;
}


/**************************************************************************************************************
	�Լ��� :  DelWL
	Input :
		char *szPath : ������ ���� ���ϸ� (NULL�̸� ȭ��Ʈ����Ʈ�� �ؽ������� ����)
		DWORD dwListSize : ȭ��Ʈ����Ʈ �޸� ������ (Ȯ�忡 ����Ͽ� ������� ����)
	Input/Output :
		PVOID pWhiteList : ������ ȭ��Ʈ����Ʈ �޸� (��η� �����ϴ� ��� ������ �����͸� ��ȯ)
	Output :
		char *acLogMsg : ���� �޽���
	RetVal :
		0 : ���� ���� ����
		< 0 : ���� ���� ����
	Information :
		���Ϸ� �����ϴ� ��� �� ȭ��Ʈ ����Ʈ�� �����ϴ� ��� ����, ���Ϸ� �߰��ϴ� ��� �߰��Ǵ� ������ ��ȯ
**************************************************************************************************************/

INT32 CWhiteEngineUtil::DelWL(char *szPath, PVOID pWhiteList, DWORD dwListSize, char *acLogMsg)
{
	PASI_WENG_WL_EX pWhiteListEx = NULL;
	INT32 nRetVal = 0;

	if(szPath == NULL && pWhiteList == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[DelWL] invalid input data");
		return -1;
	}

	pWhiteListEx = (PASI_WENG_WL_EX)malloc(sizeof(ASI_WENG_WL_EX));
	if(pWhiteListEx == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[DelWL] fail to allocate memory (%d)", errno);
		return -2;
	}
	memset(pWhiteListEx, 0, sizeof(ASI_WENG_WL_EX));

	do{
		if(szPath == NULL || szPath[0] == 0)
		{
			if(dwListSize != sizeof(ASI_WENG_WL_EX) || pWhiteList == NULL)
			{
				if(acLogMsg)
					snprintf(acLogMsg, MAX_LOGMSG, "[DelWL] invalid list size (%d)", dwListSize);
				nRetVal = -3;
				break;
			}
			memcpy(pWhiteListEx, pWhiteList, sizeof(ASI_WENG_WL_EX));
		}
		nRetVal = m_tWPtnUtil.asi_del_white_list(szPath, pWhiteListEx, acLogMsg);
		if(nRetVal < 0)
		{
			nRetVal -= -100;
			break;
		}
		if(dwListSize == sizeof(ASI_WENG_WL_EX) && pWhiteList != NULL)
		{
			memcpy(pWhiteList, pWhiteListEx, sizeof(ASI_WENG_WL_EX));
		}
	}while(FALSE);
	safe_free(pWhiteListEx);
	return nRetVal;
}

/**************************************************************************************************************
	�Լ��� :  GetWL
	Input :
		char *szPath : ��ȸ�� ���� ���ϸ� (NULL�̸� ȭ��Ʈ����Ʈ�� �ؽ������� ��ȸ)
		DWORD dwListSize : ȭ��Ʈ����Ʈ �޸� ������ (Ȯ�忡 ����Ͽ� ������� ����)
	Input/Output :
		PVOID pWhiteList : ��ȸ�� ȭ��Ʈ����Ʈ �޸�
		DWORD *pdwWhiteType : ��ȸ�� ȭ��Ʈ����Ʈ ���� ����
		AS_WHITE_FILE(0x0000)	: ȭ��Ʈ����Ʈ ����
		AS_ELF_FILE(0x0001)  : ȭ��Ʈ����Ʈ �������� �ʴ� ELF ����
		AS_INVALID_FILE(0x0004) " Non ELF ���� Ȥ�� ���� ��Ȳ
	Output :
		char *acLogMsg : ���� �޽���
	RetVal :
		0 : ���� ��ȸ ����
		< 0 : ���� ��ȸ ����
	Information :
		���Ϸ� ��ȸ�ϴ� ��� �� ȭ��Ʈ ����Ʈ �ؽ��� ��ȸ�ϴ� ��� ����
**************************************************************************************************************/

INT32 CWhiteEngineUtil::GetWL(char *szPath, PVOID pWhiteList, DWORD dwListSize, DWORD *pdwWhiteType, char *acLogMsg)
{
	PASI_WENG_WL_EX pWhiteListEx = NULL;
	INT32 nRetVal = 0;
	DWORD dwWhiteType = AS_INVALID_FILE;
	if(szPath == NULL && pWhiteList == NULL || pdwWhiteType == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[GetWL] invalid input data");
		return -1;
	}
	pWhiteListEx = (PASI_WENG_WL_EX)malloc(sizeof(ASI_WENG_WL_EX));
	if(pWhiteListEx == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[GetWL] fail to allocate memory (%d)", errno);
		return -2;
	}
	memset(pWhiteListEx, 0, sizeof(ASI_WENG_WL_EX));
	
	do{
		if(szPath == NULL || szPath[0] == 0)
		{
			if(dwListSize != sizeof(ASI_WENG_WL_EX) || pWhiteList == NULL)
			{
				if(acLogMsg)
					snprintf(acLogMsg, MAX_LOGMSG, "[GetWL] invalid list size (%d)", dwListSize);
				nRetVal = -3;
				break;
			}
			memcpy(pWhiteListEx, pWhiteList, sizeof(ASI_WENG_WL_EX));
		}
		nRetVal = m_tWPtnUtil.asi_get_white_list(szPath, pWhiteListEx, &dwWhiteType, acLogMsg);
		if(nRetVal < 0)
		{
			nRetVal -= 100;
			break;
		}
		*pdwWhiteType = dwWhiteType;
		if(dwWhiteType != AS_INVALID_FILE)
		{
			if(dwListSize == sizeof(ASI_WENG_WL_EX) && pWhiteList != NULL)
			{
				memcpy(pWhiteList, pWhiteListEx, sizeof(ASI_WENG_WL_EX));
			}
		}
	}while(FALSE);
	safe_free(pWhiteListEx);
	return nRetVal;
}

/**************************************************************************************************************
	�Լ��� :  GetWLCnt
	Input :
		PVOID pPasrseData : ��ȸ�� ���� ���� ����ü (NULL�� ��� ��ü ����Ʈ)
		DWORD dwDataSize : ���� ���� ����ü ������
	Output :
		INT32 *pnCount : ���ǿ� ��ġ�ϴ� ���� ��
		char *acLogMsg : ���� �޽���
	RetVal :
		0 : ���� �� ��ȸ ����
		< 0 : ���� �� ��ȸ ����
	Information :
		�Էµ� ���� ����ü�� ��ġ�ϴ� ����Ʈ�� �� ��ȸ
**************************************************************************************************************/

INT32 CWhiteEngineUtil::GetWLCnt(PVOID pPasrseData, DWORD dwDataSize, INT32 *pnCount, char *acLogMsg)
{
	PWHITE_PARSE_DATA pRuleData = NULL;
	INT32 nRetVal = 0;
	INT32 nListCount = 0;

	if(pnCount == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[GetWLCnt] invalid input data");
		return -1;
	}
	pRuleData = (PWHITE_PARSE_DATA)malloc(sizeof(WHITE_PARSE_DATA));
	if(pRuleData == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[GetWLCnt] fail to allocate memory (%d)", errno);
		return -2;
	}
	memset(pRuleData, 0, sizeof(WHITE_PARSE_DATA));

	if(dwDataSize == sizeof(WHITE_PARSE_DATA) && pPasrseData != NULL)
	{
		memcpy(pRuleData, pPasrseData, sizeof(WHITE_PARSE_DATA));
	}
	do{
		nRetVal = m_tWPtnUtil.asi_get_white_list_count(pRuleData, &nListCount, acLogMsg);
		if(nRetVal < 0)
		{
			nRetVal -= 100;
			break;
		}
		*pnCount = nListCount;
		nRetVal = 0;
	}while(FALSE);
	safe_free(pRuleData);
	
	return nRetVal;
}

/**************************************************************************************************************
	�Լ��� :  GetAllWL
	Input :
		PVOID pPasrseData : ��ȸ�� ���� ���� ����ü (NULL�� ��� ��ü ����Ʈ, �� we_get_white_list_count ���ǰ� ������ �����̾�� ��)
		DWORD dwDataSize : ���� ���� ����ü ������
		INT32 nTotalCount : ��ȸ�� ȭ��Ʈ����Ʈ ��
	Output :
		PVOID pWhiteList : ��ȸ�� ȭ��Ʈ����Ʈ
		DWORD dwListSize : ȭ��Ʈ����Ʈ ����ü ������
		char *acLogMsg : ���� �޽���
	RetVal :
		0 : ��ü ���� ��ȸ ����
		< 0 : ��ü ���� ��ȸ ����
	Information :
		�Էµ� ���� ����ü�� ��ġ�ϴ� ����Ʈ ��ü ��ȸ
**************************************************************************************************************/

INT32 CWhiteEngineUtil::GetAllWL(PVOID pPasrseData, DWORD dwDataSize, INT32 nTotalCount, PVOID pWhiteList, DWORD dwListSize, char *acLogMsg)
{
	PWHITE_PARSE_DATA pRuleData = NULL;
	INT32 nRetVal = 0;
	PASI_WENG_WL_EX pWhiteListEx = NULL;

	if(pWhiteList == NULL || dwListSize == 0 || nTotalCount < 0)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[GetAllWL] invalid input data");
		return -1;
	}
	pRuleData = (PWHITE_PARSE_DATA)malloc(sizeof(WHITE_PARSE_DATA));
	if(pRuleData == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[GetAllWL] fail to allocate memory (%d)", errno);
		return -2;
	}
	memset(pRuleData, 0, sizeof(WHITE_PARSE_DATA));

	if(dwDataSize == sizeof(WHITE_PARSE_DATA) && pPasrseData != NULL)
	{
		memcpy(pRuleData, pPasrseData, sizeof(WHITE_PARSE_DATA));
	}

	do{
		pWhiteListEx = (PASI_WENG_WL_EX)malloc(sizeof(ASI_WENG_WL_EX)*nTotalCount);
		if(pWhiteListEx == NULL)
		{
			if(acLogMsg)
				snprintf(acLogMsg, MAX_LOGMSG, "[GetAllWL] fail to allocate memory (en:%d) (cnt:%d)", errno, nTotalCount);
			nRetVal = -3;
			break;
		}
		memset(pWhiteListEx, 0, sizeof(ASI_WENG_WL_EX)*nTotalCount);

		nRetVal = m_tWPtnUtil.asi_get_all_white_list(pRuleData, nTotalCount, pWhiteListEx, acLogMsg);
		if(nRetVal < 0)
		{
			nRetVal -= 100;
			break;
		}
		if(dwListSize == sizeof(ASI_WENG_WL_EX) && pWhiteList != NULL)
		{
			memcpy(pWhiteList, pWhiteListEx, sizeof(ASI_WENG_WL_EX)*nTotalCount);
		}
		nRetVal = 0;
	}while(FALSE);

	safe_free(pRuleData);
	safe_free(pWhiteListEx);

	return nRetVal;
}

/**************************************************************************************************************
	�Լ��� :  GetWLDBCnt
	Input :
		char *acEnginePath : ���� ������ ���ԵǾ� �ִ� ��� (wdb ���� �� ��ȸ)
	Output :
		DWORD *pdwFileCount : ���� �� ��ȯ
		char *acLogMsg : ���� �޽���
	RetVal :
		0 : ���� �� ��ȸ ����
		FALSE : ���� �� ��ȸ ����
	Information :
		�Էµ� ��ο� ���ԵǾ� �ִ� ���� ���� �� ��ȯ
**************************************************************************************************************/


INT32 CWhiteEngineUtil::GetWLDBCnt(char *szEnginePath, INT32 *pnFileCount, char *acLogMsg)
{
	return m_tWPtnUtil.asi_get_wdb_count(szEnginePath, pnFileCount, acLogMsg);
}


/**************************************************************************************************************
	�Լ��� :  GetAllWLDBHdr
	Input :
		char *acEnginePath : ���� ������ ���ԵǾ� �ִ� ��� (wdb ���� ��� ��ȸ)
		INT32 nFileCount : ���� ���� ��
		DWORD dwHdrSize : ���� ��� ���� ����ü ������
	Output :
		PVOID pWhiteHdr : ��ȯ�Ǵ� ���� ��� ���� ����Ʈ
		char *acLogMsg : ���� �޽���
	RetVal :
		0 : ��ü ���� ���� ��� ��ȸ ����
		< 0 : ��ü ���� ���� ��� ��ȸ ����
	Information :
		�Էµ� ��ο� ���ԵǾ� �ִ� ��ü ���� ���� ��� ���� ��ȸ
**************************************************************************************************************/


INT32 CWhiteEngineUtil::GetAllWLDBHdr(char *szEnginePath, INT32 nFileCount, PVOID pWhiteHdr, DWORD dwHdrSize, char *acLogMsg)
{
	PWHITE_FILE_HDR pFileHdr = NULL;
	INT32 nRetVal = 0;
	
	if(szEnginePath == NULL || nFileCount < 0 || pWhiteHdr == NULL || dwHdrSize == 0)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[GetAllWLDBHdr] invalid input data");
		return -1;
	}

	pFileHdr = (PWHITE_FILE_HDR)malloc(sizeof(WHITE_FILE_HDR)*nFileCount);
	if(pFileHdr == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[GetAllWLDBHdr] fail to allocate memory (cnt:%d) (%d)", nFileCount, errno);
		return -2;
	}
	memset(pFileHdr, 0, sizeof(WHITE_FILE_HDR)*nFileCount);

	do{
		nRetVal = m_tWPtnUtil.asi_get_all_wdb_hdr(szEnginePath, nFileCount, pFileHdr, acLogMsg);
		if(nRetVal < 0)
		{
			nRetVal -= 100;
			break;
		}
		if(sizeof(WHITE_FILE_HDR) != dwHdrSize)
		{
			if(acLogMsg)
				snprintf(acLogMsg, MAX_LOGMSG, "[GetAllWLDBHdr] invalid header size (in:%d) (sz:%d)", dwHdrSize, sizeof(WHITE_FILE_HDR));
			nRetVal = -3;
			break;
		}
		memcpy(pWhiteHdr, pFileHdr, sizeof(WHITE_FILE_HDR)*nFileCount);
		nRetVal = 0;
	}while(FALSE);
	safe_free(pFileHdr);
	return nRetVal;
}


/**************************************************************************************************************
	�Լ��� :  GetWLDBHdr
	Input :
		char *acEngineFile : ���� ���� ���
		DWORD dwHdrSize : ���� ��� ���� ����ü ������
	Output :
		PVOID pWhiteHdr : ��ȯ�Ǵ� ���� ��� ����
		char *acLogMsg : ���� �޽���
	RetVal :
		0 : ���� ���� ��� ��ȸ ����
		< 0 : ���� ���� ��� ��ȸ ����
	Information :
		�Էµ� ����� ���� ���� ��� ���� ��ȸ
**************************************************************************************************************/

INT32 CWhiteEngineUtil::GetWLDBHdr(char *acEngineFile, PVOID pWhiteHdr, DWORD dwHdrSize, char *acLogMsg)
{
	int nLen = 0;
	INT32 nRetVal = 0;
	FILE *fp = NULL;
	PWHITE_FILE_HDR pFileHdr = NULL;
	char szTempPath[MAX_PATH] = {0,};

	if(acEngineFile == NULL || pWhiteHdr == NULL || dwHdrSize == 0)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[GetWLDBHdr] invalid input data");
		return -1;
	}
	snprintf(szTempPath, MAX_PATH-1, "%s.tmp", acEngineFile);

	pFileHdr = (PWHITE_FILE_HDR)malloc(sizeof(WHITE_FILE_HDR));
	if(pFileHdr == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[GetWLDBHdr] fail to allocate memory (%d)", errno);
		return -2;
	}
	memset(pFileHdr, 0, sizeof(WHITE_FILE_HDR));

	do{
		nRetVal = AriaDeCryptFile(ASI_ARIA, acEngineFile, szTempPath, acLogMsg);
		if(nRetVal < 0)
		{
			nRetVal -= 100;
			break;
		}
		fp = fopen(szTempPath, "r");
		if(fp == NULL)
		{
			if(acLogMsg)
				snprintf(acLogMsg, MAX_LOGMSG, "[GetWLDBHdr] fail to open file %s (%d) ", szTempPath, errno);
			nRetVal = -3;
			break;
		}
		nRetVal = m_tWPtnUtil.asi_get_wdb_hdr(fp, pFileHdr, acLogMsg);
		if(nRetVal < 0)
		{
			nRetVal -= 200;
			break;
		}
		if(sizeof(WHITE_FILE_HDR) != dwHdrSize)
		{
			if(acLogMsg)
				snprintf(acLogMsg, MAX_LOGMSG, "[GetWLDBHdr] invalid header size (%d) (%d)", dwHdrSize, sizeof(WHITE_FILE_HDR));
			nRetVal = -4;
			break;
		}
		memcpy(pWhiteHdr, pFileHdr, sizeof(WHITE_FILE_HDR));
		nRetVal = 0;
	}while(FALSE);

	if(fp != NULL)
	{
		fclose(fp);
	}
	if(is_file(szTempPath) == 0)
	{
		unlink(szTempPath);
	}
	safe_free(pFileHdr);
	return nRetVal;
}

/**************************************************************************************************************
	�Լ��� :  MakeWLDB
	Input :
		char *szEngineFile : ������ ���� ���� ���
		DWORD dwCategory : ������ ���� ���� ī�װ�
		PVOID pPasrseData : ������ ���� ���� ����ü (NULL�� ��� ��ü ����Ʈ)
		DWORD dwDataSize : ���� ���� ����ü ������
	Output :
		DWORD *pdwCount : ���ǿ� ��ġ�Ͽ� ���� ���Ͽ� �߰��� ���� ��
		char *acLogMsg : ���� �޽���
	RetVal :
		0 : ���� ���� ���� ����
		< 0 : ���� ���� ���� ����
	Information :
		�޸𸮿� �ִ� ��ü ����Ʈ�� �Էµ� ���ǿ� ��ġ�ϴ� ������ �Էµ� ���� ���ϸ����� ���� ���� ����
**************************************************************************************************************/

INT32 CWhiteEngineUtil::MakeWLDB(char *szEngineFile, DWORD dwCategory, PVOID pPasrseData, DWORD dwDataSize, INT32 *pnCount, char *acLogMsg)
{
	PWHITE_PARSE_DATA pRuleData = NULL;
	INT32 nRetVal = 0;
	INT32 nListCount = 0;
	if(szEngineFile == NULL || pnCount == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[MakeWLDB] invalid input data");
		return -1;
	}

	pRuleData = (PWHITE_PARSE_DATA)malloc(sizeof(WHITE_PARSE_DATA));
	if(pRuleData == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[MakeWLDB] fail to allocate memory (%d)", errno);
		return -2;
	}
	memset(pRuleData, 0, sizeof(WHITE_PARSE_DATA));

	do{
		if(dwDataSize == sizeof(WHITE_PARSE_DATA) && pPasrseData != NULL)
		{
			memcpy(pRuleData, pPasrseData, sizeof(WHITE_PARSE_DATA));
		}
		nRetVal = m_tWPtnUtil.asi_make_wdb(szEngineFile, dwCategory, pRuleData, &nListCount, acLogMsg);
		if(nRetVal < 0)
		{
			nRetVal -= 100;
			break;
		}
		*pnCount = nListCount;
		nRetVal = 0;
	}while(FALSE);
	safe_free(pRuleData);
	return nRetVal;
}

/**************************************************************************************************************
	�Լ��� :  LoadWL
	Input :
		char *szEngineFile : �ε��� ���� ���� ���
		PVOID pPasrseData : �ε��� ���� ���� ����ü (NULL�� ��� ������ ��ü ����Ʈ)
		DWORD dwDataSize : ���� ���� ����ü ������
	Output :
		INT32 *pnCount : ���ǿ� ��ġ�Ͽ� �ε��� ���� ��
		char *acLogMsg : ���� �޽���
	RetVal :
		0 : ���� ���� �ε� ����
		< 0 : ���� ���� �ε� ����
	Information :
		���� ���Ͽ��� �Էµ� ���ǿ� ��ġ�ϴ� ������ ȭ��Ʈ����Ʈ �޸𸮿� �ε�
**************************************************************************************************************/

INT32 CWhiteEngineUtil::LoadWL(char *szEngineFile, PVOID pPasrseData, DWORD dwDataSize, INT32 *pnCount, char *acLogMsg)
{
	PWHITE_PARSE_DATA pRuleData = NULL;
	INT32 nRetVal = 0;
	INT32 nListCount = 0;

	if(szEngineFile == NULL || pnCount == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[LoadWL] invalid input data");
		return -1;
	}
	pRuleData = (PWHITE_PARSE_DATA)malloc(sizeof(WHITE_PARSE_DATA));
	if(pRuleData == NULL)
	{
		if(acLogMsg)
			snprintf(acLogMsg, MAX_LOGMSG, "[LoadWL] fail to allocate memory (%d)", errno);
		return -2;
	}
	memset(pRuleData, 0, sizeof(WHITE_PARSE_DATA));

	do{
		if(dwDataSize == sizeof(WHITE_PARSE_DATA) && pPasrseData != NULL)
		{
			memcpy(pRuleData, pPasrseData, sizeof(WHITE_PARSE_DATA));
		}
		nRetVal = m_tWPtnUtil.asi_load_white_list(szEngineFile, pRuleData, &nListCount, acLogMsg);
		if(nRetVal < 0)
		{
			nRetVal -= 100;
			break;
		}
		*pnCount = nListCount;
		nRetVal = 0;
	}while(FALSE);

	safe_free(pRuleData);

	return nRetVal;
}