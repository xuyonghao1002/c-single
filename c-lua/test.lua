package.cpath = "luaclib/?.so"

local so = require "tbl.c"

so.echo("Hello1")  -- 新的虚拟栈
so.echo("Hello1")  -- 新的虚拟栈
so.echo("Hello1")  -- 新的虚拟栈