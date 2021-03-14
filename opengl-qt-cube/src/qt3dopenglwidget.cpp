#include "qt3dopenglwidget.h"
#include "qt3dwavefrontobject.h"
#include <QTimer>
#include <QDebug>

Qt3dOpenGLWidget::Qt3dOpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    mMode = GL_PROJECTION;
    mRotation = 0.0f;
    m_xScale = 0.1f;
    m_yScale = 0.1f;
    m_zScale = 0.1f;
    m_xRotationEnabled = false;
    m_yRotationEnabled = true;
    m_zRotationEnabled = false;
    mObjectColor = Qt::red;
    mBackground = Qt::black;
    mTimer = makeTimer();
    mObject = nullptr;
}

Qt3dOpenGLWidget::~Qt3dOpenGLWidget()
{
    delete mObject;
}

void Qt3dOpenGLWidget::paintGL()
{
    glMatrixMode(mMode);
    glClearColor(mBackground.redF(), mBackground.greenF(), mBackground.blueF(), mBackground.alphaF());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glPushMatrix();
    glScalef(m_xScale, m_yScale, m_zScale);
    glRotatef(mRotation, m_xRotationEnabled, m_yRotationEnabled, m_zRotationEnabled);
    if (mObject)
    {
        mObject->display(mObjectColor);
    }
    glPopMatrix();

    mRotation += 5.0f;
    if (mRotation > 360.0)
    {
        mRotation -= 360;
    }
}

void Qt3dOpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void Qt3dOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

QTimer *Qt3dOpenGLWidget::makeTimer()
{
    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, [&]()
    {
        update();
    });

    timer->start();

    return timer;
}
