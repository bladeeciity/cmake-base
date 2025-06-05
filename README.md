# cmake-base

A minimal CMake-based C++ project template.

> **Note:** I'm new to CMake. This template was mainly created for personal use. If you find any issues or have suggestions, please open an issue or a pull request.

## Project Structure

- `include/` - Public header files
- `source/` - Source files
- `bin/` - Output binaries and libraries

### Optional VS Code Settings

Add the following to your `.vscode/settings.json`:

````json
{
    "cmake.buildDirectory": "${workspaceFolder}/vs-build"
}
