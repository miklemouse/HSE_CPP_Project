//
// Created by Mikhail Rusanov on 25.06.2022.
//

#ifndef MAINFILTERMODEL_H
#define MAINFILTERMODEL_H

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
#include "WineTable.h"
#include "cartwindow.h"

class MainWindow;

class MainFilterModel : public QSortFilterProxyModel
{
Q_OBJECT
public:
    MainFilterModel(QObject* parent, const MainWindow* mainWindow);
    virtual void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;

    bool sortByPoints = false;

protected:
    virtual bool filterAcceptsRow(int sourceRow, const QModelIndex &source_parent) const override;


private:
    const MainWindow* mainWindow = nullptr;
};


#endif //MAINFILTERMODEL_H
