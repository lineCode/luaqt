/****************************************************************************
**
** Copyright (C) 2013 tdzl2003.
** Contact: https://github.com/tdzl2003/luaqt
**
** This file is part of the LuaQt Toolkit source.
**
** This file is generated by tools. It's still licensed at BSD New license.
**
** NOTICE:
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
** ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
** INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
** POSSIBILITY OF SUCH DAMAGE.** 
**
** read COPYRIGHT.md for more informations.
**
****************************************************************************/

#include <LuaQt/globals.hpp>
#include <LuaQt/fix.hpp>
#include </*%return fileName%*/>

/*%
return depHeaders()
%*/

#define CLASS_NAME STR(/*%return classname%*/)
#define CLASS   /*%return classname%*/

/*%
	if (not isAbstract) then
		return constructors()
	else
		return ""
	end
%*/

/*%
	if (not isAbstract) then
		return extendedImpl()
	else
		return ""
	end
%*/

/*%
	if (not isAbstract) then
		return extendedConstructor()
	else
		return ""
	end
%*/

/*%
	return methodImpls()
%*/

/*%
	return signalImpls()
%*/

/*%
	return casters()
%*/

/*%
	return declareExtraMethods()
%*/

/*%
	return staticMethodsImpls()
%*/

static luaL_Reg methods[] = {
/*%
	return methodTable()
%*/
/*%
	return signalTable()
%*/
	{NULL, NULL}
};

/*%
	return declareInitSuperMethods()
%*/
Q_DECL_EXPORT void /*%return classname%*/_initMethods(lua_State *L)
{
/*%
	return initSuperMethods()
%*/
	luaL_regfuncs(L, methods, sizeof(methods)/sizeof(luaL_Reg) - 1);
}

static luaQt_enumReg enumValues[] = {
/*%
	return enumValues()
%*/
	{NULL, 0}
};

static void init_enumValues(lua_State *L)
{
	luaL_regenumValues(L, enumValues, sizeof(enumValues)/sizeof(enumValues[0]) - 1);
}


static luaL_Reg getters[] = {
/*%
	return casterList()
%*/
	{NULL, NULL}
};

static luaL_Reg setters[] = {
	{NULL, NULL}
};

static luaL_Reg statics[] = {
/*%
	if (not isAbstract) then
		return '\t{"new", ' .. classname .. '_constructor},'
	else
		return ""
	end
%*/
/*%
	if (not isAbstract) then
		return '\t{"newExtended", ' .. classname .. '_constructorWithExtend},'
	else
		return ""
	end
%*/
/*%
	return staticMethodsTable()
%*/
	{NULL, NULL}
};

//static int __gc(lua_State *L)
//{
//	CLASS* p = (CLASS*)LuaQt::checkObject(L, 1, CLASS_NAME);
//	delete p;
//	return 0;
//}

void luadef_/*%return classname%*/(lua_State *L)
{
	luaL_newlib(L, statics);

	init_enumValues(L);

	lua_pushlightuserdata(L, const_cast<void*>(reinterpret_cast<const void*>(&CLASS::staticMetaObject)));
	lua_setfield(L, -2, "_metaObject");

	// register meta table.
	if (!luaL_newmetatable(L, CLASS_NAME)) 
	{
		// luaL_error(L, "Metatable "CLASS_NAME" has been registered.");
		return;
	}

	//luaL_newlib(L, methods);	
	lua_createtable(L, 0, 0);
	/*%return classname%*/_initMethods(L);
	
	lua_pushvalue(L, -1);
	lua_setfield(L, -4, "methods");

	luaL_newlib(L, getters);
	lua_pushvalue(L, -1);
	lua_setfield(L, -5, "getters");

	lua_pushcclosure(L, LuaQt::General_index, 2);
	lua_setfield(L, -2, "__index");

	luaL_newlib(L, setters);
	lua_pushcclosure(L, LuaQt::General_newindex, 1);
	lua_setfield(L, -2, "__newindex");

	//lua_pushcfunction(L, __gc);
	//lua_setfield(L, -2, "__gc");

	lua_pop(L, 1);

	// register static table.
	lua_setglobal(L, CLASS_NAME);
}
