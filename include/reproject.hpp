#pragma once

struct Point3d {
    double x;
    double y;
    double z;
};

struct Pixel {
    double u;
    double v;
};

struct Camera {
    double fx;
    double fy;
    double cx;
    double cy;
};

Point3d worldToCamera(const Point3d& Pw, const double R[3][3], const Point3d& t);
Pixel projectToPixel(const Point3d& Pc, const Camera& cam);
double pixelDistance(const Pixel& a, const Pixel& b);
