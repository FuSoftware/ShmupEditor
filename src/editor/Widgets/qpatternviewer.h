#ifndef QPATTERNVIEWER_H
#define QPATTERNVIEWER_H

#include "qsfmlcanvas.h"

#include "constantes.h"

class QPatternViewer : public QSFMLCanvas
{
public:
    QPatternViewer(QWidget* Parent, const QPoint& Position, const QSize& Size);
    ~QPatternViewer();
    void OnInit();
    void OnUpdate();
};

#endif // QPATTERNVIEWER_H
