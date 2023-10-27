#pragma once

#include <iostream>

class Brain{

	protected :
				std::string _ideas[100];
	
	public	:
				Brain();
				Brain(const Brain& rhs);
				Brain &operator=(const Brain &rhs);
				~Brain();
				void fill_idea(void);
				std::string show_idea();

};