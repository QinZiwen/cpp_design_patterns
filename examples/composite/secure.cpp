#include "common/common.h"

class Dir;

class FileSystem {
public:
    virtual ~FileSystem() {}
    virtual void showName(int level) = 0;
    virtual Dir* isCompositeObj() { return nullptr; }
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

    virtual Dir* isCompositeObj() { return this; }

    int add(FileSystem* pfilesys) {
        if (pfilesys == nullptr) {
            return -1;
        }

        m_child.push_back(pfilesys);
        return 0;
    }

    int remove(FileSystem* pfilesys) {
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

    Dir* dir1 = pdir1->isCompositeObj();
    if (dir1 != nullptr) {
        dir1->add(pfile1);
        dir1->add(pfile2);
        dir1->add(pfile3);
    }

    Dir* dir2 = pdir2->isCompositeObj();
    if (dir2 != nullptr) {
        dir1->add(pdir2);
        dir2->add(pfile4);
        dir2->add(pfile5);
    }
    
    Dir* dir3 = pdir3->isCompositeObj();
    if (dir3 != nullptr) {
        dir1->add(pdir3);
        dir3->add(pfile6);
        dir3->add(pfile7);

        Dir* dir4 = pdir4->isCompositeObj();
        if (dir4 != nullptr) {
            dir3->add(pdir4);
            dir4->add(pfile8);
        }
    }

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
