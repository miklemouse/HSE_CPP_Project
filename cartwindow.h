//
// Created by Mikhail Rusanov on 08.06.2022.
//

#ifndef CARTWINDOW_H
#define CARTWINDOW_H

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
#include "CartFilterModel.h"


class CartWindow : public QMainWindow
{
Q_OBJECT
    QTableView* modelView = nullptr;
    WineModel* wineModel = nullptr;
    QPushButton prevCart{"Previous cart"};
    QPushButton nextCart{"Next cart"};
    QPushButton purchaseButton{"Complete purchase"};
    CartFilterModel* filterModel = nullptr;
    QWidget* buyingWindow;
    QLineEdit* totalPrice;
    double totalPriceValue = 0;
    double getTotalPrice();

public:
    CartWindow(QWidget* parent = nullptr);

    std::vector<Wine> loadData(const QString& dir);

    void saveData(const QString& dir);

    void addToCart(const Wine& wine);

    ~CartWindow();

    static std::string fieldToCSVString(const QVariant& field);

public slots:

    void deleteRows();

    void loadDataFunction();

    void saveDataFunction();

    void showConfirmingPurchaseWindow();

    void loadPrevCart();

    void loadNextCart();

    friend class CartFilterModel;

protected:

    int currentCart = -1;
};

#endif // CARTWINDOW_H
