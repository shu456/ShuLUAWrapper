#ifndef PUSHVALUE_HPP
#define PUSHVALUE_HPP

namespace SLW
{
  //generic type!
  template<typename T>
	void PushValue(lua_State* state, T const& data)
	{
		if (data)
			lua_pushlightuserdata(state, data);
		else
			lua_pushnil(state);
	}
  //specialised type
	template<>
	void PushValue<double>(lua_State* state, double const& data)
  {
		lua_pushnumber(state, data);
	}
	template<>
	void PushValue<float>(lua_State* state, float const& data)
  {
		lua_pushnumber(state, data);
	}
	template<>
	void PushValue<std::string>(lua_State* state, std::string const& data)
  {
		lua_pushstring(state, data.c_str());
	}
	template<>
	void PushValue<int>(lua_State* state, int const& data)
  {
		lua_pushinteger(state, data);
	}
	template<>
	void PushValue<unsigned>(lua_State* state, unsigned const& data)
  {
		lua_pushinteger(state, data);
	}
	template<>
	void PushValue<short>(lua_State* state, short const& data)
  {
		lua_pushinteger(state, data);
	}
	template<>
	void PushValue<bool>(lua_State* state, bool const& data)
  {
		lua_pushinteger(state, data);
	}
}

#endif

