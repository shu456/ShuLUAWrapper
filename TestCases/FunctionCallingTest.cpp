#include <iostream>

#include "../include/ShuLUAWrapper.hpp"

int main(void)
{
  //creating state
  SLW::State state("test.lua");
  
  //calling lua functions
  //supports as many args as possible!
  SLW::CallFunctions(state,"Test1",6);
  SLW::CallFunctions(state,"Test2",6,5);
  SLW::CallFunctions(state,"Test3",6,5,9);
  SLW::CallFunctions(state,"Test4",6,5,8,89999);
  
	return 0;
}