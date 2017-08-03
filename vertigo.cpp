#include <iostream>
#include <QApplication>
#include <QCommandLineParser>

#include "VertigoWindow.h"

/* ------------------------------------------------------------------------- */

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  QSurfaceFormat format;
  format.setVersion(4, 1);
  format.setProfile(QSurfaceFormat::CoreProfile);
  /* format.setDepthBufferSize(24); */
  QSurfaceFormat::setDefaultFormat(format);

  QCommandLineParser parser;
  parser.setApplicationDescription("An image editor for me.");
  parser.addPositionalArgument("file", "Image file.");
  parser.process(app);

  const QStringList args = parser.positionalArguments();

  VertigoWindow *window = new VertigoWindow();
  window->load(args.begin()->toStdString());
  window->resize(768, 512);
  window->show();

  return app.exec();
}

/* ------------------------------------------------------------------------- */

