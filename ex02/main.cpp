/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:11:16 by tsomchan          #+#    #+#             */
/*   Updated: 2026/10/14 17:38:10 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const Bureaucrat check_bureaucrat(std::string name, int grade)
{
	try
	{
		Bureaucrat b(name, grade);
		std::cout << b;
		return (b);
	}
	catch(const std::exception &e)
	{
		std::cerr << YLW << "Exception caught: " << e.what() << std::endl;
		return Bureaucrat(name, 150);
	}
}

const Bureaucrat check_bureaucrat(Bureaucrat b)
{
	return check_bureaucrat(b.getName(), b.getGrade());
}

void	sign_form_test(Form form, Bureaucrat b)
{
	check_bureaucrat(b);
	b.signForm(form);
	std::cout << form;

	//std::cout << std::endl;
}

void	sign_form_test(Form form, std::string b_name, int b_grade)
{
	Bureaucrat b(b_name, b_grade);
	sign_form_test(form, b);
}

void	test_header(std::string text)
{
	std::cout << GRN << "=== " << CYN << text  << GRN "\t==================================================== == = =" << NCL << std::endl;
}

int main(void)
{
	std::cout << PUR "=== " GRN"CPP05 " CYN"ex02" PUR "\t====== ==== === = = =" NCL << std::endl;

	return (0);
}
