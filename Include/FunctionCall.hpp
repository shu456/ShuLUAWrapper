#ifndef FUNCTIONCALL_HPP
#define FUNCTIONCALL_HPP

#include "PushValue.hpp"

namespace SLW
{
  int PushArg(lua_State*)
  {
    //base case that do nothing.
    return 0;
  }

	template<typename H,typename ... Args>
	int PushArg(lua_State* state,H const& data1, Args&& ... rest)
	{
		PushValue(state, data1);

		return PushArg(state, rest...)+1;
	}
  
  template<typename ... Args>
	void CallFunctions(State& l_state, const char * func, Args&& ... arg)
	{
    lua_State* state = l_state.m_state;
		lua_getglobal(state, func);
		int count = PushArg(state, arg...);

		if (lua_pcall(state, count, 0, 0))
		{
			//cannot find the function
			//no logging for now
		}
	}
}

#endif

