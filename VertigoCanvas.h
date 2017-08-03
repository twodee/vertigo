#ifndef CUADROSCANVAS_H
#define CUADROSCANVAS_H

#include <QMouseEvent>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_4_1_Core>

#include "VertigoRenderer.h"

class VertigoCanvas : public QOpenGLWidget, protected QOpenGLFunctions_4_1_Core {
  public:
    explicit VertigoCanvas(QWidget *parent = nullptr);

    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    VertigoRenderer *getRenderer();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

  private:
    VertigoRenderer renderer;
};


#endif
