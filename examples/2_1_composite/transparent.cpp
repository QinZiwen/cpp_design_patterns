#include "common/common.h"

class FileSystem {
public:
    virtual ~FileSystem() {}
    virtual void showName(int level) = 0;
    virtual int add(FileSystem* pfilesys) = 0;
    virtual int remove(FileSystem* pfilesys) = 0;
};

class File : public FileSystem {
public:
    File(const std::string& name) : m_name(name) {}
    
    virtual void showName(int level) override {
        for (int i = 0; i < level; ++i) {
            std::cout << "    ";
        }
        std::cout << " - " << m_name << std::endl;
    }

    virtual int add(FileSystem* pfilesys) override {
        return -1;
    }

    virtual int remove(FileSystem* pfilesys) {
        return -1;
    }

private:
    std::string m_name;
};

class Dir : public FileSystem {
public:
    Dir(const std::string& name) : m_name(name) {}

    virtual void showName(int level) override {
        for (int i = 0; i < level; ++i) {
            std::cout << "    ";
        }
        std::cout << " + " << m_name << std::endl;

        ++level;
        for (const auto& child : m_child) {
            child->showName(level);
        }
    }

    virtual int add(FileSystem* pfilesys) override {
        if (pfilesys == nullptr) {
            return -1;
        }

        m_child.push_back(pfilesys);
        return 0;
    }

    virtual int remove(FileSystem* pfilesys) override {
        if (pfilesys == nullptr) {
            return -1;
        }

        m_child.remove(pfilesys);
        return 0;
    }

private:
    std::string m_name;
    std::list<FileSystem*> m_child;
};

int main() {
    FileSystem* pdir1 = new Dir("root");

    FileSystem* pfile1 = new File("root_file1");
    FileSystem* pfile2 = new File("root_file2");
    FileSystem* pfile3 = new File("root_file3");

    FileSystem* pdir2 = new Dir("app");
    FileSystem* pfile4 = new File("app_file1");
    FileSystem* pfile5 = new File("app_file2");

    FileSystem* pdir3 = new Dir("user");
    FileSystem* pfile6 = new File("user_file1");
    FileSystem* pfile7 = new File("user_file2");

    FileSystem* pdir4 = new Dir("shared");
    FileSystem* pfile8 = new File("shared_file1");

    pdir1->add(pfile1);
    pdir1->add(pfile2);
    pdir1->add(pfile3);

    pdir1->add(pdir2);
    pdir2->add(pfile4);
    pdir2->add(pfile5);

    pdir1->add(pdir3);
    pdir3->add(pfile6);
    pdir3->add(pfile7);

    pdir3->add(pdir4);
    pdir4->add(pfile8);

    pdir1->showName(0);

    delete pfile8;
    delete pdir4;
    
    delete pfile7;
    delete pfile6;
    delete pdir3;

    delete pfile5;
    delete pfile4;
    delete pdir2;

    delete pfile3;
    delete pfile2;
    delete pfile1;
    delete pdir1;
    return 0;
}