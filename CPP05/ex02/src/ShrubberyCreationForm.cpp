#include "ShrubberyCreationForm.hpp"




/*----------------- Coplien ------------- */

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137) {
	_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137) {
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm(rhs){
	this->_target = rhs._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs){

	this->_target = rhs._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}


/*---------------- Operator ------------- */

std::ostream& operator<<(std::ostream& o, const ShrubberyCreationForm& rhs){
	o   << std::endl;
	return o; 
}


/*---------- Getter / Setter ------------ */


/*--------------- Function -------------- */

std::string ShrubberyCreationForm::getTarget(){
	return this->_target;
}


void draw_tree(void);
{
	std::cout	<<"                                       =*********=                                    "<< endl
				<<"                                    *              ***                                "<< endl
				<<"                                   +                  **                              "<< endl
				<<"                              -==  *                      +*                          "<< endl
				<<"                       +**                                   =*                       "<< endl
				<<"                    +*-                                       *                       "<< endl
				<<"                  +*                                        **                        "<< endl
				<<"                 **                                             :**+                  "<< endl
				<<"                *+                  +          =                     **+              "<< endl
				<<"               =*                     + :*   -*                        +*-            "<< endl
				<<"                *                                                       **            "<< endl
				<<"               =                                        :      *        +*   *        "<< endl
				<<"             *                                            +****          *   *        "<< endl
				<<"          :+                                                           =***+          "<< endl
				<<"          --                                                                :***      "<< endl
				<<"           **:    =                   *+:*                                      **    "<< endl
				<<"       :-      :   *         +*         :                +                       =*   "<< endl
				<<"     *                :+****:          **   +*:            +*****+                *   "<< endl
				<<"   :                    +   *       *** ***   ***********+           -           **   "<< endl
				<<"   -       -     =    **   *=        **  *     **     *   ***:   ***+  -       **-    "<< endl
				<<"  *         *+::+*********+ *     *+          ****: * ++* +*+              ***        "<< endl
				<<"    **               **-  =*  *****  *       =:**=*** * :*         ********:          "<< endl
				<<"       :***********+        -- :*+  **                 *-********-                    "<< endl
				<<"                     ***+    =*              *    **+                                 "<< endl
				<<"                               *             *  **                                    "<< endl
				<<"                                -*** *:         *                                     "<< endl
				<<"                                    *         * *                                     "<< endl
				<<"                                   =:      : +*-*                                     "<< endl
				<<"                                  +        * +=*                                      "<< endl
				<<"                                 *=*         -*                                       "<< endl
				<<"                                 *=          *:                                       "<< endl
				<<"                                * -        * *                                        "<< endl
				<<"                             -*+ =        =* *                                        "<< endl
				<<"                         -***-   *      + **  *+                                      "<< endl
				<<"                   **=          +       + ****+   =*=                                 "<< endl
				<<"                *  ****+*****+:    ***=  * **   :**+  **                              "<< endl
				<<"            **-:           -*-   *:    +**   *+        -**                            "<< endl
				<<"     *+:               +*******:          ** =*             +***+:                   "<< endl
				<<"                  -+              ==          -**                    :               "<< endl;
}
/*--------------- Exception ------------- */
