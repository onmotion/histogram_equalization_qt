//
//  AKImage.cpp
//  filter
//
//  Created by Aleksandr Kozhevnikov on 11/11/2017.
//

#include "AKImageProcessor.h"
#include <qpainter.h>

AKImageProcessor::AKImageProcessor(QObject *parent) : QObject(parent){
    
}

AKImageProcessor::~AKImageProcessor(){
    //
};

void AKImageProcessor::setImage(const QImage &img){
    this->img = img;
    this->height = img.height();
    this->width = img.width();
};

void AKImageProcessor::getOriginalHistogram(){

    this->computeHistogram();
    emit sendOriginalHistogram(this->generateHistogram());
}

void AKImageProcessor::getEqualizedHistogram(){

    this->computeHistogram("equalized");
    QImage image = this->generateHistogram("equalized");
    
    emit sendEqualizedHistogram(image);
}

void AKImageProcessor::getCumulative(int lightFactor){

    QImage hist = this->generateHistogram();
    this->computeCumulative(lightFactor);
    int max = this->getMaxValue(cumulative);
    int cumulativeHeight = (max + 10); //небольшой отступ сверху, для удобной визуализации
    
    QImage *cumImg = &hist;
    QPainter *painter = new QPainter(cumImg);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(QColor(0, 255, 255), 1));
    QPainterPath path;
    path.moveTo(0, cumulativeHeight - cumulative[0]);
    
    for (int i = 0; i < (int)cumulative.size(); i++) {
        path.lineTo(i, cumulativeHeight - cumulative[i]);
    }

    painter->drawPath(path);
    painter->end();
    *cumImg = cumImg->scaled(255, 200);
  
    emit sendCumulative(*cumImg);
}

void AKImageProcessor::getEqualizedImage(int lightFactor){

    this->computeCumulative(lightFactor);
    this->resultImage = QImage(width, height, QImage::Format_RGB32);
    int *h = new int;
    int *s = new int;
    int *l = new int;
    
    for (int row = 0; row < height - 1; row++){
        for (int col = 0; col < width - 1; col++){
            QColor color = img.pixelColor(col, row);
            color.getHsl(h, s, l);
            int L = cumulative[*l];
            L = L > 255 ? 255 : L;
            color.setHsl(*h, *s, L);
            resultImage.setPixelColor(col, row, color);
        }
    }
    emit sendResultImage(resultImage);
}


//**********private***************//

std::vector<int> AKImageProcessor::computeHistogram(QString type){
    QImage *img = nullptr;
    std::vector<int> *histogram;
    if (type == "equalized") {
        if (this->resultImage.data_ptr() == NULL) {
            this->getEqualizedImage(255);
        }
        img = &this->resultImage;
        histogram = &equalizedHistogram;
    }else{
        img = &this->img;
        histogram = &this->histogram;
    }
    *histogram = std::vector<int>(256, 0);
    QRgb* rowData;
    int *h = new int;
    int *s = new int;
    int *l = new int;
    
    for (int row = 0; row < height - 1; row++){
        rowData = (QRgb*)img->scanLine(row);
        for (int col = 0; col < width - 1; col++){
            QColor(rowData[col]).getHsl(h, s, l);
            ++(*histogram)[*l];
        }
    }
    return *histogram;
}

std::vector<int> AKImageProcessor::computeCumulative(int lightFactor){
    std::vector<double> percentage = std::vector<double>(256, 0.0);
    percentage[0] = (double)histogram[0] / (double)(img.width() * img.height());
    for (int i = 1; i < (int)histogram.size(); i++) {
        percentage[i] = percentage[i-1] + (double)histogram[i] / (double)(img.width() * img.height());
        cumulative[i] = (int)(percentage[i] * (double)lightFactor);
    }
    return cumulative;
}

int AKImageProcessor::getMaxValue(std::vector<int> &vector){
    int max = vector[0];
    for (int i = 1; i < (int)vector.size(); i++) {
        max = max > vector[i] ? max : vector[i];
    }
    return max;
}

QImage AKImageProcessor::generateHistogram(QString type){
    std::vector<int> *histogram;
    if (type == "equalized") {
        histogram = &equalizedHistogram;
    }else{
        histogram = &this->histogram;
    }
    int max = this->getMaxValue(*histogram);
    int ratio = (max/190)+1;
    int histHeight = 200;
    
    if (ratio > 1) {
        for (int i = 0; i < 255; i++) {
            normalizedHistogram[i] = (int)((*histogram)[i]/ratio);
        }
    }else{
        normalizedHistogram = *histogram;
    }
    
    QImage histImg = QImage(255, histHeight, QImage::Format_RGB32);
    QPainter *painter = new QPainter(&histImg);
    painter->setRenderHint(QPainter::Antialiasing);
    histImg.fill(QColor(100, 100, 100));
    painter->setPen(QPen(QColor(255, 255, 255)));
    
    for (int i = 0; i < (int)normalizedHistogram.size(); i++) {
        painter->drawLine(i, histHeight - normalizedHistogram[i], i, histHeight);
    }
    painter->end();
    delete painter;
    
    return histImg;
}
