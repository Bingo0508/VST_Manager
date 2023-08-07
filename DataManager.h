#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QString>
#include <QList>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QMessageBox>
#include <QWidget>
#include <QObject>
#include <QStringList>

struct Data
{
    Data(const QString& vstName, const QString& note);
    QString vstName;
    QString note;
};

class DataManager
{
public:
    DataManager(QWidget* parent = nullptr);

    Data header() const;
    Data dataAt(const quint32 index) const;

private:
    void loadData();

    QList<Data> data;
    QWidget *parentWidget;

    const QString DATA_FILE;
};

#endif // DATAMANAGER_H
