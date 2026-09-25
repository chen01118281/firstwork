#include "reproject.hpp"
#include <cmath>

Point3d worldToCamera(const Point3d& Pw, const double R[3][3], const Point3d& t) {
    Point3d Pc;
    Pc.x = R[0][0] * Pw.x + R[0][1] * Pw.y + R[0][2] * Pw.z + t.x;
    Pc.y = R[1][0] * Pw.x + R[1][1] * Pw.y + R[1][2] * Pw.z + t.y;
    Pc.z = R[2][0] * Pw.x + R[2][1] * Pw.y + R[2][2] * Pw.z + t.z;
    return Pc;
}

Pixel projectToPixel(const Point3d& Pc, const Camera& cam) {
    Pixel p;
    p.u = cam.fx * Pc.x / Pc.z + cam.cx;
    p.v = cam.fy * Pc.y / Pc.z + cam.cy;
    return p;
}

double pixelDistance(const Pixel& a, const Pixel& b) {
    double du = a.u - b.u;
    double dv = a.v - b.v;
    return sqrt(du * du + dv * dv);
}
