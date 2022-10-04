#include <queuep/queuep.h>
#include <iostream>

void QueueP::push(int value) {
	std::unique_ptr<Node> new_node = std::make_unique<Node>();
	new_node->value = value;
	if (head == nullptr || head->value > value) {
		new_node->next = std::move(head);
		head = std::move(new_node);
		return;
	}
	std::unique_ptr<Node> s_node = std::make_unique<Node>();
	s_node = std::move(head);
	while (s_node->next != nullptr && value >= s_node->next->value) {
		s_node = std::move(s_node->next);
	}
	new_node->next = std::move(s_node->next);
	s_node->next = std::move(new_node);
	return;
}

void QueueP::pop() {
	if (head == nullptr) {
		std::cout << "Queue is empty." << std::endl;
		return;
	}
	head = std::move(head->next);
	return;
}

int QueueP::peek() {
	if (head == nullptr) {
		std::cout << "Queue is empty." << std::endl;
		return -1;
	}
	return head->value;
}

bool QueueP::isEmpty() {
	return head == nullptr;
}

void QueueP::clear() {
	while (head != nullptr) {
		head = std::move(head->next);
	}
	return;
}

QueueP::~QueueP() {
	clear();
	return;
}
