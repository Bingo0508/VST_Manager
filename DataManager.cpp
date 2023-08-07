#include "DataManager.h"

DataManager::DataManager(QWidget* parent)
    :   parentWidget(parent),
        DATA_FILE("data.csv")
{
    loadData();
}

Data DataManager::header() const
{
    const quint8 HEADER_INDEX = 0; // The first line of data is the header
    return data[HEADER_INDEX];
}

Data DataManager::dataAt(const quint32 index) const
{
    return data[index];
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
        QStringList rawData = line.split(";");

        const quint8 VST_NAME_INDEX = 0;
        const quint8 NOTE_INDEX = 1;
        data << Data(rawData[VST_NAME_INDEX], rawData[NOTE_INDEX]);
    }
}
