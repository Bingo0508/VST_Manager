#include "VstManager.h"

VstManager::VstManager()
    :   dataManager()
{
    createModel();

    createCentralWidget();

    setWindowIcon(QIcon(":images/vst"));
    setWindowTitle(tr("Trình quản lý VST"));
}

void VstManager::search(QString keyword)
{
    if(keyword.isEmpty()) {
        searchResult->setModel(model);
        return;
    }

    QStandardItemModel *searchData = new QStandardItemModel();
    searchData->setHorizontalHeaderLabels(dataManager.getHeaderLabelList());

    foreach(DataInRow row, dataManager.getDataInRowList()) {
        const quint8 VST_NAME_INDEX = 0;
        const quint8 NOTE_INDEX = 1;

        QString vstName = row.data[VST_NAME_INDEX]->text();
        QString note = row.data[NOTE_INDEX]->text();

        bool vstNameContainKeyword = vstName.contains(keyword, Qt::CaseInsensitive);
        bool noteContainKeyword = note.contains(keyword, Qt::CaseInsensitive);

        if(vstNameContainKeyword || noteContainKeyword) {
            // !IMPORTANT: Must clone the row before appending it to the new
            // model because one QStandardItem is only set with one model at a time.
            DataInRow rowCloned(row);

            searchData->appendRow(rowCloned.data);
        }
    }

    searchResult->setModel(searchData);
}

void VstManager::createCentralWidget()
{
    QWidget *centralWidget = new QWidget(this);

    searchBar = new QLineEdit(centralWidget);
    searchResult = new QTreeView(centralWidget);
    searchResult->setRootIsDecorated(false);
    searchResult->setEditTriggers(QAbstractItemView::NoEditTriggers);
    searchResult->setModel(model);

    QVBoxLayout *centralLayout = new QVBoxLayout();
    centralLayout->addWidget(searchBar);
    centralLayout->addWidget(searchResult);

    centralWidget->setLayout(centralLayout);

    setCentralWidget(centralWidget);

    connect(searchBar, SIGNAL(textChanged(QString)), this, SLOT(typing(QString)));
}

void VstManager::createModel()
{
    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(dataManager.getHeaderLabelList());

    QList<DataInRow> dataInRowList = dataManager.getDataInRowList();
    foreach(DataInRow row, dataInRowList) {
        model->appendRow(row.data);
    }
}
