#include "linkedlist.h"
#include <iostream>

int main()
{
	linkedlist<int> l;
	std::cout << l << std::endl;
	l.add(1);
	l.add(2);
	l.add(2);
	l.add(3);
	std::cout << l << std::endl;
	l.add(4);
	l.add(5);
	std::cout << l << std::endl;

	l.remove(1);
	std::cout << l << std::endl;

	l.remove(4);
	std::cout << l << std::endl;

	l.add(2);
	l.add(2);
	l.add(3);
	std::cout << l << std::endl;

	l.remove_all_duplicates();
	std::cout << l << std::endl;

	l.add(2);
	l.add(2);
	l.add(3);
	std::cout << l << std::endl;
	l.remove_all(2);
	std::cout << l << std::endl;

	l.remove_all(3);
	std::cout << l << std::endl;

	l.remove(5);
	std::cout << l << std::endl;

	l.add(2);
	l.add(2);
	l.add(3);
	l.add(5);
	l.add(2);
	l.add(2);
	l.add(3);
	std::cout << l << std::endl;
	l.remove_all_duplicates2();
	std::cout << l << std::endl;


	l.add(2);
	l.add(2);
	l.add(3);
	std::cout << l << std::endl;
	l.remove_all_duplicates3();
	std::cout << l << std::endl;

	l.add(1);
	l.add(4);
	l.add(7);
	std::cout << l << std::endl;

	for (int i = 1; i < 9; ++i)
	{
		auto node = l.find_k(i);
		if (node)
		{
			std::cout << node->m_data << " ";
		}
		else
		{
			std::cout << "list length less than " << i <<" ";
		}
	}
	std::cout << std::endl;

	for (int i = 1; i < 9; ++i)
	{
		auto node = l.find_k_recursive(i);
		if (node)
		{
			std::cout << node->m_data << " ";
		}
		else
		{
			std::cout << "list length less than " << i <<" ";
		}
	}
	std::cout << std::endl;

	l.split_by(4);
	std::cout << "split_by(4): " << l << std::endl;
	l.split_by(5);
	std::cout << "split_by(5): " << l << std::endl;
	l.split_by(3);
	std::cout << "split_by(3): " << l << std::endl;

	std::cout << l << std::endl;
	l.invert();
	std::cout << l << std::endl;

	return 0;
}