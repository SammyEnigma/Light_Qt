#include <iostream>

#include <qapplication.h>

#include "Light.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  Light l;
  l.resize(200, 200);
  l.turnOn();
  l.show();

  return app.exec();
}