#ifndef CPP_BOX_MEMORY_MAP_HPP
#define CPP_BOX_MEMORY_MAP_HPP

namespace cpp_box::system {

constexpr static std::uint32_t TOTAL_RAM = 1024 * 1024 * 10;  // 10 MB

enum struct Memory_Map : std::uint32_t {
  // TODO: Add interrupt vectors here
  //
  REGISTER_START = 0x00000000,
  RAM_SIZE       = REGISTER_START + 0x0000,
  SCREEN_WIDTH   = REGISTER_START + 0x0004,  // 16bit screen width
  SCREEN_HEIGHT  = REGISTER_START + 0x0006,  // 16bit screen height
  SCREEN_BPP     = REGISTER_START + 0x0008,  // 8bit screen bits per pixel. Bits are divided evenly across the color space with preference given for
  // the odd bit to green, then to blue. Special cases for 1 bpp and 2 bpp.
  // 1 bpp: black or white
  // 2 bpp: 2 levels of grey (0%, 33%, 66%, 100%)
  // 3 bpp: 1 bit red, 1 bit green, 1 bit blue. Possible colors: black, white, red, green, blue, yellow, cyan, magenta).
  // 4 bpp: 1 bit red, 2 bits green, 1 bit blue.
  // 5 bpp: 1 bit red, 2 bits green, 2 bits blue.
  // 6 bpp: 2 bits red, 2 bits green, 2 bits blue.
  // 7 bpp: 2 bits red, 3 bits green, 2 bits blue.
  // 8 bpp: 2 bits red, 3 bits green, 3 bits blue.
  // etc
  // 24 bpp: max value without alpha
  // 32 bpp: 24 + alpha
  // 0xA0009,  // 8bit screen refresh rate
  // 0xA000A,  // 8bit Horizontal aspect
  // 0xA000B,  // 8bit Vertical aspect
  SCREEN_BUFFER  = REGISTER_START + 0x000C,  // 32bit pointer to current framebuffer
  RANDOM_DEVICE  = REGISTER_START + 0x0010,  // 32bits of random data
  USER_RAM_START = REGISTER_START + 0x1000,  // leave more space for registers, this is where binaries will load
};

constexpr static std::uint32_t DEFAULT_SCREEN_BUFFER = TOTAL_RAM - (1024 * 1024 * 2);  // by default VRAM is 2 MB from top
constexpr static std::uint32_t STACK_START           = TOTAL_RAM - 1;

}  // namespace cpp_box

#endif
