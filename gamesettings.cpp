#include "gamesettings.h"
#include "ui_gamesettings.h"
#include <QMessageBox>
#include "gamefield.h"

GameSettings::GameSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameSettings) {
    ui->setupUi(this);

    connect(ui->start, SIGNAL(clicked()),
            this, SLOT(start_pressed()));

    m_field = nullptr;

    ui->game_status->setText("игра не начата");
}

GameSettings::~GameSettings()
{
    delete ui;
}

void GameSettings::start_pressed() {
    if (m_field != nullptr)
        return;

    m_field = new GameField(10, 10);

    this->connect(m_field, SIGNAL(status(QString)),
                  SLOT(status_changed(QString)));

    connect(m_field, SIGNAL(closed()),
            this, SLOT(field_closed()));

    m_field->show();

    ui->game_status->setText("игра начата");
    ui->start->setEnabled(false);

    // ЗАДАЧИ к лекции 6:
    // 1) вместо Setting сделать меню с кнопками "играть" и "статистика" --сделано
    // 2) статистика считывается с файла.
    // 3) после победы запрашивать имя победителя и увеличивать счетчик в статистике
    // 4) после нажатия "играть" открывается поле 10 на 10
    // 5) после окончания игры открывается окно меню
    // 6) игра 5 в ряд
    // 7) попробовать написать хороший код,
}

void GameSettings::field_closed() {
    m_field = nullptr;

    ui->start->setEnabled(true);
}

void GameSettings::status_changed(QString status) {
    ui->game_status->setText(status);
}
