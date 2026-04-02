#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class DocumentElement
{
public:
  virtual string render() = 0;
};

class TextElement : public DocumentElement
{
public:
  string text;
  TextElement(string text)
  {
    this->text = text;
  }

  string render() override
  {
    return text;
  }
};

class ImageElement : public DocumentElement
{
public:
  string imagePath;
  ImageElement(string iamgepath)
  {
    this->imagePath = imagePath;
  }
  string render() override
  {
    return imagePath;
  }
};

class NewLineElement : public DocumentElement
{
public:
  string render()
  {
    return "\n";
  }
};

class NewTabElement : public DocumentElement
{
public:
  string render()
  {
    return "\t";
  }
};

class Document
{
public:
  vector<DocumentElement *> documentElementList;

  void addElement(DocumentElement *element)
  {
    documentElementList.push_back(element);
  }

  string render()
  {
    string result;
    for (auto it : documentElementList)
    {
      result += it->render();
    }
    return result;
  }
};

class Persistence
{
public:
  virtual void save(string data) = 0;
};

class SaveToDB : public Persistence
{
public:
  void save(string data) override
  {

    cout << endl
         << data << endl;
    cout << endl
         << "Saving to db....." << endl;
  }
};

class saveToFiel : public Persistence
{
public:
  void save(string data) override
  {

    cout << endl
         << data << endl;

    cout << endl
         << "saving to file::::::" << endl;
  }
};

class DocumentEditor
{
private:
  Document *doc;
  Persistence *p;

public:
  DocumentEditor(Document *doc, Persistence *p)
  {
    this->doc = doc;
    this->p = p;
  }

  void addText(string text)
  {
    doc->addElement(new TextElement(text));
  }
  void addImage(string text)
  {
    doc->addElement(new ImageElement(text));
  }
  void renderDoc()
  {
    doc->render();
  }
  void save()
  {
    p->save(doc->render());
  }
};

int main()
{
}