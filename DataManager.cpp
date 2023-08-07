#include "DataManager.h"

DataManager::DataManager(QWidget* parent)
    :   parentWidget(parent),
        DATA_FILE("data.csv"),
    HEADER_LABEL_LIST({ "Tên bộ VST", "Ghi chú" })
{
    loadData();
}

QList<DataInRow> DataManager::getDataInRowList() const
{
    return dataInRowList;
}

QStringList DataManager::getHeaderLabelList() const
{
    return HEADER_LABEL_LIST;
}

void DataManager::loadData()
{
    QFile dataFile(DATA_FILE);

    if (!dataFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(parentWidget, QObject::tr("Lỗi"), QObject::tr("Không thể đọc dữ liệu!"));
        return;
    }

    QTextStream inp(&dataFile);
    while(!inp.atEnd()) {
        QString line = inp.readLine();
        line = line.trimmed();

        QStringList rawData = line.split(";");

        dataInRowList << DataInRow(rawData);
    }
}
