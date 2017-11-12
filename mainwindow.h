#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "AKImageProcessor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int lightFactor = 255;

private slots:
    void on_chooseImagePB_clicked();
    void on_processPB_clicked();
    void on_lightFactorSlider_valueChanged(int value);
    
    void redrawNormalizedHistogram(QImage image);
    void redrawOriginalHistogram(QImage image);
    void redrawResultImage(QImage image);
    void redrawCumulative(QImage image);

private:
    Ui::MainWindow *ui;
    QPixmap* imgPM;
    AKImageProcessor* imageProcessor;
    
    void redraw();
    
signals:
    void getNormalizedHistogram();
    void getOriginalHistogram();
    void getEqualizedImage(int lightFactor);
    void getCumulative(int lightFactor);
};

#endif // MAINWINDOW_H
