/**
 * \file mainwindow.cpp
 * \brief Fichier d'implémentation de la classe mainwindow.
 * \author Sébastien Angibaud
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QSettings>
#include <iostream>
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    setFocusPolicy(Qt::StrongFocus);
    this->grabKeyboard();

    m_ui->setupUi(this);

    m_ui->pushButtonExemple->setText( "X" );

    QGraphicsScene* scene = new QGraphicsScene();
    m_ui->graphicsView->setScene(scene);
    m_exemple.setBar(m_ui ->progressBar_joueur);

    // AJOUT : bouton Rejouer caché au départ
    m_ui->pushButtonRejouer->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::demarrer()
{
    //m_exemple.dessinerExemple(m_ui->graphicsView->scene());
    m_exemple.dessinerGrille( m_ui->graphicsView->scene() );
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Right:
        m_exemple.allerADroite();
        break;
    case Qt::Key_Left:
        m_exemple.allerAGauche();
        break;
    case Qt::Key_Up:
        m_exemple.allerEnHaut();
        break;
    case Qt::Key_Down:
        m_exemple.allerEnBas();
        break;
    case Qt::Key_Space:
        m_exemple.attaquer();
        break;
    }

    m_ui->graphicsView->scene()->clear();
    m_exemple.dessinerGrille(m_ui->graphicsView->scene());

    // AJOUT : si le joueur est mort OU si tous les monstres sont morts → bouton Rejouer visible
    if (m_exemple.estMort() || m_exemple.tousLesMonstresSontMorts()) {
        m_ui->pushButtonRejouer->setVisible(true);
    }
    // Vérifie si le joueur est sur la case finale
    if (m_exemple.estVictoire()) {
        QMessageBox::information(this, "Victoire", "GG !");
        m_ui->pushButtonRejouer->setVisible(true);
    }
    else if (m_exemple.estMort()) {
        QMessageBox::information(this, "Défaite", "Tu es mort !");
        m_ui->pushButtonRejouer->setVisible(true);
    }
    else if (m_exemple.tousLesMonstresSontMorts()) {
        m_ui->pushButtonRejouer->setVisible(true);
    }

}

void MainWindow::on_pushButtonExemple_clicked()
{
    m_exemple.reset();
    m_ui->graphicsView->scene()->clear();
    m_exemple.dessinerGrille(m_ui->graphicsView->scene());
}

void MainWindow::on_pushButtonRejouer_clicked()
{
    m_exemple.reset();
    m_ui->graphicsView->scene()->clear();
    m_exemple.dessinerGrille(m_ui->graphicsView->scene());
    m_ui->pushButtonRejouer->setVisible(false);
}
