#include "ShrubberyCreationForm.hpp"




/*----------------- Coplien ------------- */

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137, "default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm(rhs){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs){
	if (this != &rhs)
		*this = rhs;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}


/*---------------- Operator ------------- */


/*---------- Getter / Setter ------------ */


/*--------------- Function -------------- */

void ShrubberyCreationForm::execute(Bureaucrat const& executor)const{

	if (this->isSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeE())
		throw GradeTooLowException();
	if (executor.getGrade() < 0)
		throw GradeTooHighException();
	shrub_exec();
}

void ShrubberyCreationForm::shrub_exec(void)const{
	std::string name;
	name.append(this->getTarget() + "_shrubbery");
	std::ofstream file(name.c_str());
	if (file.is_open()){
		draw_tree(file);
		file.close();
		std::cout << "File created" << std::endl;
	}
	else
		throw InvalidFileException();

}

void ShrubberyCreationForm::draw_tree(std::ofstream &file)const{

	file		<<"                                       =*********=                                    "<< std::endl
				<<"                                    *              ***                                "<< std::endl
				<<"                                   +                  **                              "<< std::endl
				<<"                              -==  *                      +*                          "<< std::endl
				<<"                       +**                                   =*                       "<< std::endl
				<<"                    +*-                                       *                       "<< std::endl
				<<"                  +*                                        **                        "<< std::endl
				<<"                 **                                             :**+                  "<< std::endl
				<<"                *+                  +          =                     **+              "<< std::endl
				<<"               =*                     + :*   -*                        +*-            "<< std::endl
				<<"                *                                                       **            "<< std::endl
				<<"               =                                        :      *        +*   *        "<< std::endl
				<<"             *                                            +****          *   *        "<< std::endl
				<<"          :+                                                           =***+          "<< std::endl
				<<"          --                                                                :***      "<< std::endl
				<<"           **:    =                   *+:*                                      **    "<< std::endl
				<<"       :-      :   *         +*         :                +                       =*   "<< std::endl
				<<"     *                :+****:          **   +*:            +*****+                *   "<< std::endl
				<<"   :                    +   *       *** ***   ***********+           -           **   "<< std::endl
				<<"   -       -     =    **   *=        **  *     **     *   ***:   ***+  -       **-    "<< std::endl
				<<"  *         *+::+*********+ *     *+          ****: * ++* +*+              ***        "<< std::endl
				<<"    **               **-  =*  *****  *       =:**=*** * :*         ********:          "<< std::endl
				<<"       :***********+        -- :*+  **                 *-********-                    "<< std::endl
				<<"                     ***+    =*              *    **+                                 "<< std::endl
				<<"                               *             *  **                                    "<< std::endl
				<<"                                -*** *:         *                                     "<< std::endl
				<<"                                    *         * *                                     "<< std::endl
				<<"                                   =:      : +*-*                                     "<< std::endl
				<<"                                  +        * +=*                                      "<< std::endl
				<<"                                 *=*         -*                                       "<< std::endl
				<<"                                 *=          *:                                       "<< std::endl
				<<"                                * -        * *                                        "<< std::endl
				<<"                             -*+ =        =* *                                        "<< std::endl
				<<"                         -***-   *      + **  *+                                      "<< std::endl
				<<"                   **=          +       + ****+   =*=                                 "<< std::endl
				<<"                *  ****+*****+:    ***=  * **   :**+  **                              "<< std::endl
				<<"            **-:           -*-   *:    +**   *+        -**                            "<< std::endl
				<<"     *+:               +*******:          ** =*             +***+:                    "<< std::endl
				<<"                  -+              ==          -**                    :                "<< std::endl
				<<"                                       =*********=                                    "<< std::endl
				<<"                                    *              ***                                "<< std::endl
				<<"                                   +                  **                              "<< std::endl
				<<"                              -==  *                      +*                          "<< std::endl
				<<"                       +**                                   =*                       "<< std::endl
				<<"                    +*-                                       *                       "<< std::endl
				<<"                  +*                                        **                        "<< std::endl
				<<"                 **                                             :**+                  "<< std::endl
				<<"                *+                  +          =                     **+              "<< std::endl
				<<"               =*                     + :*   -*                        +*-            "<< std::endl
				<<"                *                                                       **            "<< std::endl
				<<"               =                                        :      *        +*   *        "<< std::endl
				<<"             *                                            +****          *   *        "<< std::endl
				<<"          :+                                                           =***+          "<< std::endl
				<<"          --                                                                :***      "<< std::endl
				<<"           **:    =                   *+:*                                      **    "<< std::endl
				<<"       :-      :   *         +*         :                +                       =*   "<< std::endl
				<<"     *                :+****:          **   +*:            +*****+                *   "<< std::endl
				<<"   :                    +   *       *** ***   ***********+           -           **   "<< std::endl
				<<"   -       -     =    **   *=        **  *     **     *   ***:   ***+  -       **-    "<< std::endl
				<<"  *         *+::+*********+ *     *+          ****: * ++* +*+              ***        "<< std::endl
				<<"    **               **-  =*  *****  *       =:**=*** * :*         ********:          "<< std::endl
				<<"       :***********+        -- :*+  **                 *-********-                    "<< std::endl
				<<"                     ***+    =*              *    **+                                 "<< std::endl
				<<"                               *             *  **                                    "<< std::endl
				<<"                                -*** *:         *                                     "<< std::endl
				<<"                                    *         * *                                     "<< std::endl
				<<"                                   =:      : +*-*                                     "<< std::endl
				<<"                                  +        * +=*                                      "<< std::endl
				<<"                                 *=*         -*                                       "<< std::endl
				<<"                                 *=          *:                                       "<< std::endl
				<<"                                * -        * *                                        "<< std::endl
				<<"                             -*+ =        =* *                                        "<< std::endl
				<<"                         -***-   *      + **  *+                                      "<< std::endl
				<<"                   **=          +       + ****+   =*=                                 "<< std::endl
				<<"                *  ****+*****+:    ***=  * **   :**+  **                              "<< std::endl
				<<"            **-:           -*-   *:    +**   *+        -**                            "<< std::endl
				<<"     *+:               +*******:          ** =*             +***+:                    "<< std::endl
				<<"                  -+              ==          -**                    :                "<< std::endl
				<<"                                       =*********=                                    "<< std::endl
				<<"                                    *              ***                                "<< std::endl
				<<"                                   +                  **                              "<< std::endl
				<<"                              -==  *                      +*                          "<< std::endl
				<<"                       +**                                   =*                       "<< std::endl
				<<"                    +*-                                       *                       "<< std::endl
				<<"                  +*                                        **                        "<< std::endl
				<<"                 **                                             :**+                  "<< std::endl
				<<"                *+                  +          =                     **+              "<< std::endl
				<<"               =*                     + :*   -*                        +*-            "<< std::endl
				<<"                *                                                       **            "<< std::endl
				<<"               =                                        :      *        +*   *        "<< std::endl
				<<"             *                                            +****          *   *        "<< std::endl
				<<"          :+                                                           =***+          "<< std::endl
				<<"          --                                                                :***      "<< std::endl
				<<"           **:    =                   *+:*                                      **    "<< std::endl
				<<"       :-      :   *         +*         :                +                       =*   "<< std::endl
				<<"     *                :+****:          **   +*:            +*****+                *   "<< std::endl
				<<"   :                    +   *       *** ***   ***********+           -           **   "<< std::endl
				<<"   -       -     =    **   *=        **  *     **     *   ***:   ***+  -       **-    "<< std::endl
				<<"  *         *+::+*********+ *     *+          ****: * ++* +*+              ***        "<< std::endl
				<<"    **               **-  =*  *****  *       =:**=*** * :*         ********:          "<< std::endl
				<<"       :***********+        -- :*+  **                 *-********-                    "<< std::endl
				<<"                     ***+    =*              *    **+                                 "<< std::endl
				<<"                               *             *  **                                    "<< std::endl
				<<"                                -*** *:         *                                     "<< std::endl
				<<"                                    *         * *                                     "<< std::endl
				<<"                                   =:      : +*-*                                     "<< std::endl
				<<"                                  +        * +=*                                      "<< std::endl
				<<"                                 *=*         -*                                       "<< std::endl
				<<"                                 *=          *:                                       "<< std::endl
				<<"                                * -        * *                                        "<< std::endl
				<<"                             -*+ =        =* *                                        "<< std::endl
				<<"                         -***-   *      + **  *+                                      "<< std::endl
				<<"                   **=          +       + ****+   =*=                                 "<< std::endl
				<<"                *  ****+*****+:    ***=  * **   :**+  **                              "<< std::endl
				<<"            **-:           -*-   *:    +**   *+        -**                            "<< std::endl
				<<"     *+:               +*******:          ** =*             +***+:                    "<< std::endl
				<<"                  -+              ==          -**                    :                "<< std::endl;
}

/*--------------- Exception ------------- */
