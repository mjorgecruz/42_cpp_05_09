/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:37:35 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 15:08:48 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        RobotomyRequestForm();
    public:
        ~RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm &src);
        RobotomyRequestForm &operator= (RobotomyRequestForm &src);
        RobotomyRequestForm(std::string target);

        void beExecuted(Bureaucrat const & executor) const;
};