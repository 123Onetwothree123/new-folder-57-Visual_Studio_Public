#ifndef COORDIN_H_
#define COORDIN_H_
struct polar {
    double distance;
    double angle;
};
struct rect {
    double x;
    double y;
};
//prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapor);
#endif //COORDIN_H_
