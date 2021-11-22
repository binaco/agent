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

#ifndef DBMgrPoFaOpUnitObjPkgH
#define DBMgrPoFaOpUnitObjPkgH
//---------------------------------------------------------------------------

class CDBMgrPoFaOpUnitObjPkg : public CDBMgrBase
{
public:
	INT32			SetInitalize();

public:
	INT32			LoadDB(TListDBPoFaOpUnitObjPkg& tDBPoFaOpUnitObjPkgList);

public:
    INT32			InsertPoFaOpUnitObjPkg(DB_PO_FA_OP_UNIT_OBJ_PKG& dpfouop);
    INT32			UpdatePoFaOpUnitObjPkg(DB_PO_FA_OP_UNIT_OBJ_PKG& dpfouop);
    INT32			DeletePoFaOpUnitObjPkg(UINT32 nID);
	INT32			ClearPoFaOpUnitObjPkg();

public:
	virtual INT32	LoadExecute(PVOID lpTempletList);     
	virtual INT32	InsertExecute(PVOID lpTemplet);
	virtual INT32	UpdateExecute(PVOID lpTemplet);
	virtual INT32	DeleteExecute(UINT32 nID);
	virtual INT32	ClearExecute();


public:
	CDBMgrPoFaOpUnitObjPkg();
    ~CDBMgrPoFaOpUnitObjPkg();
};

extern CDBMgrPoFaOpUnitObjPkg*		t_DBMgrPoFaOpUnitObjPkg;

#endif
