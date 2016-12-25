#include "death.h"
#include "ui_death.h"

Death::Death(QList<PokeMon *> mons, QWidget *parent) :
    QDialog(parent),   monsters(mons),
    ui(new Ui::Death)
{
    ui->setupUi(this);
    QIcon icon(QPixmap(":/new/prefix1/image/leave.png"));
    setWindowIcon(icon);
    this->show();
    setWindowTitle("Pick one to death!");
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    setWindowModality(Qt::WindowModal);
    for(auto mon:mons)
    {
        ui->comboBox_mons->addItem(mon->name);
    }
}

Death::~Death()
{
    delete ui;
}

int Death::value()
{
    return id;
}

void Death::on_pushButton_OK_clicked()
{
    int index=ui->comboBox_mons->currentIndex();
    id=monsters[index]->id;

    this->accept();
}