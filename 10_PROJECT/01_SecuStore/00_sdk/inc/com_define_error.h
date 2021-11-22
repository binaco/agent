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


#ifndef Com_Error_H
#define Com_Error_H

#define	ERR_SUCCESS											0	//	��û�� �Ϸ� �Ͽ����ϴ�.
#define	ERR_UNKNOWN											1	//	��û�� �˼� ���� ������ ���� �Ͽ����ϴ�.

#define	ERR_DBMS_INSERT_FAIL								11	//	DBMS �Է��� ���� �Ͽ����ϴ�.
#define	ERR_DBMS_UPDATE_FAIL								12	//	DBMS ������ ���� �Ͽ����ϴ�.
#define	ERR_DBMS_DELETE_FAIL								13	//	DBMS ������ ���� �Ͽ����ϴ�.
#define	ERR_DBMS_SELECT_FAIL								14	//	DBMS �˻��� ���� �Ͽ����ϴ�.

#define	ERR_SOCKET_BIND_FAIL								21	//	��� ���� ��⸦ ���� �Ͽ����ϴ�.
#define	ERR_SOCKET_CONNECT_FAIL								22	//	��� ������ ���� �Ͽ����ϴ�.
#define	ERR_SOCKET_SVR_TO_CLT_INVALID_PKT					23	//	���� ���� ���� ��Ŷ�� ���� �Ǿ����ϴ�.
#define	ERR_SOCKET_CLT_TO_SVR_INVALID_PKT					24	//	���� ���� ���� ��Ŷ�� ���� �Ͽ����ϴ�.
#define	ERR_SOCKET_DISCONNECT_UNKNOWN						25	//	�˼� ���� ������ ����� ���� �Ǿ����ϴ�.
#define	ERR_SOCKET_NOT_FIND_TARGET_FOR_SEND					26	//	���� ����� ã�� �� �����ϴ�.
#define	ERR_SOCKET_TRANS_DATA_TIME_OVER						27	//	������ ���� �ð��� �ʰ� �Ǿ����ϴ�.

#define	ERR_AUTH_ACCOUNT_INFO_INVALID						31	//	����� ������ �߸� �Ǿ����ϴ�.
#define	ERR_AUTH_ACCOUNT_INFO_LOCK							32	//	����� ������ ��� ���� �Դϴ�.
#define	ERR_AUTH_ACCOUNT_INFO_DENY_IP						33	//	����� ���� �ּҰ� ���ܵǾ����ϴ�.
#define	ERR_AUTH_INVALID_REQUEST_STEP						34	//	�߸��� ���� ������ �����Ǿ����ϴ�.
#define	ERR_AUTH_INVALID_BIN_VERSION						35	//	�߸��� ��� �����Դϴ�.
#define ERR_AUTH_INVALID_OTP_CODE							36	//  �߸��� OTP �ڵ� �Դϴ�.
#define ERR_AUTH_INVALID_OTP_ENV							37	//  �߸��� OTP ȯ�� �Դϴ�.
#define ERR_AUTH_INVALID_OTP_SESSION_TIME					38	//	OTP �ڵ� �Է� �ð��� �ʰ� �Ǿ����ϴ�.
#define ERR_AUTH_INVALID_CHANGE_ENV_CONFIRM_PW				39	//	��û ����� ��ȣ�� ��ġ���� �ʽ��ϴ�.
#define ERR_AUTH_INVALID_PREVIOUSLY_USED_PASSWORD			40	//	������ ����� ��ȣ�� ����Ҽ� �����ϴ�.

