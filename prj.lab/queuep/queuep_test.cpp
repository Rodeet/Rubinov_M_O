#include <queuep/queuep.h>
#include <iostream>


int main()
{
	QueueP q;
	std::cout << q.isEmpty() << std::endl;
	q.push(5);
	q.push(4);
	q.push(3);
	q.push(2);
	q.push(1);
	std::cout << q.isEmpty() << std::endl;
	std::cout << q.peek() << std::endl;
	q.pop();
	std::cout << q.peek() << std::endl;
	q.pop();
	std::cout << q.peek() << std::endl;
	q.pop();
	std::cout << q.peek() << std::endl;
	q.clear();
	q.pop();
	return 0;
}
