package.cpath = "luaclib/?.so"

local tbl = require "tbl.c"

-- tbl.echo("Hello1")  -- 新的虚拟栈
-- tbl.echo("Hello1")  -- 新的虚拟栈
-- tbl.echo("Hello1")  -- 新的虚拟栈

local uv = require "uv.c"
uv.echo("Hello1")
uv.echo("Hello2")
uv.echo("Hello3")
uv.echo("Hello4")
uv.echo("Hello5")