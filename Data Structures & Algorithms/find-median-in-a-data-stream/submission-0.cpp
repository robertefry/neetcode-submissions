
class MedianFinder final
{
    // invariant: lower.size() - upper.size() in 0..=1
    priority_queue<int, vector<int>, greater<>> lower {};
    priority_queue<int, vector<int>, less<>>    upper {};

public:
    explicit MedianFinder() = default;

    void addNum(int num)
    {
        lower.push(num);
        num = lower.top();
        lower.pop();

        upper.push(num);
        num = upper.top();
        upper.pop();

        // here: lower.top() <= num <= upper.top()

        if (lower.size() == upper.size()) {
            lower.push(num);
        } else {
            upper.push(num);
        }
    }

    [[nodiscard]]
    double findMedian() const
    {
        if (lower.size() > upper.size()) {
            return static_cast<double>(lower.top());
        }
        auto lower_top = static_cast<double>(lower.top());
        auto upper_top = static_cast<double>(upper.top());
        return (lower_top + upper_top) / 2.0;
    }
};
