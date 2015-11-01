#ifndef PATTERNBULLET_H
#define PATTERNBULLET_H


class PatternBullet
{
public:
    PatternBullet(double angle, double speed);

    void setAngle(double a);
    void setSpeed(double s);

    double getAngle();
    double getSpeed();

private:
    double angle; //Degrés
    double speed;
};

#endif // PATTERNBULLET_H
