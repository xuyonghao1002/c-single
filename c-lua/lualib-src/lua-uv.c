#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <stdio.h>

static int lecho(lua_State *L){
    lua_Integer n = lua_tointeger(L, lua_upvalueindex(1));
    n++;
    const char* str = lua_tostring(L, -1);
    fprintf(stdout, "[n=%lld]--%s\n", n, str);
    lua_pushinteger(L, n);
    lua_replace(L, lua_upvalueindex(1));
    return 0;
}

static const luaL_Reg l[] = {
    {"echo", lecho},
    {NULL, NULL}
};

int luaopen_uv_c(lua_State *L){
    // luaL_newlib(L, l);
    // fprintf(stdout, "000 top index is %d\n", lua_gettop(L));
    luaL_newlibtable(L, l);
    // fprintf(stdout, "111 top index is %d\n", lua_gettop(L));
    lua_pushinteger(L, 0); // 1 -2 
    // fprintf(stdout, "222 top index is %d\n", lua_gettop(L));
    luaL_setfuncs(L, l, 1); // 2 -1 
    // fprintf(stdout, "333 top index is %d\n", lua_gettop(L));
    return 1;
}
