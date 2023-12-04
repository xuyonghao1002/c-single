#include <stdio.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"


// c 调用 lua

lua_State* L;

int
luaadd(int x, int y){
    int sum;
    lua_getglobal(L, "add");
    lua_pushnumber(L, x);
    lua_pushnumber(L, y);
    lua_call(L, 2, 1);
    sum = (int)lua_tonumber(L, -1);
    lua_pop(L, 1);
    return sum;
}

int main(int argc, char const *argv[])
{
    int sum;
    L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, "add.lua");
    sum = luaadd(1,1);
    printf("the sum is %d\n", sum);
    lua_close(L);
    return 0;
}
