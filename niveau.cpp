/**
 * \file partie.cpp
 * \brief Fichier d'implémentation de la classe partie.
 * \author Sébastien Angibaud
 */

#include "niveau.h"

#include "utilitaire.h"

#include <QFile>
#include <QGraphicsPixmapItem>
#include <QImage>

/** -----------------------------------------------------------
    * \Brief Constructeur par défaut de la classe Exemple.
*/
Niveau::Niveau()
{
    m_position.setX( 3 );
    m_position.setY( 0 );
    m_position_ennemi1.setX(6);
    m_position_ennemi1.setY(7);
    m_position_ennemi2.setX(5);
    m_position_ennemi2.setY(11);
    m_position_ennemi3.setX(10);
    m_position_ennemi3.setY(5);
    m_position_ennemi4.setX(15);
    m_position_ennemi4.setY(8);


    // --- Attaques automatiques toutes les 0.5 s sans QObject parent ---
    timerAttaque = new QTimer; // pas de 'this' ici
    QObject::connect(timerAttaque, &QTimer::timeout, [this]() {
        this->monstresAttaquent();
    });
    timerAttaque->start(500);

    for ( int x = 0 ; x != 20; x++ )
        for ( int y = 0; y != 20; y++ )
            m_grille[x][y] = MUR;

    m_grille[3][0] = VIDE;
    m_grille[3][1] = VIDE;
    m_grille[3][2] = VIDE;
    m_grille[3][3] = VIDE;
    m_grille[3][4] = VIDE;
    m_grille[3][5] = VIDE;
    m_grille[4][5] = VIDE;
    m_grille[5][5] = VIDE;
    m_grille[6][5] = VIDE;
    m_grille[6][6] = VIDE;
    m_grille[6][7] = VIDE;
    m_grille[6][8] = VIDE;
    m_grille[5][8] = VIDE;
    m_grille[4][8] = VIDE;
    m_grille[3][8] = VIDE;
    m_grille[3][9] = VIDE;
    m_grille[3][10] = VIDE;
    m_grille[3][11] = VIDE;
    m_grille[4][11] = VIDE;
    m_grille[5][11] = VIDE;
    m_grille[6][11] = VIDE;
    m_grille[7][11] = VIDE;
    m_grille[8][11] = VIDE;
    m_grille[8][10] = VIDE;
    m_grille[8][9] = VIDE;
    m_grille[8][8] = VIDE;
    m_grille[9][8] = VIDE;
    m_grille[9][7] = VIDE;
    m_grille[9][6] = VIDE;
    m_grille[9][5] = VIDE;
    m_grille[10][5] = VIDE;
    m_grille[11][5] = VIDE;
    m_grille[11][4] = VIDE;
    m_grille[11][3] = VIDE;
    m_grille[12][3] = VIDE;
    m_grille[13][3] = VIDE;
    m_grille[13][4] = VIDE;
    m_grille[13][5] = VIDE;
    m_grille[13][6] = VIDE;
    m_grille[14][6] = VIDE;
    m_grille[15][6] = VIDE;
    m_grille[15][7] = VIDE;
    m_grille[15][8] = VIDE;
    m_grille[15][9] = VIDE;
    m_grille[14][9] = VIDE;
    m_grille[13][9] = VIDE;
    m_grille[12][9] = VIDE;
    m_grille[12][10] = VIDE;
    m_grille[12][11] = VIDE;
    m_grille[12][12] = VIDE;
    m_grille[12][13] = VIDE;
    m_grille[12][14] = VIDE;










}



/** -----------------------------------------------------------
    * \Brief Dessine le niveau dans la scene donnée en paramètre.
    * \param scene Un pointeur sur l'objet QGraphicsScene dans lequel dessiner.
*/
void Niveau::dessinerGrille( QGraphicsScene * scene ) const
{
    for ( unsigned int x = 0; x < NB_COLONNES_X; ++x )
        for ( unsigned int y = 0; y < NB_LIGNES_Y; ++y )
            dessinerCase(scene, x, y);

    dessinerImage(scene, m_position.x(), m_position.y(), Utilitaire::relativeFileName("images/personnage.png"));
    dessinerImage(scene,  m_position_ennemi1.x(),  m_position_ennemi1.y(), Utilitaire::relativeFileName("images/monstre.png"));
    dessinerImage(scene,  m_position_ennemi2.x(),  m_position_ennemi2.y(), Utilitaire::relativeFileName("images/monstre.png"));
    dessinerImage(scene,  m_position_ennemi3.x(),  m_position_ennemi3.y(), Utilitaire::relativeFileName("images/monstre.png"));
    dessinerImage(scene,  m_position_ennemi4.x(),  m_position_ennemi4.y(), Utilitaire::relativeFileName("images/monstre.png"));



}
/** -----------------------------------------------------------
    * \Brief Dessine une case du niveau dans la scene donnée en paramètre.
    * \param scene Un pointeur sur l'objet QGraphicsScene dans lequel dessiner.
    * \param x La coordonnée x de la case à dessiner.
    * \param y La coordonnée y de la case à dessiner.
*/
void Niveau::dessinerCase(QGraphicsScene * scene, int x, int y) const
{
    switch ( m_grille[x][y] ) {
    case VIDE:
        dessinerImage(scene, x, y, Utilitaire::relativeFileName("images/vide.png"));
        break;
    case MUR:
        dessinerImage(scene, x, y, Utilitaire::relativeFileName("images/mur.png"));
        break;

    }
}

