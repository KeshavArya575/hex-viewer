# Hex Viewer

A simple hex viewer written in C that reads binary files and displays their contents in both hexadecimal and ASCII formats.

## Features

* Displays file content in 16-byte rows
* Shows offset (address) for each row
* Hexadecimal representation of bytes
* ASCII interpretation of printable characters
* Proper alignment and formatting
* Displays total file size

## Example Output

```
File size: 26 bytes

00000000  31 20 32 20 33 20 34 20  35 20 37 0D 0A 48 65 6C  1 2 3 4 5 7..Hel
00000010  6C 6F 2C 20 77 6F 72 6C  64 21                    lo, world!
```

## Build

```bash
gcc src/hexviewer.c -o hexviewer
```

## Usage

```bash
./hexviewer <file>
```

