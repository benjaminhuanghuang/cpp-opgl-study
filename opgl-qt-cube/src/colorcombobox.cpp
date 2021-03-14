#include "colorcombobox.h"
#include <QPaintEvent>
#include <QStylePainter>
#include <QListWidget>
#include <QMenu>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QWidgetAction>

ColorComboBox::ColorComboBox(QWidget *parent)
    : QWidget { parent }
{
    mListWidget = makeListWidget();
    mMenu = makeMenu();
    setCurrentColor(Qt::color0);
    setMinimumHeight(20);
}

void ColorComboBox::setCurrentColor(const QColor &color)
{
    if (mCurrentColor != color)
    {
        mCurrentColor = color;
        update();
        emit currentColorChanged(mCurrentColor);
    }
}

QRect ColorComboBox::makeColorRect() const
{
    QRect colorRect;
    QPoint center = rect().center();
    colorRect.setWidth(int(width() * 2.0/3.0));
    colorRect.setHeight(int(height() * 2.0/3.0));
    colorRect.setX(center.x() - colorRect.width()/2);
    colorRect.setY(center.y() - colorRect.height()/4);
    return colorRect;
}

QStyleOptionComboBox ColorComboBox::makeComboBoxStyle()
{
    QStyleOptionComboBox option;
    option.initFrom(this);
    return option;
}

void ColorComboBox::paintEvent(QPaintEvent *e)
{
    QStylePainter painter(this);
    painter.drawComplexControl(QStyle::CC_ComboBox, makeComboBoxStyle());
    painter.fillRect(makeColorRect(), mCurrentColor);
    QWidget::paintEvent(e);
}

void ColorComboBox::mousePressEvent(QMouseEvent *e)
{
    mListWidget->setMinimumWidth(width());
    QPoint p = parentWidget()->mapToGlobal(pos());
    p.setY(p.y() + height());
    mMenu->popup(p);
    QWidget::mousePressEvent(e);
}

QListWidget *ColorComboBox::makeListWidget()
{
    QListWidget *listWidget = new QListWidget(this);
    listWidget->setMinimumSize(width(), 250);
    assignColors(listWidget);

    connect(listWidget, &QListWidget::itemClicked, this, [&](QListWidgetItem *item)
    {
        setCurrentColor(item->background().color());
        update();
        mMenu->hide();
    });

    return listWidget;
}

QMenu *ColorComboBox::makeMenu()
{
    QMenu *menu = new QMenu(this);
    QWidgetAction *action = new QWidgetAction(this);
    action->setDefaultWidget(mListWidget);
    menu->addAction(action);
    return menu;
}

void ColorComboBox::assignColors(QListWidget *listWidget)
{
    QFile JSFile(":/colors.json");
    if (JSFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QJsonDocument doc = QJsonDocument::fromJson(JSFile.readAll());
        JSFile.close();
        QJsonArray colorsArray = doc.array();
        const int nColors = colorsArray.size();
        if (nColors > 0)
        {
            listWidget->clear();
            for (int iColor = 0; iColor < nColors; ++iColor)
            {
                QJsonObject colorObj = colorsArray.at(iColor).toObject();
                QListWidgetItem *colorItem = new QListWidgetItem;
                colorItem->setText(colorObj["name"].toString());
                colorItem->setBackground(QColor(colorObj["hexvalue"].toString()));
                colorItem->setForeground(Qt::white);
                listWidget->addItem(colorItem);
            }
        }
    }
}
