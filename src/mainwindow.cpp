/*
   Qt Test Project
   Copyright 2020, Jonas Kvinge <jonas@jkvinge.net>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

 */

#include <QtGlobal>
#include <QObject>
#include <QApplication>
#include <QMainWindow>
#include <QSettings>
#include <QPushButton>
#include <QAction>
#include <QShowEvent>
#include <QCloseEvent>

#include "iconloader.h"
#include "logging.h"
#include "aboutdialog.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui_(new Ui_MainWindow),
      aboutdialog_(new AboutDialog(this)) {

  ui_->setupUi(this);

  ui_->action_about_qt->setIcon(QIcon(":/qt-project.org/qmessagebox/images/qtlogo-64.png"));
  ui_->action_about->setIcon(QIcon(":/qt-project.org/qmessagebox/images/qtlogo-64.png"));
  ui_->action_exit->setIcon(IconLoader::Load("application-exit"));
  ui_->button_exit->setIcon(IconLoader::Load("application-exit"));

  QObject::connect(ui_->button_exit, &QPushButton::clicked, this, &MainWindow::Exit);
  QObject::connect(ui_->action_exit, &QAction::triggered, this, &MainWindow::Exit);
  QObject::connect(ui_->action_about, &QAction::triggered, aboutdialog_, &AboutDialog::show);
  QObject::connect(ui_->action_about_qt, &QAction::triggered, qApp, &QApplication::aboutQt);

  show();

}

MainWindow::~MainWindow() { delete ui_; }

void MainWindow::showEvent(QShowEvent *e) {

  if (!e->spontaneous()) {
    QSettings s;
    s.beginGroup(qApp->applicationName());
    if (s.contains("geometry")) {
      restoreGeometry(s.value("geometry").toByteArray());
    }
    s.endGroup();

#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
    QScreen *screen = QGuiApplication::screenAt(pos());
    if (screen) {
      const QRect sr = screen->availableGeometry();
      const QRect wr({}, size().boundedTo(sr.size()));
      resize(wr.size());
      move(sr.center() - wr.center());
    }
#endif
  }

}

void MainWindow::closeEvent(QCloseEvent*) {
  Exit();
}

void MainWindow::Exit() {

  QSettings s;
  s.beginGroup(qApp->applicationName());
  s.setValue("geometry", saveGeometry());
  s.endGroup();

  qApp->exit();

}
