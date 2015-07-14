// stdafx.cpp : source file that includes just the standard includes
// Win32Project3.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
void print(_In_ const char* fmt, _In_ ...)
{
        char log_buffer[2048];
    va_list args;
 
    va_start(args,fmt);
    HRESULT hRes = StringCbVPrintfA(log_buffer, sizeof(log_buffer), fmt, args);
    if (S_OK != hRes)
    {
        fprintf(
            stderr,
            "%s, StringCbVPrintfA() failed. res = 0x%08x",
            __FUNCTION__,
            hRes
            );
        return;
    }
 
    OutputDebugStringA(log_buffer);
    fprintf(stdout, "%s \n", log_buffer);
}

bool is_file_existsW(_In_ const wchar_t* file_path)
{
	_ASSERTE(NULL != file_path);
	_ASSERTE(TRUE != IsBadStringPtrW(file_path, MAX_PATH));
	if ((NULL == file_path) || (TRUE == IsBadStringPtrW(file_path, MAX_PATH))) return false;

	WIN32_FILE_ATTRIBUTE_DATA info = {0};

	if (GetFileAttributesExW(file_path, GetFileExInfoStandard, &info)==0)
		return false;
	else
		return true;
}