#include "linechart.h"

LineChart::LineChart(QWidget *parent) : QWidget(parent)
{
    axis_pen = new QPen(QBrush(Qt::SolidPattern), 3);
    resize(800, 800);

    padding_left = 20;
    padding_right = 20;
    padding_top = 20;
    padding_bottom = 20;
    tick_length = 4;
    xticks = 6;
    yticks = 5;

    max_x = 9;
    min_x = 0;
    min_y = 0;
    max_y = 9;

}

void LineChart::paintEvent(QPaintEvent *event) {

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw Y Axis
    int ylabel_width = 0;
    int left_offset = padding_left + ylabel_width;

    int title_height = 0;
    int top_offset = padding_top + title_height;

    int xlabel_height = 0;
    int bottom_offset = padding_bottom + xlabel_height;

    painter.setPen(*axis_pen);
    painter.drawLine(left_offset, top_offset, left_offset, height() - bottom_offset);

    // Draw X Axis
    int right_offset = padding_right;

    painter.setPen(*axis_pen);
    QPoint yaxis_p1(left_offset, height() - bottom_offset);
    QPoint yaxis_p2(width() - right_offset, height() - bottom_offset);
    painter.drawLine(yaxis_p1, yaxis_p2);

    // Draw X Ticks
    double x_spread = max_x - min_x;
    int xaxis_length = (width() - right_offset) - left_offset;

    double xscale = (double) xaxis_length / x_spread;
    double xinc = x_spread / xticks;

    for (int i = 1; i <= xticks; i++) {
        int x1 = (xscale * (i * xinc)) + left_offset;
        int y1 = (height() - bottom_offset);
        painter.drawLine(x1, y1, x1, y1 + tick_length);
    }

    // Draw Y Ticks
    double y_spread = max_y - min_y;
    int yaxis_length = height() - bottom_offset - top_offset;

    double yscale = (double) yaxis_length / y_spread;
    double yinc = y_spread / yticks;

    for (int i=1; i <= yticks; i++) {
        int x1 = left_offset;
        int y1 = yaxis_p2.y() - (yscale * (i * yinc));
        painter.drawLine(x1, y1, x1 - tick_length, y1);
    }

}
