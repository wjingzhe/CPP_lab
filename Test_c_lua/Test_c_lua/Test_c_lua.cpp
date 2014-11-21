// Test_c_lua.cpp : �������̨Ӧ�ó������ڵ㡣
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
    lua_State *L = lua_open(); /* �� Lua */  
    luaL_openlibs(L); /* ���� .lib �ļ� */  
      
    // ���ؽű��ļ�����Ҫ���ڳ���Ŀ¼   
    luaL_loadfile( L, "test.lua" );  
    lua_resume( L, 0 );  
    // ���á�ShowIm������   
    lua_getglobal( L, "ShowHello" );  
    if( lua_resume( L, 0 ) )  
        printf( "%s/n", lua_tostring( L, 1 ) );  
    // ���ý���   
    lua_close(L);  
  
    system("pause");  
    return 0;  
}