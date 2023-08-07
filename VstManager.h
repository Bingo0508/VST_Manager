#ifndef VSTMANAGER_H
#define VSTMANAGER_H

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

private:
    void createCentralWidget();

    QLineEdit *searchBar;
    QTreeView *searchResult;
};

#endif // VSTMANAGER_H
