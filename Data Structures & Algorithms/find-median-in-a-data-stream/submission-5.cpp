
class MedianFinder final
{
    // invariant: 0 <= lower.size() - upper.size() <= 1
    priority_queue<int, vector<int>, less<>>    lower {};
    priority_queue<int, vector<int>, greater<>> upper {};

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
