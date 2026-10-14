/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:59:45 by tsomchan          #+#    #+#             */
/*   Updated: 2026/10/14 17:53:08 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _sign(150), _exec(150) { }

AForm::AForm(const std::string name, const int sign, const int exec) : _name(name), _isSigned(false), _sign(sign), _exec(exec) { }

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _sign(other._sign), _exec(other._exec) { }

AForm &AForm::operator=(const AForm &other)
{
	_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm() { }

void AForm::beSigned(const Bureaucrat &bureau)
{
	if (bureau.getGrade() <= _sign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::string	AForm::getName()			const { return (_name); }
bool		AForm::getSigned()		const { return (_isSigned); }
int			AForm::getGradeSign()	const { return (_sign); }
int			AForm::getGradeExecute()	const { return (_exec); }

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &os,  AForm const &form)
{
	os << PUR "AForm Name: " << YLW << form.getName() << CYN " isSigned = " << WHT << form.getSigned() << CYN " SignGrade = " << WHT << form.getGradeSign() << CYN " ExecuteGrade = " << WHT << form.getGradeExecute() << std::endl;
	return (os);
}