
// Fitness App v1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFitnessAppv1App:
// See Fitness App v1.cpp for the implementation of this class
//

class CFitnessAppv1App : public CWinApp
{
public:
	CFitnessAppv1App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFitnessAppv1App theApp;