/** -----------------------------------------------------------
    * \Brief Dessine une image dans la scene donnée en paramètre.
    * \param scene Un pointeur sur l'objet QGraphicsScene dans lequel dessiner.
    * \param x La coordonnée x de la case à dessiner.
    * \param y La coordonnée y de la case à dessiner.
*/
void Niveau::dessinerImage(QGraphicsScene * scene, int x, int y, QString filename) const
{
    QImage image(filename);
    QGraphicsPixmapItem *pixmap = scene->addPixmap(QPixmap::fromImage(image));
    pixmap->setOffset(x*NB_PIXELS_CASE, y*NB_PIXELS_CASE);
}

void Niveau::setBar(QProgressBar *newBar)
{
    m_bar = newBar;
}

/** -----------------------------------------------------------
    * \Brief Destructeur de la classe Exemple.
*/
Niveau::~Niveau()
{

}

/** -----------------------------------------------------------
    * \Brief Réinitialise l'Exemple.
*/
void Niveau::reset()
{
    // Réinitialiser la position du joueur
    m_position.setX(3);
    m_position.setY(0);

    // Réinitialiser les PV
    pvJoueur = 100;
    pvMonstre1 = 100;
    pvMonstre2 = 100;
    pvMonstre3 = 100;
    pvMonstre4 = 100;

    // Réinitialiser les positions des monstres
    m_position_ennemi1 = QPoint(6,7);
    m_position_ennemi2 = QPoint(5,11);
    m_position_ennemi3 = QPoint(10,5);
    m_position_ennemi4 = QPoint(15,8);

    // Redémarrer le timer si besoin
    if (timerAttaque && !timerAttaque->isActive())
        timerAttaque->start(500);
}

void Niveau::allerADroite() {
    int nx = m_position.x() + 1;
    int ny = m_position.y();
    if (nx >= 0 && nx < NB_COLONNES_X && ny >= 0 && ny < NB_LIGNES_Y
        && m_grille[nx][ny] == VIDE
        && !caseOccupeeParMonstre(nx, ny))   // <-- empêche de traverser un monstre vivant
    {
        m_position.setX(nx);
    }
}

void Niveau::allerAGauche() {
    int nx = m_position.x() - 1;
    int ny = m_position.y();
    if (nx >= 0 && nx < NB_COLONNES_X && ny >= 0 && ny < NB_LIGNES_Y
        && m_grille[nx][ny] == VIDE
        && !caseOccupeeParMonstre(nx, ny))   // <-- empêche de traverser un monstre vivant
    {
        m_position.setX(nx);
    }
}

void Niveau::allerEnHaut() {
    int nx = m_position.x();
    int ny = m_position.y() - 1;
    if (nx >= 0 && nx < NB_COLONNES_X && ny >= 0 && ny < NB_LIGNES_Y
        && m_grille[nx][ny] == VIDE
        && !caseOccupeeParMonstre(nx, ny))   // <-- empêche de traverser un monstre vivant
    {
        m_position.setY(ny);
    }
}

void Niveau::allerEnBas() {
    int nx = m_position.x();
    int ny = m_position.y() + 1;
    if (nx >= 0 && nx < NB_COLONNES_X && ny >= 0 && ny < NB_LIGNES_Y
        && m_grille[nx][ny] == VIDE
        && !caseOccupeeParMonstre(nx, ny))   // <-- empêche de traverser un monstre vivant
    {
        m_position.setY(ny);
    }
}

