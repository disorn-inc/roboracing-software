#ifndef PROJECT_RESETPANEL_H
#define PROJECT_RESETPANEL_H

#include <ros/ros.h>
#include <rviz/panel.h>
#include <QSlider>
#include <QSpinBox>
#include <rr_platform/color.h>

/*
 * All of our panels need to be under the rr_rviz_plugins namespace.
 */
namespace rr_rviz_plugins {

class ColorPanel : public rviz::Panel {
Q_OBJECT
public:
    ColorPanel(QWidget *parent = 0);
    int hue_min;
    int hue_max;

protected:
    QSlider *hue_slider_min;
    QSpinBox *hue_spinner_min;
    QSlider *hue_slider_max;
    QSpinBox *hue_spinner_max;
    ros::NodeHandle nh;
    ros::Publisher color_pub;
    void publishColor();


private slots:
    void colorCallback();
    void hueMinCallback(int value);
    void hueMaxCallback(int value);
};

}

#endif
