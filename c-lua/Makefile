LUA_CLIB_PATH ?= luaclib
LUA_CLIB_SRC ?= lualib-src
LUA_CLIB = tbl

all : \
	$(foreach v, $(LUA_CLIB), $(LUA_CLIB_PATH)/$(v).so)

$(LUA_CLIB_PATH) :
	mkdir $(LUA_CLIB_PATH)

$(LUA_CLIB_PATH)/tbl.so : $(LUA_CLIB_SRC)/lua-tbl.c | $(LUA_CLIB_PATH)
	gcc -shared -fPIC $^ -o $@

clean :
	rm -f $(LUA_CLIB_PATH)/*.so