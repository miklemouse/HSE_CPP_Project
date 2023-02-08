//
// Created by Mikhail Rusanov on 08.06.2022.
//

#include "mainwindow.h"
#include <QGridLayout>
#include <QMenuBar>
#include <QFileDialog>
#include <fstream>
#include <sstream>
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget (this);
    resize (1200, 600);

    cartWindow = new CartWindow();

    setCentralWidget(centralWidget);

    wineModel = new WineModel();
    filterModel = new MainFilterModel(this, this);
    filterModel->setSourceModel (wineModel);
    modelView = new QTableView(centralWidget);
    modelView->setSelectionBehavior(QAbstractItemView::SelectRows);
    modelView->setSortingEnabled(true);
    modelView->setModel (filterModel);
    modelView->setColumnHidden((int)wineFields::num_of_bottles, true);

    QGridLayout *layout = new QGridLayout(centralWidget);
    logo = new LogoWidget (this);
    logo->setFixedSize(50, 50);

    QHBoxLayout *logoLayout = new QHBoxLayout(this);
    layout->addLayout (logoLayout, 0, 0);
    logoLayout->addWidget (logo);
    logoLayout->addWidget (new QLabel("Wine Catalog"));

    /*entryNumberElement = new QLineEdit ();*/
    QHBoxLayout *addToCartLayout = new QHBoxLayout(this);
    /*addToCartLayout->addWidget(new QLabel ("Enter the number of the wine you want to buy:"));*/
    addToCartLayout->addWidget(entryNumberElement);
    addToCartLayout->addWidget(&showCartButton);
    addToCartLayout->addStretch();
    layout->addLayout (addToCartLayout, 1, 0);
    connect (&showCartButton, &QPushButton::clicked, this, &MainWindow::showCartButtonFunction);


    layout->addWidget (modelView);


    minPrice = new QDoubleSpinBox();
    maxPrice = new QDoubleSpinBox();
    countryFilter = new QLineEdit ();
    countryFilter->setMaximumWidth(100);

    maxPrice->setRange (0, 1e30);
    maxPrice->setValue (1e30);
    maxPrice->setMaximumWidth(100);

    minPrice->setRange (0, 1e30);
    minPrice->setValue (0);
    minPrice->setMaximumWidth(100);

    std::map<const char*, QWidget*> filters = {{"Min Price:", minPrice},
                                                 {"Max Price:", maxPrice},
                                                 {"Country:", countryFilter}};

/*    QHBoxLayout *checkBoxLayout = new QHBoxLayout(this);
    checkBoxLayout->addWidget(new QLabel ("Enter the number of the wine you want to buy:"));
    checkBoxLayout->addWidget(entryNumberElement);
    checkBoxLayout->addWidget(&checkBox);
    checkBoxLayout->addStretch();
    layout->addLayout (checkBoxLayout, 1, 0);
    connect (&, &QPushButton::clicked, this, &MainWindow::showCartButtonFunction); */

    QHBoxLayout *checkBoxLayout = new QHBoxLayout(this);
    checkBoxLayout->addWidget(&checkBox);
    layout->addLayout(checkBoxLayout, 4, 0);
    connect (&checkBox, &QCheckBox::stateChanged, this, &MainWindow::checkBoxFunction);

    int currentRow = 5;
    for (const auto& filter : filters)
    {
        QHBoxLayout *localLayout = new QHBoxLayout(this);
        localLayout->addWidget(new QLabel (filter.first));
        localLayout->addWidget(filter.second);
        localLayout->addStretch();
        layout->addLayout (localLayout, currentRow++, 0);
    }

    layout->addWidget (&applyFilter);
    applyFilter.setMaximumWidth(50);

    connect (&applyFilter, &QPushButton::clicked, this, &MainWindow::filterData);

    auto fileMenu = menuBar ()->addMenu ("File");

    QAction *openAction = new QAction ("Open");
    connect (openAction, &QAction::triggered, this, &MainWindow::loadDataFunction);
    fileMenu->addAction  (openAction);

    QAction *saveAsAction = new QAction ("Save As");
    connect (saveAsAction, &QAction::triggered, this, &MainWindow::saveDataFunction);
    fileMenu->addAction  (saveAsAction);

    auto editMenu = menuBar ()->addMenu ("Edit");

    QAction *addAction = new QAction ("Add Row");
    connect (addAction, &QAction::triggered, wineModel, &WineModel::addRow);
    addAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_A));

    QAction *deleteAction = new QAction ("Delete Rows");
    connect (deleteAction, &QAction::triggered, this, &MainWindow::deleteRows);
    deleteAction->setShortcut(QKeySequence(Qt::Key_Delete));

    editMenu->addAction (addAction);
    editMenu->addAction (deleteAction);

    auto helpMenu = menuBar ()->addMenu ("Help");

    QAction *aboutAction = new QAction ("Abоut");
    connect (aboutAction, &QAction::triggered, this, &MainWindow::aboutFunction);
    helpMenu->addAction (aboutAction);

    aboutWindow = new QWidget();
    renderAboutWindow();

    QAction *getHelpAction = new QAction ("Get Help");
    connect (getHelpAction, &QAction::triggered, this, &MainWindow::getHelpFunction);
    helpMenu->addAction (getHelpAction);


}

