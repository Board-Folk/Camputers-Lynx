
typedef struct {
  uint16_t noshift_1[Lynx_KEYMAP_SIZE];
  uint16_t shift_1[Lynx_KEYMAP_SIZE];
  uint16_t noshift_2[Lynx_KEYMAP_SIZE];
  uint16_t shift_2[Lynx_KEYMAP_SIZE];
} LynxKeymap_t;

/* Maps are positional in relation to keyboard ASCII codes.

Each map has a normal (without shift) and shifted (with shift) array.

In situations where there is a shift difference, add 160 to the Lynx key byte. 
This is when a key is shifted on keyboard, but not shifted on the Lynx or vise-versa.

Unused ASCII codes need to have the IGNORE_KEYCODE value in place.(Default 340)

*/

const PROGMEM LynxKeymap_t LynxKeymap_main = {
  // map 1 without shift
   {340,340,340,340,340,340, 71, 71,// ASCII Codes 0x00 - 0x07
     86, 86,340,340, 67,340,340,340,// ASCII Codes 0x08 - 0x0F
    340,340,340,340,340, 50, 53, 65,// ASCII Codes 0x10 - 0x17
     69,340,340, 70, 48,340, 51, 75,// ASCII Codes 0x18 - 0x1F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x20 - 0x27
    340,340,340,340,340,340,340,340,// ASCII Codes 0x28 - 0x2F
     32, 64, 80, 96,100,112, 72,104,// ASCII Codes 0x30 - 0x37
    108,  0, 21,  3, 16, 35, 19,340,// ASCII Codes 0x38 - 0x3F
    340, 85, 77,101, 97, 98,117,113,// ASCII Codes 0x40 - 0x47
     74,  4,109,  5, 34,107, 73,  2,// ASCII Codes 0x48 - 0x4F
     36, 84,116, 81,114,106,115, 82,// ASCII Codes 0x50 - 0x57
     99, 76, 83, 37, 20, 18, 52, 33,// ASCII Codes 0x58 - 0x5F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x60 - 0x67
    340,340,340,340,340,340,340,340,// ASCII Codes 0x68 - 0x6F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x70 - 0x77
    340,340,340,340,340,340,340,340,// ASCII Codes 0x78 - 0x7F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x80 - 0x87
    340,340,340,340,340,340,340,340},// ASCII Codes 0x88 - 0x8F

    
  // map 1 with shift
   {340,340,340,340,340,340, 71, 71,// ASCII Codes 0x00 - 0x07
     86, 86,340,340, 67,340,340,340,// ASCII Codes 0x08 - 0x0F
    340,340,340,340,340, 50, 53, 65,// ASCII Codes 0x10 - 0x17
     69,340,340, 70, 48,340, 51, 75,// ASCII Codes 0x18 - 0x1F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x20 - 0x27
    340,340,340,340,340,340,340,340,// ASCII Codes 0x28 - 0x2F
     32, 64, 80, 96,100,112, 72,104,// ASCII Codes 0x30 - 0x37
    108,  0, 21,  3, 16, 35, 19,340,// ASCII Codes 0x38 - 0x3F
    340, 85, 77,101, 97, 98,117,113,// ASCII Codes 0x40 - 0x47
     74,  4,109,  5, 34,107, 73,  2,// ASCII Codes 0x48 - 0x4F
     36, 84,116, 81,114,106,115, 82,// ASCII Codes 0x50 - 0x57
     99, 76, 83, 37, 20, 18, 52, 33,// ASCII Codes 0x58 - 0x5F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x60 - 0x67
    340,340,340,340,340,340,340,340,// ASCII Codes 0x68 - 0x6F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x70 - 0x77
    340,340,340,340,340,340,340,340,// ASCII Codes 0x78 - 0x7F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x80 - 0x87
    340,340,340,340,340,340,340,340},// ASCII Codes 0x88 - 0x8F
    

  
  // Same for now....
  // map 2 without shift
   {340,340,340,340,340,340,340,340,// ASCII Codes 0x00 - 0x07
    340,340,340,340,340,340,340,340,// ASCII Codes 0x08 - 0x0F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x10 - 0x17
    340,340,340,340,340,340,340,340,// ASCII Codes 0x18 - 0x1F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x20 - 0x27
    340,340,340,340,340,340,340,340,// ASCII Codes 0x28 - 0x2F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x30 - 0x37
    340,340,340,340,340,340,340,340,// ASCII Codes 0x38 - 0x3F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x40 - 0x47
    340,340,340,340,340,340,340,340,// ASCII Codes 0x48 - 0x4F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x50 - 0x57
    340,340,340,340,340,340,340,340,// ASCII Codes 0x58 - 0x5F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x60 - 0x67
    340,340,340,340,340,340,340,340,// ASCII Codes 0x68 - 0x6F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x70 - 0x77
    340,340,340,340,340,340,340,340,// ASCII Codes 0x78 - 0x7F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x80 - 0x87
    340,340,340,340,340,340,340,340},// ASCII Codes 0x88 - 0x8F
    
  // map 2 with shift
   {340,340,340,340,340,340,340,340,// ASCII Codes 0x00 - 0x07
    340,340,340,340,340,340,340,340,// ASCII Codes 0x08 - 0x0F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x10 - 0x17
    340,340,340,340,340,340,340,340,// ASCII Codes 0x18 - 0x1F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x20 - 0x27
    340,340,340,340,340,340,340,340,// ASCII Codes 0x28 - 0x2F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x30 - 0x37
    340,340,340,340,340,340,340,340,// ASCII Codes 0x38 - 0x3F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x40 - 0x47
    340,340,340,340,340,340,340,340,// ASCII Codes 0x48 - 0x4F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x50 - 0x57
    340,340,340,340,340,340,340,340,// ASCII Codes 0x58 - 0x5F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x60 - 0x67
    340,340,340,340,340,340,340,340,// ASCII Codes 0x68 - 0x6F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x70 - 0x77
    340,340,340,340,340,340,340,340,// ASCII Codes 0x78 - 0x7F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x80 - 0x87
    340,340,340,340,340,340,340,340}// ASCII Codes 0x88 - 0x8F

};
