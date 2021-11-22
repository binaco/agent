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
 * 
 */


#include "stdafx.h"
#include "com_struct.h"
#include "DBMgrPoInDevOBL.h"

//---------------------------------------------------------------------------

CDBMgrPoInDevOBL*		t_DBMgrPoInDevOBL = NULL;

//---------------------------------------------------------------------------

CDBMgrPoInDevOBL::CDBMgrPoInDevOBL()
{
	m_strDBTName = "po_in_devo_bl";
}
//---------------------------------------------------------------------------

CDBMgrPoInDevOBL::~CDBMgrPoInDevOBL()
{
}
//---------------------------------------------------------------------------

INT32			CDBMgrPoInDevOBL::SetInitalize()
{
    {
    	
	}
	//WriteLogN("current file dbms : [po_in_devo_bl][%d]", m_nDBSVer);
    return 0;
}
//---------------------------------------------------------------------------

INT32			CDBMgrPoInDevOBL::LoadDB(TListDBPoInDevOBL& tDBPoInDevOBLList)
{
    UINT32 nReadCnt = 0;
    DB_PO_IN_DEVO_BL dpfn;

    INT32 nIndex = 0;

    m_strQuery = SPrintf(DBMS_POLICY_QUERY_HDR_SELECT
						" FROM po_in_devo_bl WHERE used_flag=1;");
    if(DBOP_Check(ExecuteQuery(m_strQuery)))		return ERR_DBMS_SELECT_FAIL;

    
    do
    {
		nIndex = 0;
		DB_PO_HEADER& tDPH = dpfn.tDPH;

		tDPH					= GetDBField_PoHDR(nIndex);
		
        tDBPoInDevOBLList.push_back(dpfn);
        if(m_nLoadMaxID < UINT32(tDPH.nID))	m_nLoadMaxID = tDPH.nID;
        nReadCnt++;
    }while(Next());
	m_nLoadNumber = tDBPoInDevOBLList.size();
	WriteLogN("load database : [%s][%u]", m_strDBTName.c_str(), m_nLoadNumber);
    return 0;
}
//---------------------------------------------------------------------------

INT32			CDBMgrPoInDevOBL::InsertPoInDevOBL(DB_PO_IN_DEVO_BL& dpfn)
{
	DB_PO_HEADER& tDPH = dpfn.tDPH;

	m_strQuery = SPrintf("INSERT INTO po_in_devo_bl("
						DBMS_POLICY_QUERY_HDR_INSERT_NAME
						") VALUES (%s"
						");",
                        GetPoHDRQuery_InsertValue(tDPH).c_str());

	if(DBOP_Check(ExecuteQuery(m_strQuery)))		return ERR_DBMS_INSERT_FAIL;

	if(tDPH.nID == 0)
		tDPH.nID      = GetLastID();

    return 0;
}
//---------------------------------------------------------------------------

INT32			CDBMgrPoInDevOBL::UpdatePoInDevOBL(DB_PO_IN_DEVO_BL& dpfn)
{
	DB_PO_HEADER& tDPH = dpfn.tDPH;

	m_strQuery = SPrintf("UPDATE po_in_devo_bl SET %s"
						" WHERE id=%u;",
						GetPoHDRQuery_Update(tDPH).c_str(),
						tDPH.nID);

	if(DBOP_Check(ExecuteQuery(m_strQuery)))		return ERR_DBMS_UPDATE_FAIL;

    return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------  
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

INT32	CDBMgrPoInDevOBL::LoadExecute(PVOID lpTempletList)
{
	TListDBPoInDevOBL* ptDBList = (TListDBPoInDevOBL*)lpTempletList;

    return LoadDB(*ptDBList);
}
//---------------------------------------------------------------------------

INT32	CDBMgrPoInDevOBL::InsertExecute(PVOID lpTemplet)
{
	PDB_PO_IN_DEVO_BL pd_t = (PDB_PO_IN_DEVO_BL)lpTemplet;

    return InsertPoInDevOBL(*pd_t);
}
//---------------------------------------------------------------------------

INT32	CDBMgrPoInDevOBL::UpdateExecute(PVOID lpTemplet)
{
	PDB_PO_IN_DEVO_BL pd_t = (PDB_PO_IN_DEVO_BL)lpTemplet;

    return UpdatePoInDevOBL(*pd_t);
}
//---------------------------------------------------------------------------

INT32	CDBMgrPoInDevOBL::DeleteExecute(UINT32 nID)
{
	return CDBMgrBase::DeleteExecute(nID);
}
//---------------------------------------------------------------------------