/**------------------------------------------------------------
    *\Brief Dessine une image pour l'exemple dans la scene donnée en paramètre.
    * \param scene Un pointeur sur l'objet QGraphicsScene dans lequel dessiner.
*/
void Niveau::dessinerExemple( QGraphicsScene * scene ) const
{
    QString fileName = Utilitaire::relativeFileName("images/personnage.png");
    QImage image(fileName);
    QGraphicsPixmapItem *pixmap = scene->addPixmap(QPixmap::fromImage(image));
    pixmap->setOffset(m_position.x(), m_position.y());


}
void Niveau::attaquer() {
    // Vérifie si le joueur est à côté du monstre
    int dx1 = abs(m_position.x() - m_position_ennemi1.x());
    int dy1 = abs(m_position.y() - m_position_ennemi1.y());
    int dx2 = abs(m_position.x() - m_position_ennemi2.x());
    int dy2 = abs(m_position.y() - m_position_ennemi2.y());
    int dx3 = abs(m_position.x() - m_position_ennemi3.x());
    int dy3 = abs(m_position.y() - m_position_ennemi3.y());
    int dx4 = abs(m_position.x() - m_position_ennemi4.x());
    int dy4 = abs(m_position.y() - m_position_ennemi4.y());


    if (dx1 <= 1 && dy1 <= 1 && pvMonstre1 > 0) {
        pvMonstre1 -= degatsJoueur;
        qDebug() << "Vous attaquez le monstre ! PV restants :" << pvMonstre1;

        // Si le monstre est mort
        if (pvMonstre1 <= 0) {
            qDebug() << "Le monstre est vaincu !";
            m_position_ennemi1 = QPoint(-1,-1); // le monstre disparaît


        }
    }
    if (dx2 <= 1 && dy2 <= 1 && pvMonstre2 > 0) {
        pvMonstre2 -= degatsJoueur;
        qDebug() << "Vous attaquez le monstre ! PV restants :" << pvMonstre2;

        // Si le monstre est mort
        if (pvMonstre2 <= 0) {
            qDebug() << "Le monstre est vaincu !";
            m_position_ennemi2 = QPoint(-1,-1); // le monstre disparaît


        }
    }
    if (dx3 <= 1 && dy3 <= 1 && pvMonstre3 > 0) {
        pvMonstre3 -= degatsJoueur;
        qDebug() << "Vous attaquez le monstre ! PV restants :" << pvMonstre3;

        // Si le monstre est mort
        if (pvMonstre3 <= 0) {
            qDebug() << "Le monstre est vaincu !";
            m_position_ennemi3 = QPoint(-1,-1); // le monstre disparaît


        }
    }
    if (dx4 <= 1 && dy4 <= 1 && pvMonstre4 > 0) {
        pvMonstre4 -= degatsJoueur;
        qDebug() << "Vous attaquez le monstre ! PV restants :" << pvMonstre4;

        // Si le monstre est mort
        if (pvMonstre4 <= 0) {
            qDebug() << "Le monstre est vaincu !";
            m_position_ennemi4 = QPoint(-1,-1); // le monstre disparaît


        }

    }
}
void Niveau::monstresAttaquent() {
    // Monstre 1
    if (abs(m_position.x() - m_position_ennemi1.x()) <= 1 &&
        abs(m_position.y() - m_position_ennemi1.y()) <= 1 &&
        pvMonstre1 > 0) {
        pvJoueur -= degatsMonstre;
        qDebug() << "Le monstre 1 vous attaque ! PV Joueur :" << pvJoueur;
        if (pvJoueur <= 0) {
            qDebug() << "Vous êtes vaincu !";
            m_position = QPoint(-1,-1);
        }
    }

    // Monstre 2
    if (abs(m_position.x() - m_position_ennemi2.x()) <= 1 &&
        abs(m_position.y() - m_position_ennemi2.y()) <= 1 &&
        pvMonstre2 > 0) {
        pvJoueur -= degatsMonstre;
        qDebug() << "Le monstre 2 vous attaque ! PV Joueur :" << pvJoueur;
        if (pvJoueur <= 0) {
            qDebug() << "Vous êtes vaincu !";
            m_position = QPoint(-1,-1);
        }
    }

    // Monstre 3
    if (abs(m_position.x() - m_position_ennemi3.x()) <= 1 &&
        abs(m_position.y() - m_position_ennemi3.y()) <= 1 &&
        pvMonstre3 > 0) {
        pvJoueur -= degatsMonstre;
        qDebug() << "Le monstre 3 vous attaque ! PV Joueur :" << pvJoueur;
        if (pvJoueur <= 0) {
            qDebug() << "Vous êtes vaincu !";
            m_position = QPoint(-1,-1);
        }
    }

    // Monstre 4
    if (abs(m_position.x() - m_position_ennemi4.x()) <= 1 &&
        abs(m_position.y() - m_position_ennemi4.y()) <= 1 &&
        pvMonstre4 > 0) {
        pvJoueur -= degatsMonstre;
        qDebug() << "Le monstre 4 vous attaque ! PV Joueur :" << pvJoueur;
        if (pvJoueur <= 0) {
            qDebug() << "Vous êtes vaincu !";
            m_position = QPoint(-1,-1);
        }
    }

    m_bar ->setValue(pvJoueur);
}
