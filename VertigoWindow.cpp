#include <iostream>

#include <QFileDialog>
#include <QGridLayout>
#include <QLabel>
#include <QSpacerItem>
#include <QStackedWidget>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include <QVBoxLayout>

#include "VertigoWindow.h"

/* ------------------------------------------------------------------------- */

VertigoWindow::VertigoWindow(QWidget *parent) :
  QMainWindow(parent),
  last_directory(QDir::homePath()) {

  horizontal_splitter = new QSplitter(this);
  horizontal_splitter->setOrientation(Qt::Horizontal);

  canvas = new VertigoCanvas(horizontal_splitter);
  renderer = canvas->getRenderer();

  QSizePolicy p1(QSizePolicy::Preferred, QSizePolicy::Preferred);
  p1.setHorizontalStretch(1);
  p1.setVerticalStretch(1);
  canvas->setSizePolicy(p1);

  QWidget *settings_panel = new QWidget(horizontal_splitter);;

  horizontal_splitter->addWidget(canvas);
  horizontal_splitter->addWidget(settings_panel);

  QSpacerItem *vertical_spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

  settings_picker = new QComboBox();
  settings_picker->addItem("Display");

  QStackedWidget *settings_pager = new QStackedWidget();

  QWidget *display_page = new QWidget();

  QGridLayout *display_page_layout = new QGridLayout(display_page);
  display_page_layout->setSpacing(-1);
  display_page_layout->setContentsMargins(0, 0, 0, 0);
  display_page_layout->addItem(vertical_spacer, 1, 0, 1, 2);

  // Add pages
  settings_pager->addWidget(display_page);

  QVBoxLayout *settings_panel_layout = new QVBoxLayout(settings_panel);
  settings_panel_layout->setSpacing(6);
  settings_panel_layout->setContentsMargins(0, 6, 0, 0);
  settings_panel_layout->addWidget(settings_picker);
  settings_panel_layout->addWidget(settings_pager);

  this->setCentralWidget(horizontal_splitter);

  setWindowTitle("Vertigo");
}

/* ------------------------------------------------------------------------- */

VertigoWindow::~VertigoWindow() {
}

/* ------------------------------------------------------------------------- */

void VertigoWindow::load(const std::string &path) {
  renderer->load(path);
}

/* ------------------------------------------------------------------------- */

