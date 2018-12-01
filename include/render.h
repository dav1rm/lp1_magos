#ifndef RENDER_H
#define RENDER_H
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/stb_image_write.h"

namespace mzr
{
class Render
{
public:
  Maze m_maze;
  Render(Maze *m, size_t w = 0, size_t h = 0)
      : m_width{w}, m_height{h}, m_maze{*m}
  { /* empty */
  }

  //=== Attribute accessors members.
  /// Get the canvas width.
  size_t width(void) const
  {
    return m_width;
  }
  /// Get the cancas height.
  size_t height(void) const
  {
    return m_height;
  }
  void draw(std::string name_img) const
  {
    // Invocando a função de gravação da biblioteca STB para gravar PNG.
    stbi_write_png_compression_level = 0; // defaults to 8; set to higher for more compression
    stbi_write_png(name_img + ".png",     // file name
                   m_width, m_width,      // image dimensions
                   3,                     // # of channels per pixel
                   pixels,                // the pixels
                   m_width * 3);          // length of a row (in bytes), see above.
  }

private:
  size_t m_width;  //!< The image width in pixel units.
  size_t m_height; //!< The image height in pixel unitsr
};
} // namespace mzr

#endif // RENDER_H
