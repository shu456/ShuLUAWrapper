#ifndef ALASTATE_HPP
#define ALASTATE_HPP

#include <string>

#include "lua.hpp"

namespace SLW
{
  class State
  {
    public:
      bool Open(std::string const& filename) { return Open(filename.c_str()); }
      bool Open(char const* filename)
      {
        m_state = luaL_newstate();
        luaL_openlibs(m_state);
        
        if (luaL_dofile(m_state, filename))
        {
          return m_b_state = false;
        }
        
        return m_b_state = true;
      }
      
      void Close()
      {
        if(m_state)
        {
          m_b_state = false;
          lua_close(m_state);
        }
      }
      
      void CallFunction(const char* func) 
      {
        lua_getglobal(m_state, func);

        if (lua_pcall(m_state, 0, 0, 0))
        {
          //cannot find the function
          //no logging for now
        }
      }
      
      State() : m_state(nullptr), m_b_state(false){}
      State(char const* filename) : m_state(nullptr), m_b_state(false){ Open(filename); }
      State(std::string const& filename) : m_state(nullptr), m_b_state(false){ Open(filename); }
      
      ~State()
      {
        Close();
      }

      lua_State* m_state;
      bool m_b_state;
  };
}

#endif



