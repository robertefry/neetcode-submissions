
class MedianFinder final
{
    // invariant: 0 <= lower.size() - upper.size() <= 1
    priority_queue<int, vector<int>, less<>>    lower {};
    priority_queue<int, vector<int>, greater<>> upper {};

public:
    explicit MedianFinder() = default;

    void addNum(int num)
    {
        if (lower.empty()) [[unlikely]] {
            lower.push(num);
            return;
        }

        if (num <= lower.top())
        {
            lower.push(num);

            if (lower.size() > upper.size() + 1) {
                upper.push(lower.top());
                lower.pop();
            }
        }
        else
        {
            upper.push(num);

            if (upper.size() > lower.size()) {
                lower.push(upper.top());
                upper.pop();
            }
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
