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
#ifndef COM_DEFINE_DB_PO_HOST_RUN_H_938EF200_F60B_452A_BD30_A10E8507EDCC
#define COM_DEFINE_DB_PO_HOST_RUN_H_938EF200_F60B_452A_BD30_A10E8507EDCC

//-------------------------------------------------------------------
//host run option
#define SS_PO_HOST_RUN_OPTION_FLAG_SUPPORT_SAFE_MODE				0x00000001 // ������� ���� ����
#define SS_PO_HOST_RUN_OPTION_FLAG_SUPPORT_ASI_DEPLOY_SVR			0x00000002 // ASI ���� ������ ���� ���� ����(������Ʈ ����)
#define SS_PO_HOST_RUN_OPTION_FLAG_SUPPORT_ASI_LICENSE_SVR			0x00000004 // ASI LICENSE ������ ���� Lgn ���� ���� �˻�
#define SS_PO_HOST_RUN_OPTION_FLAG_SUPPORT_PTOP						0x00000008 // PtoP�� �̿��� �ٿ�ε� ����
#define SS_PO_HOST_RUN_OPTION_FLAG_SUPPORT_BOOT_APPLY				0x00000010 // ���ý� ��å ����
#define SS_PO_HOST_RUN_OPTION_FLAG_SUPPORT_ALLOW_MGR_CLOSE			0x00000020 // MGR ���� ��뿩��
#define SS_PO_HOST_RUN_OPTION_FLAG_SUPPORT_ALLOW_MGR_LOGIN			0x00000040 // MGR �α��� ���̱� ����
#define	SS_PO_HOST_RUN_OPTION_FLAG_SUPPORT_ALLOW_MGR_MANUAL_DEL		0x00000080 // MGR_�������� ���̱� ����
#define	SS_PO_HOST_RUN_OPTION_FLAG_SUPPORT_RESTART_SVC				0x00000100 // ���� ����� �ֱ�
#define SS_PO_HOST_RUN_OPTION_FLAG_SUPPORT_ALLOW_MGR_LOGIN_ID		0x00000200 // MGR �α��� ���̱� ���� (ID�θ� �α��� )

#define SS_PO_HOST_RUN_OPTION_FLAG_SUPPORT_MGR_IF_PORT_CHG_AUTO		0x00000400 // MGR if port ���� ���н� �ٸ� ��Ʈ�� ã�� ����.(�⺻��Ʈ���� + 3�� �����ϸ� �õ� )

//-------------------------------------------------------------------
//host mgr show type
#define SS_PO_HOST_RUN_MGR_SHOW_TYPE_NOT_USED						0 // Agt Mgr ǥ�� ����
#define SS_PO_HOST_RUN_MGR_SHOW_TYPE_NORMAL							1 // Agt Mgr ǥ��
#define SS_PO_HOST_RUN_MGR_SHOW_TYPE_HIDE_START						2 // Agt Mgr ���μ��� ����

//-------------------------------------------------------------------
//system boot chk type
#define SS_PO_HOST_RUN_BOOT_CHK_TYPE_AUTO							0
#define SS_PO_HOST_RUN_BOOT_CHK_TYPE_START_SVC						1


//-------------------------------------------------------------------
// SS_PO_HOST_RUN_OPTION_FLAG_SUPPORT_MGR_IF_PORT_CHG_AUTO ������

#define SS_PO_HOST_RUN_MGR_IF_PORT_CHG_INTERVAL						5

//--------------------------------------------------------------------

#define SS_PO_HOST_RUN_MGR_SHOW_ORDER_BIT_BLOCK_SIZE				4 // bit

#define SS_PO_HOST_RUN_MRG_SHOW_ORDER_PKG_NUM						1 // 0 : Default
#define SS_PO_HOST_RUN_MRG_SHOW_ORDER_CLS_NUM						6 // 0 : NONE,  1 : NI, 2 : NO, 3 : Circle, 4 : NP, 5:NC

#define SS_PO_HOST_RUN_MRG_SHOW_ORDER_PKG_TYPE_NONE					0x0
#define SS_PO_HOST_RUN_MRG_SHOW_ORDER_PKG_TYPE_NI					0x1
#define SS_PO_HOST_RUN_MRG_SHOW_ORDER_PKG_TYPE_NO					0x2
#define SS_PO_HOST_RUN_MRG_SHOW_ORDER_PKG_TYPE_CIRCLE				0x3
#define SS_PO_HOST_RUN_MRG_SHOW_ORDER_PKG_TYPE_NP					0x4
#define SS_PO_HOST_RUN_MRG_SHOW_ORDER_PKG_TYPE_NC					0x5

#define SS_PO_HOST_RUN_MRG_SHOW_ORDER_CLS_TYPE_NO_VULN				0x1
#define SS_PO_HOST_RUN_MRG_SHOW_ORDER_CLS_TYPE_NO_PROC				0x2
#define SS_PO_HOST_RUN_MRG_SHOW_ORDER_CLS_TYPE_NO_RS				0x3

#define SS_PO_HOST_RUN_CONN_MANAGE_ANYTIME_CONN						0
#define SS_PO_HOST_RUN_CONN_MANAGE_BOOT_DISCONN						1
#define SS_PO_HOST_RUN_CONN_MANAGE_ONEHOUR_DISCONN					2

//host run log reset flag

#define SS_PO_HOST_RUN_LOG_RESET_FLAG_DOCLOG						0x00000001 // �����α�

//--------------------------------------------------------------------

#endif	//COM_DEFINE_DB_PO_HOST_RUN_H_938EF200_F60B_452A_BD30_A10E8507EDCC