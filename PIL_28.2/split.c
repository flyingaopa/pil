#include <string.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"


static int l_split(lua_State *L)
{
    const char *str = luaL_checkstring(L, 1);
    const char *sep = luaL_checkstring(L, 2);
    const char *idx;
    int i = 1;

    lua_newtable(L);

    while((idx = strchr(str, *sep)) != NULL)
    {
        lua_pushlstring(L, str, idx - str);
        lua_rawseti(L, -2, i++);
        str = idx + 1;
    }
    lua_pushstring(L, str);
    lua_rawseti(L, -2, i);
    return 1;
}


static int l_split2(lua_State *L)
{
    int zlen;
    const char *str = luaL_checklstring(L, 1, &zlen);
    const char *sep = luaL_checkstring(L, 2);
    const char *idx = str;
    int i = 1;

    printf("orig zlen = %d\n", zlen);
    lua_newtable(L);

    while((idx = memchr(str, *sep, zlen)) != NULL)
    {
        lua_pushlstring(L, str, idx - str);
        lua_rawseti(L, -2, i++);
        zlen -= (idx - str + 1);  
        printf("zlen = %d\n", zlen);
        str = idx + 1;
    }
    printf("last zlen = %d\n", zlen);
    lua_pushlstring(L, str, zlen);
    lua_rawseti(L, -2, i);
    return 1;
}

static const luaL_Reg funcs[] =
{
    {"split", l_split},
    {"split2", l_split2},
    {NULL, NULL}
};

int luaopen_split(lua_State *L)
{
    luaL_newlib(L, funcs);
    return 1;
}

