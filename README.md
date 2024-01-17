# cccrypt

Geometry Dash CCGameManager.dat encoder/decoder written in C++

**Warning: I do not support modifying the save data to give yourself higher stats. That's just not cool, man. This is useful if you
noclipped levels and want to uncomplete them, or if your save data is broken due to bugs.**

## Usage

cccrypt allows a CCGameManager.dat to be decoded into XML, modified and then re-encoded into a CCGameManager.dat
with your changes.

To decode on Linux: `cccrypt -i ./CCGameManager.dat -o ./CCGameManager.xml -d`

You can then modify this file like any normal file. When you're done, you encode it.

To encode on Linux: `cccrypt -i ./CCGameManager.xml -o ./CCGameManager.dat -e`

Be careful when editing the file, in some cases Geometry Dash may reject the changes
so please back up the original file.

For more command line parameters, execute `cccrypt -h` from the command line.

## Compile

To compile, you can use the included meson build file:

- `meson setup build --prefix=/usr`
- `cd build; meson install; cd ..`

If you want to build for Windows, consider using Visual Studio or cross-compile.
I don't use Windows, so no solution is included. If you have one, please PR!

## Compatibility

It should build and work perfectly fine on Windows and Linux. As of now, it does **not** work on macOS due to
differences in the save data.

## Dependencies

- zlib
- C++17 compiler (though, C++11 might work?)

## License

GNU General Public License version 3.

See https://www.gnu.org/licenses/gpl-3.0.txt for license terms.
