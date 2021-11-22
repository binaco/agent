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

//---------------------------------------------------------------------------


#include "stdafx.h"
#include "com_struct.h"
#include "ManagePoInVulnEditApp.h"

//---------------------------------------------------------------------------

CManagePoInVulnEditApp*	t_ManagePoInVulnEditApp = NULL;

//---------------------------------------------------------------------------

CManagePoInVulnEditApp::CManagePoInVulnEditApp()
{
	t_DBMgrPoInVulnEditApp	= new CDBMgrPoInVulnEditApp();
}
//---------------------------------------------------------------------------

CManagePoInVulnEditApp::~CManagePoInVulnEditApp()
{
	if(t_DBMgrPoInVulnEditApp)	{	delete t_DBMgrPoInVulnEditApp;	t_DBMgrPoInVulnEditApp = NULL;	}
}
//---------------------------------------------------------------------------

INT32		CManagePoInVulnEditApp::LoadDBMS()
{
	TListDBPoInVulnEditApp tDBPoInVulnEditAppList;
    TListDBPoInVulnEditAppItor begin, end;
	if(SetER(t_DBMgrPoInVulnEditApp->LoadExecute(&tDBPoInVulnEditAppList)))
    {
    	return g_nErrRtn;
    }

    begin = tDBPoInVulnEditAppList.begin();	end = tDBPoInVulnEditAppList.end();
    for(begin; begin != end; begin++)
    {
    	AddItem(begin->tDPH.nID, *begin);
    }
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnEditApp::InitHash()
{
	t_ManagePoInVulnEditAppPkg->InitPkg();
	
	TListID tIDList;
	TListIDItor begin, end;

	GetItemIDList(tIDList);
	begin = tIDList.begin();		end = tIDList.end();
	for(begin; begin != end; begin++)
	{
		InitHash(*begin);
	}	
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnEditApp::InitHash(UINT32 nID)
{
	String strOrgValue;

	PDB_PO_IN_VULN_EDIT_APP pdata 			= NULL;
	{
		if( (pdata = FindItem(nID)) == NULL)
		{
			WriteLogE("not find po_in_vuln_edit_app by hash : [%d]", ERR_INFO_NOT_OP_BECAUSE_NOT_FIND);
			return ERR_INFO_NOT_OP_BECAUSE_NOT_FIND;
		}
	}

	{
		strOrgValue = SPrintf("%s,",
							GetHdrHashInfo(pdata).c_str());

		{
			TMapIDItor begin, end;
			begin = pdata->tDPH.tSubIDMap.begin();	end = pdata->tDPH.tSubIDMap.end();
			for(begin; begin != end; begin++)
			{
				String strPkgValue;
				t_ManagePoInVulnEditAppPkg->GetHash(begin->first, strPkgValue);
				strOrgValue += strPkgValue;
			}
		}
	}

	{
		char pszHashValue[CHAR_MAX_SIZE] = {0, };
		SHAString(ASIHASH_SHA_LEN_TYPE_128, strOrgValue.c_str(), strOrgValue.length(), pszHashValue, CHAR_MAX_SIZE);
		pdata->tDPH.strHash = pszHashValue;
	}
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnEditApp::AddPoInVulnEditApp(DB_PO_IN_VULN_EDIT_APP&	data)
{
	if(SetER(t_DBMgrPoInVulnEditApp->InsertExecute(&data)))
    {
    	return g_nErrRtn;
    }

    AddItem(data.tDPH.nID, data);
	InitHash(data.tDPH.nID);

    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnEditApp::EditPoInVulnEditApp(DB_PO_IN_VULN_EDIT_APP&	data)
{
	PDB_PO_IN_VULN_EDIT_APP pdata = FindItem(data.tDPH.nID);
	if(!pdata)	return ERR_DBMS_UPDATE_FAIL;

	if(SetER(t_DBMgrPoInVulnEditApp->UpdateExecute(&data)))
    {
    	return g_nErrRtn;
    }

    EditItem(data.tDPH.nID, data);
	InitHash(data.tDPH.nID);

    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnEditApp::DelPoInVulnEditApp(UINT32 nID)
{
	PDB_PO_IN_VULN_EDIT_APP pdata = FindItem(nID);
	if(!pdata)	return ERR_DBMS_DELETE_FAIL;

	if(SetER(t_DBMgrPoInVulnEditApp->DeleteExecute(pdata->tDPH.nID)))
    {
    	return g_nErrRtn;
    }

    DeleteItem(nID);
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnEditApp::ApplyPoInVulnEditApp(DB_PO_IN_VULN_EDIT_APP&	data)
{
	if(FindItem(data.tDPH.nID))
	{
		return EditPoInVulnEditApp(data);
	}
	return AddPoInVulnEditApp(data);
}
//---------------------------------------------------------------------------

String					CManagePoInVulnEditApp::GetName(UINT32 nID)
{
	PDB_PO_IN_VULN_EDIT_APP pdata = FindItem(nID);
    if(!pdata)	return "";
    return pdata->tDPH.strName;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

INT32					CManagePoInVulnEditApp::SetPkt(MemToken& SendToken)
{
    SendToken.TokenAdd_32(m_tMap.size());

	TMapDBPoInVulnEditAppItor begin, end;
    begin = m_tMap.begin();	end = m_tMap.end();
    for(begin; begin != end; begin++)
    {
    	SetPkt(&(begin->second), SendToken);
    }
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnEditApp::SetPkt(UINT32 nID, MemToken& SendToken)
{
	PDB_PO_IN_VULN_EDIT_APP pdata = FindItem(nID);
	if(!pdata)	return -1;

	SetPkt(pdata, SendToken);
	
	{
		SendToken.TokenAdd_32(pdata->tDPH.tSubIDMap.size());

		TMapIDItor begin, end;
		begin = pdata->tDPH.tSubIDMap.begin();	end = pdata->tDPH.tSubIDMap.end();
		for(begin; begin != end; begin++)
		{
			t_ManagePoInVulnEditAppPkg->SetPkt(begin->first, SendToken);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnEditApp::SetPktHost(UINT32 nID, MemToken& SendToken)
{
	PDB_PO_IN_VULN_EDIT_APP pdata = FindItem(nID);
	if(!pdata)	return -1;

	SetPkt(pdata, SendToken);

	{
		SendToken.TokenAdd_32(pdata->tDPH.tSubIDMap.size());

		TMapIDItor begin, end;
		begin = pdata->tDPH.tSubIDMap.begin();	end = pdata->tDPH.tSubIDMap.end();
		for(begin; begin != end; begin++)
		{
			t_ManagePoInVulnEditAppPkg->SetPktHost(begin->first, SendToken);
		}
	}

	return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnEditApp::SetPkt(PDB_PO_IN_VULN_EDIT_APP pdata, MemToken& SendToken)
{
	SendToken.TokenAdd_DPH(pdata->tDPH);

	SendToken.TokenSet_Block();
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnEditApp::GetPkt(MemToken& RecvToken, DB_PO_IN_VULN_EDIT_APP& data)
{
	if (!RecvToken.TokenDel_DPH(data.tDPH))					goto	INVALID_PKT;

	RecvToken.TokenSkip_Block();
	return 0;
INVALID_PKT:
	return -1;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



