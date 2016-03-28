#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static int l_filter(lua_State *L)
{
    int i,n,r,j;
    luaL_checktype(L, 1, LUA_TTABLE);
    luaL_checktype(L, 2, LUA_TFUNCTION);

    j = 0;
    n = luaL_len(L, 1);
    lua_newtable(L);
    for(i = 1; i <= n; i++)
    {
        lua_pushvalue(L, 2);
        lua_rawgeti(L, 1, i);
        lua_call(L, 1, 1);
        r = lua_toboolean(L, -1);
        lua_pop(L, 1);
        if(r != 0)
        {
            lua_rawgeti(L, 1, i);
            lua_rawseti(L, -2, ++j);
        }
    }
    return 1;
}


static const luaL_Reg funcs[] =
{
    {"filter", l_filter},
    {NULL, NULL}
};


int luaopen_filter(lua_State *L)
{
    luaL_newlib(L, funcs);
    return 1;
}
