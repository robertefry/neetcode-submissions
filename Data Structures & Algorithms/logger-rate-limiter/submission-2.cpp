
class Logger {

    unordered_map<string,int> m_LastMessageTimes {};

public:
    bool shouldPrintMessage(int timestamp, string message)
    {
        if (
            not m_LastMessageTimes.contains(message)
            || m_LastMessageTimes[message] + 10 <= timestamp
        ) {
            m_LastMessageTimes[message] = timestamp;
            return true;
        }

        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
