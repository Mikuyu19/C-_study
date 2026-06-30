#ifndef COLOR_HPP
#define COLOR_HPP

// Color 类：保存一个 RGB 颜色。
class Color
{
public:
    // 默认构造函数：没有传颜色时，默认是黑色 (0, 0, 0)。
    Color();

    // 带参数构造函数：创建颜色时，直接指定红、绿、蓝三个分量。
    Color(int r, int g, int b);

    // 同时设置红、绿、蓝三个颜色分量。
    void setValue(int r, int g, int b);

    // 单独设置红色分量。
    void setRed(int r);

    // 获取红色分量。
    int getRed() const;

    // 把 RGB 三个分量合成一个整数，方便写入屏幕显存。
    int toInt() const;

private:
    int _red;   // 红色分量，范围通常是 0~255
    int _green; // 绿色分量，范围通常是 0~255
    int _blue;  // 蓝色分量，范围通常是 0~255
};

#endif
