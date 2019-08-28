
template<typename T>
class Node{
protected:
	T value;
	Node* Next;
public:
	Node(T value);
	Node(T value, Node* N);
}
