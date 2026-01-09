/**
 * \file partie.h
 * \brief Fichier de déclaration de la classe partie.
 * \author Sébastien Angibaud
 */

#ifndef EXEMPLE_H
#define EXEMPLE_H
#include "defines.h"

#include <QGraphicsScene>
#include <QPoint>
#include <QTimer>
#include <QProgressBar>

/** -----------------------------------------------------------
    * \Class Niveau
    * \Brief Déclaration de la classe Exemple représentant une partie. Celle-ci est composée de plusieurs niveaux.
*/
class Niveau
{
    enum typeCase{VIDE, MUR};

public:
    // Constructeur
    Niveau();
    ~Niveau();

    void reset();

    void allerADroite();
    void allerAGauche();
    void allerEnHaut();
    void allerEnBas();
    void attaquer();
    void monstresAttaquent();
    void dessinerExemple(QGraphicsScene * scene) const;
    // Affichage
    void dessinerGrille(QGraphicsScene * scene) const;
    void dessinerCase(QGraphicsScene * scene, int x, int y) const;
    void dessinerImage(QGraphicsScene * scene, int x, int y, QString filename) const;
    bool estMort() const { return pvJoueur <= 0; }
    bool tousLesMonstresSontMorts() const {
        return pvMonstre1 <= 0 && pvMonstre2 <= 0 && pvMonstre3 <= 0 && pvMonstre4 <= 0;
    }
    bool estVictoire() const {
        return m_position == QPoint(12, 12);
    }
    void setBar(QProgressBar *newBar);

private:
    // Déclaration des variables membres

    int pvMonstre1 = 100;   // points de vie du monstre
    int pvMonstre2 = 100;
    int pvMonstre3 = 100;
    int pvMonstre4 = 100;
    int degatsJoueur = 20; // dégâts du joueur
    int pvJoueur = 100;   // points de vie du joueur
    int degatsMonstre = 5; // dégâts infligés par un monstre
    int niveauActuel = 1; // commence au niveau 1



    /** \brief Une position pour donner un exemple. */
    QPoint m_position;
    QPoint m_position_ennemi1;
    QPoint m_position_ennemi2;
    QPoint m_position_ennemi3;
    QPoint m_position_ennemi4;

    QTimer* timerAttaque = nullptr; // timer pour attaques auto
    QProgressBar * m_bar;

    bool caseOccupeeParMonstre(int x, int y) const {
        if (pvMonstre1 > 0 && m_position_ennemi1 == QPoint(x,y)) return true;
        if (pvMonstre2 > 0 && m_position_ennemi2 == QPoint(x,y)) return true;
        if (pvMonstre3 > 0 && m_position_ennemi3 == QPoint(x,y)) return true;
        if (pvMonstre4 > 0 && m_position_ennemi4 == QPoint(x,y)) return true;
        return false;
    }


    typeCase m_grille[NB_COLONNES_X][NB_LIGNES_Y];
};

#endif // EXEMPLE_H
