#ifndef RENDER_H
#define RENDER_H
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "maze.h"
#include "canvas.h"
#include "../include/stb_image_write.h"

namespace mzr
{
class Render
{
public:

  size_t m_width;  //!< The image width in pixel units.
  size_t m_height; //!< The image height in pixel unitsr
  Maze m_maze;
  Render(Maze *m, size_t w = 0, size_t h = 0)
      : m_width(w), m_height(h), m_maze(*m)
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
  void draw(const char * name_img) const
  {
      
    canvas::Canvas c(m_width, m_height);
    auto width = c.width();
    auto height = c.height();    
    auto pixels = c.buffer(); 
    
    // Invocando a função de gravação da biblioteca STB para gravar PNG.
    stbi_write_png_compression_level = 0; // defaults to 8; set to higher for more compression
    stbi_write_png(name_img,     // file name
                   width, height,      // image dimensions
                   3,                     // # of channels per pixel
                   pixels,                // the pixels
                   width * 3);          // length of a row (in bytes), see above.
  }

private:
};
} // namespace mzr

#endif // RENDER_H