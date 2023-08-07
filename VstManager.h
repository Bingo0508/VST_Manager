#ifndef VSTMANAGER_H
#define VSTMANAGER_H

#include "DataManager.h"
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTreeView>
#include <QString>
#include <QStringList>
#include <QIcon>

class VstManager : public QMainWindow
{
    Q_OBJECT
public:
    VstManager();

private slots:
    void typing(const QString& keyword);

private:
    void createCentralWidget();
    void createModel();

    DataManager dataManager;
    QLineEdit *searchBar;
    QTreeView *searchResult;
    QStandardItemModel *model;
};

#endif // VSTMANAGER_H
