LUA_CLIB_PATH ?= luaclib
LUA_CLIB_SRC ?= lualib-src
LUA_CLIB = tbl uv reg1 reg2
LUA_INC ?= lua
SHARED := -fPIC --shared
CFLAGS = -g -O2 -Wall -I$(LUA_INC)
CC ?= gcc


all : \
	$(foreach v, $(LUA_CLIB), $(LUA_CLIB_PATH)/$(v).so)

$(LUA_CLIB_PATH) :
	mkdir $(LUA_CLIB_PATH)

$(LUA_CLIB_PATH)/tbl.so : $(LUA_CLIB_SRC)/lua-tbl.c | $(LUA_CLIB_PATH)
	$(CC) $(CFLAGS) $(SHARED) $^ -o $@

$(LUA_CLIB_PATH)/uv.so : $(LUA_CLIB_SRC)/lua-uv.c | $(LUA_CLIB_PATH)
	$(CC) $(CFLAGS) $(SHARED) $^ -o $@ 

$(LUA_CLIB_PATH)/reg1.so : $(LUA_CLIB_SRC)/lua-reg1.c | $(LUA_CLIB_PATH)
	$(CC) $(CFLAGS) $(SHARED) $^ -o $@ 

$(LUA_CLIB_PATH)/reg2.so : $(LUA_CLIB_SRC)/lua-reg2.c | $(LUA_CLIB_PATH)
	$(CC) $(CFLAGS) $(SHARED) $^ -o $@ 

clean :
	rm -f $(LUA_CLIB_PATH)/*.so