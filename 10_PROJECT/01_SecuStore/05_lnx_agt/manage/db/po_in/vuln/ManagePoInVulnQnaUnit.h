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
#ifndef ManagePoInVulnQnaUnitH
#define ManagePoInVulnQnaUnitH
//---------------------------------------------------------------------------

class CManagePoInVulnQnaUnit : public CManagePoBase<DB_PO_IN_VULN_QNA_UNIT>
{
public:
	INT32					LoadDBMS();

public:
	INT32					GetHash(UINT32 nID, String& strOrgValue);

public:
	INT32					AddPoInVulnQnaUnit(DB_PO_IN_VULN_QNA_UNIT&	data);
    INT32					EditPoInVulnQnaUnit(DB_PO_IN_VULN_QNA_UNIT&	data);
	INT32					DelPoInVulnQnaUnit(UINT32 nID);
	INT32					ApplyPoInVulnQnaUnit(DB_PO_IN_VULN_QNA_UNIT&	data);

public:
	String					GetName(UINT32 nID);    

public:
	INT32					SetPkt(MemToken& SendToken);
	INT32					SetPkt(UINT32 nID, MemToken& SendToken);
	INT32					SetPkt(PDB_PO_IN_VULN_QNA_UNIT pdata, MemToken& SendToken);
	INT32					GetPkt(MemToken& RecvToken, DB_PO_IN_VULN_QNA_UNIT& data);

public:
	CManagePoInVulnQnaUnit();
    ~CManagePoInVulnQnaUnit();

};

extern CManagePoInVulnQnaUnit*	t_ManagePoInVulnQnaUnit;

#endif
