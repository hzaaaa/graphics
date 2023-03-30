#include "Triangle.hpp"
#include "rasterizer.hpp"
#include <cmath>
#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <opencv2/opencv.hpp>

constexpr double MY_PI = 3.1415926;

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, -eye_pos[0],
        0, 1, 0, -eye_pos[1],
        0, 0, 1, -eye_pos[2],
        0, 0, 0, 1;

    view = translate * view;

    return view;
}

Eigen::Matrix4f get_model_matrix(float rotation_angle)
{
    // Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the model matrix for rotating the triangle around the Z axis.
    // Then return it.
    Eigen::Matrix4f model;
    model << cos(rotation_angle / 180.0 * acos(-1)), -sin(rotation_angle / 180.0 * acos(-1)), 0, 0,
        sin(rotation_angle / 180.0 * acos(-1)), cos(rotation_angle / 180.0 * acos(-1)), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1;

    return model;
}
Eigen::Matrix4f get_rotation(Vector4f axis, float angle)
{
    float pi = acos(-1);
    angle =angle / 180.0 *pi;
    Eigen::Matrix4f a;
    a << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1 / cos(angle);
    a = cos(angle) * a;

    Eigen::Matrix4f b = axis * axis.transpose();
    b = ((1 - cos(angle)) * b);

    Eigen::Matrix4f c;
    c << 0, -axis.z(), axis.y(), 0,
        axis.z(), 0, -axis.x(), 0,
        -axis.y(), axis.x(), 0, 0,
        0, 0, 0, 0;
    c = (sin(angle) * c);
    
    // std::cout << "frame count: " << a << '\n';
    // std::cout << "frame count: " << b << '\n';
    // std::cout << "frame count: " << c << '\n';
    return a + b + c;
}

// 可视角度?
// 宽高比
Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
                                      float zNear, float zFar)
{
    // Students will implement this function

    // Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

    float h = abs(zNear) * tan(eye_fov / 2) * 2;
    float w = h * aspect_ratio;
    Eigen::Matrix4f M2; // 平移
    M2 << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, -(zNear + zFar) / 2,
        0, 0, 0, 1;
    Eigen::Matrix4f M1; // 缩放
    M1 << 2 / w, 0, 0, 0,
        0, 2 / h, 0, 0,
        0, 0, 2 / abs(zNear - zFar), 0,
        0, 0, 0, 1;
    Eigen::Matrix4f projection; // 压平
    projection << zNear, 0, 0, 0,
        0, zNear, 0, 0,
        0, 0, (zNear + zFar), -zNear * zFar,
        0, 0, 1, 0;

    // TODO: Implement this function
    // Create the projection matrix for the given parameters.
    // Then return it.

    return M1 * M2 * projection;
}

int main(int argc, const char **argv)
{
    float angle = 0;
    bool command_line = false;
    std::string filename = "output.png";

    if (argc >= 3)
    {
        command_line = true;
        angle = std::stof(argv[2]); // -r by default
        if (argc == 4)
        {
            filename = std::string(argv[3]);
        }
        else
            return 0;
    }

    rst::rasterizer r(700, 700);

    Eigen::Vector3f eye_pos = {0, 0, 5};

    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};

    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    auto pos_id = r.load_positions(pos);
    auto ind_id = r.load_indices(ind);

    int key = 0;
    int frame_count = 0;

    if (command_line)
    {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);

        cv::imwrite(filename, image);

        return 0;
    }

    while (key != 27)
    {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);
        Eigen::Vector4f test = {0, 0, 1, 0};
        Eigen::Matrix4f b = get_rotation(test, angle);
        // Eigen::Matrix4f c = get_model_matrix(angle);
        // std::cout << "frame count: " << b << '\n';
        // std::cout << "frame count: " << c << '\n';
        // return 0;
        r.set_model(b);
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, -0.1, -50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);

        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);

        std::cout << "frame count: " << frame_count++ << '\n';

        if (key == 'a')
        {
            angle += 10;
        }
        else if (key == 'd')
        {
            angle -= 10;
        }
    }

    return 0;
}
