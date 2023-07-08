#include "common/common.h"

class GameConfig {
public:
    static GameConfig* getInstance() {
        static GameConfig instance;
        return &instance;
    }

private:
    GameConfig() { std::cout << "Construct GameConfig" << std::endl; }
    ~GameConfig() { std::cout << "Destroy GameConfig" << std::endl; }
    GameConfig(const GameConfig& gameConfig) = delete;
    GameConfig& operator=(const GameConfig& gameConfig) = delete;
};

int main() {
    std::cout << "main running ..." << std::endl;
    GameConfig* instance = GameConfig::getInstance();
    return 0;
}