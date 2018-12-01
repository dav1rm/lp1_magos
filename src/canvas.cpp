/*!
 * Canvas class implementation.
 * @file canvas.cpp
 */

#include <stdexcept>
#include <iostream>

#include "../include/canvas.h"

namespace canvas
{
typedef unsigned char component_t;
typedef unsigned char color_t;
/*!
     * Deep copy of the canvas.
     * @param clone The object we are copying from.
     */
Canvas::Canvas(const Canvas &clone)
{
    // TODO
}

/*!
     * @param source The object we are copying information from.
     * @return A reference to the `this` object.
     */
Canvas &Canvas::operator=(const Canvas &source)
{
    // TODO: incompleto

    return *this;
}

void Canvas::clear(const Color &color)
{
    for (unsigned int x = 0; x <= m_width; x++)
    {
        for (unsigned int y = 0; y <= m_height; y++)
        {
            pixel(x, y, color);
        }
    }
}

/*!
     * @throw `std::invalid_argument()` it the pixel coordinate is located outside the canvas.
     * @param p The 2D coordinate of the pixel we want to know the color of.
     * @return The pixel color.
     */
Color Canvas::pixel(coord_type x, coord_type y) const
{
    component_t *pixel = pixel_pos(x, y);
    Color pixels_color(pixel[0], pixel[1], pixel[2]);
    return pixels_color;
}
/*!
     * @throw `std::invalid_argument()` it the pixel coordinate is located outside the canvas.
     * @param p The 2D coordinate of the pixel we want to know the color of.
     * @return The pixel position on vector.
     */
component_t *Canvas::pixel_pos(coord_type x, coord_type y) const
{
    return m_pixels + (3 * (x + y * m_width));
}

/*!
     * @note Nothing is done if the  pixel coordinate is located outside the canvas.
     * @param p The 2D coordinate of the pixel we want to change the color.
     * @param c The color.
     */
void Canvas::pixel(coord_type x, coord_type y, const Color &c)
{
    component_t *pixel = pixel_pos(x, y);
    pixel[0] = c.channels[0];
    pixel[1] = c.channels[1];
    pixel[2] = c.channels[2];
}

/*!
     * Draws on the canvas a horizontal line.
     * @param p The 2D coordinate of the initial pixel of the line.
     * @param length The horizontal length of the line in pixels.
     */
void Canvas::hline(coord_type x, coord_type y, size_t length, const Color &color)
{
    for (unsigned int i = 0; i < length; i++)
        pixel(x + i, y, color);
}

/*!
     * Draws on the canvas a vertical line.
     * @param p The 2D coordinate of the initial pixel of the line.
     * @param length The vertical length of the line in pixels.
     */
void Canvas::vline(coord_type x, coord_type y, size_t length, const Color &color)
{
    for (unsigned int i = 0; i < length; i++)
        pixel(x, y + i, color);
} // namespace canvas

/*!
     * Draws on the canvas a filled box. The origin of the box is the top-left corner.
     * The box is compose of horizontal lines, drawn top to bottom.
     * @param p The 2D coordinate of the initial pixel of the box (top-left corner).
     * @param width The box's width in pixels.
     * @param height The box's heigth in pixels.
     */
void Canvas::box(coord_type x, coord_type y, size_t width, size_t height, const Color &color)
{
    for (unsigned int i = 0; i < height; i++)
        hline(x, y + i, width, color);
}
} // namespace canvas

//================================[ canvas.cpp ]================================//