void MainWindow::deleteRows ()
{
    std::unordered_set<size_t> rowsToDelete;
    for (const auto &row_index : modelView->selectionModel()->selectedRows())
        rowsToDelete.insert (row_index.row());
    if (rowsToDelete.size ())
        wineModel->deleteRows (rowsToDelete);
}


void MainWindow::loadDataFunction ()
{
    auto dir = QFileDialog::getOpenFileName (this, "Open File", QDir::currentPath ());
    if (!dir.size ())
        return;
    auto data = loadData (dir);
    wineModel->setData (data);
}

void MainWindow::saveDataFunction ()
{
    auto dir = QFileDialog::getSaveFileName (this, "Save File As", QDir::currentPath ());
    if (!dir.size ())
        return;
    saveData (dir);
}

void MainWindow::aboutFunction ()
{
    if (!aboutWindow)
    {
        aboutWindow = new QWidget();
        renderAboutWindow();
    }
    aboutWindow->show();
}

void MainWindow::getHelpFunction()
{}

void MainWindow::filterData ()
{
    filterModel->invalidate();
}

void MainWindow::showCartButtonFunction()
{
    if (!cartWindow)
        cartWindow = new CartWindow();
    if (!wineModel->modelData.empty())
    {
        for (const auto &row_index : modelView->selectionModel()->selectedRows())
        {
            cartWindow->addToCart(wineModel->modelData[row_index.row()]);
        }
    }
    cartWindow->show();
}

std::vector<Wine> MainWindow::loadData (const QString& dir)
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
}

void MainWindow::saveData (const QString& dir)
{
    std::ofstream file (dir.toStdString ());
    int totalColumns = static_cast<int> (wineFields::COUNT);

    file << wineModel->headers << '\n';
    for (auto& wine : wineModel->modelData)
    {
        for (int ithColumn = 0; ithColumn < totalColumns; ++ithColumn)
        {

            file << wine.data[ithColumn].toString().toStdString();
            if (ithColumn < totalColumns - 1)
                file << ",";
            else
                file << "\n";
        }
    }
}


MainWindow::~MainWindow()
{}

void MainWindow::renderAboutWindow()
{
    QGridLayout *aboutWindowLayout = new QGridLayout(aboutWindow);

    LogoWidget* aboutLogo = new LogoWidget (aboutWindow);
    aboutLogo->setFixedSize(300, 300);

    QHBoxLayout *aboutLogoLayout = new QHBoxLayout(aboutWindow);
    aboutWindowLayout->addLayout (aboutLogoLayout, 0, 0);
    aboutLogoLayout->addWidget (aboutLogo);

    aboutWindowLayout->addWidget(new QLabel("Student № 118"), 1, 0);
}

void MainWindow::checkBoxFunction(int state)
{
    if (state == 0)
        filterModel->sortByPoints = false;
    else
    {
        filterModel->sortByPoints = true;
        filterModel->sort((int)wineFields::points, Qt::DescendingOrder);
    }
}
