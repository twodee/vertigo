#include <iostream>

#include "VertigoCanvas.h"

/* ------------------------------------------------------------------------- */

VertigoCanvas::VertigoCanvas(QWidget *parent) :
  QOpenGLWidget(parent),
  renderer() {
}

/* ------------------------------------------------------------------------- */

void VertigoCanvas::initializeGL() {
  initializeOpenGLFunctions();
  renderer.initializeGL();
}

/* ------------------------------------------------------------------------- */

void VertigoCanvas::paintGL() {
  renderer.render();
}

/* ------------------------------------------------------------------------- */

void VertigoCanvas::resizeGL(int width, int height) {
  renderer.resize(width, height);
}

/* ------------------------------------------------------------------------- */

VertigoRenderer *VertigoCanvas::getRenderer() {
  return &renderer;
}

/* ------------------------------------------------------------------------- */

void VertigoCanvas::mousePressEvent(QMouseEvent *event) {
  makeCurrent();
  if (event->buttons() & Qt::LeftButton) {
    renderer.leftMouseDownAt(event->x(), height() - event->y());
  } else if (event->buttons() & Qt::RightButton) {
  }
  update();
}

/* ------------------------------------------------------------------------- */

void VertigoCanvas::mouseMoveEvent(QMouseEvent *event) {
  makeCurrent();
  if (event->buttons() & Qt::LeftButton) {
    renderer.leftMouseDraggedTo(event->x(), height() - event->y());
  } else if (event->buttons() & Qt::RightButton) {
  }
  update();
}

/* ------------------------------------------------------------------------- */

void VertigoCanvas::mouseReleaseEvent(QMouseEvent *event) {
  makeCurrent();
  update();
}

/* ------------------------------------------------------------------------- */

void VertigoCanvas::wheelEvent(QWheelEvent *event) {
  makeCurrent();
  renderer.scroll(event->angleDelta().y());
  update();
}

/* ------------------------------------------------------------------------- */

