#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


class Base{
	public		:
					virtual ~Base();

	protected	:

	private		:

};

class A : public Base{
	
	public		:

	protected	:

	private		:
};

class B : public Base{
	
	public		:

	protected	:

	private		:
};

class C : public Base{
	
	public		:

	protected	:

	private		:
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);
