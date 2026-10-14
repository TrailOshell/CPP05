/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:59:45 by tsomchan          #+#    #+#             */
/*   Updated: 2026/10/14 17:40:07 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form() : _name("Default"), _isSigned(false), _sign(150), _exec(150) { }

Form::Form(const std::string name, const int sign, const int exec) : _name(name), _isSigned(false), _sign(sign), _exec(exec) { }

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _sign(other._sign), _exec(other._exec) { }

Form &Form::operator=(const Form &other)
{
	_isSigned = other._isSigned;
	return (*this);
}

Form::~Form() { }

void Form::beSigned(const Bureaucrat &bureau)
{
	if (bureau.getGrade() <= _sign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::string	Form::getName()			const { return (_name); }
bool		Form::getSigned()		const { return (_isSigned); }
int			Form::getGradeSign()	const { return (_sign); }
int			Form::getGradeExecute()	const { return (_exec); }

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &os,  Form const &form)
{
	os << PUR "Form Name: " << YLW << form.getName() << CYN " isSigned = " << WHT << form.getSigned() << CYN " SignGrade = " << WHT << form.getGradeSign() << CYN " ExecuteGrade = " << WHT << form.getGradeExecute() << std::endl;
	return (os);
}