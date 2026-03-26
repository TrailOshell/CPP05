/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:11:16 by tsomchan          #+#    #+#             */
/*   Updated: 2026/03/26 20:04:36 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const Bureaucrat test(std::string name, int grade)
{
	std::cout << std::endl;
	std::cout << BLU << "Bureaucrat: " << CYN << "name = " << YLW << name << CYN << ", grade = " << YLW << grade << NCL << std::endl;
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

void	increment_test(std::string name, int grade)
{
	Bureaucrat b = test(name, grade);
	try
	{
		std::cout << CYN << "Proceeding to " << GRN << "increment" << CYN << " the grade." NCL << std::endl;
		b.incrementGrade();
		std::cout << b;
	}
	catch(const std::exception &e) {
		std::cerr << YLW << "Exception caught: " << e.what() << std::endl;
	}
}

void	decrement_test(std::string name, int grade)
{
	Bureaucrat b = test(name, grade);
	try
	{
		std::cout << CYN << "Proceeding to " << YLW << "decrement" << CYN << " the grade." NCL << std::endl;
		b.decrementGrade();
		std::cout << b;
	}
	catch(const std::exception &e) {
		std::cerr << YLW << "Exception caught: " << e.what() << std::endl;
	}
}

int main(void)
{
	test("a", -1);
	test("b", 151);
	test("c", 42);

	increment_test("d", 2);
	increment_test("e", 1);
	
	decrement_test("f", 149);
	decrement_test("g", 150);

	return (0);
}