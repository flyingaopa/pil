#include <dirent.h>
#include <string.h>
#include <errno.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static int dir_iter(lua_State *L)
{
    DIR *dp = *(DIR **)lua_touserdata(L, lua_upvalueindex(1));
    struct dirent *ent;
    if( (ent = readdir(dp)) != NULL )
    {
        lua_pushstring(L, ent->d_name);
        return 1;
    }
    return 0;
}

static int l_dir(lua_State *L)
{
    const char *dirname = luaL_checkstring(L, 1);
    DIR **dp = (DIR **)lua_newuserdata(L, sizeof(DIR *));

    luaL_getmetatable(L, "luabook.dir");
    lua_setmetatable(L, -2);

    *dp = opendir(dirname);
    if( *dp == NULL )
    {
        luaL_error(L, "cannot open %s: %s", dirname, strerror(errno));
    }

    lua_pushcclosure(L, dir_iter, 1);
    return 1;
}


static int dir_gc(lua_State *L)
{
    DIR *dp = *(DIR **)lua_touserdata(L,1);
    if(dp)
        closedir(dp);
    return 0;
}

static const luaL_Reg dirlib[] =
{
    {"open", l_dir},
    {NULL, NULL}
};

int luaopen_dir(lua_State *L)
{
    luaL_newmetatable(L, "luabook.dir");

    lua_pushcfunction(L, dir_gc);
    lua_setfield(L, -2, "__gc");

    luaL_newlib(L, dirlib);
    return 1;
}

