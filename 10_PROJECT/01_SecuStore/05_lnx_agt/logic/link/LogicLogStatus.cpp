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
#include "LogicLogStatus.h"

//---------------------------------------------------------------------------

CLogicLogStatus*		t_LogicLogStatus = NULL;

//---------------------------------------------------------------------------

CLogicLogStatus::CLogicLogStatus()
{
	m_strLogicName = "logic log status";
}
//---------------------------------------------------------------------------

CLogicLogStatus::~CLogicLogStatus()
{
}
//---------------------------------------------------------------------------

void		CLogicLogStatus::AnalyzePkt_LogStatus(PPKT_DATA pkt_data)
{
	InitBaseMember(pkt_data);
	switch(m_nPktCode)
    {
        default:
        {
        	WriteLogE("[%s] not define pkt code from console : [%d][%d]", m_strLogicName.c_str(), m_nPktType, m_nPktCode);
            break;
        }
    }
	InitBaseMember();
    return;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



