//
// Created by Mikhail Rusanov on 09.06.2022.
//

#include "WineTable.h"

int WineModel::rowCount(const QModelIndex&) const
{
    return modelData.size();
}

int WineModel::columnCount(const QModelIndex&) const
{
    return static_cast<int> (wineFields::COUNT);
}

void WineModel::deleteRows(const std::unordered_set<size_t>& selectedRows)
{
    beginResetModel();
    size_t j = 0;
    for (size_t i = 0; i < modelData.size(); ++i)
    {
        if (selectedRows.find(i) == selectedRows.end())
            modelData[j++] = modelData[i];
    }
    modelData.resize(j);

    endResetModel();
    emit layoutChanged();
}

void WineModel::clear()
{
    beginResetModel();
    modelData.clear();

    endResetModel();
    emit layoutChanged();
}

QVariant WineModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
    const Wine& currentWine = modelData[index.row()];
    return currentWine.data[index.column()];
    }
    return {};
}

Qt::ItemFlags WineModel::flags(const QModelIndex&) const
{
    return {Qt::ItemIsEnabled, Qt::ItemIsEditable, Qt::ItemIsSelectable};
}

void WineModel::addNewEntry(const Wine& wine)
{
    beginResetModel();
    modelData.push_back(wine);
    endResetModel();
    emit layoutChanged();
}

void WineModel::setData(const std::vector<Wine>& data)
{
    beginResetModel();
    modelData = data;
    endResetModel();
    emit layoutChanged();
}


const char *enumToString(wineFields field)
{
    switch (field)
    {
        case wineFields::number:
            return "number";
        case wineFields::country:
            return "country";
        case wineFields::description:
            return "description";
        case wineFields::designation:
            return "designation";
        case wineFields::points:
            return "points";
        case wineFields::price:
            return "price";
        case wineFields::province:
            return "province";
        case wineFields::region_1:
            return "region_1";
        case wineFields::region_2:
            return "region_2";
        case wineFields::taster_name:
            return "taster_name";
        case wineFields::taster_twitter_handle:
            return "taster_twitter_handle";
        case wineFields::title:
            return "title";
        case wineFields::variety:
            return "variety";
        case wineFields::winery:
            return "winery";
        case wineFields::num_of_bottles:
            return "num_of_bottles";
        case wineFields::COUNT:
            return "";
    }
    return {};
}

void WineModel::addRow()
{
    addNewEntry();
}

std::vector<QString> Wine::stripeData(const std::string& line)
{
    std::vector<QString> result;
    std::string currentString;
    bool withinQuotes = false;
    for (size_t i = 0; i < line.size(); ++i)
    {
        if (line[i] == '"')
        {
            if (withinQuotes)
            {
                if (i + 1 < line.size() && line[i + 1] == '"')
                {
                    currentString += '"';
                    ++i;
                }
                else
                    withinQuotes = false;
            }
            else
                withinQuotes = true;
            continue;
        }
        if (line[i] == ',' && !withinQuotes)
        {
            result.emplace_back(currentString.c_str());
            currentString.clear();
            continue;
        }
        currentString += line[i];
    }
    result.emplace_back(currentString.c_str());
    return result;
}

Wine::Wine(std::string line)
{
    std::vector<QString> split = stripeData(line);
    for (size_t fieldNum = 0; fieldNum < static_cast<int> (wineFields::COUNT); ++fieldNum)
    {
        if (fieldNum == (int) (wineFields::num_of_bottles))
            data[fieldNum] = 1;
        else if (fieldNum == (int) wineFields::number || fieldNum == (int) wineFields::points)
            data[fieldNum] = split[fieldNum].toInt();
        else if (fieldNum == (int) wineFields::price)
            data[fieldNum] = split[fieldNum].toDouble();
        else
            data[fieldNum] = split[fieldNum];
    }
}
