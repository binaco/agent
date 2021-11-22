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


#ifndef ManagePoInDevOInfoH
#define ManagePoInDevOInfoH
//---------------------------------------------------------------------------

class CManagePoInDevOInfo : public CManagePoBase<DB_PO_IN_DEVO_INFO>
{
public:
	INT32					LoadDBMS();

public:
	INT32					InitHash();
	String					GetHash();
	INT32					GetHash(UINT32 nID, String& strOrgValue);

public:
	INT32					AddPoInDevOInfo(DB_PO_IN_DEVO_INFO&	didi);
    INT32					EditPoInDevOInfo(DB_PO_IN_DEVO_INFO&	didi);
    INT32					DelPoInDevOInfo(UINT32 nID);
	INT32					ApplyPoInDevOInfo(DB_PO_IN_DEVO_INFO&	didi);

public:
	String					GetName(UINT32 nID);    

public:
	INT32					SetPkt(MemToken& SendToken);
	INT32					SetPkt(UINT32 nID, MemToken& SendToken);
	INT32					SetPkt(PDB_PO_IN_DEVO_INFO pdidi, MemToken& SendToken);
	INT32					GetPkt(MemToken& RecvToken, DB_PO_IN_DEVO_INFO& didi);

public:
	CManagePoInDevOInfo();
    ~CManagePoInDevOInfo();

};

extern CManagePoInDevOInfo*	t_ManagePoInDevOInfo;

#endif
