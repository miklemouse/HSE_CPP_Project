//
// Created by Mikhail Rusanov on 25.06.2022.
//

#ifndef CARTFILTERMODEL_H
#define CARTFILTERMODEL_H

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
#include "WineTable.h"

class CartWindow;

class CartFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    CartFilterModel(QObject* parent, const CartWindow* cartWindow);

protected:
    virtual bool filterAcceptsRow(int sourceRow, const QModelIndex& source_parent) const override;

private:
    const CartWindow* cartWindow = nullptr;
};


#endif //CARTFILTERMODEL_H
