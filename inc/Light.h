#ifndef ON_OFF_LIGHT_WIDGET_H
#define ON_OFF_LIGHT_WIDGET_H

#include <qwidget.h>
#include <qcolor.h>
#include <qevent.h>

//TEMP
#include <qpainter.h>
#include <qbrush.h>

class Light : public QWidget
{
private:
  //member data
  QColor m_onColor;
  QColor m_offColor;
  bool m_on;

  //private functions
  void init(bool on, const QColor& onColor, const QColor& offColor);

protected:
  //event handlers
  void paintEvent(QPaintEvent* e) override;

public:
  //constructors
  Light(QWidget* parent = nullptr);
  //TODO: add other constructors
  ~Light();

  //public functions

  //getters
  QColor onColor() const;
  QColor offColor() const;
  bool on() const;

  //setters
  void setOnColor(const QColor& newColor);
  void setOnColor(int r, int g, int b);
  void setOffColor(const QColor& newColor);
  void setOffColor(int r, int g, int b);

signals:
  //signals
  void stateChanged(bool on);

public slots:
  //public slots
  void turnOn();
  void turnOff();

};

#endif