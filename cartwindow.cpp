//
// Created by Mikhail Rusanov on 08.06.2022.
//

#include "cartwindow.h"
#include <QGridLayout>
#include <QMenuBar>
#include <QFileDialog>
#include <fstream>
#include <QPainter>
#include <sstream>
#include <limits>


CartWindow::CartWindow(QWidget* parent)
        : QMainWindow(parent)
{
    QWidget* centralWidget = new QWidget(this);
    resize(600, 400);

    buyingWindow = new QWidget();
    QGridLayout* buyingWindowLayout = new QGridLayout(buyingWindow);
    buyingWindowLayout->addWidget(new QLabel("Your order has been completed!"));

    setCentralWidget(centralWidget);

    wineModel = new WineModel();
    filterModel = new CartFilterModel(this, this);
    filterModel->setSourceModel(wineModel);
    modelView = new QTableView(centralWidget);
    modelView->setModel(filterModel);
    modelView->setSelectionBehavior(QAbstractItemView::SelectRows);
    modelView->setColumnHidden((int)wineFields::description, true);
    modelView->setColumnHidden((int)wineFields::designation, true);
    modelView->setColumnHidden((int)wineFields::province, true);
    modelView->setColumnHidden((int)wineFields::region_1, true);
    modelView->setColumnHidden((int)wineFields::region_2, true);
    modelView->setColumnHidden((int)wineFields::taster_name, true);
    modelView->setColumnHidden((int)wineFields::taster_twitter_handle, true);
    modelView->setColumnHidden((int)wineFields::variety, true);
    modelView->setColumnHidden((int)wineFields::winery, true);


    QGridLayout* layout = new QGridLayout(centralWidget);

    QHBoxLayout* nameLayout = new QHBoxLayout(this);
    layout->addLayout(nameLayout, 0, 0);
    nameLayout->addWidget(new QLabel("Shopping cart"));


    layout->addWidget(modelView);

    QHBoxLayout *totalPriceLayout = new QHBoxLayout(this);
    totalPrice = new QLineEdit ();
    totalPriceLayout->addWidget(new QLabel ("Total price:"));
    totalPriceLayout->addWidget(totalPrice);
    totalPriceLayout->addStretch();
    totalPrice->setReadOnly(true);
    layout->addLayout (totalPriceLayout, 2, 0);


    QHBoxLayout* cartLayout = new QHBoxLayout(this);
    cartLayout->addWidget(&purchaseButton);
    cartLayout->addWidget(&prevCart);
    cartLayout->addWidget(&nextCart);
    cartLayout->addStretch();
    layout->addLayout(cartLayout, 3, 0);
    connect (&purchaseButton, &QPushButton::clicked, this, &CartWindow::showConfirmingPurchaseWindow);
    connect (&prevCart, &QPushButton::clicked, this, &CartWindow::loadPrevCart);
    connect (&nextCart, &QPushButton::clicked, this, &CartWindow::loadNextCart);

    auto fileMenu = menuBar()->addMenu("File");
    QAction* openAction = new QAction("Open");
    connect(openAction, &QAction::triggered, this, &CartWindow::loadDataFunction);
    fileMenu->addAction(openAction);

    QAction* saveAsAction = new QAction("Save As");
    connect(saveAsAction, &QAction::triggered, this, &CartWindow::saveDataFunction);
    fileMenu->addAction(saveAsAction);

    auto editMenu = menuBar()->addMenu("Edit");

    QAction* addAction = new QAction("Add Row");
    connect(addAction, &QAction::triggered, wineModel, &WineModel::addRow);
    addAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_A));

    QAction* deleteAction = new QAction("Delete Rows");
    connect(deleteAction, &QAction::triggered, this, &CartWindow::deleteRows);
    deleteAction->setShortcut(QKeySequence(Qt::Key_Delete));

    editMenu->addAction(addAction);
    editMenu->addAction(deleteAction);

}

void CartWindow::addToCart(const Wine& wine)
{
    bool exists = false;
    for (auto& w: wineModel->modelData)
    {
        if (w.data[static_cast<int> (wineFields::number)] == wine.data[static_cast<int> (wineFields::number)])
        {
            exists = true;
            int numberOfBottlesCol = static_cast<int> (wineFields::num_of_bottles);
            w.data[numberOfBottlesCol] = w.data[numberOfBottlesCol].toInt() + 1;
            w.data[(int) wineFields::price] = w.data[numberOfBottlesCol].toInt() * wine.data[(int) wineFields::price].toDouble();
            break;
        }
    }
    if (!exists)
        wineModel->addNewEntry(wine);

    currentCart = -1;
    totalPriceValue = getTotalPrice();
}

