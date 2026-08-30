
class Logger {

    unordered_map<string,int> m_LastMessageTimes{};

public:
    Logger()
    {}
    
    bool shouldPrintMessage(int timestamp, string message)
    {
        if (not m_LastMessageTimes.contains(message)) {
            m_LastMessageTimes[message] = timestamp;
            return true;
        }

        if (m_LastMessageTimes[message] + 10 > timestamp) {
            // Req: rate limit the messages
            return false;
        }

        m_LastMessageTimes[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
