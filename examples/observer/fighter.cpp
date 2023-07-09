#include "common/common.h"

class Fighter;
class Notifier {
public:
    virtual ~Notifier() = default;

    virtual void addToList(Fighter* player) = 0;
    virtual void removeFromList(Fighter* player) = 0;
    virtual void notify(Fighter* talker, const std::string& content) = 0;
};

class Fighter {
public:
    Fighter(int id, const std::string& name) : m_playerId(id), m_playerName(name), m_familyId(-1) {}
    virtual ~Fighter() = default;

    void setFamilyId(int id) { m_familyId = id; }
    int familyId() { return m_familyId; }

    void sayWords(const std::string& content, Notifier* notifier) {
        notifier->notify(this, content);
    }

    virtual void notifyWords(const Fighter* talker, const std::string& content) {
        std::cout << "Player: " << m_playerName << " received: " << talker->m_playerName
                  << " content: " << content << std::endl;
    }
private:
    int m_playerId;
    std::string m_playerName;
    int m_familyId;
};

class Warrior : public Fighter {
public:
    Warrior(int id, const std::string& name) : Fighter(id, name) {}
};

class Mage : public Fighter {
public:
    Mage(int id, const std::string& name) : Fighter(id, name) {}
};

class TalkNotifier : public Notifier {
public:
    virtual void addToList(Fighter* player) override {
        if (player && player->familyId() > 0) {
            auto iter = m_familyList.find(player->familyId());
            if (iter != m_familyList.end()) {
                iter->second.emplace_back(player);
            } else {
                m_familyList[player->familyId()] = {player};
            }
        }
    }

    virtual void removeFromList(Fighter* player) {
        if (player && player->familyId() > 0) {
            auto iter = m_familyList.find(player->familyId());
            if (iter != m_familyList.end()) {
                iter->second.remove(player);
            }
        }
    }

    virtual void notify(Fighter* talker, const std::string& content) {
        if (talker && talker->familyId() > 0) {
            auto iter = m_familyList.find(talker->familyId());
            if (iter != m_familyList.end()) {
                for (auto it = iter->second.begin(); it != iter->second.end(); ++it) {
                    (*it)->notifyWords(talker, content);
                }
            }
        }
    }

private:
    std::map<int, std::list<Fighter*>> m_familyList;
};

int main() {
    Fighter* player1 = new Warrior(1, "warrior_p1");
    Fighter* player2 = new Warrior(2, "warrior_p2");
    Fighter* player3 = new Mage(3, "mage_p1");
    Fighter* player4 = new Mage(4, "mage_p2");

    player1->setFamilyId(1);
    player3->setFamilyId(1);

    Notifier* notifier = new TalkNotifier();
    notifier->addToList(player1);
    notifier->addToList(player2);
    notifier->addToList(player3);
    notifier->addToList(player4);

    player1->sayWords("Go to point A", notifier);
    player2->sayWords("Go to point B", notifier);

    delete player1;
    delete player2;
    delete player3;
    delete player4;
    delete notifier;
}
