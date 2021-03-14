#ifndef QT3DWAVEFRONTOBJECT_H
#define QT3DWAVEFRONTOBJECT_H

#include <QList>
#include <QColor>
#include <QString>
#include <QVector3D>

class Qt3dWavefrontObject
{
public:
    Qt3dWavefrontObject();

    void loadFromFile(const QString &filename);

    void display(const QColor &color = Qt::white);

    const QList<QVector3D> &vertices() const
    {
        return mVertices;
    }
private:
    QList<QVector3D> mVertices;
};

#endif // QT3DWAVEFRONTOBJECT_H
