// Test_c_lua.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>

extern "C"
{
    #include "lua.h"
    #include "lauxlib.h"
    #include "lualib.h"
}

using namespace std;
#pragma   comment(lib, "lua5.1.lib")

int _tmain(int argc, _TCHAR* argv[])
{
    lua_State *L = lua_open(); /* 打开 Lua */  
    luaL_openlibs(L); /* 加载 .lib 文件 */  
      
    // 加载脚本文件，需要放在程序目录   
    luaL_loadfile( L, "test.lua" );  
    lua_resume( L, 0 );  
    // 调用【ShowIm】函数   
    lua_getglobal( L, "ShowHello" );  
    if( lua_resume( L, 0 ) )  
        printf( "%s/n", lua_tostring( L, 1 ) );  
    // 调用结束   
    lua_close(L);  
  
    system("pause");  
    return 0;  
}