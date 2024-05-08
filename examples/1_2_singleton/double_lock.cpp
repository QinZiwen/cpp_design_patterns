#include "common/common.h"

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

    class Garbo {
    public:
        ~Garbo() {
            // You may not write GameConfig, but if you write it, it can be clearer
            if (GameConfig::m_instance != nullptr) {
                delete GameConfig::m_instance;
                GameConfig::m_instance = nullptr;
                std::cout << "Garbo work" << std::endl;
            }
        }
    };
private:
    static GameConfig* m_instance;
    static std::mutex m_mutex;
    static Garbo m_garbo;
};

GameConfig* GameConfig::m_instance = nullptr;
std::mutex GameConfig::m_mutex;
GameConfig::Garbo GameConfig::m_garbo;

int main() {
    std::cout << "main running ..." << std::endl;
    GameConfig* instance = GameConfig::getInstance();
    return 0;
}