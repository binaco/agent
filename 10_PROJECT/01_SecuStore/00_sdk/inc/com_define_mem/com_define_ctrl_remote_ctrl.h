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


#ifndef COM_DEFINE_COMMON_REMOTE_CTRL_H_938EF200_F60B_452A_BD30_A10E8507EDCC
#define COM_DEFINE_COMMON_REMOTE_CTRL_H_938EF200_F60B_452A_BD30_A10E8507EDCC

// �ڼ��� ������ �Ʒ��� ��Ű �������� �����Ͻñ� �ٶ��ϴ�.
// [PoRemoteRequest]
// http://mw.ashindev.com/wiki/index.php/CtlRemoteRequest

//-------------------------------------------------------------------
// agent alert option
#define SS_COMMON_REMOTE_CTRL_ALERT_TYPE_UNUSED							0x00000000 // ����� �˸� �޽��� ������
#define SS_COMMON_REMOTE_CTRL_ALERT_TYPE_USED							0x00000001 // ����� �˸� �޽��� ����� 

//-------------------------------------------------------------------
// remote connect mode
#define SS_COMMON_REMOTE_CTRL_CONNECT_MODE_GDI							0x00000000 // DC�� �̿��� Bitmap Cache(GDI) - �� ���� �� �⺻��
#define SS_COMMON_REMOTE_CTRL_CONNECT_MODE_DRIVER						0x00000001 // Ŀ�� ����̹� Hook ��� (�� ���� ���� �������� �ʽ��ϴ�.) 

//-------------------------------------------------------------------
// remote view only mode
#define SS_COMMON_REMOTE_CTRL_VIEW_ONLY_USED							0x00000000 // ���� ȭ���� �ܼ��� ����θ� ���
#define SS_COMMON_REMOTE_CTRL_VIEW_ONLY_UNUSED							0x00000001 // ���� ȭ�� ������ ��� ������ (���콺, Ű���� �Է��� ���� ������ PC ���� ����) 

//-------------------------------------------------------------------
#define SS_COMMON_REMOTE_CTRL_LOCALE_DEFALUT							0x00000000 // Ŭ���̾�Ʈ �������� ������ ���� �� (�̼��� �� �⺻�� DEFAULT)
#define SS_COMMON_REMOTE_CTRL_LOCALE_KOR								0x00000001 // �ѱ�
#define SS_COMMON_REMOTE_CTRL_LOCALE_ENG								0x00000002 // ����
#define SS_COMMON_REMOTE_CTRL_LOCALE_JPN								0x00000003 // �Ϻ�
#define SS_COMMON_REMOTE_CTRL_LOCALE_CHS								0x00000004 // �߱��� ��ü
#define SS_COMMON_REMOTE_CTRL_LOCALE_CHT								0x00000005 // �߱��� ��ü 
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//--------------------------------------------------------------------
#endif	//COM_DEFINE_COMMON_REMOTE_CTRL_H_938EF200_F60B_452A_BD30_A10E8507EDCC