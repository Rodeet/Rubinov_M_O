#ifndef QUEUEP
#define QUEUEP

#include <memory>

class QueueP {
public:
	QueueP() = default;
	~QueueP();

	void push(int value);
	void pop();
	int peek();
	bool isEmpty();
	void clear();
private:
	struct Node {
		std::unique_ptr<Node> next{ nullptr };
		int value = 0;
	};

	std::unique_ptr<Node> head{ nullptr };
};

#endif