// main.cpp
#include <QCoreApplication>
#include <QTextStream>
#include <cstdio>

QTextStream out(stdout);

class MyObject : public QObject {
  Q_OBJECT
public:
  MyObject() {}
  Q_SLOT void mySlot() { out << "Hello from " << __FUNCTION__ << endl; }
};

int main(int argc, char ** argv) {
  QCoreApplication app(argc, argv);
  MyObject obj;

  return app.exec();
}

#include "main.moc"