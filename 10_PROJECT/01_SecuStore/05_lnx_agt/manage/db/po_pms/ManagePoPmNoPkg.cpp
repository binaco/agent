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
#include "ManagePoPmNoPkg.h"

//---------------------------------------------------------------------------

CManagePoPmNoPkg*	t_ManagePoPmNoPkg = NULL;

//---------------------------------------------------------------------------

CManagePoPmNoPkg::CManagePoPmNoPkg()
{
	t_DBMgrPoPmNoPkg	= new CDBMgrPoPmNoPkg();
}
//---------------------------------------------------------------------------

CManagePoPmNoPkg::~CManagePoPmNoPkg()
{
	if(t_DBMgrPoPmNoPkg)	{	delete t_DBMgrPoPmNoPkg;	t_DBMgrPoPmNoPkg = NULL;	}
}
//---------------------------------------------------------------------------

INT32		CManagePoPmNoPkg::LoadDBMS()
{
	TListDBPoPmNoPkg tDBPoPmNoPkgList;
    TListDBPoPmNoPkgItor begin, end;
	if(SetER(t_DBMgrPoPmNoPkg->LoadExecute(&tDBPoPmNoPkgList)))
    {
    	return g_nErrRtn;
    }

    begin = tDBPoPmNoPkgList.begin();	end = tDBPoPmNoPkgList.end();
    for(begin; begin != end; begin++)
    {
		AddItem(begin->tDPH.nID, *begin);
		AddKeyIDListPkg(&(*begin));
    }
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoPmNoPkg::InitPkg()
{
	TMapDBPoPmNoPkgItor begin, end;
	begin = m_tMap.begin();		end = m_tMap.end();
	for(begin; begin != end; begin++)
	{
		PDB_PO_PM_NO pdata = t_ManagePoPmNo->FindItem(begin->second.tDPH.nPolicyID);
		if(!pdata)
		{
//			WriteLogE("not find po_pm_no_pkg information [%d]:po_id[%d]:[%d]", begin->second.tDPH.nPolicyID, begin->first, ERR_INFO_NOT_OP_BECAUSE_NOT_FIND);
			continue;
		}

		pdata->tDPH._add_id_value(begin->first, begin->second.tDPH.nUnitID);
	}
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoPmNoPkg::GetHash(UINT32 nID, String& strOrgValue)
{
	PDB_PO_PM_NO_PKG pdata 			= NULL;
	{
		if( (pdata = FindItem(nID)) == NULL)
		{
			WriteLogE("not find po_pm_no_pkg by hash : [%d]", ERR_INFO_NOT_OP_BECAUSE_NOT_FIND);
			return ERR_INFO_NOT_OP_BECAUSE_NOT_FIND;
		}
	}

	{
		String strItemHash;
		strItemHash = SPrintf("%u,", pdata->tDPH.nUnitID);
		strOrgValue += strItemHash;
	}
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoPmNoPkg::AddPoPmNoPkg(DB_PO_PM_NO_PKG&	data)
{
	if(SetER(t_DBMgrPoPmNoPkg->InsertExecute(&data)))
    {
    	return g_nErrRtn;
    }

	AddItem(data.tDPH.nID, data);
	AddKeyIDListPkg(&data);

    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoPmNoPkg::EditPoPmNoPkg(DB_PO_PM_NO_PKG&	data)
{
	PDB_PO_PM_NO_PKG pdata = FindItem(data.tDPH.nID);
	if(!pdata)	return ERR_DBMS_UPDATE_FAIL;

	if(SetER(t_DBMgrPoPmNoPkg->UpdateExecute(&data)))
    {
    	return g_nErrRtn;
    }

    EditItem(data.tDPH.nID, data);

    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoPmNoPkg::DelPoPmNoPkg(UINT32 nID)
{
	PDB_PO_PM_NO_PKG pdata = FindItem(nID);
	if(!pdata)	return ERR_DBMS_DELETE_FAIL;

	if(SetER(t_DBMgrPoPmNoPkg->DeleteExecute(pdata->tDPH.nID)))
    {
    	return g_nErrRtn;
    }

	DelKeyIDListPkg(pdata);
    DeleteItem(nID);
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoPmNoPkg::ClearItemByPolicyID(UINT32 nPolicyID)
{
	TListID tIDList;
	GetItemIDList(tIDList);

	TListIDItor begin, end;
	begin = tIDList.begin();	end = tIDList.end();
	for(begin; begin != end; begin++)
	{
		PDB_PO_PM_NO_PKG pdata = FindItem(*begin);
		if(pdata->tDPH.nPolicyID != nPolicyID)	continue;

		DelPoPmNoPkg(*begin);
	}
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoPmNoPkg::ClearPkgUnitByPolicyID(UINT32 nPolicyID)
{	
	TListID tIDList;
	GetItemIDList(tIDList);

	TListIDItor begin, end;
	begin = tIDList.begin();	end = tIDList.end();
	for(begin; begin != end; begin++)
	{
		PDB_PO_HEADER pDPH = GetPoHdr(*begin);
		if(!pDPH || pDPH->nPolicyID != nPolicyID)		continue;

		DelPoPmNoPkg(*begin);
	}
	return 0;
}
//---------------------------------------------------------------------------

String					CManagePoPmNoPkg::GetName(UINT32 nID)
{
	PDB_PO_PM_NO_PKG pdata = FindItem(nID);
    if(!pdata)	return "";
    return pdata->tDPH.strName;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

INT32					CManagePoPmNoPkg::SetPkt(MemToken& SendToken)
{
    SendToken.TokenAdd_32(m_tMap.size());

	TMapDBPoPmNoPkgItor begin, end;
    begin = m_tMap.begin();	end = m_tMap.end();
    for(begin; begin != end; begin++)
    {
    	SetPkt(&(begin->second), SendToken);
    }
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoPmNoPkg::SetPkt(UINT32 nID, MemToken& SendToken)
{
	PDB_PO_PM_NO_PKG pdata = FindItem(nID);
	if(!pdata)	return -1;

	return SetPkt(pdata, SendToken);
}
//---------------------------------------------------------------------------

INT32					CManagePoPmNoPkg::SetPkt(PDB_PO_PM_NO_PKG pdata, MemToken& SendToken)
{
	SendToken.TokenAdd_DPH(pdata->tDPH);

	SendToken.TokenSet_Block();
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoPmNoPkg::GetPkt(MemToken& RecvToken, DB_PO_PM_NO_PKG& data)
{
	if (!RecvToken.TokenDel_DPH(data.tDPH))				goto	INVALID_PKT;

	RecvToken.TokenSkip_Block();
	return 0;
INVALID_PKT:
	return -1;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

INT32					CManagePoPmNoPkg::SetPktHost(UINT32 nID, MemToken& SendToken)
{
	PDB_PO_PM_NO_PKG pdata = FindItem(nID);
	if(!pdata)	return -1;

	return SetPkt(pdata, SendToken);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



