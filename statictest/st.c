#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <stdio.h>



static testvar = 0;

static int printaddr(lua_State *L)
{
    printf("%p\n", &testvar);
    return 0;
}

const struct luaL_Reg _st[] =
{
    {"printaddr", printaddr},
    {NULL,NULL}
};

int luaopen_st(lua_State *L)
{
    luaL_newlib(L, _st);
    return 1;
}

