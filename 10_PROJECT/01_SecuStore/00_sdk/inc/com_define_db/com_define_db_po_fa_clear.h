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
#ifndef COM_DEFINE_DB_PO_FA_CLEAR_H_938EF200_F60B_452A_BD30_A10E8507EDCC
#define COM_DEFINE_DB_PO_FA_CLEAR_H_938EF200_F60B_452A_BD30_A10E8507EDCC


//-------------------------------------------------------------------
//fa clear file ptn type
#define SS_PO_FA_CLEAR_PTN_TYPE_GLOBAL						0 // 
#define SS_PO_FA_CLEAR_PTN_TYPE_LOCAL						1 // 

//-------------------------------------------------------------------
//fa clear scan type
#define SS_PO_FA_CLEAR_SCAN_TYPE_AUTO						0
#define SS_PO_FA_CLEAR_SCAN_TYPE_DEMAND						1

//-------------------------------------------------------------------
//fa clear file check type
#define SS_PO_FA_CLEAR_FILE_CHK_TYPE_CREATE_DT				0	// ���� �ð� ����
#define SS_PO_FA_CLEAR_FILE_CHK_TYPE_MODIFY_DT				1	// ���� �ð� ����
#define SS_PO_FA_CLEAR_FILE_CHK_TYPE_ACCESS_DT				2	// ���� �ð� ����
#define SS_PO_FA_CLEAR_FILE_CHK_TYPE_MANUAL					3	// ����� ����

//--------------------------------------------------------------------

#define SS_PO_FA_CLEAR_UNIT_OPTION_FLAG_SCAN_DOC_FILE_FMT				0x00000001 // ���� ���� �˻� ����
#define SS_PO_FA_CLEAR_UNIT_OPTION_FLAG_EXCLUDE_DEFAULT_PATH			0x00000002 // �⺻ ���� ��� ( �⺻ ���� ��οɼ��� �ش� �ɼ��� ������� ������/ ���� ��쿡�� ����� )
#define SS_PO_FA_CLEAR_UNIT_OPTION_FLAG_EXCLUDE_ALL_PATH				0x00000004 // �⺻ ���ܸ� ��� ��� ����
#define SS_PO_FA_CLEAR_UNIT_OPTION_FLAG_SCAN_TYPE_DEMAND_NON_FIND_AUTO	0x00000008 // ��ĵ Ÿ���� ����� �����ϰ�� ��å�� ���ؼ� �ڵ���ĵ ���� �ʰ� ����� ��ĵ â�� ���.
#define SS_PO_FA_CLEAR_UNIT_OPTION_FLAG_NOTIFY_EXCEPT_DOC_DEL_END		0x00000010 // �˸� ���� ����
#define SS_PO_FA_CLEAR_UNIT_OPTION_FLAG_NOTIFY_EXCEPT_SCH_INFO			0x00000020 // �˸� ���� ����


//--------------------------------------------------------------------
//net drive mode
#define SS_PO_FA_CLEAR_UNIT_NET_DRIVE_TYPE_EXCLUDE			0
#define SS_PO_FA_CLEAR_UNIT_NET_DRIVE_TYPE_INCLUDE			1
#define SS_PO_FA_CLEAR_UNIT_NET_DRIVE_TYPE_SINGLE_SELECT	10


//--------------------------------------------------------------------
//po fa clear extoption
#define SS_PO_FA_CLEAR_EXT_OPTION_FLAG_SHOW_MANUAL_DEL_BY_USER_TO_AGENT			0x00000001	// ����� ���� �������� �ɼ�
#define SS_PO_FA_CLEAR_EXT_OPTION_FLAG_SCHEDULE_USER_DELETION					0x00000002	// ����� ���� ����
#define SS_PO_FA_CLEAR_EXT_OPTION_FLAG_SECU_DELETE_DEMAND						0x00000004	// ���� ���� ����
#define SS_PO_FA_CLEAR_EXT_OPTION_FLAG_SECU_DELETE_AUTO							0x00000008	// �ڵ� ���� ����

#define SS_PO_FA_CLEAR_EXT_OPTION_FLAG_EXPLORER_POPUP						(SS_PO_FA_CLEAR_EXT_OPTION_FLAG_SECU_DELETE_DEMAND | SS_PO_FA_CLEAR_EXT_OPTION_FLAG_SCHEDULE_USER_DELETION)
#define SS_PO_FA_CLEAR_EXT_OPTION_FLAG_SECU_DELETE_ALL						(SS_PO_FA_CLEAR_EXT_OPTION_FLAG_SECU_DELETE_DEMAND | SS_PO_FA_CLEAR_EXT_OPTION_FLAG_SECU_DELETE_AUTO)

//-------------------------------------------------------------------
//po fa clear delete method
#define SS_PO_FA_CLEAR_OPTION_DEL_METHOD_SDELETE						0x00000000 // SDELETE
#define SS_PO_FA_CLEAR_OPTION_DEL_METHOD_WIPE							0x00000001 // FAST WIPE

//--------------------------------------------------------------------

#endif	//COM_DEFINE_DB_PO_FA_CLEAR_H_938EF200_F60B_452A_BD30_A10E8507EDCC