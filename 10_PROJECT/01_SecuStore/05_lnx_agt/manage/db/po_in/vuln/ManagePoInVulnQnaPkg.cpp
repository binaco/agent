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
#include "ManagePoInVulnQnaPkg.h"

//---------------------------------------------------------------------------

CManagePoInVulnQnaPkg*	t_ManagePoInVulnQnaPkg = NULL;

//---------------------------------------------------------------------------

CManagePoInVulnQnaPkg::CManagePoInVulnQnaPkg()
{
	t_DBMgrPoInVulnQnaPkg	= new CDBMgrPoInVulnQnaPkg();
}
//---------------------------------------------------------------------------

CManagePoInVulnQnaPkg::~CManagePoInVulnQnaPkg()
{
	if(t_DBMgrPoInVulnQnaPkg)	{	delete t_DBMgrPoInVulnQnaPkg;	t_DBMgrPoInVulnQnaPkg = NULL;	}
}
//---------------------------------------------------------------------------

INT32		CManagePoInVulnQnaPkg::LoadDBMS()
{
	TListDBPoInVulnQnaPkg tDBPoInVulnQnaPkgList;
    TListDBPoInVulnQnaPkgItor begin, end;
	if(SetER(t_DBMgrPoInVulnQnaPkg->LoadExecute(&tDBPoInVulnQnaPkgList)))
    {
    	return g_nErrRtn;
    }

    begin = tDBPoInVulnQnaPkgList.begin();	end = tDBPoInVulnQnaPkgList.end();
    for(begin; begin != end; begin++)
    {
		AddItem(begin->tDPH.nID, *begin);
		AddKeyIDListPkg(&(*begin));
    }
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnQnaPkg::InitPkg()
{
	TMapDBPoInVulnQnaPkgItor begin, end;
	begin = m_tMap.begin();		end = m_tMap.end();
	for(begin; begin != end; begin++)
	{
		PDB_PO_IN_VULN_QNA pdata = t_ManagePoInVulnQna->FindItem(begin->second.tDPH.nPolicyID);
		if(!pdata)
		{
			if(begin->second.tDPH.nPolicyID != 0)
				WriteLogE("not find po_in_vuln_qna_pkg information [%d]:po_id[%d]:[%d]", begin->second.tDPH.nPolicyID, begin->first, ERR_INFO_NOT_OP_BECAUSE_NOT_FIND);
			continue;
		}

		pdata->tDPH._add_id_value(begin->first, begin->second.tDPH.nUnitID);
	}
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnQnaPkg::GetHash(UINT32 nID, String& strOrgValue)
{
	PDB_PO_IN_VULN_QNA_PKG pdata 			= NULL;
	{
		if( (pdata = FindItem(nID)) == NULL)
		{
			if(nID != 0)
				WriteLogE("not find po_in_vuln_qna_pkg by hash : [%d]", ERR_INFO_NOT_OP_BECAUSE_NOT_FIND);
			return ERR_INFO_NOT_OP_BECAUSE_NOT_FIND;
		}
	}

	{
		t_ManagePoInVulnQnaUnit->GetHash(pdata->tDPH.nUnitID, strOrgValue);
	}
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnQnaPkg::AddPoInVulnQnaPkg(DB_PO_IN_VULN_QNA_PKG&	data)
{
	if(SetER(t_DBMgrPoInVulnQnaPkg->InsertExecute(&data)))
    {
    	return g_nErrRtn;
    }

	AddItem(data.tDPH.nID, data);
	AddKeyIDListPkg(&data);

    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnQnaPkg::EditPoInVulnQnaPkg(DB_PO_IN_VULN_QNA_PKG&	data)
{
	PDB_PO_IN_VULN_QNA_PKG pdata = FindItem(data.tDPH.nID);
	if(!pdata)	return ERR_DBMS_UPDATE_FAIL;

	if(SetER(t_DBMgrPoInVulnQnaPkg->UpdateExecute(&data)))
    {
    	return g_nErrRtn;
    }

    EditItem(data.tDPH.nID, data);

    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnQnaPkg::DelPoInVulnQnaPkg(UINT32 nID)
{
	PDB_PO_IN_VULN_QNA_PKG pdata = FindItem(nID);
	if(!pdata)	return ERR_DBMS_DELETE_FAIL;

	if(SetER(t_DBMgrPoInVulnQnaPkg->DeleteExecute(pdata->tDPH.nID)))
    {
    	return g_nErrRtn;
    }

	DelKeyIDListPkg(pdata);
    DeleteItem(nID);
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnQnaPkg::ClearItemByPolicyID(UINT32 nPolicyID)
{
	TListID tIDList;
	GetItemIDList(tIDList);

	TListIDItor begin, end;
	begin = tIDList.begin();	end = tIDList.end();
	for(begin; begin != end; begin++)
	{
		PDB_PO_IN_VULN_QNA_PKG pdata = FindItem(*begin);
		if(pdata->tDPH.nPolicyID != nPolicyID)	continue;

		DelPoInVulnQnaPkg(*begin);
	}
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnQnaPkg::ClearPkgUnitByPolicyID(UINT32 nPolicyID)
{	
	TListID tIDList;
	GetItemIDList(tIDList);

	TListIDItor begin, end;
	begin = tIDList.begin();	end = tIDList.end();
	for(begin; begin != end; begin++)
	{
		PDB_PO_HEADER pDPH = GetPoHdr(*begin);
		if(!pDPH || pDPH->nPolicyID != nPolicyID)		continue;

		if(IsMultiUsedUnit(nPolicyID, pDPH->nUnitID) == 0)
		{
			t_ManagePoInVulnQnaUnit->DelPoInVulnQnaUnit(pDPH->nUnitID);
		}

		DelPoInVulnQnaPkg(*begin);
	}
	return 0;
}
//---------------------------------------------------------------------------

String					CManagePoInVulnQnaPkg::GetName(UINT32 nID)
{
	PDB_PO_IN_VULN_QNA_PKG pdata = FindItem(nID);
    if(!pdata)	return "";
    return pdata->tDPH.strName;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

INT32					CManagePoInVulnQnaPkg::SetPkt(MemToken& SendToken)
{
    SendToken.TokenAdd_32(m_tMap.size());

	TMapDBPoInVulnQnaPkgItor begin, end;
    begin = m_tMap.begin();	end = m_tMap.end();
    for(begin; begin != end; begin++)
    {
    	SetPkt(&(begin->second), SendToken);
    }
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnQnaPkg::SetPkt(UINT32 nID, MemToken& SendToken)
{
	PDB_PO_IN_VULN_QNA_PKG pdata = FindItem(nID);
	if(!pdata)	return -1;

	return SetPkt(pdata, SendToken);
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnQnaPkg::SetPkt(PDB_PO_IN_VULN_QNA_PKG pdata, MemToken& SendToken)
{
	SendToken.TokenAdd_DPH(pdata->tDPH);

	SendToken.TokenSet_Block();
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManagePoInVulnQnaPkg::GetPkt(MemToken& RecvToken, DB_PO_IN_VULN_QNA_PKG& data)
{
	if (!RecvToken.TokenDel_DPH(data.tDPH))				goto	INVALID_PKT;

	RecvToken.TokenSkip_Block();
	return 0;
INVALID_PKT:
	return -1;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

INT32					CManagePoInVulnQnaPkg::SetPktHost(UINT32 nID, MemToken& SendToken)
{
	PDB_PO_IN_VULN_QNA_PKG pdata = FindItem(nID);
	if(!pdata)	return -1;

	SetPkt(pdata, SendToken);

	return t_ManagePoInVulnQnaUnit->SetPkt(pdata->tDPH.nUnitID, SendToken);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



