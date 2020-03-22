#include "singleitemwidget.h"
#include "ui_singleitemwidget.h"

SingleItemWidget::SingleItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingleItemWidget)
{
    ui->setupUi(this);

    SingleItem_init();
    SingleItem_conn();
}

SingleItemWidget::~SingleItemWidget()
{
    delete ui;
}



void SingleItemWidget::SingleItem_conn()
{
    connect(ui->toolButtonDel,SIGNAL(clicked()),this,SLOT(clickDelBtn()));
}


/****************Slots*******************/

void SingleItemWidget::clickDelBtn()
{
    qDebug() << "child  click del";
    emit childDelEvent();
}

void SingleItemWidget::SingleItem_init()
{
    qDebug() << "";
//    //设置图片大小
//    ui->toolButtonDel->setIconSize(QSize(12,16));
//    ui->toolButtonLock->setIconSize(QSize(12,16));
    //文本框属性
    ui->textEdit_Item->setReadOnly(true);//只读
    //ui->textEdit_Item->setFocusPolicy(Qt::NoFocus);//无焦点
    ui->textEdit_ItemDate->setReadOnly(true);
    //按钮属性
    ui->toolButtonDel->setStyleSheet("QToolButton#toolButtonDel{image:url(:/new/prefix1/SVG/delete.svg);}"
                             "QToolButton#toolButtonDel:hover{image:url(:/new/prefix1/SVG/delete-hover.svg);}"
                             "QToolButton#toolButtonDel:pressed{image:url(:/new/prefix1/SVG/delete-click.svg);}");
}




