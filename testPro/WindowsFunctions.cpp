#include "WindowsFunctions.h"
#include <shlobj.h>
#include <windows.h>
#include <algorithm>

std::string GetAppDataPath()
{
    char path[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, path))) 
    {
        std::string p = std::string(path);
        std::replace(p.begin(), p.end(), '\\', '/');
        return p;
    }
        
    else 
    {
        return "";
    }
    
}
