//
// Created by Mikhail Rusanov on 09.06.2022.
//

#ifndef WINE_TABLE_H
#define WINE_TABLE_H

#include <QTableView>
#include <QSortFilterProxyModel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <unordered_set>
#include <QStyledItemDelegate>
#include <QtWidgets/qcombobox.h>

class Wine;

enum class wineFields
{
    number,
    country,
    description,
    designation,
    points,
    price,
    province,
    region_1,
    region_2,
    taster_name,
    taster_twitter_handle,
    title,
    variety,
    winery,
    num_of_bottles,

    COUNT
};

const char *enumToString(wineFields field);


class Wine
{
public:
    Wine(std::array<QVariant, static_cast<int> (wineFields::COUNT)> data = {}) : data(data)
    {}

    Wine(std::string line);

    static std::vector<QString> stripeData(const std::string& line);

    std::array<QVariant, static_cast<int> (wineFields::COUNT)> data;

};

class WineModel : public QAbstractTableModel
{
Q_OBJECT
public:
    const std::string headers = ",country,description,designation,points,price,province,region_1,region_2,taster_name,taster_twitter_handle,title,variety,winery";

    std::vector<Wine> modelData;

    int rowCount(const QModelIndex&) const override;

    int columnCount(const QModelIndex&) const override;

    void setData(const std::vector<Wine>& data);

    void deleteRows(const std::unordered_set<size_t>& selectedRows);

    void clear();

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex&) const override;

    void addNewEntry(const Wine& wine = {});


public slots:

    void addRow();
};


#endif //WINE_TABLE_H
