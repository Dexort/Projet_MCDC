/**
 * \file mainwindow.h
 * \brief Fichier de déclaration de la classe mainwindow.
 * \author Sébastien Angibaud
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "niveau.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

/** -----------------------------------------------------------
    * \Class MainWindow
    * \Brief Déclaration de la classe MainWindow représentant la fenêtre principale.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void demarrer();

protected:
    void keyReleaseEvent(QKeyEvent *event);

private slots:
    void on_pushButtonExemple_clicked();
    void on_pushButtonRejouer_clicked();    // <-- AJOUT

private:
    Ui::MainWindow *m_ui;
    Niveau m_exemple;
};

#endif // MAINWINDOW_H
