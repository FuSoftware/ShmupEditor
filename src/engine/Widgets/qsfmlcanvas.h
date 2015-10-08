#ifndef QSFMLCANVAS_H
#define QSFMLCANVAS_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <QtWidgets>

class QSFMLCanvas : public QWidget
{
    Q_OBJECT
public :

    QSFMLCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime = 0);
    virtual ~QSFMLCanvas();

    sf::RenderWindow *getRenderWindow();

private :

    virtual void OnInit();
    virtual void OnUpdate();
    virtual QPaintEngine* paintEngine() const;
    virtual void showEvent(QShowEvent*);
    virtual void paintEvent(QPaintEvent*);

    QTimer myTimer;
    bool   myInitialized;

protected:
    sf::RenderWindow *renderWindow;
};

#endif // QSFMLCANVAS_H
