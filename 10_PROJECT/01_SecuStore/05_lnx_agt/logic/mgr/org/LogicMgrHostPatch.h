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


#ifndef LogicMgrHostPatchH
#define LogicMgrHostPatchH
//---------------------------------------------------------------------------

class CLogicMgrHostPatch	: public CLogicBase
{
private:
	INT32		AnalyzePkt_FromMgr_Ext();
	INT32		AnalyzePkt_FromMgr_Edit_Ext();

public:
	void		ScanPatchList(UINT32 nPolicy = 0, UINT32 nItemID = 0);
	void		SendPkt_HostPatch(UINT32 nWorkID);
	void		SendPkt_Sync();

private:
	void		MakePatchInfo(TListDBHostPatch& tUnitList);

public:
	CLogicMgrHostPatch();
    ~CLogicMgrHostPatch();
};

extern CLogicMgrHostPatch*		t_LogicMgrHostPatch;

#endif
