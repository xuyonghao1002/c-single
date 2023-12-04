
#include <stdio.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

// #define CODE1
// #define CODE2
// #define CODE3
#define CODE4

// https://wmf.im/p/skynet%E6%BA%90%E7%A0%81%E5%88%86%E6%9E%90%E4%BA%8C%E5%90%AF%E5%8A%A8%E6%B5%81%E7%A8%8B/

int main(int argc, char const *argv[])
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	// 加载lua文件
	int ret = luaL_loadfile(L, "test.lua");
	if(ret == 0)
		printf("load file success retLoad:%d\n", ret);
	if(ret || lua_pcall(L, 0,0,0)){
		printf("error %s\n", lua_tostring(L, -1));
		return -1;
	}

#ifdef CODE1
	// 读取lua的全局变量
	lua_getglobal(L, "name");
	lua_getglobal(L, "age");
	int age = lua_tointeger(L, -1);
	const char* name = lua_tostring(L, -2);
	printf("name = %s\n", name); //栈顶
    printf("age = %d\n", age);   //次栈顶
#endif

#ifdef CODE2
	// 调用lua函数
	lua_getglobal(L, "add");
	lua_pushnumber(L, 10);
	lua_pushnumber(L, 20);
	lua_pcall(L, 2, 1, 0);
	int value = lua_tonumber(L, -1);
	printf("val:%d\n", value);
#endif

#ifdef CODE3
	// 读取lua table的值
	lua_getglobal(L, "mytable");
	lua_pushstring(L, "name");
	lua_gettable(L, 1);

	const char* name = lua_tostring(L, -1);
	printf("name:%s\n", name);

	lua_pushstring(L, "id");

	lua_gettable(L, 1);

	int id = lua_tonumber(L, -1);
	printf("id:%d\n", id);
#endif

#ifdef CODE4
	printf("stack length is %d\n", lua_gettop(L));
	lua_newtable(L);
	printf("stack length is %d\n", lua_gettop(L));
	int ref = luaL_ref(L, LUA_REGISTRYINDEX);
	printf("stack length is %d\n", lua_gettop(L));
	lua_rawgeti(L, LUA_REGISTRYINDEX, ref);
	printf("stack length is %d\n", lua_gettop(L));
#endif

	lua_close(L);
	return 0;
}
