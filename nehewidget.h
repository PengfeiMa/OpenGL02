#ifndef NEHEWIDGET_H
#define NEHEWIDGET_H

#include <QWidget>
#include <qopengl.h>
#include <QGLWidget>
#include <QKeyEvent>
#include <QMainWindow>
#include <GL/glu.h>

namespace UI {
class NeHeWidget;
}

class NeHeWidget : public QGLWidget
{
    Q_OBJECT

public:

  NeHeWidget( QWidget* parent = 0, const char* name = 0, bool fs = false );
  void keyPressEvent( QKeyEvent *e );
  ~NeHeWidget();

protected:

  bool fullscreen;
  GLfloat rTri;
  GLfloat rQuad;

  void initializeGL();
  void paintGL();
  void resizeGL( int width, int height );


};

#endif // NEHEWIDGET_H
