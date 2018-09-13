#include "Light.h"

//private functions
void Light::init(bool on, const QColor& onColor, const QColor& offColor)
{
  if (on)
  {
    turnOn();
  } //end  if (on)
  else
  {
    turnOff();
  } //end  else

  setOnColor(onColor);
  setOffColor(offColor);
}

//event handlers
void Light::paintEvent(QPaintEvent* e)
{
  std::cout << "paint event" << std::endl;
  //QPainter painter(this);
  //QPainterPath path;
  //path.addEllipse(rect());
  //QBrush brush;
  //auto color = m_on ? m_onColor : m_offColor;
  //brush.setColor(color);
  //painter.setBrush(brush);
  //painter.drawPath(path);
  //painter.fillPath(path, brush);
  QLinearGradient myGradient;
  QPen myPen;

  QPainterPath myPath;
  myPath.addEllipse(rect());

  QPainter painter(this);
  painter.setBrush(myGradient);
  painter.setPen(myPen);
  painter.drawPath(myPath);
}

//constructors
Light::Light(QWidget* parent) :
  QWidget(parent)
{
  init(false, QColor(45, 239, 77), QColor(0, 0, 0));
}
Light::~Light()
{
}

//public functions

//getters
QColor Light::onColor() const
{
  return m_onColor;
}
QColor Light::offColor() const
{
  return m_offColor;
}
bool Light::on() const
{
  return m_on;
}

//setters
void Light::setOnColor(const QColor& newColor)
{
  m_onColor = newColor;
}
void Light::setOnColor(int r, int g, int b)
{
  setOnColor(QColor(r, g, b));
}
void Light::setOffColor(const QColor& newColor)
{
  m_offColor = newColor;
}
void Light::setOffColor(int r, int g, int b)
{
  setOffColor(QColor(r, g, b));
}

//public slots
void Light::turnOn()
{
  m_on = true;
  repaint();
}
void Light::turnOff()
{
  m_on = false;
  repaint();
}
