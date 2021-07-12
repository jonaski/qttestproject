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
#include <QCoreApplication>
#include <QDialog>
#include <QDialogButtonBox>
#include <QString>
#include <QIcon>
#include <QPixmap>
#include <QPoint>
#include <QFont>
#include <QLabel>
#include <QPushButton>
#include <QKeySequence>
#include <QShowEvent>

#include "iconloader.h"

#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent), ui_(new Ui_AboutDialog) {

  ui_->setupUi(this);
  setWindowFlags(this->windowFlags()|Qt::WindowStaysOnTopHint);
  setWindowTitle(tr("About Qt Test Project"));

  ui_->label_icon->setPixmap(QPixmap(":/qt-project.org/qmessagebox/images/qtlogo-64.png"));

  QFont title_font;
  title_font.setBold(true);
  title_font.setPointSize(title_font.pointSize() + 2);
  ui_->headline->setFont(title_font);
  QString html;
  html += "<p>";
  html += tr("About Qt Test Project");
  html += "<br />";
  html += tr("Version %1").arg(QCoreApplication::applicationVersion());
  html += "</p>";
  html += tr("</p>");
  ui_->headline->setText(html);

  html.clear();

  html += "<p>";
  html += tr("Qt Test Project by %1.").arg("<a href=\"https://jkvinge.net/\">Jonas Kvinge</a>");
  html += "</p>";

  ui_->text->setText(html);

  ui_->buttonBox->button(QDialogButtonBox::Close)->setShortcut(QKeySequence::Close);

  QObject::connect(ui_->buttonBox, &QDialogButtonBox::accepted, this, &AboutDialog::Close);
  QObject::connect(ui_->buttonBox, &QDialogButtonBox::rejected, this, &AboutDialog::Close);

}

AboutDialog::~AboutDialog() { delete ui_; }

void AboutDialog::showEvent(QShowEvent *e) {

  Q_UNUSED(e)

}

void AboutDialog::Close() {

  hide();

}
