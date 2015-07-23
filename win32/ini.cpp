// read ini from working dir
TCHAR szCurrentPath[MAX_PATH] = {0};
TCHAR szIniFileName[MAX_PATH] = {0};
INT nVal = 0;

GetCurrentDirectory(sizeof(szCurrentPath), szCurrentPath);
_tcscpy(szIniFileName, szCurrentPath);
_tcscat(szIniFileName, _T("\\cfg.ini"));
nVal = GetPrivateProfileInt(_T("setup"), _T("AutoInstall"), 0, szIniFileName);
// https://msdn.microsoft.com/en-us/library/windows/desktop/ms724345(v=vs.85).aspx