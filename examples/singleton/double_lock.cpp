#include <iostream>
#include <mutex>

class GameConfig {
public:
    static GameConfig* getInstance() {
        if (m_instance == nullptr) {
            std::lock_guard<std::mutex> insGuard(m_mutex);
            if (m_instance == nullptr) {
                m_instance = new GameConfig;
            }
        }
        return m_instance;
    }

private:
    GameConfig() { std::cout << "Construct GameConfig" << std::endl; }
    ~GameConfig() { std::cout << "Destroy GameConfig" << std::endl; }
    GameConfig(const GameConfig& gameConfig) = delete;
    GameConfig& operator=(const GameConfig& gameConfig) = delete;

private:
    static GameConfig* m_instance;
    static std::mutex m_mutex;
};

GameConfig* GameConfig::m_instance = nullptr;
std::mutex GameConfig::m_mutex;

int main() {
    GameConfig* instance = GameConfig::getInstance();
    return 0;
}