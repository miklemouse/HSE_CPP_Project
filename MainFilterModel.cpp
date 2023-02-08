//
// Created by Mikhail Rusanov on 25.06.2022.
//

#include "mainwindow.h"
#include "MainFilterModel.h"


MainFilterModel::MainFilterModel (QObject *parent, const MainWindow *mainWindow) : QSortFilterProxyModel (parent), mainWindow (mainWindow)
{}

bool MainFilterModel::filterAcceptsRow (int sourceRow, const QModelIndex&) const
{
    auto country = mainWindow->countryFilter->text();
    const Wine& wine = mainWindow->wineModel->modelData[sourceRow];
    double minPrice = mainWindow->minPrice->value();
    double maxPrice = mainWindow->maxPrice->value();
    double price = wine.data[(int)wineFields::price].toDouble();
    return (price < maxPrice && price >= minPrice) &&
           (!country.size () || wine.data[(int)wineFields::country].toString () == country);
}

void MainFilterModel::sort(int column, Qt::SortOrder order)
{
    QSortFilterProxyModel::sort(column, order);
    if (sortByPoints)
        QSortFilterProxyModel::sort((int)wineFields::points, Qt::DescendingOrder);
}
