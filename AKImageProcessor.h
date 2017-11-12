//
//  AKImageProcessor.h
//  filter
//
//  Created by Aleksandr Kozhevnikov on 11/11/2017.
//

#ifndef AKImageProcessor_h
#define AKImageProcessor_h

#include <QMainWindow>

class AKImageProcessor : public QObject{
   
Q_OBJECT
    
private:
    QImage img;
    QImage resultImage;
    
    std::vector<int> histogram = std::vector<int>(256, 0);
    std::vector<int> normalizedHistogram = std::vector<int>(256, 0);
    std::vector<int> equalizedHistogram = std::vector<int>(256, 0);
    std::vector<int> cumulative = std::vector<int>(256, 0.0);
    int height = 0,
    width = 0;
    
    std::vector<int> computeHistogram(QString type = "");
    std::vector<int> computeCumulative(int lightFactor);
    
    int getMaxValue(std::vector<int> &vector);
    QImage generateHistogram(QString type = "");
public slots:
    void getEqualizedHistogram();
    void getEqualizedImage(int lightFactor);
    void getOriginalHistogram();
    void getCumulative(int lightFactor);
    
public:
    explicit AKImageProcessor(QObject *parent = 0);
    ~AKImageProcessor();
    
    void setImage(const QImage &);
    
signals:
    void sendEqualizedHistogram(QImage);
    void sendResultImage(QImage);
    void sendOriginalHistogram(QImage);
    void sendCumulative(QImage);
};

#endif /* AKImageProcessor_h */
