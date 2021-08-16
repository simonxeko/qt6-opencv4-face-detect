#include "facedetector.h"
#include <QDebug>
#include <QFileInfo>

FaceDetector::FaceDetector() {
    // This file can be downlaode from https://raw.githubusercontent.com/opencv/opencv/master/data/haarcascades/haarcascade_frontalface_default.xml
    cascade_name = "/Users/simon/Downloads/haarcascade_frontalface_default.xml";
    assert(QFileInfo::exists(QString::fromStdString(cascade_name)));

    if (!face_cascade.load(cascade_name)) {
        qDebug() << "--(!)Error loading\n";
    }

    /*8 colors collection*/
    colorsCol   << cv::Scalar(0.0, 0.0, 255.0)   << cv::Scalar(0.0, 128.0, 255.0)
                << cv::Scalar(0.0, 255.0, 255.0) << cv::Scalar(0.0, 255.0, 0.0)
                << cv::Scalar(255.0, 128.0, 0.0) << cv::Scalar(255.0, 255.0, 0.0)
                << cv::Scalar(255.0, 0.0, 0.0)   << cv::Scalar(255.0, 0.0, 255.0);
}


QImage FaceDetector::detect(Mat frame) {
    Mat frame_gray;
    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);
    //Detection
    face_cascade.detectMultiScale(frame_gray,
                                  foundFaces,
                                  1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(100, 100));
    int n = foundFaces.size();
    //Draw rectangles around faces
    cv::Rect rect;

    for (int i = 0; i < n ; i++) {
        rect = foundFaces[i];
        rectangle(frame, cv::Point(rect.x, rect.y),
                  cv::Point((rect.x + rect.width), (rect.y + rect.height)),
                  colorsCol[i % 8]);
    }

    // Convert Mat to QImage
    QImage result = QImage((const uchar *)frame.data,
                           frame.cols,
                           frame.rows,
                           frame.step,
                           QImage::Format_RGB888).rgbSwapped();
    return result;
}

