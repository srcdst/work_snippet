
// ATL
// read
if (::RegOpenKeyEx(HKEY_CURRENT_USER, L"software\\name", 0, KEY_READ, &hKey) != ERROR_SUCCESS)
	return FALSE;
UINT nStartCnt;
DWORD dwType = 0;
DWORD dwCountSize = sizeof(UINT);
if ((::RegQueryValueEx(hKey, _T("Count"), NULL, &dwType, (LPBYTE)&nStartCnt, &dwCountSize) != ERROR_SUCCESS)  && (dwType == REG_DWORD))
	return FALSE;
::RegCloseKey(hKey);
// del
HKEY hKey = NULL;
if (::RegOpenKeyEx(HKEY_CURRENT_USER, L"software\\name", 0, KEY_WRITE, &hKey) != ERROR_SUCCESS)
	return FALSE;
::RegDeleteValue(hKey, L"start");
::RegCloseKey(hKey);
// write
if (::RegOpenKeyEx(HKEY_CURRENT_USER, L"software\\name", 0, KEY_WRITE, &hKey) != ERROR_SUCCESS)
	return FALSE;
::RegSetValueEx(hKey, _T("Start"), 0, REG_DWORD, (const BYTE *)&nTime, sizeof(UINT));
::RegCloseKey(hKey);