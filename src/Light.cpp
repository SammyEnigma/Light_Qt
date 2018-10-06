#include "Light.h"

//private functions
void Light::init(bool on, const QColor& onColor, const QColor& offColor)
{
  setOnColor(onColor);
  setOffColor(offColor);

  //should happen after the colors have been set, so inital draw is the correct color
  if (on)
  {
    turnOn();
  } //end  if (on)
  else
  {
    turnOff();
  } //end  else
}

//event handlers
void Light::paintEvent(QPaintEvent* e)
{
  //figure out what color to use based on current light state
  auto color = m_on ? m_onColor : m_offColor;

  //generate the circle to be drawn
  QPainterPath path;
  path.moveTo(80.0, 50.0);
  path.addEllipse(rect());

  //create the painter to draw the circle
  QPainter painter(this);
  painter.setPen(QPen(color));
  painter.setBrush(QBrush(color));
  painter.drawPath(path);
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
  //if m is not on, turn it on, otherwise ignore
  if (!m_on)
  {
    m_on = true;
    repaint();
  } //end  if (!m_on
}
void Light::turnOff()
{
  //if m is on, turn it off. otherwise ignore
  if (m_on)
  {
    m_on = false;
    repaint();
  }
}
