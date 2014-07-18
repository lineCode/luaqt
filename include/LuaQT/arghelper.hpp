/****************************************************************************
**
** Copyright (C) 2013 tdzl2003.
** Contact: https://github.com/tdzl2003/luaqt
**
** This file is part of the LuaQt Toolkit source.
**
** This file is licensed at BSD New license.
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

#pragma once

template<typename Enum>
class QFlags;

template<class Key, class T>
class QMap;

template<class Key, class T>
class QHash;

template<class Key>
class QSet;

// Argument helper functions&macros
namespace LuaQt
{
	template <typename T>
	struct is_qobject_ptr
		: public std::tr1::false_type
	{
	};

	template <typename T>
	struct is_qobject_ptr<T*>
		: public std::tr1::is_base_of<QObject, T>
	{
	};

	template <typename T>
	class ArgHelperGeneral
	{
	public:
		static bool CheckArg(lua_State *L, int idx);
		static T GetArg(lua_State *L, int idx);
		static void pushRetVal(lua_State*L, const T& val);
		static void pushRetVal(lua_State*L, T&& val);
	};

	template <typename T>
	class ArgHelperEnum
	{
	public:
		static bool CheckArg(lua_State *L, int idx){
			return lua_isnumber(L, idx);;
		}
		static T GetArg(lua_State *L, int idx){
			return (T)(lua_tointeger(L, idx));
		}
		static void pushRetVal(lua_State*L, const T& val){
			lua_pushinteger(L, (int)val);
		}
		static void pushRetVal(lua_State*L, T&& val) {
			lua_pushinteger(L, (int)val);
		}
	};

	template <typename T>
	class ArgHelperQObjectPtr
	{
	};

	template <typename T>
	class ArgHelperQObjectPtr<T*>
	{
	public:
		static bool CheckArg(lua_State *L, int idx){
			return isObject(L, idx, T::staticMetaObject.className());
		}
		static T* GetArg(lua_State *L, int idx){
			return (T*)checkObject(L, idx, T::staticMetaObject.className());
		}
		static void pushRetVal(lua_State*L,  T* const& val){
            PushObject(L, val);
		}
		static void pushRetVal(lua_State*L, T*&& val) {
            PushObject(L, val);
		}
	};

    template <typename T>
    class ArgHelperQObjectPtr<const T*>
    {
    public:
        static bool CheckArg(lua_State *L, int idx){
            return isObject(L, idx, T::staticMetaObject.className());
        }
        static const T* GetArg(lua_State *L, int idx){
            return (const T*)checkObject(L, idx, T::staticMetaObject.className());
        }
        static void pushRetVal(lua_State*L,  const T* const& val){
            luaL_error(L, "Not implemented.");
        }
        static void pushRetVal(lua_State*L, const T*&& val) {
            luaL_error(L, "Not implemented.");
        }
    };

	template <typename T>
	class ArgHelperQList
	{
	public:
		static bool CheckArg(lua_State *L, int idx){
			luaL_error(L, "Not implemented.");
			return false;
		}
		static QList<T> GetArg(lua_State *L, int idx){
			luaL_error(L, "Not implemented.");
			return QList<T>();
		}
		static void pushRetVal(lua_State*L, const QList<T>& val){
			luaL_error(L, "Not implemented.");
			lua_pushnil(L);
		}
		static void pushRetVal(lua_State*L, QList<T>&& val) {
			luaL_error(L, "Not implemented.");
			lua_pushnil(L);
		}
	};

	template <typename T>
	class ArgHelperQVector
	{
	public:
		static bool CheckArg(lua_State *L, int idx){
			luaL_error(L, "Not implemented.");
			return false;
		}
		static QVector<T> GetArg(lua_State *L, int idx){
			luaL_error(L, "Not implemented.");
			return QVector<T>();
		}
		static void pushRetVal(lua_State*L, const QVector<T>& val){
			luaL_error(L, "Not implemented.");
			lua_pushnil(L);
		}
		static void pushRetVal(lua_State*L, QVector<T>&& val) {
			luaL_error(L, "Not implemented.");
			lua_pushnil(L);
		}
	};

	template <typename KT, typename VT>
	class ArgHelperQMap
	{
	public:
		static bool CheckArg(lua_State *L, int idx){
			luaL_error(L, "Not implemented.");
			return false;
		}
		static QMap<KT, VT> GetArg(lua_State *L, int idx){
			luaL_error(L, "Not implemented.");
			return QMap<KT, VT>();
		}
		static void pushRetVal(lua_State*L, const QMap<KT, VT>& val){
			luaL_error(L, "Not implemented.");
			lua_pushnil(L);
		}
		static void pushRetVal(lua_State*L, QMap<KT, VT>&& val) {
			luaL_error(L, "Not implemented.");
			lua_pushnil(L);
		}
	};
	
	template <typename KT, typename VT>
	class ArgHelperQHash
	{
	public:
		static bool CheckArg(lua_State *L, int idx){
			luaL_error(L, "Not implemented.");
			return false;
		}
		static QHash<KT, VT> GetArg(lua_State *L, int idx){
			luaL_error(L, "Not implemented.");
			return QHash<KT, VT>();
		}
		static void pushRetVal(lua_State*L, const QHash<KT, VT>& val){
			luaL_error(L, "Not implemented.");
			lua_pushnil(L);
		}
		static void pushRetVal(lua_State*L, QHash<KT, VT>&& val) {
			luaL_error(L, "Not implemented.");
			lua_pushnil(L);
		}
	};

	template <typename KT>
	class ArgHelperQSet
	{
	public:
		static bool CheckArg(lua_State *L, int idx){
			luaL_error(L, "Not implemented.");
			return false;
		}
		static QSet<KT> GetArg(lua_State *L, int idx){
			luaL_error(L, "Not implemented.");
			return QSet<KT>();
		}
		static void pushRetVal(lua_State*L, const QSet<KT>& val){
			luaL_error(L, "Not implemented.");
			lua_pushnil(L);
		}
		static void pushRetVal(lua_State*L, QSet<KT>&& val) {
			luaL_error(L, "Not implemented.");
			lua_pushnil(L);
		}
	};

	template <typename T, 
		bool isEnum = std::tr1::is_enum<T>::value,
		bool isQObjectPtr = is_qobject_ptr<T>::value>
	class ArgHelper
		: public ArgHelperGeneral<T>
	{
	};

	template <typename T>
	class ArgHelper<T, true, false>
		: public ArgHelperEnum<T>
	{
	};

	template <typename T>
	class ArgHelper<QFlags<T>, false, false>
		: public ArgHelperEnum<QFlags<T>>
	{
	};

	template <typename T>
	class ArgHelper<T, false, true>
		: public ArgHelperQObjectPtr<T>
	{
	};

	template <typename T>
	class ArgHelper<QList<T>, false, false>
		: public ArgHelperQList<T>
	{
	};

	template <typename T>
	class ArgHelper<QVector<T>, false, false>
		: public ArgHelperQVector<T>
	{
	};

	template <typename KT, typename VT>
	class ArgHelper<QMap<KT, VT>, false, false>
		: public ArgHelperQMap<KT, VT>
	{
	};

	template <typename KT, typename VT>
	class ArgHelper<QHash<KT, VT>, false, false>
		: public ArgHelperQHash<KT, VT>
	{
	};

	template <typename KT>
	class ArgHelper<QSet<KT>, false, false>
		: public ArgHelperQSet<KT>
	{
	};

	using std::tr1::remove_reference;
	using std::tr1::remove_const;
}
