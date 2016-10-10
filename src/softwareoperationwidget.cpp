/*
    软件升级和系统重启视图
*/
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "softwareoperationwidget.h"
#include "ui_softwareoperationwidget.h"

SoftwareOperationWidget::SoftwareOperationWidget(QWidget *parent, QRect rect) :
    QWidget(parent),
    ui(new Ui::SoftwareOperationWidget)
{
    ui->setupUi(this);

    this->setGeometry(rect.x()+1,  rect.y()+30, rect.width()-5,rect.height() -2);

    QPalette *p = new QPalette(COLOR_12);
    this->setPalette(*p);
    this->setAutoFillBackground(true);

    leShutDown = new LineEdit(ui->groupBox);
    leShutDown->setGeometry(ui->leShutDown_->geometry());
    leShutDown->setReadOnly(true);
    leShutDown->setText(ui->leShutDown_->text());
    leShutDown->setStyleSheet(ui->leShutDown_->styleSheet());
    leShutDown->setFont(ui->leShutDown_->font());

    leRestartThis = new LineEdit(ui->groupBox);
    leRestartThis->setGeometry(ui->leRestartThis_->geometry());
    leRestartThis->setReadOnly(true);
    leRestartThis->setText(ui->leRestartThis_->text());
    leRestartThis->setStyleSheet(ui->leRestartThis_->styleSheet());
    leRestartThis->setFont(ui->leRestartThis_->font());

    leUpgradeRemote = new LineEdit(ui->groupBox);
    leUpgradeRemote->setGeometry(ui->leUpgradeRemote_->geometry());
    leUpgradeRemote->setReadOnly(true);
    leUpgradeRemote->setText(ui->leUpgradeRemote_->text());
    leUpgradeRemote->setStyleSheet(ui->leUpgradeRemote_->styleSheet());
    leUpgradeRemote->setFont(ui->leUpgradeRemote_->font());

    leUpgradeRemoteStatus = new LineEdit(ui->groupBox);
    leUpgradeRemoteStatus->setGeometry(ui->leUpgradeRemoteStatus_->geometry());
    leUpgradeRemoteStatus->setReadOnly(true);
    leUpgradeRemoteStatus->setText(ui->leUpgradeRemoteStatus_->text());
    leUpgradeRemoteStatus->setStyleSheet(ui->leUpgradeRemoteStatus_->styleSheet());
    leUpgradeRemoteStatus->setFont(ui->leUpgradeRemoteStatus_->font());

    leClearFlash = new LineEdit(ui->groupBox_2);
    leClearFlash->setGeometry(ui->leClearFlash_->geometry());
    leClearFlash->setReadOnly(true);
    leClearFlash->setText(ui->leClearFlash_->text());
    leClearFlash->setStyleSheet(ui->leClearFlash_->styleSheet());
    leClearFlash->setFont(ui->leClearFlash_->font());

    leClearFlashStatus = new LineEdit(ui->groupBox_2);
    leClearFlashStatus->setGeometry(ui->leClearFlashStatus_->geometry());
    leClearFlashStatus->setReadOnly(true);
    leClearFlashStatus->setText(ui->leClearFlashStatus_->text());
    leClearFlashStatus->setStyleSheet(ui->leClearFlashStatus_->styleSheet());
    leClearFlashStatus->setFont(ui->leClearFlashStatus_->font());

    leUpgradeFlash = new LineEdit(ui->groupBox_2);
    leUpgradeFlash->setGeometry(ui->leUpgradeFlash_->geometry());
    leUpgradeFlash->setReadOnly(true);
    leUpgradeFlash->setText(ui->leUpgradeFlash_->text());
    leUpgradeFlash->setStyleSheet(ui->leUpgradeFlash_->styleSheet());
    leUpgradeFlash->setFont(ui->leUpgradeFlash_->font());

    leUpgadeFlashStatus = new LineEdit(ui->groupBox_2);
    leUpgadeFlashStatus->setGeometry(ui->leUpgadeFlashStatus_->geometry());
    leUpgadeFlashStatus->setReadOnly(true);
    leUpgadeFlashStatus->setText(ui->leUpgadeFlashStatus_->text());
    leUpgadeFlashStatus->setStyleSheet(ui->leUpgadeFlashStatus_->styleSheet());
    leUpgadeFlashStatus->setFont(ui->leUpgadeFlashStatus_->font());

    leRestartRemote= new LineEdit(ui->groupBox_2);
    leRestartRemote->setGeometry(ui->leRestartRemote_->geometry());
    leRestartRemote->setReadOnly(true);
    leRestartRemote->setText(ui->leRestartRemote_->text());
    leRestartRemote->setStyleSheet(ui->leRestartRemote_->styleSheet());
    leRestartRemote->setFont(ui->leRestartRemote_->font());

    leRestartRemoteStatus = new LineEdit(ui->groupBox_2);
    leRestartRemoteStatus->setGeometry(ui->leRestartRemoteStatus_->geometry());
    leRestartRemoteStatus->setReadOnly(true);
    leRestartRemoteStatus->setText(ui->leRestartRemoteStatus_->text());
    leRestartRemoteStatus->setStyleSheet(ui->leRestartRemoteStatus_->styleSheet());
    leRestartRemoteStatus->setFont(ui->leRestartRemoteStatus_->font());

    leStartedAsStatus = new LineEdit(ui->groupBox_2);
    leStartedAsStatus->setGeometry(ui->leStartedAsStatus_->geometry());
    leStartedAsStatus->setReadOnly(true);
    leStartedAsStatus->setText(ui->leStartedAsStatus_->text());
    leStartedAsStatus->setStyleSheet(ui->leStartedAsStatus_->styleSheet());
    leStartedAsStatus->setFont(ui->leStartedAsStatus_->font());

    leModeStatus = new LineEdit(ui->groupBox_2);
    leModeStatus->setGeometry(ui->leModeStatus_->geometry());
    leModeStatus->setReadOnly(true);
    leModeStatus->setText(ui->leModeStatus_->text());
    leModeStatus->setStyleSheet(ui->leModeStatus_->styleSheet());
    leModeStatus->setFont(ui->leModeStatus_->font());

    leFileVersionStatus = new LineEdit(ui->groupBox_2);
    leFileVersionStatus->setGeometry(ui->leFileVersionStatus_->geometry());
    leFileVersionStatus->setReadOnly(true);
    leFileVersionStatus->setText(ui->leFileVersionStatus_->text());
    leFileVersionStatus->setStyleSheet(ui->leFileVersionStatus_->styleSheet());
    leFileVersionStatus->setFont(ui->leFileVersionStatus_->font());

    connect(leShutDown,SIGNAL(clicked()),SLOT(shutDown()));
    connect(leRestartThis,SIGNAL(clicked()),SLOT(restartThis()));
    //connect(ui->pushButton,SIGNAL(clicked()),SLOT(test()));
}

