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
#include "LogicBase.h"

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void	CLogicBase::SendData_Lgn(PPKT_DATA pkt_data, MemToken& SendToken)
{
	SendData_Lgn(pkt_data->hdr.type, pkt_data->hdr.code, SendToken);
    return;
}
//---------------------------------------------------------------------------

void	CLogicBase::SendData_Lgn(UINT16 nType, UINT16 nCode, MemToken& SendToken)
{
	t_LgnCltUtil->Send_CLD(nType, nCode, SendToken.GetLength(), SendToken.GetData());

    return;
}
//---------------------------------------------------------------------------

void	CLogicBase::EditSKey_Lgn(UINT32 nSessionKey)
{
	t_LgnCltUtil->EditSessionKey_CLD(nSessionKey);

    return;
}
//---------------------------------------------------------------------------

void	CLogicBase::Disconnected_Lgn()
{
	t_LgnCltUtil->CloseSocket_CLD(0);
	return;
}
//---------------------------------------------------------------------------

String	CLogicBase::GetConnectAddr_Lgn()
{
	char pszAddr[CHAR_MAX_SIZE] = {0, };
	UINT32 nAddr = GetConnectIP_Lgn();

    return ConvertIP(nAddr);
}
//---------------------------------------------------------------------------

UINT32	CLogicBase::GetConnectIP_Lgn()
{
	UINT32 nAddr = 0;
	t_LgnCltUtil->GetLocalAddress_CLD(nAddr);

    return nAddr;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