void CartWindow::deleteRows()
{
    std::unordered_set<size_t> rowsToDelete;
    for (const auto& row_index: modelView->selectionModel()->selectedRows())
        rowsToDelete.insert(row_index.row());
    if (rowsToDelete.size())
        wineModel->deleteRows(rowsToDelete);

    currentCart = -1;
    totalPriceValue = getTotalPrice();
}


void CartWindow::loadDataFunction()
{
    auto dir = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath());
    if (!dir.size())
        return;
    auto data = loadData(dir);
    wineModel->setData(data);
}

void CartWindow::saveDataFunction()
{
    auto dir = QFileDialog::getSaveFileName(this, "Save File As", QDir::currentPath());
    if (!dir.size())
        return;
    saveData(dir);
}

void CartWindow::showConfirmingPurchaseWindow()
{
    int i = 0;
    while (true)
    {
        std::ifstream file(".cart_" + std::to_string(i) + ".csv");
        if (!file.good())
            break;
        ++i;
    }

    if (wineModel->modelData.size()) //
    {
        CartWindow::saveData((".cart_" + std::to_string(i) + ".csv").c_str());

        if (!buyingWindow)
            buyingWindow = new QWidget();
        buyingWindow->show();

        wineModel->clear();
    }
}

void CartWindow::loadPrevCart()
{
    if (currentCart == -1)
    {
        int i = 0;
        while (true)
        {
            std::ifstream file(".cart_" + std::to_string(i) + ".csv");
            if (!file.good())
                break;
            ++i;
        }
        if (i == 0)
            return;
        wineModel->setData(loadData((".cart_" + std::to_string(i - 1) + ".csv").c_str()));
        currentCart = i - 1;
    }
    else if (currentCart > 0)
    {
        --currentCart;
        wineModel->setData(loadData((".cart_" + std::to_string(currentCart) + ".csv").c_str()));
    }
}

void CartWindow::loadNextCart()
{
    if (currentCart == -1)
        return;
    std::ifstream file(".cart_" + std::to_string(currentCart + 1) + ".csv");
    if (!file.good())
        return;
    wineModel->setData(loadData((".cart_" + std::to_string(currentCart + 1) + ".csv").c_str()));
    ++currentCart;
}

std::vector<Wine> CartWindow::loadData(const QString& dir)
{
    std::fstream file;
    std::vector<Wine> result;
    file.open(dir.toStdString ());
    std::string line;
    bool firstLine = true;
    while (std::getline(file, line))
    {
        if (firstLine)
        {
            //wineModel->headers = QString(line.c_str());
            firstLine = false;
            continue;
        }
        result.emplace_back(line);
    }
    file.close();
    return result;

    currentCart = -1;
    totalPriceValue = getTotalPrice();
}

void CartWindow::saveData(const QString& dir)
{
    std::ofstream file(dir.toStdString());
    int totalColumns = static_cast<int> (wineFields::COUNT);

    file << wineModel->headers << '\n';
    for (auto& wine: wineModel->modelData)
    {
        for (int ithColumn = 0; ithColumn < totalColumns; ++ithColumn)
        {
            file << fieldToCSVString(wine.data[ithColumn]);
            if (ithColumn < totalColumns - 1)
                file << ",";
            else
                file << "\n";
        }
    }
}

CartWindow::~CartWindow()
{
}

QVariant WineModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        wineFields field = (wineFields) section;
        return enumToString(field);
    }
    return {};
}

double CartWindow::getTotalPrice()
{
    double res = 0;
    for (auto& wine: wineModel->modelData)
        res += wine.data[static_cast<int> (wineFields::price)].toDouble();
    totalPrice->setText(QString::number(res));
    return res;
}

std::string CartWindow::fieldToCSVString(const QVariant& field)
{
    std::string res = field.toString().toStdString();
    for (int i = 0; i < res.size(); ++i)
        if (res[i] == '"')
            res.insert(i++, "\"");
    if (res.find(',') != std::string::npos)
        res = '"' + res + '"';
    return res;
}
