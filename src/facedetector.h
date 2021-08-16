#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"

#include <QImage>
#include <vector>

using namespace cv;
class FaceDetector {
    public:
        FaceDetector();

    public slots:
        QImage detect(Mat frame);

    private:
        String                   cascade_name;
        CascadeClassifier        face_cascade;
        std::vector<cv::Rect>        foundFaces;
        QList<cv::Scalar>          colorsCol;
};

#endif // FACEDETECTOR_H
