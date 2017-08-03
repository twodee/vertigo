#ifndef CUADROSWINDOW_H
#define CUADROSWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QComboBox>

#include "VertigoCanvas.h"

/* ------------------------------------------------------------------------- */

class VertigoWindow : public QMainWindow {
  Q_OBJECT

  public:
    explicit VertigoWindow(QWidget *parent = 0);
    ~VertigoWindow();

    void load(const std::string &path);

  private:
    VertigoCanvas *canvas;
    VertigoRenderer *renderer;
    QSplitter *horizontal_splitter;

    QComboBox *settings_picker;
    QComboBox *interpolation_picker;

    QString last_directory;
};

/* ------------------------------------------------------------------------- */

#endif