#define ERR_INFO_NOT_OP_BECAUSE_NOT_EXISTS_RIGHT			40	//	������ ��� ������ ���� �Ҽ� �����ϴ�.
#define ERR_INFO_NOT_OP_BECAUSE_ADMIN_LOW_LEVEL				41	//	������ ������ ���Ƽ� ������ ���� �Ҽ� �����ϴ�.
#define	ERR_INFO_NOT_ADD_BECAUSE_EXIST_NAME					42	//	�̹� ������ �̸��� �����Ͽ� �߰� �� �� �����ϴ�.
#define	ERR_INFO_NOT_ADD_BECAUSE_EXIST_INFO					43	//	�̹� ������ ������ �����Ͽ� �߰� �� �� �����ϴ�.
#define	ERR_INFO_NOT_ADD_BECAUSE_PRE_CHECK_FAIL				44	//	���� �˻縦 �����Ͽ� �߰� �� �� �����ϴ�.
#define	ERR_INFO_NOT_EDIT_BECAUSE_NOT_FIND					51	//	������ �������� �ʾ� ���� ���� ��û�� ���� �� �� �����ϴ�.
#define	ERR_INFO_NOT_EDIT_BECAUSE_EXIST_INFO				52	//	�̹� ������ ������ �����Ͽ� ���� �� �� �����ϴ�.
#define	ERR_INFO_NOT_EDIT_BECAUSE_SAME_OLD_INFO				53	//	���� ������ �����Ͽ� ���� �� �� �����ϴ�.
#define	ERR_INFO_NOT_DELETE_BECAUSE_NOT_FIND				61	//	������ �������� �ʾ� ���� ���� ��û�� ���� �� �� �����ϴ�.
#define	ERR_INFO_NOT_DELETE_BECAUSE_EXIST_SUB_INFO			62	//	���� ������ �����Ͽ� ��û ������ ���� �� �� �����ϴ�.
#define	ERR_INFO_NOT_OP_BECAUSE_NOT_FIND					71	//	������ ã�� �� ���� ��û�� ���� �� �� �����ϴ�.
#define	ERR_INFO_NOT_OP_BECAUSE_INVALID_SET_ENV				72	//	���� ������ ��ȿ���� �ʾ� ��û�� ���� �� �� �����ϴ�.

#define	ERR_SYS_NOT_SUPPORT_SYSTEM							100	//	�������� �ʴ� �ý��� �Դϴ�.
#define	ERR_SYS_FILE_NOT_FIND								101	//	������ ã�� �� �����ϴ�.
#define	ERR_SYS_FILE_NOT_DELETE								102	//	������ ���� �� �� �����ϴ�.
#define	ERR_SYS_FILE_NOT_EXECUTE							103	//	������ ���� �� �� �����ϴ�.
#define	ERR_SYS_FILE_NOT_CREATE								104	//	���� ������ ���� �Ͽ����ϴ�.
#define	ERR_SYS_FILE_NOT_COPY								105	//	���� ���縦 ���� �Ͽ����ϴ�.
#define	ERR_SYS_FILE_INVALID_HASH							106	//	������ ���Ἲ ������ ��ġ���� �ʽ��ϴ�.
#define	ERR_SYS_FILE_NOT_DOWNLOAD							107	//	���� �ٿ�ε带 ���� �Ͽ����ϴ�.
#define ERR_SYS_FILE_INSTALL_ING							108	//	���� ��ġ�� ������ �Դϴ�.
#define ERR_SYS_FILE_NOT_FIND_CODESIGN						109	//	���� �ڵ� ���� ������ ã���� �����ϴ�.

#define ERR_ENV_STATUS_IS_NOT_LOG_ON						200	//	�α��� ���°� �ƴϹǷ� ���� �� �� �����ϴ�.

#define ERR_ENV_SORG_MAKE_GROUP_FAIL						400	//  ���� ���� �׷� ���� ������ ���� �Ͽ����ϴ�.
#define ERR_ENV_SORG_MAKE_USER_FAIL							401	//  ���� ���� ����� ���� ������ ���� �Ͽ����ϴ�.
#define ERR_ENV_SORG_MAKE_USER_PC_FAIL						402	//  ���� ���� ����� PC ���� ������ ���� �Ͽ����ϴ�.
#define ERR_ENV_SORG_SYNC_GROUP_FAIL						403	//  ���� ���� �׷� ���� ����ȭ�� ���� �Ͽ����ϴ�.
#define ERR_ENV_SORG_SYNC_USER_FAIL							404	//  ���� ���� ����� ���� ����ȭ�� ���� �Ͽ����ϴ�.

#define	ERR_POLICY_NOT_APPLY_BECAUSE_ADMIN_LEVEL_LOW		1000	//	������ ������ ���� ��å ������ ���� �Ͽ����ϴ�.
#define	ERR_POLICY_NOT_APPLY_BECAUSE_HIGH_ADMIN_LOCK		1001	//	���� �����ڰ� ���� ��� ���Ͽ� ��� �����Ͽ����ϴ�.
#define	ERR_POLICY_NOT_APPLY_BECAUSE_TARGET_EMPTY			1002	//	��å ���� ����� �������� �ʽ��ϴ�.




#endif