SoftwareOperationWidget::~SoftwareOperationWidget()
{
    delete ui;
}

void SoftwareOperationWidget::shutDown()
{
    qDebug("QCoreApplication::exit(1);");
    QCoreApplication::exit(1);
}

void SoftwareOperationWidget::restartThis()
{
    qDebug("restart");

        qApp->quit();
      QProcess::startDetached(qApp->applicationFilePath(), QStringList());
}

/*

调整亮度 参数0-100
设置成功返回0
设置失败返回负数
*/
//int SoftwareOperationWidget::SetGamma(int bright)
//{
//        void * lpGamma = NULL;
//        int iArrayValue;
//        WORD gMap[3][256] = {0};
//        lpGamma = &gMap;
//        HDC hdc = ::GetDC(NULL);
//        if (NULL == hdc)
//                return -1;
//        for (int i = 0; i < 256; i++)
//        {
//                iArrayValue = i * (bright + 128);
//                if (iArrayValue > 65535)
//                        iArrayValue = 65535;
//                    gMap[0][i] =
//                        gMap[1][i] =
//                        gMap[2][i] = (WORD)iArrayValue;
//        }
////        if (FALSE == SetDeviceGammaRamp(hdc, lpGamma))
////                return -2;
//        return 0;



//}

//bool SoftwareOperationWidget::test()
//{
//     HANDLE hToken;
//     TOKEN_PRIVILEGES tkp;

//     //获取进程标志
//     if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
//          return false;

//     //获取关机特权的LUID
//     LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,&tkp.Privileges[0].Luid);
//     tkp.PrivilegeCount = 1;
//     tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

//     //获取这个进程的关机特权
//     AdjustTokenPrivileges(hToken, false, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
//     if (GetLastError() != ERROR_SUCCESS) return false;

//     // 强制关闭计算机
//     if ( !ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 0))
//           return false;
//     return true;
//}
