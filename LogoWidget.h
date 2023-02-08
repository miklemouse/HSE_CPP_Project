//
// Created by Mikhail Rusanov on 25.06.2022.
//

#ifndef LOGOWIDGET_H
#define LOGOWIDGET_H

#include <QMainWindow>
#include <QTableView>
#include <QSortFilterProxyModel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <unordered_set>
#include <QStyledItemDelegate>
#include <QtWidgets/qcombobox.h>
#include <QGridLayout>
#include <QPainter>
#include <QtGui/qpainterpath.h>


class LogoWidget : public QWidget
{
    Q_OBJECT
public:
    LogoWidget(QWidget* = nullptr);
    void drawLogo(QPainter& painter, int width, int height);

protected:
    void paintEvent(QPaintEvent* event) override;
};


#endif //LOGOWIDGET_H
