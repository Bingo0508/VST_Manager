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
#include <QStandardItem>

struct DataInRow
{
    DataInRow(const QStringList& rawData) {
        const quint8 VST_NAME_INDEX = 0;
        const quint8 NOTE_INDEX = 1;
        QStandardItem *vstName = new QStandardItem(rawData[VST_NAME_INDEX]);
        QStandardItem *note = new QStandardItem(rawData[NOTE_INDEX]);
        data << vstName;
        data << note;
    }

    QList<QStandardItem*> data;
};

class DataManager
{
public:
    DataManager(QWidget* parent = nullptr);

    QList<DataInRow> getDataInRowList() const;
    QStringList getHeaderLabelList() const;

private:
    void loadData();

    QWidget *parentWidget;

    QList<DataInRow> dataInRowList;

    const QString DATA_FILE;
    const QStringList HEADER_LABEL_LIST;
};

#endif // DATAMANAGER_H
