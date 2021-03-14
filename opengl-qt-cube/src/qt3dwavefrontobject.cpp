#include "qt3dwavefrontobject.h"
#include "util.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>

Qt3dWavefrontObject::Qt3dWavefrontObject()
{
}

void Qt3dWavefrontObject::loadFromFile(const QString &filename)
{
    QFile F(filename);
    if (F.open(QIODevice::Text | QIODevice::ReadOnly))
    {
        QChar v;
        float x, y, z;
        float xmax = std::numeric_limits<float>::min();
        float ymax = std::numeric_limits<float>::min();
        float zmax = std::numeric_limits<float>::min();        
        float xmin = std::numeric_limits<float>::max();
        float ymin = std::numeric_limits<float>::max();
        float zmin = std::numeric_limits<float>::max();
        QTextStream xin(&F);
        while (!xin.atEnd())
        {
            QString line = xin.readLine();
            QTextStream sin(&line);
            sin >> v >> x >> y >> z;
            if (v == "v")
            {
                mVertices.append(QVector3D(x, y, z));

                // calculando xmax, ymax, zmax
                if (x > xmax)
                {
                    xmax = x;
                }
                if (y > ymax)
                {
                    ymax = y;
                }
                if (z > zmax)
                {
                    zmax = z;
                }

                // calculando xmin, ymin, zmin
                if (x < xmin)
                {
                    xmin = x;
                }
                if (y < ymin)
                {
                    ymin = y;
                }
                if (z < zmin)
                {
                    zmin = z;
                }
            }
        }
        F.close();
        const int nVertices = mVertices.size();
        for (int i = 0; i < nVertices; ++i)
        {
            mVertices[i].setX(Util::normalize_between_minus1_plus1(mVertices[i].x(), xmax, xmin));
            mVertices[i].setY(Util::normalize_between_minus1_plus1(mVertices[i].y(), ymax, ymin));
            mVertices[i].setZ(Util::normalize_between_minus1_plus1(mVertices[i].z(), zmax, zmin));
        }
    }
}

void Qt3dWavefrontObject::display(const QColor &color)
{
    const int nVertices = mVertices.size();
    glBegin(GL_POINTS);
    glColor3f(color.redF(), color.greenF(), color.blueF());
    for (int i = 0; i < nVertices; ++i)
    {
        glVertex3f(mVertices[i].x(), mVertices[i].y(), mVertices[i].z());
    }
    glEnd();
}
