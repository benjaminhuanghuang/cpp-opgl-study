#ifndef QT3DOPENGLWIDGET_H
#define QT3DOPENGLWIDGET_H

#include "qt3dwavefrontobject.h"
#include <OpenGL/gl.h>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class QTimer;
class Qt3dWavefrontObject;

class Qt3dOpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    Qt3dOpenGLWidget(QWidget *parent = nullptr);
    ~Qt3dOpenGLWidget();

    void set3dObject(Qt3dWavefrontObject *object)
    {
        mObject = object;
    }

    void setMode(int mode)
    {
        mMode = mode;
    }

    void set_xScale(float scale)
    {
        m_xScale = scale;
    }

    void set_yScale(float scale)
    {
        m_yScale = scale;
    }

    void set_zScale(float scale)
    {
        m_zScale = scale;
    }

    void set_xRotationEnabled(bool enabled)
    {
        m_xRotationEnabled = enabled;
    }

    void set_yRotationEnabled(bool enabled)
    {
        m_yRotationEnabled = enabled;
    }

    void set_zRotationEnabled(bool enabled)
    {
        m_zRotationEnabled = enabled;
    }

    void setObjectColor(const QColor &color)
    {
        mObjectColor = color;
    }

    void setBackground(const QColor &color)
    {
        mBackground = color;
    }
protected:
    void paintGL() override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
private:
    int mMode;
    float mRotation;
    float m_xScale;
    float m_yScale;
    float m_zScale;
    bool m_xRotationEnabled;
    bool m_yRotationEnabled;
    bool m_zRotationEnabled;
    QColor mObjectColor;
    QColor mBackground;

    QTimer *mTimer;
    QTimer *makeTimer();

    Qt3dWavefrontObject *mObject;
};

#endif // QT3DOPENGLWIDGET_H
