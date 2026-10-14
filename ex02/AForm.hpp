/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:40:48 by tsomchan          #+#    #+#             */
/*   Updated: 2026/10/14 17:53:08 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string.h>
# include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int 			_sign;
		const int 			_exec;
	
	public:
		AForm();
		AForm(const std::string name, const int sign_grade, const int execute_grade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

		std::string getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExecute() const;

		void		beSigned(const Bureaucrat &bureau);
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream & os, AForm const &other);

#endif