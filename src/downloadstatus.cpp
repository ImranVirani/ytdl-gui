#include "downloadstatus.h"
#include "ui_downloadstatus.h"
#include <QIcon>
#include <QCloseEvent>

downloadStatus::downloadStatus(QWidget *parent) :
    QDialog(parent),
    download_ui(new Ui::downloadStatus)
{
    download_ui->setupUi(this);
    this->setWindowTitle("Progress");
    this->setWindowIcon(QIcon::fromTheme("youtubedl-gui"));
}

downloadStatus::~downloadStatus()
{
    delete download_ui;
}

Ui::downloadStatus* downloadStatus::getUiInstance() {
    return this->download_ui;
}

void downloadStatus::closeEvent(QCloseEvent* event) {
    if (download_lock) {
        event->ignore();
    }

    else {
        event->accept();
    }
}
