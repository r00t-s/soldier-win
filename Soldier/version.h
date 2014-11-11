//------------------------------------------------------------------------------------------------
//			              PARAMETERS TO BE CHANGED IN CASE OF CRISIS
//------------------------------------------------------------------------------------------------

#ifndef _VERSION_H_
#define _VERSION_H_

#include <Windows.h>

#define BUILD_VERSION		1006

/*
	USER-AGENT HISTORY

	Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.9.2.25) Gecko/20111212 Firefox/3.6.25 ( .NET CLR 3.5.30729)
	Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 6.1; WOW64; Trident/6.0)"
	--------------------------------------------------------------------------------------------------

	SOCIAL_USER_AGENT HISTORY

	Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko)	

	---------------------------------------------------------------------------------------------------

	SYNC_URL HISTORY

	/about.php
*/

#define USER_AGENT			L"Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 6.1; WOW64; Trident/6.0)"		//WinHTTPSetup			in file winhttp.cpp
#define SOCIAL_USER_AGENT	L"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:29.0) Gecko/20120101 Firefox/29.0"		//SocialWinHttpSetutp	in file	social.cpp
#define POST_PAGE			L"/index.asp"																	//WinHTTPSetup			in file winhttp.cpp

//function prototype
LPWSTR GetScoutSharedMemoryName();

#ifdef _GLOBAL_VERSION_FUNCTIONS_

/*	SHARED MEMORY HISTORY

	pServerKey[6], pServerKey[5], pServerKey[4], pServerKey[3], pServerKey[2], pServerKey[1], pServerKey[0]);
*/


LPWSTR GetScoutSharedMemoryName()
{		
	WCHAR strFormat[] = { L'%', L'0', L'2', L'X', L'%', L'0', L'2', L'X', L'%', L'0', L'2', L'X', L'%', L'0', L'2', L'X', L'%', L'0', L'2', L'X', L'%', L'0', L'2', L'X', L'%', L'0', L'2', L'X', L'%', L'0', L'2', L'X', L'%', L'0', L'2', L'X', L'\0' };
	LPWSTR pName = (LPWSTR)zalloc(20 * sizeof(WCHAR));

	_snwprintf_s(pName, 
		20,
		_TRUNCATE,
		strFormat,
		pServerKey[5], pServerKey[6], pServerKey[5], pServerKey[3], pServerKey[4], pServerKey[2], pServerKey[1], pServerKey[0], pServerKey[2]);		

	return pName;
}
#endif

#endif

//------------------------------------------------------------------------------------------------