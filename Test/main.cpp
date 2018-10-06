#include <iostream>

#include <qapplication.h>
#include <qpushbutton.h>
#include <qcheckbox.h>

#include "Light.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  Light l;
  l.resize(200, 200);
  l.turnOn();
  l.show();

  QPushButton btnOn("Turn On");
  btnOn.move(0, 0);
  btnOn.show();
  QPushButton btnOff("Turn off");
  btnOff.move(0, 50);
  btnOff.show();
  QCheckBox chkBox("on/off?");
  chkBox.show();

  qApp->connect(&btnOff, &QPushButton::clicked, &l, &Light::turnOff);
  qApp->connect(&btnOn, &QPushButton::clicked, &l, &Light::turnOn);
  qApp->connect(&l, &Light::stateChanged, &chkBox, &QCheckBox::setChecked);

  return app.exec();
}
