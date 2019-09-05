template<typename T>
class Node{
protected:
    T value;
public:
    Node* Next;
    Node(T value);
    Node(T value, Node* N);
    T get_value();
    template <typename _T>
    friend class ForwardList;
};
