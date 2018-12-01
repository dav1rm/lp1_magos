#ifndef MAZE_H
#define MAZE_H

namespace mzr
{
class Maze
{
  typedef size_t coord_type;

public:
  enum cell_e
  {
    RightWall,
    BottomWall,
    LeftWall,
    TopWall
  };
  Maze(size_t w = 0, size_t h = 0)
      : m_width{w}, m_height{h}
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
  void knock_down(coord_type x, coord_type y, cell_e);

private:
  size_t m_width;  //!< The image width in pixel units.
  size_t m_height; //!< The image height in pixel unitsr
};
} // namespace mzr

#endif // CANVAS_H
