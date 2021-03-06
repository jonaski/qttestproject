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

#pragma once

#include <QMainWindow>

class QShowEvent;
class QCloseEvent;
class Ui_MainWindow;
class AboutDialog;

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 protected:
  void showEvent(QShowEvent *e);
  void closeEvent(QCloseEvent *e);

 private slots:
  void Exit();

 private:

 private:
  Ui_MainWindow *ui_;
  AboutDialog *aboutdialog_;

};
