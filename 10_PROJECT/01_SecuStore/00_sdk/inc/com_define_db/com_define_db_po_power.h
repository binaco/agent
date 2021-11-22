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
#ifndef COM_DEFINE_DB_PO_POWER_H_938EF200_F60B_452A_BD30_A10E8507EDCC
#define COM_DEFINE_DB_PO_POWER_H_938EF200_F60B_452A_BD30_A10E8507EDCC

//-------------------------------------------------------------------
// [HDR - nExtOption]
#define SS_PO_POWER_OPTION_MODE_SUPPORT_USER_WAIT			0x00000001 //����� ��� ���
#define	SS_PO_POWER_OPTION_MODE_SUPPORT_NOTIFY_MSG			0x00000002 //����� �˸� ���

/*
// nScPeriodType
#define SCHEDULE_PERIOD_TYPE_AUTO		0
#define SCHEDULE_PERIOD_TYPE_ONCE		1
#define SCHEDULE_PERIOD_TYPE_HOUR		2
#define SCHEDULE_PERIOD_TYPE_DAY		3	//����
#define SCHEDULE_PERIOD_TYPE_WEEK		4	//����
#define SCHEDULE_PERIOD_TYPE_MONTH		5	//�Ŵ�
*/

// nCtlMode
#define SS_PO_POWER_CONTROL_MODE_SYSTEM_TURN_ON				0x00000001 //�ý��� �ѱ�
#define	SS_PO_POWER_CONTROL_MODE_SYSTEM_TURN_OFF			0x00000002 //�ý��� ����
#define	SS_PO_POWER_CONTROL_MODE_SYSTEM_RESTART				0x00000003 //�ý��� �����

#define	SS_PO_POWER_CONTROL_MODE_MONITOR_TURN_ON			0x00000010 //����� �ѱ�
#define	SS_PO_POWER_CONTROL_MODE_MONITOR_TURN_OFF			0x00000011 //����� ����[nCtlWaitTime]

#define SS_PO_POWER_FASTBOOT_DISABLE						0x00000000 //���� ���� ���� ������
#define SS_PO_POWER_FASTBOOT_OFF							0x00000001 //���� ���� OFF
#define SS_PO_POWER_FASTBOOT_ON								0x00000002 //���� ���� ON


//--------------------------------------------------------------------
#endif	//COM_DEFINE_DB_PO_CTL_PANEL_H_938EF200_F60B_452A_BD30_A10E8507EDCC