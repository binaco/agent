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
 */
#ifndef COM_DEFINE_DB_PO_HOST_CLEAR_H_938EF200_F60B_452A_BD30_A10E8507EDCC
#define COM_DEFINE_DB_PO_HOST_CLEAR_H_938EF200_F60B_452A_BD30_A10E8507EDCC

//-------------------------------------------------------------------
//host clear [ nChkType ]

#define SS_PO_HOST_CLEAR_CHECK_OPTION_DISCON_DT				0x00000001 // ���� ���� ��¥
#define SS_PO_HOST_CLEAR_CHECK_OPTION_IP_ADDRESS			0x00000002 // ������Ʈ �ּ� �ߺ�
//#define SS_PO_HOST_CLEAR_CHECK_OPTION_MAC_ADDRESS			0x00000004 // ������Ʈ Mac �ּ� �ߺ�

//-------------------------------------------------------------------
//host clear [ nDisposalType ]

#define SS_PO_HOST_CLEAR_DISPOSAL_TYPE_SLEEP				0x00000001 // �޸� ó���� ���
#define SS_PO_HOST_CLEAR_DISPOSAL_TYPE_REMOVE				0x00000002 // ���� ó���� ���
#define SS_PO_HOST_CLEAR_DISPOSAL_TYPE_SLEEP_AND_REMOVE		0x00000004 // �޸� �� ���� ó�� ���

//--------------------------------------------------------------------
#endif	//COM_DEFINE_DB_PO_HOST_CLEAR_H_938EF200_F60B_452A_BD30_A10E8507EDCC