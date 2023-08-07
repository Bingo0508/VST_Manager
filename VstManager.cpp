#include "VstManager.h"

VstManager::VstManager()
    :   dataManager()
{
    createModel();

    createCentralWidget();

    setWindowIcon(QIcon(":images/vst"));
    setWindowTitle(tr("Trình quản lý VST"));
}

void VstManager::createCentralWidget()
{
    QWidget *centralWidget = new QWidget(this);

    searchBar = new QLineEdit(centralWidget);
    searchResult = new QTreeView(centralWidget);
    searchResult->setRootIsDecorated(false);
    searchResult->setModel(model);

    QVBoxLayout *centralLayout = new QVBoxLayout();
    centralLayout->addWidget(searchBar);
    centralLayout->addWidget(searchResult);

    centralWidget->setLayout(centralLayout);

    setCentralWidget(centralWidget);
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
