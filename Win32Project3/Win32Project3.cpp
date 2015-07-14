/**
 * @brief
 * @param      
 * @see        
 * @remarks    
 * @code               
 * @endcode    
 * @return     
**/


#include <stdio.h>
#include "stdafx.h"
#include "mmio.h"

/**
 * @brief
 * @param      
 * @see        
 * @remarks    
 * @code               
 * @endcode    
 * @return     
**/
bool create_bob_txt()
{
    // current directory 를 구한다.
    wchar_t *buf=NULL;
    uint32_t buflen = 0;
    buflen = GetCurrentDirectoryW(buflen, buf);
        if (0 == buflen)
        {
        print("err, GetCurrentDirectoryW() failed. gle = 0x%08x", GetLastError());
        return false;
        }
 
        buf = (PWSTR) malloc(sizeof(WCHAR) * buflen);
        if (0 == GetCurrentDirectoryW(buflen, buf))
        {
                print("err, GetCurrentDirectoryW() failed. gle = 0x%08x", GetLastError());
                free(buf);
                return false;
        }
 
    // current dir \\ bob.txt 파일명 생성
    wchar_t file_name[260];
    if (!SUCCEEDED(StringCbPrintfW(
                            file_name,
                            sizeof(file_name),
                            L"%ws\\bob.txt",
                            buf)))
    {  
        print("err, can not create file name");
        free(buf);
        return false;
    }
    free(buf); buf = NULL;
 
    if (true == is_file_existsW(file_name))
    {
        ::DeleteFileW(file_name);
    }
 
    // 파일 생성
    HANDLE file_handle = CreateFileW(
                                file_name,
                                                        GENERIC_WRITE,
                                                        FILE_SHARE_READ,
                                                        NULL,
                                                        CREATE_NEW,
                                                        FILE_ATTRIBUTE_NORMAL,
                                                        NULL); 
        if(file_handle == INVALID_HANDLE_VALUE)
        {                                              
        print("err, CreateFile(path=%ws), gle=0x%08x", file_name, GetLastError());
        return false;
        }
 
    // 파일에 데이터 쓰기
    DWORD bytes_written = 0;
    wchar_t string_buf[1024];
    if (!SUCCEEDED(StringCbPrintfW(
                        string_buf,
                        sizeof(string_buf),
                        L"동해물과 백두산이 마르고 닳도록 하느님이 보우하사 우리나라만세")))
    {
        print("err, can not create data to write.");
        CloseHandle(file_handle);
        return false;
    }

	char strUtf8[1024] ={0,};
	int nLen = WideCharToMultiByte(CP_UTF8, 0, string_buf, lstrlenW(string_buf), NULL, 0, NULL, NULL);
	WideCharToMultiByte (CP_UTF8, 0, string_buf, lstrlenW(string_buf), strUtf8, nLen, NULL, NULL);
 
    if (!WriteFile(file_handle, strUtf8, strlen(strUtf8), &bytes_written, NULL))
    {
        print("err, WriteFile() failed. gle = 0x%08x", GetLastError());
        CloseHandle(file_handle);
        return false;
    }
 
    // 영어로 쓰기
    if (!SUCCEEDED(StringCbPrintfW(
                        string_buf,
                        sizeof(string_buf),
                        L"All work and no play makes jack a dull boy.")))
    {
        print("err, can not create data to write.");
        CloseHandle(file_handle);
        return false;
    }

	char strUtf8b[1024] = { 0,};
	nLen = WideCharToMultiByte(CP_UTF8, 0, string_buf, lstrlenW(string_buf), NULL, 0, NULL, NULL);
	WideCharToMultiByte (CP_UTF8, 0, string_buf, lstrlenW(string_buf), strUtf8b, nLen, NULL, NULL);
 
    if (!WriteFile(file_handle, strUtf8b, strlen(strUtf8b), &bytes_written, NULL))
    {
        print("err, WriteFile() failed. gle = 0x%08x", GetLastError());
        CloseHandle(file_handle);
        return false;
    }
 
	
 
 
 
    char string_bufa[1024];
    if (!SUCCEEDED(StringCbPrintfA(
                        string_bufa,
                        sizeof(string_bufa),
                        "동해물과 백두산이 마르고 닳도록 하느님이 보우하사 우리나라만세")))
    {
        print("err, can not create data to write.");
        CloseHandle(file_handle);
        return false;
    }
 
    if (!WriteFile(file_handle, strUtf8, strlen(strUtf8), &bytes_written, NULL))
    {
        print("err, WriteFile() failed. gle = 0x%08x", GetLastError());
        CloseHandle(file_handle);
        return false;
    }
 
    // 영어로 쓰기
    if (!SUCCEEDED(StringCbPrintfA(
                        string_bufa,
                        sizeof(string_bufa),
                        "All work and no play makes jack a dull boy.")))
    {
        print("err, can not create data to write.");
        CloseHandle(file_handle);
        return false;
    }

	wchar_t strUnicode[1024] = { 0, };
	int nLen1 = MultiByteToWideChar( CP_ACP, 0, string_bufa, strlen( string_bufa ), NULL, NULL );
	MultiByteToWideChar( CP_ACP, 0, string_bufa, strlen( string_bufa ), strUnicode, nLen1 );

	char strUtf8a[1024] ={0,};
	nLen1 = WideCharToMultiByte(CP_UTF8, 0, strUnicode, lstrlenW(strUnicode), NULL, 0, NULL, NULL);
	WideCharToMultiByte (CP_UTF8, 0, strUnicode, lstrlenW(strUnicode), strUtf8a, nLen1, NULL, NULL);
 

    if (!WriteFile(file_handle, strUtf8a, strlen(strUtf8a), &bytes_written, NULL))
    {
        print("err, WriteFile() failed. gle = 0x%08x", GetLastError());
        CloseHandle(file_handle);
        return false;
    }
	
//	WCHAR tmp[MAX_PATH];
	
//	GetCurrentDirectoryW( MAX_PATH, tmp );
	
	
	CopyFile( "C:\\Users\\0x1C\\Documents\\Visual Studio 2012\\Projects\\Win32Project3\\Win32Project3\\bob.txt", "C:\\Users\\0x1C\\Documents\\Visual Studio 2012\\Projects\\Win32Project3\\Win32Project3\\bob2.txt", true );
    // 파일 닫기
	CloseHandle(file_handle);
    if (true == is_file_existsW(file_name))
    {
		 ::DeleteFileW(file_name);
    }

	

	buf=NULL;
    buflen = 0;
    buflen = GetCurrentDirectoryW(buflen, buf);
    if (0 == buflen)
    {
        print("err, GetCurrentDirectoryW() failed. gle = 0x%08x", GetLastError());
        return false;
    }
 
    buf = (PWSTR) malloc(sizeof(WCHAR) * buflen);
    if (0 == GetCurrentDirectoryW(buflen, buf))
    {
            print("err, GetCurrentDirectoryW() failed. gle = 0x%08x", GetLastError());
            free(buf);
            return false;
    }
 
    // current dir \\ bob2.txt 파일명 생성

    if (!SUCCEEDED(StringCbPrintfW(
                            file_name,
                            sizeof(file_name),
                            L"%ws\\bob2.txt",
                            buf)))
    {  
        print("err, can not create file name");
        free(buf);
        return false;
    }

 
    // 파일 읽기
    file_handle = CreateFileW(
                                file_name,
                                GENERIC_READ,
                                FILE_SHARE_READ,
                                NULL,
                                OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL,
                                NULL); 
        if(file_handle == INVALID_HANDLE_VALUE)
        {                                              
        print("err, CreateFile(path=%ws), gle=0x%08x", file_name, GetLastError());
        return false;
        }

		char consolebuf[300] = { 0, };
		DWORD dwBytesRead;
		wchar_t buff2[300] = { 0, };
		char printbuffer[300] = { 0, };
		
		ReadFile (file_handle, consolebuf, 300, &dwBytesRead, NULL);
		
		nLen = MultiByteToWideChar(CP_UTF8, 0, consolebuf, dwBytesRead, NULL, NULL);
		MultiByteToWideChar(CP_UTF8, 0, consolebuf, dwBytesRead, buff2, nLen);

		nLen = WideCharToMultiByte( CP_ACP, 0, buff2, -1, NULL, 0, NULL, NULL );	
		WideCharToMultiByte( CP_ACP, 0, buff2, -1, printbuffer, nLen, NULL, NULL );
		
	
		// readfile	
		printf( "%s\n", printbuffer );
		CloseHandle(file_handle);

		// mmio
		read_file_using_memory_map();


	if (true == is_file_existsW(file_name))
   {
       ::DeleteFileW(file_name);
    }
	
    return true;
 
}


int main( void )
{
	create_bob_txt();
}