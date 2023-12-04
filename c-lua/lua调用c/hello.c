/*
lua调用c的方式：
1. 通过在C中注册函数给lua调用
2. 封装成c动态链接库，在lua中require
3. 在LuaJIT里面可以使用ffi高性能的调用C（但是IOS上不支持LuaJIT。。）
*/

#include <stdio.h>
#include <string.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"



// 在C中注册函数给Lua
static int
l_hello(lua_State* L){
    const char* l = luaL_checkstring(L, 1);
    char str[100] = "hello ";
    strcat(str, l);
    lua_pushstring(L, str);
    return 1;
}

int main(int argc, char const *argv[])
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    lua_register(L, "say_hello", l_hello);

    const char* cmd = "print(say_hello('xuyh'))";
    if (luaL_dostring(L, cmd))
    {
        
    }

    lua_close(L);
    
    return 0;
}