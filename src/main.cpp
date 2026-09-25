#include "reproject.hpp"
#include <iostream>
#include <vector>

int main() {
    Camera cam;
    std::cout << "请输入内参 fx fy cx cy（空格隔开）: ";
    std::cin >> cam.fx >> cam.fy >> cam.cx >> cam.cy;

    Point3d t;
    std::cout << "请输入平移 t (tx ty tz): ";
    std::cin >> t.x >> t.y >> t.z;

    double R[3][3];
    std::cout << "请输入旋转矩阵 R 的 9 个数（按行输入）: ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> R[i][j];
        }
    }

    int n = 0;
    std::cout << "请输入点的个数 n: ";
    std::cin >> n;

    std::vector<Point3d> worldPts(n);
    std::vector<Pixel>   obsPts(n);

    for (int i = 0; i < n; i++) {
        std::cout << "点" << i + 1 << " - 输入世界坐标 x y z 和观测像素 u v（共5个数）: ";
        std::cin >> worldPts[i].x >> worldPts[i].y >> worldPts[i].z
                 >> obsPts[i].u   >> obsPts[i].v;
    }

    std::cout << "\n========== 重投影结果如下 ==========" << std::endl;
    for (int i = 0; i < n; i++) {
        Point3d Pc = worldToCamera(worldPts[i], R, t);

        if (Pc.z <= 0) {
            std::cout << "点" << i + 1 << ": 深度 z = " << Pc.z
                      << " <= 0，非正深度，跳过该点" << std::endl;
            continue;
        }

        Pixel proj = projectToPixel(Pc, cam);
        double err = pixelDistance(proj, obsPts[i]);

        std::cout << "点" << i + 1 << ": 像素坐标 u = " << proj.u
                  << ", v = " << proj.v
                  << " | 与观测点的像素欧氏距离 = " << err << std::endl;
    }

    return 0;
}
