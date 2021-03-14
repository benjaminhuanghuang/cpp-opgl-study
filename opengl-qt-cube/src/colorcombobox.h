#ifndef COLORCOMBOBOX_H
#define COLORCOMBOBOX_H

#include <QWidget>
#include <QStyleOptionComboBox>

class QMenu;
class QListWidget;

class ColorComboBox : public QWidget
{
    Q_OBJECT
public:
    ColorComboBox(QWidget *parent = nullptr);

    void setCurrentColor(const QColor &color);

    QColor currentColor() const
    {
        return mCurrentColor;
    }
signals:
    void currentColorChanged(const QColor &color);
protected:
    void paintEvent(QPaintEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
private:
    QColor mCurrentColor;

    QMenu *mMenu;
    QMenu *makeMenu();

    QListWidget *mListWidget;
    QListWidget *makeListWidget();

    QRect makeColorRect() const;

    void assignColors(QListWidget *listWidget);

    QStyleOptionComboBox makeComboBoxStyle();
};

#endif // COLORCOMBOBOX_H
