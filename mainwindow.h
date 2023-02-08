//
// Created by Mikhail Rusanov on 08.06.2022.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <QCheckBox>
#include "WineTable.h"
#include "cartwindow.h"
#include "MainFilterModel.h"
#include "LogoWidget.h"

class MainWindow : public QMainWindow
{
Q_OBJECT
    QTableView* modelView = nullptr;
    WineModel* wineModel = nullptr;
    QCheckBox checkBox {"Always sort by points"};
    QDoubleSpinBox* minPrice;
    QDoubleSpinBox* maxPrice;
    QLineEdit* countryFilter;
    QPushButton applyFilter{"Apply"};
    QPushButton showCartButton{"Add to cart"};
    MainFilterModel* filterModel = nullptr;
    LogoWidget* logo;
    CartWindow* cartWindow;
    QLineEdit* entryNumberElement;
    QWidget *aboutWindow;

private:

    void renderAboutWindow();

public:
    MainWindow(QWidget* parent = nullptr);

    std::vector<Wine> loadData(const QString &dir);

    void saveData(const QString &dir);

    ~MainWindow();

public slots:

    void deleteRows();

    void loadDataFunction();

    void saveDataFunction();

    void aboutFunction();

    void getHelpFunction();

    void filterData();

    void showCartButtonFunction();

    void checkBoxFunction(int state);

    friend class MainFilterModel;
};


#endif // MAINWINDOW_H
