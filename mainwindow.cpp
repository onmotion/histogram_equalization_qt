#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QThread>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    imageProcessor = new AKImageProcessor();
    ui->setupUi(this);
    this->lightFactor = ui->lightFactorSlider->value();
    
    QThread *thread= new QThread;
    
    imageProcessor->moveToThread(thread);
    
    connect(imageProcessor, SIGNAL(sendOriginalHistogram(QImage)), this, SLOT(redrawOriginalHistogram(QImage)));
    connect(this, SIGNAL(getOriginalHistogram()), imageProcessor, SLOT(getOriginalHistogram()));
    
    connect(imageProcessor, SIGNAL(sendCumulative(QImage)), this, SLOT(redrawCumulative(QImage)));
    connect(this, SIGNAL(getCumulative(int)), imageProcessor, SLOT(getCumulative(int)));
    
    connect(imageProcessor, SIGNAL(sendEqualizedHistogram(QImage)), this, SLOT(redrawNormalizedHistogram(QImage)));
    connect(this, SIGNAL(getNormalizedHistogram()), imageProcessor, SLOT(getEqualizedHistogram()));
    
    connect(imageProcessor, SIGNAL(sendResultImage(QImage)), this, SLOT(redrawResultImage(QImage)));
    connect(this, SIGNAL(getEqualizedImage(int)), imageProcessor, SLOT(getEqualizedImage(int)));
    
    thread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete imageProcessor;
}

void MainWindow::on_chooseImagePB_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Выбрать изображение"), "/", "(*.bmp *.jpg *.png)");
    imgPM = new QPixmap();
    imgPM->load(filename);
    int width = imgPM->width();
    int height = imgPM->height();
    ui->heightLabel->setText(QString::number(height) + "px");
    ui->widthLabel->setText(QString::number(width) + "px");
    int labelWidth = ui->resultImageLabel->width();
    int labelHeight = ui->resultImageLabel->height();
    
    if (width > labelWidth || height > labelHeight) {
        *imgPM = imgPM->scaled(labelWidth, labelHeight, Qt::KeepAspectRatio);
    }
    ui->originalImageLabel->setPixmap(*imgPM);
    QImage img = imgPM->toImage();
    
    imageProcessor->setImage(img);
    ui->resultImageLabel->clear();
    this->getOriginalHistogram();
}

void MainWindow::on_processPB_clicked()
{
    redraw();
}

void MainWindow::on_lightFactorSlider_valueChanged(int value)
{
    this->lightFactor = value;
    redraw();
}

void MainWindow::redraw(){
    
    ui->lightFactorSlider->blockSignals(true);

    this->getCumulative(this->lightFactor);
    this->getEqualizedImage(this->lightFactor);
    this->getNormalizedHistogram();
}

void MainWindow::redrawOriginalHistogram(QImage image){
    QPixmap pm = QPixmap::fromImage(image);
    ui->originalHistogramLabel->clear();
    ui->originalHistogramLabel->setPixmap(pm);
    ui->lightFactorSlider->blockSignals(false);
}

void MainWindow::redrawCumulative(QImage image){
    QPixmap pm = QPixmap::fromImage(image);
    ui->originalHistogramLabel->clear();
    ui->originalHistogramLabel->setPixmap(pm);
}

void MainWindow::redrawNormalizedHistogram(QImage image){
    QPixmap eqHistImgPM = QPixmap::fromImage(image);
    ui->normalizedHistogramLabel->clear();
    ui->normalizedHistogramLabel->setPixmap(eqHistImgPM);
}

void MainWindow::redrawResultImage(QImage image){
    QPixmap resultImgPM = QPixmap::fromImage(image);
    ui->resultImageLabel->clear();
    ui->resultImageLabel->setPixmap(resultImgPM);
    ui->lightFactorSlider->blockSignals(false);
}

