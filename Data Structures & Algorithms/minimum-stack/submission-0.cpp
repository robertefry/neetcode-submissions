
class MinStack
{
    struct Node {
        int value;
        int running_min;
    };
    stack<Node> m_Nodes {};

public:
    MinStack() = default;

    void push(int val)
    {
        int running_min = [&]{
            if (m_Nodes.empty()) return val;
            return min(val, m_Nodes.top().running_min);
        }();

        m_Nodes.push(Node{
            .value = val,
            .running_min = running_min,
        });
    }

    void pop()
    {
        m_Nodes.pop();
    }

    int top()
    {
        return m_Nodes.top().value;
    }

    int getMin()
    {
        return m_Nodes.top().running_min;
    }
};
