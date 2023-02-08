//
// Created by Mikhail Rusanov on 25.06.2022.
//

#include "CartFilterModel.h"

CartFilterModel::CartFilterModel(QObject* parent, const CartWindow* cartWindow) : QSortFilterProxyModel(parent),
                                                                                  cartWindow(cartWindow)
{}

bool CartFilterModel::filterAcceptsRow(int sourceRow, const QModelIndex&) const
{
    return true;
}

