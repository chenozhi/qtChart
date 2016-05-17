#ifndef LINECHART_H
#define LINECHART_H

#include <QWidget>
#include <QPainter>

class LineChart : public QWidget
{
    Q_OBJECT
public:
    explicit LineChart(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    int padding_left;
    int padding_right;
    int padding_top;
    int padding_bottom;
    int tick_length;
    int xticks;
    int yticks;
    double max_x;
    double min_x;
    double max_y;
    double min_y;


    QPen* axis_pen;

signals:

public slots:
};

#endif // LINECHART_H
