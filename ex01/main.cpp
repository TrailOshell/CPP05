/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:11:16 by tsomchan          #+#    #+#             */
/*   Updated: 2026/10/14 16:51:21 by tsomchan         ###   ########.fr       */
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
	std::cout << PUR "=== " GRN"CPP05 " CYN"ex01" PUR "\t====== ==== === = = =" NCL << std::endl;

	test_header("test_form");
	Form test_form("TEST_FORM", 100, 90);
	std::cout << test_form;
	std::cout << std::endl;

	test_header("lost_guy");
	Bureaucrat lost_guy;
	sign_form_test(test_form, lost_guy);
	std::cout << std::endl;
	
	test_header("found_guy");
	Bureaucrat found_guy("found_guy", 100);
	sign_form_test(test_form, found_guy);
	std::cout << std::endl;

	test_header("fresh_guy");
	sign_form_test(test_form, "fresh_guy", 50);
	std::cout << std::endl;
	return (0);
}
