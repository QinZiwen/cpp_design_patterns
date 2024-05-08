#include "common/common.h"

class Computer {
public:
    virtual void setCPU(const std::string& cpu) = 0;

    virtual void setRAM(const std::string& ram) = 0;

    virtual void setStorage(const std::string& storage) = 0;

    virtual void setGraphicsCard(const std::string& graphicsCard) = 0;

    virtual void setMonitor(const std::string& monitor) = 0;
    
    virtual void show() = 0;
};

class GamingComputer : public Computer {
public:
    virtual void setCPU(const std::string& cpu) override {
        m_cpu = cpu;
    }

    virtual void setRAM(const std::string& ram) override {
        m_ram = ram;
    }

    virtual void setStorage(const std::string& storage) override {
        m_storage = storage;
    }

    virtual void setGraphicsCard(const std::string& graphicsCard) override {
        m_graphicsCard = graphicsCard;
    }

    virtual void setMonitor(const std::string& monitor) override {
        m_monitor = monitor;
    }

    virtual void show() override {
        std::cout << "Gaming Computer:" << std::endl;
        std::cout << "CPU: " << m_cpu << std::endl;
        std::cout << "RAM: " << m_ram << std::endl;
        std::cout << "Storage: " << m_storage << std::endl;
        std::cout << "Graphics Card: " << m_graphicsCard << std::endl;
        std::cout << "Monitor: " << m_monitor << std::endl;
    }

private:
    std::string m_cpu;
    std::string m_ram;
    std::string m_storage;
    std::string m_graphicsCard;
    std::string m_monitor;
};

class OfficeComputer : public Computer {
public:
    virtual void setCPU(const std::string& cpu) override {
        m_cpu = cpu;
    }

    virtual void setRAM(const std::string& ram) override {
        m_ram = ram;
    }

    virtual void setStorage(const std::string& storage) override {
        m_storage = storage;
    }

    virtual void setGraphicsCard(const std::string& graphicsCard) override {
        m_graphicsCard = graphicsCard;
    }

    virtual void setMonitor(const std::string& monitor) override {
        m_monitor = monitor;
    }

    virtual void show() override {
        std::cout << "Office Computer:" << std::endl;
        std::cout << "CPU: " << m_cpu << std::endl;
        std::cout << "RAM: " << m_ram << std::endl;
        std::cout << "Storage: " << m_storage << std::endl;
        std::cout << "Graphics Card: " << m_graphicsCard << std::endl;
        std::cout << "Monitor: " << m_monitor << std::endl;
    }

private:
    std::string m_cpu;
    std::string m_ram;
    std::string m_storage;
    std::string m_graphicsCard;
    std::string m_monitor;
};

class ComputerBuilder {
public:
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual void buildGraphicsCard() = 0;
    virtual void buildMonitor() = 0;
    virtual Computer* getResult() = 0;
};

class GamingComputerBuilder : public ComputerBuilder {
public:
    virtual void buildCPU() override {
        m_computer->setCPU("Intel Core i7");
    }

    virtual void buildRAM() override {
        m_computer->setRAM("16GB DDR4");
    }

    virtual void buildStorage() override {
        m_computer->setStorage("1TB SSD");
    }

    virtual void buildGraphicsCard() override {
        m_computer->setGraphicsCard("NVIDIA GeForce RTX 2080 Ti");
    }

    virtual void buildMonitor() override {
        m_computer->setMonitor("27-inch 4K IPS");
    }

    Computer* getResult() override {
        return m_computer;
    }

private:
    Computer* m_computer = new GamingComputer();
};

class OfficeComputerBuilder : public ComputerBuilder {
public:
    virtual void buildCPU() override {
        m_computer->setCPU("Intel Core i5");
    }

    virtual void buildRAM() override {
        m_computer->setRAM("8GB DDR4");
    }

    virtual void buildStorage() override {
        m_computer->setStorage("500GB SSD");
    }

    virtual void buildGraphicsCard() override {
        m_computer->setGraphicsCard("Integrated Graphics");
    }

    virtual void buildMonitor() override {
        m_computer->setMonitor("24-inch Full HD");
    }

    Computer* getResult() override {
        return m_computer;
    }

private:
    Computer* m_computer = new OfficeComputer();
};

class Director {
public:
    Computer* construct(ComputerBuilder* builder) {
        builder->buildCPU();
        builder->buildRAM();
        builder->buildStorage();
        builder->buildGraphicsCard();
        builder->buildMonitor();
        return builder->getResult();
    }
};

int main() {
    Director director;
    ComputerBuilder* gamingBuilder = new GamingComputerBuilder();
    Computer* gamingComputer = director.construct(gamingBuilder);
    gamingComputer->show();
    std::cout << std::endl;

    ComputerBuilder* officeBuilder = new OfficeComputerBuilder();
    Computer* officeComputer = director.construct(officeBuilder);
    officeComputer->show();

    delete gamingComputer;
    delete gamingBuilder;
    delete officeComputer;
    delete officeBuilder;

    return 0;
}