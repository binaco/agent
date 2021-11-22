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

#if !defined(AFX_THREAD_EVT_MON_H__83ABD8B0_065D_4303_A05E_165A4583F052__INCLUDED_)
#define AFX_THREAD_EVT_MON_H__83ABD8B0_065D_4303_A05E_165A4583F052__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ThreadEvtMon.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CThreadEvtMon thread

class CThreadEvtMon : public CThreadBase
{
public:
	CThreadEvtMon();           // protected constructor used by dynamic creation
	virtual ~CThreadEvtMon();

	INT32	SetThreadID(pthread_t nTimerThreadId, pthread_t nSocketThreadId);
	VOID	CheckThreadID();
public:
	pthread_t	m_nTimerThreadId;
	pthread_t	m_nSocketThreadId;
	CMutexExt	m_tMutex;
	CTimerUtil	t_TimerUtil;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadEvtMon)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
protected:
	INT32	ChkEvtTime();

};

extern	CThreadEvtMon*	t_ThreadEvtMon;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREAD_EVT_MON_H__83ABD8B0_065D_4303_A05E_165A4583F052__INCLUDED_)
