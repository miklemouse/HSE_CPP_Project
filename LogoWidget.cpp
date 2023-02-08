//
// Created by Mikhail Rusanov on 25.06.2022.
//

#include "LogoWidget.h"

LogoWidget::LogoWidget(QWidget*)
{}

void LogoWidget::drawLogo(QPainter& painter, int width, int height)
{
    QPoint center_widget(width / 2, height / 2);
    int leg_len = std::min(width, height) * .25;
    int bottom_width = leg_len * .3;
    int walls_height = leg_len;
    painter.drawLine(center_widget.x() - walls_height, center_widget.y() - walls_height, center_widget.x(),
                     center_widget.y());
    painter.drawLine(center_widget.x() + walls_height, center_widget.y() - walls_height, center_widget.x(),
                     center_widget.y());
    painter.drawLine(center_widget.x() - walls_height, center_widget.y() - walls_height,
                     center_widget.x() + walls_height, center_widget.y() - walls_height);
    painter.drawLine(center_widget.x(), center_widget.y() + leg_len, center_widget.x(), center_widget.y());
    painter.drawLine(center_widget.x() - bottom_width, center_widget.y() + leg_len, center_widget.x() + bottom_width,
                     center_widget.y() + leg_len);

    int wine_level = leg_len * .9;
    QPainterPath path;
    path.moveTo(center_widget.x(), center_widget.y());
    path.lineTo(center_widget.x() - wine_level, center_widget.y() - wine_level);
    path.lineTo(center_widget.x() + wine_level, center_widget.y() - wine_level);
    path.lineTo(center_widget.x(), center_widget.y());
    painter.fillPath(path, QBrush(Qt::black));
}

void LogoWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setBackground(QBrush(Qt::white));
    painter.setPen(QPen(Qt::black));

    drawLogo(painter, width(), height());
}
