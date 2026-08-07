#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class FileSystemItem
{
public:
  virtual ~FileSystemItem() = default;
  virtual void operation() = 0;
  virtual void ls(int indent = 0) = 0;
  virtual void openAll(int indent = 0) = 0;
  virtual FileSystemItem* cd(string name) = 0;
  virtual double getSize() = 0;
  virtual string getName() = 0;
  virtual bool isFolder() = 0;
};

class FileItem : public FileSystemItem
{
  string fileName;
  double size;

public:
  FileItem(string fileName, double fileSize)
  {
    this->fileName = fileName;
    this->size = fileSize;
  }


  void ls(int indent) override {
    cout<<endl<<string(indent, ' ')<<this->fileName;
  }

  void openAll(int indent) override {
    cout<<endl<<string(indent, ' ')<<this->fileName;
  }

  void operation() override {
    cout << endl
         << "Name: " << this->fileName;
    cout << endl
         << "Size: " << this->size;
  }

  bool isFolder() override {
    return false;
  }

  double getSize() override{
    return this->size;
  }

  FileSystemItem* cd(string str) override {
    (void)str;
    return nullptr;
  }

  string getName() override {
    return this->fileName;
  }

};
class FolderItem : public FileSystemItem
{
  string folderName;
  double size;
  vector<FileSystemItem*> children;

public:
  FolderItem(string folderName, double fileSize)
  {
    this->folderName = folderName;
    this->size = fileSize;
  }

  void operation() override
  {
    cout << endl
         << "Name: " << this->folderName;
    cout << endl
         << "Size: " << this->size;
  }

  void ls(int indent = 0) override {
    for (auto item: children) {
      if (item->isFolder()) {
        cout<<endl<<"*"<<string(indent, ' ')<<item->getName();
      } else {
        cout<<endl<<string(indent, ' ')<<item->getName();
      }
    }
  }

  void openAll(int indent = 0) override {
    for (auto item: children) {
      item->openAll(indent + 2);
    }
  }

  void add(FileSystemItem* fileSystemChild) {
    children.push_back(fileSystemChild);
  }

  bool isFolder() override {
    return true;
  }

    double getSize() override {
    return this->size;
  }

    string getName() override {
    return this->folderName;
  }

  void openAll(int indent = 0) override {
    cout<<endl<<string(indent, ' ')<<this->folderName;
    for (auto item: children){
      item->openAll(indent+4);
    }
  }

  double getSize() override {
    double size = 0;
    for (auto item: children) {
      size += item->getSize();
    }
    return size;
  }

  FileSystemItem* cd(string target) override {
    for (auto item: children) {
      if (item->isFolder() && item == target) return item;
    }
    return nullptr;
  }
};

int main() {
  
}