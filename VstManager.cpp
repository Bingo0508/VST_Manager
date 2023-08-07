#include "VstManager.h"

VstManager::VstManager()
{
    createCentralWidget();

    setWindowIcon(QIcon(":images/vst"));
    setWindowTitle(tr("Trình quản lý VST"));
}

void VstManager::createCentralWidget()
{
    QWidget *centralWidget = new QWidget(this);

    searchBar = new QLineEdit(centralWidget);
    searchResult = new QTreeView(centralWidget);

    QVBoxLayout *centralLayout = new QVBoxLayout();
    centralLayout->addWidget(searchBar);
    centralLayout->addWidget(searchResult);

    centralWidget->setLayout(centralLayout);

    setCentralWidget(centralWidget);
}
