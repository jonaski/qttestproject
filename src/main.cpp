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
#include <QApplication>
#include <QCoreApplication>
#include <QLoggingCategory>

#include "logging.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {

  QCoreApplication::setApplicationName("qttestproject");
  QCoreApplication::setOrganizationName("qttestproject");
  QCoreApplication::setApplicationVersion("0.0.1");
  QCoreApplication::setOrganizationDomain("jkvinge.net");

  logging::Init();

  QApplication app(argc, argv);

  QLoggingCategory::defaultCategory()->setEnabled(QtDebugMsg, true);

  Q_INIT_RESOURCE(data);
  Q_INIT_RESOURCE(icons);

  MainWindow w;

  return app.exec();

}
