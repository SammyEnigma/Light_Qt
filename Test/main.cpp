#include <iostream>

#include <qapplication.h>
#include <qpushbutton.h>

#include "Light.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  Light l;
  l.resize(200, 200);
  l.turnOn();
  l.show();

  QPushButton btnOn("Turn On");
  btnOn.show();
  QPushButton btnOff("Turn off");
  btnOff.show();

  qApp->connect(&btnOff, &QPushButton::clicked, &l, &Light::turnOff);
  qApp->connect(&btnOn, &QPushButton::clicked, &l, &Light::turnOn);

  return app.exec();
}